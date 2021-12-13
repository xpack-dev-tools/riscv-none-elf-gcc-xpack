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
[xPack Build Box (XBB)](https://xpack.github.io/xbb/),
a set of elaborate build environments based on a recent GCC (Docker containers
for GNU/Linux and Windows or a custom folder for MacOS).

There are two types of builds:

- **local/native builds**, which use the tools available on the
  host machine; generally the binaries do not run on a different system
  distribution/version; intended mostly for development purposes;
- **distribution builds**, which create the archives distributed as
  binaries; expected to run on most modern systems.

This page documents the distribution builds.

For native builds, see the `build-native.sh` script.

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

The version string is an extension to semver, the format looks like `10.2.0-1.3`.
It includes the three digits with the original GCC version, a fourth
digit with the SiFive release, a fifth digit with the xPack release number.

When publishing on the **npmjs.com** server, a sixth digit is appended.

## Changes

Compared to the original SiFive distribution, there should be no
major functional changes, perhaps only bug fixes.

The actual changes for each version are documented in the corresponding
release pages:

- <https://xpack.github.io/riscv-none-embed-gcc/releases/>

## How to build local/native binaries

### README-DEVELOP.md

The details on how to prepare the development environment for native build
are in the
[`README-DEVELOP.md`](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/blob/xpack/README-DEVELOP.md) file.

## How to build distributions

## Build

The builds currently run on 3 dedicated machines (Intel GNU/Linux,
Arm GNU/Linux and Intel macOS). A fourth machine for Arm macOS is planned.

### Build the Intel GNU/Linux and Windows binaries

The current platform for Intel GNU/Linux and Windows production builds is a
Debian 10, running on an Intel NUC8i7BEH mini PC with 32 GB of RAM
and 512 GB of fast M.2 SSD. The machine name is `xbbli`.

```sh
caffeinate ssh xbbli
```

Before starting a build, check if Docker is started:

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
REPOSITORY          TAG                    IMAGE ID            CREATED             SIZE
ilegeul/ubuntu      i386-12.04-xbb-v3.3    35fb0236572c        23 hours ago        5GB
ilegeul/ubuntu      amd64-12.04-xbb-v3.3   1c4ba2e7e87e        29 hours ago        5.43GB
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
screen -S arm

sudo rm -rf ~/Work/riscv-none-embed-gcc-*
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --all
```

or, for development builds:

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --without-pdf --disable-tests --disable-multilib --linux64 --linux32 --win64 --win32
```

When ready, run the build on the production machine (`xbbli`):

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r arm`; to kill the session use `Ctrl-a` `Ctrl-k` and confirm.

About 5 hours later, the output of the build script is a set of 4 files and
their SHA signatures, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 1429180
-rw-rw-r-- 1 ilg ilg 366111034 Oct 24 23:03 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-x32.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 24 23:03 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-x32.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 361419776 Oct 24 20:30 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-x64.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 24 20:30 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-x64.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 360858795 Oct 24 23:40 xpack-riscv-none-embed-gcc-10.2.0-1.3-win32-x32.zip
-rw-rw-r-- 1 ilg ilg       117 Oct 24 23:40 xpack-riscv-none-embed-gcc-10.2.0-1.3-win32-x32.zip.sha
-rw-rw-r-- 1 ilg ilg 375055827 Oct 24 21:04 xpack-riscv-none-embed-gcc-10.2.0-1.3-win32-x64.zip
-rw-rw-r-- 1 ilg ilg       117 Oct 24 21:04 xpack-riscv-none-embed-gcc-10.2.0-1.3-win32-x64.zip.sha
```

### Build the Arm GNU/Linux binaries

The supported Arm architectures are:

- `armhf` for 32-bit devices
- `aarch64` for 64-bit devices

The current platform for Arm GNU/Linux production builds is a
Raspberry Pi OS 10, running on a Raspberry Pi Compute Module 4, with
8 GB of RAM and 256 GB of fast M.2 SSD. The machine name is `xbbla`.

```sh
caffeinate ssh xbbla
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
REPOSITORY       TAG                      IMAGE ID       CREATED          SIZE
ilegeul/ubuntu   arm32v7-16.04-xbb-v3.3   a0ceaa6dad05   57 minutes ago   3.34GB
ilegeul/ubuntu   arm64v8-16.04-xbb-v3.3   1b0b4a94de6d   13 hours ago     3.6GB
```

Since the build takes a while, use `screen` to isolate the build session
from unexpected events, like a broken
network connection or a computer entering sleep.

```sh
screen -S arm

sudo rm -rf ~/Work/riscv-none-embed-gcc-*
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --arm64 --arm32
```

or, for development builds:

```sh
screen -S arm

sudo rm -rf ~/Work/riscv-none-embed-gcc-*
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --without-pdf --disable-tests --disable-multilib --arm64 --arm32
```

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r arm`; to kill the session use `Ctrl-a` `Ctrl-k` and confirm.

About 15 hours later, the output of the build script is a set of 2
archives and their SHA signatures, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 702592
-rw-rw-r-- 1 ilg ilg 361351380 Oct 24 23:42 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-arm64.tar.gz
-rw-rw-r-- 1 ilg ilg       122 Oct 24 23:42 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-arm64.tar.gz.sha
-rw-rw-r-- 1 ilg ilg 358086677 Oct 25 07:31 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-arm.tar.gz
-rw-rw-r-- 1 ilg ilg       120 Oct 25 07:31 xpack-riscv-none-embed-gcc-10.2.0-1.3-linux-arm.tar.gz.sha
```

Note: on some versions, the 32-bit Arm binaries could not be built, since the RVV support requires more than 4 GB or RAM.

### Build the macOS binaries

The current platforms for macOS production builds are:

- a macOS 10.13.6 running on a MacBook Pro 2011 with 32 GB of RAM and
  a fast SSD; the machine name is `xbbmi`
- a macOS 11.6.1 running on a Mac Mini M1 2020 with 16 GB of RAM;
  the machine name is `xbbma`

```sh
caffeinate ssh xbbmi

caffeinate ssh xbbma
```

To build the latest macOS version:

```sh
screen -S arm

sudo rm -rf ~/Work/riscv-none-embed-gcc-*
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop  --disable-multilib --macos
```

or, for development builds:

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --without-pdf --disable-tests --disable-multilib --macos
```

To detach from the session, use `Ctrl-a` `Ctrl-d`; to reattach use
`screen -r arm`; to kill the session use `Ctrl-a` `Ctrl-k` and confirm.

In about 4 hours, the output of the build script is a compressed archive
and its SHA signature, created in the `deploy` folder:

```console
$ ls -l ~/Work/riscv-none-embed-gcc-*/deploy
total 698240
-rw-r--r--  1 ilg  staff  357492352 Oct 24 22:51 xpack-riscv-none-embed-gcc-10.2.0-1.3-darwin-x64.tar.gz
-rw-r--r--  1 ilg  staff        121 Oct 24 22:51 xpack-riscv-none-embed-gcc-10.2.0-1.3-darwin-x64.tar.gz.sha
```

## Subsequent runs

### Separate platform specific builds

Instead of `--all`, you can use any combination of:

```console
--win32 --win64
--linux32 --linux64
```

On Arm, instead of `--all`, you can use:

```console
--arm32 --arm64
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

### --jobs

By default, the build steps use all available cores. If, for any reason,
parallel builds fail, it is possible to reduce the load.

### --disable-multilib

For development builds, to save time, it is recommended to build the
toolchain without multilib.

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
$ .../xpack-riscv-none-embed-gcc/bin/riscv-none-embed-gcc --version
riscv-none-embed-gcc (xPack RISC-V Embedded GCC, 64-bit) 10.2.0
```

## Installed folders

After install, the package should create a structure like this (only the
first two depth levels are shown):

```console
$ tree -L 2 /Users/ilg/Library/xPacks/\@xpack-dev-tools/riscv-none-embed-gcc/10.2.0-1.3/.content/
/Users/ilg/Library/xPacks/\@xpack-dev-tools/riscv-none-embed-gcc/10.2.0-1.3/.content/
├── README.md
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
│   ├── riscv-none-embed-gcc-10.2.0
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
│   ├── riscv-none-embed-lto-dump
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
│   ├── libcc1.so -> libcc1.0.so
│   └── python3.7
├── libexec
│   ├── gcc
│   ├── libcrypt.2.dylib
│   ├── libcrypto.1.1.dylib
│   ├── libexpat.1.6.7.dylib
│   ├── libexpat.1.dylib -> libexpat.1.6.7.dylib
│   ├── libgcc_s.1.dylib
│   ├── libgmp.10.dylib
│   ├── libiconv.2.dylib
│   ├── libintl.8.dylib
│   ├── libisl.15.dylib
│   ├── liblzma.5.dylib
│   ├── libmpc.3.dylib
│   ├── libmpfr.4.dylib
│   ├── libncurses.6.dylib
│   ├── libpanel.6.dylib
│   ├── libpython3.7m.dylib
│   ├── libreadline.8.0.dylib
│   ├── libreadline.8.dylib -> libreadline.8.0.dylib
│   ├── libsqlite3.0.dylib
│   ├── libssl.1.1.dylib
│   ├── libstdc++.6.dylib
│   ├── libz.1.2.8.dylib
│   └── libz.1.dylib -> libz.1.2.8.dylib
├── riscv-none-embed
│   ├── bin
│   ├── include
│   ├── lib
│   └── share
└── share
    ├── doc
    └── gcc-riscv-none-embed

21 directories, 58 files
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
