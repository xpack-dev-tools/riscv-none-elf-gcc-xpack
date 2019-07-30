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

#ifndef RISCV_ARCH_CSR_FUNCTIONS_INLINES_H_
#define RISCV_ARCH_CSR_FUNCTIONS_INLINES_H_

#include <stdint.h>

/*
 * Inline implementations for the RISC-V core support functions.
 */

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

  // --------------------------------------------------------------------------

#if 0
  // Not available, due to ISA limitations (no 'r' to pass the CSR,
  // mandatory on -O0, even when called with constants).

  inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_read (uint32_t reg)
    {
      riscv_arch_register_t tmp;

      asm volatile (
          "csrr %[r],%[csr]"

          : [r] "=rm"(tmp) /* Outputs */
          : [csr] "ri"(reg) /* Inputs */
          : /* Clobbers */
      );
      return tmp;
    }

#endif

  // --------------------------------------------------------------------------

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_read_mstatus (void)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrr %[r],mstatus"

        : [r] "=r"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  static inline void
  __attribute__((always_inline))
  riscv_csr_write_mstatus (riscv_arch_register_t value)
  {
    asm volatile (
        "csrw mstatus,%[v]"

        : /* Outputs */
        : [v] "rK"(value) /* Inputs */
        : /* Clobbers */
    );
  }

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_clear_mstatus_bits (riscv_arch_register_t mask)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrrc %[r],mstatus,%[v]"

        : [r] "=r"(tmp) /* Outputs */
        : [v] "rK"(mask) /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_set_mstatus_bits (riscv_arch_register_t mask)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrrs %[r],mstatus,%[v]"

        : [r] "=r"(tmp) /* Outputs */
        : [v] "rK"(mask) /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  // --------------------------------------------------------------------------

  /**
   * Read `mtvec` CSR.
   */
  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_read_mtvec (void)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrr %[r],mtvec"

        : [r] "=r"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  /**
   * Write `mtvec` CSR.
   */
  static inline void
  __attribute__((always_inline))
  riscv_csr_write_mtvec (riscv_arch_register_t value)
  {
    asm volatile (
        "csrw mtvec,%[v]"

        : /* Outputs */
        : [v] "rK"(value) /* Inputs */
        : /* Clobbers */
    );
  }

  // --------------------------------------------------------------------------

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_read_mcause (void)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrr %[r],mcause"

        : [r] "=r"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  // --------------------------------------------------------------------------

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_read_mie (void)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrr %[r],mie"

        : [r] "=r"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  static inline void
  __attribute__((always_inline))
  riscv_csr_write_mie (riscv_arch_register_t value)
  {
    asm volatile (
        "csrw mie,%[v]"

        : /* Outputs */
        : [v] "rK"(value) /* Inputs */
        : /* Clobbers */
    );
  }

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_clear_mie_bits (riscv_arch_register_t mask)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrrc %[r],mie,%[v]"

        : [r] "=r"(tmp) /* Outputs */
        : [v] "rK"(mask) /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_set_mie_bits (riscv_arch_register_t mask)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrrs %[r],mie,%[v]"

        : [r] "=r"(tmp) /* Outputs */
        : [v] "rK"(mask) /* Inputs */
        : /* Clobbers */
    );

    return tmp;
  }

  // --------------------------------------------------------------------------

#if __riscv_xlen == 64

  /**
   * Read `mcycle` CSR.
   */
  static inline uint64_t
  __attribute__((always_inline))
  riscv_csr_read_mcycle (void)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrr %[r],mcycle"

        : [r] "=rm"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );
    return tmp;
  }

#endif /* __riscv_xlen == 64 */

  static inline uint32_t
  __attribute__((always_inline))
  riscv_csr_read_mcycle_low (void)
  {
#if __riscv_xlen == 32

    uint32_t tmp;

    asm volatile (
        "csrr %[r],mcycle"

        : [r] "=rm"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );
    return tmp;

#elif __riscv_xlen == 64

    return (uint32_t) riscv_csr_read_mcycle ();

#endif /* __riscv_xlen */
  }

  static inline uint32_t
  __attribute__((always_inline))
  riscv_csr_read_mcycle_high (void)
  {
#if __riscv_xlen == 32

    uint32_t tmp;

    asm volatile (
        "csrr %[r],mcycleh"

        : [r] "=rm"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );
    return tmp;

#elif __riscv_xlen == 64

    return (uint32_t) (riscv_csr_read_mcycle () >> 32);

#endif /* __riscv_xlen */
  }

  // --------------------------------------------------------------------------

  static inline riscv_arch_register_t
  __attribute__((always_inline))
  riscv_csr_read_mhartid (void)
  {
    riscv_arch_register_t tmp;

    asm volatile (
        "csrr %[r],mhartid"

        : [r] "=r"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    );
    return tmp;
  }

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

    inline arch::register_t
    __attribute__((always_inline))
    mstatus (void)
    {
      return riscv_csr_read_mstatus ();
    }

    inline void
    __attribute__((always_inline))
    mstatus (arch::register_t value)
    {
      riscv_csr_write_mstatus (value);
    }

    inline void
    __attribute__((always_inline))
    clear_mstatus_bits (arch::register_t mask)
    {
      riscv_csr_clear_mstatus_bits (mask);
    }

    inline void
    __attribute__((always_inline))
    set_mstatus_bits (arch::register_t mask)
    {
      riscv_csr_set_mstatus_bits (mask);
    }

    // ------------------------------------------------------------------------

    inline arch::register_t
    __attribute__((always_inline))
    mtvec (void)
    {
      return riscv_csr_read_mtvec ();
    }

    inline void
    __attribute__((always_inline))
    mtvec (arch::register_t value)
    {
      riscv_csr_write_mtvec (value);
    }

    // ------------------------------------------------------------------------

    inline arch::register_t
    __attribute__((always_inline))
    mcause (void)
    {
      return riscv_csr_read_mcause ();
    }

    // ------------------------------------------------------------------------

    inline arch::register_t
    __attribute__((always_inline))
    mie (void)
    {
      return riscv_csr_read_mie ();
    }

    inline void
    __attribute__((always_inline))
    mie (arch::register_t value)
    {
      riscv_csr_write_mie (value);
    }

    inline void
    __attribute__((always_inline))
    clear_mie_bits (arch::register_t mask)
    {
      riscv_csr_clear_mie_bits (mask);
    }

    inline void
    __attribute__((always_inline))
    set_mie_bits (arch::register_t mask)
    {
      riscv_csr_set_mie_bits (mask);
    }

    // ------------------------------------------------------------------------

#if __riscv_xlen == 64

    inline uint64_t
    __attribute__((always_inline))
    mcycle (void)
    {
      return riscv_csr_read_mcycle ();
    }

#endif /* __riscv_xlen == 64 */

    inline uint32_t
    __attribute__((always_inline))
    mcycle_low (void)
    {
      return riscv_csr_read_mcycle_low ();
    }

    inline uint32_t
    __attribute__((always_inline))
    mcycle_high (void)
    {
      return riscv_csr_read_mcycle_high ();
    }

    // ------------------------------------------------------------------------

    inline arch::register_t
    __attribute__((always_inline))
    mhartid (void)
    {
      return riscv_csr_read_mhartid ();
    }

  // --------------------------------------------------------------------------
  } /* namespace csr */

// ----------------------------------------------------------------------------
} /* namespace riscv */

#endif /* defined(__cplusplus) */

// ----------------------------------------------------------------------------

#endif /* RISCV_ARCH_CSR_FUNCTIONS_INLINES_H_ */
