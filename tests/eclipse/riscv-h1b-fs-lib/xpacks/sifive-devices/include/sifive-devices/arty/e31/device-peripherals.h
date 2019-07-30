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

#ifndef SIFIVE_DEVICES_ARTY_E31_DEVICE_PERIPHERALS_H_
#define SIFIVE_DEVICES_ARTY_E31_DEVICE_PERIPHERALS_H_

// ----------------------------------------------------------------------------

/**
 * @brief µOS++ Core - device peripherals header file
 *  for Core Complex E31 Arty from SiFive, Inc.
 * @version 0.2.0
 * @date 2017-12-12
 * @note Generated from e31arty-xsvd.json@0.2.0 with xsvd@0.3.0.
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
 * @addtogroup e31arty
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
  sifive_e31arty_interrupt_global_uart0 = 1, /**< UART0 Interrupt */
  sifive_e31arty_interrupt_global_switch0 = 2, /**< SWITCH 0 Interrupt */
  sifive_e31arty_interrupt_global_switch1 = 3, /**< SWITCH 1 Interrupt */
  sifive_e31arty_interrupt_global_switch2 = 4, /**< SWITCH 2 Interrupt */
  sifive_e31arty_interrupt_global_switch3 = 5, /**< SWITCH 3 Interrupt */
  sifive_e31arty_interrupt_global_spi0 = 6, /**< SPI0 Interrupt */
  sifive_e31arty_interrupt_global_gpio0 = 7, /**< GPIO0 Interrupt */
  sifive_e31arty_interrupt_global_gpio1 = 8, /**< GPIO1 Interrupt */
  sifive_e31arty_interrupt_global_gpio2 = 9, /**< GPIO2 Interrupt */
  sifive_e31arty_interrupt_global_gpio3 = 10, /**< GPIO3 Interrupt */
  sifive_e31arty_interrupt_global_gpio4 = 11, /**< GPIO4 Interrupt */
  sifive_e31arty_interrupt_global_gpio5 = 12, /**< GPIO5 Interrupt */
  sifive_e31arty_interrupt_global_gpio6 = 13, /**< GPIO6 Interrupt */
  sifive_e31arty_interrupt_global_gpio7 = 14, /**< GPIO7 Interrupt */
  sifive_e31arty_interrupt_global_gpio8 = 15, /**< GPIO8 Interrupt */
  sifive_e31arty_interrupt_global_gpio9 = 16, /**< GPIO9 Interrupt */
  sifive_e31arty_interrupt_global_gpio10 = 17, /**< GPIO10 Interrupt */
  sifive_e31arty_interrupt_global_gpio11 = 18, /**< GPIO11 Interrupt */
  sifive_e31arty_interrupt_global_gpio12 = 19, /**< GPIO12 Interrupt */
  sifive_e31arty_interrupt_global_gpio13 = 20, /**< GPIO13 Interrupt */
  sifive_e31arty_interrupt_global_gpio14 = 21, /**< GPIO14 Interrupt */
  sifive_e31arty_interrupt_global_gpio15 = 22, /**< GPIO15 Interrupt */
  sifive_e31arty_interrupt_global_pwm0cmp0 = 23, /**< PWM0 Compare 0 Interrupt */
  sifive_e31arty_interrupt_global_pwm0cmp1 = 24, /**< PWM0 Compare 1 Interrupt */
  sifive_e31arty_interrupt_global_pwm0cmp2 = 25, /**< PWM0 Compare 2 Interrupt */
  sifive_e31arty_interrupt_global_pwm0cmp3 = 26, /**< PWM0 Compare 3 Interrupt */
} riscv_interrupts_global_enum_t;

#define RISCV_INTERRUPTS_GLOBAL_PRIORITY_BITS  (3u)
#define RISCV_INTERRUPTS_GLOBAL_PRIORITY_LEVELS  (7u)
#define RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER  (26u)

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
} sifive_e31arty_clint_mtimecmp_t; // 0x02004007

// ----------------------------------------------------------------------------

/**
 * @brief Machine Time Register.
 */

typedef struct {
  I__  uint32_t low;  /**< @0x0200BFF8: Machine Time Register Low */
  I__  uint32_t high;  /**< @0x0200BFFC: Machine Time Register High */
} sifive_e31arty_clint_mtime_t; // 0x0200BFFF

// ----------------------------------------------------------------------------

/**
 * @brief Core Complex Local Interruptor (CLINT) Peripheral.
 */

typedef struct {
  IO__ uint32_t msip[1];  /**< @0x02000000: MSIP (Machine-mode Software Interrupts) Register per Hart */
       uint32_t reserved1[4095];
       sifive_e31arty_clint_mtimecmp_t mtimecmp[1];  /**< @0x02004000: Machine Time Compare Registers per Hart */
       uint64_t reserved2[4094];
       sifive_e31arty_clint_mtime_t mtime;  /**< @0x0200BFF8: Machine Time Register */
       uint32_t reserved3[4096];
} sifive_e31arty_clint_t; // 0x0200FFFF

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 M-mode Interrupt Enable Bits.
 */

typedef struct {
  IO__ uint32_t enables[8];  /**< @0x0C002000: Interrupt Enable Bits Registers */
} sifive_e31arty_plic_enablestarget0_m_t; // 0x0C00201F

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 Interrupt Enable Bits.
 */

typedef struct {
       sifive_e31arty_plic_enablestarget0_m_t m;  /**< @0x0C002000: Hart 0 M-mode Interrupt Enable Bits */
} sifive_e31arty_plic_enablestarget0_t; // 0x0C00201F

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 M-Mode Interrupt Threshold.
 */

typedef struct {
  IO__ uint32_t threshold;  /**< @0x0C200000: The Priority Threshold Register */
  IO__ uint32_t claimcomplete;  /**< @0x0C200004: The Interrupt Claim/Completion Register */
} sifive_e31arty_plic_target0_m_t; // 0x0C200007

// ----------------------------------------------------------------------------

/**
 * @brief Hart 0 Interrupt Thresholds.
 */

