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

#ifndef RISCV_ARCH_ARCH_DEFINES_H_
#define RISCV_ARCH_ARCH_DEFINES_H_

#if 0
// TODO: check and possibly prefix them.

// ----------------------------------------------------------------------------
// Definitions from SiFive bsp/env/encoding.h.

#define DCSR_XDEBUGVER      (3U<<30)
#define DCSR_NDRESET        (1<<29)
#define DCSR_FULLRESET      (1<<28)
#define DCSR_EBREAKM        (1<<15)
#define DCSR_EBREAKH        (1<<14)
#define DCSR_EBREAKS        (1<<13)
#define DCSR_EBREAKU        (1<<12)
#define DCSR_STOPCYCLE      (1<<10)
#define DCSR_STOPTIME       (1<<9)
#define DCSR_CAUSE          (7<<6)
#define DCSR_DEBUGINT       (1<<5)
#define DCSR_HALT           (1<<3)
#define DCSR_STEP           (1<<2)
#define DCSR_PRV            (3<<0)

#define DCSR_CAUSE_NONE     0
#define DCSR_CAUSE_SWBP     1
#define DCSR_CAUSE_HWBP     2
#define DCSR_CAUSE_DEBUGINT 3
#define DCSR_CAUSE_STEP     4
#define DCSR_CAUSE_HALT     5

#define MCONTROL_TYPE(xlen)    (0xfULL<<((xlen)-4))
#define MCONTROL_DMODE(xlen)   (1ULL<<((xlen)-5))
#define MCONTROL_MASKMAX(xlen) (0x3fULL<<((xlen)-11))

#define MCONTROL_SELECT     (1<<19)
#define MCONTROL_TIMING     (1<<18)
#define MCONTROL_ACTION     (0x3f<<12)
#define MCONTROL_CHAIN      (1<<11)
#define MCONTROL_MATCH      (0xf<<7)
#define MCONTROL_M          (1<<6)
#define MCONTROL_H          (1<<5)
#define MCONTROL_S          (1<<4)
#define MCONTROL_U          (1<<3)
#define MCONTROL_EXECUTE    (1<<2)
#define MCONTROL_STORE      (1<<1)
#define MCONTROL_LOAD       (1<<0)

#define MCONTROL_TYPE_NONE      0
#define MCONTROL_TYPE_MATCH     2

#define MCONTROL_ACTION_DEBUG_EXCEPTION   0
#define MCONTROL_ACTION_DEBUG_MODE        1
#define MCONTROL_ACTION_TRACE_START       2
#define MCONTROL_ACTION_TRACE_STOP        3
#define MCONTROL_ACTION_TRACE_EMIT        4

#define MCONTROL_MATCH_EQUAL     0
#define MCONTROL_MATCH_NAPOT     1
#define MCONTROL_MATCH_GE        2
#define MCONTROL_MATCH_LT        3
#define MCONTROL_MATCH_MASK_LOW  4
#define MCONTROL_MATCH_MASK_HIGH 5

#define PRV_U 0
#define PRV_S 1
#define PRV_H 2
#define PRV_M 3

#define VM_MBARE 0
#define VM_MBB   1
#define VM_MBBID 2
#define VM_SV32  8
#define VM_SV39  9
#define VM_SV48  10

// ----------------------------------------------------------------------------

#define DEFAULT_RSTVEC     0x00001000
#define DEFAULT_NMIVEC     0x00001004
#define DEFAULT_MTVEC      0x00001010
#define CONFIG_STRING_ADDR 0x0000100C
#define EXT_IO_BASE        0x40000000
#define DRAM_BASE          0x80000000

// page table entry (PTE) fields
#define PTE_V     0x001 // Valid
#define PTE_R     0x002 // Read
#define PTE_W     0x004 // Write
#define PTE_X     0x008 // Execute
#define PTE_U     0x010 // User
#define PTE_G     0x020 // Global
#define PTE_A     0x040 // Accessed
#define PTE_D     0x080 // Dirty
#define PTE_SOFT  0x300 // Reserved for Software

#define PTE_PPN_SHIFT 10

