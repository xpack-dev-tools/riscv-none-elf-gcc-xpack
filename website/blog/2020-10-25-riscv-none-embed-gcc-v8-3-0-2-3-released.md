---
title:  xPack GNU RISC-V Embedded GCC v8.3.0-2.3 released

date: 2020-10-25 08:59:00 +0200

authors: ilg-ul

# To be listed in the Releases page.
tags:
  - releases

# ----- Custom properties -----------------------------------------------------

version: 8.3.0-2.3
npm_subversion: 1

download_url: https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v8.3.0-2.3/

---

Version **8.3.0-2.3** is a maintenance release of the **xPack GNU RISC-V Embedded GCC**; it adds an embedded Python 3 instance, to make `riscv-none-embed-gdb-py3` standalone and run on any system.

<!-- truncate -->

import Image from '@theme/IdealImage';

[The xPack GNU RISC-V Embedded GCC](https://xpack.github.io/dev-tools/riscv-none-embed-gcc/)
is the **xPack** distribution of the
[SiFive RISC-V GCC](https://github.com/sifive/freedom-tools/releases).

There are separate binaries for **Windows** (Intel 32/64-bit),
**macOS** (Intel 64-bit) and **GNU/Linux** (Intel 32/64-bit, Arm 32/64-bit).

:::note Raspberry Pi

The main targets for the GNU/Linux Arm
binaries are the **Raspberry Pi** class devices (armv7l and aarch64;
armv6 is not supported).

:::

## Download

The binary files are available from GitHub [releases]({ frontMatter.download_url }).

## Install

The full details of installing the **xPack GNU RISC-V Embedded GCC** on
various platforms are presented in the separate
[Install](/riscv-none-embed-gcc/install/) page.

## Compliance

Starting with 8.2.0-2, the xPack GNU RISC-V Embedded GCC (formerly
GNU MCU Eclipse RISC-V GCC) follows
the official [SiFive releases](https://github.com/sifive/freedom-tools/releases),
with as little differences as possible.

This release is based on the
[v2020.04.0-Toolchain.Only](https://github.com/sifive/freedom-tools/releases/tag/v2020.04.0-Toolchain.Only)
release, and includes the SiFive extensions.

The following commits (from [sifive/freedom-tools](https://github.com/sifive/freedom-tools/tree/v2020.04.0-Toolchain.Only)) were used:

- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
project, branch `sifive-binutils-2.32`, commit
[ac7ecc4](https://github.com/sifive/riscv-binutils-gdb/tree/ac7ecc464d0b0466c056a29e357da0f38aec4705)
from 3 Feb 2020;
- on top of this, the commit
[912ebfa](https://sourceware.org/git/gitweb.cgi?p=binutils-gdb.git;h=912ebfa0d748b4a762dbc4311364c38692c7f626)
was applied, to fix the LENGTH and ORIGIN bug;
- the [sifive/riscv-gcc](https://github.com/sifive/riscv-gcc) project,
branch `sifive-gcc-8.3.0`, commit
[e195042](https://github.com/sifive/riscv-gcc/tree/e195042babe2dc30d9fabb88d336d8c8679b3702)
from from 7 Aug 2019
- the [sifive/riscv-newlib](https://github.com/sifive/riscv-newlib) project, the `fix-S5CSD-1486` branch,
commit [6c668f8](https://github.com/sifive/riscv-newlib/tree/6c668f856bdd678ac1885aa07ffcfcc7483221b8)
from 6 Dec 2019
- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
project, branch `gdb-8.3-release-cache-control-patch`, commit
[ac7ecc4](https://github.com/sifive/riscv-binutils-gdb/tree/62a5c5e36b338bd15c7671332bb49c4ef1e5db15)
from 3 Feb 2020.

## Supported libraries

The supported libraries are:

```console
$ riscv-none-embed-gcc -print-multi-lib
.;
rv32e/ilp32e;@march=rv32e@mabi=ilp32e
rv32ea/ilp32e;@march=rv32ea@mabi=ilp32e
rv32em/ilp32e;@march=rv32em@mabi=ilp32e
rv32eac/ilp32e;@march=rv32eac@mabi=ilp32e
rv32emac/ilp32e;@march=rv32emac@mabi=ilp32e
rv32i/ilp32;@march=rv32i@mabi=ilp32
rv32if/ilp32f;@march=rv32if@mabi=ilp32f
rv32ifd/ilp32d;@march=rv32ifd@mabi=ilp32d
rv32ia/ilp32;@march=rv32ia@mabi=ilp32
rv32iaf/ilp32f;@march=rv32iaf@mabi=ilp32f
rv32imaf/ilp32f;@march=rv32imaf@mabi=ilp32f
rv32iafd/ilp32d;@march=rv32iafd@mabi=ilp32d
rv32im/ilp32;@march=rv32im@mabi=ilp32
rv32imf/ilp32f;@march=rv32imf@mabi=ilp32f
rv32imfc/ilp32f;@march=rv32imfc@mabi=ilp32f
rv32imfd/ilp32d;@march=rv32imfd@mabi=ilp32d
rv32iac/ilp32;@march=rv32iac@mabi=ilp32
rv32imac/ilp32;@march=rv32imac@mabi=ilp32
rv32imafc/ilp32f;@march=rv32imafc@mabi=ilp32f
rv32imafdc/ilp32d;@march=rv32imafdc@mabi=ilp32d
rv64i/lp64;@march=rv64i@mabi=lp64
rv64if/lp64f;@march=rv64if@mabi=lp64f
rv64ifd/lp64d;@march=rv64ifd@mabi=lp64d
rv64ia/lp64;@march=rv64ia@mabi=lp64
rv64iaf/lp64f;@march=rv64iaf@mabi=lp64f
rv64imaf/lp64f;@march=rv64imaf@mabi=lp64f
rv64iafd/lp64d;@march=rv64iafd@mabi=lp64d
rv64im/lp64;@march=rv64im@mabi=lp64
rv64imf/lp64f;@march=rv64imf@mabi=lp64f
rv64imfc/lp64f;@march=rv64imfc@mabi=lp64f
rv64imfd/lp64d;@march=rv64imfd@mabi=lp64d
rv64iac/lp64;@march=rv64iac@mabi=lp64
rv64imac/lp64;@march=rv64imac@mabi=lp64
rv64imafc/lp64f;@march=rv64imafc@mabi=lp64f
rv64imafdc/lp64d;@march=rv64imafdc@mabi=lp64d
```

## Changes

### Improvements

Compared to the original SiFive version, the **same architecture and API**
options are supported, and there are minimal functional changes

- `libgloss` was removed from the list of libraries always linked to the
  application, since it issues `ECALL`
  instructions that fail in bare metal environments

### newlib-nano

Support for **newlib-nano** is available using the
`--specs=nano.specs` option. For better results, this option must be
added to both compile and link time.

### nosys.specs

If no syscalls are needed, `--specs=nosys.specs` can be used at link
time to provide empty implementations for the POSIX system calls.

### Compile options

The libraries are compiled with `-O2 -mcmodel=medany`. The nano version is
compiled with `-Os -mcmodel=medany`.

:::caution

It is mandatory for the applications to
be compiled with
`-mcmodel=medany`, otherwise the link will fail." %}

### Python

Support for Python scripting was added to GDB. This distribution provides
a separate binary, `riscv-none-embed-gdb-py3` with
support for **Python 3.7**.

The Python 3 run-time is included, so GDB does not need any version of
Python to be installed, and is insensitive to the presence of other
versions.

Support for Python 2 was discontinued.

### Text User Interface (TUI)

Support for TUI was added to GDB. The `ncurses` library (v6.2) was added to
the distribution.

:::note

TUI is not available on Windows

:::

## Bug fixes

- none

## Known problems

- GDB may issue the following warning, _riscv-none-embed-gdb: warning:
  Couldn't determine a path for the index cache directory._;
  it is a known problem, caused when trying to create the cache
  folder (`$HOME/.cache/gdb` or `$HOME/Library/Caches/gdb`);
- the archive size got too big for the Windows 32-bit node to handle, and
  `xpm install` fails with _RangeError: Array buffer allocation failed_.

## Documentation

The original PDF documentation is available in the `share/doc` folder.

## Supported platforms

Binaries for **Windows**, **macOS** and **GNU/Linux** are provided.

The binaries were built using the
[xPack Build Box (XBB)](https://github.com/xpack/xpack-build-box), a set
of build environments based on slightly older distributions, that should be
compatible with most recent systems.

- Intel GNU/Linux: all binaries were built with GCC 9.3, running in an
  Ubuntu 12 Docker container
- Arm GNU/Linux: all binaries were built with GCC 9.3, running in an
  Ubuntu 16 Docker container (added in mid-2020)
- Windows: all binaries were built with mingw-w64 GCC 9.3, running in an
  Ubuntu 12 Docker container
- macOS: all binaries were built with GCC 9.3, running in a separate
  folder on macOS 10.10.5.

## Build

The scripts used to build this distribution are in:

- `distro-info/scripts`

For the prerequisites and more details on the build procedure, please see the
[README-MAINTAINER](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/blob/xpack/README-MAINTAINER.md) page.

## Travis tests

The first set of tests were performed on Travis, by running
a simple script to check if the binaries start and compile several simple
programs on a wide range of platforms and distributions:

- [test xPack RISC-V Embed GCC on stable platforms](https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/738682641)
- [test xPack RISC-V Embed GCC on latest platforms](https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/738682668)

## Tests

The binaries were testes on Windows 10 Pro 32/64-bit, Ubuntu 18 LTS 64-bit,
Xubuntu 18 LTS 32-bit and macOS 10.14.

The tests consist in building and debugging some
[simple Eclipse projects](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/tree/xpack/tests/eclipse)
available in the build project.

Since the source code used for GCC is identical to the one used by SiFive, the
long and complex tests performed by SiFive to validate their release were not
executed again.

## Checksums

The SHA-256 hashes for the files are:

```txt
2b138c630e85535d254ea4e2a9147859ba15fff90b9b0f0451035100cb2cd752
xpack-riscv-none-embed-gcc-8.3.0-2.3-darwin-x64.tar.gz

7bd7fdeb93481f60271f7d3fb39e41ed7599c9a2f7d03cd1313585ca1f75952d
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-arm64.tar.gz

c541d610b6d32d462e828d3e7fc98cbbf42e06df9292107bcea26007dcabfc2d
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-arm.tar.gz

8ebcebf9bd7088a866085be30ca1007bd950d9a1a837b04cc2b9238677fc745c
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-x32.tar.gz

708d0cb5ff12eb5ad070153594c4f7771cd86d4b6721a77b23f8fe695c8f9402
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-x64.tar.gz

778d4cf3389a07f9209f5c1d91ae324dea8ca59ae141b406598a82e34edd6493
xpack-riscv-none-embed-gcc-8.3.0-2.3-win32-x32.zip

59d62abc7585ba76a69da5f4ba0254cf2301ef897d47ad8e5a94468f38449db8
xpack-riscv-none-embed-gcc-8.3.0-2.3-win32-x64.zip
```

## Download analytics

- GitHub [xpack-dev-tools/riscv-none-embed-gcc-xpack](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/)
  - this release <a href={ `https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/v${ frontMatter.version }/` } ><Image img={ `https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-elf-gcc-xpack/v${ frontMatter.version }/total.svg` } alt='Github Release' /></a>
  - all xPack releases [![Github All Releases](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-embed-gcc-xpack/total.svg)](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/)
  - all GNU MCU Eclipse releases [![Github All Releases](https://img.shields.io/github/downloads/gnu-mcu-eclipse/riscv-none-gcc/total.svg)](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/releases/)
  - [individual file counters](https://somsubhra.github.io/github-release-stats/?username=xpack-dev-tools&repository=riscv-none-embed-gcc-xpack) (grouped per release)
- npmjs.com [@xpack-dev-tools/riscv-none-embed-gcc](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-embed-gcc)
  - latest releases [![npm](https://img.shields.io/npm/dw/@xpack-dev-tools/riscv-none-embed-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-embed-gcc/)
  - all @xpack-dev-tools releases [![npm](https://img.shields.io/npm/dt/@xpack-dev-tools/riscv-none-embed-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-embed-gcc/)
  - all @gnu-mcu-eclipse releases [![npm](https://img.shields.io/npm/dt/@gnu-mcu-eclipse/riscv-none-gcc.svg)](https://www.npmjs.com/package/@gnu-mcu-eclipse/riscv-none-gcc/)

Credit to [Shields IO](https://shields.io) for the badges and to
[Somsubhra/github-release-stats](https://github.com/Somsubhra/github-release-stats)
for the individual file counters.
