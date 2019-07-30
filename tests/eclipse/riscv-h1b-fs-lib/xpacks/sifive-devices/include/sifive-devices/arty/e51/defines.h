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

#ifndef SIFIVE_DEVICES_ARTY_E51_DEFINES_H_
#define SIFIVE_DEVICES_ARTY_E51_DEFINES_H_

#include <stdint.h>

// ----------------------------------------------------------------------------

#define RISCV_INTERRUPTS_LOCAL_LAST_NUMBER (31u)

#define SIFIVE_E51ARTY_GPIO_PINS_LAST_NUMBER (15u)

// ----------------------------------------------------------------------------

// The names of the RISCV_MMIO_ symbols are architecture specific,
// but their values depend on a specific device implementation.
// These definitions will be used in <riscv-arch/device-functions-inlines.h>,
// included in <micro-os-plus/device..

#define RISCV_MMIO_MTIME_ADDRESS (SIFIVE_E51ARTY_CLINT_BASE_ADDRESS + SIFIVE_E51ARTY_CLINT_MTIME_OFFSET)
#define RISCV_MMIO_MTIMECMP_ADDRESS (SIFIVE_E51ARTY_CLINT_BASE_ADDRESS + SIFIVE_E51ARTY_CLINT_MTIMECMP_OFFSET)

// ----------------------------------------------------------------------------

// TODO: sort them out

// #define MIP_MLIP(x)        (1 << (IRQ_M_LOCAL + x))

// ----------------------------------------------------------------------------

#endif /* SIFIVE_DEVICES_ARTY_E51_DEFINES_H_ */
