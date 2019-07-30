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

#include <stddef.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

#if defined (SIFIVE_E31ARTY)

extern "C"
{
  void
  sifive_e31arty_interrupt_handle_unused (void);
}

namespace sifive
{
  namespace e31arty
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_unused (void);

      // ----------------------------------------------------------------------
    } /* namespace interrupt */
  } /* namespace e31arty */
} /* namespace sifive */

// ----------------------------------------------------------------------------

// To provide the desired functionality, redefine any of these
// functions in the application.

#if defined(OS_USE_CPP_INTERRUPTS)

namespace sifive
{
  namespace e31arty
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_uart0 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_external (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_spi0 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio0 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio1 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio2 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio3 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio4 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio5 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio6 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio7 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio8 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio9 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio10 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio11 (void);

      void __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio12 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio13 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio14 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_gpio15 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_pwm0cmp0 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_pwm0cmp1 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_pwm0cmp2 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_global_pwm0cmp3 (void);

      // ----------------------------------------------------------------------
    } /* namespace interrupt */
  } /* namespace e31arty */
} /* namespace sifive */

#else

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_uart0 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_external (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_spi0 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio0 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio1 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio2 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio3 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio4 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio5 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio6 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio7 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio8 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio9 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio10 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio11 (void);

void __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio12 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio13 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio14 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_gpio15 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_pwm0cmp0 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_pwm0cmp1 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_pwm0cmp2 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_global_pwm0cmp3 (void);

#endif /* defined(OS_USE_CPP_INTERRUPTS) */

namespace riscv
{
  namespace core
  {
    // ------------------------------------------------------------------------

    // Array of pointers to interrupt handlers. See Table 3.6 from Volume II.
    riscv::core::trap_handler_ptr_t __attribute__ ((section(".interrupts_global_array")))
    global_interrupt_handlers[] =
      {
#if defined(OS_USE_CPP_INTERRUPTS)

        sifive::e31arty::interrupt::handle_unused, /* 0 */
        sifive::e31arty::interrupt::handle_global_uart0, /* 1 */
        sifive::e31arty::interrupt::handle_global_external, /* 2 */
        sifive::e31arty::interrupt::handle_unused, /* 3 */
        sifive::e31arty::interrupt::handle_unused, /* 4 */
        sifive::e31arty::interrupt::handle_unused, /* 5 */
        sifive::e31arty::interrupt::handle_global_spi0, /* 6 */
        sifive::e31arty::interrupt::handle_global_gpio0, /* 7 */
        sifive::e31arty::interrupt::handle_global_gpio1, /* 8 */
        sifive::e31arty::interrupt::handle_global_gpio2, /* 9 */
        sifive::e31arty::interrupt::handle_global_gpio3, /* 10 */
        sifive::e31arty::interrupt::handle_global_gpio4, /* 11 */
        sifive::e31arty::interrupt::handle_global_gpio5, /* 12 */
        sifive::e31arty::interrupt::handle_global_gpio6, /* 13 */
        sifive::e31arty::interrupt::handle_global_gpio7, /* 14 */
        sifive::e31arty::interrupt::handle_global_gpio8, /* 15 */
        sifive::e31arty::interrupt::handle_global_gpio9, /* 16 */
        sifive::e31arty::interrupt::handle_global_gpio10, /* 17 */
        sifive::e31arty::interrupt::handle_global_gpio11, /* 18 */
        sifive::e31arty::interrupt::handle_global_gpio12, /* 19 */
        sifive::e31arty::interrupt::handle_global_gpio13, /* 20 */
        sifive::e31arty::interrupt::handle_global_gpio14, /* 21 */
        sifive::e31arty::interrupt::handle_global_gpio15, /* 22 */
        sifive::e31arty::interrupt::handle_global_pwm0cmp0, /* 23 */
        sifive::e31arty::interrupt::handle_global_pwm0cmp1, /* 24 */
        sifive::e31arty::interrupt::handle_global_pwm0cmp2, /* 25 */
        sifive::e31arty::interrupt::handle_global_pwm0cmp3 /* 26 */

#else /* defined(OS_USE_CPP_INTERRUPTS) */

        sifive_e31arty_interrupt_handle_unused, /* 0 */
        sifive_e31arty_interrupt_handle_global_uart0, /* 1 */
        sifive_e31arty_interrupt_handle_global_external, /* 2 */
        sifive_e31arty_interrupt_handle_unused, /* 3 */
        sifive_e31arty_interrupt_handle_unused, /* 4 */
        sifive_e31arty_interrupt_handle_unused, /* 5 */
        sifive_e31arty_interrupt_handle_global_spi0, /* 6 */
        sifive_e31arty_interrupt_handle_global_gpio0, /* 7 */
        sifive_e31arty_interrupt_handle_global_gpio1, /* 8 */
        sifive_e31arty_interrupt_handle_global_gpio2, /* 9 */
        sifive_e31arty_interrupt_handle_global_gpio3, /* 10 */
        sifive_e31arty_interrupt_handle_global_gpio4, /* 11 */
        sifive_e31arty_interrupt_handle_global_gpio5, /* 12 */
        sifive_e31arty_interrupt_handle_global_gpio6, /* 13 */
        sifive_e31arty_interrupt_handle_global_gpio7, /* 14 */
        sifive_e31arty_interrupt_handle_global_gpio8, /* 15 */
        sifive_e31arty_interrupt_handle_global_gpio9, /* 16 */
        sifive_e31arty_interrupt_handle_global_gpio10, /* 17 */
        sifive_e31arty_interrupt_handle_global_gpio11, /* 18 */
        sifive_e31arty_interrupt_handle_global_gpio12, /* 19 */
        sifive_e31arty_interrupt_handle_global_gpio13, /* 20 */
        sifive_e31arty_interrupt_handle_global_gpio14, /* 21 */
        sifive_e31arty_interrupt_handle_global_gpio15, /* 22 */
        sifive_e31arty_interrupt_handle_global_pwm0cmp0, /* 23 */
        sifive_e31arty_interrupt_handle_global_pwm0cmp1, /* 24 */
        sifive_e31arty_interrupt_handle_global_pwm0cmp2, /* 25 */
        sifive_e31arty_interrupt_handle_global_pwm0cmp3 /* 26 */

#endif /* defined(OS_USE_CPP_INTERRUPTS) */
      };

    // ------------------------------------------------------------------------
  } /* namespace core */
} /* namespace riscv */

static_assert(
    sizeof(riscv::core::global_interrupt_handlers)/
      sizeof(riscv::core::global_interrupt_handlers[0]) ==
        (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER + 1),
    "riscv::core::global_interrupt_handlers[] size must match RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER");

// ----------------------------------------------------------------------------

#if defined(OS_USE_CPP_INTERRUPTS)

namespace riscv
{
  namespace interrupt
  {
    // ------------------------------------------------------------------------

    // Architecture interrupts.
    void
    __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
    handle_machine_software (void);

    void
    __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
    handle_machine_timer (void);

    #if defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

    extern void
    handle_machine_ext (void);

    #else

    // Defined in the architecture package.
    void
    __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
    handle_machine_ext (void);

    #endif /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */


    // ------------------------------------------------------------------------
  } /* namespace interrupt */
} /* namespace riscv */

namespace sifive
{
  namespace e31arty
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------
      // Device local interrupts.

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device0 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device1 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device2 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device3 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device4 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device5 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device6 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device7 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device8 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device9 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device10 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device11 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device12 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device13 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device14 (void);

      void
      __attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
      handle_local_device15 (void);

      // ----------------------------------------------------------------------
    } /* namespace interrupt */
  } /* namespace e31arty */
} /* namespace sifive */

