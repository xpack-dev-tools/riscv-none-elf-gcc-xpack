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

#ifndef RISCV_ARCH_PLIC_FUNCTIONS_H_
#define RISCV_ARCH_PLIC_FUNCTIONS_H_

#include <riscv-arch/arch-types.h>

#include <stdbool.h>

/*
 * RISC-V PLIC support functions.
 */

#if defined(__cplusplus)

namespace riscv
{
  namespace plic
  {
    // ------------------------------------------------------------------------

    using source_t = riscv_plic_source_t;
    using priority_t = riscv_plic_priority_t;

    /**
     * @brief Initialize the interrupt controller.
     * @par Parameters
     *  None.
     * @par Returns
     *  Nothing.
     *
     * @details
     * Do not assume the controller registers were cleared by reset,
     * instead set them explicitly to reasonable default values, for
     * example disable all interrupts and set the threshold to zero.
     *
     * @note
     * This function must be called from each target (hart).
     */
    void
    initialize (void);

    /**
     * @brief Clear all PLIC priorities.
     * @par Parameters
     *  None.
     * @par Returns
     *  Nothing.
     *
     * @details
     * Do not assume the controller registers were cleared by reset,
     * instead set them explicitly to reasonable default values, for
     * example set all priorities to 0.
     *
     * @note
     * The priorities are unique for the entire PLIC, do not call
     * this function from each target (hart), since it might
     * override values set by other targets.
     */
    void
    clear_priorities (void);

    /**
     * @brief Set the interrupt threshold for the current target (hart).
     * @param [in] priority The new threshold value.
     * @return The previous threshold value.
     *
     * @details
     * Each interrupt target (usually a hart) has an associated
     * priority threshold, held in
     * a platform-specific memory-mapped register. Only active
     * interrupts that have a priority strictly greater than the
     * threshold will cause an interrupt notification to be sent
     * to the target.
     *
     * Different interrupt targets need not support the same set of
     * priority threshold values. Interrupt target threshold registers
     * should be WARL fields to allow software to determine the
     * supported thresholds. A threshold register should always be
     * able to hold the value zero, in which case, no interrupts
     * are masked. If implemented, the threshold register will usually
     * also be able to hold the maximum priority level, in which case
     * all interrupts are masked.
     */
    priority_t
    threshold (priority_t priority);

    /**
     * @brief Get the interrupt threshold for the current target (hart).
     * @par Parameters
     *  None.
     * @return The threshold value.
     */
    priority_t
    threshold (void);

    /**
     * @brief Enable an interrupt for the current target (hart).
     * @param [in] global_interrupt_id The id of the global interrupt
     *  source.
     * @par Returns
     *  Nothing.
     */
    void
    enable_interrupt (source_t global_interrupt_id);

    /**
     * @brief Disable an interrupt for the current target (hart).
     * @param [in] global_interrupt_id The id of the global interrupt
     *  source.
     * @par Returns
     *  Nothing.
     */
    void
    disable_interrupt (source_t global_interrupt_id);

    /**
     * @brief Check if an interrupt is enabled for the current target
     *  (hart).
     * @param [in] global_interrupt_id The id of the global interrupt
     *  source.
     * @retval true The interrupt is enabled.
     * @retval false The interrupt is disabled.
     */
    bool
    is_interrupt_enabled (source_t global_interrupt_id);

    /**
     * @brief Set the priority of an interrupt.
     * @param [in] global_interrupt_id The id of the global interrupt
     *  source.
     * @param [in] priority The interrupt priority.
     * @par Returns
     *  Nothing.
     */
    void
    priority (source_t global_interrupt_id, priority_t priority);

    /**
     * @brief Get the priority of an interrupt.
     * @param [in] global_interrupt_id The id of the global interrupt
     *  source.
     * @return The current priority.
     */
    priority_t
    priority (source_t global_interrupt_id);

    /**
     * @brief Claim an interrupt for the current target (hart).
     * @par Parameters
     *  None.
     * @return The highest priority pending interrupt or 0, if there
     *  are no pending interrupts.
     *
     * @details
     * Sometime after a target receives an interrupt notification, it
     * might decide to service the interrupt. The target sends an
     * interrupt claim message to the PLIC core, which will usually
     * be implemented as a non-idempotent memory-mapped I/O control
     * register read. On receiving a claim message, the PLIC core will
     * atomically determine the ID of the highest-priority pending
     * interrupt for the target and then clear down the corresponding
     * source's IP bit. The PLIC core will then return the ID to the
     * target. The PLIC core will return an ID of zero, if there were
     * no pending interrupts for the target when the claim was serviced.
     *
     * After the highest-priority pending interrupt is claimed by a
     * target and the corresponding IP bit is cleared, other
     * lower-priority pending interrupts might then become visible
     * to the target, and so the PLIC EIP bit might not be cleared
     * after a claim. The interrupt handler can check the local
     * `meip/seip/ueip` bits before exiting the handler, to allow
     * more efficient service of other interrupts without first
     * restoring the interrupted context and taking another interrupt
     * trap.
     *
     * It is always legal for a hart to perform a claim even if the EIP
     * is not set. In particular, a hart could set the threshold value
     * to maximum to disable interrupt notifications and instead poll
     * for active interrupts using periodic claim requests, though a
     * simpler approach to implement polling would be to clear the
     * external interrupt enable in the corresponding `xie` register
     * for privilege mode `x`.
     */
    source_t
    claim_interrupt (void);

    /**
     * @brief Send the completion message to the interrupt target (hart).
     * @param [in] global_interrupt_id The id of the global interrupt
     *  source.
     * @par Returns
     *  Nothing.
     *
     * @details
     * After a handler has completed service of an interrupt, the
     * associated gateway must be sent an interrupt completion message,
     * usually as a write to a non-idempotent memory-mapped I/O control
     * register. The gateway will only forward additional interrupts to
     * the PLIC core after receiving the completion message.
     */
    void
    complete_interrupt (source_t global_interrupt_id);

  // --------------------------------------------------------------------------
  } /* namespace plic */

// ----------------------------------------------------------------------------
} /* namespace riscv */

#endif /* defined(__cplusplus) */

// ============================================================================

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

// --------------------------------------------------------------------------

  void
  riscv_plic_initialize (void);

  void
  riscv_plic_clear_priorities (void);

  static riscv_plic_priority_t
  riscv_plic_write_threshold (riscv_plic_priority_t priority);

  static riscv_plic_priority_t
  riscv_plic_read_threshold (void);

  static void
  riscv_plic_enable_interrupt (riscv_plic_source_t global_interrupt_id);

  static void
  riscv_plic_disable_interrupt (riscv_plic_source_t global_interrupt_id);

  static bool
  riscv_plic_is_interrupt_enabled (
      riscv_plic_source_t global_interrupt_id);

  static void
  riscv_plic_write_priority (riscv_plic_source_t global_interrupt_id,
                             riscv_plic_priority_t priority);

  static riscv_plic_priority_t
  riscv_plic_read_priority (riscv_plic_source_t global_interrupt_id);

  static riscv_plic_source_t
  riscv_plic_claim_interrupt (void);

  static void
  riscv_plic_complete_interrupt (
      riscv_plic_source_t global_interrupt_id);

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

// ----------------------------------------------------------------------------

#endif /* RISCV_ARCH_PLIC_FUNCTIONS_H_ */
