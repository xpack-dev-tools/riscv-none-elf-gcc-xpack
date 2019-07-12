# -----------------------------------------------------------------------------
# This file is part of the GNU MCU Eclipse distribution.
#   (https://gnu-mcu-eclipse.github.io)
# Copyright (c) 2019 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software 
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# Helper script used in the second edition of the build scripts.
# As the name implies, it should contain only definitions and should
# be included with 'source' by the host and container scripts.

# Warning: MUST NOT depend on $HOME or other environment variables.

# -----------------------------------------------------------------------------

# Used to display the application name.
APP_NAME=${APP_NAME:-"RISC-V Embedded GCC"}

# Used as part of file/folder paths.
APP_UC_NAME=${APP_UC_NAME:-"RISC-V Embedded GCC"}
APP_LC_NAME=${APP_LC_NAME:-"riscv-none-gcc"}

# TODO: rename to xPacks/xpacks.
# Upper case used on Windows.
DISTRO_UC_NAME=${DISTRO_UC_NAME:-"GNU MCU Eclipse"}
# Lower case used on macOS and GNU/Linux.
DISTRO_LC_NAME=${DISTRO_LC_NAME:-"gnu-mcu-eclipse"}

# TODO: remove it.
DISTRO_INFO_NAME=${DISTRO_INFO_NAME:-"${DISTRO_LC_NAME}"}

BRANDING=${BRANDING:-"${DISTRO_UC_NAME} RISC-V Embedded GCC"}

GCC_TARGET=${GCC_TARGET:-"riscv-none-embed"}
GCC_ARCH=${GCC_ARCH:-"rv32imac"}
GCC_ABI=${GCC_ABI:-"ilp32"}

CONTAINER_SCRIPT_NAME=${CONTAINER_SCRIPT_NAME:-"container-build.sh"}
CONTAINER_LIBS_FUNCTIONS_SCRIPT_NAME=${CONTAINER_LIBS_FUNCTIONS_SCRIPT_NAME:-"container-libs-functions-source.sh"}
CONTAINER_APP_FUNCTIONS_SCRIPT_NAME=${CONTAINER_APP_FUNCTIONS_SCRIPT_NAME:-"container-apps-functions-source.sh"}

# -----------------------------------------------------------------------------
