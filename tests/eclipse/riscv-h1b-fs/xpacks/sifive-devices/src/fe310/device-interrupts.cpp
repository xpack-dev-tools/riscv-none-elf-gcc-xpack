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

#if defined (SIFIVE_FE310)

extern "C"
{
  void
  sifive_fe310_interrupt_handle_unused (void);
}

namespace sifive
{
  namespace fe310
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_unused (void);

      // ----------------------------------------------------------------------
    } /* namespace interrupt */
  } /* namespace fe310 */
} /* namespace sifive */

// ----------------------------------------------------------------------------

// To provide the desired functionality, redefine any of these
// functions in the application.

#if defined(OS_USE_CPP_INTERRUPTS)

namespace sifive
{
  namespace fe310
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_wdogcmp (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_rtccmp (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_uart0 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_uart1 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_spi0 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_spi1 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_spi2 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio0 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio1 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio2 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio3 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio4 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio5 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio6 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio7 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio8 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio9 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio10 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio11 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio12 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio13 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio14 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio15 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio16 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio17 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio18 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio19 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio20 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio21 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio22 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio23 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio24 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio25 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio26 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio27 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio28 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio29 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio30 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_gpio31 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm0cmp0 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm0cmp1 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm0cmp2 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm0cmp3 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm1cmp0 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm1cmp1 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm1cmp2 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm1cmp3 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm2cmp0 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm2cmp1 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm2cmp2 (void);

      void
      __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
      handle_global_pwm2cmp3 (void);

      // ----------------------------------------------------------------------
    } /* namespace interrupt */
  } /* namespace fe310 */
} /* namespace sifive */