typedef struct {
       sifive_e31arty_plic_target0_m_t m;  /**< @0x0C200000: Hart 0 M-Mode Interrupt Threshold */
} sifive_e31arty_plic_target0_t; // 0x0C200007

// ----------------------------------------------------------------------------

/**
 * @brief Platform-Level Interrupt Controller (PLIC) Peripheral.
 */

typedef struct {
  IO__ uint32_t priorities[27];  /**< @0x0C000000: Interrupt Priorities Registers; 0 is reserved. */
       uint32_t reserved1[997];
  I__  uint32_t pendings[8];  /**< @0x0C001000: Interrupt Pending Bits Registers */
       uint32_t reserved2[1016];
       sifive_e31arty_plic_enablestarget0_t enablestarget0;  /**< @0x0C002000: Hart 0 Interrupt Enable Bits */
       uint32_t reserved3[522232];
       sifive_e31arty_plic_target0_t target0;  /**< @0x0C200000: Hart 0 Interrupt Thresholds */
       uint32_t reserved4[16252926];
} sifive_e31arty_plic_t; // 0x0FFFFFFF

// ----------------------------------------------------------------------------

/**
 * @brief Universal Asynchronous Receiver/Transmitter (UART) Peripheral.
 */

typedef struct {
  IO__ uint32_t txdata;  /**< @0x20000000: Transmit Data Register */
  IO__ uint32_t rxdata;  /**< @0x20000004: Receive Data Register */
  IO__ uint32_t txctrl;  /**< @0x20000008: Transmit Control Register  */
  IO__ uint32_t rxctrl;  /**< @0x2000000C: Receive Control Register */
  IO__ uint32_t ie;  /**< @0x20000010: Interrupt Enable Register */
  I__  uint32_t ip;  /**< @0x20000014: Interrupt Pending Register */
  IO__ uint32_t div;  /**< @0x20000018: Baud Rate Divisor Register */
       uint32_t reserved1[1017];
} sifive_e31arty_uart_t; // 0x20000FFF

// ----------------------------------------------------------------------------

/**
 * @brief General Purpose Input/Output Controller (GPIO) Peripheral.
 */

typedef struct {
  IO__ uint32_t value;  /**< @0x20002000: Pin Value Register */
  IO__ uint32_t inputen;  /**< @0x20002004: Pin Input Enable Register */
  IO__ uint32_t outputen;  /**< @0x20002008: Pin Output Enable Register */
  IO__ uint32_t port;  /**< @0x2000200C: Output Port Value Register */
  IO__ uint32_t pue;  /**< @0x20002010: Internal Pull-up Enable Register */
  IO__ uint32_t ds;  /**< @0x20002014: Pin Drive Strength Register */
  IO__ uint32_t riseie;  /**< @0x20002018: Rise Interrupt Enable Register */
  IO__ uint32_t riseip;  /**< @0x2000201C: Rise Interrupt Pending Register */
  IO__ uint32_t fallie;  /**< @0x20002020: Fall Interrupt Enable Register */
  IO__ uint32_t fallip;  /**< @0x20002024: Fall Interrupt Pending Register */
  IO__ uint32_t highie;  /**< @0x20002028: High Interrupt Enable Register */
  IO__ uint32_t highip;  /**< @0x2000202C: High Interrupt Pending Register */
  IO__ uint32_t lowie;  /**< @0x20002030: Low Interrupt Enable Register */
  IO__ uint32_t lowip;  /**< @0x20002034: Low Interrupt Pending Register */
  IO__ uint32_t iofen;  /**< @0x20002038: HW I/O Function Enable Register */
  IO__ uint32_t iofsel;  /**< @0x2000203C: HW I/O Function Select Register */
  IO__ uint32_t outxor;  /**< @0x20002040: Output XOR (invert) Register */
       uint32_t reserved1[1007];
} sifive_e31arty_gpio_t; // 0x20002FFF

// ----------------------------------------------------------------------------

/**
 * @brief Serial Peripheral Interface (SPI) Peripheral.
 */

typedef struct {
  IO__ uint32_t sckdiv;  /**< @0x20004000: Serial clock divisor Register */
  IO__ uint32_t sckmode;  /**< @0x20004004: Serial Clock Mode Register */
       uint32_t reserved1[2];
  IO__ uint32_t csid;  /**< @0x20004010: Chip Select ID Register */
  IO__ uint32_t csdef;  /**< @0x20004014: Chip Select Default Register */
  IO__ uint32_t csmode;  /**< @0x20004018: Chip Select Mode Register */
       uint32_t reserved2[3];
  IO__ uint32_t delay0;  /**< @0x20004028: Delay Control 0 Register */
  IO__ uint32_t delay1;  /**< @0x2000402C: Delay Control 1 Register */
       uint32_t reserved3[4];
  IO__ uint32_t fmt;  /**< @0x20004040: Frame Format Register */
       uint32_t reserved4;
  IO__ uint32_t txdata;  /**< @0x20004048: Tx FIFO Data Register */
  I__  uint32_t rxdata;  /**< @0x2000404C: Rx FIFO Data Register */
  IO__ uint32_t txmark;  /**< @0x20004050: Tx FIFO Watermark Register */
  IO__ uint32_t rxmark;  /**< @0x20004054: Rx FIFO Watermark Register */
       uint32_t reserved5[2];
  IO__ uint32_t fctrl;  /**< @0x20004060: Flash Interface Control Register */
  IO__ uint32_t ffmt;  /**< @0x20004064: Flash Instruction Format Register */
       uint32_t reserved6[2];
  IO__ uint32_t ie;  /**< @0x20004070: Interrupt Enable Register */
  IO__ uint32_t ip;  /**< @0x20004074: Interrupt Pending Register */
       uint32_t reserved7[994];
} sifive_e31arty_spi_t; // 0x20004FFF

// ----------------------------------------------------------------------------

/**
 * @brief Pulse-Width Modulation (PWM) Peripheral.
 */

