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

#ifndef MICRO_OS_PLUS_DEVICE_H_
#define MICRO_OS_PLUS_DEVICE_H_

// ----------------------------------------------------------------------------

// Architecture definitions.
#include <micro-os-plus/architecture.h>

// ----------------------------------------------------------------------------

// Automatically generated device header files.
#include <sifive-devices/device-peripherals.h>

// Additional definitions and types.
#include <sifive-devices/defines.h>
#include <sifive-devices/types.h>

// ----------------------------------------------------------------------------

// API function prototypes. 
// Currently not used. 
// #include <sifive-devices/functions.h>
// #include <sifive-devices/functions-inlines.h>

// ----------------------------------------------------------------------------

#include <sifive-devices/device-interrupts-handlers.h>

// ----------------------------------------------------------------------------

// The names of the RISCV_MMIO_ symbols are architecture specific,
// but their values depend on a specific device implementation.
// These definitions are used in <riscv-arch/device-functions-inlines.h>,
// included below.

#if !defined(RISCV_MMIO_MTIME_ADDRESS)
#error "Define RISCV_MMIO_MTIME_ADDRESS in the device specific header file (defines.h)."
#endif

#if !defined(RISCV_MMIO_MTIMECMP_ADDRESS)
#error "Define RISCV_MMIO_MTIMECMP_ADDRESS in the device specific header file (defines.h)."
#endif

#include <riscv-arch/device-functions.h>
#include <riscv-arch/device-functions-inlines.h>

// ----------------------------------------------------------------------------

#include <riscv-arch/plic-functions.h>
#include <sifive-devices/plic-functions-inlines.h>

// ----------------------------------------------------------------------------

#endif /* MICRO_OS_PLUS_DEVICE_H_ */
