---
title:  xPack GNU RISC-V Embedded GCC v8.3.0-2.1 released

date: 2020-10-10 13:07:00 +0300

authors: ilg-ul

# To be listed in the Releases page.
tags:
  - releases

# ----- Custom properties -----------------------------------------------------

version: 8.3.0-2.1
npm_subversion: 1

download_url: https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v8.3.0-2.1/

---

Version **8.3.0-2.1** is a new release of the **xPack GNU RISC-V Embedded GCC**, following SiFive release 2020.04.0 from August 2020; it also changes to use **DT_RPATH** to make the binaries immune to custom LD_LIBRARY_PATH.

<!-- truncate -->

import Image from '@theme/IdealImage';

This is the **xPack** distribution of the
[SiFive RISC-V GCC](https://github.com/sifive/freedom-tools/releases).

There are separate binaries for **Windows**, **macOS** and
**GNU/Linux**, 32/64-bit.

Starting with mid-2020 (v8.3.0-1.2), support for 32/64-bit
**Arm GNU/Linux** platforms, like **Raspberry Pi**, was added.

Starting with this version, robustness of the standalone binaries was increased
by setting `DT_RPATH` instead of `DT_RUNPATH` (see below).

## Download

The binary files are available from <a href={ frontMatter.download_url }>GitHub Releases</a>.

## Install

The full details of installing the **xPack GNU RISC-V Embedded GCC** on
various platforms are presented in the [Install Guide](/docs/install/).

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
from 3 Feb 2020
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
from 3 Feb 2020

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

## Bug fixes

- none

## Improvements

Compared to the original SiFive version, the **same architecture and API**
options are supported, and there are minimal functional changes

- `libgloss` was removed from the list of libraries always linked to the
  application, since it issues `ECALL`
  instructions that fail in bare metal environments

## newlib-nano

Support for **newlib-nano** is available using the
`--specs=nano.specs` option. For better results, this option must be
added to both compile and link time.

## nosys.specs

If no syscalls are needed, `--specs=nosys.specs` can be used at link
time to provide empty implementations for the POSIX system calls.

## Compile options

The libraries are compiled with `-O2 -mcmodel=medany`. The nano version is
compiled with `-Os -mcmodel=medany`.

:::caution

It is mandatory for the applications to
be compiled with
`-mcmodel=medany`, otherwise the link will fail." %}

## Python

Support for Python scripting was added to GDB. This distribution provides
a separate binary, `riscv-none-embed-gdb-py3` with
support for **Python 3.7**.

It is mandatory to have **exactly** this version installed, otherwise
GDB will not start properly.

For this it is recommended to install the binaries provided by
[Python](https://www.python.org/downloads/),
not those available in the distribution, since they may be incomplete, for
example those in Ubuntu/Debian, which split the Python system library into
multiple packages.

On GNU/Linux, the recommended way is to build is from sources, and
install locally:

```bash
python3_version="3.7.9"
mkdir -p "${HOME}/Downloads"
curl -L --fail -o "${HOME}/Downloads/Python-${python3_version}.tgz" https://www.python.org/ftp/python/${python3_version}/Python-${python3_version}.tgz
rm -rf "${HOME}/Work/Python-${python3_version}"
mkdir -p "${HOME}/Work"
cd "${HOME}/Work"
tar xzf "${HOME}/Downloads/Python-${python3_version}.tgz"
cd "${HOME}/Work/Python-${python3_version}"
bash ./configure --prefix="${HOME}/opt"
make
make altinstall
```

To run GDB with this version of Python, use a script to set the proper
environment, like:

```bash
mkdir -p "${HOME}/opt/bin"
cat <<'__EOF__' > "${HOME}/opt/bin/riscv-none-embed-gdb-py3.sh"
#!/usr/bin/env bash
PYTHONPATH="$($HOME/opt/bin/python3.7 -c 'import os; import sys; print(os.pathsep.join(sys.path))')" \
PYTHONHOME="$($HOME/opt/bin/python3.7 -c 'import sys; print(sys.prefix)')" \
riscv-none-embed-gdb-py3 "$@"
__EOF__
chmod +x "${HOME}/opt/bin/riscv-none-embed-gdb-py3.sh"
```

Support for Python 2 was discontinued.

## Text User Interface (TUI)

Support for TUI was added to GDB. The `ncurses` library (v6.2) was added to
the distribution.

:::note

TUI is not available on Windows

:::

## Known problems

- the GDB binary with Python support was built with version 3.7,
  and require exactly this version in order to run properly;
- binutils 2.32 introduced a regression bug affecting the recognition of
  [LENGTH and ORIGIN in MEMORY regions](https://sourceware.org/bugzilla/show_bug.cgi?id=24289);
  the bug was fixed in binutils 2.33.1, and the fix was included in the
  next **8.3.0-2.2** release;
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

- [test xPack RISC-V Embed GCC on stable platforms](https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/734643749)
- [test xPack RISC-V Embed GCC on latest platforms](https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/734646066)

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
3740ef563b845009db5892dc7204a3d4e074b99c3f171009e15db4c2746c7cd8
xpack-riscv-none-embed-gcc-8.3.0-2.1-darwin-x64.tar.gz

e5e053b9eafb514f8969ff6d266a506299969cf4189c2298b1c1afe03cbb71a0
xpack-riscv-none-embed-gcc-8.3.0-2.1-linux-arm64.tar.gz

cce99bf7be2b36d09199e955643d2146d3c65ee535435a94f80eaaee9669d7de
xpack-riscv-none-embed-gcc-8.3.0-2.1-linux-arm.tar.gz

c04d4803355ab5874c6b6920d32b56d1569dbddf591a93b6da4ee1dab6a8de95
xpack-riscv-none-embed-gcc-8.3.0-2.1-linux-x32.tar.gz

6f5de80f9916935b75149ee0dd6e04d66d86d202157a9319e595c2587a103718
xpack-riscv-none-embed-gcc-8.3.0-2.1-linux-x64.tar.gz

9814d12dc1984abebe8010e31ab5cf8bb9b2f3f082f26bd731856192d08ab827
xpack-riscv-none-embed-gcc-8.3.0-2.1-win32-x32.zip

967797fb60cee98010170c93090df9d7e7e45e4dac840dcdb129cd06f8a8126f
xpack-riscv-none-embed-gcc-8.3.0-2.1-win32-x64.zip
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
