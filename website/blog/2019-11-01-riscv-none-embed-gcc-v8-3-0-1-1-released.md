---
title:  xPack GNU RISC-V Embedded GCC v8.3.0-1.1 released

date: 2019-11-01 21:17:00 +0300

authors: ilg-ul

# To be listed in the Releases page.
tags:
  - releases

# ----- Custom properties -----------------------------------------------------

version: 8.3.0-1.1
npm_subversion: 1

download_url: https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v8.3.0-1.1/

---

Version **8.3.0-1.1** is a new release of the **xPack GNU RISC-V Embedded GCC**, following SiFive release from August 2019.

<!-- truncate -->

import Image from '@theme/IdealImage';

## Download

The binary files are available from GitHub [releases]({ frontMatter.download_url }).

## Install

The full details of installing the **xPack GNU RISC-V Embedded GCC** on
various platforms are presented in the [Install Guide](/docs/install/).

## Compliance

Starting with v8.2.0-2, this distribution closely follows the official
[SiFive](https://www.sifive.com)
[Freedom Tools](https://github.com/sifive/freedom-tools) distribution.

This release is based on the
[v2019.08.0](https://github.com/sifive/freedom-tools/releases/tag/v2019.08.0)
release, and includes the SiFive extensions (like CLIC interrupts and a an
even larger multi-lib set).

The following commits (from [sifive/freedom-tools](https://github.com/sifive/freedom-tools/tree/master/src)) were used:

- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
project, branch `sifive-binutils-2.32`, commit
[03d23d5](https://github.com/sifive/riscv-binutils-gdb/tree/03d23d58701bdd425c613b0be2d458bcde46912b)
from 2 September 2019
- the [sifive/riscv-gcc](https://github.com/sifive/riscv-gcc) project,
branch `sifive-gcc-8.3.0`, commit
[e195042](https://github.com/sifive/riscv-gcc/tree/e195042babe2dc30d9fabb88d336d8c8679b3702)
from from 7 Aug 2019
- the [sifive/riscv-newlib](https://github.com/sifive/riscv-newlib) project, the `master` branch,
commit [0d24a86](https://github.com/sifive/riscv-newlib/tree/0d24a86822a5ee73d6a6aa69e2a0118aa1e35204)
from 9 July 2019

GDB was upstreamed and does not require SiFive specific patches,
so the current build uses
`git://sourceware.org/git/binutils-gdb.git`, the `9b40759` commit from
28 Feb 2019.

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
rv32ia/ilp32;@march=rv32ia@mabi=ilp32
rv32im/ilp32;@march=rv32im@mabi=ilp32
rv32if/ilp32f;@march=rv32if@mabi=ilp32f
rv32ifd/ilp32d;@march=rv32ifd@mabi=ilp32d
rv32iaf/ilp32f;@march=rv32iaf@mabi=ilp32f
rv32iafd/ilp32d;@march=rv32iafd@mabi=ilp32d
rv32imaf/ilp32f;@march=rv32imaf@mabi=ilp32f
rv32imf/ilp32f;@march=rv32imf@mabi=ilp32f
rv32imfd/ilp32d;@march=rv32imfd@mabi=ilp32d
rv32iac/ilp32;@march=rv32iac@mabi=ilp32
rv32imac/ilp32;@march=rv32imac@mabi=ilp32
rv32imafc/ilp32f;@march=rv32imafc@mabi=ilp32f
rv32imafdc/ilp32d;@march=rv32imafdc@mabi=ilp32d
rv64i/lp64;@march=rv64i@mabi=lp64
rv64ia/lp64;@march=rv64ia@mabi=lp64
rv64im/lp64;@march=rv64im@mabi=lp64
rv64if/lp64f;@march=rv64if@mabi=lp64f
rv64ifd/lp64d;@march=rv64ifd@mabi=lp64d
rv64iaf/lp64f;@march=rv64iaf@mabi=lp64f
rv64iafd/lp64d;@march=rv64iafd@mabi=lp64d
rv64imf/lp64f;@march=rv64imf@mabi=lp64f
rv64imaf/lp64f;@march=rv64imaf@mabi=lp64f
rv64iac/lp64;@march=rv64iac@mabi=lp64
rv64imac/lp64;@march=rv64imac@mabi=lp64
rv64imafc/lp64f;@march=rv64imafc@mabi=lp64f
rv64imafdc/lp64d;@march=rv64imafdc@mabi=lp64d
```

## Bug fixes

- [[#3]](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues/3)
Due to an omission in the build scripts, the content of the `libgcov`
library was mostly empty; the script was fixed and now the library has the
expected content.
- [[#4]](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues/4)
Due to a bug in the build scripts, the Windows binaries included two
copies of the `docs` folder, one in root and one in the `share` folder;
the script was fixed and now there is only one copy in `share/docs`.

## Improvements

Compared to the original SiFive version, the **same architecture and API**
options are supported, and there are minimal functional changes

- `libgloss` was removed from the list of libraries always linked to the
  application, since it issues `ECALL`
  instructions that fail in bare metal environments
- `march=rv32imaf/mabi=ilp32f` was added to the list of multi-libs
- the standard documentation, in PDF and HTML, is included
- experimental support for Python in GDB was added

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

## Known problems

- [[#5]](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues/5)
the `riscv-none-embed-gdb-py` fails to start on Ubuntu (and possibly
other Debian) systems, it fails with a message like:
```console
$ PYTHONHOME=/usr PYTHONPATH=/usr/lib/python2.7 riscv-none-embed-gdb-py --version
Traceback (most recent call last):
  File "/usr/lib/python2.7/site.py", line 554, in <module>
    main()
  File "/usr/lib/python2.7/site.py", line 536, in main
    known_paths = addusersitepackages(known_paths)
  File "/usr/lib/python2.7/site.py", line 272, in addusersitepackages
    user_site = getusersitepackages()
  File "/usr/lib/python2.7/site.py", line 247, in getusersitepackages
    user_base = getuserbase() # this will also set USER_BASE
  File "/usr/lib/python2.7/site.py", line 237, in getuserbase
    USER_BASE = get_config_var('userbase')
  File "/usr/lib/python2.7/sysconfig.py", line 587, in get_config_var
    return get_config_vars().get(name)
  File "/usr/lib/python2.7/sysconfig.py", line 533, in get_config_vars
    _init_posix(_CONFIG_VARS)
  File "/usr/lib/python2.7/sysconfig.py", line 417, in _init_posix
    from _sysconfigdata import build_time_vars
  File "/usr/lib/python2.7/_sysconfigdata.py", line 6, in <module>
    from _sysconfigdata_nd import *
ImportError: No module named _sysconfigdata_nd
```

The problem is caused by gdb-py not being able to locate the Python
system libraries, split into multiple packages and installed in multiple
folders.

The workaround is to pass the Python environment to gdb-py:

```bash
PYTHONPATH="$(python -c 'import os; import sys; print(os.pathsep.join(sys.path))')" \
PYTHONHOME="$(python -c 'import sys; print(sys.prefix)')"
```

## Documentation

The original PDF documentation is available in the `share/doc` folder.

## Supported platforms

Binaries for **Windows**, **macOS** and **GNU/Linux** are provided.

The binaries were built using the
[xPack Build Box (XBB)](https://github.com/xpack/xpack-build-box), a set
of build environments based on slightly older distributions, that should be
compatible with most recent systems.

- GNU/Linux: all binaries were built with GCC 7.4, running in a CentOS 6
  Docker container
- Windows: all binaries were built with mingw-w64 GCC 7.4, running in a
  CentOS 6 Docker container
- macOS: most binaries were built with GCC 7.4, running in a separate
  folder on macOS 10.10.5; GDB cannot be compiled with GCC, so Apple
  clang was used.

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
532f719c11f7311a0103eac6ddd7dd012716a2c3030dd1ee7e64374b1af41d34
xpack-riscv-none-embed-gcc-8.3.0-1.1-darwin-x64.tgz

c40d8e74a3f87839131287ecd68be2e691c84af0b75d684c1e47ab60687ff987
xpack-riscv-none-embed-gcc-8.3.0-1.1-linux-x32.tgz

7b95d397a2bd319892f5c930757f7b3bc47acac633dafcf055b0901172513c00
xpack-riscv-none-embed-gcc-8.3.0-1.1-linux-x64.tgz

5d608a0438c5f5c4a2c8b6d4eb13499a60a17618da04fb20972eb0f4965ed4bd
xpack-riscv-none-embed-gcc-8.3.0-1.1-win32-x32.zip

10443f00627473f08c44fd00c8011b17c67953d1eb4f1609fb00e5653165d5d3
xpack-riscv-none-embed-gcc-8.3.0-1.1-win32-x64.zip
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