#define PTE_TABLE(PTE) (((PTE) & (PTE_V | PTE_R | PTE_W | PTE_X)) == PTE_V)

#if __riscv_xlen == 32
# define MSTATUS_SD MSTATUS32_SD
# define SSTATUS_SD SSTATUS32_SD
# define RISCV_PGLEVEL_BITS 10
#elif __riscv_xlen == 64
# define MSTATUS_SD MSTATUS64_SD
# define SSTATUS_SD SSTATUS64_SD
# define RISCV_PGLEVEL_BITS 9
#endif /* __riscv_xlen */

#define RISCV_PGSHIFT 12
#define RISCV_PGSIZE (1 << RISCV_PGSHIFT)

// End of SiFive definitions.
// ----------------------------------------------------------------------------
#endif

#define RISCV_CSR_MSTATUS_UIE         0x00000001ul
#define RISCV_CSR_MSTATUS_SIE         0x00000002ul
#define RISCV_CSR_MSTATUS_MIE         0x00000008ul
#define RISCV_CSR_MSTATUS_UPIE        0x00000010ul
#define RISCV_CSR_MSTATUS_SPIE        0x00000020ul
#define RISCV_CSR_MSTATUS_MPIE        0x00000080ul
#define RISCV_CSR_MSTATUS_SPP         0x00000100ul
#define RISCV_CSR_MSTATUS_MPP         0x00001800ul
#define RISCV_CSR_MSTATUS_FS          0x00006000ul
#define RISCV_CSR_MSTATUS_XS          0x00018000ul
#define RISCV_CSR_MSTATUS_MPRV        0x00020000ul
#define RISCV_CSR_MSTATUS_PUM         0x00040000ul
#define RISCV_CSR_MSTATUS_MXR         0x00080000ul
#define RISCV_CSR_MSTATUS_VM          0x1F000000ul
#define RISCV_CSR_MSTATUS32_SD        0x80000000ul
#define RISCV_CSR_MSTATUS64_SD        0x8000000000000000ul

#define RISCV_CSR_SSTATUS_UIE         0x00000001ul
#define RISCV_CSR_SSTATUS_SIE         0x00000002ul
#define RISCV_CSR_SSTATUS_UPIE        0x00000010ul
#define RISCV_CSR_SSTATUS_SPIE        0x00000020ul
#define RISCV_CSR_SSTATUS_SPP         0x00000100ul
#define RISCV_CSR_SSTATUS_FS          0x00006000ul
#define RISCV_CSR_SSTATUS_XS          0x00018000ul
#define RISCV_CSR_SSTATUS_PUM         0x00040000ul
#define RISCV_CSR_SSTATUS32_SD        0x80000000ul
#define RISCV_CSR_SSTATUS64_SD        0x8000000000000000ul

#define RISCV_CSR_MIP_SSIP            (1ul << riscv_interrupt_local_supervisor_software)
#define RISCV_CSR_MIP_MSIP            (1ul << riscv_interrupt_local_machine_software)
#define RISCV_CSR_MIP_STIP            (1ul << riscv_interrupt_local_supervisor_timer)
#define RISCV_CSR_MIP_MTIP            (1ul << riscv_interrupt_local_machine_timer)
#define RISCV_CSR_MIP_SEIP            (1ul << riscv_interrupt_local_supervisor_ext)
#define RISCV_CSR_MIP_MEIP            (1ul << riscv_interrupt_local_machine_ext)

// ----------------------------------------------------------------------------

#if __riscv_xlen == 32
#define RISCV_CSR_MCAUSE_INTERRUPT  (1ul << 31ul)
#define RISCV_CSR_MCAUSE_CAUSE      (0x7FFFFFFFul)
#elif __riscv_xlen == 64
#define RISCV_CSR_MCAUSE_INTERRUPT  (1ul << 63ul)
#define RISCV_CSR_MCAUSE_CAUSE      (0x7FFFFFFFFFFFFFFFul)
#else
#error "Unsupported __riscv_xlen"
#endif /* __riscv_xlen */

// ----------------------------------------------------------------------------

#endif /* RISCV_ARCH_ARCH_DEFINES_H_ */
