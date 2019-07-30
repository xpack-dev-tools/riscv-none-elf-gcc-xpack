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

#include <micro-os-plus/device.h>
#include <micro-os-plus/diag/trace.h>

#include <stddef.h>
#include <stdbool.h>
#include <inttypes.h>

// ----------------------------------------------------------------------------

extern "C"
{
  void
  riscv_core_handle_unused_trap (void);
}

// ----------------------------------------------------------------------------

// To provide the desired functionality, redefine it in the application.
#if defined(OS_USE_CPP_INTERRUPTS)

namespace riscv
{
  namespace core
  {
    void
    __attribute__ ((weak, alias ("riscv_core_handle_unused_trap")))
    handle_exceptions (void);
  } /* namespace core */
} /* namespace riscv */

#else /* defined(OS_USE_CPP_INTERRUPTS) */

void
__attribute__ ((weak, alias ("riscv_core_handle_unused_trap")))
riscv_core_handle_exceptions (void);

#endif /* defined(OS_USE_CPP_INTERRUPTS) */

// ----------------------------------------------------------------------------

namespace riscv
{
  namespace core
  {
    // ------------------------------------------------------------------------

    void
    handle_trap ();

    void
    __attribute__ ((section(".traps_handlers")))
    handle_trap ()
    {
      riscv::arch::register_t cause = riscv::csr::mcause ();
      if ((cause & RISCV_CSR_MCAUSE_INTERRUPT) != 0)
        {
          size_t index = (cause & RISCV_CSR_MCAUSE_CAUSE);
          // The `<=` is because the number is the last valid one.
          if (index <= (RISCV_INTERRUPTS_LOCAL_LAST_NUMBER))
            {
              // Call the local device interrupt handler via the pointer.
              riscv::core::local_interrupt_handlers[index] ();

              return;
            }
        }
      else
        {
          size_t index = cause;
          if (index < RISCV_EXCEPTIONS_LAST_NUMBER)
            {
              // Call the single handler for all exception.
              // No need to pass the number, the handler can get
              // it again from `mcause()`.
#if defined(OS_USE_CPP_INTERRUPTS)
              riscv::core::handle_exceptions ();
#else
              riscv_core_handle_exceptions ();
#endif

              return;
            }
        }

#if defined(DEBUG)
      riscv::arch::ebreak ();
#endif /* defined(DEBUG) */

      while (true)
        {
          riscv::arch::wfi ();
        }
    }

    // ------------------------------------------------------------------------
  } /* namespace core */
} /* namespace riscv */

// Alias function to C, so that the assembly code will reach it.
extern "C" void
__attribute__ ((alias("_ZN5riscv4core11handle_trapEv")))
riscv_core_handle_trap (void);

#if defined(RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

namespace riscv
{
  namespace interrupt
  {
    // ------------------------------------------------------------------------

    void
    handle_machine_ext (void);

    void
    handle_machine_ext (void)
    {
      // Get the current interrupt number from the PLIC.
      size_t int_num = riscv::plic::claim_interrupt ();

      // The `<=` is because the number is the last valid one.
      if (int_num <= RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)
        {
          // Call the global interrupt handler via the pointer.
          riscv::core::global_interrupt_handlers[int_num] ();

          // Acknowledge the interrupt in the PLIC.
          riscv::plic::complete_interrupt ((riscv::plic::source_t) int_num);

          return;
        }

#if defined(DEBUG)
      riscv::arch::ebreak ();
#endif /* defined(DEBUG) */

      while (true)
        {
          riscv::arch::wfi ();
        }
    }

    // ------------------------------------------------------------------------
  } /* namespace interrupt */
} /* namespace riscv */

extern "C" void
__attribute__ ((alias("_ZN5riscv9interrupt18handle_machine_extEv")))
riscv_interrupt_handle_machine_ext (void);

#endif /* defined(RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

void
__attribute__ ((section(".traps_handlers"),weak))
riscv_core_handle_unused_trap (void)
{
  riscv::arch::register_t mcause = riscv::csr::mcause ();
  os::trace::printf ("%s() mcause=0x%0" PRIX64 "\n", __func__, mcause);

#if defined(DEBUG)
  riscv::arch::ebreak ();
#endif /* defined(DEBUG) */

  while (true)
    {
      riscv::arch::wfi ();
    }
}

// ----------------------------------------------------------------------------
