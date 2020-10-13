# How to build the xPack GNU RISC-V Embedded GCC

## Introduction

This project includes the scripts and additional files required to
build and publish the
[xPack GNU RISC-V Embedded GCC](https://xpack.github.io/riscv-none-embed-gcc/) binaries.

It follows the official
[SiFive](https://github.com/sifive/freedom-tools)
releases, and it is planned to make a new release after each future
SiFive release.

The build scripts use the
[xPack Build Box (XBB)](https://github.com/xpack/xpack-build-box),
a set of elaborate build environments based on a recent GCC (Docker containers
for GNU/Linux and Windows or a custom folder for MacOS).

There are two types of builds:

- local/native builds, which use the tools available on the
  host machine; generally the binaries do not run on a different system
  distribution/version; intended mostly for development purposes.
- distribution builds, which create the archives distributed as
  binaries; expected to run on most modern systems.

This page documents the distribution builds.

## Repository URLs

The build scripts use a set of local repositories, to accommodate the
small changes required by the `riscv-none-embed-` prefix:

- [xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)
- [xpack-dev-tools/riscv-gcc](https://github.com/xpack-dev-tools/riscv-gcc)
- [xpack-dev-tools/riscv-newlib](https://github.com/xpack-dev-tools/riscv-newlib)

These repositories were forked from the SiFive repositories:

- [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
- [sifive/riscv-gcc](https://github.com/sifive/riscv-gcc)
- [sifive/riscv-newlib](https://github.com/sifive/riscv-newlib)

GDB was upstreamed and does not require SiFive specific patches, so the
original FSF repository is used:

- `git://sourceware.org/git/binutils-gdb.git`

However, to accommodate the custom prefix, a separate branch is created
in `xpack-dev-tools/riscv-binutils-gdb`.

## Download the build scripts repo

The build scripts are available in the `scripts` folder of the
[`xpack-dev-tools/riscv-none-embed-gcc-xpack`](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack)
Git repo.

To download them, the following shortcut is available:

```console
$ curl --fail -L https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/raw/xpack/scripts/git-clone.sh | bash
```

This small script issues the following two commands:

```console
$ rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git
$ git clone --recurse-submodules https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git
```

> Note: the repository uses submodules; for a successful build it is
> mandatory to recurse the submodules.

For development purposes, there is a shortcut to clone the `xpack-develop`
branch:

```console
$ curl --fail -L https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/raw/xpack/scripts/git-clone-develop.sh | bash
```

which is a shortcut for:

```console
$ rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git
$ git clone --recurse-submodules --branch xpack-develop https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git
```

## The `Work` folder

The script creates a temporary build `Work/riscv-none-embed-gcc-${version}`
folder in the user home. Although not recommended, if for any reasons
you need to change the location of the `Work` folder,
you can redefine `WORK_FOLDER_PATH` variable before invoking the script.

## Customizations

There are many other settings that can be redefined via
environment variables. If necessary,
place them in a file and pass it via `--env-file`. This file is
either passed to Docker or sourced to shell. The Docker syntax
**is not** identical to shell, so some files may
not be accepted by bash.

## Prerequisites

The prerequisites are common to all binary builds. Please follow the
instructions from the separate
[Prerequisites for building xPack binaries](https://xpack.github.io/xbb/prerequisites/)
page and return when ready.

## Prepare release

### Check `README.md`

Normally `README.md` should not need changes, but better check.
Information related to the new version should not be included here,
but in the version specific file (below).

### Identify SiFive commit IDs

- check the [SiFive Releases](https://github.com/sifive/freedom-tools/releases)
for new releases
- identify the tag of the latest release (like `v2019.08.0`)
- switch to Code view and select the tag
- open the `src` folder to identify the commit IDs used for the linked repos
- copy/paste the submodule links to common-versions-sources.sh
- get binutils version from binutils/CHANGELOG
- get gcc version from gcc/BASE_VER (gcc/ChangeLog)
- get newlib version from newlib/configure, VERSION= (newlib/README)
- get gdb version from gdb/VERSION.in (gdb/ChangeLog)

### Identify the main GCC version

Determine the GCC version (like `8.3.0`) and update the `scripts/VERSION`
  file; the format is `8.3.0-2.2`. The fourth digit is the number of the
  SiFive release of the same GCC version, and the fifth digit is the xPack
  GNU RISC-V Embedded GCC release number of this version.

### Create `README-<version>.md`

In the `scripts` folder create a copy of the previous version one.

From the the `src` folder, follow the linked module links for
binutils/gcc/newlib and copy/paste them.
Also update the short IDs and dates.

Check the GDB commit ID (not linked, since it points to external repo).

### Update binutils

With Sourcetree in
[xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)

Check if there is a `sifive` remote pointing to
https://github.com/sifive/riscv-binutils-gdb.

If the changes apply to an existing branch:

- checkout the current SiFive branch (like `sifive-binutils-2.32`)
- merge the commit with the desired ID from the corresponding branch in
the `sifive` remote
- checkout the corresponding xpack branch (like `sifive-binutils-2.32-xpack`)
- merge the previous merge
- check the differences from the non-xpack branch; it should be only the
addition of `embed)` in `config.sub`

If the changes are on a new branch (most likely):

- from the `sifive` remote
checkout the new SiFive branch (like `sifive-binutils-2.32`) into a new local
branch
- identify the commit ID and switch to it
- create a new branch with a similar name, but suffixed by `-xpack`
(like `sifive-binutils-2.32-xpack`)
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
which adds `-embed)`
- commit as **add support for riscv-none-embed-***

In both cases:

- push the two modified branches (like `sifive-binutils-2.32` and
`sifive-binutils-2.32-xpack`)
- add a tag with the current version (like `v8.3.0-2.2`), and push
it to `origin`

- copy/paste the branch name and commit id tp common-versions-source.sh

### Update gcc

With Sourcetree in
[xpack-dev-tools/riscv-gcc](https://github.com/xpack-dev-tools/riscv-gcc)

Check if there is a `sifive` remote pointing to
https://github.com/sifive/riscv-gcc.

If the changes apply to an existing branch:

- checkout the current SiFive branch (like `sifive-gcc-8.3.0`)
- merge the commit with the desired ID from the corresponding branch in
the `sifive` remote
- checkout the corresponding xpack branch (like `sifive-gcc-8.3.0-xpack`)
- merge the previous merge
- check the differences from the non-xpack branch; there should be tree files:
  - `elf-embed.h` with the `LIB_SPEC` definitions without libgloss
  - `config.gcc` with `tm_file` definition that uses `elf-embed.h`
  - `config.sub` which adds `riscv0*)` and `-embed)`

If this is a new branch:

- from the `sifive` remote
checkout the new SiFive branch (like `sifive-gcc-8.3.0`) into a new local
branch
- identify the commit ID and switch to it
- create a new branch with a similar name, but suffixed by `-xpack`
(like `sifive-gcc-8.3.0-xpack`)
- identify the commit which adds the xPaack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be tree files:
  - `elf-embed.h` with the `LIB_SPEC` definitions without libgloss
  - `config.gcc` with `tm_file` definition that uses `elf-embed.h`
  - `config.sub` which adds `riscv0*)` and `-embed)`
- commit as **add support for riscv-none-embed-***

In both cases:

- push the two modified branches (like `sifive-gcc-8.3.0` and
`sifive-gcc-8.3.0-xpack`)
- add a tag with the current version (like `v8.3.0-2.2`), and push
it to `origin`.

### Update newlib

With Sourcetree in
[xpack-dev-tools/riscv-newlib](https://github.com/xpack-dev-tools/riscv-newlib)

Check if there is a `sifive` remote pointing to
https://github.com/sifive/riscv-newlib.

If the changes apply to an existing branch:

- checkout the current SiFive branch (like `master`)
- merge the commit with the desired ID from the corresponding branch in
the `sifive` remote
- checkout the corresponding xpack branch (like `sifive-binutils-2.32-xpack`)
- merge the previous merge
- check the differences from the non-xpack branch; it should be only the
addition of `embed)` in `config.sub`

- from the `sifive` remote
checkout the new SiFive branch (like `master`) into a new local
branch (like `sifive-master`)
- identify the commit ID and switch to it
- create a new branch with a similar name, but suffixed by `-xpack`
(like `sifive-master-xpack`)
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
which adds `-embed)`
- commit as **add support for riscv-none-embed-***

In both cases:

- push the two modified branches (like `sifive--master` and
`sifive--master-xpack`)
- add a tag with the current version (like `v8.3.0-2.2`), and push
it to `origin`.

### Update gdb

With Sourcetree in
[xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)

Check if there is a `gdb` remote pointing to
git://sourceware.org/git/binutils-gdb.git.

For GDB, it is a bit tricky, since it must identify the GNU code in line
with what was used by SiFive; create a branch like `sifive-gdb-8.3`

- branch it into `sifive-gdb-8.3-xpack` and edit the prefix code
- add a tag like `v8.3.0-2.2-gdb`

### Update container-build.sh

- add a new set of definitions in the `scripts/container-build.sh`, with
  the versions of various components;
- update `GH_RELEASE` to the new version (like `8.3.0-2.2`, without `v`)
- in [SiFive Releases](https://github.com/sifive/freedom-tools/releases)
for new releases
- identify the tag of the latest release (like `v2019.08.0`)
- switch to Code view and select the tag
- open the `Makefile` file to identify the `MULTILIBS_GEN` definition;
- copy/paste it into `GCC_MULTILIB` (mind the tabs!)
- add `rv32imaf-ilp32f--` after `rv32imf-` (already in for recent versions)

## Update `CHANGELOG.md`

Check `CHANGELOG.md` and add the new release.

## Build

Although it is perfectly possible to build all binaries in a single step
on a macOS system, due to Docker specifics, it is faster to build the
GNU/Linux and Windows binaries on a GNU/Linux system and the macOS binary
separately.

### Build the Intel GNU/Linux and Windows binaries

The current platform for Intel GNU/Linux and Windows production builds is a
Debian 10, running on an Intel NUC8i7BEH mini PC with 32 GB of RAM
and 512 GB of fast M.2 SSD.

```console
$ ssh xbbi
```

Before starting a multi-platform build, check if Docker is started:

```console
$ docker info
```

Eventually run the test image:

```console
$ docker run hello-world
```

Before running a build for the first time, it is recommended to preload the
docker images.

```console
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh preload-images
```

The result should look similar to:

```console
$ docker images
REPOSITORY          TAG                              IMAGE ID            CREATED             SIZE
ilegeul/ubuntu      i386-12.04-xbb-v3.2              fadc6405b606        2 days ago          4.55GB
ilegeul/ubuntu      amd64-12.04-xbb-v3.2             3aba264620ea        2 days ago          4.98GB
hello-world         latest                           bf756fb1ae65        5 months ago        13.3kB
```

It is also recommended to Remove unused Docker space. This is mostly useful
after failed builds, during development, when dangling images may be left
by Docker.

To check the content of a Docker image:

```console
$ docker run --interactive --tty ilegeul/ubuntu:amd64-12.04-xbb-v3.2
```

To remove unused files:

```console
$ docker system prune --force
```

To download the build scripts:

```console
$ curl --fail -L https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/raw/xpack/scripts/git-clone.sh | bash
```

To build both the 32/64-bit Windows and GNU/Linux versions, use `--all`; to
build selectively, use `--linux64 --win64` or `--linux32 --win32` (GNU/Linux
can be built alone; Windows also requires the GNU/Linux build).

Since the build takes a while, use `screen` to isolate the build session
from unexpected events, like a broken
network connection or a computer entering sleep.

```console
$ screen -S riscv

$ sudo rm -rf ~/Work/riscv-none-embed-gcc-*
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --all
```

or, for development builds:

```console
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --disable-multilib --develop --disable-tests --without-pdf --linux64 --linux32 --win64 --win32
```

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r riscv`; to kill the session use `Ctrl-a` `Ctrl-\` and confirm.

About 4h45' later, the output of the build script is a set of 4 files and
their SHA signatures, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 1346668
-rw-rw-r-- 1 ilg ilg 347985751 Oct 10 14:22 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-x32.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 10 14:22 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-x32.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 343458303 Oct 10 11:55 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-x64.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 10 11:55 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-x64.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 337016277 Oct 10 14:58 xpack-riscv-none-embed-gcc-8.3.0-2.2-win32-x32.zip
-rw-rw-r-- 1 ilg ilg       117 Oct 10 14:58 xpack-riscv-none-embed-gcc-8.3.0-2.2-win32-x32.zip.sha
-rw-rw-r-- 1 ilg ilg 350502092 Oct 10 12:28 xpack-riscv-none-embed-gcc-8.3.0-2.2-win32-x64.zip
-rw-rw-r-- 1 ilg ilg       117 Oct 10 12:28 xpack-riscv-none-embed-gcc-8.3.0-2.2-win32-x64.zip.sha
```

To copy the files from the build machine to the current development
machine, either use NFS to mount the entire folder, or open the `deploy`
folder in a terminal and use `scp`:

```console
$ (cd ~/Work/riscv-none-embed-gcc-*/deploy; scp * ilg@wks:Downloads/xpack-binaries/riscv)
```

#### Build the Arm GNU/Linux binaries

The supported Arm architectures are:

- `armhf` for 32-bit devices
- `arm64` for 64-bit devices

The current platform for Arm GNU/Linux production builds is a
Debian 9, running on an ROCK Pi 4 SBC with 4 GB of RAM
and 256 GB of fast M.2 SSD.

```console
$ ssh xbba
```

Before starting a multi-platform build, check if Docker is started:

```console
$ docker info
```

Before running a build for the first time, it is recommended to preload the
docker images.

```console
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh preload-images
```

The result should look similar to:

```console
$ docker images
REPOSITORY          TAG                                IMAGE ID            CREATED             SIZE
ilegeul/ubuntu      arm32v7-16.04-xbb-v3.2             b501ae18580a        27 hours ago        3.23GB
ilegeul/ubuntu      arm64v8-16.04-xbb-v3.2             db95609ffb69        37 hours ago        3.45GB
hello-world         latest                             a29f45ccde2a        5 months ago        9.14kB
```

To download the build scripts:

```console
$ curl -L https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/raw/xpack/scripts/git-clone.sh | bash
```

Since the build takes a while, use `screen` to isolate the build session
from unexpected events, like a broken
network connection or a computer entering sleep.

```console
$ screen -S riscv

$ sudo rm -rf ~/Work/riscv-none-embed-gcc-*
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --all
```

or, for development builds:

```console
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --disable-multilib --develop --disable-tests --without-pdf --arm32 --arm64

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r arm`; to kill the session use `Ctrl-a` `Ctrl-k` and confirm.

About 15 hours later, the output of the build script is a set of 2
archives and their SHA signatures, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 667980
-rw-rw-r-- 1 ilg ilg 343409720 Oct 10 14:55 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-arm64.tar.gz
-rw-rw-r-- 1 ilg ilg       122 Oct 10 14:55 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-arm64.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 340579759 Oct 10 22:10 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-arm.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 10 22:10 xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-arm.tar.gz.sha
```

To copy the files from the build machine to the current development
machine, either use NFS to mount the entire folder, or open the `deploy`
folder in a terminal and use `scp`:

```console
$ (cd ~/Work/riscv-none-embed-gcc-*/deploy; scp * ilg@wks:Downloads/xpack-binaries/riscv)
```

### Build the macOS binary

The current platform for macOS production builds is a macOS 10.10.5
running on a MacBookPro with 16 GB of RAM and a fast SSD.

```console
$ ssh xbbm
```

To download them, the following shortcut is available:

```console
$ curl --fail -L https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/raw/xpack/scripts/git-clone.sh | bash
```

To build the latest macOS version:

```console
$ screen -S riscv

$ sudo rm -rf ~/Work/riscv-none-embed-gcc-*
$ caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --osx
```

or, for development builds:

```console
$ caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --disable-multilib --develop --disable-tests --without-pdf --osx
```

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r riscv`; to kill the session use `Ctrl-a` `Ctrl-k` and confirm.

About 4h10' later, the output of the build script is a compressed archive
and its SHA signature, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 666560
-rw-r--r--  1 ilg  staff  341272214 Oct 10 14:23 xpack-riscv-none-embed-gcc-8.3.0-2.2-darwin-x64.tar.gz
-rw-r--r--  1 ilg  staff        121 Oct 10 14:23 xpack-riscv-none-embed-gcc-8.3.0-2.2-darwin-x64.tar.gz.sha
```

To copy the files from the build machine to the current development
machine, either use NFS to mount the entire folder, or open the `deploy`
folder in a terminal and use `scp`:

```console
$ (cd ~/Work/riscv-none-embed-gcc-*/deploy; scp * ilg@wks:Downloads/xpack-binaries/riscv)
```

## Run a test build

Before starting the builds on the dedicated machines, run a quick test on
the local development workstation.

```console
$ caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --disable-multilib --develop --disable-tests --without-pdf --osx
```

or on the build machine:

```console
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --disable-multilib --develop --disable-tests --without-pdf --linux64
```

This should check the commit IDs and the tag names in all the refered
repositories, and the build scripts.

It is _quick_ because it does not build the multilibs. Even so, on a
fast machine, it may take 30-60 minutes.

## Subsequent runs

### Separate platform specific builds

Instead of `--all`, you can use any combination of:

```
--linux32 --linux64
--arm32 --arm64
--win32 --win64
```

Please note that, due to the specifics of the GCC build process, the
Windows build requires the corresponding GNU/Linux build, so `--win32`
should be run after or together with `--linux32` and `--win64` after
or together with `--linux64`.

### clean

To remove most build files, use:

```console
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh clean
```

To also remove the repository and the output files, use:

```console
$ bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh cleanall
```

For production builds it is recommended to completely remove the build folder.

### --develop

For performance reasons, the actual build folders are internal to each
Docker run, and are not persistent. This gives the best speed, but has
the disadvantage that interrupted builds cannot be resumed.

For development builds, it is possible to define the build folders in the
host file system, and resume an interrupted build.

### --debug

For development builds, it is also possible to create everything
with `-g -O0` and be able to run debug sessions.

### --disable-multilib

For development builds, to save time, it is recommended to build the
toolchain without multilib.

### --jobs

By default, the build steps use all available cores. If, for any reason,
parallel builds fail, it is possible to reduce the load.

### Interrupted builds

The Docker scripts run with root privileges. This is generally not a
problem, since at the end of the script the output files are reassigned
to the actual user.

However, for an interrupted build, this step is skipped, and files in
the install folder will remain owned by root. Thus, before removing the
build folder, it might be necessary to run a recursive `chown`.

## Testing

A simple test is performed by the script at the end, by launching the
executables to check if all shared/dynamic libraries are correctly used.

For a true test you need to unpack the archive in a temporary location
(like `~/Downloads`) and then run the
program from there. For example on macOS the output should
look like:

```console
$ /Users/ilg/Downloads/xPacks/riscv-none-embed-gcc/8.3.0-2.2/bin/riscv-none-embed-gcc --version
riscv-none-embed-gcc (xPack RISC-V Embedded GCC, 64-bit) 8.3.0
```

## Travis tests

A multi-platform validation test for all binary archives can be performed
using Travis CI.

For details please see `tests/scripts/README.md`.

## Installed folders

After install, the package should create a structure like this (only the
first two depth levels are shown):

```console
$ tree -L 2 /Users/ilg/opt/xPacks/riscv-none-embed-gcc/8.3.0-2.2
/Users/ilg/opt/gnu-mcu-eclipse/riscv-none-embed-gcc/8.3.0-2.2
├── README.md
├── riscv-none-embed
│   ├── bin
│   ├── include
│   ├── lib
│   └── share
├── bin
│   ├── riscv-none-embed-addr2line
│   ├── riscv-none-embed-ar
│   ├── riscv-none-embed-as
│   ├── riscv-none-embed-c++
│   ├── riscv-none-embed-c++filt
│   ├── riscv-none-embed-cpp
│   ├── riscv-none-embed-elfedit
│   ├── riscv-none-embed-g++
│   ├── riscv-none-embed-gcc
│   ├── riscv-none-embed-gcc-8.2.1
│   ├── riscv-none-embed-gcc-ar
│   ├── riscv-none-embed-gcc-nm
│   ├── riscv-none-embed-gcc-ranlib
│   ├── riscv-none-embed-gcov
│   ├── riscv-none-embed-gcov-dump
│   ├── riscv-none-embed-gcov-tool
│   ├── riscv-none-embed-gdb
│   ├── riscv-none-embed-gdb-add-index
│   ├── riscv-none-embed-gdb-add-index-py3
│   ├── riscv-none-embed-gdb-py3
│   ├── riscv-none-embed-gprof
│   ├── riscv-none-embed-ld
│   ├── riscv-none-embed-ld.bfd
│   ├── riscv-none-embed-nm
│   ├── riscv-none-embed-objcopy
│   ├── riscv-none-embed-objdump
│   ├── riscv-none-embed-ranlib
│   ├── riscv-none-embed-readelf
│   ├── riscv-none-embed-size
│   ├── riscv-none-embed-strings
│   └── riscv-none-embed-strip
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
│   └── libcc1.so -> libcc1.0.so
├── libexec
│   └── gcc
└── share
    ├── doc
    └── gcc-riscv-none-embed

19 directories, 37 files
```

No other files are installed in any system folders or other locations.

## Uninstall

The binaries are distributed as portable archives; thus they do not
need to run a setup and do not require an uninstall.

## Files cache

The XBB build scripts use a local cache such that files are downloaded only
during the first run, later runs being able to use the cached files.

However, occasionally some servers may not be available, and the builds
may fail.

The workaround is to manually download the files from an alternate
location (like
https://github.com/xpack-dev-tools/files-cache/tree/master/libs),
place them in the XBB cache (`Work/cache`) and restart the build.

## More build details

The build process is split into several scripts. The build starts on the
host, with `build.sh`, which runs `container-build.sh` several times,
once for each target, in one of the two docker containers. Both scripts
include several other helper scripts. The entire process is quite complex,
and an attempt to explain its functionality in a few words would not
be realistic. Thus, the authoritative source of details remains the source
code.