typedef struct {
  IO__ uint32_t cfg;  /**< @0x20005000: Configuration Register */
       uint32_t reserved1;
  IO__ uint32_t count;  /**< @0x20005008: Configuration Register */
       uint32_t reserved2;
  IO__ uint32_t scale;  /**< @0x20005010: Scale Register */
       uint32_t reserved3[3];
  IO__ uint32_t cmp[4];  /**< @0x20005020: Compare Registers */
       uint32_t reserved4[1012];
} sifive_e31arty_pwm_t; // 0x20005FFF

// ----------------------------------------------------------------------------

/**
 * @brief Chip Select Modes Enumeration.
 */

typedef enum {
  sifive_e31arty_spi_csmode_mode_auto = 0, /**< Assert/de-assert CS at the beginning/end of each frame */
  sifive_e31arty_spi_csmode_mode_hold = 2, /**< Keep CS continuously asserted after the initial frame */
  sifive_e31arty_spi_csmode_mode_off = 3, /**< Disable hardware control of the CS pin */
} sifive_e31arty_spi_csmode_mode_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief SPI Protocol Enumeration.
 */

typedef enum {
  sifive_e31arty_spi_fmt_proto_single = 0, /**< DQ0 (MOSI), DQ1 (MISO) */
  sifive_e31arty_spi_fmt_proto_dual = 1, /**< DQ0, DQ1 */
  sifive_e31arty_spi_fmt_proto_quad = 2, /**< DQ0, DQ1, DQ2, DQ3 */
} sifive_e31arty_spi_fmt_proto_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief SPI Endianness Enumeration.
 */

typedef enum {
  sifive_e31arty_spi_fmt_endian_msb = 0, /**< Transmit most-significant bit (MSB) first */
  sifive_e31arty_spi_fmt_endian_lsb = 1, /**< Transmit least-significant bit (LSB) first */
} sifive_e31arty_spi_fmt_endian_enum_t;

// ----------------------------------------------------------------------------

/**
 * @brief SPI I/O Direction Enumeration.
 */

typedef enum {
  sifive_e31arty_spi_fmt_dir_rx = 0, /**< For dual and quad protocols, the DQ pins are tri-stated. For the single protocol, the DQ0 pin is driven with the transmit data as normal. */
  sifive_e31arty_spi_fmt_dir_tx = 1, /**< The receive FIFO is not populated. */
} sifive_e31arty_spi_fmt_dir_enum_t;

// ----------------------------------------------------------------------------
// Struct 'sifive_e31arty_plic_target0_m_t' positions & masks.

// Register 'plic.target0.m.threshold'.
#define SIFIVE_E31ARTY_PLIC_TARGET0_M_THRESHOLD_VALUE_POSITION  (0ul)
#define SIFIVE_E31ARTY_PLIC_TARGET0_M_THRESHOLD_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] The priority threshold value */

// ----------------------------------------------------------------------------
// Struct 'sifive_e31arty_plic_t' positions & masks.

// Register 'plic.priorities'.
#define SIFIVE_E31ARTY_PLIC_PRIORITIES_VALUE_POSITION  (0ul)
#define SIFIVE_E31ARTY_PLIC_PRIORITIES_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] The priority for a given global interrupt */

// ----------------------------------------------------------------------------
// Struct 'sifive_e31arty_uart_t' positions & masks.

// Register 'uart.txdata'.
#define SIFIVE_E31ARTY_UART_TXDATA_DATA_POSITION  (0ul)
#define SIFIVE_E31ARTY_UART_TXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Transmit data */
#define SIFIVE_E31ARTY_UART_TXDATA_FULL_POSITION  (31ul)
#define SIFIVE_E31ARTY_UART_TXDATA_FULL_MASK  (0x1ul << 31ul)  /**< [31..31] Transmit FIFO full */
#define SIFIVE_E31ARTY_UART_TXDATA_FULL  (1ul << 31ul)

// Register 'uart.rxdata'.
#define SIFIVE_E31ARTY_UART_RXDATA_DATA_POSITION  (0ul)
#define SIFIVE_E31ARTY_UART_RXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Received data */
#define SIFIVE_E31ARTY_UART_RXDATA_EMPTY_POSITION  (31ul)
#define SIFIVE_E31ARTY_UART_RXDATA_EMPTY_MASK  (0x1ul << 31ul)  /**< [31..31] Receive FIFO empty */
#define SIFIVE_E31ARTY_UART_RXDATA_EMPTY  (1ul << 31ul)

// Register 'uart.txctrl'.
#define SIFIVE_E31ARTY_UART_TXCTRL_TXEN_POSITION  (0ul)
#define SIFIVE_E31ARTY_UART_TXCTRL_TXEN_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit enable */
#define SIFIVE_E31ARTY_UART_TXCTRL_TXEN  (1ul << 0ul)
#define SIFIVE_E31ARTY_UART_TXCTRL_NSTOP_POSITION  (1ul)
#define SIFIVE_E31ARTY_UART_TXCTRL_NSTOP_MASK  (0x1ul << 1ul)  /**< [1..1] Number of stop bits */
#define SIFIVE_E31ARTY_UART_TXCTRL_NSTOP  (1ul << 1ul)
#define SIFIVE_E31ARTY_UART_TXCTRL_TXCNT_POSITION  (16ul)
#define SIFIVE_E31ARTY_UART_TXCTRL_TXCNT_MASK  (0x7ul << 16ul)  /**< [18..16] Transmit watermark level */

// Register 'uart.rxctrl'.
#define SIFIVE_E31ARTY_UART_RXCTRL_RXEN_POSITION  (0ul)
#define SIFIVE_E31ARTY_UART_RXCTRL_RXEN_MASK  (0x1ul << 0ul)  /**< [0..0] Receive enable */
#define SIFIVE_E31ARTY_UART_RXCTRL_RXEN  (1ul << 0ul)
#define SIFIVE_E31ARTY_UART_RXCTRL_RXCNT_POSITION  (16ul)
#define SIFIVE_E31ARTY_UART_RXCTRL_RXCNT_MASK  (0x7ul << 16ul)  /**< [18..16] Receive watermark level */

