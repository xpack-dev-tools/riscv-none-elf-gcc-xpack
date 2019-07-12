[![Github All Releases](https://img.shields.io/github/downloads/gnu-mcu-eclipse/riscv-none-gcc/latest/total.svg)](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/releases/) [![Github All Releases](https://img.shields.io/github/downloads/gnu-mcu-eclipse/riscv-none-gcc/total.svg)](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/releases/)

# GNU MCU Eclipse RISC-V Embedded GCC

## Rationale

**GNU MCU Eclipse RISC-V Embedded GCC** is a GCC toolchain distribution 
for RISC-V devices, that complements the official 
[RISC-V](https://github.com/riscv/riscv-gnu-toolchain/)
distribution, maintained by SiFive.

For main benefits for the users are:

- convenience: binaries for all major platforms are provided 
(Windows 64/32-bits, GNU/Linux 64/32-bits, macOS); 
- uniform and portable install: the toolchain is also available 
as a binary xPack, and can be easily installed with `xpm`;
- improved support for Continuous Integration usage: 
as for any xPack, the toolchain can be easily used
in test environments.

## Changes

Compared to the original RISC-V release, there are no functional changes; 
the **same architecture options** are supported, and **the same 
combinations of libraries** (derived from newlib) are provided, 
plus possibly more.

## Releases

The **GNU MCU Eclipse RISC-V Embedded GCC** releases generally follow the official 
[RISC-V](https://github.com/riscv/riscv-gnu-toolchain/)
distribution, maintained by SiFive.

- 8.2.0-2.2 (20190521)
- 8.2.0-2.1 (20190425)
- 8.1.0-2 (20181019)
- 7.2.0-4 (20180606)
- 7.2.0-3 (20180506)
- 7.2.0-2 (20180111)
- 7.2.0-1 (20171109)
- 7.1.1-2 (20170912)
- 7.1.1-1 (20170702)

## Install

The procedure to install **GNU MCU Eclipse RISC-V Embedded GCC** is platform 
specific, but relatively straight forward (a .zip archive on Windows, 
a compressed tar archive on macOS and GNU/Linux).

A portable method is to use [`xpm`](https://www.npmjs.com/package/xpm):

```console
$ xpm install @gnu-mcu-eclipse/riscv-none-gcc --global
```

More details are available on the 
[How to install the RISC-V toolchain?](https://gnu-mcu-eclipse.github.io/toolchain/riscv/install/) 
page.

## Build

The build scripts are part of the separate 
[gnu-mcu-eclipse/riscv-none-gcc-build](https://github.com/gnu-mcu-eclipse/riscv-none-gcc-build)
project.

## Publish

The procedure used to publish the binaries is documented in the separate
[PUBLISH](PUBLISH.md) page.

The metadata files used to publish the xPacks on the `npmjs.com` server 
are available from the 
[gnu-mcu-eclipse/riscv-none-gcc-xpack](https://github.com/gnu-mcu-eclipse/riscv-none-gcc-xpack)
project.

## Download analytics

* GitHub [gnu-mcu-eclipse/riscv-none-gcc.git](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/)
  * latest release
[![Github All Releases](https://img.shields.io/github/downloads/gnu-mcu-eclipse/riscv-none-gcc/latest/total.svg)](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/releases/)
  * all releases [![Github All Releases](https://img.shields.io/github/downloads/gnu-mcu-eclipse/riscv-none-gcc/total.svg)](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/releases/)
* xPack [@gnu-mcu-eclipse/riscv-none-gcc](https://github.com/gnu-mcu-eclipse/riscv-none-gcc-xpack/)
  * latest release, per month 
[![npm (scoped)](https://img.shields.io/npm/v/@gnu-mcu-eclipse/riscv-none-gcc.svg)](https://www.npmjs.com/package/@gnu-mcu-eclipse/riscv-none-gcc/)
[![npm](https://img.shields.io/npm/dm/@gnu-mcu-eclipse/riscv-none-gcc.svg)](https://www.npmjs.com/package/@gnu-mcu-eclipse/riscv-none-gcc/)
  * all releases [![npm](https://img.shields.io/npm/dt/@gnu-mcu-eclipse/riscv-none-gcc.svg)](https://www.npmjs.com/package/@gnu-mcu-eclipse/riscv-none-gcc/)
* [individual file counters](https://www.somsubhra.com/github-release-stats/?username=gnu-mcu-eclipse&repository=riscv-none-gcc) (grouped per release)
  
Credits to [Shields IO](https://shields.io) and [Somsubhra/github-release-stats](https://github.com/Somsubhra/github-release-stats).