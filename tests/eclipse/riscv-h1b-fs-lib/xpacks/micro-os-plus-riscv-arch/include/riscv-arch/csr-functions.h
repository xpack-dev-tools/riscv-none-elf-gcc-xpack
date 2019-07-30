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

#ifndef RISCV_ARCH_CSR_FUNCTIONS_H_
#define RISCV_ARCH_CSR_FUNCTIONS_H_

#include <riscv-arch/arch-types.h>

/*
 * RISC-V CSR support functions.
 */

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

  // --------------------------------------------------------------------------

#if 0
  // Not available, due to ISA limitations.
  // The workaround is to use distinct functions
  // for each CSR. There are only 4096 of them.

  riscv_arch_register_t
  riscv_csr_read (uint32_t reg);

  void
  riscv_csr_write (uint32_t reg, riscv_arch_register_t value);
#endif

  // --------------------------------------------------------------------------
  // `mstatus`

  /**
   * Read the `mstatus` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_read_mstatus (void);

  /**
   * Write the `mstatus` CSR.
   */
  static void
  riscv_csr_write_mstatus (riscv_arch_register_t value);

  /**
   * Clear bits in the `mstatus` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_clear_mstatus_bits (riscv_arch_register_t mask);

  /**
   * Set bits in the `mstatus` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_set_mstatus_bits (riscv_arch_register_t mask);

  // --------------------------------------------------------------------------
  // `mtvec`

  /**
   * Read the `mtvec` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_read_mtvec (void);

  /**
   * Write the `mtvec` CSR.
   */
  static void
  riscv_csr_write_mtvec (riscv_arch_register_t value);

  // --------------------------------------------------------------------------
  // `mcause`

  /**
   * Read the `mcause` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_read_mcause (void);

  // --------------------------------------------------------------------------
  // `mie`

  /**
   * Read the `mie` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_read_mie (void);

  /**
   * Write the `mie` CSR.
   */
  static void
  riscv_csr_write_mie (riscv_arch_register_t value);

  /**
   * Clear bits in the `mie` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_clear_mie_bits (riscv_arch_register_t mask);

  /**
   * Set bits in the `mie` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_set_mie_bits (riscv_arch_register_t mask);

  // --------------------------------------------------------------------------
  // `mcycle`

  /**
   * Read the `mcycle` CSR.
   */
#if __riscv_xlen == 64
  static
#endif /* __riscv_xlen == 64 */
  uint64_t
  riscv_csr_read_mcycle (void);

  static uint32_t
  riscv_csr_read_mcycle_low (void);

  static uint32_t
  riscv_csr_read_mcycle_high (void);

  // --------------------------------------------------------------------------
  // `mhartid`

  /**
   * Read the `mhartid` CSR.
   */
  static riscv_arch_register_t
  riscv_csr_read_mhartid (void);

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

// ============================================================================

#if defined(__cplusplus)

namespace riscv
{
  namespace csr
  {
    // ------------------------------------------------------------------------
    // `mstatus`

    arch::register_t
    mstatus (void);

    void
    mstatus (arch::register_t value);

    void
    clear_mstatus_bits (arch::register_t mask);

    void
    set_mstatus_bits (arch::register_t mask);

    // ------------------------------------------------------------------------
    // `mtvec`

    arch::register_t
    mtvec (void);

    void
    mtvec (arch::register_t value);

    // ------------------------------------------------------------------------
    // `mcause`

    arch::register_t
    mcause (void);

    // ------------------------------------------------------------------------
    // `mie`

    arch::register_t
    mie (void);

    void
    mie (arch::register_t value);

    void
    clear_mie_bits (arch::register_t mask);

    void
    set_mie_bits (arch::register_t mask);

    // ------------------------------------------------------------------------
    // `mcycle`

    /**
     * Read the mcycle counter.
     */
    uint64_t
    mcycle (void);

    uint32_t
    mcycle_low (void);

    uint32_t
    mcycle_high (void);

    // ------------------------------------------------------------------------
    // `mhartid`

    arch::register_t
    mhartid (void);

  // --------------------------------------------------------------------------
  } /* namespace csr */

// ----------------------------------------------------------------------------
} /* namespace riscv */

#endif /* defined(__cplusplus) */

// ----------------------------------------------------------------------------

#endif /* RISCV_ARCH_CSR_FUNCTIONS_H_ */
