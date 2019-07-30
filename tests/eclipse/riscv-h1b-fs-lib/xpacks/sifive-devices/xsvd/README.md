## XSVD files

## Overview

The XSVD files are similar to ARM SVD files, but have a better structure and use the JSON format.

## Purpose

The XSVD files are intended for:

* generating the device peripheral headers
* displaying the peripheral registers in Eclipse
* generating the QEMU code

These files were created by hand.

## Current issues & questions

Entries in reverse chronological order.

### 2017-10-26

* the AON peripherals in all xsvd files: should they be split in separate peripherals? - fixed, separate peripherals
* should `uart1` be included, considering its pins are not connected to any pads?
* are the names `qspi[012]` appropriate? or should we use `spi[012]`? - fixed, SPI
* for the `wdogcfg` register, I renamed the fields from `wdogscale`, `wdogrsten`, ..., to the more readable names `scale`, `rsten` (I removed the redundant prefix) 
* for the `pwm` register, I removed the redundant prefix
* the `plic` is not very clear, the structure and member names might need more work

