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

#ifndef RISCV_ARCH_ARCH_TYPES_H_
#define RISCV_ARCH_ARCH_TYPES_H_

#include <stdint.h>

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

#if __riscv_xlen == 32
  typedef uint32_t riscv_arch_register_t;
#elif __riscv_xlen == 64
  typedef uint64_t riscv_arch_register_t;
#endif /* __riscv_xlen */

  typedef void
  (*riscv_core_trap_handler_ptr_t) (void);

  // --------------------------------------------------------------------------

  typedef enum {
    riscv_exception_misaligned_fetch = 0,
    riscv_exception_fault_fetch = 1,
    riscv_exception_illegal_instruction = 2,
    riscv_exception_breakpoint = 3,
    riscv_exception_misaligned_load = 4,
    riscv_exception_fault_load = 5,
    riscv_exception_misaligned_store = 6,
    riscv_exception_fault_store = 7,
    riscv_exception_user_ecall = 8,
    riscv_exception_supervisor_ecall = 9,
    /* 10 */
    riscv_exception_machine_ecall = 11,
    riscv_exception_page_fetch = 12,
    riscv_exception_page_load = 13,
    /* 14 */
    riscv_exception_page_store = 15
  } riscv_exceptions_enum_t;

#define RISCV_EXCEPTIONS_LAST_NUMBER (15u)

  // --------------------------------------------------------------------------
  // Values from Table 3.6.

  typedef enum {
    riscv_interrupt_local_user_software = 0,
    riscv_interrupt_local_supervisor_software = 1,
    /* 2 reserved */
    riscv_interrupt_local_machine_software = 3,
    riscv_interrupt_local_user_timer = 4,
    riscv_interrupt_local_supervisor_timer = 5,
    /* 6 reserved */
    riscv_interrupt_local_machine_timer = 7,
    riscv_interrupt_local_user_ext = 8,
    riscv_interrupt_local_supervisor_ext = 9,
    /* 10 reserved */
    riscv_interrupt_local_machine_ext = 11,
    /* 12 reserved */
    /* 13 reserved */
    /* 14 reserved */
    /* 15 reserved */
  } riscv_interrupts_local_enum_t;

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

// ============================================================================

#if defined(__cplusplus)

namespace riscv
{
  namespace arch
  {
    // ------------------------------------------------------------------------

    using register_t = riscv_arch_register_t;

  // --------------------------------------------------------------------------
  } /* namespace arch */

  namespace core
  {
    // ------------------------------------------------------------------------

    using trap_handler_ptr_t = riscv_core_trap_handler_ptr_t;

  // --------------------------------------------------------------------------
  }
// ----------------------------------------------------------------------------
} /* namespace riscv */

#endif /* defined(__cplusplus) */

// ----------------------------------------------------------------------------

#endif /* RISCV_ARCH_ARCH_TYPES_H_ */
