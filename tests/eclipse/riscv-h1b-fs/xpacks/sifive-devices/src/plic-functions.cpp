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

#include <micro-os-plus/device.h>

#include <cstdint>
#include <cstddef>

// ----------------------------------------------------------------------------

namespace riscv
{
  namespace plic
  {
    // ------------------------------------------------------------------------
    // Device PLIC functions definitions.

    void
    initialize (void)
    {
      // Disable all interrupts for the current hart.
      for (std::size_t i = 0;
          i < ((RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER + 32u) / 32u); ++i)
        {
          PLIC->enablestarget0.m.enables[i] = 0;
        }

      // Set the threshold to zero.
      PLIC->target0.m.threshold = 0;
    }

    void
    clear_priorities (void)
    {
      // Set priorities to zero. The array starts at 1.
      for (std::size_t i = 1; i <= RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER; ++i)
        {
          PLIC->priorities[i - 1] = 0;
        }
    }

  // --------------------------------------------------------------------------
  } /* namespace plic */
} /* namespace riscv */

// ----------------------------------------------------------------------------
// C aliases to the C++ functions.

void
__attribute__((alias("_ZN5riscv4plic10initializeEv")))
riscv_plic_initialize (void);

void
__attribute__((alias("_ZN5riscv4plic16clear_prioritiesEv")))
riscv_plic_clear_priorities (void);

// ----------------------------------------------------------------------------
