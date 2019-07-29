# -----------------------------------------------------------------------------
# This file is part of the xPacks distribution.
#   (https://xpack.github.io)
# Copyright (c) 2019 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software 
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# Helper script used in the second edition of the xPack build 
# scripts. As the name implies, it should contain only functions and 
# should be included with 'source' by the container build scripts.

# -----------------------------------------------------------------------------


function do_zlib() 
{
  # http://zlib.net
  # http://zlib.net/fossils/
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=zlib-static
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=zlib-git
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=mingw-w64-zlib

  # 2013-04-28
  # ZLIB_VERSION="1.2.8"
  # 2017-01-15
  # ZLIB_VERSION="1.2.11"

  ZLIB_SRC_FOLDER_NAME="zlib-${ZLIB_VERSION}"
  ZLIB_FOLDER_NAME="${ZLIB_SRC_FOLDER_NAME}"
  local zlib_archive="${ZLIB_SRC_FOLDER_NAME}.tar.gz"
  local zlib_url="http://zlib.net/fossils/${zlib_archive}"

  local zlib_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-zlib-${ZLIB_VERSION}-installed"
  if [ ! -f "${zlib_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${zlib_url}" "${zlib_archive}" "${ZLIB_SRC_FOLDER_NAME}"

    (
      if [ ! -d "${LIBS_BUILD_FOLDER_PATH}/${ZLIB_FOLDER_NAME}" ]
      then
        mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${ZLIB_FOLDER_NAME}"
        # Copy the sources in the build folder.
        cp -r "${SOURCES_FOLDER_PATH}/${ZLIB_SRC_FOLDER_NAME}"/* "${LIBS_BUILD_FOLDER_PATH}/${ZLIB_FOLDER_NAME}"
      fi
      cd "${LIBS_BUILD_FOLDER_PATH}/${ZLIB_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      # export LDFLAGS="${XBB_LDFLAGS_LIB}"
      if [ "${TARGET_PLATFORM}" != "win32" ]
      then

        export CFLAGS="${XBB_CFLAGS} -Wno-shift-negative-value"

        # No config.status left, use the library.
        if [ ! -f "libz.a" ]
        then
          (
            echo
            echo "Running zlib configure..."

            # In-source build.
            bash "./configure" --help

            bash ${DEBUG} "./configure" \
              --prefix="${LIBS_INSTALL_FOLDER_PATH}"

            cp "configure.log" "${LOGS_FOLDER_PATH}/configure-zlib-log.txt"
          ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-zlib-output.txt"
        fi

        (
          echo
          echo "Running zlib make..."

          make -j ${JOBS}
          make install
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-zlib-output.txt"
      else
        (
          echo
          echo "Running zlib make..."

          make -f win32/Makefile.gcc \
            PREFIX=${CROSS_COMPILE_PREFIX}- \
            prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            CFLAGS="${XBB_CFLAGS} -Wp,-D_FORTIFY_SOURCE=2 -fexceptions --param=ssp-buffer-size=4"
          make -f win32/Makefile.gcc install \
            DESTDIR="${LIBS_INSTALL_FOLDER_PATH}/" \
            INCLUDE_PATH="include" \
            LIBRARY_PATH="lib" \
            BINARY_PATH="bin"

        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-zlib-output.txt"
      fi
    )

    touch "${zlib_stamp_file_path}"

  else
    echo "Library zlib already installed."
  fi
}

function do_gmp() 
{
  # https://gmplib.org
  # https://gmplib.org/download/gmp/
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=gmp-hg

  # 01-Nov-2015
  # GMP_VERSION="6.1.0"
  # 16-Dec-2016
  # GMP_VERSION="6.1.2"

  GMP_SRC_FOLDER_NAME="gmp-${GMP_VERSION}"
  GMP_FOLDER_NAME="${GMP_SRC_FOLDER_NAME}"
  local gmp_archive="${GMP_SRC_FOLDER_NAME}.tar.xz"
  local gmp_url="https://gmplib.org/download/gmp/${gmp_archive}"

  local gmp_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-gmp-${GMP_VERSION}-installed"
  if [ ! -f "${gmp_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${gmp_url}" "${gmp_archive}" "${GMP_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${GMP_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${GMP_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      export CFLAGS="-Wno-unused-value -Wno-empty-translation-unit -Wno-tautological-compare -Wno-overflow"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      # ABI is mandatory, otherwise configure fails on 32-bit.
      # (see https://gmplib.org/manual/ABI-and-ISA.html)
      export ABI="${TARGET_BITS}"
        
      if [ ! -f "config.status" ]
      then 

        (
          echo
          echo "Running gmp configure..."

          bash "${SOURCES_FOLDER_PATH}/${GMP_SRC_FOLDER_NAME}/configure" --help

          # On Windows mpfr wants it shared.
          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${GMP_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \
            \
            --enable-cxx \
            --enable-shared \
            --disable-static

          cp "config.log" "${LOGS_FOLDER_PATH}/config-gmp-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-gmp-output.txt"

      fi

      (
        echo
        echo "Running gmp make..."

        # Build.
        # make -j ${JOBS}
        make
        make install-strip
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-gmp-output.txt"
    )

    touch "${gmp_stamp_file_path}"

  else
    echo "Library gmp already installed."
  fi
}

function do_mpfr()
{
  # http://www.mpfr.org
  # http://www.mpfr.org/history.html
  # https://git.archlinux.org/svntogit/packages.git/tree/trunk/PKGBUILD?h=packages/mpfr

  # 6 March 2016
  # MPFR_VERSION="3.1.4"
  # 7 September 2017
  # MPFR_VERSION="3.1.6"

  MPFR_SRC_FOLDER_NAME="mpfr-${MPFR_VERSION}"
  MPFR_FOLDER_NAME="${MPFR_SRC_FOLDER_NAME}"
  local mpfr_archive="${MPFR_SRC_FOLDER_NAME}.tar.xz"
  local mpfr_url="http://www.mpfr.org/${MPFR_SRC_FOLDER_NAME}/${mpfr_archive}"

  local mpfr_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-mpfr-${MPFR_VERSION}-installed"
  if [ ! -f "${mpfr_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${mpfr_url}" "${mpfr_archive}" "${MPFR_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${MPFR_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${MPFR_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      export CFLAGS="${XBB_CFLAGS}"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      if [ ! -f "config.status" ]
      then 
        (
          echo
          echo "Running mpfr configure..."

          bash "${SOURCES_FOLDER_PATH}/${MPFR_SRC_FOLDER_NAME}/configure" --help

          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${MPFR_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \
            \
            --disable-warnings

          cp "config.log" "${LOGS_FOLDER_PATH}/config-mpfr-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-mpfr-output.txt"
      fi

      (
        echo
        echo "Running mpfr make..."

        # Build.
        # Parallel builds fail.
        # make -j ${JOBS}
        make 
        make install-strip
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-mpfr-output.txt"
    )
    touch "${mpfr_stamp_file_path}"

  else
    echo "Library mpfr already installed."
  fi
}

function do_mpc()
{
  # http://www.multiprecision.org/
  # ftp://ftp.gnu.org/gnu/mpc
  # https://git.archlinux.org/svntogit/packages.git/tree/trunk/PKGBUILD?h=packages/libmpc

  # 20 Feb 2015
  # MPC_VERSION="1.0.3"

  MPC_SRC_FOLDER_NAME="mpc-${MPC_VERSION}"
  MPC_FOLDER_NAME="${MPC_SRC_FOLDER_NAME}"
  local mpc_archive="${MPC_SRC_FOLDER_NAME}.tar.gz"

  local mpc_url="ftp://ftp.gnu.org/gnu/mpc/${mpc_archive}"
  if [[ "${MPC_VERSION}" =~ 0\.* ]]
  then
    mpc_url="http://www.multiprecision.org/downloads/${mpc_archive}"
  fi

  local mpc_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-mpc-${MPC_VERSION}-installed"
  if [ ! -f "${mpc_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${mpc_url}" "${mpc_archive}" "${MPC_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${MPC_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${MPC_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      export CFLAGS="${XBB_CFLAGS} -Wno-unused-value -Wno-empty-translation-unit -Wno-tautological-compare"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      if [ ! -f "config.status" ]
      then 

        (
          echo
          echo "Running mpc configure..."
        
          bash "${SOURCES_FOLDER_PATH}/${MPC_SRC_FOLDER_NAME}/configure" --help

          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${MPC_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \

          cp "config.log" "${LOGS_FOLDER_PATH}/config-mpc-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-mpc-output.txt"

      fi

      (
        echo
        echo "Running mpc make..."

        # Build.
        make -j ${JOBS}
        make install-strip
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-mpc-output.txt"
    )
    touch "${mpc_stamp_file_path}"

  else
    echo "Library mpc already installed."
  fi
}

function do_isl()
{
  # http://isl.gforge.inria.fr
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=isl

  # 2015-06-12
  # ISL_VERSION="0.15"
  # 2016-01-15
  # ISL_VERSION="0.16.1"
  # 2016-12-20
  # ISL_VERSION="0.18"

  ISL_SRC_FOLDER_NAME="isl-${ISL_VERSION}"
  ISL_FOLDER_NAME="${ISL_SRC_FOLDER_NAME}"
  local isl_archive="${ISL_SRC_FOLDER_NAME}.tar.xz"
  if [[ "${ISL_VERSION}" =~ 0\.12\.* ]]
  then
    isl_archive="${ISL_SRC_FOLDER_NAME}.tar.gz"
  fi

  local isl_url="http://isl.gforge.inria.fr/${isl_archive}"

  local isl_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-isl-${ISL_VERSION}-installed"
  if [ ! -f "${isl_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${isl_url}" "${isl_archive}" "${ISL_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${ISL_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${ISL_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      export CFLAGS="${XBB_CFLAGS} -Wno-dangling-else -Wno-header-guard"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      if [ ! -f "config.status" ]
      then 

        (
          echo
          echo "Running isl configure..."

          bash "${SOURCES_FOLDER_PATH}/${ISL_SRC_FOLDER_NAME}/configure" --help

          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${ISL_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \

          cp "config.log" "${LOGS_FOLDER_PATH}/config-isl-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-isl-output.txt"

      fi

      (
        echo
        echo "Running isl make..."

        # Build.
        # make -j ${JOBS}
        make
        make install-strip
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-isl-output.txt"

    )
    touch "${isl_stamp_file_path}"

  else
    echo "Library isl already installed."
  fi
}

function do_libelf()
{
  # http://www.mr511.de/
  # http://www.mr511.de/software/

  # LIBELF_VERSION="0.8.13"

  LIBELF_SRC_FOLDER_NAME="libelf-${LIBELF_VERSION}"
  LIBELF_FOLDER_NAME="${LIBELF_SRC_FOLDER_NAME}"
  local libelf_archive="${LIBELF_SRC_FOLDER_NAME}.tar.gz"

  # local libelf_url="http://www.mr511.de/software/${libelf_archive}"
  # The original site seems unavailable, use a mirror.
  local libelf_url="https://fossies.org/linux/misc/old/${libelf_archive}"

  local libelf_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-libelf-${LIBELF_VERSION}-installed"
  if [ ! -f "${libelf_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${libelf_url}" "${libelf_archive}" "${LIBELF_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${LIBELF_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${LIBELF_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      export CFLAGS="${XBB_CFLAGS} -Wno-tautological-compare"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      if [ ! -f "config.status" ]
      then 

        (
          echo
          echo "Running libelf configure..."

          bash "${SOURCES_FOLDER_PATH}/${LIBELF_SRC_FOLDER_NAME}/configure" --help

          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${LIBELF_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \
            \
            --disable-nls

          cp "config.log" "${LOGS_FOLDER_PATH}/config-libelf-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-libelf-output.txt"

      fi

      (
        echo
        echo "Running libelf make..."

        # Build.
        make -j ${JOBS}
        make install
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-libelf-output.txt"
    )

    touch "${libelf_stamp_file_path}"

  else
    echo "Library libelf already installed."
  fi
}

function do_expat()
{
  # https://libexpat.github.io
  # https://github.com/libexpat/libexpat/releases
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=expat-git

  # Oct 21, 2017
  # EXPAT_VERSION="2.1.1"
  # Nov 1, 2017
  # EXPAT_VERSION="2.2.5"

  EXPAT_SRC_FOLDER_NAME="expat-${EXPAT_VERSION}"
  EXPAT_FOLDER_NAME="${EXPAT_SRC_FOLDER_NAME}"
  local expat_archive="${EXPAT_SRC_FOLDER_NAME}.tar.bz2"
  if [[ "${EXPAT_VERSION}" =~ 2\.0\.* ]]
  then
    expat_archive="${EXPAT_SRC_FOLDER_NAME}.tar.gz"
  fi
  
  local expat_release="R_$(echo ${EXPAT_VERSION} | sed -e 's|[.]|_|g')"
  local expat_url="https://github.com/libexpat/libexpat/releases/download/${expat_release}/${expat_archive}"

  local expat_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-expat-${EXPAT_VERSION}-installed"
  if [ ! -f "${expat_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${expat_url}" "${expat_archive}" "${EXPAT_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${EXPAT_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${EXPAT_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      export CFLAGS="${XBB_CFLAGS}"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      if [ ! -f "config.status" ]
      then 

        (
          echo
          echo "Running expat configure..."

          bash "${SOURCES_FOLDER_PATH}/${EXPAT_SRC_FOLDER_NAME}/configure" --help

          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${EXPAT_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \

          cp "config.log" "${LOGS_FOLDER_PATH}/config-expat-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-expat-output.txt"

      fi

      (
        echo
        echo "Running expat make..."

        # Build.
        make -j ${JOBS}
        make install
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-expat-output.txt"

    )

    touch "${expat_stamp_file_path}"

  else
    echo "Library expat already installed."
  fi
}

function do_libiconv()
{
  # https://www.gnu.org/software/libiconv/
  # https://ftp.gnu.org/pub/gnu/libiconv/
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=libiconv

  # 2011-08-07
  # LIBICONV_VERSION="1.14"
  # 2017-02-02
  # LIBICONV_VERSION="1.15"

  LIBICONV_SRC_FOLDER_NAME="libiconv-${LIBICONV_VERSION}"
  LIBICONV_FOLDER_NAME="${LIBICONV_SRC_FOLDER_NAME}"
  local libiconv_archive="${LIBICONV_SRC_FOLDER_NAME}.tar.gz"
  local libiconv_url="https://ftp.gnu.org/pub/gnu/libiconv/${libiconv_archive}"

  local libiconv_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-libiconv-${LIBICONV_VERSION}-installed"
  if [ ! -f "${libiconv_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${libiconv_url}" "${libiconv_archive}" "${LIBICONV_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${LIBICONV_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${LIBICONV_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      # -fgnu89-inline fixes "undefined reference to `aliases2_lookup'"
      #  https://savannah.gnu.org/bugs/?47953
      export CFLAGS="${XBB_CFLAGS} -fgnu89-inline -Wno-tautological-compare -Wno-parentheses-equality -Wno-static-in-inline"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      if [ ! -f "config.status" ]
      then 

        (
          echo
          echo "Running libiconv configure..."

          bash "${SOURCES_FOLDER_PATH}/${LIBICONV_SRC_FOLDER_NAME}/configure" --help

          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${LIBICONV_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \
            \
            --disable-nls

          cp "config.log" "${LOGS_FOLDER_PATH}/config-libiconv-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-libiconv-output.txt"

      fi

      (
        echo
        echo "Running libiconv make..."

        # Build.
        make -j ${JOBS}
        make install-strip
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-libiconv-output.txt"
    )

    touch "${libiconv_stamp_file_path}"

  else
    echo "Library libiconv already installed."
  fi
}

function do_xz()
{
  # https://tukaani.org/xz/
  # https://sourceforge.net/projects/lzmautils/files/
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=xz-git

  # 2016-12-30
  # XZ_VERSION="5.2.3"

  XZ_SRC_FOLDER_NAME="xz-${XZ_VERSION}"
  XZ_FOLDER_NAME="${XZ_SRC_FOLDER_NAME}"
  local xz_archive="${XZ_SRC_FOLDER_NAME}.tar.xz"
  local xz_url="https://sourceforge.net/projects/lzmautils/files/${xz_archive}"

  local xz_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-xz-${XZ_VERSION}-installed"
  if [ ! -f "${xz_stamp_file_path}" ]
  then

    cd "${SOURCES_FOLDER_PATH}"

    download_and_extract "${xz_url}" "${xz_archive}" "${XZ_SRC_FOLDER_NAME}"

    (
      mkdir -p "${LIBS_BUILD_FOLDER_PATH}/${XZ_FOLDER_NAME}"
      cd "${LIBS_BUILD_FOLDER_PATH}/${XZ_FOLDER_NAME}"

      xbb_activate
      xbb_activate_installed_dev

      export CFLAGS="${XBB_CFLAGS} -Wno-implicit-fallthrough"
      export CPPFLAGS="${XBB_CPPFLAGS}"
      export LDFLAGS="${XBB_LDFLAGS_LIB}"

      if [ ! -f "config.status" ]
      then 

        (
          echo
          echo "Running xz configure..."

          bash "${SOURCES_FOLDER_PATH}/${XZ_SRC_FOLDER_NAME}/configure" --help

          bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${XZ_SRC_FOLDER_NAME}/configure" \
            --prefix="${LIBS_INSTALL_FOLDER_PATH}" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${TARGET} \
            \
            --disable-rpath \
            --disable-nls

          cp "config.log" "${LOGS_FOLDER_PATH}/config-xz-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/configure-xz-output.txt"

      fi

      (
        echo
        echo "Running xz make..."

        # Build.
        make -j ${JOBS}
        make install-strip
      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/make-xz-output.txt"
    )

    touch "${xz_stamp_file_path}"

  else
    echo "Library xz already installed."
  fi
}
