# How to build the xPack GNU RISC-V Embedded GCC binaries

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

## Repositories

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

### Branches

- `xpack` - the updated content, used during builds
- `xpack-develop` - the updated content, used during development
- `master` - empty, not used.

## Prerequisites

The prerequisites are common to all binary builds. Please follow the
instructions from the separate
[Prerequisites for building xPack binaries](https://xpack.github.io/xbb/prerequisites/)
page and return when ready.

Note: Building the Arm binaries requires an Arm machine.

## Download the build scripts repo

The build scripts are available in the `scripts` folder of the
[`xpack-dev-tools/riscv-none-embed-gcc-xpack`](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack)
Git repo.

To download them, issue the following commands:

```sh
rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git clone \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git -C ~/Downloads/riscv-none-embed-gcc-xpack.git submodule update --init --recursive
```

> Note: the repository uses submodules; for a successful build it is
> mandatory to recurse the submodules.

For development purposes, clone the `xpack-develop`
branch:

```sh
rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git clone \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git -C ~/Downloads/riscv-none-embed-gcc-xpack.git submodule update --init --recursive
```

## The `Work` folder

The script creates a temporary build `Work/riscv-none-embed-gcc-${version}`
folder in the user home. Although not recommended, if for any reasons
you need to change the location of the `Work` folder,
you can redefine `WORK_FOLDER_PATH` variable before invoking the script.

## Spaces in folder names

Due to the limitations of `make`, builds started in folders with
spaces in names are known to fail.

If on your system the work folder is in such a location, redefine it in a
folder without spaces and set the `WORK_FOLDER_PATH` variable before invoking
the script.

## Customizations

There are many other settings that can be redefined via
environment variables. If necessary,
place them in a file and pass it via `--env-file`. This file is
either passed to Docker or sourced to shell. The Docker syntax
**is not** identical to shell, so some files may
not be accepted by bash.

## Versioning

The version string is an extension to semver, the format looks like `10.1.0-1.1`.
It includes the three digits with the original GCC version, a fourth
digit with the SiFive release, a fifth digit with the xPack release number.

When publishing on the **npmjs.com** server, a sixth digit is appended.

## Changes

Compared to the original SiFive distribution, there should be no
major functional changes, perhaps only bug fixes.

The actual changes for each version are documented in the corresponding
release pages:

- <https://xpack.github.io/arm-none-eabi-gcc/releases/>

## How to build local/native binaries

### README-DEVELOP.md

The details on how to prepare the development environment for native build
are in the
[`README-DEVELOP.md`](https://github.com/xpack-dev-tools/arm-none-eabi-gcc-xpack/blob/xpack/README-DEVELOP.md) file.

## How to build distributions

## Build

Although it is perfectly possible to build all binaries in a single step
on a macOS system, due to Docker specifics, it is faster to build the
GNU/Linux and Windows binaries on a GNU/Linux system and the macOS binary
separately.

### Build the Intel GNU/Linux and Windows binaries

The current platform for Intel GNU/Linux and Windows production builds is a
Debian 10, running on an Intel NUC8i7BEH mini PC with 32 GB of RAM
and 512 GB of fast M.2 SSD. The machine name is `xbbi`.

```sh
caffeinate ssh xbbi
```

Before starting a multi-platform build, check if Docker is started:

```sh
docker info
```

Eventually run the test image:

```sh
docker run hello-world
```

Before running a build for the first time, it is recommended to preload the
docker images.

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh preload-images
```

The result should look similar to:

```console
$ docker images
REPOSITORY          TAG                              IMAGE ID            CREATED             SIZE
ilegeul/ubuntu      i386-12.04-xbb-v3.3              fadc6405b606        2 days ago          4.55GB
ilegeul/ubuntu      amd64-12.04-xbb-v3.3             3aba264620ea        2 days ago          4.98GB
hello-world         latest                           bf756fb1ae65        5 months ago        13.3kB
```

It is also recommended to Remove unused Docker space. This is mostly useful
after failed builds, during development, when dangling images may be left
by Docker.

To check the content of a Docker image:

```sh
docker run --interactive --tty ilegeul/ubuntu:amd64-12.04-xbb-v3.3
```

To remove unused files:

```sh
docker system prune --force
```

Since the build takes a while, use `screen` to isolate the build session
from unexpected events, like a broken
network connection or a computer entering sleep.

```sh
screen -S riscv
```

Run the development builds on the development machine (`wks`):

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --disable-multilib --develop --disable-tests --without-pdf --linux64 --linux32 --win64 --win32
```

When ready, run the build on the production machine (`xbbi`):

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --all
```

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r riscv`; to kill the session use `Ctrl-a` `Ctrl-\` and confirm.

About 4h45' later, the output of the build script is a set of 4 files and
their SHA signatures, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 1429180
-rw-rw-r-- 1 ilg ilg 366111034 Oct 24 23:03 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-x32.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 24 23:03 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-x32.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 361419776 Oct 24 20:30 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-x64.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 24 20:30 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-x64.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 360858795 Oct 24 23:40 xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-x32.zip
-rw-rw-r-- 1 ilg ilg       117 Oct 24 23:40 xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-x32.zip.sha
-rw-rw-r-- 1 ilg ilg 375055827 Oct 24 21:04 xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-x64.zip
-rw-rw-r-- 1 ilg ilg       117 Oct 24 21:04 xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-x64.zip.sha
```

### Build the Arm GNU/Linux binaries

The supported Arm architectures are:

- `armhf` for 32-bit devices
- `aarch64` for 64-bit devices

The current platform for Arm GNU/Linux production builds is a
Raspberry Pi OS 10, running on a Raspberry Pi Compute Module 4, with
8 GB of RAM and 256 GB of fast M.2 SSD. The machine name is `xbba`.

```sh
caffeinate ssh xbba
```

Before starting a multi-platform build, check if Docker is started:

```sh
docker info
```

Before running a build for the first time, it is recommended to preload the
docker images.

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh preload-images
```

The result should look similar to:

```console
$ docker images
REPOSITORY          TAG                                IMAGE ID            CREATED             SIZE
ilegeul/ubuntu      arm32v7-16.04-xbb-v3.3             b501ae18580a        27 hours ago        3.23GB
ilegeul/ubuntu      arm64v8-16.04-xbb-v3.3             db95609ffb69        37 hours ago        3.45GB
hello-world         latest                             a29f45ccde2a        5 months ago        9.14kB
```

Since the build takes a while, use `screen` to isolate the build session
from unexpected events, like a broken
network connection or a computer entering sleep.

```sh
screen -S riscv
```

Run the development builds on the development machine (`wks`):

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --disable-multilib --develop --disable-tests --without-pdf --arm32 --arm64
```

When ready, run the build on the production machine (`berry`):

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --all
```

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r arm`; to kill the session use `Ctrl-a` `Ctrl-k` and confirm.

About 15 hours later, the output of the build script is a set of 2
archives and their SHA signatures, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 702592
-rw-rw-r-- 1 ilg ilg 361351380 Oct 24 23:42 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-arm64.tar.gz
-rw-rw-r-- 1 ilg ilg       122 Oct 24 23:42 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-arm64.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 358086677 Oct 25 07:31 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-arm.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 25 07:31 xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-arm.tar.gz.sha
```

### Build the macOS binaries

The current platform for macOS production builds is a macOS 10.13.6
running on a MacBook Pro 2011 with 32 GB of RAM and a fast SSD.
The machine name is `xbbm`.

```sh
caffeinate ssh xbbm
```

Since the build takes a while, use `screen` to isolate the build session
from unexpected events, like a broken
network connection or a computer entering sleep.

```sh
screen -S riscv
```

Run the development builds on the development machine (`wks`):

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --disable-multilib --develop --disable-tests --without-pdf --osx
```

When ready, run the build on the production machine (`xbbm`):

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --osx
```

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r riscv`; to kill the session use `Ctrl-a` `Ctrl-k` and confirm.

About 4h10' later, the output of the build script is a compressed archive
and its SHA signature, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 698240
-rw-r--r--  1 ilg  staff  357492352 Oct 24 22:51 xpack-riscv-none-embed-gcc-10.1.0-1.1-darwin-x64.tar.gz
-rw-r--r--  1 ilg  staff        121 Oct 24 22:51 xpack-riscv-none-embed-gcc-10.1.0-1.1-darwin-x64.tar.gz.sha
```

## Subsequent runs

### Separate platform specific builds

Instead of `--all`, you can use any combination of:

```console
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

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh clean
```

To also remove the repository and the output files, use:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh cleanall
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
$ /Users/ilg/Downloads/xPacks/riscv-none-embed-gcc/10.1.0-1.1/bin/riscv-none-embed-gcc --version
riscv-none-embed-gcc (xPack RISC-V Embedded GCC, 64-bit) 10.1.0
```

## Travis tests

A multi-platform validation test for all binary archives can be performed
using Travis CI.

For details please see `tests/scripts/README.md`.

## Installed folders

After install, the package should create a structure like this (only the
first two depth levels are shown):

```console
$ tree -L 2 /Users/ilg/opt/xPacks/riscv-none-embed-gcc/10.1.0-1.1
/Users/ilg/opt/gnu-mcu-eclipse/riscv-none-embed-gcc/10.1.0-1.1
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
<https://github.com/xpack-dev-tools/files-cache/tree/master/libs>),
place them in the XBB cache (`Work/cache`) and restart the build.

## More build details

The build process is split into several scripts. The build starts on the
host, with `build.sh`, which runs `container-build.sh` several times,
once for each target, in one of the two docker containers. Both scripts
include several other helper scripts. The entire process is quite complex,
and an attempt to explain its functionality in a few words would not
be realistic. Thus, the authoritative source of details remains the source
code.
