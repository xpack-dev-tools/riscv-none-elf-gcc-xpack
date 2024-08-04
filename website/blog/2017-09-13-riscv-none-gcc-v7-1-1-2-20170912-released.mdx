---
title:  GNU MCU Eclipse RISC-V Embedded GCC v7.1.1-2-20170912-* released

date: 2017-09-13 10:28:00 +0300

authors: ilg-ul

# To be listed in the Releases page.
tags:
  - releases

# ----- Custom properties -----------------------------------------------------

download_url: https://github.com/gnu-mcu-eclipse/riscv-none-gcc/releases/tag/v7.1.1-2-20170912/

---

Version **7.1.1-2-20170912-2255** is a new release of **GNU MCU Eclipse RISC-V Embedded GCC**; after the initial version of the `riscv64-unknown-elf` toolchain was released, it was discovered that it was intended more to applications that include a kernel-like environment, and less to bare-metal environments. This second release is intended to provide a temporary fix to this problem and make the toolchain more suitable for embedded bare-metal applications; for this it was necessary to to update to the latest newlib 2.5 release which uses 'underscore' syscall functions and to **remove the mandatory use of libgloss**. Hopefully the official toolchain distribution will follow shortly and use the same approach.

In addition, based on users request, support for a new `march=rv32imaf/mabi=ilp32f` library was added.

<!-- truncate -->

<p><a href={ frontMatter.download_url }>Binary files »</a></p>

## Compliance

