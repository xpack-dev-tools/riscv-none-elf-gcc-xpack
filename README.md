[![GitHub package.json version](https://img.shields.io/github/package-json/v/xpack-dev-tools/riscv-none-elf-gcc-xpack)](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/blob/xpack/package.json)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/xpack-dev-tools/riscv-none-elf-gcc-xpack)](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/)
[![npm (scoped)](https://img.shields.io/npm/v/@xpack-dev-tools/riscv-none-elf-gcc.svg?color=blue)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/)
[![license](https://img.shields.io/github/license/xpack-dev-tools/riscv-none-elf-gcc-xpack)](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/blob/xpack/LICENSE)

## The xPack GNU RISC-V Embedded GCC

A standalone cross-platform (Windows/macOS/Linux) **GNU RISC-V Embedded GCC**
binary distribution, intended for reproducible builds.

In addition to the the binary archives and the package meta data,
this project also includes the build scripts.

### Deprecation notice

This project replaces the deprecated
[`xpack-dev-tools/riscv-none-embed-gcc-xpack`](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack)
project, which followed the SiFive releases.

## Overview

This open source project is hosted on GitHub as
[`xpack-dev-tools/riscv-none-elf-gcc-xpack`](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack)
and provides the platform specific binaries for the
[xPack GNU RISC-V Embedded GCC](https://xpack.github.io/riscv-none-elf-gcc/).

The binaries can be installed automatically as **binary xPacks** or manually as
**portable archives**.

## Release schedule

This distribution plans to follow the official
[GNU](https://gcc.gnu.org/releases.html) release schedule.

## User info

This section is intended as a shortcut for those who plan
to use the GNU RISC-V Embedded GCC binaries. For full details please read the
[xPack GNU RISC-V Embedded GCC](https://xpack.github.io/riscv-none-elf-gcc/) pages.

### Easy install

The easiest way to install GNU RISC-V Embedded GCC is using the **binary xPack**, available as
[`@xpack-dev-tools/riscv-none-elf-gcc`](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc)
from the [`npmjs.com`](https://www.npmjs.com) registry.

#### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

It is recommended to update to the latest version with:

```sh
npm install --location=global xpm@latest
```

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

#### Install

With the `xpm` tool available, installing
the latest version of the package and adding it as
a dependency for a project is quite easy:

```sh
cd my-project
xpm init # Only at first use.

xpm install @xpack-dev-tools/riscv-none-elf-gcc@latest --verbose

ls -l xpacks/.bin
```

This command will:

- install the latest available version,
into the central xPacks store, if not already there
- add symbolic links to the central store
(or `.cmd` forwarders on Windows) into
the local `xpacks/.bin` folder.

The central xPacks store is a platform dependent
folder; check the output of the `xpm` command for the actual
folder used on your platform).
This location is configurable via the environment variable
`XPACKS_STORE_FOLDER`; for more details please check the
[xpm folders](https://xpack.github.io/xpm/folders/) page.

For xPacks aware tools, like the **Eclipse Embedded C/C++ plug-ins**,
it is also possible to install GNU RISC-V Embedded GCC globally, in the user home folder:

```sh
xpm install --global @xpack-dev-tools/riscv-none-elf-gcc@latest --verbose
```

Eclipse will automatically
identify binaries installed with
`xpm` and provide a convenient method to manage paths.

After install, the package should create a structure like this (only the
first two depth levels are shown):

```console
$ tree -L 2 /Users/ilg/Library/xPacks/\@xpack-dev-tools/riscv-none-elf-gcc/12.2.0-2/.content/
/Users/ilg/Library/xPacks/\@xpack-dev-tools/riscv-none-elf-gcc/12.2.0-2/.content/
├── README.md
├── bin
│   ├── riscv-none-elf-addr2line
│   ├── riscv-none-elf-ar
│   ├── riscv-none-elf-as
│   ├── riscv-none-elf-c++
│   ├── riscv-none-elf-c++filt
│   ├── riscv-none-elf-cpp
│   ├── riscv-none-elf-elfedit
│   ├── riscv-none-elf-g++
│   ├── riscv-none-elf-gcc
│   ├── riscv-none-elf-gcc-12.2.0
│   ├── riscv-none-elf-gcc-ar
│   ├── riscv-none-elf-gcc-nm
│   ├── riscv-none-elf-gcc-ranlib
│   ├── riscv-none-elf-gcov
│   ├── riscv-none-elf-gcov-dump
│   ├── riscv-none-elf-gcov-tool
│   ├── riscv-none-elf-gdb
│   ├── riscv-none-elf-gdb-add-index
│   ├── riscv-none-elf-gdb-add-index-py3
│   ├── riscv-none-elf-gdb-py3
│   ├── riscv-none-elf-gfortran
│   ├── riscv-none-elf-gprof
│   ├── riscv-none-elf-ld
│   ├── riscv-none-elf-ld.bfd
│   ├── riscv-none-elf-lto-dump
│   ├── riscv-none-elf-nm
│   ├── riscv-none-elf-objcopy
│   ├── riscv-none-elf-objdump
│   ├── riscv-none-elf-ranlib
│   ├── riscv-none-elf-readelf
│   ├── riscv-none-elf-size
│   ├── riscv-none-elf-strings
│   └── riscv-none-elf-strip
├── distro-info
│   ├── CHANGELOG.md
│   ├── licenses
│   ├── patches
│   └── scripts
├── include
│   └── gdb
├── lib
│   ├── bfd-plugins
│   ├── gcc
│   ├── libcc1.0.so
│   ├── libcc1.so -> libcc1.0.so
│   └── python3.10
├── libexec
│   ├── gcc
│   ├── libbz2.1.0.8.dylib
│   ├── libcrypt.2.dylib
│   ├── libcrypto.1.1.dylib
│   ├── libexpat.1.8.8.dylib
│   ├── libexpat.1.dylib -> libexpat.1.8.8.dylib
│   ├── libffi.8.dylib
│   ├── libgmp.10.dylib
│   ├── libiconv.2.dylib
│   ├── libisl.23.dylib
│   ├── liblzma.5.dylib
│   ├── libmpc.3.dylib
│   ├── libmpfr.6.dylib
│   ├── libncurses.6.dylib
│   ├── libpanel.6.dylib
│   ├── libpython3.10.dylib
│   ├── libreadline.8.1.dylib
│   ├── libreadline.8.dylib -> libreadline.8.1.dylib
│   ├── libsqlite3.0.dylib
│   ├── libssl.1.1.dylib
│   ├── libz.1.2.12.dylib
│   ├── libz.1.dylib -> libz.1.2.12.dylib
│   └── libzstd.1.5.2.dylib
├── riscv-none-elf
│   ├── bin
│   ├── include
│   ├── lib
│   └── share
└── share
    └── gcc-12.2.0

20 directories, 59 files
```

No other files are installed in any system folders or other locations.

#### Uninstall

To remove the links created by xpm in the current project:

```sh
cd my-project

xpm uninstall @xpack-dev-tools/riscv-none-elf-gcc
```

To completely remove the package from the global store:

```sh
xpm uninstall --global @xpack-dev-tools/riscv-none-elf-gcc
```

### Manual install

For all platforms, the **xPack GNU RISC-V Embedded GCC**
binaries are released as portable
archives that can be installed in any location.

The archives can be downloaded from the
GitHub [Releases](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/)
page.

For more details please read the
[Install](https://xpack.github.io/riscv-none-elf-gcc/install/) page.

### Versioning

The version strings used by the GCC project are three number strings
like `12.1.0`; to this string the xPack distribution adds a four number,
but since semver allows only three numbers, all additional ones can
be added only as pre-release strings, separated by a dash,
like `12.2.0-2`.
When published as a npm package, the version gets
a fifth number, like `12.2.0-2.1`.

Since adherence of third party packages to semver is not guaranteed,
it is recommended to use semver expressions like `^12.1.0` and `~12.1.0`
with caution, and prefer exact matches, like `12.2.0-2.1`.

## Maintainer info

For maintainer info, please see the
[README-MAINTAINER](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/blob/xpack/README-MAINTAINER.md)

## Support

The quick advice for getting support is to use the GitHub
[Discussions](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/discussions/).

For more details please read the
[Support](https://xpack.github.io/riscv-none-elf-gcc/support/) page.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT), with all rights
reserved to [Liviu Ionescu](https://github.com/ilg-ul/).

The binary distributions include several open-source components; the
corresponding licenses are available in the installed
`distro-info/licenses` folder.

## Download analytics

- GitHub [`xpack-dev-tools/riscv-none-elf-gcc-xpack`](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/) repo
  - latest xPack release
[![Github All Releases](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-elf-gcc-xpack/latest/total.svg)](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/)
  - all xPack releases [![Github All Releases](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-elf-gcc-xpack/total.svg)](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/)
  - previous `riscv-none-elf-gcc` releases [![Github All Releases](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-elf-gcc-xpack/total.svg)](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/)
  - [individual file counters](https://somsubhra.github.io/github-release-stats/?username=xpack-dev-tools&repository=riscv-none-elf-gcc-xpack) (grouped per release)
- npmjs.com [`@xpack-dev-tools/riscv-none-elf-gcc`](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/) xPack
  - latest release, per month
[![npm (scoped)](https://img.shields.io/npm/v/@xpack-dev-tools/riscv-none-elf-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/)
[![npm](https://img.shields.io/npm/dm/@xpack-dev-tools/riscv-none-elf-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/)
  - all releases [![npm](https://img.shields.io/npm/dt/@xpack-dev-tools/riscv-none-elf-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/)

Credit to [Shields IO](https://shields.io) for the badges and to
[Somsubhra/github-release-stats](https://github.com/Somsubhra/github-release-stats)
for the individual file counters.