#else /* defined(OS_USE_CPP_INTERRUPTS) */

// Architecture interrupts.
void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
riscv_interrupt_handle_machine_software (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
riscv_interrupt_handle_machine_timer (void);

#if defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

extern void
riscv_interrupt_handle_machine_ext (void);

#else

// Defined in the architecture package.
void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
riscv_interrupt_handle_machine_ext (void);

#endif /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

// Device local interrupts.
void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device0 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device1 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device2 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device3 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device4 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device5 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device6 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device7 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device8 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device9 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device10 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device11 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device12 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device13 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device14 (void);

void
__attribute__ ((weak, alias ("sifive_e31arty_interrupt_handle_unused")))
sifive_e31arty_interrupt_handle_local_device15 (void);

#endif /* defined(OS_USE_CPP_INTERRUPTS) */

namespace riscv
{
  namespace core
  {
    // ------------------------------------------------------------------------

    // Array of pointers to interrupt handlers. See Table 3.6 from Volume II.
    riscv::core::trap_handler_ptr_t __attribute__ ((section(".interrupts_local_array")))
    local_interrupt_handlers[] =
      {
#if defined(OS_USE_CPP_INTERRUPTS)

        // Architecture interrupts.
        sifive::e31arty::interrupt::handle_unused, /* 0 */
        sifive::e31arty::interrupt::handle_unused, /* 1 */
        sifive::e31arty::interrupt::handle_unused, /* 2 */
        riscv::interrupt::handle_machine_software, /* 3 */
        sifive::e31arty::interrupt::handle_unused, /* 4 */
        sifive::e31arty::interrupt::handle_unused, /* 5 */
        sifive::e31arty::interrupt::handle_unused, /* 6 */
        riscv::interrupt::handle_machine_timer, /* 7 */
        sifive::e31arty::interrupt::handle_unused, /* 8 */
        sifive::e31arty::interrupt::handle_unused, /* 9 */
        sifive::e31arty::interrupt::handle_unused, /* 10 */
        riscv::interrupt::handle_machine_ext, /* 11 */
        sifive::e31arty::interrupt::handle_unused, /* 12 */
        sifive::e31arty::interrupt::handle_unused, /* 13 */
        sifive::e31arty::interrupt::handle_unused, /* 14 */
        sifive::e31arty::interrupt::handle_unused, /* 15 */

        // Device local interrupts.
        sifive::e31arty::interrupt::handle_local_device0, /* 16 */
        sifive::e31arty::interrupt::handle_local_device1, /* 17 */
        sifive::e31arty::interrupt::handle_local_device2, /* 18 */
        sifive::e31arty::interrupt::handle_local_device3, /* 19 */
        sifive::e31arty::interrupt::handle_local_device4, /* 20 */
        sifive::e31arty::interrupt::handle_local_device5, /* 21 */
        sifive::e31arty::interrupt::handle_local_device6, /* 22 */
        sifive::e31arty::interrupt::handle_local_device7, /* 23 */
        sifive::e31arty::interrupt::handle_local_device8, /* 24 */
        sifive::e31arty::interrupt::handle_local_device9, /* 25 */
        sifive::e31arty::interrupt::handle_local_device10, /* 26 */
        sifive::e31arty::interrupt::handle_local_device11, /* 27 */
        sifive::e31arty::interrupt::handle_local_device12, /* 28 */
        sifive::e31arty::interrupt::handle_local_device13, /* 29 */
        sifive::e31arty::interrupt::handle_local_device14, /* 30 */
        sifive::e31arty::interrupt::handle_local_device15 /* 31 */

#else /* defined(OS_USE_CPP_INTERRUPTS) */

        // Architecture interrupts.
        sifive_e31arty_interrupt_handle_unused, /* 0 */
        sifive_e31arty_interrupt_handle_unused, /* 1 */
        sifive_e31arty_interrupt_handle_unused, /* 2 */
        riscv_interrupt_handle_machine_software, /* 3 */
        sifive_e31arty_interrupt_handle_unused, /* 4 */
        sifive_e31arty_interrupt_handle_unused, /* 5 */
        sifive_e31arty_interrupt_handle_unused, /* 6 */
        riscv_interrupt_handle_machine_timer, /* 7 */
        sifive_e31arty_interrupt_handle_unused, /* 8 */
        sifive_e31arty_interrupt_handle_unused, /* 9 */
        sifive_e31arty_interrupt_handle_unused, /* 10 */
        riscv_interrupt_handle_machine_ext, /* 11 */
        sifive_e31arty_interrupt_handle_unused, /* 12 */
        sifive_e31arty_interrupt_handle_unused, /* 13 */
        sifive_e31arty_interrupt_handle_unused, /* 14 */
        sifive_e31arty_interrupt_handle_unused, /* 15 */

        // Device local interrupts.
        sifive_e31arty_interrupt_handle_local_device0, /* 16 */
        sifive_e31arty_interrupt_handle_local_device1, /* 17 */
        sifive_e31arty_interrupt_handle_local_device2, /* 18 */
        sifive_e31arty_interrupt_handle_local_device3, /* 19 */
        sifive_e31arty_interrupt_handle_local_device4, /* 20 */
        sifive_e31arty_interrupt_handle_local_device5, /* 21 */
        sifive_e31arty_interrupt_handle_local_device6, /* 22 */
        sifive_e31arty_interrupt_handle_local_device7, /* 23 */
        sifive_e31arty_interrupt_handle_local_device8, /* 24 */
        sifive_e31arty_interrupt_handle_local_device9, /* 25 */
        sifive_e31arty_interrupt_handle_local_device10, /* 26 */
        sifive_e31arty_interrupt_handle_local_device11, /* 27 */
        sifive_e31arty_interrupt_handle_local_device12, /* 28 */
        sifive_e31arty_interrupt_handle_local_device13, /* 29 */
        sifive_e31arty_interrupt_handle_local_device14, /* 30 */
        sifive_e31arty_interrupt_handle_local_device15 /* 31 */

#endif /* defined(OS_USE_CPP_INTERRUPTS) */
      };

    // ------------------------------------------------------------------------
  } /* namespace core */
} /* namespace riscv */

static_assert(
    sizeof(riscv::core::local_interrupt_handlers)/
      sizeof(riscv::core::local_interrupt_handlers[0]) ==
        (RISCV_INTERRUPTS_LOCAL_LAST_NUMBER + 1),
    "riscv::core::local_interrupt_handlers[] size must match RISCV_INTERRUPTS_LOCAL_LAST_NUMBER");

// ----------------------------------------------------------------------------

void
__attribute__ ((section(".traps_handlers"),weak))
sifive_e31arty_interrupt_handle_unused (void)
{
#if defined(DEBUG)
  riscv::arch::ebreak ();
#endif /* defined(DEBUG) */

  while (true)
    {
      riscv::arch::wfi ();
    }
}

#endif /* DEVICE */

// ----------------------------------------------------------------------------