// Register 'uart.ie'.
#define SIFIVE_E31ARTY_UART_IE_TXWM_POSITION  (0ul)
#define SIFIVE_E31ARTY_UART_IE_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark interrupt enable */
#define SIFIVE_E31ARTY_UART_IE_TXWM  (1ul << 0ul)
#define SIFIVE_E31ARTY_UART_IE_RXWM_POSITION  (1ul)
#define SIFIVE_E31ARTY_UART_IE_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark interrupt enable */
#define SIFIVE_E31ARTY_UART_IE_RXWM  (1ul << 1ul)

// Register 'uart.ip'.
#define SIFIVE_E31ARTY_UART_IP_TXWM_POSITION  (0ul)
#define SIFIVE_E31ARTY_UART_IP_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark interrupt pending */
#define SIFIVE_E31ARTY_UART_IP_TXWM  (1ul << 0ul)
#define SIFIVE_E31ARTY_UART_IP_RXWM_POSITION  (1ul)
#define SIFIVE_E31ARTY_UART_IP_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark interrupt pending */
#define SIFIVE_E31ARTY_UART_IP_RXWM  (1ul << 1ul)

// Register 'uart.div'.
#define SIFIVE_E31ARTY_UART_DIV_VALUE_POSITION  (0ul)
#define SIFIVE_E31ARTY_UART_DIV_VALUE_MASK  (0xFFFFul << 0ul)  /**< [15..0] Baud rate divisor */

// ----------------------------------------------------------------------------
// Struct 'sifive_e31arty_spi_t' positions & masks.

// Register 'spi.sckdiv'.
#define SIFIVE_E31ARTY_SPI_SCKDIV_SCALE_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_SCKDIV_SCALE_MASK  (0xFFFul << 0ul)  /**< [11..0] Divisor for serial clock */

// Register 'spi.sckmode'.
#define SIFIVE_E31ARTY_SPI_SCKMODE_PHA_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_SCKMODE_PHA_MASK  (0x1ul << 0ul)  /**< [0..0] Serial clock phase */
#define SIFIVE_E31ARTY_SPI_SCKMODE_PHA  (1ul << 0ul)
#define SIFIVE_E31ARTY_SPI_SCKMODE_POL_POSITION  (1ul)
#define SIFIVE_E31ARTY_SPI_SCKMODE_POL_MASK  (0x1ul << 1ul)  /**< [1..1] Serial clock polarity */
#define SIFIVE_E31ARTY_SPI_SCKMODE_POL  (1ul << 1ul)

// Register 'spi.csmode'.
#define SIFIVE_E31ARTY_SPI_CSMODE_MODE_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_CSMODE_MODE_MASK  (0x3ul << 0ul)  /**< [1..0] Chip select mode */
#define SIFIVE_E31ARTY_SPI_CSMODE_MODE_AUTO  (0ul << 0ul)  /**< Assert/de-assert CS at the beginning/end of each frame */
#define SIFIVE_E31ARTY_SPI_CSMODE_MODE_HOLD  (2ul << 0ul)  /**< Keep CS continuously asserted after the initial frame */
#define SIFIVE_E31ARTY_SPI_CSMODE_MODE_OFF  (3ul << 0ul)  /**< Disable hardware control of the CS pin */

// Register 'spi.delay0'.
#define SIFIVE_E31ARTY_SPI_DELAY0_CSSCK_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_DELAY0_CSSCK_MASK  (0xFFul << 0ul)  /**< [7..0] CS to SCK Delay */
#define SIFIVE_E31ARTY_SPI_DELAY0_SCKCS_POSITION  (16ul)
#define SIFIVE_E31ARTY_SPI_DELAY0_SCKCS_MASK  (0xFFul << 16ul)  /**< [23..16] SCK to CS Delay */

// Register 'spi.delay1'.
#define SIFIVE_E31ARTY_SPI_DELAY1_INTERCS_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_DELAY1_INTERCS_MASK  (0xFFul << 0ul)  /**< [7..0] Minimum CS inactive time */
#define SIFIVE_E31ARTY_SPI_DELAY1_INTERXFR_POSITION  (16ul)
#define SIFIVE_E31ARTY_SPI_DELAY1_INTERXFR_MASK  (0xFFul << 16ul)  /**< [23..16] Maximum interframe delay */

// Register 'spi.fmt'.
#define SIFIVE_E31ARTY_SPI_FMT_PROTO_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_FMT_PROTO_MASK  (0x3ul << 0ul)  /**< [1..0] SPI Protocol */
#define SIFIVE_E31ARTY_SPI_FMT_PROTO_SINGLE  (0ul << 0ul)  /**< DQ0 (MOSI), DQ1 (MISO) */
#define SIFIVE_E31ARTY_SPI_FMT_PROTO_DUAL  (1ul << 0ul)  /**< DQ0, DQ1 */
#define SIFIVE_E31ARTY_SPI_FMT_PROTO_QUAD  (2ul << 0ul)  /**< DQ0, DQ1, DQ2, DQ3 */
#define SIFIVE_E31ARTY_SPI_FMT_ENDIAN_POSITION  (2ul)
#define SIFIVE_E31ARTY_SPI_FMT_ENDIAN_MASK  (0x1ul << 2ul)  /**< [2..2] SPI endianness */
#define SIFIVE_E31ARTY_SPI_FMT_ENDIAN_MSB  (0ul << 2ul)  /**< Transmit most-significant bit (MSB) first */
#define SIFIVE_E31ARTY_SPI_FMT_ENDIAN_LSB  (1ul << 2ul)  /**< Transmit least-significant bit (LSB) first */
#define SIFIVE_E31ARTY_SPI_FMT_DIR_POSITION  (3ul)
#define SIFIVE_E31ARTY_SPI_FMT_DIR_MASK  (0x1ul << 3ul)  /**< [3..3] SPI I/O Direction */
#define SIFIVE_E31ARTY_SPI_FMT_DIR_RX  (0ul << 3ul)  /**< For dual and quad protocols, the DQ pins are tri-stated. For the single protocol, the DQ0 pin is driven with the transmit data as normal. */
#define SIFIVE_E31ARTY_SPI_FMT_DIR_TX  (1ul << 3ul)  /**< The receive FIFO is not populated. */
#define SIFIVE_E31ARTY_SPI_FMT_LEN_POSITION  (16ul)
#define SIFIVE_E31ARTY_SPI_FMT_LEN_MASK  (0xFul << 16ul)  /**< [19..16] Number of bits per frame */

