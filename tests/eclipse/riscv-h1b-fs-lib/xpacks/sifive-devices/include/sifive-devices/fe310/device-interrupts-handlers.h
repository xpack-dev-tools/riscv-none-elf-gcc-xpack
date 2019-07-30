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

#ifndef SIFIVE_DEVICES_FE310_DEVICE_INTERRUPTS_HANDLERS_H_
#define SIFIVE_DEVICES_FE310_DEVICE_INTERRUPTS_HANDLERS_H_

/*
 * SiFive Freedom E310 global interrupts handler functions.
 */

// ----------------------------------------------------------------------------

#if defined(__cplusplus) && defined(OS_USE_CPP_INTERRUPTS)

namespace sifive
{
  namespace fe310
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------
      // Global interrupt handlers.

      void
      handle_global_wdogcmp (void);

      void
      handle_global_rtccmp (void);

      void
      handle_global_uart0 (void);

      void
      handle_global_uart1 (void);

      void
      handle_global_spi0 (void);

      void
      handle_global_spi1 (void);

      void
      handle_global_spi2 (void);

      void
      handle_global_gpio0 (void);

      void
      handle_global_gpio1 (void);

      void
      handle_global_gpio2 (void);

      void
      handle_global_gpio3 (void);

      void
      handle_global_gpio4 (void);

      void
      handle_global_gpio5 (void);

      void
      handle_global_gpio6 (void);

      void
      handle_global_gpio7 (void);

      void
      handle_global_gpio8 (void);

      void
      handle_global_gpio9 (void);

      void
      handle_global_gpio10 (void);

      void
      handle_global_gpio11 (void);

      void
      handle_global_gpio12 (void);

      void
      handle_global_gpio13 (void);

      void
      handle_global_gpio14 (void);

      void
      handle_global_gpio15 (void);

      void
      handle_global_gpio16 (void);

      void
      handle_global_gpio17 (void);

      void
      handle_global_gpio18 (void);

      void
      handle_global_gpio19 (void);

      void
      handle_global_gpio20 (void);

      void
      handle_global_gpio21 (void);

      void
      handle_global_gpio22 (void);

      void
      handle_global_gpio23 (void);

      void
      handle_global_gpio24 (void);

      void
      handle_global_gpio25 (void);

      void
      handle_global_gpio26 (void);

      void
      handle_global_gpio27 (void);

      void
      handle_global_gpio28 (void);

      void
      handle_global_gpio29 (void);

      void
      handle_global_gpio30 (void);

      void
      handle_global_gpio31 (void);

      void
      handle_global_pwm0cmp0 (void);

      void
      handle_global_pwm0cmp1 (void);

      void
      handle_global_pwm0cmp2 (void);

      void
      handle_global_pwm0cmp3 (void);

      void
      handle_global_pwm1cmp0 (void);

      void
      handle_global_pwm1cmp1 (void);

      void
      handle_global_pwm1cmp2 (void);

      void
      handle_global_pwm1cmp3 (void);

      void
      handle_global_pwm2cmp0 (void);

      void
      handle_global_pwm2cmp1 (void);

      void
      handle_global_pwm2cmp2 (void);

      void
      handle_global_pwm2cmp3 (void);

      // ----------------------------------------------------------------------
    } /* namespace interrupt */
  } /* namespace fe310 */
} /* namespace sifive */

namespace riscv
{
  namespace interrupt
  {
    // ------------------------------------------------------------------------
    // Local interrupt handlers.

    // Architecture common handlers.
    void
    handle_machine_software (void);

    void
    handle_machine_timer (void);

    void
    handle_machine_ext (void);

    // ------------------------------------------------------------------------
  } /* namespace interrupt */
} /* namespace riscv */


#else /* defined(__cplusplus) && defined(OS_USE_CPP_INTERRUPTS) */

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

  // --------------------------------------------------------------------------
  // Global interrupt handlers.

  void
  sifive_fe310_interrupt_handle_global_wdogcmp (void);

  void
  sifive_fe310_interrupt_handle_global_rtccmp (void);

  void
  sifive_fe310_interrupt_handle_global_uart0 (void);

  void
  sifive_fe310_interrupt_handle_global_uart1 (void);

  void
  sifive_fe310_interrupt_handle_global_spi0 (void);

  void
  sifive_fe310_interrupt_handle_global_spi1 (void);

  void
  sifive_fe310_interrupt_handle_global_spi2 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio0 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio1 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio2 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio3 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio4 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio5 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio6 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio7 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio8 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio9 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio10 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio11 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio12 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio13 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio14 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio15 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio16 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio17 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio18 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio19 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio20 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio21 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio22 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio23 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio24 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio25 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio26 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio27 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio28 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio29 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio30 (void);

  void
  sifive_fe310_interrupt_handle_global_gpio31 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm0cmp0 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm0cmp1 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm0cmp2 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm0cmp3 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm1cmp0 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm1cmp1 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm1cmp2 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm1cmp3 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm2cmp0 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm2cmp1 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm2cmp2 (void);

  void
  sifive_fe310_interrupt_handle_global_pwm2cmp3 (void);

  // --------------------------------------------------------------------------
  // Local interrupt handlers.

  // Architecture common handlers.
  void
  riscv_interrupt_handle_machine_software (void);

  void
  riscv_interrupt_handle_machine_timer (void);

  void
  riscv_interrupt_handle_machine_ext (void);

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* defined(__cplusplus) && defined(OS_USE_CPP_INTERRUPTS) */

// ----------------------------------------------------------------------------

#endif /* SIFIVE_DEVICES_FE310_DEVICE_INTERRUPTS_HANDLERS_H_ */
