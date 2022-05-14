[![GitHub release (latest by date)](https://img.shields.io/github/v/release/xpack-dev-tools/riscv-none-elf-gcc-xpack)](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases)
[![npm (scoped)](https://img.shields.io/npm/v/@xpack-dev-tools/riscv-none-elf-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc)

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

The only requirement is a recent
`xpm`, which is a portable
[Node.js](https://nodejs.org) command line application. To install it,
follow the instructions from the
[xpm](https://xpack.github.io/xpm/install/) page.

#### Install

With the `xpm` tool available, installing
the latest version of the package and adding it as
a dependency for a project is quite easy:

```sh
cd my-project
xpm init # Only at first use.

xpm install @xpack-dev-tools/riscv-none-elf-gcc@latest

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
`XPACKS_REPO_FOLDER`; for more details please check the
[xpm folders](https://xpack.github.io/xpm/folders/) page.

For xPacks aware tools, like the **Eclipse Embedded C/C++ plug-ins**,
it is also possible to install GNU RISC-V Embedded GCC globally, in the user home folder:

```sh
xpm install --global @xpack-dev-tools/riscv-none-elf-gcc@latest
```

Eclipse will automatically
identify binaries installed with
`xpm` and provide a convenient method to manage paths.

#### Uninstall

To remove the links from the current project:

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
like `11.3.0`; to this string the xPack distribution adds a four number,
but since semver allows only three numbers, all additional ones can
be added only as pre-release strings, separated by a dash,
like `11.3.0-1`.
When published as a npm package, the version gets
a fifth number, like `11.3.0-1.1`.

Since adherence of third party packages to semver is not guaranteed,
it is recommended to use semver expressions like `^11.3.0` and `~11.3.0`
with caution, and prefer exact matches, like `11.3.0-1.1`.

## Maintainer info

- [How to build](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/blob/xpack/README-BUILD.md)
- [How to make new releases](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/blob/xpack/README-RELEASE.md)
- [Developer info](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/blob/xpack/README-DEVELOP.md)

## Support

The quick answer is to use the GitHub
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
  - previous `riscv-none-embed-gcc` releases [![Github All Releases](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-embed-gcc-xpack/total.svg)](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/)
  - [individual file counters](https://somsubhra.github.io/github-release-stats/?username=xpack-dev-tools&repository=riscv-none-elf-gcc-xpack) (grouped per release)
- npmjs.com [`@xpack-dev-tools/riscv-none-elf-gcc`](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/) xPack
  - latest release, per month
[![npm (scoped)](https://img.shields.io/npm/v/@xpack-dev-tools/riscv-none-elf-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/)
[![npm](https://img.shields.io/npm/dm/@xpack-dev-tools/riscv-none-elf-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/)
  - all releases [![npm](https://img.shields.io/npm/dt/@xpack-dev-tools/riscv-none-elf-gcc.svg)](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-elf-gcc/)

Credit to [Shields IO](https://shields.io) for the badges and to
[Somsubhra/github-release-stats](https://github.com/Somsubhra/github-release-stats)
for the individual file counters.