// Register 'spi.txdata'.
#define SIFIVE_E31ARTY_SPI_TXDATA_DATA_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_TXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Transmit data */
#define SIFIVE_E31ARTY_SPI_TXDATA_FULL_POSITION  (31ul)
#define SIFIVE_E31ARTY_SPI_TXDATA_FULL_MASK  (0x1ul << 31ul)  /**< [31..31] FIFO full flag */
#define SIFIVE_E31ARTY_SPI_TXDATA_FULL  (1ul << 31ul)

// Register 'spi.rxdata'.
#define SIFIVE_E31ARTY_SPI_RXDATA_DATA_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_RXDATA_DATA_MASK  (0xFFul << 0ul)  /**< [7..0] Received data */
#define SIFIVE_E31ARTY_SPI_RXDATA_EMPTY_POSITION  (31ul)
#define SIFIVE_E31ARTY_SPI_RXDATA_EMPTY_MASK  (0x1ul << 31ul)  /**< [31..31] FIFO empty flag */
#define SIFIVE_E31ARTY_SPI_RXDATA_EMPTY  (1ul << 31ul)

// Register 'spi.txmark'.
#define SIFIVE_E31ARTY_SPI_TXMARK_VALUE_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_TXMARK_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] Transmit watermark */

// Register 'spi.rxmark'.
#define SIFIVE_E31ARTY_SPI_RXMARK_VALUE_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_RXMARK_VALUE_MASK  (0x7ul << 0ul)  /**< [2..0] Receive watermark */

// Register 'spi.fctrl'.
#define SIFIVE_E31ARTY_SPI_FCTRL_EN_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_FCTRL_EN_MASK  (0x1ul << 0ul)  /**< [0..0] SPI Flash Mode Select */
#define SIFIVE_E31ARTY_SPI_FCTRL_EN  (1ul << 0ul)

// Register 'spi.ffmt'.
#define SIFIVE_E31ARTY_SPI_FFMT_CMDEN_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_FFMT_CMDEN_MASK  (0x1ul << 0ul)  /**< [0..0] Enable sending of command */
#define SIFIVE_E31ARTY_SPI_FFMT_CMDEN  (1ul << 0ul)
#define SIFIVE_E31ARTY_SPI_FFMT_ADDRLEN_POSITION  (1ul)
#define SIFIVE_E31ARTY_SPI_FFMT_ADDRLEN_MASK  (0x7ul << 1ul)  /**< [3..1] Number of address bytes(0 to 4) */
#define SIFIVE_E31ARTY_SPI_FFMT_PADCNT_POSITION  (4ul)
#define SIFIVE_E31ARTY_SPI_FFMT_PADCNT_MASK  (0xFul << 4ul)  /**< [7..4] Number of dummy cycles */
#define SIFIVE_E31ARTY_SPI_FFMT_CMDPROTO_POSITION  (8ul)
#define SIFIVE_E31ARTY_SPI_FFMT_CMDPROTO_MASK  (0x3ul << 8ul)  /**< [9..8] Protocol for transmitting command */
#define SIFIVE_E31ARTY_SPI_FFMT_ADDRPROTO_POSITION  (10ul)
#define SIFIVE_E31ARTY_SPI_FFMT_ADDRPROTO_MASK  (0x3ul << 10ul)  /**< [11..10] Protocol for transmitting address and padding */
#define SIFIVE_E31ARTY_SPI_FFMT_DATAPROTO_POSITION  (12ul)
#define SIFIVE_E31ARTY_SPI_FFMT_DATAPROTO_MASK  (0x3ul << 12ul)  /**< [13..12] Protocol for receiving data bytes */
#define SIFIVE_E31ARTY_SPI_FFMT_CMDCODE_POSITION  (16ul)
#define SIFIVE_E31ARTY_SPI_FFMT_CMDCODE_MASK  (0xFFul << 16ul)  /**< [23..16] Value of command byte */
#define SIFIVE_E31ARTY_SPI_FFMT_PADCODE_POSITION  (24ul)
#define SIFIVE_E31ARTY_SPI_FFMT_PADCODE_MASK  (0xFFul << 24ul)  /**< [31..24] First 8 bits to transmit during dummy cycles */

// Register 'spi.ie'.
#define SIFIVE_E31ARTY_SPI_IE_TXWM_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_IE_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark enable */
#define SIFIVE_E31ARTY_SPI_IE_TXWM  (1ul << 0ul)
#define SIFIVE_E31ARTY_SPI_IE_RXWM_POSITION  (1ul)
#define SIFIVE_E31ARTY_SPI_IE_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark enable */
#define SIFIVE_E31ARTY_SPI_IE_RXWM  (1ul << 1ul)

// Register 'spi.ip'.
#define SIFIVE_E31ARTY_SPI_IP_TXWM_POSITION  (0ul)
#define SIFIVE_E31ARTY_SPI_IP_TXWM_MASK  (0x1ul << 0ul)  /**< [0..0] Transmit watermark pending */
#define SIFIVE_E31ARTY_SPI_IP_TXWM  (1ul << 0ul)
#define SIFIVE_E31ARTY_SPI_IP_RXWM_POSITION  (1ul)
#define SIFIVE_E31ARTY_SPI_IP_RXWM_MASK  (0x1ul << 1ul)  /**< [1..1] Receive watermark pending */
#define SIFIVE_E31ARTY_SPI_IP_RXWM  (1ul << 1ul)

// ----------------------------------------------------------------------------
// Struct 'sifive_e31arty_pwm_t' positions & masks.

