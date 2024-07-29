---
title:  xPack GNU RISC-V Embedded GCC v10.1.0-1.1 released

date: 2021-01-05 11:42:00 +0200

authors: ilg-ul

# To be listed in the Releases page.
tags:
  - releases

# ----- Custom properties -----------------------------------------------------

version: 10.1.0-1.1
npm_subversion: 1

download_url: https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v10.1.0-1.1/

---

Version **10.1.0-1.1** is a new release of the **xPack GNU RISC-V Embedded GCC**; it follows the SiFive release 2020-08.0.

<!-- truncate -->

import Image from '@theme/IdealImage';

[The xPack GNU RISC-V Embedded GCC](https://xpack.github.io/dev-tools/riscv-none-embed-gcc/)
is the **xPack** distribution of the
[SiFive RISC-V GCC](https://github.com/sifive/freedom-tools/releases).

There are separate binaries for **Windows** (Intel 32/64-bit),
**macOS** (Intel 64-bit) and **GNU/Linux** (Intel 32/64-bit, Arm 64-bit; no Arm 32-bit).

:::note Raspberry Pi

The main targets for the GNU/Linux Arm
binaries are the **Raspberry Pi** class devices (armv7l and aarch64;
armv6 is not supported).

:::

## Download

The binary files are available from <a href={ frontMatter.download_url }>GitHub Releases</a>.

## Install

The full details of installing the **xPack GNU RISC-V Embedded GCC** on
various platforms are presented in the [Install Guide](/docs/install/).

## Compliance

The xPack GNU RISC-V Embedded GCC follows
the official [SiFive releases](https://github.com/sifive/freedom-tools/releases),
with as little differences as possible.

This release is based on the
[v2020.08.0](https://github.com/sifive/freedom-tools/releases/tag/v2020.08.0)
release, and includes the SiFive extensions, including the vector support.

The following commits (from [sifive/freedom-tools](https://github.com/sifive/freedom-tools/tree/v2020.08.0)) were used:

- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
  project, commit
  [e30af3b8](https://github.com/sifive/riscv-binutils-gdb/tree/e30af3b82e62e7f8ca13992fa3c4ee6a3d0208fd)
  from 28 Jul 2020;
- the [sifive/riscv-gcc](https://github.com/sifive/riscv-gcc) project, commit
  [04cdc9d1](https://github.com/sifive/riscv-gcc/tree/04cdc9d15b90c62ef30609e9086d55101c190dc1)
  from from 27 Aug 2020
- the [sifive/riscv-newlib](https://github.com/sifive/riscv-newlib) project,
  commit [7bee030c](https://github.com/sifive/riscv-newlib/tree/7bee030c58a59b724c64c6b7aab2dd660a890410)
  from 14 May 2019
- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
  project, commit
  [24e9280a](https://github.com/sifive/riscv-binutils-gdb/tree/24e9280aac7a33dd683f4431ca73ed9ce6bd14bd)
  from 30 Jul 2020.

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
rv32iafd/ilp32d;@march=rv32iafd@mabi=ilp32d
rv32imaf/ilp32f;@march=rv32imaf@mabi=ilp32f
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
rv64iafd/lp64d;@march=rv64iafd@mabi=lp64d
rv64imaf/lp64f;@march=rv64imaf@mabi=lp64f
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

- due to the very large number of instructions added by the vector support
  (~70K), the compiler sources became too large and it was not possible to build the Arm 32-bit image
  ([#229](https://github.com/riscv/riscv-gcc/issues/229))
- the archive size got too big for the Windows 32-bit node to handle, and
  `xpm install` may fail with _RangeError: Array buffer allocation failed_;
  the 64-bit systems are not affected.

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

- [test xPack RISC-V Embed GCC on stable platforms](https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/752965761)
- [test xPack RISC-V Embed GCC on latest platforms](https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/752968056)

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
127ade5a6c915b1dafc3085c3f6c8906dd420abc75e1c9f4a1892a00814d59be
xpack-riscv-none-embed-gcc-10.1.0-1.1-darwin-x64.tar.gz

dfc28d657fae39f1822e5e632899eb287ac2aded9bc4798cc9c90b1bcea00f76
xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-arm64.tar.gz

abf73f123d716ff8f22be32b7a0a65162496daf087733096cc921f2b90caa0a1
xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-ia32.tar.gz

7e775a14726dba08aeec17ac97985345e2d8dde0981392792406169b6c0f70ac
xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-x64.tar.gz

08072fb3c272b65868cf0205130b8bcbb1b4dae7f9377d3c63fbe0b91926227a
xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-ia32.zip

204962e61a6a79619351f1dd6ffc140e10c467414155690e98373cf640bb1a3e
xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-x64.zip
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