All **GNU MCU Eclipse RISC-V Embedded GCC** releases are based on the official [RISC-V source files](https://github.com/riscv/riscv-gcc) maintained by [SiFive](https://www.sifive.com).

The current version is based on the following commits:

* the [riscv/riscv-gcc](https://github.com/riscv/riscv-gcc) project, branch `riscv-gcc-7`, commit [c95cdca](https://github.com/riscv/riscv-gcc/commit/c95cdcae21de8dbb8a8ceb9c58b5f9560f0628ff) from from Sep 12th, 2017, with a patch to remove the mandatory `libgloss`, as commit [c95cdca](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/commit/e0203ff93b1c6d6d42809400c5d37cd1448ee697)
* the [riscv/riscv-binutils-gdb](https://github.com/riscv/riscv-binutils-gdb) project, branch `riscv-binutils-2.29`, commit [60cda8d](https://github.com/riscv/riscv-binutils-gdb/commit/60cda8de81dce7bc67977b0dd1953437ed06db36) from Sep 7th, 2017
* the [riscv/riscv-newlib](https://github.com/riscv/riscv-newlib) project, branch `riscv-newlib-2.5.0`, commit [bcf3078](https://github.com/riscv/riscv-newlib/commit/bcf3078d2203be52ac7e31c58ef2dbfe02388d58) from Jul 12th, 2017

The supported architectures (`-march=`) are:

* `rv32i[m][a][f[d]][c]`
* `rv32g[c]`
* `rv64i[m][a][f[d]][c]`
* `rv64g[c]`

The supported ABIs (`-mabi=`) are:

* `ilp32` (32-bit, soft-float)
* `ilp32f` (32-bit with single-precision in registers and double in memory, niche use only)
* `ilp32d` (32-bit, hard-float)
* `lp64` (64-bit long and pointers, soft-float)
* `lp64f` (64-bit long and pointers, with single-precision in registers and double in memory, niche use only)
* `lp64d` (64-bit long and pointers, hard-float).

The supported libraries are (in parenthesis are combinations that reuse simpler libraries):

```console
march=rv32i/mabi=ilp32 (march.rv32ic/mabi.ilp32)
march=rv32im/mabi=ilp32 (march.rv32imc/mabi.ilp32)
march=rv32iac/mabi=ilp32
march=rv32imac/mabi=ilp32
march=rv32imaf/mabi=ilp32f <-- New
march=rv32imafc/mabi=ilp32f (march.rv32imafdc/mabi.ilp32f, march.rv32gc/mabi.ilp32f)
march=rv64imac/mabi=lp64
march=rv64imafdc/mabi=lp64d (march.rv64gc/mabi.lp64d)
```

Please note that, although all combinations of `march/mabi` are supported by the compiler, not all of them have libraries.

## Improvements

Compared to the original RISC-V `riscv64-unknown-elf` toolchain, the following improvements can be noted:

* a newer `newlib` was included, which supports the 'underscore' syscall functions
* the mandatory reference to `libgloss` in the linker configuration was removed
* the `march=rv32imaf/mabi=ilp32f` library was added to the list of multi-libs
* support for `newlib-nano` was added
* the standard documentation, in PDF and HTML, was added

## newlib-nano

Currently **GNU MCU Eclipse RISC-V Embedded GCC** is the only RISC-V toolchain that provides support for **newlib-nano**, using the `--specs=nano.specs` option.

If no syscalls are needed, `--specs=nosys.specs` can be used at link time to provide empty implementations for the POSIX system calls.

The _nano_ versions of the libraries are configured with simplified implementations for `printf()` and `malloc()`; in addition they are compiled with `-Os`, while the regular versions are compiled with `-O2`.

## 'Underscore' newlib syscalls

The initial RISC-V newlib was erroneously configured to directly call system functions via their direct names (like `write()`), assuming they are implemented via kernel traps in `libgloss`.

The latest newlib 2.5.0 for RISC-V fixed this, and switched to the usual newlib configuration, which uses 'underscore' functions (like `_write()`) that must be defined by the application to implement the system calls.

This change is welcome, since it brings the RISC-V toolchain in line with other toolchains, like `arm-none-eabi`.

Unfortunately this change breaks the builds for the initial SiFive SDK samples, which implements the direct function names in the `libwrap` library. To fix them, `libwrap` should no longer be used, the `--wrap` options should no longer be passed to the linker, and several functions (like `_write()`, `_istty()`, ...) must be implemented by the application.

## libgloss

For RISC-V, this library implements all syscalls via kernel traps; on other platforms (like ARM) it is used for semihosting.

The **GNU MCU Eclipse RISC-V Embedded GCC** toolchain no longer links automatically `libgloss`; however  `libgloss` is still available in the distribution and applications that need to access a kernel can include it using the usual `-lgloss` link option.

## Documentation

Another addition compared to the official distribution is the presence of the documentation files, including the PDF manuals for all tools.

## Binaries

Binaries for **Windows**, **macOS** and **GNU/Linux** are provided. For Windows and macOS, separate installable and plain archives are provided. For Windows and GNU/Linux, both 32/64-bit binaries are provided.

Instructions on how to install them are available in the project [README](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack).

For better control and repeatability, the build scripts use Docker containers; all files required during builds are available as a separate [gnu-mcu-eclipse/riscv-none-gcc-build](https://github.com/gnu-mcu-eclipse/riscv-none-gcc-build) project.

## Checksums

The SHA-256 hashes for the files are:

```txt
424a4b7bbef59c4fa59e2103760ffc7e809f2d0fff44af80719a98c20d1cf874 ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-debian32.tgz

8c4b7edcd312dbf3a3dcab975c3237e78e59d96eb5a8342bb4ac5f74a9e7cd53 ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-debian64.tgz

b9dced4d90cd836133aa29071c30659418e8705bb397f29b8b3e6207c1c8e416 ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-osx.pkg

95c96df560f9fa4e21e9378b7ccbc94ea09bb3a250273a720e90ad3044351f93 ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-osx.tgz

42a041af9381bc42bc5995b2247ce092c0a6ff2cda0c9e7ec53de26448202f9b ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-win32-setup.exe

c03585471ad042a7033f099e97eb50b965bcc90e134e12891bd6efac9d5d6b7a ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-win32.zip

f0dfb48e2e8612b37ac372af29e034aa43cecafb02f34b92d7ee9f74a16c1052 ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-win64-setup.exe

543bcdb133ed6ca9157377ae8bee564e385ce5ccc0e46b8b2c5946982f50e864 ?
gnu-mcu-eclipse-riscv-none-gcc-7.1.1-2-20170912-2255-win64.zip
```
