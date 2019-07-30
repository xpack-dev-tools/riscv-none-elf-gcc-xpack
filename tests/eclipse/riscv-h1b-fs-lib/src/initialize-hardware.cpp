/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2017 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <micro-os-plus/board.h>
#include <micro-os-plus/startup/initialize-hooks.h>

// ----------------------------------------------------------------------------

// Called early, before copying .data and clearing .bss.
// Should initialize the clocks and possible other RAM areas.
void
os_startup_initialize_hardware_early (void)
{
  // Disable all interrupts.
  riscv::csr::clear_mstatus_bits (RISCV_CSR_MSTATUS_MIE);
  // Disable all individual interrupts.
  riscv::csr::mie (0);

  // Set the trap assembly handler.
  riscv::csr::mtvec ((riscv::arch::register_t) riscv_trap_entry);

  // TODO: add support for the PRCI peripheral and use it.

  // TODO: add to C/C++ API
  // Make sure the HFROSC is on before the next line:
  PRCI->hfrosccfg |= SIFIVE_FE310_PRCI_HFROSCCFG_EN;
  // Run off 16 MHz Crystal for accuracy.
  PRCI->pllcfg |= (SIFIVE_FE310_PRCI_PLLCFG_REFSEL
          | SIFIVE_FE310_PRCI_PLLCFG_BYPASS 
          | SIFIVE_FE310_PRCI_PLLCFG_SEL);
  // Turn off HFROSC to save power
  PRCI->hfrosccfg &= ~(SIFIVE_FE310_PRCI_HFROSCCFG_EN);

  // TODO: check Arduino main.cpp for more/better initialisations.
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

// Called before running the static constructors.
void
os_startup_initialize_hardware (void)
{
  // Measure the CPU frequency in cycles, with the RTC as reference.
  riscv::core::update_running_frequency ();

  riscv::plic::clear_priorities ();
  // Hart specific initializations.
  riscv::plic::initialize ();

  // Disable M timer interrupt.
  riscv::csr::clear_mie_bits (RISCV_CSR_MIP_MTIP);

  // Clear both mtime and mtimecmp to start afresh.
  // Should trigger an interrupt as soon as enabled.
  riscv::device::mtime (0);
  riscv::device::mtimecmp (0);

  // -------------------------------------------------------------------
  // Configure Button 0 as a global GPIO irq.

  // Disable output.
  GPIO->outputen &= ~(1u << BUTTON_0_OFFSET);

  // Disable hw io function
  GPIO->iofen &= ~(1u << BUTTON_0_OFFSET);

  // Configure as input
  GPIO->inputen |= (1u << BUTTON_0_OFFSET);
  GPIO->pue |= (1u << BUTTON_0_OFFSET);

  // Configure to interrupt on both falling and rising edges.
  GPIO->fallie |= (1u << BUTTON_0_OFFSET);
  GPIO->riseie |= (1u << BUTTON_0_OFFSET);

  // Enable the BUTTON interrupt in PLIC.
  riscv::plic::enable_interrupt (INT_DEVICE_BUTTON_0);

  // Configure the BUTTON priority in PLIC. 2 out of 7.
  riscv::plic::priority (INT_DEVICE_BUTTON_0, 2);

  // Enable Global (PLIC) interrupt.
  riscv::core::enable_machine_external_interrupts ();

  // -------------------------------------------------------------------
  // When everything else is ready...

  // Enable M timer interrupt.
  riscv::csr::set_mie_bits (RISCV_CSR_MIP_MTIP);

  // Enable interrupts.
  riscv::csr::set_mstatus_bits (RISCV_CSR_MSTATUS_MIE);
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
