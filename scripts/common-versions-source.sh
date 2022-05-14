# -----------------------------------------------------------------------------
# This file is part of the xPacks distribution.
#   (https://xpack.github.io)
# Copyright (c) 2020 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# Helper script used in the xPack build scripts. As the name implies,
# it should contain only functions and should be included with 'source'
# by the build scripts (both native and container).

# -----------------------------------------------------------------------------

function build_versions()
{
  APP_PREFIX_NANO="${INSTALL_FOLDER_PATH}/${APP_LC_NAME}-nano"

  # Don't use a comma since the regular expression
  # that processes this string in the Makefile, silently fails and the
  # bfdver.h file remains empty.
  BRANDING="${DISTRO_NAME} ${APP_NAME} ${TARGET_MACHINE}"

  CFLAGS_OPTIMIZATIONS_FOR_TARGET="-ffunction-sections -fdata-sections -O2 -w"
  # Cannot use medlow with 64 bits, so all must be medany.
  CFLAGS_OPTIMIZATIONS_FOR_TARGET+=" -mcmodel=medany"

  # ---------------------------------------------------------------------------
  # Defaults. Must be present.

  GCC_PATCH_FILE_NAME=""
  GDB_PATCH_FILE_NAME=""

  # ---------------------------------------------------------------------------

  # Redefine to "y" to create the LTO plugin links.
  if [ "${TARGET_PLATFORM}" == "darwin" ]
  then
    LTO_PLUGIN_ORIGINAL_NAME="liblto_plugin.so"
    LTO_PLUGIN_BFD_PATH="lib/bfd-plugins/liblto_plugin.so"
  elif [ "${TARGET_PLATFORM}" == "linux" ]
  then
    LTO_PLUGIN_ORIGINAL_NAME="liblto_plugin.so"
    LTO_PLUGIN_BFD_PATH="lib/bfd-plugins/liblto_plugin.so"
  elif [ "${TARGET_PLATFORM}" == "win32" ]
  then
    LTO_PLUGIN_ORIGINAL_NAME="liblto_plugin.dll"
    LTO_PLUGIN_BFD_PATH="lib/bfd-plugins/liblto_plugin.dll"
  fi

  FIX_LTO_PLUGIN="y"

  NCURSES_DISABLE_WIDEC="y"

  # ---------------------------------------------------------------------------

  GCC_VERSION="$(echo "${RELEASE_VERSION}" | sed -e 's|-.*||')"
  GCC_VERSION_MAJOR=$(echo ${GCC_VERSION} | sed -e 's|\([0-9][0-9]*\)\..*|\1|')

  if [ "${TARGET_PLATFORM}" == "win32" ]
  then
    prepare_gcc_env "${CROSS_COMPILE_PREFIX}-"
  fi

  # In reverse chronological order.
  if [[ ${RELEASE_VERSION} =~ 12\.1\.0-.* ]]
  then

    # -------------------------------------------------------------------------

    if [ "${WITHOUT_MULTILIB}" != "y" ]
    then
      # The SiFive list from 10.2 with a lot of non-c extras.
      # (including `rv32imaf-ilp32f--`).
      if [ "${IS_DEVELOP}" != "y" ]
      then

        # DO NOT add the combination that is already given as the default!
        # rv32imac-ilp32-- \

        GCC_MULTILIB=${GCC_MULTILIB:-"\
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
        GCC_MULTILIB=${GCC_MULTILIB:-"\
          rv32emac-ilp32e-- \
          rv32ima-ilp32-- \
          rv64imac-lp64-- \
        "}
      fi
    fi

    # -------------------------------------------------------------------------

    (
      xbb_activate

      # ---------------------------------------------------------------------------
      # Build dependent libraries.

      # For better control, without it some components pick the lib packed
      # inside the archive.
      # http://zlib.net/fossils/
      build_zlib "1.2.12"

      # The classical GCC libraries.
      # https://gmplib.org/download/gmp/
      build_gmp "6.2.1"
      # http://www.mpfr.org/history.html
      build_mpfr "4.1.0"
      # https://www.multiprecision.org/mpc/download.html
      build_mpc "1.2.1"
      # https://sourceforge.net/projects/libisl/files/
      build_isl "0.24"

      # More libraries.
      # https://www.bytereef.org/mpdecimal/download.html
      build_libmpdec "2.5.1" # Used by Python

      # https://github.com/libexpat/libexpat/releases
      build_expat "2.4.8"
      # https://ftp.gnu.org/pub/gnu/libiconv/
      build_libiconv "1.16"
      # https://sourceforge.net/projects/lzmautils/files/
      build_xz "5.2.5"

      # http://ftp.gnu.org/pub/gnu/gettext/
      build_gettext "0.21"

      # https://www.python.org/ftp/python/
      # Requires `scripts/helper/extras/python/pyconfig-win-3.10.4.h` &
      # `python3-config-win.sh`
      PYTHON3_VERSION="3.10.4"
      WITH_GDB_PY3="y"

      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        if [ "${WITH_GDB_PY3}" == "y" ]
        then
          # Shortcut, use the existing pyton.exe instead of building
          # if from sources. It also downloads the sources.
          download_python3_win "${PYTHON3_VERSION}"

          add_python3_win_syslibs
        fi
      else # linux or darwin
        # Used by ncurses. Fails on macOS.
        if [ "${TARGET_PLATFORM}" == "linux" ]
        then
          # https://github.com/telmich/gpm/tags
          # https://github.com/xpack-dev-tools/gpm/tags
          build_gpm "1.20.7-1"
        fi

        # https://ftp.gnu.org/gnu/ncurses/
        build_ncurses "6.3"

        # https://ftp.gnu.org/gnu/readline/
        build_readline "8.1" # requires ncurses

        # https://sourceware.org/pub/bzip2/
        build_bzip2 "1.0.8"
        # https://github.com/libffi/libffi/releases
        build_libffi "3.4.2"

        # We cannot rely on a python shared library in the system, even
        # the custom build from sources does not have one.

        if [ "${WITH_GDB_PY3}" == "y" ]
        then
          # Required by a Python 3 module.
          # https://www.sqlite.org/download.html
          build_sqlite "3380200"

          # Replacement for the old libcrypt.so.1; required by Python 3.
          # https://github.com/besser82/libxcrypt/releases
          build_libxcrypt "4.4.28"

          # https://www.openssl.org/source/
          build_openssl "1.1.1n"

          build_python3 "${PYTHON3_VERSION}"

          add_python3_syslibs
        fi
      fi
      # exit 1

      # ---------------------------------------------------------------------------
      # The task descriptions are from the ARM build script.

      # Task [III-0] /$HOST_NATIVE/binutils/
      # Task [IV-1] /$HOST_MINGW/binutils/

      # https://ftp.gnu.org/gnu/binutils/
      # https://ftp.gnu.org/gnu/binutils/binutils-2.38.tar.xz

      BINUTILS_VERSION="2.38"

      BINUTILS_SRC_FOLDER_NAME="binutils-${BINUTILS_VERSION}"
      BINUTILS_ARCHIVE_NAME="binutils-${BINUTILS_VERSION}.tar.xz"
      BINUTILS_ARCHIVE_URL="https://ftp.gnu.org/gnu/binutils/${BINUTILS_ARCHIVE_NAME}"

      build_cross_binutils
      # copy_dir to libs included above
      # exit 1

      # prepare_gcc_variables "${GCC_VERSION}"

      # GCC_VERSION computer from RELEASE_VERSION
      GCC_SRC_FOLDER_NAME="gcc-${GCC_VERSION}"
      GCC_ARCHIVE_NAME="${GCC_SRC_FOLDER_NAME}.tar.xz"
      GCC_ARCHIVE_URL="https://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/${GCC_ARCHIVE_NAME}"

      GCC_PATCH_FILE_NAME="gcc-${GCC_VERSION}.patch.diff"

      # Download GCC earlier, to have time to run the multilib generator.
      download_cross_gcc
      generate_multilib_file

      if [ "${TARGET_PLATFORM}" != "win32" ]
      then

        # Task [III-1] /$HOST_NATIVE/gcc-first/
        build_cross_gcc_first
        # exit 1

        # https://www.sourceware.org/ftp/newlib/index.html
        # ftp://sourceware.org/pub/newlib/newlib-4.2.0.20211231.tar.gz
        NEWLIB_VERSION="4.2.0.20211231"

        NEWLIB_SRC_FOLDER_NAME="newlib-${NEWLIB_VERSION}"
        NEWLIB_ARCHIVE_NAME="newlib-${NEWLIB_VERSION}.tar.gz"
        NEWLIB_ARCHIVE_URL="ftp://sourceware.org/pub/newlib/${NEWLIB_ARCHIVE_NAME}"

        # Task [III-2] /$HOST_NATIVE/newlib/
        build_cross_newlib ""
        # exit 1

        # Task [III-4] /$HOST_NATIVE/gcc-final/
        build_cross_gcc_final ""
        # exit 1

        # Once again, for the -nano variant.
        # Task [III-3] /$HOST_NATIVE/newlib-nano/
        build_cross_newlib "-nano"

        # Task [III-5] /$HOST_NATIVE/gcc-size-libstdcxx/
        build_cross_gcc_final "-nano"
        # exit 1

      else

        # Task [IV-2] /$HOST_MINGW/copy_libs/
        copy_cross_linux_libs

        # Task [IV-3] /$HOST_MINGW/gcc-final/
        build_cross_gcc_final ""
        # exit 1

      fi

      # https://ftp.gnu.org/gnu/gdb/
      # https://ftp.gnu.org/gnu/gdb/gdb-11.2.tar.xz
      # https://ftp.gnu.org/gnu/gdb/gdb-12.1.tar.xz

      GDB_VERSION="12.1" # "11.2"
      GDB_SRC_FOLDER_NAME="gdb-${GDB_VERSION}"
      GDB_ARCHIVE_NAME="${GDB_SRC_FOLDER_NAME}.tar.xz"
      GDB_ARCHIVE_URL="https://ftp.gnu.org/gnu/gdb/${GDB_ARCHIVE_NAME}"

      # Mandatory, otherwise gdb-py3 is not relocatable.
      GDB_PATCH_FILE_NAME="gdb-${GDB_VERSION}.patch.diff"

      # Task [III-6] /$HOST_NATIVE/gdb/
      # Task [IV-4] /$HOST_MINGW/gdb/
      build_cross_gdb ""

      if [ "${WITH_GDB_PY3}" == "y" ]
      then
        build_cross_gdb "-py3"
      fi
    )

    # Task [III-7] /$HOST_NATIVE/build-manual
    # Nope, the build process is different.

    # ---------------------------------------------------------------------------

    # Task [III-8] /$HOST_NATIVE/pretidy/
    # Task [IV-5] /$HOST_MINGW/pretidy/
    tidy_up

    # Task [III-9] /$HOST_NATIVE/strip_host_objects/
    # Task [IV-6] /$HOST_MINGW/strip_host_objects/

    # strip_binaries # In common code.

    # Must be done after gcc 2 make install, otherwise some wrong links
    # are created in libexec.
    # Must also be done after strip binaries, since strip after patchelf
    # damages the binaries.

    # prepare_app_folder_libraries # In common code.

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then
      # Task [III-10] /$HOST_NATIVE/strip_target_objects/
      strip_libs
    fi

    final_tunings

    # Task [IV-7] /$HOST_MINGW/installation/
    # Nope, no setup.exe.

    # Task [III-11] /$HOST_NATIVE/package_tbz2/
    # Task [IV-8] /Package toolchain in zip format/

    # -------------------------------------------------------------------------
  elif [[ ${RELEASE_VERSION} =~ 11\.3\.0-.* ]]
  then

    # -------------------------------------------------------------------------

    if [ "${WITHOUT_MULTILIB}" != "y" ]
    then
      # The SiFive list from 10.2 with a lot of non-c extras.
      # (including `rv32imaf-ilp32f--`).
      if [ "${IS_DEVELOP}" != "y" ]
      then

        # DO NOT add the combination that is already given as the default!
        # rv32imac-ilp32-- \

        GCC_MULTILIB=${GCC_MULTILIB:-"\
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
        GCC_MULTILIB=${GCC_MULTILIB:-"\
          rv32emac-ilp32e-- \
          rv32ima-ilp32-- \
          rv64imac-lp64-- \
        "}
      fi
    fi

    # -------------------------------------------------------------------------

    (
      xbb_activate

      # ---------------------------------------------------------------------------
      # Build dependent libraries.

      # For better control, without it some components pick the lib packed
      # inside the archive.
      # http://zlib.net/fossils/
      build_zlib "1.2.12"

      # The classical GCC libraries.
      # https://gmplib.org/download/gmp/
      build_gmp "6.2.1"
      # http://www.mpfr.org/history.html
      build_mpfr "4.1.0"
      # https://www.multiprecision.org/mpc/download.html
      build_mpc "1.2.1"
      # https://sourceforge.net/projects/libisl/files/
      build_isl "0.24"

      # More libraries.
      # https://www.bytereef.org/mpdecimal/download.html
      build_libmpdec "2.5.1" # Used by Python

      # https://github.com/libexpat/libexpat/releases
      build_expat "2.4.8"
      # https://ftp.gnu.org/pub/gnu/libiconv/
      build_libiconv "1.16"
      # https://sourceforge.net/projects/lzmautils/files/
      build_xz "5.2.5"

      # http://ftp.gnu.org/pub/gnu/gettext/
      build_gettext "0.21"

      # https://www.python.org/ftp/python/
      # Requires `scripts/helper/extras/python/pyconfig-win-3.10.4.h` &
      # `python3-config-win.sh`
      PYTHON3_VERSION="3.10.4"
      WITH_GDB_PY3="y"

      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        if [ "${WITH_GDB_PY3}" == "y" ]
        then
          # Shortcut, use the existing pyton.exe instead of building
          # if from sources. It also downloads the sources.
          download_python3_win "${PYTHON3_VERSION}"

          add_python3_win_syslibs
        fi
      else # linux or darwin
        # Used by ncurses. Fails on macOS.
        if [ "${TARGET_PLATFORM}" == "linux" ]
        then
          # https://github.com/telmich/gpm/tags
          # https://github.com/xpack-dev-tools/gpm/tags
          build_gpm "1.20.7-1"
        fi

        # https://ftp.gnu.org/gnu/ncurses/
        build_ncurses "6.3"

        # https://ftp.gnu.org/gnu/readline/
        build_readline "8.1" # requires ncurses

        # https://sourceware.org/pub/bzip2/
        build_bzip2 "1.0.8"
        # https://github.com/libffi/libffi/releases
        build_libffi "3.4.2"

        # We cannot rely on a python shared library in the system, even
        # the custom build from sources does not have one.

        if [ "${WITH_GDB_PY3}" == "y" ]
        then
          # Required by a Python 3 module.
          # https://www.sqlite.org/download.html
          build_sqlite "3380200"

          # Replacement for the old libcrypt.so.1; required by Python 3.
          # https://github.com/besser82/libxcrypt/releases
          build_libxcrypt "4.4.28"

          # https://www.openssl.org/source/
          build_openssl "1.1.1n"

          build_python3 "${PYTHON3_VERSION}"

          add_python3_syslibs
        fi
      fi
      # exit 1

      # ---------------------------------------------------------------------------
      # The task descriptions are from the ARM build script.

      # Task [III-0] /$HOST_NATIVE/binutils/
      # Task [IV-1] /$HOST_MINGW/binutils/

      # https://ftp.gnu.org/gnu/binutils/
      # https://ftp.gnu.org/gnu/binutils/binutils-2.38.tar.xz

      BINUTILS_VERSION="2.38"

      BINUTILS_SRC_FOLDER_NAME="binutils-${BINUTILS_VERSION}"
      BINUTILS_ARCHIVE_NAME="binutils-${BINUTILS_VERSION}.tar.xz"
      BINUTILS_ARCHIVE_URL="https://ftp.gnu.org/gnu/binutils/${BINUTILS_ARCHIVE_NAME}"

      build_cross_binutils
      # copy_dir to libs included above
      # exit 1

      # prepare_gcc_variables "${GCC_VERSION}"

      # GCC_VERSION computer from RELEASE_VERSION
      GCC_SRC_FOLDER_NAME="gcc-${GCC_VERSION}"
      GCC_ARCHIVE_NAME="${GCC_SRC_FOLDER_NAME}.tar.xz"
      GCC_ARCHIVE_URL="https://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/${GCC_ARCHIVE_NAME}"

      GCC_PATCH_FILE_NAME="gcc-${GCC_VERSION}.patch.diff"

      # Download GCC earlier, to have time to run the multilib generator.
      download_cross_gcc
      generate_multilib_file

      if [ "${TARGET_PLATFORM}" != "win32" ]
      then

        # Task [III-1] /$HOST_NATIVE/gcc-first/
        build_cross_gcc_first
        # exit 1

        # https://www.sourceware.org/ftp/newlib/index.html
        # ftp://sourceware.org/pub/newlib/newlib-4.2.0.20211231.tar.gz
        NEWLIB_VERSION="4.2.0.20211231"

        NEWLIB_SRC_FOLDER_NAME="newlib-${NEWLIB_VERSION}"
        NEWLIB_ARCHIVE_NAME="newlib-${NEWLIB_VERSION}.tar.gz"
        NEWLIB_ARCHIVE_URL="ftp://sourceware.org/pub/newlib/${NEWLIB_ARCHIVE_NAME}"

        # Task [III-2] /$HOST_NATIVE/newlib/
        build_cross_newlib ""
        # exit 1

        # Task [III-4] /$HOST_NATIVE/gcc-final/
        build_cross_gcc_final ""
        # exit 1

        # Once again, for the -nano variant.
        # Task [III-3] /$HOST_NATIVE/newlib-nano/
        build_cross_newlib "-nano"

        # Task [III-5] /$HOST_NATIVE/gcc-size-libstdcxx/
        build_cross_gcc_final "-nano"
        # exit 1

      else

        # Task [IV-2] /$HOST_MINGW/copy_libs/
        copy_cross_linux_libs

        # Task [IV-3] /$HOST_MINGW/gcc-final/
        build_cross_gcc_final ""
        # exit 1

      fi

      # https://ftp.gnu.org/gnu/gdb/
      # https://ftp.gnu.org/gnu/gdb/gdb-11.2.tar.xz
      # https://ftp.gnu.org/gnu/gdb/gdb-12.1.tar.xz

      GDB_VERSION="12.1" # "11.2"
      GDB_SRC_FOLDER_NAME="gdb-${GDB_VERSION}"
      GDB_ARCHIVE_NAME="${GDB_SRC_FOLDER_NAME}.tar.xz"
      GDB_ARCHIVE_URL="https://ftp.gnu.org/gnu/gdb/${GDB_ARCHIVE_NAME}"

      # Mandatory, otherwise gdb-py3 is not relocatable.
      GDB_PATCH_FILE_NAME="gdb-${GDB_VERSION}.patch.diff"

      # Task [III-6] /$HOST_NATIVE/gdb/
      # Task [IV-4] /$HOST_MINGW/gdb/
      build_cross_gdb ""

      if [ "${WITH_GDB_PY3}" == "y" ]
      then
        build_cross_gdb "-py3"
      fi
    )

    # Task [III-7] /$HOST_NATIVE/build-manual
    # Nope, the build process is different.

    # ---------------------------------------------------------------------------

    # Task [III-8] /$HOST_NATIVE/pretidy/
    # Task [IV-5] /$HOST_MINGW/pretidy/
    tidy_up

    # Task [III-9] /$HOST_NATIVE/strip_host_objects/
    # Task [IV-6] /$HOST_MINGW/strip_host_objects/

    # strip_binaries # In common code.

    # Must be done after gcc 2 make install, otherwise some wrong links
    # are created in libexec.
    # Must also be done after strip binaries, since strip after patchelf
    # damages the binaries.

    # prepare_app_folder_libraries # In common code.

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then
      # Task [III-10] /$HOST_NATIVE/strip_target_objects/
      strip_libs
    fi

    final_tunings

    # Task [IV-7] /$HOST_MINGW/installation/
    # Nope, no setup.exe.

    # Task [III-11] /$HOST_NATIVE/package_tbz2/
    # Task [IV-8] /Package toolchain in zip format/

    # -------------------------------------------------------------------------
  else
    echo "Unsupported version ${RELEASE_VERSION}."
    exit 1
  fi

}

# -----------------------------------------------------------------------------
