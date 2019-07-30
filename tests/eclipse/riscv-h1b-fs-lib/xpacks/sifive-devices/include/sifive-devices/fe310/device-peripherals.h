/*
 * This file is part of the µOS++ distribution
 *   (http://micro-os-plus.github.io).
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

#ifndef SIFIVE_DEVICES_FE310_DEVICE_PERIPHERALS_H_
#define SIFIVE_DEVICES_FE310_DEVICE_PERIPHERALS_H_

// ----------------------------------------------------------------------------

/**
 * @brief µOS++ Core - device peripherals header file
 *  for Freedom E310-G000 from SiFive, Inc.
 * @version 0.2.0
 * @date 2017-12-12
 * @note Generated from fe310-xsvd.json@0.2.0 with xsvd@0.3.0.
 */

// ----------------------------------------------------------------------------

#include <stdint.h>

#if defined(__cplusplus)
extern "C"
{
#endif

/** 
 * @addtogroup sifive
 * @{
 */

/**
 * @addtogroup fe310
 * @{
 */

/** 
 * @addtogroup device-interrupts
 * @{
 */

// ----------------------------------------------------------------------------

/**
 * @brief Interrupt Numbers.
 */

typedef enum {
  sifive_fe310_interrupt_global_wdogcmp = 1, /**< Watchdog Compare Interrupt */
  sifive_fe310_interrupt_global_rtccmp = 2, /**< RTC Compare Interrupt */
  sifive_fe310_interrupt_global_uart0 = 3, /**< UART0 Interrupt */
  sifive_fe310_interrupt_global_uart1 = 4, /**< UART1 Interrupt */
  sifive_fe310_interrupt_global_spi0 = 5, /**< SPI0 Interrupt */
  sifive_fe310_interrupt_global_spi1 = 6, /**< SPI1 Interrupt */
  sifive_fe310_interrupt_global_spi2 = 7, /**< SPI2 Interrupt */
  sifive_fe310_interrupt_global_gpio0 = 8, /**< GPIO0 Interrupt */
  sifive_fe310_interrupt_global_gpio1 = 9, /**< GPIO1 Interrupt */
  sifive_fe310_interrupt_global_gpio2 = 10, /**< GPIO2 Interrupt */
  sifive_fe310_interrupt_global_gpio3 = 11, /**< GPIO3 Interrupt */
  sifive_fe310_interrupt_global_gpio4 = 12, /**< GPIO4 Interrupt */
  sifive_fe310_interrupt_global_gpio5 = 13, /**< GPIO5 Interrupt */
  sifive_fe310_interrupt_global_gpio6 = 14, /**< GPIO6 Interrupt */
  sifive_fe310_interrupt_global_gpio7 = 15, /**< GPIO7 Interrupt */
  sifive_fe310_interrupt_global_gpio8 = 16, /**< GPIO8 Interrupt */
  sifive_fe310_interrupt_global_gpio9 = 17, /**< GPIO9 Interrupt */
  sifive_fe310_interrupt_global_gpio10 = 18, /**< GPIO10 Interrupt */
  sifive_fe310_interrupt_global_gpio11 = 19, /**< GPIO11 Interrupt */
  sifive_fe310_interrupt_global_gpio12 = 20, /**< GPIO12 Interrupt */
  sifive_fe310_interrupt_global_gpio13 = 21, /**< GPIO13 Interrupt */
  sifive_fe310_interrupt_global_gpio14 = 22, /**< GPIO14 Interrupt */
  sifive_fe310_interrupt_global_gpio15 = 23, /**< GPIO15 Interrupt */
  sifive_fe310_interrupt_global_gpio16 = 24, /**< GPIO16 Interrupt */
  sifive_fe310_interrupt_global_gpio17 = 25, /**< GPIO17 Interrupt */
  sifive_fe310_interrupt_global_gpio18 = 26, /**< GPIO18 Interrupt */
  sifive_fe310_interrupt_global_gpio19 = 27, /**< GPIO19 Interrupt */
  sifive_fe310_interrupt_global_gpio20 = 28, /**< GPIO20 Interrupt */
  sifive_fe310_interrupt_global_gpio21 = 29, /**< GPIO21 Interrupt */
  sifive_fe310_interrupt_global_gpio22 = 30, /**< GPIO22 Interrupt */
  sifive_fe310_interrupt_global_gpio23 = 31, /**< GPIO23 Interrupt */
  sifive_fe310_interrupt_global_gpio24 = 32, /**< GPIO24 Interrupt */
  sifive_fe310_interrupt_global_gpio25 = 33, /**< GPIO25 Interrupt */
  sifive_fe310_interrupt_global_gpio26 = 34, /**< GPIO26 Interrupt */
  sifive_fe310_interrupt_global_gpio27 = 35, /**< GPIO27 Interrupt */
  sifive_fe310_interrupt_global_gpio28 = 36, /**< GPIO28 Interrupt */
  sifive_fe310_interrupt_global_gpio29 = 37, /**< GPIO29 Interrupt */
  sifive_fe310_interrupt_global_gpio30 = 38, /**< GPIO30 Interrupt */
  sifive_fe310_interrupt_global_gpio31 = 39, /**< GPIO31 Interrupt */
  sifive_fe310_interrupt_global_pwm0cmp0 = 40, /**< PWM0 Compare 0 Interrupt */
  sifive_fe310_interrupt_global_pwm0cmp1 = 41, /**< PWM0 Compare 1 Interrupt */
  sifive_fe310_interrupt_global_pwm0cmp2 = 42, /**< PWM0 Compare 2 Interrupt */
  sifive_fe310_interrupt_global_pwm0cmp3 = 43, /**< PWM0 Compare 3 Interrupt */
  sifive_fe310_interrupt_global_pwm1cmp0 = 44, /**< PWM1 Compare 0 Interrupt */
  sifive_fe310_interrupt_global_pwm1cmp1 = 45, /**< PWM1 Compare 1 Interrupt */
  sifive_fe310_interrupt_global_pwm1cmp2 = 46, /**< PWM1 Compare 2 Interrupt */
  sifive_fe310_interrupt_global_pwm1cmp3 = 47, /**< PWM1 Compare 3 Interrupt */
  sifive_fe310_interrupt_global_pwm2cmp0 = 48, /**< PWM2 Compare 0 Interrupt */
  sifive_fe310_interrupt_global_pwm2cmp1 = 49, /**< PWM2 Compare 1 Interrupt */
  sifive_fe310_interrupt_global_pwm2cmp2 = 50, /**< PWM2 Compare 2 Interrupt */
  sifive_fe310_interrupt_global_pwm2cmp3 = 51, /**< PWM2 Compare 3 Interrupt */
} riscv_interrupts_global_enum_t;

#define RISCV_INTERRUPTS_GLOBAL_PRIORITY_BITS  (3u)
#define RISCV_INTERRUPTS_GLOBAL_PRIORITY_LEVELS  (7u)
#define RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER  (51u)

// ----------------------------------------------------------------------------

/**
 * @}
 */ /* End of group device-interrupts */

/** 
 * @addtogroup device-peripheral-registers
 * @{
 */

#define IO__ volatile
#define I__ volatile
#define O__ volatile

// ----------------------------------------------------------------------------

/**
 * @brief Machine Time Compare Registers per Hart.
 */

typedef struct {
  IO__ uint32_t low;  /**< @0x02004000: Machine Compare Register Low */
  IO__ uint32_t high;  /**< @0x02004004: Machine Compare Register High */
} sifive_fe310_clint_mtimecmp_t; // 0x02004007

// ----------------------------------------------------------------------------

/**
 * @brief Machine Time Register.
 */

typedef struct {
  I__  uint32_t low;  /**< @0x0200BFF8: Machine Time Register Low */
  I__  uint32_t high;  /**< @0x0200BFFC: Machine Time Register High */
} sifive_fe310_clint_mtime_t; // 0x0200BFFF

// ----------------------------------------------------------------------------

/**
 * @brief Core Complex Local Interruptor (CLINT) Peripheral.
 */

typedef struct {
  IO__ uint32_t msip[1];  /**< @0x02000000: MSIP (Machine-mode Software Interrupts) Register per Hart */
       uint32_t reserved1[4095];
       sifive_fe310_clint_mtimecmp_t mtimecmp[1];  /**< @0x02004000: Machine Time Compare Registers per Hart */
       uint64_t reserved2[4094];
       sifive_fe310_clint_mtime_t mtime;  /**< @0x0200BFF8: Machine Time Register */
       uint32_t reserved3[4096];
} sifive_fe310_clint_t; // 0x0200FFFF

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 M-mode Interrupt Enable Bits.
 */

typedef struct {
  IO__ uint32_t enables[2];  /**< @0x0C002000: Interrupt Enable Bits Registers */
} sifive_fe310_plic_enablestarget0_m_t; // 0x0C002007

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 Interrupt Enable Bits.
 */

typedef struct {
       sifive_fe310_plic_enablestarget0_m_t m;  /**< @0x0C002000: Hart 0 M-mode Interrupt Enable Bits */
} sifive_fe310_plic_enablestarget0_t; // 0x0C002007

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 M-Mode Interrupt Threshold.
 */

typedef struct {
  IO__ uint32_t threshold;  /**< @0x0C200000: The Priority Threshold Register */
  IO__ uint32_t claimcomplete;  /**< @0x0C200004: The Interrupt Claim/Completion Register */
} sifive_fe310_plic_target0_m_t; // 0x0C200007

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 Interrupt Thresholds.
 */

typedef struct {
       sifive_fe310_plic_target0_m_t m;  /**< @0x0C200000: Hart 0 M-Mode Interrupt Threshold */
} sifive_fe310_plic_target0_t; // 0x0C200007

// ----------------------------------------------------------------------------

/**
 * @brief Platform-Level Interrupt Controller (PLIC) Peripheral.
 */

typedef struct {
  IO__ uint32_t priorities[52];  /**< @0x0C000000: Interrupt Priorities Registers; 0 is reserved. */
       uint32_t reserved1[972];
  I__  uint32_t pendings[2];  /**< @0x0C001000: Interrupt Pending Bits Registers */
       uint64_t reserved2[511];
       sifive_fe310_plic_enablestarget0_t enablestarget0;  /**< @0x0C002000: Hart 0 Interrupt Enable Bits */
       uint64_t reserved3[261119];
       sifive_fe310_plic_target0_t target0;  /**< @0x0C200000: Hart 0 Interrupt Thresholds */
       uint32_t reserved4[16252926];
} sifive_fe310_plic_t; // 0x0FFFFFFF

// ----------------------------------------------------------------------------

/**
 * @brief Watchdog Timer (WDT), part of Always-On Domain.
 */

typedef struct {
  IO__ uint32_t cfg;  /**< @0x10000000: Watchdog Configuration Register */
       uint32_t reserved1;
  IO__ uint32_t count;  /**< @0x10000008: Watchdog Count Register */
       uint32_t reserved2;
  IO__ uint32_t scale;  /**< @0x10000010: Watchdog Scale Register */
       uint32_t reserved3;
  IO__ uint32_t feed;  /**< @0x10000018: Watchdog Feed Address Register */
  IO__ uint32_t key;  /**< @0x1000001C: Watchdog Key Register */
  IO__ uint32_t cmp;  /**< @0x10000020: Watchdog Compare Register */
       uint32_t reserved4[7];
} sifive_fe310_wdog_t; // 0x1000003F

// ----------------------------------------------------------------------------

/**
 * @brief Real-Time Clock (RTC), part of Always-On Domain.
 */

typedef struct {
  IO__ uint32_t cfg;  /**< @0x10000040: RTC Configuration Register */
       uint32_t reserved1;
  IO__ uint32_t low;  /**< @0x10000048: RTC Counter Register Low */
  IO__ uint32_t high;  /**< @0x1000004C: RTC Counter Register High */
  IO__ uint32_t scale;  /**< @0x10000050: RTC Scale Register */
       uint32_t reserved2[3];
  IO__ uint32_t cmp;  /**< @0x10000060: RTC Compare Register */
       uint32_t reserved3[3];
} sifive_fe310_rtc_t; // 0x1000006F

// ----------------------------------------------------------------------------

/**
 * @brief Always-On (AON) Domain.
 */

typedef struct {
  IO__ uint32_t lfrosccfg;  /**< @0x10000070: Internal Programmable Low-Frequency Ring Oscillator Register */
       uint32_t reserved1[3];
  IO__ uint32_t backup[32];  /**< @0x10000080: Backup Registers */
} sifive_fe310_aon_t; // 0x100000FF

// ----------------------------------------------------------------------------

/**
 * @brief Power-Management Unit (PMU), part of Always-On Domain.
 */

typedef struct {
  IO__ uint32_t wakeupi[8];  /**< @0x10000100: Wakeup program instruction Registers */
  IO__ uint32_t sleepi[8];  /**< @0x10000120: Sleep Program Instruction Registers */
  IO__ uint32_t ie;  /**< @0x10000140: PMU Interrupt Enables Register */
  IO__ uint32_t cause;  /**< @0x10000144: PMU Wakeup Cause Register */
  IO__ uint32_t sleep;  /**< @0x10000148: PMU Initiate Sleep Sequence Register */
  IO__ uint32_t key;  /**< @0x1000014C: PMU Key Register */
} sifive_fe310_pmu_t; // 0x1000014F

// ----------------------------------------------------------------------------

/**
 * @brief Power, Reset, Clock, Interrupt (PRCI) Peripheral.
 */

typedef struct {
  IO__ uint32_t hfrosccfg;  /**< @0x10008000: Internal Trimmable Programmable 72 MHz Oscillator Register */
  IO__ uint32_t hfxosccfg;  /**< @0x10008004: External 16 MHz Crystal Oscillator Register */
  IO__ uint32_t pllcfg;  /**< @0x10008008: Internal High-Frequency PLL (HFPLL) Register */
  IO__ uint32_t plloutdiv;  /**< @0x1000800C: PLL Output Divider */
       uint32_t reserved1[8188];
} sifive_fe310_prci_t; // 0x1000FFFF

// ----------------------------------------------------------------------------

/**
 * @brief One-Time Programmable Memory (OTP) Peripheral.
 */

typedef struct {
  IO__ uint32_t lock;  /**< @0x10010000: Programmed-I/O Lock Register */
  IO__ uint32_t ck;  /**< @0x10010004: Device Clock Signal Register */
  IO__ uint32_t oe;  /**< @0x10010008: Device Output-Enable Signal Register */
  IO__ uint32_t sel;  /**< @0x1001000C: Device Chip-Select Signal Register */
  IO__ uint32_t we;  /**< @0x10010010: Device Write-Enable Signal Register */
  IO__ uint32_t mr;  /**< @0x10010014: Device Mode Register */
  IO__ uint32_t mrr;  /**< @0x10010018: Read-Voltage Regulator Control Register */
  IO__ uint32_t mpp;  /**< @0x1001001C: Write-Voltage Charge Pump Control Register */
  IO__ uint32_t vrren;  /**< @0x10010020: Read-Voltage Enable Register */
  IO__ uint32_t vppen;  /**< @0x10010024: Write-Voltage Enable Register */
  IO__ uint32_t a;  /**< @0x10010028: Device Address Register */
  IO__ uint32_t d;  /**< @0x1001002C: Device Data Input Register */
  IO__ uint32_t q;  /**< @0x10010030: Device Data Output Register */
  IO__ uint32_t rsctrl;  /**< @0x10010034: Read Sequencer Control Register */
       uint32_t reserved1[1010];
} sifive_fe310_otp_t; // 0x10010FFF

// ----------------------------------------------------------------------------

/**
 * @brief General Purpose Input/Output Controller (GPIO) Peripheral.
 */

typedef struct {
  IO__ uint32_t value;  /**< @0x10012000: Pin Value Register */
  IO__ uint32_t inputen;  /**< @0x10012004: Pin Input Enable Register */
  IO__ uint32_t outputen;  /**< @0x10012008: Pin Output Enable Register */
  IO__ uint32_t port;  /**< @0x1001200C: Output Port Value Register */
  IO__ uint32_t pue;  /**< @0x10012010: Internal Pull-up Enable Register */
  IO__ uint32_t ds;  /**< @0x10012014: Pin Drive Strength Register */
  IO__ uint32_t riseie;  /**< @0x10012018: Rise Interrupt Enable Register */
  IO__ uint32_t riseip;  /**< @0x1001201C: Rise Interrupt Pending Register */
  IO__ uint32_t fallie;  /**< @0x10012020: Fall Interrupt Enable Register */
  IO__ uint32_t fallip;  /**< @0x10012024: Fall Interrupt Pending Register */
  IO__ uint32_t highie;  /**< @0x10012028: High Interrupt Enable Register */
  IO__ uint32_t highip;  /**< @0x1001202C: High Interrupt Pending Register */
  IO__ uint32_t lowie;  /**< @0x10012030: Low Interrupt Enable Register */
  IO__ uint32_t lowip;  /**< @0x10012034: Low Interrupt Pending Register */
  IO__ uint32_t iofen;  /**< @0x10012038: HW I/O Function Enable Register */
  IO__ uint32_t iofsel;  /**< @0x1001203C: HW I/O Function Select Register */
  IO__ uint32_t outxor;  /**< @0x10012040: Output XOR (invert) Register */
       uint32_t reserved1[1007];
} sifive_fe310_gpio_t; // 0x10012FFF

// ----------------------------------------------------------------------------

/**
 * @brief Universal Asynchronous Receiver/Transmitter (UART) Peripheral.
 */

typedef struct {
  IO__ uint32_t txdata;  /**< @0x10013000: Transmit Data Register */
  IO__ uint32_t rxdata;  /**< @0x10013004: Receive Data Register */
  IO__ uint32_t txctrl;  /**< @0x10013008: Transmit Control Register  */
  IO__ uint32_t rxctrl;  /**< @0x1001300C: Receive Control Register */
  IO__ uint32_t ie;  /**< @0x10013010: Interrupt Enable Register */
  I__  uint32_t ip;  /**< @0x10013014: Interrupt Pending Register */
  IO__ uint32_t div;  /**< @0x10013018: Baud Rate Divisor Register */
       uint32_t reserved1[1017];
} sifive_fe310_uart_t; // 0x10013FFF

// ----------------------------------------------------------------------------

/**
 * @brief Serial Peripheral Interface (SPI) Peripheral.
 */

typedef struct {
  IO__ uint32_t sckdiv;  /**< @0x10014000: Serial clock divisor Register */
  IO__ uint32_t sckmode;  /**< @0x10014004: Serial Clock Mode Register */
       uint32_t reserved1[2];
  IO__ uint32_t csid;  /**< @0x10014010: Chip Select ID Register */
  IO__ uint32_t csdef;  /**< @0x10014014: Chip Select Default Register */
  IO__ uint32_t csmode;  /**< @0x10014018: Chip Select Mode Register */
       uint32_t reserved2[3];
  IO__ uint32_t delay0;  /**< @0x10014028: Delay Control 0 Register */
  IO__ uint32_t delay1;  /**< @0x1001402C: Delay Control 1 Register */
       uint32_t reserved3[4];
  IO__ uint32_t fmt;  /**< @0x10014040: Frame Format Register */
       uint32_t reserved4;
  IO__ uint32_t txdata;  /**< @0x10014048: Tx FIFO Data Register */
  I__  uint32_t rxdata;  /**< @0x1001404C: Rx FIFO Data Register */
  IO__ uint32_t txmark;  /**< @0x10014050: Tx FIFO Watermark Register */
  IO__ uint32_t rxmark;  /**< @0x10014054: Rx FIFO Watermark Register */
       uint32_t reserved5[2];
  IO__ uint32_t fctrl;  /**< @0x10014060: Flash Interface Control Register */
  IO__ uint32_t ffmt;  /**< @0x10014064: Flash Instruction Format Register */
       uint32_t reserved6[2];
  IO__ uint32_t ie;  /**< @0x10014070: Interrupt Enable Register */
  IO__ uint32_t ip;  /**< @0x10014074: Interrupt Pending Register */
       uint32_t reserved7[994];
} sifive_fe310_spi_t; // 0x10014FFF

// ----------------------------------------------------------------------------

/**
 * @brief Pulse-Width Modulation (PWM) Peripheral.
 */

typedef struct {
  IO__ uint32_t cfg;  /**< @0x10015000: Configuration Register */
       uint32_t reserved1;
  IO__ uint32_t count;  /**< @0x10015008: Configuration Register */
       uint32_t reserved2;
  IO__ uint32_t scale;  /**< @0x10015010: Scale Register */
       uint32_t reserved3[3];
  IO__ uint32_t cmp[4];  /**< @0x10015020: Compare Registers */
       uint32_t reserved4[1012];
} sifive_fe310_pwm0_t; // 0x10015FFF

// ----------------------------------------------------------------------------

/**
 * @brief Pulse-Width Modulation (PWM) Peripheral.
 */

typedef struct {
  IO__ uint32_t cfg;  /**< @0x10025000: Configuration Register */
       uint32_t reserved1;
  IO__ uint32_t count;  /**< @0x10025008: Configuration Register */
       uint32_t reserved2;
  IO__ uint32_t scale;  /**< @0x10025010: Scale Register */
       uint32_t reserved3[3];
  IO__ uint32_t cmp[4];  /**< @0x10025020: Compare Registers */
       uint32_t reserved4[1012];
} sifive_fe310_pwm_t; // 0x10025FFF

// ----------------------------------------------------------------------------

/**
 * @brief Wakeup Cause Values Enumeration.
 */

typedef enum {
  sifive_fe310_pmu_cause_wakeupcause_reset = 0, /**< Reset Wakeup */
  sifive_fe310_pmu_cause_wakeupcause_rtc = 1, /**< RTC Wakeup */
  sifive_fe310_pmu_cause_wakeupcause_dwakeup = 2, /**< Digital input Wakeup */
} sifive_fe310_pmu_cause_wakeupcause_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief Reset Cause Values Enumeration.
 */

typedef enum {
  sifive_fe310_pmu_cause_resetcause_external = 1, /**< External reset */
  sifive_fe310_pmu_cause_resetcause_watchdog = 2, /**< Watchdog timer reset */
} sifive_fe310_pmu_cause_resetcause_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief Reference Clock R Divide Ratio Enumeration.
 */

typedef enum {
  sifive_fe310_prci_pllcfg_r_div1 = 0, /**< Unchanged */
  sifive_fe310_prci_pllcfg_r_div2 = 1, /**< Divided by 2 */
  sifive_fe310_prci_pllcfg_r_div3 = 2, /**< Divided by 3 */
  sifive_fe310_prci_pllcfg_r_div4 = 3, /**< Divided by 4 */
} sifive_fe310_prci_pllcfg_r_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief Reference Clock F Multiplier Ratio Enumeration.
 */

typedef enum {
  sifive_fe310_prci_pllcfg_f_mul2 = 0, /**< Multiplied by 2 */
  sifive_fe310_prci_pllcfg_f_mul4 = 1, /**< Multiplied by 4 */
  sifive_fe310_prci_pllcfg_f_mul6 = 2, /**< Multiplied by 6 */
  sifive_fe310_prci_pllcfg_f_mul8 = 3, /**< Multiplied by 8 */
  sifive_fe310_prci_pllcfg_f_mul10 = 4, /**< Multiplied by 10 */
  sifive_fe310_prci_pllcfg_f_mul12 = 5, /**< Multiplied by 12 */
  sifive_fe310_prci_pllcfg_f_mul14 = 6, /**< Multiplied by 14 */
  sifive_fe310_prci_pllcfg_f_mul16 = 7, /**< Multiplied by 16 */
  sifive_fe310_prci_pllcfg_f_mul18 = 8, /**< Multiplied by 18 */
  sifive_fe310_prci_pllcfg_f_mul20 = 9, /**< Multiplied by 20 */
  sifive_fe310_prci_pllcfg_f_mul22 = 10, /**< Multiplied by 22 */
  sifive_fe310_prci_pllcfg_f_mul24 = 11, /**< Multiplied by 24 */
  sifive_fe310_prci_pllcfg_f_mul26 = 12, /**< Multiplied by 26 */
  sifive_fe310_prci_pllcfg_f_mul28 = 13, /**< Multiplied by 28 */
  sifive_fe310_prci_pllcfg_f_mul30 = 14, /**< Multiplied by 30 */
  sifive_fe310_prci_pllcfg_f_mul32 = 15, /**< Multiplied by 32 */
  sifive_fe310_prci_pllcfg_f_mul34 = 16, /**< Multiplied by 34 */
  sifive_fe310_prci_pllcfg_f_mul36 = 17, /**< Multiplied by 36 */
  sifive_fe310_prci_pllcfg_f_mul38 = 18, /**< Multiplied by 38 */
  sifive_fe310_prci_pllcfg_f_mul40 = 19, /**< Multiplied by 40 */
  sifive_fe310_prci_pllcfg_f_mul42 = 20, /**< Multiplied by 42 */
  sifive_fe310_prci_pllcfg_f_mul44 = 21, /**< Multiplied by 44 */
  sifive_fe310_prci_pllcfg_f_mul46 = 22, /**< Multiplied by 46 */
  sifive_fe310_prci_pllcfg_f_mul48 = 23, /**< Multiplied by 48 */
  sifive_fe310_prci_pllcfg_f_mul50 = 24, /**< Multiplied by 50 */
  sifive_fe310_prci_pllcfg_f_mul52 = 25, /**< Multiplied by 52 */
  sifive_fe310_prci_pllcfg_f_mul54 = 26, /**< Multiplied by 54 */
  sifive_fe310_prci_pllcfg_f_mul56 = 27, /**< Multiplied by 56 */
  sifive_fe310_prci_pllcfg_f_mul58 = 28, /**< Multiplied by 58 */
  sifive_fe310_prci_pllcfg_f_mul60 = 29, /**< Multiplied by 60 */
  sifive_fe310_prci_pllcfg_f_mul62 = 30, /**< Multiplied by 62 */
  sifive_fe310_prci_pllcfg_f_mul64 = 31, /**< Multiplied by 64 */
  sifive_fe310_prci_pllcfg_f_mul66 = 32, /**< Multiplied by 66 */
  sifive_fe310_prci_pllcfg_f_mul68 = 33, /**< Multiplied by 68 */
  sifive_fe310_prci_pllcfg_f_mul70 = 34, /**< Multiplied by 70 */
  sifive_fe310_prci_pllcfg_f_mul72 = 35, /**< Multiplied by 72 */
  sifive_fe310_prci_pllcfg_f_mul74 = 36, /**< Multiplied by 74 */
  sifive_fe310_prci_pllcfg_f_mul76 = 37, /**< Multiplied by 76 */
  sifive_fe310_prci_pllcfg_f_mul78 = 38, /**< Multiplied by 78 */
  sifive_fe310_prci_pllcfg_f_mul80 = 39, /**< Multiplied by 80 */
  sifive_fe310_prci_pllcfg_f_mul82 = 40, /**< Multiplied by 82 */
  sifive_fe310_prci_pllcfg_f_mul84 = 41, /**< Multiplied by 84 */
  sifive_fe310_prci_pllcfg_f_mul86 = 42, /**< Multiplied by 86 */
  sifive_fe310_prci_pllcfg_f_mul88 = 43, /**< Multiplied by 88 */
  sifive_fe310_prci_pllcfg_f_mul90 = 44, /**< Multiplied by 90 */
  sifive_fe310_prci_pllcfg_f_mul92 = 45, /**< Multiplied by 92 */
  sifive_fe310_prci_pllcfg_f_mul94 = 46, /**< Multiplied by 94 */
  sifive_fe310_prci_pllcfg_f_mul96 = 47, /**< Multiplied by 96 */
  sifive_fe310_prci_pllcfg_f_mul98 = 48, /**< Multiplied by 98 */
  sifive_fe310_prci_pllcfg_f_mul100 = 49, /**< Multiplied by 100 */
  sifive_fe310_prci_pllcfg_f_mul102 = 50, /**< Multiplied by 102 */
  sifive_fe310_prci_pllcfg_f_mul104 = 51, /**< Multiplied by 104 */
  sifive_fe310_prci_pllcfg_f_mul106 = 52, /**< Multiplied by 106 */
  sifive_fe310_prci_pllcfg_f_mul108 = 53, /**< Multiplied by 108 */
  sifive_fe310_prci_pllcfg_f_mul110 = 54, /**< Multiplied by 110 */
  sifive_fe310_prci_pllcfg_f_mul112 = 55, /**< Multiplied by 112 */
  sifive_fe310_prci_pllcfg_f_mul114 = 56, /**< Multiplied by 114 */
  sifive_fe310_prci_pllcfg_f_mul116 = 57, /**< Multiplied by 116 */
  sifive_fe310_prci_pllcfg_f_mul118 = 58, /**< Multiplied by 118 */
  sifive_fe310_prci_pllcfg_f_mul120 = 59, /**< Multiplied by 120 */
  sifive_fe310_prci_pllcfg_f_mul122 = 60, /**< Multiplied by 122 */
  sifive_fe310_prci_pllcfg_f_mul124 = 61, /**< Multiplied by 124 */
  sifive_fe310_prci_pllcfg_f_mul126 = 62, /**< Multiplied by 126 */
  sifive_fe310_prci_pllcfg_f_mul128 = 63, /**< Multiplied by 128 */
} sifive_fe310_prci_pllcfg_f_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief Reference Clock Q Divide Ratio Enumeration.
 */

typedef enum {
  sifive_fe310_prci_pllcfg_q_div2 = 1, /**< Divided by 2 */
  sifive_fe310_prci_pllcfg_q_div4 = 2, /**< Divided by 4 */
  sifive_fe310_prci_pllcfg_q_div8 = 3, /**< Divided by 8 */
} sifive_fe310_prci_pllcfg_q_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief Chip Select Modes Enumeration.
 */

typedef enum {
  sifive_fe310_spi_csmode_mode_auto = 0, /**< Assert/de-assert CS at the beginning/end of each frame */
  sifive_fe310_spi_csmode_mode_hold = 2, /**< Keep CS continuously asserted after the initial frame */
  sifive_fe310_spi_csmode_mode_off = 3, /**< Disable hardware control of the CS pin */
} sifive_fe310_spi_csmode_mode_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief SPI Protocol Enumeration.
 */

typedef enum {
  sifive_fe310_spi_fmt_proto_single = 0, /**< DQ0 (MOSI), DQ1 (MISO) */
  sifive_fe310_spi_fmt_proto_dual = 1, /**< DQ0, DQ1 */
  sifive_fe310_spi_fmt_proto_quad = 2, /**< DQ0, DQ1, DQ2, DQ3 */
} sifive_fe310_spi_fmt_proto_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief SPI Endianness Enumeration.
 */

typedef enum {
  sifive_fe310_spi_fmt_endian_msb = 0, /**< Transmit most-significant bit (MSB) first */
  sifive_fe310_spi_fmt_endian_lsb = 1, /**< Transmit least-significant bit (LSB) first */
} sifive_fe310_spi_fmt_endian_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief SPI I/O Direction Enumeration.
 */

typedef enum {
  sifive_fe310_spi_fmt_dir_rx = 0, /**< For dual and quad protocols, the DQ pins are tri-stated. For the single protocol, the DQ0 pin is driven with the transmit data as normal. */
  sifive_fe310_spi_fmt_dir_tx = 1, /**< The receive FIFO is not populated. */
} sifive_fe310_spi_fmt_dir_enum_t;

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_plic_target0_m_t' positions & masks.

// Register 'plic.target0.m.threshold'.
#define SIFIVE_FE310_PLIC_TARGET0_M_THRESHOLD_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_PLIC_TARGET0_M_THRESHOLD_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] The priority threshold value */

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_plic_t' positions & masks.

// Register 'plic.priorities'.
#define SIFIVE_FE310_PLIC_PRIORITIES_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_PLIC_PRIORITIES_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] The priority for a given global interrupt */

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_wdog_t' positions & masks.

// Register 'wdog.cfg'.
#define SIFIVE_FE310_WDOG_CFG_SCALE_POSITION  (0ul)
#define SIFIVE_FE310_WDOG_CFG_SCALE_MASK  (0xFul << 0ul)  /**< [3..0] Watchdog counter scale */
#define SIFIVE_FE310_WDOG_CFG_RSTEN_POSITION  (8ul)
#define SIFIVE_FE310_WDOG_CFG_RSTEN_MASK  (0x1ul << 8ul)  /**< [8..8] Watchdog full reset enable */
#define SIFIVE_FE310_WDOG_CFG_RSTEN  (1ul << 8ul)
#define SIFIVE_FE310_WDOG_CFG_ZEROCMP_POSITION  (9ul)
#define SIFIVE_FE310_WDOG_CFG_ZEROCMP_MASK  (0x1ul << 9ul)  /**< [9..9] Watchdog zero on comparator */
#define SIFIVE_FE310_WDOG_CFG_ZEROCMP  (1ul << 9ul)
#define SIFIVE_FE310_WDOG_CFG_ENALWAYS_POSITION  (12ul)
#define SIFIVE_FE310_WDOG_CFG_ENALWAYS_MASK  (0x1ul << 12ul)  /**< [12..12] Watchdog enable counter always */
#define SIFIVE_FE310_WDOG_CFG_ENALWAYS  (1ul << 12ul)
#define SIFIVE_FE310_WDOG_CFG_ENCOREAWAKE_POSITION  (13ul)
#define SIFIVE_FE310_WDOG_CFG_ENCOREAWAKE_MASK  (0x1ul << 13ul)  /**< [13..13] Watchdog counter only when awake */
#define SIFIVE_FE310_WDOG_CFG_ENCOREAWAKE  (1ul << 13ul)
#define SIFIVE_FE310_WDOG_CFG_CMPIP_POSITION  (28ul)
#define SIFIVE_FE310_WDOG_CFG_CMPIP_MASK  (0x1ul << 28ul)  /**< [28..28] Watchdog interrupt pending */
#define SIFIVE_FE310_WDOG_CFG_CMPIP  (1ul << 28ul)

// Register 'wdog.scale'.
#define SIFIVE_FE310_WDOG_SCALE_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_WDOG_SCALE_VALUE_MASK  (0xFFFFul << 0ul)  /**< [15..0] Watchdog scale value */

// Register 'wdog.cmp'.
#define SIFIVE_FE310_WDOG_CMP_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_WDOG_CMP_VALUE_MASK  (0xFFFFul << 0ul)  /**< [15..0] Watchdog compare value */

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_rtc_t' positions & masks.

// Register 'rtc.cfg'.
#define SIFIVE_FE310_RTC_CFG_SCALE_POSITION  (0ul)
#define SIFIVE_FE310_RTC_CFG_SCALE_MASK  (0xFul << 0ul)  /**< [3..0] RTC clock rate scale */
#define SIFIVE_FE310_RTC_CFG_ENALWAYS_POSITION  (12ul)
#define SIFIVE_FE310_RTC_CFG_ENALWAYS_MASK  (0x1ul << 12ul)  /**< [12..12] RTC counter enable */
#define SIFIVE_FE310_RTC_CFG_ENALWAYS  (1ul << 12ul)
#define SIFIVE_FE310_RTC_CFG_CMPIP_POSITION  (28ul)
#define SIFIVE_FE310_RTC_CFG_CMPIP_MASK  (0x1ul << 28ul)  /**< [28..28] RTC comparator interrupt pending */
#define SIFIVE_FE310_RTC_CFG_CMPIP  (1ul << 28ul)

// Register 'rtc.high'.
#define SIFIVE_FE310_RTC_HIGH_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_RTC_HIGH_VALUE_MASK  (0xFFFFul << 0ul)  /**< [15..0] RTC counter register, high bits */

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_aon_t' positions & masks.

// Register 'aon.lfrosccfg'.
#define SIFIVE_FE310_AON_LFROSCCFG_DIV_POSITION  (0ul)
#define SIFIVE_FE310_AON_LFROSCCFG_DIV_MASK  (0x3Ful << 0ul)  /**< [5..0] LFROSC divider */
#define SIFIVE_FE310_AON_LFROSCCFG_TRIM_POSITION  (16ul)
#define SIFIVE_FE310_AON_LFROSCCFG_TRIM_MASK  (0x1Ful << 16ul)  /**< [20..16] LFROSC trim value */
#define SIFIVE_FE310_AON_LFROSCCFG_EN_POSITION  (30ul)
#define SIFIVE_FE310_AON_LFROSCCFG_EN_MASK  (0x1ul << 30ul)  /**< [30..30] LFROSC enable */
#define SIFIVE_FE310_AON_LFROSCCFG_EN  (1ul << 30ul)
#define SIFIVE_FE310_AON_LFROSCCFG_RDY_POSITION  (31ul)
#define SIFIVE_FE310_AON_LFROSCCFG_RDY_MASK  (0x1ul << 31ul)  /**< [31..31] LFROSC ready */
#define SIFIVE_FE310_AON_LFROSCCFG_RDY  (1ul << 31ul)

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_pmu_t' positions & masks.

// Register 'pmu.ie'.
#define SIFIVE_FE310_PMU_IE_RTC_POSITION  (1ul)
#define SIFIVE_FE310_PMU_IE_RTC_MASK  (0x1ul << 1ul)  /**< [1..1] RTC Comparator active */
#define SIFIVE_FE310_PMU_IE_RTC  (1ul << 1ul)
#define SIFIVE_FE310_PMU_IE_DWAKEUP_POSITION  (2ul)
#define SIFIVE_FE310_PMU_IE_DWAKEUP_MASK  (0x1ul << 2ul)  /**< [2..2] dwakeup_n pin active */
#define SIFIVE_FE310_PMU_IE_DWAKEUP  (1ul << 2ul)

// Register 'pmu.cause'.
#define SIFIVE_FE310_PMU_CAUSE_WAKEUPCAUSE_POSITION  (0ul)
#define SIFIVE_FE310_PMU_CAUSE_WAKEUPCAUSE_MASK  (0x3ul << 0ul)  /**< [1..0] Wakeup cause */
#define SIFIVE_FE310_PMU_CAUSE_WAKEUPCAUSE_RESET  (0ul << 0ul)  /**< Reset Wakeup */
#define SIFIVE_FE310_PMU_CAUSE_WAKEUPCAUSE_RTC  (1ul << 0ul)  /**< RTC Wakeup */
#define SIFIVE_FE310_PMU_CAUSE_WAKEUPCAUSE_DWAKEUP  (2ul << 0ul)  /**< Digital input Wakeup */
#define SIFIVE_FE310_PMU_CAUSE_RESETCAUSE_POSITION  (8ul)
#define SIFIVE_FE310_PMU_CAUSE_RESETCAUSE_MASK  (0x3ul << 8ul)  /**< [9..8] Reset cause */
#define SIFIVE_FE310_PMU_CAUSE_RESETCAUSE_EXTERNAL  (1ul << 8ul)  /**< External reset */
#define SIFIVE_FE310_PMU_CAUSE_RESETCAUSE_WATCHDOG  (2ul << 8ul)  /**< Watchdog timer reset */

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_prci_t' positions & masks.

// Register 'prci.hfrosccfg'.
#define SIFIVE_FE310_PRCI_HFROSCCFG_DIV_POSITION  (0ul)
#define SIFIVE_FE310_PRCI_HFROSCCFG_DIV_MASK  (0x3Ful << 0ul)  /**< [5..0] HFROSC divider */
#define SIFIVE_FE310_PRCI_HFROSCCFG_TRIM_POSITION  (16ul)
#define SIFIVE_FE310_PRCI_HFROSCCFG_TRIM_MASK  (0x1Ful << 16ul)  /**< [20..16] HFROSC trim value */
#define SIFIVE_FE310_PRCI_HFROSCCFG_EN_POSITION  (30ul)
#define SIFIVE_FE310_PRCI_HFROSCCFG_EN_MASK  (0x1ul << 30ul)  /**< [30..30] HFROSC enable */
#define SIFIVE_FE310_PRCI_HFROSCCFG_EN  (1ul << 30ul)
#define SIFIVE_FE310_PRCI_HFROSCCFG_RDY_POSITION  (31ul)
#define SIFIVE_FE310_PRCI_HFROSCCFG_RDY_MASK  (0x1ul << 31ul)  /**< [31..31] HFROSC ready */
#define SIFIVE_FE310_PRCI_HFROSCCFG_RDY  (1ul << 31ul)

// Register 'prci.hfxosccfg'.
#define SIFIVE_FE310_PRCI_HFXOSCCFG_EN_POSITION  (30ul)
#define SIFIVE_FE310_PRCI_HFXOSCCFG_EN_MASK  (0x1ul << 30ul)  /**< [30..30] HFXOSC enable */
#define SIFIVE_FE310_PRCI_HFXOSCCFG_EN  (1ul << 30ul)
#define SIFIVE_FE310_PRCI_HFXOSCCFG_RDY_POSITION  (31ul)
#define SIFIVE_FE310_PRCI_HFXOSCCFG_RDY_MASK  (0x1ul << 31ul)  /**< [31..31] HFXOSC ready */
#define SIFIVE_FE310_PRCI_HFXOSCCFG_RDY  (1ul << 31ul)

// Register 'prci.pllcfg'.
#define SIFIVE_FE310_PRCI_PLLCFG_R_POSITION  (0ul)
#define SIFIVE_FE310_PRCI_PLLCFG_R_MASK  (0x7ul << 0ul)  /**< [2..0] PLL R input divider value */
#define SIFIVE_FE310_PRCI_PLLCFG_R_DIV1  (0ul << 0ul)  /**< Unchanged */
#define SIFIVE_FE310_PRCI_PLLCFG_R_DIV2  (1ul << 0ul)  /**< Divided by 2 */
#define SIFIVE_FE310_PRCI_PLLCFG_R_DIV3  (2ul << 0ul)  /**< Divided by 3 */
#define SIFIVE_FE310_PRCI_PLLCFG_R_DIV4  (3ul << 0ul)  /**< Divided by 4 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_POSITION  (4ul)
#define SIFIVE_FE310_PRCI_PLLCFG_F_MASK  (0x3Ful << 4ul)  /**< [9..4] PLL F multiplier value */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL2  (0ul << 4ul)  /**< Multiplied by 2 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL4  (1ul << 4ul)  /**< Multiplied by 4 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL6  (2ul << 4ul)  /**< Multiplied by 6 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL8  (3ul << 4ul)  /**< Multiplied by 8 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL10  (4ul << 4ul)  /**< Multiplied by 10 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL12  (5ul << 4ul)  /**< Multiplied by 12 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL14  (6ul << 4ul)  /**< Multiplied by 14 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL16  (7ul << 4ul)  /**< Multiplied by 16 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL18  (8ul << 4ul)  /**< Multiplied by 18 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL20  (9ul << 4ul)  /**< Multiplied by 20 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL22  (10ul << 4ul)  /**< Multiplied by 22 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL24  (11ul << 4ul)  /**< Multiplied by 24 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL26  (12ul << 4ul)  /**< Multiplied by 26 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL28  (13ul << 4ul)  /**< Multiplied by 28 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL30  (14ul << 4ul)  /**< Multiplied by 30 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL32  (15ul << 4ul)  /**< Multiplied by 32 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL34  (16ul << 4ul)  /**< Multiplied by 34 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL36  (17ul << 4ul)  /**< Multiplied by 36 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL38  (18ul << 4ul)  /**< Multiplied by 38 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL40  (19ul << 4ul)  /**< Multiplied by 40 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL42  (20ul << 4ul)  /**< Multiplied by 42 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL44  (21ul << 4ul)  /**< Multiplied by 44 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL46  (22ul << 4ul)  /**< Multiplied by 46 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL48  (23ul << 4ul)  /**< Multiplied by 48 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL50  (24ul << 4ul)  /**< Multiplied by 50 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL52  (25ul << 4ul)  /**< Multiplied by 52 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL54  (26ul << 4ul)  /**< Multiplied by 54 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL56  (27ul << 4ul)  /**< Multiplied by 56 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL58  (28ul << 4ul)  /**< Multiplied by 58 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL60  (29ul << 4ul)  /**< Multiplied by 60 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL62  (30ul << 4ul)  /**< Multiplied by 62 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL64  (31ul << 4ul)  /**< Multiplied by 64 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL66  (32ul << 4ul)  /**< Multiplied by 66 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL68  (33ul << 4ul)  /**< Multiplied by 68 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL70  (34ul << 4ul)  /**< Multiplied by 70 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL72  (35ul << 4ul)  /**< Multiplied by 72 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL74  (36ul << 4ul)  /**< Multiplied by 74 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL76  (37ul << 4ul)  /**< Multiplied by 76 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL78  (38ul << 4ul)  /**< Multiplied by 78 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL80  (39ul << 4ul)  /**< Multiplied by 80 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL82  (40ul << 4ul)  /**< Multiplied by 82 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL84  (41ul << 4ul)  /**< Multiplied by 84 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL86  (42ul << 4ul)  /**< Multiplied by 86 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL88  (43ul << 4ul)  /**< Multiplied by 88 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL90  (44ul << 4ul)  /**< Multiplied by 90 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL92  (45ul << 4ul)  /**< Multiplied by 92 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL94  (46ul << 4ul)  /**< Multiplied by 94 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL96  (47ul << 4ul)  /**< Multiplied by 96 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL98  (48ul << 4ul)  /**< Multiplied by 98 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL100  (49ul << 4ul)  /**< Multiplied by 100 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL102  (50ul << 4ul)  /**< Multiplied by 102 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL104  (51ul << 4ul)  /**< Multiplied by 104 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL106  (52ul << 4ul)  /**< Multiplied by 106 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL108  (53ul << 4ul)  /**< Multiplied by 108 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL110  (54ul << 4ul)  /**< Multiplied by 110 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL112  (55ul << 4ul)  /**< Multiplied by 112 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL114  (56ul << 4ul)  /**< Multiplied by 114 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL116  (57ul << 4ul)  /**< Multiplied by 116 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL118  (58ul << 4ul)  /**< Multiplied by 118 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL120  (59ul << 4ul)  /**< Multiplied by 120 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL122  (60ul << 4ul)  /**< Multiplied by 122 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL124  (61ul << 4ul)  /**< Multiplied by 124 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL126  (62ul << 4ul)  /**< Multiplied by 126 */
#define SIFIVE_FE310_PRCI_PLLCFG_F_MUL128  (63ul << 4ul)  /**< Multiplied by 128 */
#define SIFIVE_FE310_PRCI_PLLCFG_Q_POSITION  (10ul)
#define SIFIVE_FE310_PRCI_PLLCFG_Q_MASK  (0x3ul << 10ul)  /**< [11..10] PLL Q output divider value */
#define SIFIVE_FE310_PRCI_PLLCFG_Q_DIV2  (1ul << 10ul)  /**< Divided by 2 */
#define SIFIVE_FE310_PRCI_PLLCFG_Q_DIV4  (2ul << 10ul)  /**< Divided by 4 */
#define SIFIVE_FE310_PRCI_PLLCFG_Q_DIV8  (3ul << 10ul)  /**< Divided by 8 */
#define SIFIVE_FE310_PRCI_PLLCFG_SEL_POSITION  (16ul)
#define SIFIVE_FE310_PRCI_PLLCFG_SEL_MASK  (0x1ul << 16ul)  /**< [16..16] PLL select */
#define SIFIVE_FE310_PRCI_PLLCFG_SEL  (1ul << 16ul)
#define SIFIVE_FE310_PRCI_PLLCFG_REFSEL_POSITION  (17ul)
#define SIFIVE_FE310_PRCI_PLLCFG_REFSEL_MASK  (0x1ul << 17ul)  /**< [17..17] PLL reference select */
#define SIFIVE_FE310_PRCI_PLLCFG_REFSEL  (1ul << 17ul)
#define SIFIVE_FE310_PRCI_PLLCFG_BYPASS_POSITION  (18ul)
#define SIFIVE_FE310_PRCI_PLLCFG_BYPASS_MASK  (0x1ul << 18ul)  /**< [18..18] PLL bypass */
#define SIFIVE_FE310_PRCI_PLLCFG_BYPASS  (1ul << 18ul)
#define SIFIVE_FE310_PRCI_PLLCFG_LOCK_POSITION  (31ul)
#define SIFIVE_FE310_PRCI_PLLCFG_LOCK_MASK  (0x1ul << 31ul)  /**< [31..31] PLL lock indicator */
#define SIFIVE_FE310_PRCI_PLLCFG_LOCK  (1ul << 31ul)

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_otp_t' positions & masks.

// Register 'otp.rsctrl'.
#define SIFIVE_FE310_OTP_RSCTRL_SCALE_POSITION  (0ul)
#define SIFIVE_FE310_OTP_RSCTRL_SCALE_MASK  (0x3ul << 0ul)  /**< [1..0] OTP timescale */
#define SIFIVE_FE310_OTP_RSCTRL_TAS_POSITION  (3ul)
#define SIFIVE_FE310_OTP_RSCTRL_TAS_MASK  (0x1ul << 3ul)  /**< [3..3] Address setup time */
#define SIFIVE_FE310_OTP_RSCTRL_TAS  (1ul << 3ul)
#define SIFIVE_FE310_OTP_RSCTRL_TRP_POSITION  (4ul)
#define SIFIVE_FE310_OTP_RSCTRL_TRP_MASK  (0x1ul << 4ul)  /**< [4..4] Read pulse time */
#define SIFIVE_FE310_OTP_RSCTRL_TRP  (1ul << 4ul)
#define SIFIVE_FE310_OTP_RSCTRL_TRACC_POSITION  (5ul)
#define SIFIVE_FE310_OTP_RSCTRL_TRACC_MASK  (0x1ul << 5ul)  /**< [5..5] Read access time */
#define SIFIVE_FE310_OTP_RSCTRL_TRACC  (1ul << 5ul)

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_uart_t' positions & masks.

// Register 'uart.txdata'.
#define SIFIVE_FE310_UART_TXDATA_DATA_POSITION  (0ul)
#define SIFIVE_FE310_UART_TXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Transmit data */
#define SIFIVE_FE310_UART_TXDATA_FULL_POSITION  (31ul)
#define SIFIVE_FE310_UART_TXDATA_FULL_MASK  (0x1ul << 31ul)  /**< [31..31] Transmit FIFO full */
#define SIFIVE_FE310_UART_TXDATA_FULL  (1ul << 31ul)

// Register 'uart.rxdata'.
#define SIFIVE_FE310_UART_RXDATA_DATA_POSITION  (0ul)
#define SIFIVE_FE310_UART_RXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Received data */
#define SIFIVE_FE310_UART_RXDATA_EMPTY_POSITION  (31ul)
#define SIFIVE_FE310_UART_RXDATA_EMPTY_MASK  (0x1ul << 31ul)  /**< [31..31] Receive FIFO empty */
#define SIFIVE_FE310_UART_RXDATA_EMPTY  (1ul << 31ul)

// Register 'uart.txctrl'.
#define SIFIVE_FE310_UART_TXCTRL_TXEN_POSITION  (0ul)
#define SIFIVE_FE310_UART_TXCTRL_TXEN_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit enable */
#define SIFIVE_FE310_UART_TXCTRL_TXEN  (1ul << 0ul)
#define SIFIVE_FE310_UART_TXCTRL_NSTOP_POSITION  (1ul)
#define SIFIVE_FE310_UART_TXCTRL_NSTOP_MASK  (0x1ul << 1ul)  /**< [1..1] Number of stop bits */
#define SIFIVE_FE310_UART_TXCTRL_NSTOP  (1ul << 1ul)
#define SIFIVE_FE310_UART_TXCTRL_TXCNT_POSITION  (16ul)
#define SIFIVE_FE310_UART_TXCTRL_TXCNT_MASK  (0x7ul << 16ul)  /**< [18..16] Transmit watermark level */

// Register 'uart.rxctrl'.
#define SIFIVE_FE310_UART_RXCTRL_RXEN_POSITION  (0ul)
#define SIFIVE_FE310_UART_RXCTRL_RXEN_MASK  (0x1ul << 0ul)  /**< [0..0] Receive enable */
#define SIFIVE_FE310_UART_RXCTRL_RXEN  (1ul << 0ul)
#define SIFIVE_FE310_UART_RXCTRL_RXCNT_POSITION  (16ul)
#define SIFIVE_FE310_UART_RXCTRL_RXCNT_MASK  (0x7ul << 16ul)  /**< [18..16] Receive watermark level */

// Register 'uart.ie'.
#define SIFIVE_FE310_UART_IE_TXWM_POSITION  (0ul)
#define SIFIVE_FE310_UART_IE_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark interrupt enable */
#define SIFIVE_FE310_UART_IE_TXWM  (1ul << 0ul)
#define SIFIVE_FE310_UART_IE_RXWM_POSITION  (1ul)
#define SIFIVE_FE310_UART_IE_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark interrupt enable */
#define SIFIVE_FE310_UART_IE_RXWM  (1ul << 1ul)

// Register 'uart.ip'.
#define SIFIVE_FE310_UART_IP_TXWM_POSITION  (0ul)
#define SIFIVE_FE310_UART_IP_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark interrupt pending */
#define SIFIVE_FE310_UART_IP_TXWM  (1ul << 0ul)
#define SIFIVE_FE310_UART_IP_RXWM_POSITION  (1ul)
#define SIFIVE_FE310_UART_IP_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark interrupt pending */
#define SIFIVE_FE310_UART_IP_RXWM  (1ul << 1ul)

// Register 'uart.div'.
#define SIFIVE_FE310_UART_DIV_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_UART_DIV_VALUE_MASK  (0xFFFFul << 0ul)  /**< [15..0] Baud rate divisor */

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_spi_t' positions & masks.

// Register 'spi.sckdiv'.
#define SIFIVE_FE310_SPI_SCKDIV_SCALE_POSITION  (0ul)
#define SIFIVE_FE310_SPI_SCKDIV_SCALE_MASK  (0xFFFul << 0ul)  /**< [11..0] Divisor for serial clock */

// Register 'spi.sckmode'.
#define SIFIVE_FE310_SPI_SCKMODE_PHA_POSITION  (0ul)
#define SIFIVE_FE310_SPI_SCKMODE_PHA_MASK  (0x1ul << 0ul)  /**< [0..0] Serial clock phase */
#define SIFIVE_FE310_SPI_SCKMODE_PHA  (1ul << 0ul)
#define SIFIVE_FE310_SPI_SCKMODE_POL_POSITION  (1ul)
#define SIFIVE_FE310_SPI_SCKMODE_POL_MASK  (0x1ul << 1ul)  /**< [1..1] Serial clock polarity */
#define SIFIVE_FE310_SPI_SCKMODE_POL  (1ul << 1ul)

// Register 'spi.csmode'.
#define SIFIVE_FE310_SPI_CSMODE_MODE_POSITION  (0ul)
#define SIFIVE_FE310_SPI_CSMODE_MODE_MASK  (0x3ul << 0ul)  /**< [1..0] Chip select mode */
#define SIFIVE_FE310_SPI_CSMODE_MODE_AUTO  (0ul << 0ul)  /**< Assert/de-assert CS at the beginning/end of each frame */
#define SIFIVE_FE310_SPI_CSMODE_MODE_HOLD  (2ul << 0ul)  /**< Keep CS continuously asserted after the initial frame */
#define SIFIVE_FE310_SPI_CSMODE_MODE_OFF  (3ul << 0ul)  /**< Disable hardware control of the CS pin */

// Register 'spi.delay0'.
#define SIFIVE_FE310_SPI_DELAY0_CSSCK_POSITION  (0ul)
#define SIFIVE_FE310_SPI_DELAY0_CSSCK_MASK  (0xFFul << 0ul)  /**< [7..0] CS to SCK Delay */
#define SIFIVE_FE310_SPI_DELAY0_SCKCS_POSITION  (16ul)
#define SIFIVE_FE310_SPI_DELAY0_SCKCS_MASK  (0xFFul << 16ul)  /**< [23..16] SCK to CS Delay */

// Register 'spi.delay1'.
#define SIFIVE_FE310_SPI_DELAY1_INTERCS_POSITION  (0ul)
#define SIFIVE_FE310_SPI_DELAY1_INTERCS_MASK  (0xFFul << 0ul)  /**< [7..0] Minimum CS inactive time */
#define SIFIVE_FE310_SPI_DELAY1_INTERXFR_POSITION  (16ul)
#define SIFIVE_FE310_SPI_DELAY1_INTERXFR_MASK  (0xFFul << 16ul)  /**< [23..16] Maximum interframe delay */

// Register 'spi.fmt'.
#define SIFIVE_FE310_SPI_FMT_PROTO_POSITION  (0ul)
#define SIFIVE_FE310_SPI_FMT_PROTO_MASK  (0x3ul << 0ul)  /**< [1..0] SPI Protocol */
#define SIFIVE_FE310_SPI_FMT_PROTO_SINGLE  (0ul << 0ul)  /**< DQ0 (MOSI), DQ1 (MISO) */
#define SIFIVE_FE310_SPI_FMT_PROTO_DUAL  (1ul << 0ul)  /**< DQ0, DQ1 */
#define SIFIVE_FE310_SPI_FMT_PROTO_QUAD  (2ul << 0ul)  /**< DQ0, DQ1, DQ2, DQ3 */
#define SIFIVE_FE310_SPI_FMT_ENDIAN_POSITION  (2ul)
#define SIFIVE_FE310_SPI_FMT_ENDIAN_MASK  (0x1ul << 2ul)  /**< [2..2] SPI endianness */
#define SIFIVE_FE310_SPI_FMT_ENDIAN_MSB  (0ul << 2ul)  /**< Transmit most-significant bit (MSB) first */
#define SIFIVE_FE310_SPI_FMT_ENDIAN_LSB  (1ul << 2ul)  /**< Transmit least-significant bit (LSB) first */
#define SIFIVE_FE310_SPI_FMT_DIR_POSITION  (3ul)
#define SIFIVE_FE310_SPI_FMT_DIR_MASK  (0x1ul << 3ul)  /**< [3..3] SPI I/O Direction */
#define SIFIVE_FE310_SPI_FMT_DIR_RX  (0ul << 3ul)  /**< For dual and quad protocols, the DQ pins are tri-stated. For the single protocol, the DQ0 pin is driven with the transmit data as normal. */
#define SIFIVE_FE310_SPI_FMT_DIR_TX  (1ul << 3ul)  /**< The receive FIFO is not populated. */
#define SIFIVE_FE310_SPI_FMT_LEN_POSITION  (16ul)
#define SIFIVE_FE310_SPI_FMT_LEN_MASK  (0xFul << 16ul)  /**< [19..16] Number of bits per frame */

// Register 'spi.txdata'.
#define SIFIVE_FE310_SPI_TXDATA_DATA_POSITION  (0ul)
#define SIFIVE_FE310_SPI_TXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Transmit data */
#define SIFIVE_FE310_SPI_TXDATA_FULL_POSITION  (31ul)
#define SIFIVE_FE310_SPI_TXDATA_FULL_MASK  (0x1ul << 31ul)  /**< [31..31] FIFO full flag */
#define SIFIVE_FE310_SPI_TXDATA_FULL  (1ul << 31ul)

// Register 'spi.rxdata'.
#define SIFIVE_FE310_SPI_RXDATA_DATA_POSITION  (0ul)
#define SIFIVE_FE310_SPI_RXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Received data */
#define SIFIVE_FE310_SPI_RXDATA_EMPTY_POSITION  (31ul)
#define SIFIVE_FE310_SPI_RXDATA_EMPTY_MASK  (0x1ul << 31ul)  /**< [31..31] FIFO empty flag */
#define SIFIVE_FE310_SPI_RXDATA_EMPTY  (1ul << 31ul)

// Register 'spi.txmark'.
#define SIFIVE_FE310_SPI_TXMARK_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_SPI_TXMARK_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] Transmit watermark */

// Register 'spi.rxmark'.
#define SIFIVE_FE310_SPI_RXMARK_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_SPI_RXMARK_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] Receive watermark */

// Register 'spi.fctrl'.
#define SIFIVE_FE310_SPI_FCTRL_EN_POSITION  (0ul)
#define SIFIVE_FE310_SPI_FCTRL_EN_MASK  (0x1ul << 0ul)  /**< [0..0] SPI Flash Mode Select */
#define SIFIVE_FE310_SPI_FCTRL_EN  (1ul << 0ul)

// Register 'spi.ffmt'.
#define SIFIVE_FE310_SPI_FFMT_CMDEN_POSITION  (0ul)
#define SIFIVE_FE310_SPI_FFMT_CMDEN_MASK  (0x1ul << 0ul)  /**< [0..0] Enable sending of command */
#define SIFIVE_FE310_SPI_FFMT_CMDEN  (1ul << 0ul)
#define SIFIVE_FE310_SPI_FFMT_ADDRLEN_POSITION  (1ul)
#define SIFIVE_FE310_SPI_FFMT_ADDRLEN_MASK  (0x7ul << 1ul)  /**< [3..1] Number of address bytes(0 to 4) */
#define SIFIVE_FE310_SPI_FFMT_PADCNT_POSITION  (4ul)
#define SIFIVE_FE310_SPI_FFMT_PADCNT_MASK  (0xFul << 4ul)  /**< [7..4] Number of dummy cycles */
#define SIFIVE_FE310_SPI_FFMT_CMDPROTO_POSITION  (8ul)
#define SIFIVE_FE310_SPI_FFMT_CMDPROTO_MASK  (0x3ul << 8ul)  /**< [9..8] Protocol for transmitting command */
#define SIFIVE_FE310_SPI_FFMT_ADDRPROTO_POSITION  (10ul)
#define SIFIVE_FE310_SPI_FFMT_ADDRPROTO_MASK  (0x3ul << 10ul)  /**< [11..10] Protocol for transmitting address and padding */
#define SIFIVE_FE310_SPI_FFMT_DATAPROTO_POSITION  (12ul)
#define SIFIVE_FE310_SPI_FFMT_DATAPROTO_MASK  (0x3ul << 12ul)  /**< [13..12] Protocol for receiving data bytes */
#define SIFIVE_FE310_SPI_FFMT_CMDCODE_POSITION  (16ul)
#define SIFIVE_FE310_SPI_FFMT_CMDCODE_MASK  (0xFFul << 16ul)  /**< [23..16] Value of command byte */
#define SIFIVE_FE310_SPI_FFMT_PADCODE_POSITION  (24ul)
#define SIFIVE_FE310_SPI_FFMT_PADCODE_MASK  (0xFFul << 24ul)  /**< [31..24] First 8 bits to transmit during dummy cycles */

// Register 'spi.ie'.
#define SIFIVE_FE310_SPI_IE_TXWM_POSITION  (0ul)
#define SIFIVE_FE310_SPI_IE_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark enable */
#define SIFIVE_FE310_SPI_IE_TXWM  (1ul << 0ul)
#define SIFIVE_FE310_SPI_IE_RXWM_POSITION  (1ul)
#define SIFIVE_FE310_SPI_IE_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark enable */
#define SIFIVE_FE310_SPI_IE_RXWM  (1ul << 1ul)

// Register 'spi.ip'.
#define SIFIVE_FE310_SPI_IP_TXWM_POSITION  (0ul)
#define SIFIVE_FE310_SPI_IP_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark pending */
#define SIFIVE_FE310_SPI_IP_TXWM  (1ul << 0ul)
#define SIFIVE_FE310_SPI_IP_RXWM_POSITION  (1ul)
#define SIFIVE_FE310_SPI_IP_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark pending */
#define SIFIVE_FE310_SPI_IP_RXWM  (1ul << 1ul)

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_pwm0_t' positions & masks.

// Register 'pwm0.cfg'.
#define SIFIVE_FE310_PWM0_CFG_SCALE_POSITION  (0ul)
#define SIFIVE_FE310_PWM0_CFG_SCALE_MASK  (0xFul << 0ul)  /**< [3..0] Counter scale */
#define SIFIVE_FE310_PWM0_CFG_STICKY_POSITION  (8ul)
#define SIFIVE_FE310_PWM0_CFG_STICKY_MASK  (0x1ul << 8ul)  /**< [8..8] Sticky - disallow clearing pwmcmpXip bits */
#define SIFIVE_FE310_PWM0_CFG_STICKY  (1ul << 8ul)
#define SIFIVE_FE310_PWM0_CFG_ZEROCMP_POSITION  (9ul)
#define SIFIVE_FE310_PWM0_CFG_ZEROCMP_MASK  (0x1ul << 9ul)  /**< [9..9] Zero - counter resets to zero after match */
#define SIFIVE_FE310_PWM0_CFG_ZEROCMP  (1ul << 9ul)
#define SIFIVE_FE310_PWM0_CFG_DEGLITCH_POSITION  (10ul)
#define SIFIVE_FE310_PWM0_CFG_DEGLITCH_MASK  (0x1ul << 10ul)  /**< [10..10] Deglitch - latch pwmcmpXip within same cycle */
#define SIFIVE_FE310_PWM0_CFG_DEGLITCH  (1ul << 10ul)
#define SIFIVE_FE310_PWM0_CFG_ENALWAYS_POSITION  (12ul)
#define SIFIVE_FE310_PWM0_CFG_ENALWAYS_MASK  (0x1ul << 12ul)  /**< [12..12] Enable always - run continuously */
#define SIFIVE_FE310_PWM0_CFG_ENALWAYS  (1ul << 12ul)
#define SIFIVE_FE310_PWM0_CFG_ENONESHOT_POSITION  (13ul)
#define SIFIVE_FE310_PWM0_CFG_ENONESHOT_MASK  (0x1ul << 13ul)  /**< [13..13] enable one shot - run one cycle */
#define SIFIVE_FE310_PWM0_CFG_ENONESHOT  (1ul << 13ul)
#define SIFIVE_FE310_PWM0_CFG_CMP0CENTER_POSITION  (16ul)
#define SIFIVE_FE310_PWM0_CFG_CMP0CENTER_MASK  (0x1ul << 16ul)  /**< [16..16] PWM0 Compare Center */
#define SIFIVE_FE310_PWM0_CFG_CMP0CENTER  (1ul << 16ul)
#define SIFIVE_FE310_PWM0_CFG_CMP1CENTER_POSITION  (17ul)
#define SIFIVE_FE310_PWM0_CFG_CMP1CENTER_MASK  (0x1ul << 17ul)  /**< [17..17] PWM1 Compare Center */
#define SIFIVE_FE310_PWM0_CFG_CMP1CENTER  (1ul << 17ul)
#define SIFIVE_FE310_PWM0_CFG_CMP2CENTER_POSITION  (18ul)
#define SIFIVE_FE310_PWM0_CFG_CMP2CENTER_MASK  (0x1ul << 18ul)  /**< [18..18] PWM2 Compare Center */
#define SIFIVE_FE310_PWM0_CFG_CMP2CENTER  (1ul << 18ul)
#define SIFIVE_FE310_PWM0_CFG_CMP3CENTER_POSITION  (19ul)
#define SIFIVE_FE310_PWM0_CFG_CMP3CENTER_MASK  (0x1ul << 19ul)  /**< [19..19] PWM3 Compare Center */
#define SIFIVE_FE310_PWM0_CFG_CMP3CENTER  (1ul << 19ul)
#define SIFIVE_FE310_PWM0_CFG_CMP0GANG_POSITION  (24ul)
#define SIFIVE_FE310_PWM0_CFG_CMP0GANG_MASK  (0x1ul << 24ul)  /**< [24..24] PWM0/PWM1 Compare Gang */
#define SIFIVE_FE310_PWM0_CFG_CMP0GANG  (1ul << 24ul)
#define SIFIVE_FE310_PWM0_CFG_CMP1GANG_POSITION  (25ul)
#define SIFIVE_FE310_PWM0_CFG_CMP1GANG_MASK  (0x1ul << 25ul)  /**< [25..25] PWM1/PWM2 Compare Gang */
#define SIFIVE_FE310_PWM0_CFG_CMP1GANG  (1ul << 25ul)
#define SIFIVE_FE310_PWM0_CFG_CMP2GANG_POSITION  (26ul)
#define SIFIVE_FE310_PWM0_CFG_CMP2GANG_MASK  (0x1ul << 26ul)  /**< [26..26] PWM2/PWM3 Compare Gang */
#define SIFIVE_FE310_PWM0_CFG_CMP2GANG  (1ul << 26ul)
#define SIFIVE_FE310_PWM0_CFG_CMP3GANG_POSITION  (27ul)
#define SIFIVE_FE310_PWM0_CFG_CMP3GANG_MASK  (0x1ul << 27ul)  /**< [27..27] PWM3/PWM0 Compare Gang */
#define SIFIVE_FE310_PWM0_CFG_CMP3GANG  (1ul << 27ul)
#define SIFIVE_FE310_PWM0_CFG_CMP0IP_POSITION  (28ul)
#define SIFIVE_FE310_PWM0_CFG_CMP0IP_MASK  (0x1ul << 28ul)  /**< [28..28] PWM0 Interrupt Pending */
#define SIFIVE_FE310_PWM0_CFG_CMP0IP  (1ul << 28ul)
#define SIFIVE_FE310_PWM0_CFG_CMP1IP_POSITION  (29ul)
#define SIFIVE_FE310_PWM0_CFG_CMP1IP_MASK  (0x1ul << 29ul)  /**< [29..29] PWM1 Interrupt Pending */
#define SIFIVE_FE310_PWM0_CFG_CMP1IP  (1ul << 29ul)
#define SIFIVE_FE310_PWM0_CFG_CMP2IP_POSITION  (30ul)
#define SIFIVE_FE310_PWM0_CFG_CMP2IP_MASK  (0x1ul << 30ul)  /**< [30..30] PWM2 Interrupt Pending */
#define SIFIVE_FE310_PWM0_CFG_CMP2IP  (1ul << 30ul)
#define SIFIVE_FE310_PWM0_CFG_CMP3IP_POSITION  (31ul)
#define SIFIVE_FE310_PWM0_CFG_CMP3IP_MASK  (0x1ul << 31ul)  /**< [31..31] PWM3 Interrupt Pending */
#define SIFIVE_FE310_PWM0_CFG_CMP3IP  (1ul << 31ul)

// Register 'pwm0.scale'.
#define SIFIVE_FE310_PWM0_SCALE_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_PWM0_SCALE_VALUE_MASK  (0xFFul << 0ul)  /**< [7..0] Compare value */

// Register 'pwm0.cmp'.
#define SIFIVE_FE310_PWM0_CMP_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_PWM0_CMP_VALUE_MASK  (0xFFul << 0ul)  /**< [7..0] Compare value */

// ----------------------------------------------------------------------------
// Struct 'sifive_fe310_pwm_t' positions & masks.

// Register 'pwm.cfg'.
#define SIFIVE_FE310_PWM_CFG_SCALE_POSITION  (0ul)
#define SIFIVE_FE310_PWM_CFG_SCALE_MASK  (0xFul << 0ul)  /**< [3..0] Counter scale */
#define SIFIVE_FE310_PWM_CFG_STICKY_POSITION  (8ul)
#define SIFIVE_FE310_PWM_CFG_STICKY_MASK  (0x1ul << 8ul)  /**< [8..8] Sticky - disallow clearing pwmcmpXip bits */
#define SIFIVE_FE310_PWM_CFG_STICKY  (1ul << 8ul)
#define SIFIVE_FE310_PWM_CFG_ZEROCMP_POSITION  (9ul)
#define SIFIVE_FE310_PWM_CFG_ZEROCMP_MASK  (0x1ul << 9ul)  /**< [9..9] Zero - counter resets to zero after match */
#define SIFIVE_FE310_PWM_CFG_ZEROCMP  (1ul << 9ul)
#define SIFIVE_FE310_PWM_CFG_DEGLITCH_POSITION  (10ul)
#define SIFIVE_FE310_PWM_CFG_DEGLITCH_MASK  (0x1ul << 10ul)  /**< [10..10] Deglitch - latch pwmcmpXip within same cycle */
#define SIFIVE_FE310_PWM_CFG_DEGLITCH  (1ul << 10ul)
#define SIFIVE_FE310_PWM_CFG_ENALWAYS_POSITION  (12ul)
#define SIFIVE_FE310_PWM_CFG_ENALWAYS_MASK  (0x1ul << 12ul)  /**< [12..12] Enable always - run continuously */
#define SIFIVE_FE310_PWM_CFG_ENALWAYS  (1ul << 12ul)
#define SIFIVE_FE310_PWM_CFG_ENONESHOT_POSITION  (13ul)
#define SIFIVE_FE310_PWM_CFG_ENONESHOT_MASK  (0x1ul << 13ul)  /**< [13..13] enable one shot - run one cycle */
#define SIFIVE_FE310_PWM_CFG_ENONESHOT  (1ul << 13ul)
#define SIFIVE_FE310_PWM_CFG_CMP0CENTER_POSITION  (16ul)
#define SIFIVE_FE310_PWM_CFG_CMP0CENTER_MASK  (0x1ul << 16ul)  /**< [16..16] PWM0 Compare Center */
#define SIFIVE_FE310_PWM_CFG_CMP0CENTER  (1ul << 16ul)
#define SIFIVE_FE310_PWM_CFG_CMP1CENTER_POSITION  (17ul)
#define SIFIVE_FE310_PWM_CFG_CMP1CENTER_MASK  (0x1ul << 17ul)  /**< [17..17] PWM1 Compare Center */
#define SIFIVE_FE310_PWM_CFG_CMP1CENTER  (1ul << 17ul)
#define SIFIVE_FE310_PWM_CFG_CMP2CENTER_POSITION  (18ul)
#define SIFIVE_FE310_PWM_CFG_CMP2CENTER_MASK  (0x1ul << 18ul)  /**< [18..18] PWM2 Compare Center */
#define SIFIVE_FE310_PWM_CFG_CMP2CENTER  (1ul << 18ul)
#define SIFIVE_FE310_PWM_CFG_CMP3CENTER_POSITION  (19ul)
#define SIFIVE_FE310_PWM_CFG_CMP3CENTER_MASK  (0x1ul << 19ul)  /**< [19..19] PWM3 Compare Center */
#define SIFIVE_FE310_PWM_CFG_CMP3CENTER  (1ul << 19ul)
#define SIFIVE_FE310_PWM_CFG_CMP0GANG_POSITION  (24ul)
#define SIFIVE_FE310_PWM_CFG_CMP0GANG_MASK  (0x1ul << 24ul)  /**< [24..24] PWM0/PWM1 Compare Gang */
#define SIFIVE_FE310_PWM_CFG_CMP0GANG  (1ul << 24ul)
#define SIFIVE_FE310_PWM_CFG_CMP1GANG_POSITION  (25ul)
#define SIFIVE_FE310_PWM_CFG_CMP1GANG_MASK  (0x1ul << 25ul)  /**< [25..25] PWM1/PWM2 Compare Gang */
#define SIFIVE_FE310_PWM_CFG_CMP1GANG  (1ul << 25ul)
#define SIFIVE_FE310_PWM_CFG_CMP2GANG_POSITION  (26ul)
#define SIFIVE_FE310_PWM_CFG_CMP2GANG_MASK  (0x1ul << 26ul)  /**< [26..26] PWM2/PWM3 Compare Gang */
#define SIFIVE_FE310_PWM_CFG_CMP2GANG  (1ul << 26ul)
#define SIFIVE_FE310_PWM_CFG_CMP3GANG_POSITION  (27ul)
#define SIFIVE_FE310_PWM_CFG_CMP3GANG_MASK  (0x1ul << 27ul)  /**< [27..27] PWM3/PWM0 Compare Gang */
#define SIFIVE_FE310_PWM_CFG_CMP3GANG  (1ul << 27ul)
#define SIFIVE_FE310_PWM_CFG_CMP0IP_POSITION  (28ul)
#define SIFIVE_FE310_PWM_CFG_CMP0IP_MASK  (0x1ul << 28ul)  /**< [28..28] PWM0 Interrupt Pending */
#define SIFIVE_FE310_PWM_CFG_CMP0IP  (1ul << 28ul)
#define SIFIVE_FE310_PWM_CFG_CMP1IP_POSITION  (29ul)
#define SIFIVE_FE310_PWM_CFG_CMP1IP_MASK  (0x1ul << 29ul)  /**< [29..29] PWM1 Interrupt Pending */
#define SIFIVE_FE310_PWM_CFG_CMP1IP  (1ul << 29ul)
#define SIFIVE_FE310_PWM_CFG_CMP2IP_POSITION  (30ul)
#define SIFIVE_FE310_PWM_CFG_CMP2IP_MASK  (0x1ul << 30ul)  /**< [30..30] PWM2 Interrupt Pending */
#define SIFIVE_FE310_PWM_CFG_CMP2IP  (1ul << 30ul)
#define SIFIVE_FE310_PWM_CFG_CMP3IP_POSITION  (31ul)
#define SIFIVE_FE310_PWM_CFG_CMP3IP_MASK  (0x1ul << 31ul)  /**< [31..31] PWM3 Interrupt Pending */
#define SIFIVE_FE310_PWM_CFG_CMP3IP  (1ul << 31ul)

// Register 'pwm.scale'.
#define SIFIVE_FE310_PWM_SCALE_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_PWM_SCALE_VALUE_MASK  (0xFFFFul << 0ul)  /**< [15..0] Compare value */

// Register 'pwm.cmp'.
#define SIFIVE_FE310_PWM_CMP_VALUE_POSITION  (0ul)
#define SIFIVE_FE310_PWM_CMP_VALUE_MASK  (0xFFFFul << 0ul)  /**< [15..0] Compare value */

// ----------------------------------------------------------------------------
// Peripheral 'clint' offsets.

#define SIFIVE_FE310_CLINT_MSIP_OFFSET (0x00000000ul)  /**< 0x02000000: MSIP (Machine-mode Software Interrupts) Register per Hart */
#define SIFIVE_FE310_CLINT_MTIMECMP_OFFSET (0x00004000ul)  /**< 0x02004000: Machine Time Compare Registers per Hart */
#define SIFIVE_FE310_CLINT_MTIMECMP_LOW_OFFSET (0x00004000ul)  /**< 0x02004000: Machine Compare Register Low */
#define SIFIVE_FE310_CLINT_MTIMECMP_HIGH_OFFSET (0x00004004ul)  /**< 0x02004004: Machine Compare Register High */
#define SIFIVE_FE310_CLINT_MTIME_OFFSET (0x0000BFF8ul)  /**< 0x0200BFF8: Machine Time Register */
#define SIFIVE_FE310_CLINT_MTIME_LOW_OFFSET (0x0000BFF8ul)  /**< 0x0200BFF8: Machine Time Register Low */
#define SIFIVE_FE310_CLINT_MTIME_HIGH_OFFSET (0x0000BFFCul)  /**< 0x0200BFFC: Machine Time Register High */

// ----------------------------------------------------------------------------
// Peripheral 'plic' offsets.

#define SIFIVE_FE310_PLIC_PRIORITIES_OFFSET (0x00000000ul)  /**< 0x0C000000: Interrupt Priorities Registers; 0 is reserved. */
#define SIFIVE_FE310_PLIC_PENDINGS_OFFSET (0x00001000ul)  /**< 0x0C001000: Interrupt Pending Bits Registers */
#define SIFIVE_FE310_PLIC_ENABLESTARGET0_OFFSET (0x00002000ul)  /**< 0x0C002000: Hart 0 Interrupt Enable Bits */
#define SIFIVE_FE310_PLIC_ENABLESTARGET0_M_OFFSET (0x00002000ul)  /**< 0x0C002000: Hart 0 M-mode Interrupt Enable Bits */
#define SIFIVE_FE310_PLIC_ENABLESTARGET0_M_ENABLES_OFFSET (0x00002000ul)  /**< 0x0C002000: Interrupt Enable Bits Registers */
#define SIFIVE_FE310_PLIC_TARGET0_OFFSET (0x00200000ul)  /**< 0x0C200000: Hart 0 Interrupt Thresholds */
#define SIFIVE_FE310_PLIC_TARGET0_M_OFFSET (0x00200000ul)  /**< 0x0C200000: Hart 0 M-Mode Interrupt Threshold */
#define SIFIVE_FE310_PLIC_TARGET0_M_THRESHOLD_OFFSET (0x00200000ul)  /**< 0x0C200000: The Priority Threshold Register */
#define SIFIVE_FE310_PLIC_TARGET0_M_CLAIMCOMPLETE_OFFSET (0x00200004ul)  /**< 0x0C200004: The Interrupt Claim/Completion Register */

// ----------------------------------------------------------------------------
// Peripheral 'wdog' offsets.

#define SIFIVE_FE310_WDOG_CFG_OFFSET (0x00000000ul)  /**< 0x10000000: Watchdog Configuration Register */
#define SIFIVE_FE310_WDOG_COUNT_OFFSET (0x00000008ul)  /**< 0x10000008: Watchdog Count Register */
#define SIFIVE_FE310_WDOG_SCALE_OFFSET (0x00000010ul)  /**< 0x10000010: Watchdog Scale Register */
#define SIFIVE_FE310_WDOG_FEED_OFFSET (0x00000018ul)  /**< 0x10000018: Watchdog Feed Address Register */
#define SIFIVE_FE310_WDOG_KEY_OFFSET (0x0000001Cul)  /**< 0x1000001C: Watchdog Key Register */
#define SIFIVE_FE310_WDOG_CMP_OFFSET (0x00000020ul)  /**< 0x10000020: Watchdog Compare Register */

// ----------------------------------------------------------------------------
// Peripheral 'rtc' offsets.

#define SIFIVE_FE310_RTC_CFG_OFFSET (0x00000000ul)  /**< 0x10000040: RTC Configuration Register */
#define SIFIVE_FE310_RTC_LOW_OFFSET (0x00000008ul)  /**< 0x10000048: RTC Counter Register Low */
#define SIFIVE_FE310_RTC_HIGH_OFFSET (0x0000000Cul)  /**< 0x1000004C: RTC Counter Register High */
#define SIFIVE_FE310_RTC_SCALE_OFFSET (0x00000010ul)  /**< 0x10000050: RTC Scale Register */
#define SIFIVE_FE310_RTC_CMP_OFFSET (0x00000020ul)  /**< 0x10000060: RTC Compare Register */

// ----------------------------------------------------------------------------
// Peripheral 'aon' offsets.

#define SIFIVE_FE310_AON_LFROSCCFG_OFFSET (0x00000000ul)  /**< 0x10000070: Internal Programmable Low-Frequency Ring Oscillator Register */
#define SIFIVE_FE310_AON_BACKUP_OFFSET (0x00000010ul)  /**< 0x10000080: Backup Registers */

// ----------------------------------------------------------------------------
// Peripheral 'pmu' offsets.

#define SIFIVE_FE310_PMU_WAKEUPI_OFFSET (0x00000000ul)  /**< 0x10000100: Wakeup program instruction Registers */
#define SIFIVE_FE310_PMU_SLEEPI_OFFSET (0x00000020ul)  /**< 0x10000120: Sleep Program Instruction Registers */
#define SIFIVE_FE310_PMU_IE_OFFSET (0x00000040ul)  /**< 0x10000140: PMU Interrupt Enables Register */
#define SIFIVE_FE310_PMU_CAUSE_OFFSET (0x00000044ul)  /**< 0x10000144: PMU Wakeup Cause Register */
#define SIFIVE_FE310_PMU_SLEEP_OFFSET (0x00000048ul)  /**< 0x10000148: PMU Initiate Sleep Sequence Register */
#define SIFIVE_FE310_PMU_KEY_OFFSET (0x0000004Cul)  /**< 0x1000014C: PMU Key Register */

// ----------------------------------------------------------------------------
// Peripheral 'prci' offsets.

#define SIFIVE_FE310_PRCI_HFROSCCFG_OFFSET (0x00000000ul)  /**< 0x10008000: Internal Trimmable Programmable 72 MHz Oscillator Register */
#define SIFIVE_FE310_PRCI_HFXOSCCFG_OFFSET (0x00000004ul)  /**< 0x10008004: External 16 MHz Crystal Oscillator Register */
#define SIFIVE_FE310_PRCI_PLLCFG_OFFSET (0x00000008ul)  /**< 0x10008008: Internal High-Frequency PLL (HFPLL) Register */
#define SIFIVE_FE310_PRCI_PLLOUTDIV_OFFSET (0x0000000Cul)  /**< 0x1000800C: PLL Output Divider */

// ----------------------------------------------------------------------------
// Peripheral 'otp' offsets.

#define SIFIVE_FE310_OTP_LOCK_OFFSET (0x00000000ul)  /**< 0x10010000: Programmed-I/O Lock Register */
#define SIFIVE_FE310_OTP_CK_OFFSET (0x00000004ul)  /**< 0x10010004: Device Clock Signal Register */
#define SIFIVE_FE310_OTP_OE_OFFSET (0x00000008ul)  /**< 0x10010008: Device Output-Enable Signal Register */
#define SIFIVE_FE310_OTP_SEL_OFFSET (0x0000000Cul)  /**< 0x1001000C: Device Chip-Select Signal Register */
#define SIFIVE_FE310_OTP_WE_OFFSET (0x00000010ul)  /**< 0x10010010: Device Write-Enable Signal Register */
#define SIFIVE_FE310_OTP_MR_OFFSET (0x00000014ul)  /**< 0x10010014: Device Mode Register */
#define SIFIVE_FE310_OTP_MRR_OFFSET (0x00000018ul)  /**< 0x10010018: Read-Voltage Regulator Control Register */
#define SIFIVE_FE310_OTP_MPP_OFFSET (0x0000001Cul)  /**< 0x1001001C: Write-Voltage Charge Pump Control Register */
#define SIFIVE_FE310_OTP_VRREN_OFFSET (0x00000020ul)  /**< 0x10010020: Read-Voltage Enable Register */
#define SIFIVE_FE310_OTP_VPPEN_OFFSET (0x00000024ul)  /**< 0x10010024: Write-Voltage Enable Register */
#define SIFIVE_FE310_OTP_A_OFFSET (0x00000028ul)  /**< 0x10010028: Device Address Register */
#define SIFIVE_FE310_OTP_D_OFFSET (0x0000002Cul)  /**< 0x1001002C: Device Data Input Register */
#define SIFIVE_FE310_OTP_Q_OFFSET (0x00000030ul)  /**< 0x10010030: Device Data Output Register */
#define SIFIVE_FE310_OTP_RSCTRL_OFFSET (0x00000034ul)  /**< 0x10010034: Read Sequencer Control Register */

// ----------------------------------------------------------------------------
// Peripheral 'gpio' offsets.

#define SIFIVE_FE310_GPIO_VALUE_OFFSET (0x00000000ul)  /**< 0x10012000: Pin Value Register */
#define SIFIVE_FE310_GPIO_INPUTEN_OFFSET (0x00000004ul)  /**< 0x10012004: Pin Input Enable Register */
#define SIFIVE_FE310_GPIO_OUTPUTEN_OFFSET (0x00000008ul)  /**< 0x10012008: Pin Output Enable Register */
#define SIFIVE_FE310_GPIO_PORT_OFFSET (0x0000000Cul)  /**< 0x1001200C: Output Port Value Register */
#define SIFIVE_FE310_GPIO_PUE_OFFSET (0x00000010ul)  /**< 0x10012010: Internal Pull-up Enable Register */
#define SIFIVE_FE310_GPIO_DS_OFFSET (0x00000014ul)  /**< 0x10012014: Pin Drive Strength Register */
#define SIFIVE_FE310_GPIO_RISEIE_OFFSET (0x00000018ul)  /**< 0x10012018: Rise Interrupt Enable Register */
#define SIFIVE_FE310_GPIO_RISEIP_OFFSET (0x0000001Cul)  /**< 0x1001201C: Rise Interrupt Pending Register */
#define SIFIVE_FE310_GPIO_FALLIE_OFFSET (0x00000020ul)  /**< 0x10012020: Fall Interrupt Enable Register */
#define SIFIVE_FE310_GPIO_FALLIP_OFFSET (0x00000024ul)  /**< 0x10012024: Fall Interrupt Pending Register */
#define SIFIVE_FE310_GPIO_HIGHIE_OFFSET (0x00000028ul)  /**< 0x10012028: High Interrupt Enable Register */
#define SIFIVE_FE310_GPIO_HIGHIP_OFFSET (0x0000002Cul)  /**< 0x1001202C: High Interrupt Pending Register */
#define SIFIVE_FE310_GPIO_LOWIE_OFFSET (0x00000030ul)  /**< 0x10012030: Low Interrupt Enable Register */
#define SIFIVE_FE310_GPIO_LOWIP_OFFSET (0x00000034ul)  /**< 0x10012034: Low Interrupt Pending Register */
#define SIFIVE_FE310_GPIO_IOFEN_OFFSET (0x00000038ul)  /**< 0x10012038: HW I/O Function Enable Register */
#define SIFIVE_FE310_GPIO_IOFSEL_OFFSET (0x0000003Cul)  /**< 0x1001203C: HW I/O Function Select Register */
#define SIFIVE_FE310_GPIO_OUTXOR_OFFSET (0x00000040ul)  /**< 0x10012040: Output XOR (invert) Register */

// ----------------------------------------------------------------------------
// Peripheral 'uart' offsets.

#define SIFIVE_FE310_UART_TXDATA_OFFSET (0x00000000ul)  /**< 0x10013000: Transmit Data Register */
#define SIFIVE_FE310_UART_RXDATA_OFFSET (0x00000004ul)  /**< 0x10013004: Receive Data Register */
#define SIFIVE_FE310_UART_TXCTRL_OFFSET (0x00000008ul)  /**< 0x10013008: Transmit Control Register  */
#define SIFIVE_FE310_UART_RXCTRL_OFFSET (0x0000000Cul)  /**< 0x1001300C: Receive Control Register */
#define SIFIVE_FE310_UART_IE_OFFSET (0x00000010ul)  /**< 0x10013010: Interrupt Enable Register */
#define SIFIVE_FE310_UART_IP_OFFSET (0x00000014ul)  /**< 0x10013014: Interrupt Pending Register */
#define SIFIVE_FE310_UART_DIV_OFFSET (0x00000018ul)  /**< 0x10013018: Baud Rate Divisor Register */

// ----------------------------------------------------------------------------
// Peripheral 'spi' offsets.

#define SIFIVE_FE310_SPI_SCKDIV_OFFSET (0x00000000ul)  /**< 0x10014000: Serial clock divisor Register */
#define SIFIVE_FE310_SPI_SCKMODE_OFFSET (0x00000004ul)  /**< 0x10014004: Serial Clock Mode Register */
#define SIFIVE_FE310_SPI_CSID_OFFSET (0x00000010ul)  /**< 0x10014010: Chip Select ID Register */
#define SIFIVE_FE310_SPI_CSDEF_OFFSET (0x00000014ul)  /**< 0x10014014: Chip Select Default Register */
#define SIFIVE_FE310_SPI_CSMODE_OFFSET (0x00000018ul)  /**< 0x10014018: Chip Select Mode Register */
#define SIFIVE_FE310_SPI_DELAY0_OFFSET (0x00000028ul)  /**< 0x10014028: Delay Control 0 Register */
#define SIFIVE_FE310_SPI_DELAY1_OFFSET (0x0000002Cul)  /**< 0x1001402C: Delay Control 1 Register */
#define SIFIVE_FE310_SPI_FMT_OFFSET (0x00000040ul)  /**< 0x10014040: Frame Format Register */
#define SIFIVE_FE310_SPI_TXDATA_OFFSET (0x00000048ul)  /**< 0x10014048: Tx FIFO Data Register */
#define SIFIVE_FE310_SPI_RXDATA_OFFSET (0x0000004Cul)  /**< 0x1001404C: Rx FIFO Data Register */
#define SIFIVE_FE310_SPI_TXMARK_OFFSET (0x00000050ul)  /**< 0x10014050: Tx FIFO Watermark Register */
#define SIFIVE_FE310_SPI_RXMARK_OFFSET (0x00000054ul)  /**< 0x10014054: Rx FIFO Watermark Register */
#define SIFIVE_FE310_SPI_FCTRL_OFFSET (0x00000060ul)  /**< 0x10014060: Flash Interface Control Register */
#define SIFIVE_FE310_SPI_FFMT_OFFSET (0x00000064ul)  /**< 0x10014064: Flash Instruction Format Register */
#define SIFIVE_FE310_SPI_IE_OFFSET (0x00000070ul)  /**< 0x10014070: Interrupt Enable Register */
#define SIFIVE_FE310_SPI_IP_OFFSET (0x00000074ul)  /**< 0x10014074: Interrupt Pending Register */

// ----------------------------------------------------------------------------
// Peripheral 'pwm0' offsets.

#define SIFIVE_FE310_PWM0_CFG_OFFSET (0x00000000ul)  /**< 0x10015000: Configuration Register */
#define SIFIVE_FE310_PWM0_COUNT_OFFSET (0x00000008ul)  /**< 0x10015008: Configuration Register */
#define SIFIVE_FE310_PWM0_SCALE_OFFSET (0x00000010ul)  /**< 0x10015010: Scale Register */
#define SIFIVE_FE310_PWM0_CMP_OFFSET (0x00000020ul)  /**< 0x10015020: Compare Registers */

// ----------------------------------------------------------------------------
// Peripheral 'pwm' offsets.

#define SIFIVE_FE310_PWM_CFG_OFFSET (0x00000000ul)  /**< 0x10025000: Configuration Register */
#define SIFIVE_FE310_PWM_COUNT_OFFSET (0x00000008ul)  /**< 0x10025008: Configuration Register */
#define SIFIVE_FE310_PWM_SCALE_OFFSET (0x00000010ul)  /**< 0x10025010: Scale Register */
#define SIFIVE_FE310_PWM_CMP_OFFSET (0x00000020ul)  /**< 0x10025020: Compare Registers */

// ----------------------------------------------------------------------------
// Peripherals memory map.

#define SIFIVE_FE310_CLINT_BASE_ADDRESS  (0x02000000ul)
#define SIFIVE_FE310_PLIC_BASE_ADDRESS  (0x0C000000ul)
#define SIFIVE_FE310_WDOG_BASE_ADDRESS  (0x10000000ul)
#define SIFIVE_FE310_RTC_BASE_ADDRESS  (0x10000040ul)
#define SIFIVE_FE310_AON_BASE_ADDRESS  (0x10000070ul)
#define SIFIVE_FE310_PMU_BASE_ADDRESS  (0x10000100ul)
#define SIFIVE_FE310_PRCI_BASE_ADDRESS  (0x10008000ul)
#define SIFIVE_FE310_OTP_BASE_ADDRESS  (0x10010000ul)
#define SIFIVE_FE310_GPIO_BASE_ADDRESS  (0x10012000ul)
#define SIFIVE_FE310_UART0_BASE_ADDRESS  (0x10013000ul)
#define SIFIVE_FE310_SPI0_BASE_ADDRESS  (0x10014000ul)
#define SIFIVE_FE310_PWM0_BASE_ADDRESS  (0x10015000ul)
#define SIFIVE_FE310_UART1_BASE_ADDRESS  (0x10023000ul)
#define SIFIVE_FE310_SPI1_BASE_ADDRESS  (0x10024000ul)
#define SIFIVE_FE310_PWM1_BASE_ADDRESS  (0x10025000ul)
#define SIFIVE_FE310_SPI2_BASE_ADDRESS  (0x10034000ul)
#define SIFIVE_FE310_PWM2_BASE_ADDRESS  (0x10035000ul)

// ----------------------------------------------------------------------------
// Peripherals declarations.

#define CLINT  ((sifive_fe310_clint_t*) SIFIVE_FE310_CLINT_BASE_ADDRESS)
#define PLIC  ((sifive_fe310_plic_t*) SIFIVE_FE310_PLIC_BASE_ADDRESS)
#define WDOG  ((sifive_fe310_wdog_t*) SIFIVE_FE310_WDOG_BASE_ADDRESS)
#define RTC  ((sifive_fe310_rtc_t*) SIFIVE_FE310_RTC_BASE_ADDRESS)
#define AON  ((sifive_fe310_aon_t*) SIFIVE_FE310_AON_BASE_ADDRESS)
#define PMU  ((sifive_fe310_pmu_t*) SIFIVE_FE310_PMU_BASE_ADDRESS)
#define PRCI  ((sifive_fe310_prci_t*) SIFIVE_FE310_PRCI_BASE_ADDRESS)
#define OTP  ((sifive_fe310_otp_t*) SIFIVE_FE310_OTP_BASE_ADDRESS)
#define GPIO  ((sifive_fe310_gpio_t*) SIFIVE_FE310_GPIO_BASE_ADDRESS)
#define UART0  ((sifive_fe310_uart_t*) SIFIVE_FE310_UART0_BASE_ADDRESS)
#define SPI0  ((sifive_fe310_spi_t*) SIFIVE_FE310_SPI0_BASE_ADDRESS)
#define PWM0  ((sifive_fe310_pwm0_t*) SIFIVE_FE310_PWM0_BASE_ADDRESS)
#define UART1  ((sifive_fe310_uart_t*) SIFIVE_FE310_UART1_BASE_ADDRESS)
#define SPI1  ((sifive_fe310_spi_t*) SIFIVE_FE310_SPI1_BASE_ADDRESS)
#define PWM1  ((sifive_fe310_pwm_t*) SIFIVE_FE310_PWM1_BASE_ADDRESS)
#define SPI2  ((sifive_fe310_spi_t*) SIFIVE_FE310_SPI2_BASE_ADDRESS)
#define PWM2  ((sifive_fe310_pwm_t*) SIFIVE_FE310_PWM2_BASE_ADDRESS)

// ----------------------------------------------------------------------------

/**
 * @}
 */ /* End of group device-peripheral-registers */

/**
 * @} 
 */ /* End of group fe310 */

/**
 * @} 
 */ /* End of group sifive */

#if defined(__cplusplus)
}
#endif

// ----------------------------------------------------------------------------

#endif /* SIFIVE_DEVICES_FE310_DEVICE_PERIPHERALS_H_ */
