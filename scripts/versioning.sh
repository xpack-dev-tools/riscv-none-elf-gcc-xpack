# -----------------------------------------------------------------------------
# This file is part of the xPacks distribution.
#   (https://xpack.github.io)
# Copyright (c) 2020 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------

function application_build_versioned_components()
{
  # This definition also enables building newlib-nano.
  XBB_NEWLIB_NANO_SUFFIX="-nano"

  # Don't use a comma since the regular expression
  # that processes this string in the Makefile, silently fails and the
  # bfdver.h file remains empty.
  XBB_BRANDING="${XBB_APPLICATION_DISTRO_NAME} ${XBB_APPLICATION_NAME} ${XBB_REQUESTED_TARGET_MACHINE}"

  XBB_CFLAGS_OPTIMIZATIONS_FOR_TARGET="-ffunction-sections -fdata-sections -O2 -w"
  # Cannot use medlow with 64 bits, so all must be medany.
  XBB_CFLAGS_OPTIMIZATIONS_FOR_TARGET+=" -mcmodel=medany"

  # ---------------------------------------------------------------------------
  # Defaults. Must be present.

  XBB_GCC_PATCH_FILE_NAME=""
  XBB_GDB_PATCH_FILE_NAME=""

  # ---------------------------------------------------------------------------

  XBB_FIX_LTO_PLUGIN="y"

  XBB_NCURSES_DISABLE_WIDEC="y"

  XBB_WITH_GDB_PY3=""

  # ---------------------------------------------------------------------------

  XBB_GCC_VERSION="$(xbb_strip_version_pre_release "${XBB_RELEASE_VERSION}")"
  XBB_GCC_VERSION_MAJOR=$(xbb_get_version_major "${XBB_GCC_VERSION}")

  # In reverse chronological order.
  if [[ ${XBB_RELEASE_VERSION} =~ 13[.][2][.]0-.* ]] ||
     [[ ${XBB_RELEASE_VERSION} =~ 12[.][3][.]0-.* ]]
  then

    # -------------------------------------------------------------------------

    if [ "${XBB_APPLICATION_WITHOUT_MULTILIB:-""}" != "y" ]
    then
      # The SiFive list from 10.2 with a lot of non-c extras.
      # (including `rv32imaf-ilp32f--`).
      if [ "${XBB_IS_DEVELOP}" != "y" ]
      then

        # DO NOT add the combination that is already given as the default!
        # rv32imac-ilp32-- \

        # The `zicsr*zifencei` seems redundant for GCC 13, but are
        # important for GCC 12.
        XBB_GCC_MULTILIB_LIST=${XBB_GCC_MULTILIB_LIST:-"\
          rv32e-ilp32e--zicsr*zifencei \
          rv32ea-ilp32e--zicsr*zifencei \
          rv32eac-ilp32e--zicsr*zifencei \
          rv32ec-ilp32e--zicsr*zifencei \
          rv32em-ilp32e--zicsr*zifencei \
          rv32ema-ilp32e--zicsr*zifencei \
          rv32emac-ilp32e--zicsr*zifencei \
          rv32emc-ilp32e--zicsr*zifencei \
          \
          rv32i-ilp32--zicsr*zifencei \
          rv32ia-ilp32--zicsr*zifencei \
          rv32iac-ilp32--zicsr*zifencei \
          rv32iaf-ilp32f--zicsr*zifencei \
          rv32iafc-ilp32f--zicsr*zifencei \
          rv32iafd-ilp32d--zicsr*zifencei \
          rv32iafdc-ilp32d--zicsr*zifencei \
          rv32ic-ilp32--zicsr*zifencei \
          rv32if-ilp32f--zicsr*zifencei \
          rv32ifc-ilp32f--zicsr*zifencei \
          rv32ifd-ilp32d--zicsr*zifencei \
          rv32ifdc-ilp32d--zicsr*zifencei \
          rv32im-ilp32--zicsr*zifencei \
          rv32ima-ilp32--zicsr*zifencei \
          rv32imaf-ilp32f--zicsr*zifencei \
          rv32imafc-ilp32f--zicsr*zifencei \
          rv32imafd-ilp32d--zicsr*zifencei \
          rv32imafdc-ilp32d--zicsr*zifencei \
          rv32imc-ilp32--zicsr*zifencei \
          rv32imf-ilp32f--zicsr*zifencei \
          rv32imfc-ilp32f--zicsr*zifencei \
          rv32imfd-ilp32d--zicsr*zifencei \
          rv32imfdc-ilp32d--zicsr*zifencei \
          \
          rv64i-lp64--zicsr*zifencei \
          rv64ia-lp64--zicsr*zifencei \
          rv64iac-lp64--zicsr*zifencei \
          rv64iaf-lp64f--zicsr*zifencei \
          rv64iafc-lp64f--zicsr*zifencei \
          rv64iafd-lp64d--zicsr*zifencei \
          rv64iafdc-lp64d--zicsr*zifencei \
          rv64ic-lp64--zicsr*zifencei \
          rv64if-lp64f--zicsr*zifencei \
          rv64ifc-lp64f--zicsr*zifencei \
          rv64ifd-lp64d--zicsr*zifencei \
          rv64ifdc-lp64d--zicsr*zifencei \
          rv64im-lp64--zicsr*zifencei \
          rv64ima-lp64--zicsr*zifencei \
          rv64imac-lp64--zicsr*zifencei \
          rv64imaf-lp64f--zicsr*zifencei \
          rv64imafc-lp64f--zicsr*zifencei \
          rv64imafd-lp64d--zicsr*zifencei \
          rv64imafdc-lp64d--zicsr*zifencei \
          rv64imc-lp64--zicsr*zifencei \
          rv64imf-lp64f--zicsr*zifencei \
          rv64imfc-lp64f--zicsr*zifencei \
          rv64imfd-lp64d--zicsr*zifencei \
          rv64imfdc-lp64d--zicsr*zifencei \
        "}
      else
        # Short list used during development to save time.
        # Skip: rv32imac-ilp32-- (see above).
        XBB_GCC_MULTILIB_LIST=${XBB_GCC_MULTILIB_LIST:-"\
          rv32emac-ilp32e-- \
          rv32ima-ilp32--zicsr*zifencei \
          rv64imac-lp64-- \
        "}
      fi
    fi

    # https://ftp.gnu.org/gnu/binutils/
    # https://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.xz

    # Note "2.41" requires a newer makeinfo
    XBB_BINUTILS_VERSION="2.41" # "2.38"

    XBB_BINUTILS_SRC_FOLDER_NAME="binutils-${XBB_BINUTILS_VERSION}"
    XBB_BINUTILS_ARCHIVE_NAME="binutils-${XBB_BINUTILS_VERSION}.tar.xz"
    XBB_BINUTILS_ARCHIVE_URL="https://ftp.gnu.org/gnu/binutils/${XBB_BINUTILS_ARCHIVE_NAME}"

    XBB_BINUTILS_PATCH_FILE_NAME="binutils-${XBB_BINUTILS_VERSION}.patch"

    # XBB_GCC_VERSION computer from XBB_RELEASE_VERSION
    XBB_GCC_SRC_FOLDER_NAME="gcc-${XBB_GCC_VERSION}"
    XBB_GCC_ARCHIVE_NAME="${XBB_GCC_SRC_FOLDER_NAME}.tar.xz"
    XBB_GCC_ARCHIVE_URL="https://ftp.gnu.org/gnu/gcc/gcc-${XBB_GCC_VERSION}/${XBB_GCC_ARCHIVE_NAME}"

    # The Apple Silicon host patches are already in for 12.x.
    # GCC_PATCH_FILE_NAME="gcc-${XBB_GCC_VERSION}-cross.git.patch"
    # check_patch "${GCC_PATCH_FILE_NAME}"

    # https://www.sourceware.org/ftp/newlib/index.html
    # ftp://sourceware.org/pub/newlib/newlib-4.3.0.20230120.tar.gz
    XBB_NEWLIB_VERSION="4.3.0.20230120" # "4.2.0.20211231"

    XBB_NEWLIB_SRC_FOLDER_NAME="newlib-${XBB_NEWLIB_VERSION}"
    XBB_NEWLIB_ARCHIVE_NAME="newlib-${XBB_NEWLIB_VERSION}.tar.gz"
    XBB_NEWLIB_ARCHIVE_URL="ftp://sourceware.org/pub/newlib/${XBB_NEWLIB_ARCHIVE_NAME}"

    XBB_ENABLE_NEWLIB_RISCV_NANO_CXX_PATCH="y"

    # https://ftp.gnu.org/gnu/gdb/
    # https://ftp.gnu.org/gnu/gdb/gdb-13.2.tar.xz

    XBB_GDB_VERSION="13.2" # "12.1"
    XBB_GDB_SRC_FOLDER_NAME="gdb-${XBB_GDB_VERSION}"
    XBB_GDB_ARCHIVE_NAME="${XBB_GDB_SRC_FOLDER_NAME}.tar.xz"
    XBB_GDB_ARCHIVE_URL="https://ftp.gnu.org/gnu/gdb/${XBB_GDB_ARCHIVE_NAME}"

    # Mandatory, otherwise gdb-py3 is not relocatable.
    XBB_GDB_PATCH_FILE_NAME="gdb-${XBB_GDB_VERSION}-cross.git.patch"
    check_patch "${XBB_GDB_PATCH_FILE_NAME}"

    # https://www.python.org/ftp/python/
    # Requires `scripts/helper/extras/python/pyconfig-win-3.11.4.h` &
    # `python3-config-win.sh`

    XBB_WITH_GDB_PY3="y"

    export XBB_PYTHON3_VERSION="3.11.4" # "3.10.4"
    export XBB_PYTHON3_VERSION_MAJOR=$(xbb_get_version_major "${XBB_PYTHON3_VERSION}")
    export XBB_PYTHON3_VERSION_MINOR=$(xbb_get_version_minor "${XBB_PYTHON3_VERSION}")

    # Explicit, since it is also used in python3_copy_syslibs
    export XBB_PYTHON3_SRC_FOLDER_NAME="Python-${XBB_PYTHON3_VERSION}"

    # https://ftp.gnu.org/pub/gnu/libiconv/
    XBB_LIBICONV_VERSION="1.17" # "1.16"

    # https://zlib.net/fossils/
    XBB_ZLIB_VERSION="1.2.13" # "1.2.12"

    # https://gmplib.org/download/gmp/
    # Arm: In `gmp-h.in` search for `__GNU_MP_VERSION`.
    XBB_GMP_VERSION="6.3.0" # "6.2.1"

    # https://www.mpfr.org/history.html
    # Arm: In `VERSION`.
    XBB_MPFR_VERSION="4.2.0" # "4.1.0"

    # https://www.multiprecision.org/mpc/download.html
    # Arm: In `configure`, search for `VERSION=`.
    XBB_MPC_VERSION="1.3.1" # "1.2.1"

    # https://sourceforge.net/projects/libisl/files/
    # Arm: In `configure`, search for `PACKAGE_VERSION=`.
    XBB_ISL_VERSION="0.26" # "0.24"

    # https://sourceforge.net/projects/lzmautils/files/
    XBB_XZ_VERSION="5.4.4" # "5.2.5"

    # https://github.com/facebook/zstd/releases
    XBB_ZSTD_VERSION="1.5.5" # "1.5.2"

    # https://ftp.gnu.org/gnu/ncurses/
    XBB_NCURSES_VERSION="6.4" # "6.3"

    # https://github.com/westes/texinfo/releases
    XBB_TEXINFO_VERSION="7.0.3"

    # -------------------------------------------------------------------------

    libiconv_build "${XBB_LIBICONV_VERSION}"

    (
      XBB_NCURSES_DISABLE_WIDEC="y"

      ncurses_build "${XBB_NCURSES_VERSION}"
    )

    # Requires libiconf & ncurses.
    texinfo_build "${XBB_TEXINFO_VERSION}"

    # -------------------------------------------------------------------------

    # Download GCC earlier, to have time to run the multilib generator.
    gcc_cross_download
    gcc_cross_generate_riscv_multilib_file

    # -------------------------------------------------------------------------
    # Build the native dependencies.

    # new makeinfo needed by binutils 2.41 and up
    # checking for suffix of object files...   MAKEINFO doc/bfd.info
    # /Users/ilg/Work/xpack-dev-tools-build/riscv-none-elf-gcc-13.2.0-1/darwin-x64/sources/binutils-2.41/bfd/doc/bfd.texi:245: Node `Sections' requires a sectioning command (e.g., @unnumberedsubsec).
    # Now as xPack.

    if [ "${XBB_REQUESTED_HOST_PLATFORM}" == "win32" ]
    then
      echo
      echo "# Building a bootstrap compiler..."

      gcc_cross_build_dependencies

      gcc_cross_build_all "${XBB_APPLICATION_TARGET_TRIPLET}"
    fi

    # -------------------------------------------------------------------------
    # Build the target dependencies.

    xbb_reset_env
    xbb_set_target "requested"

    gcc_cross_build_dependencies

    # -------------------------------------------------------------------------
    # GDB dependencies

    # https://github.com/libexpat/libexpat/releases
    # Arm: from release notes
    # https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/downloads-1
    XBB_EXPAT_VERSION="2.5.0" # "2.4.8"

    # https://ftp.gnu.org/gnu/libunistring/
    XBB_LIBUNISTRING_VERSION="1.1"

    # https://ftp.gnu.org/pub/gnu/gettext/
    XBB_GETTEXT_VERSION="0.22" # "0.21"

    # https://github.com/telmich/gpm/tags
    # https://github.com/xpack-dev-tools/gpm/tags
    XBB_GPM_VERSION="1.20.7-1"

    # https://ftp.gnu.org/gnu/readline/
    XBB_READLINE_VERSION="8.2" # "8.1"

    # https://sourceware.org/pub/bzip2/
    XBB_BZIP2_VERSION="1.0.8"

    # https://github.com/libffi/libffi/releases
    XBB_LIBFFI_VERSION="3.4.4" # "3.4.2"

    # https://www.bytereef.org/mpdecimal/download.html
    XBB_MPDECIMAL_VERSION="2.5.1"

    # Required by a Python 3 module.
    # https://www.sqlite.org/download.html
    XBB_SQLITE_VERSION="3400100" # "3380200"

    # Replacement for the old libcrypt.so.1; required by Python 3.
    # https://github.com/besser82/libxcrypt/releases
    XBB_LIBXCRYPT_VERSION="4.4.36" # "4.4.28"

    # https://www.openssl.org/source/
    XBB_OPENSSL_VERSION="1.1.1v" # "1.1.1q"

    gdb_cross_build_dependencies

    # -------------------------------------------------------------------------
    # Build the application binaries.

    xbb_set_executables_install_path "${XBB_APPLICATION_INSTALL_FOLDER_PATH}"
    xbb_set_libraries_install_path "${XBB_DEPENDENCIES_INSTALL_FOLDER_PATH}"

    # -------------------------------------------------------------------------

    if [ "${XBB_REQUESTED_HOST_PLATFORM}" == "win32" ]
    then
      (
        # For makeinfo (binutils).
        xbb_activate_installed_bin

        binutils_cross_build "${XBB_BINUTILS_VERSION}" "${XBB_APPLICATION_TARGET_TRIPLET}"

        # As usual, for Windows things require more innovtive solutions.
        # In this case the libraries are copied from the bootstrap,
        # and only the executables are build for Windows.
        gcc_cross_copy_linux_libs "${XBB_APPLICATION_TARGET_TRIPLET}"

        # Be sure to have installed_bin to access the bootstrap compiler.
        gcc_cross_build_final "${XBB_GCC_VERSION}" "${XBB_APPLICATION_TARGET_TRIPLET}"
      )
    else
      # For macOS & GNU/Linux build the toolchain natively.
      gcc_cross_build_all "${XBB_APPLICATION_TARGET_TRIPLET}"
    fi

    gdb_cross_build "${XBB_APPLICATION_TARGET_TRIPLET}" ""

    if [ "${XBB_WITH_GDB_PY3}" == "y" ]
    then
      if [ "${XBB_REQUESTED_HOST_PLATFORM}" == "win32" ]
      then
        # Shortcut, use the existing python.exe instead of building
        # if from sources. It also downloads the sources.
        python3_download_win "${XBB_PYTHON3_VERSION}"
        python3_copy_win_syslibs
      else # linux or darwin
        # Copy libraries from sources and dependencies.
        python3_copy_syslibs
      fi

      gdb_cross_build "${XBB_APPLICATION_TARGET_TRIPLET}" "-py3"
    fi

    # -------------------------------------------------------------------------
  elif [[ ${XBB_RELEASE_VERSION} =~ 12[.][2][.]0-.* ]]
  then

    # -------------------------------------------------------------------------

    if [ "${XBB_APPLICATION_WITHOUT_MULTILIB:-""}" != "y" ]
    then
      # The SiFive list from 10.2 with a lot of non-c extras.
      # (including `rv32imaf-ilp32f--`).
      if [ "${XBB_IS_DEVELOP}" != "y" ]
      then

        # DO NOT add the combination that is already given as the default!
        # rv32imac-ilp32-- \

        XBB_GCC_MULTILIB_LIST=${XBB_GCC_MULTILIB_LIST:-"\
          rv32e-ilp32e-- \
          rv32ea-ilp32e-- \
          rv32eac-ilp32e-- \
          rv32ec-ilp32e-- \
          rv32em-ilp32e-- \
          rv32ema-ilp32e-- \
          rv32emac-ilp32e-- \
          rv32emc-ilp32e-- \
          \
          rv32i-ilp32-- \
          rv32ia-ilp32-- \
          rv32iac-ilp32-- \
          rv32iaf-ilp32f-- \
          rv32iafc-ilp32f-- \
          rv32iafd-ilp32d-- \
          rv32iafdc-ilp32d-- \
          rv32ic-ilp32-- \
          rv32if-ilp32f-- \
          rv32ifc-ilp32f-- \
          rv32ifd-ilp32d-- \
          rv32ifdc-ilp32d-- \
          rv32im-ilp32-- \
          rv32ima-ilp32-- \
          rv32imaf-ilp32f-- \
          rv32imafc-ilp32f-- \
          rv32imafd-ilp32d-- \
          rv32imafdc-ilp32d-- \
          rv32imc-ilp32-- \
          rv32imf-ilp32f-- \
          rv32imfc-ilp32f-- \
          rv32imfd-ilp32d-- \
          rv32imfdc-ilp32d-- \
          \
          rv64i-lp64-- \
          rv64ia-lp64-- \
          rv64iac-lp64-- \
          rv64iaf-lp64f-- \
          rv64iafc-lp64f-- \
          rv64iafd-lp64d-- \
          rv64iafdc-lp64d-- \
          rv64ic-lp64-- \
          rv64if-lp64f-- \
          rv64ifc-lp64f-- \
          rv64ifd-lp64d-- \
          rv64ifdc-lp64d-- \
          rv64im-lp64-- \
          rv64ima-lp64-- \
          rv64imac-lp64-- \
          rv64imaf-lp64f-- \
          rv64imafc-lp64f-- \
          rv64imafd-lp64d-- \
          rv64imafdc-lp64d-- \
          rv64imc-lp64-- \
          rv64imf-lp64f-- \
          rv64imfc-lp64f-- \
          rv64imfd-lp64d-- \
          rv64imfdc-lp64d-- \
        "}
      else
        # Short list used during development to save time.
        # Skip: rv32imac-ilp32-- (see above).
        XBB_GCC_MULTILIB_LIST=${XBB_GCC_MULTILIB_LIST:-"\
          rv32emac-ilp32e-- \
          rv32ima-ilp32-- \
          rv64imac-lp64-- \
        "}
      fi
    fi

    # https://ftp.gnu.org/gnu/binutils/
    # https://ftp.gnu.org/gnu/binutils/binutils-2.38.tar.xz

    XBB_BINUTILS_VERSION="2.38"

    XBB_BINUTILS_SRC_FOLDER_NAME="binutils-${XBB_BINUTILS_VERSION}"
    XBB_BINUTILS_ARCHIVE_NAME="binutils-${XBB_BINUTILS_VERSION}.tar.xz"
    XBB_BINUTILS_ARCHIVE_URL="https://ftp.gnu.org/gnu/binutils/${XBB_BINUTILS_ARCHIVE_NAME}"

    XBB_BINUTILS_PATCH_FILE_NAME="binutils-${XBB_BINUTILS_VERSION}.patch"

    # XBB_GCC_VERSION computer from XBB_RELEASE_VERSION
    XBB_GCC_SRC_FOLDER_NAME="gcc-${XBB_GCC_VERSION}"
    XBB_GCC_ARCHIVE_NAME="${XBB_GCC_SRC_FOLDER_NAME}.tar.xz"
    XBB_GCC_ARCHIVE_URL="https://ftp.gnu.org/gnu/gcc/gcc-${XBB_GCC_VERSION}/${XBB_GCC_ARCHIVE_NAME}"

    # The Apple Silicon host patches are already in for 12.x.
    # GCC_PATCH_FILE_NAME="gcc-${XBB_GCC_VERSION}-cross.git.patch"
    # check_patch "${GCC_PATCH_FILE_NAME}"

    # https://www.sourceware.org/ftp/newlib/index.html
    # ftp://sourceware.org/pub/newlib/newlib-4.2.0.20211231.tar.gz
    XBB_NEWLIB_VERSION="4.2.0.20211231"

    XBB_NEWLIB_SRC_FOLDER_NAME="newlib-${XBB_NEWLIB_VERSION}"
    XBB_NEWLIB_ARCHIVE_NAME="newlib-${XBB_NEWLIB_VERSION}.tar.gz"
    XBB_NEWLIB_ARCHIVE_URL="ftp://sourceware.org/pub/newlib/${XBB_NEWLIB_ARCHIVE_NAME}"

    XBB_ENABLE_NEWLIB_RISCV_NANO_CXX_PATCH="y"

    # https://ftp.gnu.org/gnu/gdb/
    # https://ftp.gnu.org/gnu/gdb/gdb-11.2.tar.xz
    # https://ftp.gnu.org/gnu/gdb/gdb-12.1.tar.xz

    XBB_GDB_VERSION="12.1" # "11.2"
    XBB_GDB_SRC_FOLDER_NAME="gdb-${XBB_GDB_VERSION}"
    XBB_GDB_ARCHIVE_NAME="${XBB_GDB_SRC_FOLDER_NAME}.tar.xz"
    XBB_GDB_ARCHIVE_URL="https://ftp.gnu.org/gnu/gdb/${XBB_GDB_ARCHIVE_NAME}"

    # Mandatory, otherwise gdb-py3 is not relocatable.
    XBB_GDB_PATCH_FILE_NAME="gdb-${XBB_GDB_VERSION}-cross.git.patch"
    check_patch "${XBB_GDB_PATCH_FILE_NAME}"

    # https://www.python.org/ftp/python/
    # Requires `scripts/helper/extras/python/pyconfig-win-3.10.4.h` &
    # `python3-config-win.sh`

    XBB_WITH_GDB_PY3="y"

    export XBB_PYTHON3_VERSION="3.10.4"
    export XBB_PYTHON3_VERSION_MAJOR=$(xbb_get_version_major "${XBB_PYTHON3_VERSION}")
    export XBB_PYTHON3_VERSION_MINOR=$(xbb_get_version_minor "${XBB_PYTHON3_VERSION}")

    # Explicit, since it is also used in python3_copy_syslibs
    export XBB_PYTHON3_SRC_FOLDER_NAME="Python-${XBB_PYTHON3_VERSION}"

    # https://ftp.gnu.org/pub/gnu/libiconv/
    XBB_LIBICONV_VERSION="1.16"

    # https://zlib.net/fossils/
    XBB_ZLIB_VERSION="1.2.12"

    # https://gmplib.org/download/gmp/
    # Arm: In `gmp-h.in` search for `__GNU_MP_VERSION`.
    XBB_GMP_VERSION="6.2.1"

    # https://www.mpfr.org/history.html
    # Arm: In `VERSION`.
    XBB_MPFR_VERSION="4.1.0"

    # https://www.multiprecision.org/mpc/download.html
    # Arm: In `configure`, search for `VERSION=`.
    XBB_MPC_VERSION="1.2.1"

    # https://sourceforge.net/projects/libisl/files/
    # Arm: In `configure`, search for `PACKAGE_VERSION=`.
    XBB_ISL_VERSION="0.24"

    # https://sourceforge.net/projects/lzmautils/files/
    XBB_XZ_VERSION="5.2.5"

    # https://github.com/facebook/zstd/releases
    XBB_ZSTD_VERSION="1.5.2"

    # -------------------------------------------------------------------------

    # Download GCC earlier, to have time to run the multilib generator.
    gcc_cross_download
    gcc_cross_generate_riscv_multilib_file

    # -------------------------------------------------------------------------
    # Build the native dependencies.

    if [ "${XBB_REQUESTED_HOST_PLATFORM}" == "win32" ]
    then
      echo
      echo "# Building a bootstrap compiler..."

      gcc_cross_build_dependencies

      gcc_cross_build_all "${XBB_APPLICATION_TARGET_TRIPLET}"
    fi

    # -------------------------------------------------------------------------
    # Build the target dependencies.

    xbb_reset_env
    xbb_set_target "requested"

    gcc_cross_build_dependencies

    # -------------------------------------------------------------------------
    # GDB dependencies

    # https://github.com/libexpat/libexpat/releases
    # Arm: from release notes
    # https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/downloads-1
    XBB_EXPAT_VERSION="2.4.8"

    # https://ftp.gnu.org/pub/gnu/gettext/
    XBB_GETTEXT_VERSION="0.21"

    # https://github.com/telmich/gpm/tags
    # https://github.com/xpack-dev-tools/gpm/tags
    XBB_GPM_VERSION="1.20.7-1"

    # https://ftp.gnu.org/gnu/ncurses/
    XBB_NCURSES_VERSION="6.3"

    # https://ftp.gnu.org/gnu/readline/
    XBB_READLINE_VERSION="8.1"

    # https://sourceware.org/pub/bzip2/
    XBB_BZIP2_VERSION="1.0.8"

    # https://github.com/libffi/libffi/releases
    XBB_LIBFFI_VERSION="3.4.2"

    # https://www.bytereef.org/mpdecimal/download.html
    XBB_MPDECIMAL_VERSION="2.5.1"

    # Required by a Python 3 module.
    # https://www.sqlite.org/download.html
    XBB_SQLITE_VERSION="3380200"

    # Replacement for the old libcrypt.so.1; required by Python 3.
    # https://github.com/besser82/libxcrypt/releases
    XBB_LIBXCRYPT_VERSION="4.4.28"

    # https://www.openssl.org/source/
    XBB_OPENSSL_VERSION="1.1.1q"

    gdb_cross_build_dependencies

    # -------------------------------------------------------------------------
    # Build the application binaries.

    xbb_set_executables_install_path "${XBB_APPLICATION_INSTALL_FOLDER_PATH}"
    xbb_set_libraries_install_path "${XBB_DEPENDENCIES_INSTALL_FOLDER_PATH}"

    # -------------------------------------------------------------------------

    if [ "${XBB_REQUESTED_HOST_PLATFORM}" == "win32" ]
    then
      binutils_cross_build "${XBB_BINUTILS_VERSION}" "${XBB_APPLICATION_TARGET_TRIPLET}"

      # As usual, for Windows things require more innovtive solutions.
      # In this case the libraries are copied from the bootstrap,
      # and only the executables are build for Windows.
      gcc_cross_copy_linux_libs "${XBB_APPLICATION_TARGET_TRIPLET}"

      (
        # To access the bootstrap compiler.
        xbb_activate_installed_bin

        gcc_cross_build_final "${XBB_GCC_VERSION}" "${XBB_APPLICATION_TARGET_TRIPLET}"
      )
    else
      # For macOS & GNU/Linux build the toolchain natively.
      gcc_cross_build_all "${XBB_APPLICATION_TARGET_TRIPLET}"
    fi

    gdb_cross_build "${XBB_APPLICATION_TARGET_TRIPLET}" ""

    if [ "${XBB_WITH_GDB_PY3}" == "y" ]
    then
      if [ "${XBB_REQUESTED_HOST_PLATFORM}" == "win32" ]
      then
        # Shortcut, use the existing python.exe instead of building
        # if from sources. It also downloads the sources.
        python3_download_win "${XBB_PYTHON3_VERSION}"
        python3_copy_win_syslibs
      else # linux or darwin
        # Copy libraries from sources and dependencies.
        python3_copy_syslibs
      fi

      gdb_cross_build "${XBB_APPLICATION_TARGET_TRIPLET}" "-py3"
    fi

    # -------------------------------------------------------------------------
  else
    echo "Unsupported ${XBB_APPLICATION_LOWER_CASE_NAME} version ${XBB_RELEASE_VERSION}"
    exit 1
  fi

  # ---------------------------------------------------------------------------

  gcc_cross_tidy_up

  if [ "${XBB_REQUESTED_HOST_PLATFORM}" != "win32" ]
  then
    gcc_cross_strip_libs "${XBB_APPLICATION_TARGET_TRIPLET}"
  fi

  gcc_cross_final_tunings

}

# -----------------------------------------------------------------------------
