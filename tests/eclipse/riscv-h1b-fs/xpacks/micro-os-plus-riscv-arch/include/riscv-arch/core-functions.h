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

#ifndef RISCV_ARCH_CORE_FUNCTIONS_H_
#define RISCV_ARCH_CORE_FUNCTIONS_H_

#include <stdint.h>

/*
 * RISC-V core support functions.
 */

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

  // --------------------------------------------------------------------------
  // Support functions.

  uint32_t
  riscv_core_get_running_frequency_hz (void);

  void
  riscv_core_update_running_frequency (void);

  static void
  riscv_core_enable_machine_external_interrupts(void);

  static void
  riscv_core_disable_machine_external_interrupts(void);

  /**
   * Hardware trap entry point (assembly).
   */
  void
  riscv_trap_entry (void);

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

// ============================================================================

#if defined(__cplusplus)

namespace riscv
{
  namespace core
  {
    // ------------------------------------------------------------------------
    // Support functions.

    /**
     * Get the previously computed CPU frequency.
     */
    uint32_t
    running_frequency_hz (void);

    /**
     * Compute the CPU frequency. Call this after changing the
     * clock settings.
     */
    void
    update_running_frequency (void);

    /**
     * @brief Enable external interrupts (used by PLIC).
     */
    void
    enable_machine_external_interrupts (void);

    /**
     * @brief Disable external interrupts (used by PLIC).
     */
    void
    disable_machine_external_interrupts (void);

  // --------------------------------------------------------------------------
  } /* namespace core */

// ----------------------------------------------------------------------------
} /* namespace riscv */

#endif /* defined(__cplusplus) */

// ----------------------------------------------------------------------------

#endif /* RISCV_ARCH_CORE_FUNCTIONS_H_ */