// Register 'pwm.cfg'.
#define SIFIVE_E31ARTY_PWM_CFG_SCALE_POSITION  (0ul)
#define SIFIVE_E31ARTY_PWM_CFG_SCALE_MASK  (0xFul << 0ul)  /**< [3..0] Counter scale */
#define SIFIVE_E31ARTY_PWM_CFG_STICKY_POSITION  (8ul)
#define SIFIVE_E31ARTY_PWM_CFG_STICKY_MASK  (0x1ul << 8ul)  /**< [8..8] Sticky - disallow clearing pwmcmpXip bits */
#define SIFIVE_E31ARTY_PWM_CFG_STICKY  (1ul << 8ul)
#define SIFIVE_E31ARTY_PWM_CFG_ZEROCMP_POSITION  (9ul)
#define SIFIVE_E31ARTY_PWM_CFG_ZEROCMP_MASK  (0x1ul << 9ul)  /**< [9..9] Zero - counter resets to zero after match */
#define SIFIVE_E31ARTY_PWM_CFG_ZEROCMP  (1ul << 9ul)
#define SIFIVE_E31ARTY_PWM_CFG_DEGLITCH_POSITION  (10ul)
#define SIFIVE_E31ARTY_PWM_CFG_DEGLITCH_MASK  (0x1ul << 10ul)  /**< [10..10] Deglitch - latch pwmcmpXip within same cycle */
#define SIFIVE_E31ARTY_PWM_CFG_DEGLITCH  (1ul << 10ul)
#define SIFIVE_E31ARTY_PWM_CFG_ENALWAYS_POSITION  (12ul)
#define SIFIVE_E31ARTY_PWM_CFG_ENALWAYS_MASK  (0x1ul << 12ul)  /**< [12..12] Enable always - run continuously */
#define SIFIVE_E31ARTY_PWM_CFG_ENALWAYS  (1ul << 12ul)
#define SIFIVE_E31ARTY_PWM_CFG_ENONESHOT_POSITION  (13ul)
#define SIFIVE_E31ARTY_PWM_CFG_ENONESHOT_MASK  (0x1ul << 13ul)  /**< [13..13] enable one shot - run one cycle */
#define SIFIVE_E31ARTY_PWM_CFG_ENONESHOT  (1ul << 13ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP0CENTER_POSITION  (16ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP0CENTER_MASK  (0x1ul << 16ul)  /**< [16..16] PWM0 Compare Center */
#define SIFIVE_E31ARTY_PWM_CFG_CMP0CENTER  (1ul << 16ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP1CENTER_POSITION  (17ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP1CENTER_MASK  (0x1ul << 17ul)  /**< [17..17] PWM1 Compare Center */
#define SIFIVE_E31ARTY_PWM_CFG_CMP1CENTER  (1ul << 17ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP2CENTER_POSITION  (18ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP2CENTER_MASK  (0x1ul << 18ul)  /**< [18..18] PWM2 Compare Center */
#define SIFIVE_E31ARTY_PWM_CFG_CMP2CENTER  (1ul << 18ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP3CENTER_POSITION  (19ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP3CENTER_MASK  (0x1ul << 19ul)  /**< [19..19] PWM3 Compare Center */
#define SIFIVE_E31ARTY_PWM_CFG_CMP3CENTER  (1ul << 19ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP0GANG_POSITION  (24ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP0GANG_MASK  (0x1ul << 24ul)  /**< [24..24] PWM0/PWM1 Compare Gang */
#define SIFIVE_E31ARTY_PWM_CFG_CMP0GANG  (1ul << 24ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP1GANG_POSITION  (25ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP1GANG_MASK  (0x1ul << 25ul)  /**< [25..25] PWM1/PWM2 Compare Gang */
#define SIFIVE_E31ARTY_PWM_CFG_CMP1GANG  (1ul << 25ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP2GANG_POSITION  (26ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP2GANG_MASK  (0x1ul << 26ul)  /**< [26..26] PWM2/PWM3 Compare Gang */
#define SIFIVE_E31ARTY_PWM_CFG_CMP2GANG  (1ul << 26ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP3GANG_POSITION  (27ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP3GANG_MASK  (0x1ul << 27ul)  /**< [27..27] PWM3/PWM0 Compare Gang */
#define SIFIVE_E31ARTY_PWM_CFG_CMP3GANG  (1ul << 27ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP0IP_POSITION  (28ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP0IP_MASK  (0x1ul << 28ul)  /**< [28..28] PWM0 Interrupt Pending */
#define SIFIVE_E31ARTY_PWM_CFG_CMP0IP  (1ul << 28ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP1IP_POSITION  (29ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP1IP_MASK  (0x1ul << 29ul)  /**< [29..29] PWM1 Interrupt Pending */
#define SIFIVE_E31ARTY_PWM_CFG_CMP1IP  (1ul << 29ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP2IP_POSITION  (30ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP2IP_MASK  (0x1ul << 30ul)  /**< [30..30] PWM2 Interrupt Pending */
#define SIFIVE_E31ARTY_PWM_CFG_CMP2IP  (1ul << 30ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP3IP_POSITION  (31ul)
#define SIFIVE_E31ARTY_PWM_CFG_CMP3IP_MASK  (0x1ul << 31ul)  /**< [31..31] PWM3 Interrupt Pending */
#define SIFIVE_E31ARTY_PWM_CFG_CMP3IP  (1ul << 31ul)

// Register 'pwm.scale'.
#define SIFIVE_E31ARTY_PWM_SCALE_VALUE_POSITION  (0ul)
#define SIFIVE_E31ARTY_PWM_SCALE_VALUE_MASK  (0xFFul << 0ul)  /**< [7..0] Compare value */

// Register 'pwm.cmp'.
#define SIFIVE_E31ARTY_PWM_CMP_VALUE_POSITION  (0ul)
#define SIFIVE_E31ARTY_PWM_CMP_VALUE_MASK  (0xFFul << 0ul)  /**< [7..0] Compare value */

// ----------------------------------------------------------------------------
// Peripheral 'clint' offsets.

