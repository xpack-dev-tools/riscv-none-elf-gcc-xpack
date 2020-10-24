# -----------------------------------------------------------------------------
# This file is part of the xPacks distribution.
#   (https://xpack.github.io)
# Copyright (c) 2020 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software 
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# Helper script used in the second edition of the GNU MCU Eclipse build 
# scripts. As the name implies, it should contain only functions and 
# should be included with 'source' by the container build scripts.

# -----------------------------------------------------------------------------

function prepare_variables()
{
  if [ "${USE_GITS}" != "y" ]
  then

    # -------------------------------------------------------------------------

    BINUTILS_SRC_FOLDER_NAME=${BINUTILS_SRC_FOLDER_NAME:-"${BINUTILS_PROJECT_NAME}-${BINUTILS_GH_RELEASE}"}
    BINUTILS_ARCHIVE_NAME=${BINUTILS_ARCHIVE_NAME:-"${BINUTILS_SRC_FOLDER_NAME}.tar.gz"}

    BINUTILS_ARCHIVE_URL=${BINUTILS_ARCHIVE_URL:-"https://github.com/xpack-dev-tools/${BINUTILS_PROJECT_NAME}/archive/v${BINUTILS_GH_RELEASE}.tar.gz"}

    BINUTILS_GIT_URL=""

    # -------------------------------------------------------------------------

    GCC_SRC_FOLDER_NAME=${GCC_SRC_FOLDER_NAME:-"${GCC_PROJECT_NAME}-${GCC_GH_RELEASE}"}
    GCC_ARCHIVE_NAME=${GCC_ARCHIVE_NAME:-"${GCC_SRC_FOLDER_NAME}.tar.gz"}

    GCC_ARCHIVE_URL=${GCC_ARCHIVE_URL:-"https://github.com/xpack-dev-tools/${GCC_PROJECT_NAME}/archive/v${GCC_GH_RELEASE}.tar.gz"}

    GCC_GIT_URL=""

    # -------------------------------------------------------------------------

    NEWLIB_SRC_FOLDER_NAME=${NEWLIB_SRC_FOLDER_NAME:-"${NEWLIB_PROJECT_NAME}-${NEWLIB_GH_RELEASE}"}
    NEWLIB_ARCHIVE_NAME=${NEWLIB_ARCHIVE_NAME:-"${NEWLIB_SRC_FOLDER_NAME}.tar.gz"}

    NEWLIB_ARCHIVE_URL=${NEWLIB_ARCHIVE_URL:-"https://github.com/xpack-dev-tools/${NEWLIB_PROJECT_NAME}/archive/v${NEWLIB_GH_RELEASE}.tar.gz"}

    NEWLIB_GIT_URL=""

    # -------------------------------------------------------------------------

    GDB_SRC_FOLDER_NAME=${GDB_SRC_FOLDER_NAME:-"${GDB_PROJECT_NAME}-${GDB_GH_RELEASE}"}
    GDB_ARCHIVE_NAME=${GDB_ARCHIVE_NAME:-"${GDB_SRC_FOLDER_NAME}.tar.gz"}

    GDB_ARCHIVE_URL=${GDB_ARCHIVE_URL:-"https://github.com/xpack-dev-tools/${GDB_PROJECT_NAME}/archive/v${GDB_GH_RELEASE}.tar.gz"}

    GDB_GIT_URL=""

    # -------------------------------------------------------------------------
  else
    # -------------------------------------------------------------------------

    BINUTILS_SRC_FOLDER_NAME=${BINUTILS_SRC_FOLDER_NAME:-"${BINUTILS_PROJECT_NAME}.git"}

    BINUTILS_GIT_URL=${BINUTILS_GIT_URL:-"https://github.com/xpack-dev-tools/${BINUTILS_PROJECT_NAME}.git"}

    BINUTILS_ARCHIVE_URL=""

    # -------------------------------------------------------------------------

    GCC_SRC_FOLDER_NAME=${GCC_SRC_FOLDER_NAME:-"${GCC_PROJECT_NAME}.git"}

    GCC_GIT_URL=${GCC_GIT_URL:-"https://github.com/xpack-dev-tools/${GCC_PROJECT_NAME}.git"}

    GCC_ARCHIVE_URL=""

    # -------------------------------------------------------------------------

    NEWLIB_SRC_FOLDER_NAME=${NEWLIB_SRC_FOLDER_NAME:-"${NEWLIB_PROJECT_NAME}.git"}
      
    NEWLIB_GIT_URL=${NEWLIB_GIT_URL:-"https://github.com/xpack-dev-tools/${NEWLIB_PROJECT_NAME}.git"}

    NEWLIB_ARCHIVE_URL=""

    # -------------------------------------------------------------------------

    # Pre 8.x builds define it to reuse the binutils repo.
    GDB_SRC_FOLDER_NAME=${GDB_SRC_FOLDER_NAME:-"binutils-gdb.git"}

    GDB_GIT_URL=${GDB_GIT_URL:-"https://github.com/xpack-dev-tools/${GDB_PROJECT_NAME}.git"}

    GDB_ARCHIVE_URL=""

    # -------------------------------------------------------------------------
  fi

  # ---------------------------------------------------------------------------

  BINUTILS_FOLDER_NAME="binutils-${BINUTILS_VERSION}"
  GCC_FOLDER_NAME="gcc-${GCC_VERSION}"
  NEWLIB_FOLDER_NAME="newlib-${NEWLIB_VERSION}"
  GDB_FOLDER_NAME="gdb-${GDB_VERSION}"

}

# -----------------------------------------------------------------------------

function add_linux_install_path()
{
  # Verify that the compiler is there.
  "${WORK_FOLDER_PATH}/${LINUX_INSTALL_RELATIVE_PATH}/${APP_LC_NAME}/bin/${GCC_TARGET}-gcc" --version

  export PATH="${WORK_FOLDER_PATH}/${LINUX_INSTALL_RELATIVE_PATH}/${APP_LC_NAME}/bin:${PATH}"
  echo ${PATH}
}

# -----------------------------------------------------------------------------
