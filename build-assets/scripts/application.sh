# -----------------------------------------------------------------------------
# This file is part of the xPacks distribution.
#   (https://xpack.github.io)
# Copyright (c) 2019 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Application specific definitions. Included with source.

# Used to display the application name.
XBB_APPLICATION_NAME=${XBB_APPLICATION_NAME:-"GNU RISC-V Embedded GCC"}

# Used as part of file/folder paths.
XBB_APPLICATION_LOWER_CASE_NAME=${XBB_APPLICATION_LOWER_CASE_NAME:-"riscv-none-elf-gcc"}

XBB_APPLICATION_DISTRO_NAME=${XBB_APPLICATION_DISTRO_NAME:-"xPack"}
XBB_APPLICATION_DISTRO_LOWER_CASE_NAME=${XBB_APPLICATION_DISTRO_LOWER_CASE_NAME:-"xpack"}
XBB_APPLICATION_DISTRO_TOP_FOLDER=${XBB_APPLICATION_DISTRO_TOP_FOLDER:-"xPacks"}

XBB_APPLICATION_DESCRIPTION="${XBB_APPLICATION_DISTRO_NAME} ${XBB_APPLICATION_NAME}"

declare -a XBB_APPLICATION_DEPENDENCIES=( )
declare -a XBB_APPLICATION_COMMON_DEPENDENCIES=( texinfo zlib gmp mpfr mpc isl libiconv xz zstd binutils-cross gcc-cross newlib-cross expat libunistring gettext gpm ncurses readline bzip2 libffi mpdecimal sqlite libxcrypt openssl python3 gdb-cross )

XBB_APPLICATION_HAS_FLEX_PACKAGE="y"

# XBB_APPLICATION_BOOTSTRAP_ONLY="y"

# To download from the dedicated git branch instead of the released archive.
# XBB_APPLICATION_TEST_PRERELEASE="y"

# XBB_APPLICATION_USE_GCC_FOR_GCC_ON_MACOS="y"

# -----------------------------------------------------------------------------

# Normally should be commented out. Enable it only during tests,
# to save some build time.
# XBB_APPLICATION_WITHOUT_MULTILIB="y"

# -----------------------------------------------------------------------------

XBB_APPLICATION_TARGET_TRIPLET=${XBB_APPLICATION_TARGET_TRIPLET:-"riscv-none-elf"}
XBB_APPLICATION_GCC_ARCH=${XBB_APPLICATION_GCC_ARCH:-"rv32imac"}
XBB_APPLICATION_GCC_ABI=${XBB_APPLICATION_GCC_ABI:-"ilp32"}

# XBB_APPLICATION_GCC_MULTILIB_LIST=" ... "

# -----------------------------------------------------------------------------

XBB_GITHUB_ORG="${XBB_GITHUB_ORG:-"xpack-dev-tools"}"
XBB_GITHUB_REPO="${XBB_GITHUB_REPO:-"${XBB_APPLICATION_LOWER_CASE_NAME}-xpack"}"
XBB_GITHUB_PRE_RELEASES="${XBB_GITHUB_PRE_RELEASES:-"pre-releases"}"

XBB_NPM_PACKAGE="${XBB_NPM_PACKAGE:-"@xpack-dev-tools/${XBB_APPLICATION_LOWER_CASE_NAME}@${XBB_NPM_PACKAGE_VERSION:-"next"}"}"


# -----------------------------------------------------------------------------