#define SIFIVE_E31ARTY_CLINT_MSIP_OFFSET (0x00000000ul)  /**< 0x02000000: MSIP (Machine-mode Software Interrupts) Register per Hart */
#define SIFIVE_E31ARTY_CLINT_MTIMECMP_OFFSET (0x00004000ul)  /**< 0x02004000: Machine Time Compare Registers per Hart */
#define SIFIVE_E31ARTY_CLINT_MTIMECMP_LOW_OFFSET (0x00004000ul)  /**< 0x02004000: Machine Compare Register Low */
#define SIFIVE_E31ARTY_CLINT_MTIMECMP_HIGH_OFFSET (0x00004004ul)  /**< 0x02004004: Machine Compare Register High */
#define SIFIVE_E31ARTY_CLINT_MTIME_OFFSET (0x0000BFF8ul)  /**< 0x0200BFF8: Machine Time Register */
#define SIFIVE_E31ARTY_CLINT_MTIME_LOW_OFFSET (0x0000BFF8ul)  /**< 0x0200BFF8: Machine Time Register Low */
#define SIFIVE_E31ARTY_CLINT_MTIME_HIGH_OFFSET (0x0000BFFCul)  /**< 0x0200BFFC: Machine Time Register High */

// ----------------------------------------------------------------------------
// Peripheral 'plic' offsets.

#define SIFIVE_E31ARTY_PLIC_PRIORITIES_OFFSET (0x00000000ul)  /**< 0x0C000000: Interrupt Priorities Registers; 0 is reserved. */
#define SIFIVE_E31ARTY_PLIC_PENDINGS_OFFSET (0x00001000ul)  /**< 0x0C001000: Interrupt Pending Bits Registers */
#define SIFIVE_E31ARTY_PLIC_ENABLESTARGET0_OFFSET (0x00002000ul)  /**< 0x0C002000: Hart 0 Interrupt Enable Bits */
#define SIFIVE_E31ARTY_PLIC_ENABLESTARGET0_M_OFFSET (0x00002000ul)  /**< 0x0C002000: Hart 0 M-mode Interrupt Enable Bits */
#define SIFIVE_E31ARTY_PLIC_ENABLESTARGET0_M_ENABLES_OFFSET (0x00002000ul)  /**< 0x0C002000: Interrupt Enable Bits Registers */
#define SIFIVE_E31ARTY_PLIC_TARGET0_OFFSET (0x00200000ul)  /**< 0x0C200000: Hart 0 Interrupt Thresholds */
#define SIFIVE_E31ARTY_PLIC_TARGET0_M_OFFSET (0x00200000ul)  /**< 0x0C200000: Hart 0 M-Mode Interrupt Threshold */
#define SIFIVE_E31ARTY_PLIC_TARGET0_M_THRESHOLD_OFFSET (0x00200000ul)  /**< 0x0C200000: The Priority Threshold Register */
#define SIFIVE_E31ARTY_PLIC_TARGET0_M_CLAIMCOMPLETE_OFFSET (0x00200004ul)  /**< 0x0C200004: The Interrupt Claim/Completion Register */

// ----------------------------------------------------------------------------
// Peripheral 'uart' offsets.

#define SIFIVE_E31ARTY_UART_TXDATA_OFFSET (0x00000000ul)  /**< 0x20000000: Transmit Data Register */
#define SIFIVE_E31ARTY_UART_RXDATA_OFFSET (0x00000004ul)  /**< 0x20000004: Receive Data Register */
#define SIFIVE_E31ARTY_UART_TXCTRL_OFFSET (0x00000008ul)  /**< 0x20000008: Transmit Control Register  */
#define SIFIVE_E31ARTY_UART_RXCTRL_OFFSET (0x0000000Cul)  /**< 0x2000000C: Receive Control Register */
#define SIFIVE_E31ARTY_UART_IE_OFFSET (0x00000010ul)  /**< 0x20000010: Interrupt Enable Register */
#define SIFIVE_E31ARTY_UART_IP_OFFSET (0x00000014ul)  /**< 0x20000014: Interrupt Pending Register */
#define SIFIVE_E31ARTY_UART_DIV_OFFSET (0x00000018ul)  /**< 0x20000018: Baud Rate Divisor Register */

// ----------------------------------------------------------------------------
// Peripheral 'gpio' offsets.

#define SIFIVE_E31ARTY_GPIO_VALUE_OFFSET (0x00000000ul)  /**< 0x20002000: Pin Value Register */
#define SIFIVE_E31ARTY_GPIO_INPUTEN_OFFSET (0x00000004ul)  /**< 0x20002004: Pin Input Enable Register */
#define SIFIVE_E31ARTY_GPIO_OUTPUTEN_OFFSET (0x00000008ul)  /**< 0x20002008: Pin Output Enable Register */
#define SIFIVE_E31ARTY_GPIO_PORT_OFFSET (0x0000000Cul)  /**< 0x2000200C: Output Port Value Register */
#define SIFIVE_E31ARTY_GPIO_PUE_OFFSET (0x00000010ul)  /**< 0x20002010: Internal Pull-up Enable Register */
#define SIFIVE_E31ARTY_GPIO_DS_OFFSET (0x00000014ul)  /**< 0x20002014: Pin Drive Strength Register */
#define SIFIVE_E31ARTY_GPIO_RISEIE_OFFSET (0x00000018ul)  /**< 0x20002018: Rise Interrupt Enable Register */
#define SIFIVE_E31ARTY_GPIO_RISEIP_OFFSET (0x0000001Cul)  /**< 0x2000201C: Rise Interrupt Pending Register */
#define SIFIVE_E31ARTY_GPIO_FALLIE_OFFSET (0x00000020ul)  /**< 0x20002020: Fall Interrupt Enable Register */
#define SIFIVE_E31ARTY_GPIO_FALLIP_OFFSET (0x00000024ul)  /**< 0x20002024: Fall Interrupt Pending Register */
#define SIFIVE_E31ARTY_GPIO_HIGHIE_OFFSET (0x00000028ul)  /**< 0x20002028: High Interrupt Enable Register */
#define SIFIVE_E31ARTY_GPIO_HIGHIP_OFFSET (0x0000002Cul)  /**< 0x2000202C: High Interrupt Pending Register */
#define SIFIVE_E31ARTY_GPIO_LOWIE_OFFSET (0x00000030ul)  /**< 0x20002030: Low Interrupt Enable Register */
#define SIFIVE_E31ARTY_GPIO_LOWIP_OFFSET (0x00000034ul)  /**< 0x20002034: Low Interrupt Pending Register */
#define SIFIVE_E31ARTY_GPIO_IOFEN_OFFSET (0x00000038ul)  /**< 0x20002038: HW I/O Function Enable Register */
#define SIFIVE_E31ARTY_GPIO_IOFSEL_OFFSET (0x0000003Cul)  /**< 0x2000203C: HW I/O Function Select Register */
#define SIFIVE_E31ARTY_GPIO_OUTXOR_OFFSET (0x00000040ul)  /**< 0x20002040: Output XOR (invert) Register */

