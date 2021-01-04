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

function build_versions()
{

  APP_PREFIX_NANO="${INSTALL_FOLDER_PATH}/${APP_LC_NAME}-nano"

  # The \x2C is a comma in hex; without this trick the regular expression
  # that processes this string in the Makefile, silently fails and the 
  # bfdver.h file remains empty.
  BRANDING="${BRANDING}\x2C ${TARGET_BITS}-bit"

  CFLAGS_OPTIMIZATIONS_FOR_TARGET="-ffunction-sections -fdata-sections -O2 -w"
  # Cannot use medlow with 64 bits, so all must be medany.
  CFLAGS_OPTIMIZATIONS_FOR_TARGET+=" -mcmodel=medany"

  BINUTILS_PROJECT_NAME="riscv-binutils-gdb"
  GCC_PROJECT_NAME="riscv-gcc"
  NEWLIB_PROJECT_NAME="riscv-newlib"
  GDB_PROJECT_NAME="riscv-binutils-gdb"

  # ---------------------------------------------------------------------------
  # Defaults. Must be present.

  BINUTILS_PATCH=""
  GDB_PATCH=""

  WITH_GDB_PY2=""
  WITH_GDB_PY3=""
  USE_PLATFORM_PYTHON2=""
  USE_PLATFORM_PYTHON3=""

  if [ "${WITHOUT_MULTILIB}" == "y" ]
  then
    MULTILIB_FLAGS="--disable-multilib"
  else
    # By default it searches the definitions in "t-elf-multilib"
    MULTILIB_FLAGS=""
  fi

  # ---------------------------------------------------------------------------

  # Redefine to "y" to create the LTO plugin links.
  FIX_LTO_PLUGIN=""
  if [ "${TARGET_PLATFORM}" == "darwin" ]
  then
    LTO_PLUGIN_ORIGINAL_NAME="liblto_plugin.0.so"
    LTO_PLUGIN_BFD_PATH="lib/bfd-plugins/liblto_plugin.so"
  elif [ "${TARGET_PLATFORM}" == "linux" ]
  then
    LTO_PLUGIN_ORIGINAL_NAME="liblto_plugin.so.0.0.0"
    LTO_PLUGIN_BFD_PATH="lib/bfd-plugins/liblto_plugin.so"
  elif [ "${TARGET_PLATFORM}" == "win32" ]
  then
    LTO_PLUGIN_ORIGINAL_NAME="liblto_plugin-0.dll"
    LTO_PLUGIN_BFD_PATH="lib/bfd-plugins/liblto_plugin-0.dll"
  fi

  FIX_LTO_PLUGIN="y"

  # ---------------------------------------------------------------------------

  GCC_VERSION="$(echo "${RELEASE_VERSION}" | sed -e 's|-[0-9]*||')"

  # In reverse chronological order.
  # Keep them in sync with https://github.com/sifive/freedom-tools/releases.
  if [[ "${RELEASE_VERSION}" =~ 10\.1\.0-1\.* ]]
  then
    # This is similar to SiFive 2020.08.0 release.
    # https://github.com/sifive/freedom-tools/releases
    # https://github.com/sifive/freedom-tools/releases/tag/v2020.08.0
    # https://github.com/sifive/freedom-tools/
    # https://github.com/sifive/freedom-tools/tree/v2020.08.0

    # Binutils 2.35 with SiFive CLIC patches
    # https://github.com/sifive/riscv-binutils-gdb/tree/e30af3b82e62e7f8ca13992fa3c4ee6a3d0208fd

    # GCC 10.1.0 with SiFive CLIC patches
    # https://github.com/sifive/riscv-gcc/tree/04cdc9d15b90c62ef30609e9086d55101c190dc1

    # Newlib 3.2.0 from SiFive branch
    # https://github.com/sifive/riscv-newlib/tree/7bee030c58a59b724c64c6b7aab2dd660a890410

    # GDB 9.1 from SiFive branch
    # https://github.com/sifive/riscv-binutils-gdb/tree/24e9280aac7a33dd683f4431ca73ed9ce6bd14bd

    # -------------------------------------------------------------------------

    BINUTILS_VERSION="2.35"
    # From gcc/BASE_VER
    GCC_VERSION="10.1.0"
    # From newlib/configure, VERSION=
    NEWLIB_VERSION="3.2.0"
    # From gdb/VERSION.in
    GDB_VERSION="9.1"

    # -------------------------------------------------------------------------

    # Inspired from SiFive
    # MULTILIBS_GEN :=            rv32e-ilp32e--c rv32em-ilp32e--c rv32eac-ilp32e-- rv32emac-ilp32e-- rv32i-ilp32--c rv32im-ilp32--c rv32imf-ilp32f--c rv32iac-ilp32-- rv32imac-ilp32-- rv32imafc-ilp32f-rv32imafdc- rv32imafdc-ilp32d-- rv64i-lp64--c rv64im-lp64--c rv64imf-lp64f--c rv64iac-lp64-- rv64imac-lp64-- rv64imafc-lp64f-rv64imafdc- rv64imafdc-lp64d--

    # Minimal list, for tests only. Pass it via the environment.
    # GCC_MULTILIB=${GCC_MULTILIB:-"rv32imac-ilp32-- rv64imac-lp64--"}

    # New extended list, based on SiFive list.
    # Added: rv32imaf-ilp32f-- (already in)
    GCC_MULTILIB=${GCC_MULTILIB:-"\
    rv32e-ilp32e--c*v*zvqmac \
    rv32ea-ilp32e--m*v*zvqmac \
    rv32em-ilp32e--c*v*zvqmac \
    rv32eac-ilp32e--v*zvqmac \
    rv32emac-ilp32e--v*zvqmac \
    rv32i-ilp32--c*f*d*zfh*v*zvqmac \
    rv32ia-ilp32--m*f*d*v*zfh*zvqmac \
    rv32im-ilp32--c*f*d*zfh*v*zvqmac \
    rv32iac-ilp32--f*d*v*zfh*zvqmac \
    rv32imac-ilp32-rv32imafc,rv32imafdc,rv32imafczfh,rv32imafdczfh-v*zvqmac \
    rv32if-ilp32f--d*c*v*zfh*zvqmac \
    rv32iaf-ilp32f--d*c*v*zfh*zvqmac \
    rv32imf-ilp32f--d*v*zfh*zvqmac \
    rv32imaf-ilp32f-rv32imafd-zfh*v*zvqmac \
    rv32imfc-ilp32f--d*v*zfh*zvqmac \
    rv32imafc-ilp32f-rv32imafdc-v*zfh*zvqmac \
    rv32ifd-ilp32d--c*v*zfh*zvqmac \
    rv32imfd-ilp32d--c*v*zfh*zvqmac \
    rv32iafd-ilp32d-rv32imafd,rv32iafdc-v*zfh*zvqmac \
    rv32imafdc-ilp32d--v*zfh*zvqmac \
    rv64i-lp64--f*d*c*v*zfh*zvqmac \
    rv64ia-lp64--m*f*d*v*zfh*zvqmac \
    rv64im-lp64--f*d*c*v*zfh*zvqmac \
    rv64iac-lp64--f*d*v*zfh*zvqmac \
    rv64imac-lp64-rv64imafc,rv64imafdc,rv64imafczfh,rv64imafdczfh-v*zvqmac \
    rv64if-lp64f--d*c*v*zfh*zvqmac \
    rv64iaf-lp64f--d*c*v*zfh*zvqmac \
    rv64imf-lp64f--d*v*zfh*zvqmac \
    rv64imaf-lp64f-rv64imafd-v*zfh*zvqmac \
    rv64imfc-lp64f--d*v*zfh*zvqmac \
    rv64imafc-lp64f-rv64imafdc-v*zfh*zvqmac \
    rv64ifd-lp64d--c*v*zfh*zvqmac \
    rv64imfd-lp64d--c*v*zfh*zvqmac \
    rv64iafd-lp64d-rv64imafd,rv64iafdc-v*zfh*zvqmac \
    rv64imafdc-lp64d--v*zfh*zvqmac \
    "}

    GCC_MULTILIB_FILE=${GCC_MULTILIB_FILE:-"t-elf-multilib"}

    # -------------------------------------------------------------------------


    if [ "${USE_GITS}" != "y" ]
    then

      # Be sure there is no `v`, it is added in the URL.
      GH_RELEASE="${RELEASE_VERSION}"

      BINUTILS_GH_RELEASE=${BINUTILS_GH_RELEASE:-"${GH_RELEASE}"}
      GCC_GH_RELEASE=${GCC_GH_RELEASE:-"${GH_RELEASE}"}
      NEWLIB_GH_RELEASE=${NEWLIB_GH_RELEASE:-"${GH_RELEASE}"}
      # Same, with a `-gdb` suffix added.
      GDB_GH_RELEASE=${GDB_GH_RELEASE:-"${GH_RELEASE}-gdb"}

    else

      BINUTILS_GIT_BRANCH=${BINUTILS_GIT_BRANCH:-"v2020.08.0-xpack"}
      BINUTILS_GIT_COMMIT=${BINUTILS_GIT_COMMIT:-"0087c431ff1f7f7530b212fa06a27b89e464df53"}

      GCC_GIT_BRANCH=${GCC_GIT_BRANCH:-"v2020.08.0-xpack"}
      GCC_GIT_COMMIT=${GCC_GIT_COMMIT:-"6c3ae221b1292bb0163bbd62c3fe6289ee5633bc"}

      NEWLIB_GIT_BRANCH=${NEWLIB_GIT_BRANCH:-"v2020.08.0-xpack"}
      NEWLIB_GIT_COMMIT=${NEWLIB_GIT_COMMIT:-"70ceac87eea11d55bd87c53fa633afc03a263888"}

      GDB_SRC_FOLDER_NAME=${GDB_SRC_FOLDER_NAME:-"binutils-gdb.git"}
      GDB_GIT_BRANCH=${GDB_GIT_BRANCH:-"v2020.08.0-gdb-xpack"}
      GDB_GIT_COMMIT=${GDB_GIT_COMMIT:-"b3302ee671beb2ea9ea80528c7c779cfd765dd00"}

    fi
    
    # -------------------------------------------------------------------------

    WITH_GDB_PY3="y"

    PYTHON3_VERSION="3.7.9"

    BINUTILS_PATCH="binutils-${BINUTILS_VERSION}.patch"
    GDB_PATCH="gdb-${GDB_VERSION}.patch"

    prepare_variables

    # ---------------------------------------------------------------------------
    # Build dependent libraries.

    # For better control, without it some components pick the lib packed 
    # inside the archive.
    build_zlib "1.2.8"

    # The classical GCC libraries.
    build_gmp "6.1.2"
    build_mpfr "3.1.6"
    build_mpc "1.0.3"
    build_isl "0.18"

    # More libraries.
    # Fails on mingw
    ## build_libelf "0.8.13"
    build_libmpdec "2.5.0" # Used by Python
    build_expat "2.2.5"
    build_libiconv "1.15"
    build_xz "5.2.3"

    build_gettext "0.19.8.1"

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
        build_gpm "1.20.7"
      fi

      build_ncurses "6.2"

      build_readline "8.0" # requires ncurses

      build_bzip2 "1.0.8"
      build_libffi "3.3"

      # We cannot rely on a python shared library in the system, even
      # the custom build from sources does not have one.

      if [ "${WITH_GDB_PY3}" == "y" ]
      then
        # Required by a Python 3 module.
        build_sqlite "3.32.3"

        # Replacement for the old libcrypt.so.1; required by Python 3.
        build_libxcrypt "4.4.17"
        build_openssl "1.1.1h"

        build_python3 "${PYTHON3_VERSION}"

        add_python3_syslibs
      fi
    fi

    # ---------------------------------------------------------------------------

    # The task descriptions are from the ARM build script.

    # Task [III-0] /$HOST_NATIVE/binutils/
    # Task [IV-1] /$HOST_MINGW/binutils/
    build_binutils "${BINUTILS_VERSION}"
    # copy_dir to libs included above

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then

      # Task [III-1] /$HOST_NATIVE/gcc-first/
      build_gcc_first

      # Task [III-2] /$HOST_NATIVE/newlib/
      build_newlib ""
      # Task [III-3] /$HOST_NATIVE/newlib-nano/
      build_newlib "-nano"

      # Task [III-4] /$HOST_NATIVE/gcc-final/
      build_gcc_final ""

      # Task [III-5] /$HOST_NATIVE/gcc-size-libstdcxx/
      build_gcc_final "-nano"

    else

      # Task [IV-2] /$HOST_MINGW/copy_libs/
      copy_linux_libs

      # Task [IV-3] /$HOST_MINGW/gcc-final/
      build_gcc_final ""

    fi

    # Task [III-6] /$HOST_NATIVE/gdb/
    # Task [IV-4] /$HOST_MINGW/gdb/
    build_gdb ""

    if [ "${WITH_GDB_PY3}" == "y" ]
    then
      build_gdb "-py3"
    fi

    # Task [III-7] /$HOST_NATIVE/build-manual
    # Nope, the build process is different.

    # ---------------------------------------------------------------------------

    # Task [III-8] /$HOST_NATIVE/pretidy/
    # Task [IV-5] /$HOST_MINGW/pretidy/
    tidy_up

    # Task [III-9] /$HOST_NATIVE/strip_host_objects/
    # Task [IV-6] /$HOST_MINGW/strip_host_objects/
    strip_binaries

    # Must be done after gcc 2 make install, otherwise some wrong links
    # are created in libexec.
    # Must also be done after strip binaries, since strip after patchelf
    # damages the binaries.
    prepare_app_folder_libraries

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
  elif [[ "${RELEASE_VERSION}" =~ 8\.3\.0-2\.* ]]
  then
    # This is similar to SiFive 2020.04.0 release.
    # https://github.com/sifive/freedom-tools/releases
    # https://github.com/sifive/freedom-tools/releases/tag/v2020.04.0-Toolchain.Only
    # https://github.com/sifive/freedom-tools/
    # https://github.com/sifive/freedom-tools/tree/v2020.04.0-Toolchain.Only

    # Binutils 2.32 with SiFive CLIC patches
    # https://github.com/sifive/riscv-binutils-gdb/tree/ac7ecc464d0b0466c056a29e357da0f38aec4705

    # GCC 8.3.0 with SiFive CLIC patches
    # https://github.com/sifive/riscv-gcc/tree/e195042babe2dc30d9fabb88d336d8c8679b3702

    # Newlib 3.1.0 from SiFive branch
    # https://github.com/sifive/riscv-newlib/tree/6c668f856bdd678ac1885aa07ffcfcc7483221b8

    # GDB 8.3 from SiFive branch
    # https://github.com/sifive/riscv-binutils-gdb/tree/62a5c5e36b338bd15c7671332bb49c4ef1e5db15

    # -------------------------------------------------------------------------

    BINUTILS_VERSION="2.32"
    # From gcc/BASE_VER
    GCC_VERSION="8.3.0"
    # From newlib/configure, VERSION=
    NEWLIB_VERSION="3.1.0"
    # From gdb/VERSION.in
    GDB_VERSION="8.3"

    if [ "${RELEASE_VERSION}" == "8.3.0-2.1" ]
    then
      README_OUT_FILE_NAME="README-${RELEASE_VERSION}.md"
    fi

    # -------------------------------------------------------------------------

    # Inspired from SiFive
    # MULTILIBS_GEN :=            rv32e-ilp32e--c rv32em-ilp32e--c rv32eac-ilp32e-- rv32emac-ilp32e-- rv32i-ilp32--c rv32im-ilp32--c rv32imf-ilp32f--c rv32iac-ilp32-- rv32imac-ilp32-- rv32imafc-ilp32f-rv32imafdc- rv32imafdc-ilp32d-- rv64i-lp64--c rv64im-lp64--c rv64imf-lp64f--c rv64iac-lp64-- rv64imac-lp64-- rv64imafc-lp64f-rv64imafdc- rv64imafdc-lp64d--

    # Minimal list, for tests only. Pass it via the environment.
    # GCC_MULTILIB=${GCC_MULTILIB:-"rv32imac-ilp32-- rv64imac-lp64--"}

    # New extended list, based on SiFive list.
    # Added: rv32imaf-ilp32f-- (already in)
    GCC_MULTILIB=${GCC_MULTILIB:-"\
    rv32e-ilp32e--c*v*zvqmac \
    rv32ea-ilp32e--m*v*zvqmac \
    rv32em-ilp32e--c*v*zvqmac \
    rv32eac-ilp32e--v*zvqmac \
    rv32emac-ilp32e--v*zvqmac \
    rv32i-ilp32--c*f*d*zfh*v*zvqmac \
    rv32ia-ilp32--m*f*d*v*zfh*zvqmac \
    rv32im-ilp32--c*f*d*zfh*v*zvqmac \
    rv32iac-ilp32--f*d*v*zfh*zvqmac \
    rv32imac-ilp32-rv32imafc,rv32imafdc,rv32imafczfh,rv32imafdczfh-v*zvqmac \
    rv32if-ilp32f--d*c*v*zfh*zvqmac \
    rv32iaf-ilp32f--d*c*v*zfh*zvqmac \
    rv32imf-ilp32f--d*v*zfh*zvqmac \
    rv32imaf-ilp32f-rv32imafd-zfh*v*zvqmac \
    rv32imfc-ilp32f--d*v*zfh*zvqmac \
    rv32imafc-ilp32f-rv32imafdc-v*zfh*zvqmac \
    rv32ifd-ilp32d--c*v*zfh*zvqmac \
    rv32imfd-ilp32d--c*v*zfh*zvqmac \
    rv32iafd-ilp32d-rv32imafd,rv32iafdc-v*zfh*zvqmac \
    rv32imafdc-ilp32d--v*zfh*zvqmac \
    rv64i-lp64--f*d*c*v*zfh*zvqmac \
    rv64ia-lp64--m*f*d*v*zfh*zvqmac \
    rv64im-lp64--f*d*c*v*zfh*zvqmac \
    rv64iac-lp64--f*d*v*zfh*zvqmac \
    rv64imac-lp64-rv64imafc,rv64imafdc,rv64imafczfh,rv64imafdczfh-v*zvqmac \
    rv64if-lp64f--d*c*v*zfh*zvqmac \
    rv64iaf-lp64f--d*c*v*zfh*zvqmac \
    rv64imf-lp64f--d*v*zfh*zvqmac \
    rv64imaf-lp64f-rv64imafd-v*zfh*zvqmac \
    rv64imfc-lp64f--d*v*zfh*zvqmac \
    rv64imafc-lp64f-rv64imafdc-v*zfh*zvqmac \
    rv64ifd-lp64d--c*v*zfh*zvqmac \
    rv64imfd-lp64d--c*v*zfh*zvqmac \
    rv64iafd-lp64d-rv64imafd,rv64iafdc-v*zfh*zvqmac \
    rv64imafdc-lp64d--v*zfh*zvqmac
    "}

    GCC_MULTILIB_FILE=${GCC_MULTILIB_FILE:-"t-elf-multilib"}

    # -------------------------------------------------------------------------


    if [ "${USE_GITS}" != "y" ]
    then

      # Be sure there is no `v`, it is added in the URL.
      GH_RELEASE="8.3.0-2.1"
      if [[ "${RELEASE_VERSION}" =~ 8\.3\.0-2\.[1] ]]
      then
        BINUTILS_GH_RELEASE=${BINUTILS_GH_RELEASE:-"${GH_RELEASE}"}
      else # [234]
        BINUTILS_GH_RELEASE=${BINUTILS_GH_RELEASE:-"8.3.0-2.2"}
      fi
      GCC_GH_RELEASE=${GCC_GH_RELEASE:-"${GH_RELEASE}"}
      NEWLIB_GH_RELEASE=${NEWLIB_GH_RELEASE:-"${GH_RELEASE}"}
      # Same, with a `-gdb` suffix added.
      GDB_GH_RELEASE=${GDB_GH_RELEASE:-"${GH_RELEASE}-gdb"}

    else

      BINUTILS_GIT_BRANCH=${BINUTILS_GIT_BRANCH:-"sifive-binutils-2.32-cache-control-patch-xpack"}
      if [[ "${RELEASE_VERSION}" =~ 8\.3\.0-2\.[1] ]]
      then
        BINUTILS_GIT_COMMIT=${BINUTILS_GIT_COMMIT:-"d005a513ac8469bf23a1a7655a6d372a7f470dd3"}
      else # [234]
        BINUTILS_GIT_COMMIT=${BINUTILS_GIT_COMMIT:-"c46d3912cd901db4bdc331bd394aa97d85ac1746"}
      fi

      GCC_GIT_BRANCH=${GCC_GIT_BRANCH:-"sifive-gcc-8.3.0-xpack"}
      GCC_GIT_COMMIT=${GCC_GIT_COMMIT:-"e195042babe2dc30d9fabb88d336d8c8679b3702"}

      NEWLIB_GIT_BRANCH=${NEWLIB_GIT_BRANCH:-"fix-S5CSD-1486-xpack"}
      NEWLIB_GIT_COMMIT=${NEWLIB_GIT_COMMIT:-"dd7f1b85e9bb29a97d9357a617b6ff29a7d2f19a"}

      GDB_SRC_FOLDER_NAME=${GDB_SRC_FOLDER_NAME:-"binutils-gdb.git"}
      GDB_GIT_BRANCH=${GDB_GIT_BRANCH:-"gdb-8.3-release-cache-control-patch-xpack"}
      GDB_GIT_COMMIT=${GDB_GIT_COMMIT:-"ee1f38cc20612d5a570cab0e818ee40fc31b148a"}

    fi
    
    # -------------------------------------------------------------------------

    WITH_GDB_PY3="y" 
    PYTHON3_VERSION="3.7.9"

    BINUTILS_PATCH="binutils-gdb-${BINUTILS_VERSION}.patch"
    GDB_PATCH="binutils-gdb-${BINUTILS_VERSION}.patch"

    prepare_variables

    # ---------------------------------------------------------------------------
    # Build dependent libraries.

    # For better control, without it some components pick the lib packed 
    # inside the archive.
    build_zlib "1.2.8"

    # The classical GCC libraries.
    build_gmp "6.1.2"
    build_mpfr "3.1.6"
    build_mpc "1.0.3"
    build_isl "0.18"

    # More libraries.
    # Fails on mingw
    ## build_libelf "0.8.13"
    build_libmpdec "2.5.0" # Used by Python
    build_expat "2.2.5"
    build_libiconv "1.15"
    build_xz "5.2.3"

    build_gettext "0.19.8.1"

    if [ "${TARGET_PLATFORM}" == "win32" ]
    then
      if [ "${WITH_GDB_PY3}" == "y" ]
      then
        if [[ "${RELEASE_VERSION}" =~ 8\.3\.0-2\.[12] ]]
        then
          :
        else # [34]
          # Shortcut, use the existing pyton.exe instead of building
          # if from sources. It also downloads the sources.
          download_python3_win "${PYTHON3_VERSION}"

          add_python3_win_syslibs
        fi
      fi
    else # linux or darwin
      # Used by ncurses. Fails on macOS.
      if [ "${TARGET_PLATFORM}" == "linux" ]
      then
        build_gpm "1.20.7"
      fi

      build_ncurses "6.2"

      if [[ "${RELEASE_VERSION}" =~ 8\.3\.0-2\.[12] ]]
      then
        : 
      else # [34]
        build_readline "8.0" # requires ncurses

        build_bzip2 "1.0.8"
        build_libffi "3.3"


        # We cannot rely on a python shared library in the system, even
        # the custom build from sources does not have one.

        if [ "${WITH_GDB_PY3}" == "y" ]
        then
          # Required by a Python 3 module.
          build_sqlite "3.32.3"

          # Replacement for the old libcrypt.so.1; required by Python 3.
          build_libxcrypt "4.4.17"
          build_openssl "1.1.1h"

          build_python3 "${PYTHON3_VERSION}"

          if [[ "${RELEASE_VERSION}" =~ 8\.3\.0-2\.[12] ]]
          then
            :
          else # [34]
            add_python3_syslibs
          fi
        fi
      fi
    fi

    # ---------------------------------------------------------------------------

    # The task descriptions are from the ARM build script.

    # Task [III-0] /$HOST_NATIVE/binutils/
    # Task [IV-1] /$HOST_MINGW/binutils/
    build_binutils "${BINUTILS_VERSION}"
    # copy_dir to libs included above

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then

      # Task [III-1] /$HOST_NATIVE/gcc-first/
      build_gcc_first

      # Task [III-2] /$HOST_NATIVE/newlib/
      build_newlib ""
      # Task [III-3] /$HOST_NATIVE/newlib-nano/
      build_newlib "-nano"

      # Task [III-4] /$HOST_NATIVE/gcc-final/
      build_gcc_final ""

      # Task [III-5] /$HOST_NATIVE/gcc-size-libstdcxx/
      build_gcc_final "-nano"

    else

      # Task [IV-2] /$HOST_MINGW/copy_libs/
      copy_linux_libs

      # Task [IV-3] /$HOST_MINGW/gcc-final/
      build_gcc_final ""

    fi

    # Task [III-6] /$HOST_NATIVE/gdb/
    # Task [IV-4] /$HOST_MINGW/gdb/
    build_gdb ""

    if [ "${WITH_GDB_PY3}" == "y" ]
    then
      build_gdb "-py3"
    fi

    # Task [III-7] /$HOST_NATIVE/build-manual
    # Nope, the build process is different.

    # ---------------------------------------------------------------------------

    # Task [III-8] /$HOST_NATIVE/pretidy/
    # Task [IV-5] /$HOST_MINGW/pretidy/
    tidy_up

    # Task [III-9] /$HOST_NATIVE/strip_host_objects/
    # Task [IV-6] /$HOST_MINGW/strip_host_objects/
    strip_binaries

    # Must be done after gcc 2 make install, otherwise some wrong links
    # are created in libexec.
    # Must also be done after strip binaries, since strip after patchelf
    # damages the binaries.
    prepare_app_folder_libraries

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
  elif [[ "${RELEASE_VERSION}" =~ 8\.3\.0-1\.* ]]
  then
    # This is similar to SiFive 2019.08.0 release.
    # https://github.com/sifive/freedom-tools/releases

    # Binutils 2.32 with SiFive CLIC patches
    # https://github.com/sifive/riscv-binutils-gdb/tree/03d23d58701bdd425c613b0be2d458bcde46912b

    # GCC 8.3.0 with SiFive CLIC patches
    # https://github.com/sifive/riscv-gcc/tree/e195042babe2dc30d9fabb88d336d8c8679b3702

    # Newlib 3.1.0 from SiFive branch
    # https://github.com/sifive/riscv-newlib/tree/0d24a86822a5ee73d6a6aa69e2a0118aa1e35204

    # GDB 8.3 from FSF gdb-8.3-release branch
    # riscv-gdb @ 9b40759 (11 May 2019)
    # https://sourceware.org/git/?p=binutils-gdb.git
    # git://sourceware.org/git/binutils-gdb.git


    # -------------------------------------------------------------------------

    # Inspired from SiFive
    # MULTILIBS_GEN :=            rv32e-ilp32e--c rv32em-ilp32e--c rv32eac-ilp32e-- rv32emac-ilp32e-- rv32i-ilp32--c rv32im-ilp32--c rv32imf-ilp32f--c rv32iac-ilp32-- rv32imac-ilp32-- rv32imafc-ilp32f-rv32imafdc- rv32imafdc-ilp32d-- rv64i-lp64--c rv64im-lp64--c rv64imf-lp64f--c rv64iac-lp64-- rv64imac-lp64-- rv64imafc-lp64f-rv64imafdc- rv64imafdc-lp64d--

    # Minimal list, for tests only. Pass it via the environment.
    # GCC_MULTILIB=${GCC_MULTILIB:-"rv32imac-ilp32-- rv64imac-lp64--"}

    # New extended list, based on SiFive list.
    # Added: rv32imaf-ilp32f--
    GCC_MULTILIB=${GCC_MULTILIB:-"\
    rv32e-ilp32e--c \
    rv32ea-ilp32e--m \
    rv32em-ilp32e--c \
    rv32eac-ilp32e-- \
    rv32emac-ilp32e-- \
    rv32i-ilp32--c \
    rv32ia-ilp32--m \
    rv32im-ilp32--c \
    rv32if-ilp32f-rv32ifd-c \
    rv32iaf-ilp32f-rv32imaf,rv32iafc-d \
    rv32imf-ilp32f-rv32imfd-c \
    rv32imaf-ilp32f-- \
    rv32iac-ilp32-- \
    rv32imac-ilp32-- \
    rv32imafc-ilp32f-rv32imafdc- \
    rv32ifd-ilp32d--c \
    rv32imfd-ilp32d--c \
    rv32iafd-ilp32d-rv32imafd,rv32iafdc- \
    rv32imafdc-ilp32d-- \
    rv64i-lp64--c \
    rv64ia-lp64--m \
    rv64im-lp64--c \
    rv64if-lp64f-rv64ifd-c \
    rv64iaf-lp64f-rv64iafc-d \
    rv64imf-lp64f-rv64imfd-c \
    rv64imaf-lp64f-- \
    rv64iac-lp64-- \
    rv64imac-lp64-- \
    rv64imafc-lp64f-rv64imafdc- \
    rv64ifd-lp64d--m,c \
    rv64iafd-lp64d-rv64imafd,rv64iafdc- \
    rv64imafdc-lp64d-- \
    "}

    GCC_MULTILIB_FILE=${GCC_MULTILIB_FILE:-"t-elf-multilib"}

    # -------------------------------------------------------------------------

    BINUTILS_VERSION="2.32"
    # From gcc/BASE_VER
    GCC_VERSION="8.3.0"
    # From newlib/configure, VERSION=
    NEWLIB_VERSION="3.1.0"
    # From gdb/VERSION.in
    GDB_VERSION="8.3"

    README_OUT_FILE_NAME="README-${RELEASE_VERSION}.md"

    # -------------------------------------------------------------------------

    if [ "${USE_GITS}" != "y" ]
    then

      # Be sure there is no `v`, it is added in the URL.
      GH_RELEASE="8.3.0-1.1"
      BINUTILS_GH_RELEASE=${BINUTILS_GH_RELEASE:-"${GH_RELEASE}"}
      GCC_GH_RELEASE=${GCC_GH_RELEASE:-"${GH_RELEASE}"}
      NEWLIB_GH_RELEASE=${NEWLIB_GH_RELEASE:-"${GH_RELEASE}"}
      # Same, with a `-gdb` suffix added.
      GDB_GH_RELEASE=${GDB_GH_RELEASE:-"${GH_RELEASE}-gdb"}

    else

      BINUTILS_GIT_BRANCH=${BINUTILS_GIT_BRANCH:-"sifive-binutils-2.32-xpack"}
      # 16 April 2019
      BINUTILS_GIT_COMMIT=${BINUTILS_GIT_COMMIT:-"03d23d58701bdd425c613b0be2d458bcde46912b"}

      GCC_GIT_BRANCH=${GCC_GIT_BRANCH:-"sifive-gcc-8.3.0-xpack"}
      GCC_GIT_COMMIT=${GCC_GIT_COMMIT:-"e195042babe2dc30d9fabb88d336d8c8679b3702"}

      NEWLIB_GIT_BRANCH=${NEWLIB_GIT_BRANCH:-"sifive-master-xpack"}
      NEWLIB_GIT_COMMIT=${NEWLIB_GIT_COMMIT:-"0d24a86822a5ee73d6a6aa69e2a0118aa1e35204"}

      GDB_SRC_FOLDER_NAME=${GDB_SRC_FOLDER_NAME:-"binutils-gdb.git"}
      GDB_GIT_BRANCH=${GDB_GIT_BRANCH:-"sifive-gdb-8.3-xpack"}
      GDB_GIT_COMMIT=${GDB_GIT_COMMIT:-"9b8cecd18313807ac0cc4d2b1871603279b94244"}

    fi
    
    # -------------------------------------------------------------------------

    ZLIB_VERSION="1.2.8"
    GMP_VERSION="6.1.2"
    MPFR_VERSION="3.1.6"
    MPC_VERSION="1.0.3"
    ISL_VERSION="0.18"
    LIBELF_VERSION="0.8.13"
    EXPAT_VERSION="2.2.5"
    LIBICONV_VERSION="1.15"
    XZ_VERSION="5.2.3"

    # -------------------------------------------------------------------------

    if [ "${RELEASE_VERSION}" == "8.3.0-1.2" ]
    then

      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        # On Windows if fails with 
        # "The procedure entry point ClearCommBreak could not be located
        # in the dynamic link library." 
        # It looks like an incompatibility between Python2 and mingw-w64.
        # Given that Python2 is end-of-life, it is not worth to further
        # investigate, disable it for now.
        WITH_GDB_PY2=""
      elif [ "${TARGET_PLATFORM}" == "darwin" ]
      then
        # ImportError: dlopen(/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/lib-dynload/operator.so, 2): Symbol not found: __PyUnicodeUCS2_AsDefaultEncodedString
        #  Referenced from: /Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/lib-dynload/operator.so
        #  Expected in: flat namespace
        # in /Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/lib-dynload/operator.so
        WITH_GDB_PY2=""
      else
        WITH_GDB_PY2="y"
      fi

      PYTHON2_VERSION="2.7.18"

      WITH_GDB_PY3="y" 
      PYTHON3_VERSION="3.7.6"

    elif [ "${RELEASE_VERSION}" == "8.3.0-1.1" ]
    then

      PYTHON2_VERSION="2.7.13"

      if [ "${TARGET_PLATFORM}" == "darwin" ]
      then
        USE_PLATFORM_PYTHON2="y"
      fi

      WITH_GDB_PY2="y"

    else
      echo "Unsupported version ${RELEASE_VERSION}."
      exit 1
    fi

    BINUTILS_PATCH="binutils-gdb-${BINUTILS_VERSION}.patch"
    GDB_PATCH="binutils-gdb-${BINUTILS_VERSION}.patch"

    prepare_variables

    # ---------------------------------------------------------------------------
    # Build dependent libraries.

    # For better control, without it some components pick the lib packed 
    # inside the archive.
    build_zlib "${ZLIB_VERSION}"

    # The classical GCC libraries.
    build_gmp "${GMP_VERSION}"
    build_mpfr "${MPFR_VERSION}"
    build_mpc "${MPC_VERSION}"
    build_isl "${ISL_VERSION}"

    # More libraries.
    # Fails on mingw
    ## do_libelf
    build_expat "${EXPAT_VERSION}"
    build_libiconv "${LIBICONV_VERSION}"
    build_xz "${XZ_VERSION}"

    build_gettext "0.19.8.1"

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then
      # Used by ncurses. Fails on macOS.
      if [ "${TARGET_PLATFORM}" == "linux" ]
      then
        build_gpm "1.20.7"
      fi

      build_ncurses "6.2"
      build_readline "8.0" # requires ncurses
    fi

    # ---------------------------------------------------------------------------

    # The task descriptions are from the ARM build script.

    # Task [III-0] /$HOST_NATIVE/binutils/
    # Task [IV-1] /$HOST_MINGW/binutils/
    build_binutils "${BINUTILS_VERSION}"
    # copy_dir to libs included above

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then

      # Task [III-1] /$HOST_NATIVE/gcc-first/
      build_gcc_first

      # Task [III-2] /$HOST_NATIVE/newlib/
      build_newlib ""
      # Task [III-3] /$HOST_NATIVE/newlib-nano/
      build_newlib "-nano"

      # Task [III-4] /$HOST_NATIVE/gcc-final/
      build_gcc_final ""

      # Task [III-5] /$HOST_NATIVE/gcc-size-libstdcxx/
      build_gcc_final "-nano"

    else

      # Task [IV-2] /$HOST_MINGW/copy_libs/
      copy_linux_libs

      # Task [IV-3] /$HOST_MINGW/gcc-final/
      build_gcc_final ""

    fi

    # Task [III-6] /$HOST_NATIVE/gdb/
    # Task [IV-4] /$HOST_MINGW/gdb/
    build_gdb ""

    if [ "${WITH_GDB_PY2}" == "y" ]
    then
      # The Windows GDB needs some headers from the Python distribution.
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        download_python2_win "${PYTHON2_VERSION}"
      fi

      build_gdb "-py"
    fi

    if [ "${WITH_GDB_PY3}" == "y" ]
    then
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        download_python3_win "${PYTHON3_VERSION}"
      fi

      build_gdb "-py3"
    fi

    # Task [III-7] /$HOST_NATIVE/build-manual
    # Nope, the build process is different.

    # ---------------------------------------------------------------------------

    # Task [III-8] /$HOST_NATIVE/pretidy/
    # Task [IV-5] /$HOST_MINGW/pretidy/
    tidy_up

    # Task [III-9] /$HOST_NATIVE/strip_host_objects/
    # Task [IV-6] /$HOST_MINGW/strip_host_objects/
    strip_binaries

    # Must be done after gcc 2 make install, otherwise some wrong links
    # are created in libexec.
    # Must also be done after strip binaries, since strip after patchelf
    # damages the binaries.
    prepare_app_folder_libraries

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
  elif [[ "${RELEASE_VERSION}" =~ 8\.2\.0-3\.* ]]
  then
    # This is similar to SiFive 2019.05.0 release.
    # https://github.com/sifive/freedom-tools/releases

    # Binutils 2.32 with SiFive CLIC patches
    # https://github.com/sifive/riscv-binutils-gdb/tree/164267155c96f91472a539ca78ac919993bc5b4e

    # GCC 8.2.0 with SiFive CLIC patches
    # https://github.com/sifive/riscv-gcc/tree/242abcaff697d0a1ea12dccc975465e1bfeb8331

    # GDB 8.3 from FSF gdb-8.3-release branch
    # riscv-gdb @ 9b40759 (11 May 2019)
    # https://sourceware.org/git/?p=binutils-gdb.git
    # git://sourceware.org/git/binutils-gdb.git

    # Newlib 3.0.0 from SiFive branch
    # https://github.com/sifive/riscv-newlib/tree/42c2e3fb9f557d59b76d1a64bb6fb32707ff4530

    # -------------------------------------------------------------------------

    # Inspired from SiFive
    # MULTILIBS_GEN :=            rv32e-ilp32e--c rv32em-ilp32e--c rv32eac-ilp32e-- rv32emac-ilp32e-- rv32i-ilp32--c rv32im-ilp32--c rv32imf-ilp32f--c rv32iac-ilp32-- rv32imac-ilp32-- rv32imafc-ilp32f-rv32imafdc- rv32imafdc-ilp32d-- rv64i-lp64--c rv64im-lp64--c rv64imf-lp64f--c rv64iac-lp64-- rv64imac-lp64-- rv64imafc-lp64f-rv64imafdc- rv64imafdc-lp64d--

    # Minimal list, for tests only. Pass it via the environment.
    # GCC_MULTILIB=${GCC_MULTILIB:-"rv32imac-ilp32-- rv64imac-lp64--"}

    # New extended list, based on SiFive list.
    # Added: rv32imaf-ilp32f--
    GCC_MULTILIB=${GCC_MULTILIB:-"rv32e-ilp32e--c rv32em-ilp32e--c rv32eac-ilp32e-- rv32emac-ilp32e-- rv32i-ilp32--c rv32im-ilp32--c rv32imf-ilp32f--c rv32imaf-ilp32f-- rv32iac-ilp32-- rv32imac-ilp32-- rv32imafc-ilp32f-rv32imafdc- rv32imafdc-ilp32d-- rv64i-lp64--c rv64im-lp64--c rv64imf-lp64f--c rv64iac-lp64-- rv64imac-lp64-- rv64imafc-lp64f-rv64imafdc- rv64imafdc-lp64d--"}

    GCC_MULTILIB_FILE=${GCC_MULTILIB_FILE:-"t-elf-multilib"}

    # -------------------------------------------------------------------------

    BINUTILS_VERSION="2.32"
    # From gcc/BASE_VER
    GCC_VERSION="8.2.0"
    # From newlib/configure, VERSION=
    NEWLIB_VERSION="3.0.0"
    # From gdb/VERSION.in
    GDB_VERSION="8.3"

    README_OUT_FILE_NAME="README-${RELEASE_VERSION}.md"

    # -------------------------------------------------------------------------

    if [ "${USE_GITS}" != "y" ]
    then

      # Be sure there is no `v`, it is added in the URL.
      GH_RELEASE="8.2.0-3.1"
      BINUTILS_GH_RELEASE=${BINUTILS_GH_RELEASE:-"${GH_RELEASE}"}
      GCC_GH_RELEASE=${GCC_GH_RELEASE:-"${GH_RELEASE}"}
      NEWLIB_GH_RELEASE=${NEWLIB_GH_RELEASE:-"${GH_RELEASE}"}
      # Same, with a `-gdb` suffix added.
      GDB_GH_RELEASE=${GDB_GH_RELEASE:-"${GH_RELEASE}-gdb"}

    else

      BINUTILS_GIT_BRANCH=${BINUTILS_GIT_BRANCH:-"sifive-binutils-2.32-xpack"}
      # 16 April 2019
      BINUTILS_GIT_COMMIT=${BINUTILS_GIT_COMMIT:-"82b51c7b5087ddb77988287cd7a2dd8921331bfd"}

      GCC_GIT_BRANCH=${GCC_GIT_BRANCH:-"sifive-gcc-8.2.0-xpack"}
      GCC_GIT_COMMIT=${GCC_GIT_COMMIT:-"0c7a874f0b6f452eeafde57731646e5f460187e4"}

      NEWLIB_GIT_BRANCH=${NEWLIB_GIT_BRANCH:-"sifive-newlib-3.0.0-xpack"}
      NEWLIB_GIT_COMMIT=${NEWLIB_GIT_COMMIT:-"1975c561730cbd4b93c491eaadeb6c3b01a89447"}

      GDB_SRC_FOLDER_NAME=${GDB_SRC_FOLDER_NAME:-"binutils-gdb.git"}
      GDB_GIT_BRANCH=${GDB_GIT_BRANCH:-"sifive-gdb-8.3-xpack"}
      GDB_GIT_COMMIT=${GDB_GIT_COMMIT:-"9b8cecd18313807ac0cc4d2b1871603279b94244"}

    fi
    
    # -------------------------------------------------------------------------

    # LIBELF_VERSION="0.8.13"

    WITH_GDB_PY2="y"
    PYTHON2_VERSION="2.7.13"

    BINUTILS_PATCH="binutils-gdb-${BINUTILS_VERSION}.patch"
    GDB_PATCH="binutils-gdb-${BINUTILS_VERSION}.patch"

    prepare_variables

    # ---------------------------------------------------------------------------
    # Build dependent libraries.

    # For better control, without it some components pick the lib packed 
    # inside the archive.
    build_zlib "1.2.8"

    # The classical GCC libraries.
    build_gmp "6.1.2"
    build_mpfr "3.1.6"
    build_mpc "1.0.3"
    build_isl "0.18"

    # More libraries.
    # Fails on mingw
    ## do_libelf
    build_expat "2.2.5"
    build_libiconv "1.15"
    build_xz "5.2.3"

    build_gettext "0.19.8.1"

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then
      # Used by ncurses. Fails on macOS.
      if [ "${TARGET_PLATFORM}" == "linux" ]
      then
        build_gpm "1.20.7"
      fi
    fi

    # ---------------------------------------------------------------------------

    # The task descriptions are from the ARM build script.

    # Task [III-0] /$HOST_NATIVE/binutils/
    # Task [IV-1] /$HOST_MINGW/binutils/
    build_binutils "${BINUTILS_VERSION}"
    # copy_dir to libs included above

    if [ "${TARGET_PLATFORM}" != "win32" ]
    then

      # Task [III-1] /$HOST_NATIVE/gcc-first/
      build_gcc_first

      # Task [III-2] /$HOST_NATIVE/newlib/
      build_newlib ""
      # Task [III-3] /$HOST_NATIVE/newlib-nano/
      build_newlib "-nano"

      # Task [III-4] /$HOST_NATIVE/gcc-final/
      build_gcc_final ""

      # Task [III-5] /$HOST_NATIVE/gcc-size-libstdcxx/
      build_gcc_final "-nano"

    else

      # Task [IV-2] /$HOST_MINGW/copy_libs/
      copy_linux_libs

      # Task [IV-3] /$HOST_MINGW/gcc-final/
      build_gcc_final ""

    fi

    # Task [III-6] /$HOST_NATIVE/gdb/
    # Task [IV-4] /$HOST_MINGW/gdb/
    build_gdb ""

    if [ "${WITH_GDB_PY2}" == "y" ]
    then
      # The Windows GDB needs some headers from the Python distribution.
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        download_python2_win "${PYTHON2_VERSION}"
      fi

      build_gdb "-py"
    fi

    if [ "${WITH_GDB_PY3}" == "y" ]
    then
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        download_python3_win "${PYTHON3_VERSION}"
      fi

      build_gdb "-py3"
    fi

    # Task [III-7] /$HOST_NATIVE/build-manual
    # Nope, the build process is different.

    # ---------------------------------------------------------------------------

    # Task [III-8] /$HOST_NATIVE/pretidy/
    # Task [IV-5] /$HOST_MINGW/pretidy/
    tidy_up

    # Task [III-9] /$HOST_NATIVE/strip_host_objects/
    # Task [IV-6] /$HOST_MINGW/strip_host_objects/
    if [ "${WITH_STRIP}" == "y" ]
    then
      strip_binaries
    fi

    # Must be done after gcc 2 make install, otherwise some wrong links
    # are created in libexec.
    # Must also be done after strip binaries, since strip after patchelf
    # damages the binaries.
    prepare_app_folder_libraries

    if [ "${WITH_STRIP}" == "y" -a "${TARGET_PLATFORM}" != "win32" ]
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
