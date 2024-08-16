---
title:  xPack GNU RISC-V Embedded GCC v14.2.0-1 released

date: 2024-08-07 07:34:16 +0300

authors: ilg-ul

# To be listed in the Releases page.
tags:
  - releases

# ----- Custom properties -----------------------------------------------------

gcc_version: "14.2.0"
binutils_version: "2.42"
newlib_version: "4.4.0"
gdb_version: "15.1"
python_version: "3.12.2"

version: "14.2.0-1"
npm_subversion: "1"

download_url: https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/tag/v14.2.0-1/

---

Version **14.2.0-1** is a new release; it follows the GNU GCC release.

<!-- truncate -->

import Image from '@theme/IdealImage';
import CodeBlock from '@theme/CodeBlock';

import Prerequisites from './_common/_prerequisites-glib-2.27.mdx'
import DeprecationNotices from './_common/_deprecation-notices-glib-2.27.mdx'
import DownloadAnalytics from './_common/_download-analytics.mdx'

[The xPack GNU RISC-V Embedded GCC](/)
is a standalone cross-platform binary distribution of
[GNU GCC](https://gcc.gnu.org/releases.html) for embedded RISC-V.

There are separate binaries for **Windows** (x64),
**macOS** (x64 and arm64) and **GNU/Linux** (x64, arm64 and arm).

:::note Raspberry Pi

The main targets for the GNU/Linux Arm
binaries are the **Raspberry Pi** class devices (armv7l and aarch64;
armv6 is not supported).

:::

## Download

The binary files can be downloaded automatically with **xpm** or manually
from <a href={ frontMatter.download_url }>GitHub Releases</a>.

<Prerequisites/>

## Install

The full details of installing the **xPack GNU RISC-V Embedded GCC**
on various platforms are presented in the [Install Guide](/docs/install/).

## Compliance

The xPack GNU RISC-V Embedded GCC uses the official sources,
with no functional changes:

- GCC { frontMatter.gcc_version }
- binutils { frontMatter.binutils_version }
- newlib { frontMatter.newlib_version }
- gdb { frontMatter.gdb_version }
- python { frontMatter.python_version }

## Supported libraries

The default architecture/ABI pair is `rv32imac/ilp32`.

The other supported libraries are:

```console
$ riscv-none-elf-gcc -print-multi-lib
.;
rv32e/ilp32e;@march=rv32e@mabi=ilp32e
rv32ea/ilp32e;@march=rv32ea@mabi=ilp32e
rv32eac/ilp32e;@march=rv32eac@mabi=ilp32e
rv32ec/ilp32e;@march=rv32ec@mabi=ilp32e
rv32em/ilp32e;@march=rv32em@mabi=ilp32e
rv32ema/ilp32e;@march=rv32ema@mabi=ilp32e
rv32emac/ilp32e;@march=rv32emac@mabi=ilp32e
rv32emc/ilp32e;@march=rv32emc@mabi=ilp32e
rv32i/ilp32;@march=rv32i@mabi=ilp32
rv32ia/ilp32;@march=rv32ia@mabi=ilp32
rv32iac/ilp32;@march=rv32iac@mabi=ilp32
rv32iaf_zicsr/ilp32f;@march=rv32iaf_zicsr@mabi=ilp32f
rv32iafc_zicsr/ilp32f;@march=rv32iafc_zicsr@mabi=ilp32f
rv32iafd_zicsr/ilp32d;@march=rv32iafd_zicsr@mabi=ilp32d
rv32iafdc_zicsr/ilp32d;@march=rv32iafdc_zicsr@mabi=ilp32d
rv32ic/ilp32;@march=rv32ic@mabi=ilp32
rv32if_zicsr/ilp32f;@march=rv32if_zicsr@mabi=ilp32f
rv32ifc_zicsr/ilp32f;@march=rv32ifc_zicsr@mabi=ilp32f
rv32ifd_zicsr/ilp32d;@march=rv32ifd_zicsr@mabi=ilp32d
rv32ifdc_zicsr/ilp32d;@march=rv32ifdc_zicsr@mabi=ilp32d
rv32im/ilp32;@march=rv32im@mabi=ilp32
rv32ima/ilp32;@march=rv32ima@mabi=ilp32
rv32imaf_zicsr/ilp32f;@march=rv32imaf_zicsr@mabi=ilp32f
rv32imafc_zicsr/ilp32f;@march=rv32imafc_zicsr@mabi=ilp32f
rv32imafd_zicsr/ilp32d;@march=rv32imafd_zicsr@mabi=ilp32d
rv32imafdc_zicsr/ilp32d;@march=rv32imafdc_zicsr@mabi=ilp32d
rv32imc/ilp32;@march=rv32imc@mabi=ilp32
rv32imf_zicsr/ilp32f;@march=rv32imf_zicsr@mabi=ilp32f
rv32imfc_zicsr/ilp32f;@march=rv32imfc_zicsr@mabi=ilp32f
rv32imfd_zicsr/ilp32d;@march=rv32imfd_zicsr@mabi=ilp32d
rv32imfdc_zicsr/ilp32d;@march=rv32imfdc_zicsr@mabi=ilp32d
rv64i/lp64;@march=rv64i@mabi=lp64
rv64ia/lp64;@march=rv64ia@mabi=lp64
rv64iac/lp64;@march=rv64iac@mabi=lp64
rv64iaf_zicsr/lp64f;@march=rv64iaf_zicsr@mabi=lp64f
rv64iafc_zicsr/lp64f;@march=rv64iafc_zicsr@mabi=lp64f
rv64iafd_zicsr/lp64d;@march=rv64iafd_zicsr@mabi=lp64d
rv64iafdc_zicsr/lp64d;@march=rv64iafdc_zicsr@mabi=lp64d
rv64ic/lp64;@march=rv64ic@mabi=lp64
rv64if_zicsr/lp64f;@march=rv64if_zicsr@mabi=lp64f
rv64ifc_zicsr/lp64f;@march=rv64ifc_zicsr@mabi=lp64f
rv64ifd_zicsr/lp64d;@march=rv64ifd_zicsr@mabi=lp64d
rv64ifdc_zicsr/lp64d;@march=rv64ifdc_zicsr@mabi=lp64d
rv64im/lp64;@march=rv64im@mabi=lp64
rv64ima/lp64;@march=rv64ima@mabi=lp64
rv64imac/lp64;@march=rv64imac@mabi=lp64
rv64imaf_zicsr/lp64f;@march=rv64imaf_zicsr@mabi=lp64f
rv64imafc_zicsr/lp64f;@march=rv64imafc_zicsr@mabi=lp64f
rv64imafd_zicsr/lp64d;@march=rv64imafd_zicsr@mabi=lp64d
rv64imafdc_zicsr/lp64d;@march=rv64imafdc_zicsr@mabi=lp64d
rv64imc/lp64;@march=rv64imc@mabi=lp64
rv64imf_zicsr/lp64f;@march=rv64imf_zicsr@mabi=lp64f
rv64imfc_zicsr/lp64f;@march=rv64imfc_zicsr@mabi=lp64f
rv64imfd_zicsr/lp64d;@march=rv64imfd_zicsr@mabi=lp64d
rv64imfdc_zicsr/lp64d;@march=rv64imfdc_zicsr@mabi=lp64d
```

## Changes

Compared to the upstream GNU release, there are no functional changes.

## Bug fixes

- none

## Enhancements

- none

## Known problems

- due to the large number of libraries, the archive is >500 MB.

## Documentation

The original GNU Arm Embedded GCC documentation is available from the
[GCC online documentation](https://gcc.gnu.org/onlinedocs/) web site.

## Build

The binaries for all supported platforms
(Windows, macOS and GNU/Linux) were built using the
[xPack Build Box (XBB)](https://xpack.github.io/xbb/), a set
of build environments based on slightly older distributions, that should be
compatible with most recent systems.

For the prerequisites and more details on the build procedure, please see the
[Maintainer Info](/docs/maintainer/) page.

## CI tests

Before publishing, a set of simple tests were performed on an exhaustive
set of platforms. The results are available from:

- [GitHub Actions](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/actions/)
- [Travis CI](https://app.travis-ci.com/github/xpack-dev-tools/riscv-none-elf-gcc-xpack/builds/)

## Tests

The binaries were tested on a variety of platforms,
but mainly to check the integrity of the
build, not the compiler functionality.

## Checksums

The SHA-256 hashes for the files are:

```txt
37e862dfe7c085a4497cd9f7d2d44468500ddb9ecce7c02a40784a4bd52d0c5e
xpack-riscv-none-elf-gcc-14.2.0-1-darwin-arm64.tar.gz

8baa5c250da21146ccda934b10f35b9fab082c2d4ee0577cc11bdcddd240e7cd
xpack-riscv-none-elf-gcc-14.2.0-1-darwin-x64.tar.gz

ac41040fd2995c68a2445902d7f94d50e52b0cca8a70fe0543bcfcba7e8dc9ea
xpack-riscv-none-elf-gcc-14.2.0-1-linux-arm.tar.gz

12b9f088733054628e75067456b670ac4da2cc452c0ce0466645d73f0dee14c2
xpack-riscv-none-elf-gcc-14.2.0-1-linux-arm64.tar.gz

a5eb707595e1424ff4127cc8b21b8b8cb076e6f0070b670485e72b9f74806200
xpack-riscv-none-elf-gcc-14.2.0-1-linux-x64.tar.gz

183d602dc1eb7de43eb43ac43afef492f02b665c26418733ca5bca959c1ee5c3
xpack-riscv-none-elf-gcc-14.2.0-1-win32-x64.zip

```

<DeprecationNotices/>

<DownloadAnalytics version={ frontMatter.version }/>
