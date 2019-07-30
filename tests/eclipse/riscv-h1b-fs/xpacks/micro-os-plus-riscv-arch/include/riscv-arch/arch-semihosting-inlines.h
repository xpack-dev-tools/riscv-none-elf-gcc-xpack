/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2015 Liviu Ionescu.
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

#ifndef RISCV_ARCH_ARCH_SEMIHOSTING_INLINES_H_
#define RISCV_ARCH_ARCH_SEMIHOSTING_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

  // ----------------------------------------------------------------------------

// The hint that differentiates the semihosting call.
#define RISCV_SEMIHOSTING_CALL_NUMBER 7

// ----------------------------------------------------------------------------

  static inline int
  __attribute__ ((always_inline))
  os_semihosting_call_host (int reason, void* arg)
  {
    register int value asm ("a0") = reason;
    register void* ptr asm ("a1") = arg;

    asm volatile (

        // Workaround for RISC-V lack of multiple EBREAKs.
        " .option push \n"
        " .option norvc \n"
        " slli x0, x0, 0x1f \n"
        " ebreak \n"
        " srai x0, x0, %[swi] \n"
        " .option pop \n"

        : "=r" (value) /* Outputs */
        : "0" (value), "r" (ptr), [swi] "i" (RISCV_SEMIHOSTING_CALL_NUMBER) /* Inputs */
        : "memory" /* Clobbers */
    );

    return value;
  }

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

// ----------------------------------------------------------------------------

#endif /* RISCV_ARCH_ARCH_SEMIHOSTING_INLINES_H_ */