// ----------------------------------------------------------------------------
// Peripheral 'spi' offsets.

#define SIFIVE_E31ARTY_SPI_SCKDIV_OFFSET (0x00000000ul)  /**< 0x20004000: Serial clock divisor Register */
#define SIFIVE_E31ARTY_SPI_SCKMODE_OFFSET (0x00000004ul)  /**< 0x20004004: Serial Clock Mode Register */
#define SIFIVE_E31ARTY_SPI_CSID_OFFSET (0x00000010ul)  /**< 0x20004010: Chip Select ID Register */
#define SIFIVE_E31ARTY_SPI_CSDEF_OFFSET (0x00000014ul)  /**< 0x20004014: Chip Select Default Register */
#define SIFIVE_E31ARTY_SPI_CSMODE_OFFSET (0x00000018ul)  /**< 0x20004018: Chip Select Mode Register */
#define SIFIVE_E31ARTY_SPI_DELAY0_OFFSET (0x00000028ul)  /**< 0x20004028: Delay Control 0 Register */
#define SIFIVE_E31ARTY_SPI_DELAY1_OFFSET (0x0000002Cul)  /**< 0x2000402C: Delay Control 1 Register */
#define SIFIVE_E31ARTY_SPI_FMT_OFFSET (0x00000040ul)  /**< 0x20004040: Frame Format Register */
#define SIFIVE_E31ARTY_SPI_TXDATA_OFFSET (0x00000048ul)  /**< 0x20004048: Tx FIFO Data Register */
#define SIFIVE_E31ARTY_SPI_RXDATA_OFFSET (0x0000004Cul)  /**< 0x2000404C: Rx FIFO Data Register */
#define SIFIVE_E31ARTY_SPI_TXMARK_OFFSET (0x00000050ul)  /**< 0x20004050: Tx FIFO Watermark Register */
#define SIFIVE_E31ARTY_SPI_RXMARK_OFFSET (0x00000054ul)  /**< 0x20004054: Rx FIFO Watermark Register */
#define SIFIVE_E31ARTY_SPI_FCTRL_OFFSET (0x00000060ul)  /**< 0x20004060: Flash Interface Control Register */
#define SIFIVE_E31ARTY_SPI_FFMT_OFFSET (0x00000064ul)  /**< 0x20004064: Flash Instruction Format Register */
#define SIFIVE_E31ARTY_SPI_IE_OFFSET (0x00000070ul)  /**< 0x20004070: Interrupt Enable Register */
#define SIFIVE_E31ARTY_SPI_IP_OFFSET (0x00000074ul)  /**< 0x20004074: Interrupt Pending Register */

// ----------------------------------------------------------------------------
// Peripheral 'pwm' offsets.

#define SIFIVE_E31ARTY_PWM_CFG_OFFSET (0x00000000ul)  /**< 0x20005000: Configuration Register */
#define SIFIVE_E31ARTY_PWM_COUNT_OFFSET (0x00000008ul)  /**< 0x20005008: Configuration Register */
#define SIFIVE_E31ARTY_PWM_SCALE_OFFSET (0x00000010ul)  /**< 0x20005010: Scale Register */
#define SIFIVE_E31ARTY_PWM_CMP_OFFSET (0x00000020ul)  /**< 0x20005020: Compare Registers */

// ----------------------------------------------------------------------------
// Peripherals memory map.

#define SIFIVE_E31ARTY_CLINT_BASE_ADDRESS  (0x02000000ul)
#define SIFIVE_E31ARTY_PLIC_BASE_ADDRESS  (0x0C000000ul)
#define SIFIVE_E31ARTY_UART0_BASE_ADDRESS  (0x20000000ul)
#define SIFIVE_E31ARTY_GPIO_BASE_ADDRESS  (0x20002000ul)
#define SIFIVE_E31ARTY_SPI0_BASE_ADDRESS  (0x20004000ul)
#define SIFIVE_E31ARTY_PWM0_BASE_ADDRESS  (0x20005000ul)

// ----------------------------------------------------------------------------
// Peripherals declarations.

#define CLINT  ((sifive_e31arty_clint_t*) SIFIVE_E31ARTY_CLINT_BASE_ADDRESS)
#define PLIC  ((sifive_e31arty_plic_t*) SIFIVE_E31ARTY_PLIC_BASE_ADDRESS)
#define UART0  ((sifive_e31arty_uart_t*) SIFIVE_E31ARTY_UART0_BASE_ADDRESS)
#define GPIO  ((sifive_e31arty_gpio_t*) SIFIVE_E31ARTY_GPIO_BASE_ADDRESS)
#define SPI0  ((sifive_e31arty_spi_t*) SIFIVE_E31ARTY_SPI0_BASE_ADDRESS)
#define PWM0  ((sifive_e31arty_pwm_t*) SIFIVE_E31ARTY_PWM0_BASE_ADDRESS)

// ----------------------------------------------------------------------------

/**
 * @}
 */ /* End of group device-peripheral-registers */

/**
 * @} 
 */ /* End of group e31arty */

/**
 * @} 
 */ /* End of group sifive */

#if defined(__cplusplus)
}
#endif

// ----------------------------------------------------------------------------

#endif /* SIFIVE_DEVICES_ARTY_E31_DEVICE_PERIPHERALS_H_ */