#else

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_wdogcmp (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_rtccmp (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_uart0 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_uart1 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_spi0 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_spi1 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_spi2 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio0 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio1 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio2 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio3 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio4 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio5 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio6 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio7 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio8 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio9 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio10 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio11 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio12 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio13 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio14 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio15 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio16 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio17 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio18 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio19 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio20 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio21 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio22 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio23 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio24 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio25 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio26 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio27 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio28 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio29 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio30 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_gpio31 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm0cmp0 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm0cmp1 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm0cmp2 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm0cmp3 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm1cmp0 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm1cmp1 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm1cmp2 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm1cmp3 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm2cmp0 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm2cmp1 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm2cmp2 (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
sifive_fe310_interrupt_handle_global_pwm2cmp3 (void);

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

        sifive::fe310::interrupt::handle_unused, /* 0 */
        sifive::fe310::interrupt::handle_global_wdogcmp, /* 1 */
        sifive::fe310::interrupt::handle_global_rtccmp, /* 2 */
        sifive::fe310::interrupt::handle_global_uart0, /* 3 */
        sifive::fe310::interrupt::handle_global_uart1, /* 4 */
        sifive::fe310::interrupt::handle_global_spi0, /* 5 */
        sifive::fe310::interrupt::handle_global_spi1, /* 6 */
        sifive::fe310::interrupt::handle_global_spi2, /* 7 */
        sifive::fe310::interrupt::handle_global_gpio0, /* 8 */
        sifive::fe310::interrupt::handle_global_gpio1, /* 9 */
        sifive::fe310::interrupt::handle_global_gpio2, /* 10 */
        sifive::fe310::interrupt::handle_global_gpio3, /* 11 */
        sifive::fe310::interrupt::handle_global_gpio4, /* 12 */
        sifive::fe310::interrupt::handle_global_gpio5, /* 13 */
        sifive::fe310::interrupt::handle_global_gpio6, /* 14 */
        sifive::fe310::interrupt::handle_global_gpio7, /* 15 */
        sifive::fe310::interrupt::handle_global_gpio8, /* 16 */
        sifive::fe310::interrupt::handle_global_gpio9, /* 17 */
        sifive::fe310::interrupt::handle_global_gpio10, /* 18 */
        sifive::fe310::interrupt::handle_global_gpio11, /* 19 */
        sifive::fe310::interrupt::handle_global_gpio12, /* 20 */
        sifive::fe310::interrupt::handle_global_gpio13, /* 21 */
        sifive::fe310::interrupt::handle_global_gpio14, /* 22 */
        sifive::fe310::interrupt::handle_global_gpio15, /* 23 */
        sifive::fe310::interrupt::handle_global_gpio16, /* 24 */
        sifive::fe310::interrupt::handle_global_gpio17, /* 25 */
        sifive::fe310::interrupt::handle_global_gpio18, /* 26 */
        sifive::fe310::interrupt::handle_global_gpio19, /* 27 */
        sifive::fe310::interrupt::handle_global_gpio20, /* 28 */
        sifive::fe310::interrupt::handle_global_gpio21, /* 29 */
        sifive::fe310::interrupt::handle_global_gpio22, /* 30 */
        sifive::fe310::interrupt::handle_global_gpio23, /* 31 */
        sifive::fe310::interrupt::handle_global_gpio24, /* 32 */
        sifive::fe310::interrupt::handle_global_gpio25, /* 33 */
        sifive::fe310::interrupt::handle_global_gpio26, /* 34 */
        sifive::fe310::interrupt::handle_global_gpio27, /* 35 */
        sifive::fe310::interrupt::handle_global_gpio28, /* 36 */
        sifive::fe310::interrupt::handle_global_gpio29, /* 37 */
        sifive::fe310::interrupt::handle_global_gpio30, /* 38 */
        sifive::fe310::interrupt::handle_global_gpio31, /* 39 */
        sifive::fe310::interrupt::handle_global_pwm0cmp0, /* 40 */
        sifive::fe310::interrupt::handle_global_pwm0cmp1, /* 41 */
        sifive::fe310::interrupt::handle_global_pwm0cmp2, /* 42 */
        sifive::fe310::interrupt::handle_global_pwm0cmp3, /* 43 */
        sifive::fe310::interrupt::handle_global_pwm1cmp0, /* 44 */
        sifive::fe310::interrupt::handle_global_pwm1cmp1, /* 45 */
        sifive::fe310::interrupt::handle_global_pwm1cmp2, /* 46 */
        sifive::fe310::interrupt::handle_global_pwm1cmp3, /* 47 */
        sifive::fe310::interrupt::handle_global_pwm2cmp0, /* 48 */
        sifive::fe310::interrupt::handle_global_pwm2cmp1, /* 49 */
        sifive::fe310::interrupt::handle_global_pwm2cmp2, /* 50 */
        sifive::fe310::interrupt::handle_global_pwm2cmp3 /* 51 */

#else /* defined(OS_USE_CPP_INTERRUPTS) */

        sifive_fe310_interrupt_handle_unused, /* 0 */
        sifive_fe310_interrupt_handle_global_wdogcmp, /* 1 */
        sifive_fe310_interrupt_handle_global_rtccmp, /* 2 */
        sifive_fe310_interrupt_handle_global_uart0, /* 3 */
        sifive_fe310_interrupt_handle_global_uart1, /* 4 */
        sifive_fe310_interrupt_handle_global_spi0, /* 5 */
        sifive_fe310_interrupt_handle_global_spi1, /* 6 */
        sifive_fe310_interrupt_handle_global_spi2, /* 7 */
        sifive_fe310_interrupt_handle_global_gpio0, /* 8 */
        sifive_fe310_interrupt_handle_global_gpio1, /* 9 */
        sifive_fe310_interrupt_handle_global_gpio2, /* 10 */
        sifive_fe310_interrupt_handle_global_gpio3, /* 11 */
        sifive_fe310_interrupt_handle_global_gpio4, /* 12 */
        sifive_fe310_interrupt_handle_global_gpio5, /* 13 */
        sifive_fe310_interrupt_handle_global_gpio6, /* 14 */
        sifive_fe310_interrupt_handle_global_gpio7, /* 15 */
        sifive_fe310_interrupt_handle_global_gpio8, /* 16 */
        sifive_fe310_interrupt_handle_global_gpio9, /* 17 */
        sifive_fe310_interrupt_handle_global_gpio10, /* 18 */
        sifive_fe310_interrupt_handle_global_gpio11, /* 19 */
        sifive_fe310_interrupt_handle_global_gpio12, /* 20 */
        sifive_fe310_interrupt_handle_global_gpio13, /* 21 */
        sifive_fe310_interrupt_handle_global_gpio14, /* 22 */
        sifive_fe310_interrupt_handle_global_gpio15, /* 23 */
        sifive_fe310_interrupt_handle_global_gpio16, /* 24 */
        sifive_fe310_interrupt_handle_global_gpio17, /* 25 */
        sifive_fe310_interrupt_handle_global_gpio18, /* 26 */
        sifive_fe310_interrupt_handle_global_gpio19, /* 27 */
        sifive_fe310_interrupt_handle_global_gpio20, /* 28 */
        sifive_fe310_interrupt_handle_global_gpio21, /* 29 */
        sifive_fe310_interrupt_handle_global_gpio22, /* 30 */
        sifive_fe310_interrupt_handle_global_gpio23, /* 31 */
        sifive_fe310_interrupt_handle_global_gpio24, /* 32 */
        sifive_fe310_interrupt_handle_global_gpio25, /* 33 */
        sifive_fe310_interrupt_handle_global_gpio26, /* 34 */
        sifive_fe310_interrupt_handle_global_gpio27, /* 35 */
        sifive_fe310_interrupt_handle_global_gpio28, /* 36 */
        sifive_fe310_interrupt_handle_global_gpio29, /* 37 */
        sifive_fe310_interrupt_handle_global_gpio30, /* 38 */
        sifive_fe310_interrupt_handle_global_gpio31, /* 39 */
        sifive_fe310_interrupt_handle_global_pwm0cmp0, /* 40 */
        sifive_fe310_interrupt_handle_global_pwm0cmp1, /* 41 */
        sifive_fe310_interrupt_handle_global_pwm0cmp2, /* 42 */
        sifive_fe310_interrupt_handle_global_pwm0cmp3, /* 43 */
        sifive_fe310_interrupt_handle_global_pwm1cmp0, /* 44 */
        sifive_fe310_interrupt_handle_global_pwm1cmp1, /* 45 */
        sifive_fe310_interrupt_handle_global_pwm1cmp2, /* 46 */
        sifive_fe310_interrupt_handle_global_pwm1cmp3, /* 47 */
        sifive_fe310_interrupt_handle_global_pwm2cmp0, /* 48 */
        sifive_fe310_interrupt_handle_global_pwm2cmp1, /* 49 */
        sifive_fe310_interrupt_handle_global_pwm2cmp2, /* 50 */
        sifive_fe310_interrupt_handle_global_pwm2cmp3 /* 51 */

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
    __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
    handle_machine_software (void);

    void
    __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
    handle_machine_timer (void);

#if defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

    extern void
    handle_machine_ext (void);

#else /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

    // Defined in the architecture package.
    void
    __attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
    handle_machine_ext (void);

#endif /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

    // Device local interrupts.
    // (none)

    // ------------------------------------------------------------------------
  } /* namespace interrupt */
} /* namespace riscv */

#else /* defined(OS_USE_CPP_INTERRUPTS) */

// Architecture interrupts.
void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
riscv_interrupt_handle_machine_software (void);

void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
riscv_interrupt_handle_machine_timer (void);

#if defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

extern void
riscv_interrupt_handle_machine_ext (void);

#else /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

// Defined in the architecture package.
void
__attribute__ ((weak, alias ("sifive_fe310_interrupt_handle_unused")))
riscv_interrupt_handle_machine_ext (void);

#endif /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

// Device local interrupts.
// (none)

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
        sifive::fe310::interrupt::handle_unused, /* 0 */
        sifive::fe310::interrupt::handle_unused, /* 1 */
        sifive::fe310::interrupt::handle_unused, /* 2 */
        riscv::interrupt::handle_machine_software, /* 3 */
        sifive::fe310::interrupt::handle_unused, /* 4 */
        sifive::fe310::interrupt::handle_unused, /* 5 */
        sifive::fe310::interrupt::handle_unused, /* 6 */
        riscv::interrupt::handle_machine_timer, /* 7 */
        sifive::fe310::interrupt::handle_unused, /* 8 */
        sifive::fe310::interrupt::handle_unused, /* 9 */
        sifive::fe310::interrupt::handle_unused, /* 10 */
        riscv::interrupt::handle_machine_ext, /* 11 */
        sifive::fe310::interrupt::handle_unused, /* 12 */
        sifive::fe310::interrupt::handle_unused, /* 13 */
        sifive::fe310::interrupt::handle_unused, /* 14 */
        sifive::fe310::interrupt::handle_unused, /* 15 */
        // Device local interrupts.
        // (none)

#else /* defined(OS_USE_CPP_INTERRUPTS) */

        // Architecture interrupts.
        sifive_fe310_interrupt_handle_unused, /* 0 */
        sifive_fe310_interrupt_handle_unused, /* 1 */
        sifive_fe310_interrupt_handle_unused, /* 2 */
        riscv_interrupt_handle_machine_software, /* 3 */
        sifive_fe310_interrupt_handle_unused, /* 4 */
        sifive_fe310_interrupt_handle_unused, /* 5 */
        sifive_fe310_interrupt_handle_unused, /* 6 */
        riscv_interrupt_handle_machine_timer, /* 7 */
        sifive_fe310_interrupt_handle_unused, /* 8 */
        sifive_fe310_interrupt_handle_unused, /* 9 */
        sifive_fe310_interrupt_handle_unused, /* 10 */
        riscv_interrupt_handle_machine_ext, /* 11 */
        sifive_fe310_interrupt_handle_unused, /* 12 */
        sifive_fe310_interrupt_handle_unused, /* 13 */
        sifive_fe310_interrupt_handle_unused, /* 14 */
        sifive_fe310_interrupt_handle_unused, /* 15 */
        // Device local interrupts.
        // (none)

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
sifive_fe310_interrupt_handle_unused (void)
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
