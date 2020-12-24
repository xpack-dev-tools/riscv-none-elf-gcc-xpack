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

function build_binutils()
{
  # https://ftp.gnu.org/gnu/binutils/
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=binutils-git
  # https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=gdb-git

  local binutils_version="$1"
  # No versioning here, the inner archives use simple names.
  local binutils_folder_name="binutils-${binutils_version}"
  local binutils_patch="${binutils_folder_name}.patch"

  local binutils_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-${binutils_folder_name}-installed"

  if [ ! -f "${binutils_stamp_file_path}" ]
  then

    if [ ! -d "${SOURCES_FOLDER_PATH}/${BINUTILS_SRC_FOLDER_NAME}" ]
    then
      (
        cd "${SOURCES_FOLDER_PATH}"
        if [ -n "${BINUTILS_GIT_URL}" ]
        then
          git_clone "${BINUTILS_GIT_URL}" "${BINUTILS_GIT_BRANCH}" \
            "${BINUTILS_GIT_COMMIT}" "${BINUTILS_SRC_FOLDER_NAME}"
          cd "${BINUTILS_SRC_FOLDER_NAME}"
          do_patch "${BINUTILS_PATCH}"
        elif [ -n "${BINUTILS_ARCHIVE_URL}" ]
        then
          download_and_extract "${BINUTILS_ARCHIVE_URL}" \
            "${BINUTILS_ARCHIVE_NAME}" "${BINUTILS_SRC_FOLDER_NAME}" \
            "${BINUTILS_PATCH}"
        fi
      )
    fi

    mkdir -pv "${LOGS_FOLDER_PATH}/${binutils_folder_name}"

    (
      mkdir -pv "${BUILD_FOLDER_PATH}/${binutils_folder_name}"
      cd "${BUILD_FOLDER_PATH}/${binutils_folder_name}"

      xbb_activate
      xbb_activate_installed_dev

      CPPFLAGS="${XBB_CPPFLAGS}"
      CFLAGS="${XBB_CFLAGS_NO_W}"
      CXXFLAGS="${XBB_CXXFLAGS_NO_W}"

      LDFLAGS="${XBB_LDFLAGS_APP}" 
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        LDFLAGS+=" -Wl,${XBB_FOLDER_PATH}/mingw/lib/CRT_glob.o"
      elif [ "${TARGET_PLATFORM}" == "linux" ]
      then
        LDFLAGS+=" -Wl,-rpath,${LD_LIBRARY_PATH}"
      fi
      if [ "${IS_DEVELOP}" == "y" ]
      then
        LDFLAGS+=" -v"
      fi

      export CPPFLAGS
      export CFLAGS
      export CXXFLAGS
      export LDFLAGS

      env | sort

      if [ ! -f "config.status" ]
      then
        (
          echo
          echo "Running binutils configure..."
        
          bash "${SOURCES_FOLDER_PATH}/${BINUTILS_SRC_FOLDER_NAME}/configure" --help

          # ? --without-python --without-curses, --with-expat
          # Note that GDB is disabled here, will be build later, possibly from 
          # different sources.
          run_verbose bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${BINUTILS_SRC_FOLDER_NAME}/configure" \
            --prefix="${APP_PREFIX}" \
            --infodir="${APP_PREFIX_DOC}/info" \
            --mandir="${APP_PREFIX_DOC}/man" \
            --htmldir="${APP_PREFIX_DOC}/html" \
            --pdfdir="${APP_PREFIX_DOC}/pdf" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${GCC_TARGET} \
            \
            --with-pkgversion="${BRANDING}" \
            --with-bugurl="${BUGURL}" \
            \
            --disable-nls \
            --disable-werror \
            --disable-sim \
            --disable-gdb \
            --enable-interwork \
            --enable-plugins \
            \
            --disable-libdecnumber \
            --disable-libreadline \
            --with-sysroot="${APP_PREFIX}/${GCC_TARGET}" \
            \
            --enable-build-warnings=no \
            --with-system-zlib \
            
          cp "config.log" "${LOGS_FOLDER_PATH}/${binutils_folder_name}/config-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${binutils_folder_name}/configure-output.txt"
      fi

      (
        echo
        echo "Running binutils make..."
      
        # Build.
        run_verbose make -j ${JOBS} 

        if [ "${WITH_TESTS}" == "y" ]
        then
          run_verbose make check
        fi

        if false # [ "${WITH_STRIP}" == "y" ]
        then
          # For -strip, readline needs a patch.
          run_verbose make install-strip
        else
          run_verbose make install
        fi

        (
          xbb_activate_tex

          if [ "${WITH_PDF}" == "y" ]
          then
            run_verbose make pdf
            run_verbose make install-pdf
          fi

          if [ "${WITH_HTML}" == "y" ]
          then
            run_verbose make html
            run_verbose make install-html
          fi
        )

        # Without this copy, the build for the nano version of the GCC second 
        # step fails with unexpected errors, like "cannot compute suffix of 
        # object files: cannot compile".
        copy_dir "${APP_PREFIX}" "${APP_PREFIX_NANO}"

        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-ar"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-as"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-ld"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-nm"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-objcopy"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-objdump"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-ranlib"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-size"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-strings"
        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-strip"

      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${binutils_folder_name}/make-output.txt"

      copy_license \
        "${SOURCES_FOLDER_PATH}/${BINUTILS_SRC_FOLDER_NAME}" \
        "${binutils_folder_name}"

    )

    touch "${binutils_stamp_file_path}"
  else
    echo "Component binutils already installed."
  fi

  tests_add "test_binutils"
}

function test_binutils()
{
  (
    xbb_activate_installed_bin

    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-ar"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-as"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-ld"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-nm"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-objcopy"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-objdump"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-ranlib"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-size"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-strings"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-strip"

    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-ar" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-as" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-ld" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-nm" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-objcopy" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-objdump" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-ranlib" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-size" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-strings" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-strip" --version

  )
}

function build_gcc_first()
{
  local gcc_first_folder_name="${GCC_FOLDER_NAME}-first"
  local gcc_first_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-${gcc_first_folder_name}-installed"

  if [ ! -f "${gcc_first_stamp_file_path}" ]
  then

    if [ ! -d "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}" ]
    then
      (
        cd "${SOURCES_FOLDER_PATH}"
        if [ -n "${GCC_GIT_URL}" ]
        then
          git_clone "${GCC_GIT_URL}" "${GCC_GIT_BRANCH}" \
            "${GCC_GIT_COMMIT}" "${GCC_SRC_FOLDER_NAME}"
        elif [ -n "${GCC_ARCHIVE_URL}" ]
        then
          download_and_extract "${GCC_ARCHIVE_URL}" \
            "${GCC_ARCHIVE_NAME}" "${GCC_SRC_FOLDER_NAME}"
        fi
      )
    fi

    mkdir -pv "${LOGS_FOLDER_PATH}/${gcc_first_folder_name}"

    if [ -n "${GCC_MULTILIB}" ]
    then
      (
        echo
        echo "Running the multilib generator..."

        cd "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}/gcc/config/riscv"

        xbb_activate
        xbb_activate_installed_dev

        # Be sure the ${GCC_MULTILIB} has no quotes, since it defines 
        # multiple strings.

        # Change IFS temporarily so that we can pass a simple string of
        # whitespace delimited multilib tokens to multilib-generator
        local IFS=$' '
        ./multilib-generator ${GCC_MULTILIB} > "${GCC_MULTILIB_FILE}"
        cat "${GCC_MULTILIB_FILE}"
      )
    fi

    (
      mkdir -pv "${BUILD_FOLDER_PATH}/${gcc_first_folder_name}"
      cd "${BUILD_FOLDER_PATH}/${gcc_first_folder_name}"

      xbb_activate
      xbb_activate_installed_dev

      CPPFLAGS="${XBB_CPPFLAGS}"
      # The gcc/emit_insn.c is huge (>62 MB), so give up on using -pipe
      # and multiple sections, in order to save memory.
      CFLAGS="$(echo "${XBB_CFLAGS_NO_W}" | sed -e 's|-ffunction-sections||' | sed -e 's|-fdata-sections||' | sed -e 's|-pipe||')"
      CXXFLAGS="$(echo "${XBB_CXXFLAGS_NO_W}" | sed -e 's|-ffunction-sections||' | sed -e 's|-fdata-sections||' | sed -e 's|-pipe||')"
      LDFLAGS="${XBB_LDFLAGS_APP}" 
      if [ "${TARGET_PLATFORM}" == "linux" ]
      then
        LDFLAGS+=" -Wl,-rpath,${LD_LIBRARY_PATH}"
      fi      
      if [ "${IS_DEVELOP}" == "y" ]
      then
        LDFLAGS+=" -v"
      fi

      CFLAGS_FOR_TARGET="${CFLAGS_OPTIMIZATIONS_FOR_TARGET}" 
      CXXFLAGS_FOR_TARGET="${CFLAGS_OPTIMIZATIONS_FOR_TARGET}" 

      export CPPFLAGS
      export CFLAGS
      export CXXFLAGS
      export LDFLAGS

      export CFLAGS_FOR_TARGET 
      export CXXFLAGS_FOR_TARGET

      env | sort

      if [ ! -f "config.status" ]
      then
        (
          echo
          echo "Running gcc first stage configure..."
        
          bash "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}/configure" --help

          # https://gcc.gnu.org/install/configure.html
          # --enable-shared[=package[,…]] build shared versions of libraries
          # --enable-tls specify that the target supports TLS (Thread Local Storage). 
          # --enable-nls enables Native Language Support (NLS)
          # --enable-checking=list the compiler is built to perform internal consistency checks of the requested complexity. ‘yes’ (most common checks)
          # --with-headers=dir specify that target headers are available when building a cross compiler
          # --with-newlib Specifies that ‘newlib’ is being used as the target C library. This causes `__eprintf`` to be omitted from `libgcc.a`` on the assumption that it will be provided by newlib.
          # --enable-languages=c newlib does not use C++, so C should be enough

          # --enable-checking=no ???

          # --with-native-system-header-dir="/include" \

          run_verbose bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}/configure" \
            --prefix="${APP_PREFIX}"  \
            --infodir="${APP_PREFIX_DOC}/info" \
            --mandir="${APP_PREFIX_DOC}/man" \
            --htmldir="${APP_PREFIX_DOC}/html" \
            --pdfdir="${APP_PREFIX_DOC}/pdf" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${GCC_TARGET} \
            \
            --with-pkgversion="${BRANDING}" \
            --with-bugurl="${BUGURL}" \
            \
            --enable-languages=c \
            --enable-lto \
            --disable-decimal-float \
            --disable-libffi \
            --disable-libgomp \
            --disable-libmudflap \
            --disable-libquadmath \
            --disable-libssp \
            --disable-libstdcxx-pch \
            --disable-nls \
            --disable-threads \
            --disable-tls \
            --enable-checking=yes \
            --with-newlib \
            --without-headers \
            --with-gnu-as \
            --with-gnu-ld \
            --with-python-dir="share/gcc-${GCC_TARGET}" \
            --with-sysroot="${APP_PREFIX}/${GCC_TARGET}" \
            \
            ${MULTILIB_FLAGS} \
            --with-abi="${GCC_ABI}" \
            --with-arch="${GCC_ARCH}" \
            \
            --disable-build-format-warnings \
            --with-system-zlib \

          cp "config.log" "${LOGS_FOLDER_PATH}/${gcc_first_folder_name}/config-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${gcc_first_folder_name}/configure-output.txt"
      fi

      (
        # Partial build, without documentation.
        echo
        echo "Running gcc first stage make..."

        # Build.
        # No need to make 'all', 'all-gcc' is enough to compile the libraries.
        # Disable parallel build to accomodate for the huge files.
        run_verbose make -j 1 all-gcc
        
        # No -strip available here.
        run_verbose make install-gcc

        # Strip?

      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${gcc_first_folder_name}/make-output.txt"
    )

    touch "${gcc_first_stamp_file_path}"
  else
    echo "Component gcc first stage already installed."
  fi
}

# For the nano build, call it with "-nano".
# $1="" or $1="-nano"
function build_newlib()
{
  local newlib_folder_name="${NEWLIB_FOLDER_NAME}$1"
  local newlib_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-${newlib_folder_name}-installed"

  if [ ! -f "${newlib_stamp_file_path}" ]
  then

    if [ ! -d "${SOURCES_FOLDER_PATH}/${NEWLIB_SRC_FOLDER_NAME}" ]
    then
      (
        cd "${SOURCES_FOLDER_PATH}"
        if [ -n "${NEWLIB_GIT_URL}" ]
        then
          git_clone "${NEWLIB_GIT_URL}" "${NEWLIB_GIT_BRANCH}" \
            "${NEWLIB_GIT_COMMIT}" "${NEWLIB_SRC_FOLDER_NAME}"
        elif [ -n "${NEWLIB_ARCHIVE_URL}" ]
        then
          download_and_extract "${NEWLIB_ARCHIVE_URL}" \
            "${NEWLIB_ARCHIVE_NAME}" "${NEWLIB_SRC_FOLDER_NAME}" 
        fi
      )
    fi

    mkdir -pv "${LOGS_FOLDER_PATH}/${newlib_folder_name}"

    (
      mkdir -pv "${BUILD_FOLDER_PATH}/${newlib_folder_name}"
      cd "${BUILD_FOLDER_PATH}/${newlib_folder_name}"

      xbb_activate
      xbb_activate_installed_dev

      # Add the gcc first stage binaries to the path.
      PATH="${APP_PREFIX}/bin:${PATH}"

      local optimize="${CFLAGS_OPTIMIZATIONS_FOR_TARGET}"
      if [ "$1" == "-nano" ]
      then
        # For newlib-nano optimize for size.
        optimize="$(echo ${optimize} | sed -e 's/-O[123]/-Os/')"
      fi

      CPPFLAGS="${XBB_CPPFLAGS}" 
      CFLAGS="${XBB_CFLAGS_NO_W}"
      CXXFLAGS="${XBB_CXXFLAGS_NO_W}"

      # Note the intentional `-g`.
      CFLAGS_FOR_TARGET="${optimize} -g" 
      CXXFLAGS_FOR_TARGET="${optimize} -g" 

      export CPPFLAGS
      export CFLAGS
      export CXXFLAGS

      export CFLAGS_FOR_TARGET
      export CXXFLAGS_FOR_TARGET

      env | sort

      if [ ! -f "config.status" ]
      then
        (
          # --disable-nls do not use Native Language Support
          # --enable-newlib-io-long-double   enable long double type support in IO functions printf/scanf
          # --enable-newlib-io-long-long   enable long long type support in IO functions like printf/scanf
          # --enable-newlib-io-c99-formats   enable C99 support in IO functions like printf/scanf
          # --enable-newlib-register-fini   enable finalization function registration using atexit
          # --disable-newlib-supplied-syscalls disable newlib from supplying syscalls (__NO_SYSCALLS__)

          # --disable-newlib-fvwrite-in-streamio    disable iov in streamio
          # --disable-newlib-fseek-optimization    disable fseek optimization
          # --disable-newlib-wide-orient    Turn off wide orientation in streamio
          # --disable-newlib-unbuf-stream-opt    disable unbuffered stream optimization in streamio
          # --enable-newlib-nano-malloc    use small-footprint nano-malloc implementation
          # --enable-lite-exit	enable light weight exit
          # --enable-newlib-global-atexit	enable atexit data structure as global
          # --enable-newlib-nano-formatted-io    Use nano version formatted IO
          # --enable-newlib-reent-small

          # --enable-newlib-retargetable-locking ???

          echo
          echo "Running newlib$1 configure..."
        
          bash "${SOURCES_FOLDER_PATH}/${NEWLIB_SRC_FOLDER_NAME}/configure" --help

          # I still did not figure out how to define a variable with
          # the list of options, such that it can be extended, so the
          # brute force approach is to duplicate the entire call.

          if [ "$1" == "" ]
          then

            # Extra options to ARM distribution:
            # --enable-newlib-io-long-long
            # --enable-newlib-io-c99-formats
            # --enable-newlib-reent-check-verify

            # Used in a previous version --enable-newlib-retargetable-locking \

            run_verbose bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${NEWLIB_SRC_FOLDER_NAME}/configure" \
              --prefix="${APP_PREFIX}"  \
              --infodir="${APP_PREFIX_DOC}/info" \
              --mandir="${APP_PREFIX_DOC}/man" \
              --htmldir="${APP_PREFIX_DOC}/html" \
              --pdfdir="${APP_PREFIX_DOC}/pdf" \
              \
              --build=${BUILD} \
              --host=${HOST} \
              --target="${GCC_TARGET}" \
              \
              --enable-newlib-io-long-double \
              --enable-newlib-io-long-long \
              --enable-newlib-io-c99-formats \
              --enable-newlib-register-fini \
              \
              --disable-newlib-supplied-syscalls \
              --disable-nls \
              \

          elif [ "$1" == "-nano" ]
          then

            # --enable-newlib-io-long-long and --enable-newlib-io-c99-formats
            # are currently ignored if --enable-newlib-nano-formatted-io.
            # --enable-newlib-register-fini is debatable, was removed.
            # --enable-newlib-reent-check-verify
            run_verbose bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${NEWLIB_SRC_FOLDER_NAME}/configure" \
              --prefix="${APP_PREFIX_NANO}"  \
              \
              --build=${BUILD} \
              --host=${HOST} \
              --target="${GCC_TARGET}" \
              \
              --enable-newlib-reent-small \
              --disable-newlib-fvwrite-in-streamio \
              --disable-newlib-fseek-optimization \
              --disable-newlib-wide-orient \
              --enable-newlib-nano-malloc \
              --disable-newlib-unbuf-stream-opt \
              --enable-lite-exit \
              --enable-newlib-global-atexit \
              --enable-newlib-nano-formatted-io \
              --disable-newlib-supplied-syscalls \
              --disable-nls \
              --enable-newlib-register-fini \

          else
            echo "Unsupported build_newlib arg $1"
            exit 1
          fi

          cp "config.log" "${LOGS_FOLDER_PATH}/${newlib_folder_name}/config-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${newlib_folder_name}/configure-output.txt"
      fi

      (
        # Partial build, without documentation.
        echo
        echo "Running newlib$1 make..."

        # Build.
        run_verbose make -j ${JOBS}
        # make

        # Top make fails with install-strip due to libgloss make.
        run_verbose make install

        if [ "$1" == "" ]
        then

          if [ "${WITH_PDF}" == "y" ]
          then

            # Warning, parallel build failed on Debian 32-bit.

            (
              if [[ "${RELEASE_VERSION}" =~ 5\.4\.1-* ]]
              then
                hack_pdfetex
              fi

              xbb_activate_tex

              run_verbose make pdf
            )

            install -v -d "${APP_PREFIX_DOC}/pdf"

            install -v -c -m 644 \
              "${GCC_TARGET}/libgloss/doc/porting.pdf" "${APP_PREFIX_DOC}/pdf"
            install -v -c -m 644 \
              "${GCC_TARGET}/newlib/libc/libc.pdf" "${APP_PREFIX_DOC}/pdf"
            install -v -c -m 644 \
              "${GCC_TARGET}/newlib/libm/libm.pdf" "${APP_PREFIX_DOC}/pdf"

          fi

          if [ "${WITH_HTML}" == "y" ]
          then

            run_verbose make html

            install -v -d "${APP_PREFIX_DOC}/html"

            copy_dir "${GCC_TARGET}/newlib/libc/libc.html" "${APP_PREFIX_DOC}/html/libc"
            copy_dir "${GCC_TARGET}/newlib/libm/libm.html" "${APP_PREFIX_DOC}/html/libm"

          fi

        fi

      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${newlib_folder_name}/make-output.txt"

      if [ "$1" == "" ]
      then
        copy_license \
          "${SOURCES_FOLDER_PATH}/${NEWLIB_SRC_FOLDER_NAME}" \
          "${NEWLIB_FOLDER_NAME}"
      fi

    )

    touch "${newlib_stamp_file_path}"
  else
    echo "Component newlib$1 already installed."
  fi
}

# -----------------------------------------------------------------------------

function copy_nano_libs() 
{
  local src_folder="$1"
  local dst_folder="$2"

  if [ -f "${src_folder}/libstdc++.a" ]
  then
    cp -v -f "${src_folder}/libstdc++.a" "${dst_folder}/libstdc++_nano.a"
  fi
  if [ -f "${src_folder}/libsupc++.a" ]
  then
    cp -v -f "${src_folder}/libsupc++.a" "${dst_folder}/libsupc++_nano.a"
  fi
  cp -v -f "${src_folder}/libc.a" "${dst_folder}/libc_nano.a"
  cp -v -f "${src_folder}/libg.a" "${dst_folder}/libg_nano.a"
  if [ -f "${src_folder}/librdimon.a" ]
  then
    cp -v -f "${src_folder}/librdimon.a" "${dst_folder}/librdimon_nano.a"
  fi

  cp -v -f "${src_folder}/nano.specs" "${dst_folder}/"
  if [ -f "${src_folder}/rdimon.specs" ]
  then
    cp -v -f "${src_folder}/rdimon.specs" "${dst_folder}/"
  fi
  cp -v -f "${src_folder}/nosys.specs" "${dst_folder}/"
  cp -v -f "${src_folder}"/*crt0.o "${dst_folder}/"
}

# Copy target libraries from each multilib folders.
# $1=source
# $2=destination
# $3=target gcc
function copy_multi_libs()
{
  local -a multilibs
  local multilib
  local multi_folder
  local src_folder="$1"
  local dst_folder="$2"
  local gcc_target="$3"

  echo ${gcc_target}
  multilibs=( $("${gcc_target}" -print-multi-lib 2>/dev/null) )
  if [ ${#multilibs[@]} -gt 0 ]
  then
    for multilib in "${multilibs[@]}"
    do
      multi_folder="${multilib%%;*}"
      copy_nano_libs "${src_folder}/${multi_folder}" \
        "${dst_folder}/${multi_folder}"
    done
  else
    copy_nano_libs "${src_folder}" "${dst_folder}"
  fi
}

# -----------------------------------------------------------------------------

function copy_linux_libs()
{
  local copy_linux_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-copy-linux-completed"
  if [ ! -f "${copy_linux_stamp_file_path}" ]
  then

    local linux_path="${LINUX_INSTALL_RELATIVE_PATH}/${APP_LC_NAME}"

    (
      cd "${WORK_FOLDER_PATH}"

      copy_dir "${linux_path}/${GCC_TARGET}/lib" "${APP_PREFIX}/${GCC_TARGET}/lib"
      copy_dir "${linux_path}/${GCC_TARGET}/include" "${APP_PREFIX}/${GCC_TARGET}/include"
      copy_dir "${linux_path}/include" "${APP_PREFIX}/include"
      copy_dir "${linux_path}/lib" "${APP_PREFIX}/lib"
      copy_dir "${linux_path}/share" "${APP_PREFIX}/share"
    ) 

    (
      cd "${APP_PREFIX}"
      find "${GCC_TARGET}/lib" "${GCC_TARGET}/include" "include" "lib" "share" \
        -perm /111 -and ! -type d \
        -exec rm '{}' ';'
    )
    touch "${copy_linux_stamp_file_path}"

  else
    echo "Component copy-linux-libs already processed."
  fi
}

# -----------------------------------------------------------------------------

# For the nano build, call it with "-nano".
# $1="" or $1="-nano"
function build_gcc_final()
{
  local gcc_final_folder_name="${GCC_FOLDER_NAME}-final$1"
  local gcc_final_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-${gcc_final_folder_name}-installed"

  if [ ! -f "${gcc_final_stamp_file_path}" ]
  then

    if [ ! -d "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}" ]
    then
      (
        cd "${SOURCES_FOLDER_PATH}"
        if [ -n "${GCC_GIT_URL}" ]
        then
          git_clone "${GCC_GIT_URL}" "${GCC_GIT_BRANCH}" \
            "${GCC_GIT_COMMIT}" "${GCC_SRC_FOLDER_NAME}"
        elif [ -n "${GCC_ARCHIVE_URL}" ]
        then
          download_and_extract "${GCC_ARCHIVE_URL}" \
            "${GCC_ARCHIVE_NAME}" "${GCC_SRC_FOLDER_NAME}"
        fi
      )
    fi

    mkdir -pv "${LOGS_FOLDER_PATH}/${gcc_final_folder_name}"

    (
      mkdir -pv "${BUILD_FOLDER_PATH}/${gcc_final_folder_name}"
      cd "${BUILD_FOLDER_PATH}/${gcc_final_folder_name}"

      xbb_activate
      xbb_activate_installed_dev

      CPPFLAGS="${XBB_CPPFLAGS}" 

      # The gcc/emit_insn.c is huge (>62 MB), so give up on using -pipe
      # and multiple sections, in order to save memory.
      CFLAGS="$(echo "${XBB_CFLAGS_NO_W}" | sed -e 's|-ffunction-sections||' | sed -e 's|-fdata-sections||' | sed -e 's|-pipe||')"
      CXXFLAGS="$(echo "${XBB_CXXFLAGS_NO_W}" | sed -e 's|-ffunction-sections||' | sed -e 's|-fdata-sections||' | sed -e 's|-pipe||')"

      # Attempts to use `-Wa,-mbig-obj` failed on Windows.

      LDFLAGS="${XBB_LDFLAGS_APP}" 
      if [ "${TARGET_PLATFORM}" == "linux" ]
      then
        LDFLAGS+=" -Wl,-rpath,${LD_LIBRARY_PATH}"
      fi      
      # Do not add CRT_glob.o here, it will fail with already defined,
      # since it is already handled by --enable-mingw-wildcard.
      if [ "${IS_DEVELOP}" == "y" ]
      then
        LDFLAGS+=" -v"
      fi

      local optimize="${CFLAGS_OPTIMIZATIONS_FOR_TARGET}"
      if [ "$1" == "-nano" ]
      then
        # For newlib-nano optimize for size.
        optimize="$(echo ${optimize} | sed -e 's|-O[123]|-Os|')"
      fi

      # Note the intentional `-g`.
      CFLAGS_FOR_TARGET="${optimize} -g" 
      CXXFLAGS_FOR_TARGET="${optimize} -fno-exceptions -g" 

      export CPPFLAGS
      export CFLAGS
      export CXXFLAGS 
      export LDFLAGS        

      export CFLAGS_FOR_TARGET
      export CXXFLAGS_FOR_TARGET

      local mingw_wildcard="--disable-mingw-wildcard"

      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        add_linux_install_path

        mingw_wildcard="--enable-mingw-wildcard"

        export AR_FOR_TARGET="${GCC_TARGET}-ar"
        export NM_FOR_TARGET="${GCC_TARGET}-nm"
        export OBJDUMP_FOR_TARET="${GCC_TARGET}-objdump"
        export STRIP_FOR_TARGET="${GCC_TARGET}-strip"
        export CC_FOR_TARGET="${GCC_TARGET}-gcc"
        export GCC_FOR_TARGET="${GCC_TARGET}-gcc"
        export CXX_FOR_TARGET="${GCC_TARGET}-g++"
      fi

      env | sort

      if [ ! -f "config.status" ]
      then
        (
          echo
          echo "Running gcc$1 final stage configure..."
        
          bash "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}/configure" --help

          # https://gcc.gnu.org/install/configure.html
          # --enable-shared[=package[,…]] build shared versions of libraries
          # --enable-tls specify that the target supports TLS (Thread Local Storage). 
          # --enable-nls enables Native Language Support (NLS)
          # --enable-checking=list the compiler is built to perform internal consistency checks of the requested complexity. ‘yes’ (most common checks)
          # --with-headers=dir specify that target headers are available when building a cross compiler
          # --with-newlib Specifies that ‘newlib’ is being used as the target C library. This causes `__eprintf`` to be omitted from `libgcc.a`` on the assumption that it will be provided by newlib.
          # --enable-languages=c,c++ Support only C/C++, ignore all other.

          # SiFive uses --enable-tls; I don't think it is necessary.

          if [ "$1" == "" ]
          then

            run_verbose bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}/configure" \
              --prefix="${APP_PREFIX}"  \
              --infodir="${APP_PREFIX_DOC}/info" \
              --mandir="${APP_PREFIX_DOC}/man" \
              --htmldir="${APP_PREFIX_DOC}/html" \
              --pdfdir="${APP_PREFIX_DOC}/pdf" \
              \
              --build=${BUILD} \
              --host=${HOST} \
              --target=${GCC_TARGET} \
              \
              --with-pkgversion="${BRANDING}" \
              --with-bugurl="${BUGURL}" \
              \
              --enable-languages=c,c++ \
              ${mingw_wildcard} \
              --enable-plugins \
              --enable-lto \
              --enable-checking=yes \
              \
              --disable-tls \
              --disable-decimal-float \
              --disable-libffi \
              --disable-libgomp \
              --disable-libmudflap \
              --disable-libquadmath \
              --disable-libssp \
              --disable-libstdcxx-pch \
              --disable-nls \
              --disable-threads \
              \
              --with-gnu-as \
              --with-gnu-ld \
              --with-newlib \
              --with-headers=yes \
              --with-python-dir="share/gcc-${GCC_TARGET}" \
              --with-sysroot="${APP_PREFIX}/${GCC_TARGET}" \
              --with-native-system-header-dir="/include" \
              \
              ${MULTILIB_FLAGS} \
              --with-abi="${GCC_ABI}" \
              --with-arch="${GCC_ARCH}" \
              \
              --disable-build-format-warnings \
              --with-system-zlib

          elif [ "$1" == "-nano" ]
          then

            run_verbose bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}/configure" \
              --prefix="${APP_PREFIX_NANO}"  \
              \
              --build=${BUILD} \
              --host=${HOST} \
              --target=${GCC_TARGET} \
              \
              --with-pkgversion="${BRANDING}" \
              --with-bugurl="${BUGURL}" \
              \
              --enable-languages=c,c++ \
              \
              --disable-tls \
              --disable-decimal-float \
              --disable-libffi \
              --disable-libgomp \
              --disable-libmudflap \
              --disable-libquadmath \
              --disable-libssp \
              --disable-libstdcxx-pch \
              --disable-libstdcxx-verbose \
              --disable-nls \
              --disable-threads \
              \
              --with-gnu-as \
              --with-gnu-ld \
              --with-newlib \
              --with-headers=yes \
              --with-python-dir="share/gcc-${GCC_TARGET}" \
              --with-sysroot="${APP_PREFIX_NANO}/${GCC_TARGET}" \
              --with-native-system-header-dir="/include" \
              ${MULTILIB_FLAGS} \
              \
              --disable-build-format-warnings \
              --with-system-zlib

          fi

          cp "config.log" "${LOGS_FOLDER_PATH}/${gcc_final_folder_name}/config-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${gcc_final_folder_name}/configure-output.txt"
      fi

      (
        # Partial build, without documentation.
        echo
        echo "Running gcc$1 final stage make..."

        if [ "${TARGET_PLATFORM}" != "win32" ]
        then

          # Passing USE_TM_CLONE_REGISTRY=0 via INHIBIT_LIBC_CFLAGS to disable
          # transactional memory related code in crtbegin.o.
          # This is a workaround. Better approach is have a t-* to set this flag via
          # CRTSTUFF_T_CFLAGS

          # Disable parallel build for the compiler itself,
          # to accomodate for the huge files.
          run_verbose make -j 1 INHIBIT_LIBC_CFLAGS="-DUSE_TM_CLONE_REGISTRY=0" all-gcc

          # Compile the libraries.
          run_verbose make -j ${JOBS} INHIBIT_LIBC_CFLAGS="-DUSE_TM_CLONE_REGISTRY=0"
          # make INHIBIT_LIBC_CFLAGS="-DUSE_TM_CLONE_REGISTRY=0"

          if [ "${WITH_STRIP}" == "y" ]
          then
            run_verbose make install-strip
          else
            run_verbose make install
          fi

          if [ "$1" == "-nano" ]
          then

            local target_gcc=""
            if [ "${TARGET_PLATFORM}" == "win32" ]
            then
              target_gcc="${GCC_TARGET}-gcc"
            else
              target_gcc="${APP_PREFIX_NANO}/bin/${GCC_TARGET}-gcc"
            fi

            # Copy the libraries after appending the `_nano` suffix.
            # Iterate through all multilib names.
            copy_multi_libs \
              "${APP_PREFIX_NANO}/${GCC_TARGET}/lib" \
              "${APP_PREFIX}/${GCC_TARGET}/lib" \
              "${target_gcc}"

            # Copy the nano configured newlib.h file into the location that nano.specs
            # expects it to be.
            mkdir -pv "${APP_PREFIX}/${GCC_TARGET}/include/newlib-nano"
            cp -v -f "${APP_PREFIX_NANO}/${GCC_TARGET}/include/newlib.h" \
              "${APP_PREFIX}/${GCC_TARGET}/include/newlib-nano/newlib.h"

          fi

        else

          # Build.
          # For Windows build only the GCC binaries, the libraries were copied 
          # from the Linux build.
          # Disable parallel build to accomodate for the huge files.
          run_verbose make -j 1 all-gcc

          # No -strip here.
          run_verbose make install-gcc

          # Strip?

        fi

        if [ "$1" == "" ]
        then
          (
            xbb_activate_tex

            # Full build, with documentation.
            if [ "${WITH_PDF}" == "y" ]
            then
              run_verbose make pdf
              run_verbose make install-pdf
            fi

            if [ "${WITH_HTML}" == "y" ]
            then
              run_verbose make html
              run_verbose make install-html
            fi
          )
        fi

      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${gcc_final_folder_name}/make-output.txt"

      if [ "$1" == "" ]
      then
        copy_license \
          "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}" \
          "${GCC_FOLDER_NAME}"
      fi
    )

    touch "${gcc_final_stamp_file_path}"
  else
    echo "Component gcc$1 final stage already installed."
  fi

  if [ "$1" == "" ]
  then
    tests_add "test_gcc"
  fi
}

function test_gcc()
{
  (
    xbb_activate_installed_bin

    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-gcc"
    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-g++"
    show_libs "${APP_PREFIX}/libexec/gcc/${GCC_TARGET}/${GCC_VERSION}/cc1"
    show_libs "${APP_PREFIX}/libexec/gcc/${GCC_TARGET}/${GCC_VERSION}/cc1plus"
    show_libs "${APP_PREFIX}/libexec/gcc/${GCC_TARGET}/${GCC_VERSION}/collect2"
    show_libs "${APP_PREFIX}/libexec/gcc/${GCC_TARGET}/${GCC_VERSION}/lto-wrapper"
    show_libs "${APP_PREFIX}/libexec/gcc/${GCC_TARGET}/${GCC_VERSION}/lto1"

    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" --help
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" -dumpversion
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" -dumpmachine
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" -print-multi-lib
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" -dumpspecs | wc -l

    local tmp=$(mktemp /tmp/gcc-test.XXXXX)
    rm -rf "${tmp}"

    mkdir -pv "${tmp}"
    cd "${tmp}"

    # Note: __EOF__ is quoted to prevent substitutions here.
    cat <<'__EOF__' > hello.c
#include <stdio.h>

int
main(int argc, char* argv[])
{
  printf("Hello World\n");
}
__EOF__
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" -o hello-c.elf -specs=nosys.specs hello.c

    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" -o hello.c.o -c -flto hello.c
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gcc" -o hello-c-lto.elf -specs=nosys.specs -flto -v hello.c.o

    # Note: __EOF__ is quoted to prevent substitutions here.
    cat <<'__EOF__' > hello.cpp
#include <iostream>

int
main(int argc, char* argv[])
{
  std::cout << "Hello World" << std::endl;
}

extern "C" void __sync_synchronize();

void 
__sync_synchronize()
{
}
__EOF__
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-g++" -o hello-cpp.elf -specs=nosys.specs hello.cpp

    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-g++" -o hello.cpp.o -c -flto hello.cpp
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-g++" -o hello-cpp-lto.elf -specs=nosys.specs -flto -v hello.cpp.o

    cd ..
    rm -rf "${tmp}"
  )
}

# Called multile times, with and without python support.
# $1="" or $1="-py" or $1="-py3"
function build_gdb()
{  
  local gdb_folder_name="${GDB_FOLDER_NAME}$1"
  local gdb_stamp_file_path="${INSTALL_FOLDER_PATH}/stamp-${gdb_folder_name}-installed"

  if [ ! -f "${gdb_stamp_file_path}" ]
  then

    # Same package as binutils.
    if [ ! -d "${SOURCES_FOLDER_PATH}/${GDB_SRC_FOLDER_NAME}" ]
    then
      (
        cd "${SOURCES_FOLDER_PATH}"
        if [ -n "${GDB_GIT_URL}" ]
        then
          git_clone "${GDB_GIT_URL}" "${GDB_GIT_BRANCH}" \
            "${GDB_GIT_COMMIT}" "${GDB_SRC_FOLDER_NAME}"
          cd "${GDB_SRC_FOLDER_NAME}"
          do_patch "${GDB_PATCH}"
        elif [ -n "${GDB_ARCHIVE_URL}" ]
        then
          download_and_extract "${GDB_ARCHIVE_URL}" \
            "${GDB_ARCHIVE_NAME}" "${GDB_SRC_FOLDER_NAME}" \
            "${GDB_PATCH}"
        fi
      )
    fi

    mkdir -pv "${LOGS_FOLDER_PATH}/${gdb_folder_name}"

    (
      mkdir -pv "${BUILD_FOLDER_PATH}/${gdb_folder_name}"
      cd "${BUILD_FOLDER_PATH}/${gdb_folder_name}"

      xbb_activate
      xbb_activate_installed_dev

      CPPFLAGS="${XBB_CPPFLAGS}" 
      CFLAGS="${XBB_CFLAGS_NO_W}"
      CXXFLAGS="${XBB_CXXFLAGS_NO_W}"
          
      # libiconv is used by Python3.
      # export LIBS="-liconv"
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        # https://stackoverflow.com/questions/44150871/embeded-python3-6-with-mingw-in-c-fail-on-linking
        # ???
        CPPFLAGS+=" -DPy_BUILD_CORE_BUILTIN=1"

        # From Arm script.
        LDFLAGS="${XBB_LDFLAGS_APP} -Wl,${XBB_FOLDER_PATH}/mingw/lib/CRT_glob.o"
        # Workaround for undefined reference to `__strcpy_chk' in GCC 9.
        # https://sourceforge.net/p/mingw-w64/bugs/818/
        LIBS="-lssp -liconv"
      elif [ "${TARGET_PLATFORM}" == "darwin" ]
      then
        # This makes gdb-py fail!
        # Pick some system libraries from XBB, to avoid rebuilding them here.
        #        CPPFLAGS+=" -I${XBB_FOLDER_PATH}/include" 
        #        LDFLAGS+=" -L${XBB_FOLDER_PATH}/lib"
        LDFLAGS="${XBB_LDFLAGS_APP}"
        LIBS="-liconv -lncurses"
      elif [ "${TARGET_PLATFORM}" == "linux" ]
      then
        LDFLAGS="${XBB_LDFLAGS_APP}"
        LDFLAGS+=" -Wl,-rpath,${LD_LIBRARY_PATH}"
        LIBS=""
      fi

      if [ "${IS_DEVELOP}" == "y" ]
      then
        LDFLAGS+=" -v"
      fi

      if [ "${TARGET_PLATFORM}" == "darwin" ]
      then
        # Pick some system libraries from XBB, to avoid rebuilding them here.
        # Otherwise configure will not identify that Python is present.
        CPPFLAGS+=" -I${XBB_FOLDER_PATH}/include" 
        LDFLAGS+=" -L${XBB_FOLDER_PATH}/lib"
      fi

      # Not yet used, requires patching the python-config.py.
      # See the arm-none-eabi script.
      CONFIG_PYTHON_PREFIX=""

      local extra_python_opts="--with-python=no"
      if [ "$1" == "-py3" ]
      then
        if [ "${TARGET_PLATFORM}" == "win32" ]
        then
          # The source archive includes only the pyconfig.h.in, which needs
          # to be configured, which is not an easy task. Thus add the file copied 
          # from a Windows install.
          cp -v "${BUILD_GIT_PATH}/patches/pyconfig-win-${PYTHON3_VERSION}.h" \
            "${LIBS_INSTALL_FOLDER_PATH}/include/pyconfig.h"

          extra_python_opts="--with-python=${BUILD_GIT_PATH}/patches/python${PYTHON3_VERSION_MAJOR_MINOR}-config.sh"
        else
          extra_python_opts="--with-python=${LIBS_INSTALL_FOLDER_PATH}/bin/python3.${PYTHON3_VERSION_MINOR}"

          CONFIG_PYTHON_PREFIX="${APP_PREFIX}"
        fi
      fi

      local tui_option
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        tui_option="--disable-tui"
      else
        tui_option="--enable-tui"
      fi

      export CPPFLAGS
      export CFLAGS
      export CXXFLAGS
          
      export LDFLAGS
      export LIBS

      export CONFIG_PYTHON_PREFIX

      env | sort

      if [ ! -f "config.status" ]
      then
        (
          echo
          echo "Running gdb$1 configure..."
        
          bash "${SOURCES_FOLDER_PATH}/${GDB_SRC_FOLDER_NAME}/configure" --help

          # Note that all components are disabled, except GDB.
          run_verbose bash ${DEBUG} "${SOURCES_FOLDER_PATH}/${GDB_SRC_FOLDER_NAME}/configure" \
            --prefix="${APP_PREFIX}"  \
            --infodir="${APP_PREFIX_DOC}/info" \
            --mandir="${APP_PREFIX_DOC}/man" \
            --htmldir="${APP_PREFIX_DOC}/html" \
            --pdfdir="${APP_PREFIX_DOC}/pdf" \
            \
            --build=${BUILD} \
            --host=${HOST} \
            --target=${GCC_TARGET} \
            \
            --with-pkgversion="${BRANDING}" \
            --with-bugurl="${BUGURL}" \
            \
            --enable-gdb \
            --disable-nls \
            --disable-sim \
            --disable-gas \
            --disable-binutils \
            --disable-ld \
            --disable-gold \
            --disable-gprof \
            --with-expat \
            --with-lzma=yes \
            --with-system-gdbinit="${APP_PREFIX}/${GCC_TARGET}/lib/gdbinit" \
            --with-gdb-datadir="${APP_PREFIX}/${GCC_TARGET}/share/gdb" \
            \
            ${extra_python_opts} \
            --program-prefix="${GCC_TARGET}-" \
            --program-suffix="$1" \
            \
            --disable-werror \
            --enable-build-warnings=no \
            --with-system-zlib \
            --without-guile \
            --without-babeltrace \
            --without-libunwind-ia64 \
            ${tui_option} \

          cp "config.log" "${LOGS_FOLDER_PATH}/${gdb_folder_name}/config-log.txt"
        ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${gdb_folder_name}/configure-output.txt"
      fi

      (
        echo
        echo "Running gdb$1 make..."

        # Build.
        run_verbose make -j ${JOBS}
        # make 

        # install-strip fails, not only because of readline has no install-strip
        # but even after patching it tries to strip a non elf file
        # strip:.../install/riscv-none-gcc/bin/_inst.672_: file format not recognized
        run_verbose make install

        if [ "$1" == "" ]
        then
          (
            xbb_activate_tex

            if [ "${WITH_PDF}" == "y" ]
            then
              run_verbose make pdf
              run_verbose make install-pdf
            fi

            if [ "${WITH_HTML}" == "y" ]
            then
              run_verbose make html 
              run_verbose make install-html 
            fi
          )
        fi

        rm -rfv "${LIBS_INSTALL_FOLDER_PATH}/include/pyconfig.h"

        show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-gdb$1"

      ) 2>&1 | tee "${LOGS_FOLDER_PATH}/${gdb_folder_name}/make-output.txt"

      if [ "$1" == "" ]
      then
        copy_license \
          "${SOURCES_FOLDER_PATH}/${GDB_SRC_FOLDER_NAME}/gdb" \
          "${GDB_FOLDER_NAME}"
      fi

    )

    touch "${gdb_stamp_file_path}"
  else
    echo "Component gdb$1 already installed."
  fi

  tests_add "test_gdb$1"
}

function test_gdb_py()
{
  test_gdb "-py"
}

function test_gdb_py3()
{
  test_gdb "-py3"
}

function test_gdb()
{
  local suffix=""
  if [ $# -ge 1 ]
  then
    suffix="$1"
  fi

  (
    # Required by gdb-py to access the python shared library.
    xbb_activate_installed_bin

    show_libs "${APP_PREFIX}/bin/${GCC_TARGET}-gdb${suffix}"

    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gdb${suffix}" --version
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gdb${suffix}" --config

    # This command is known to fail with 'Abort trap: 6' (SIGABRT)
    run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gdb${suffix}" \
      --nh \
      --nx \
      -ex='show language' \
      -ex='set language auto' \
      -ex='quit'


    if [ "${suffix}" == "-py3" ]
    then
      # Show Python paths.
      run_app "${APP_PREFIX}/bin/${GCC_TARGET}-gdb${suffix}" \
        --nh \
        --nx \
        -ex='set pagination off' \
        -ex='python import sys; print(sys.prefix)' \
        -ex='python import sys; import os; print(os.pathsep.join(sys.path))' \
        -ex='quit'
    fi
  )
}

# -----------------------------------------------------------------------------

function tidy_up() 
{
  (
    xbb_activate

    echo
    echo "Tidying up..."

    cd "${WORK_FOLDER_PATH}"

    find "${APP_PREFIX}" -name "libiberty.a" -exec rm -v '{}' ';'
    find "${APP_PREFIX}" -name '*.la' -exec rm -v '{}' ';'

    if [ "${TARGET_PLATFORM}" == "win32" ]
    then
      find "${APP_PREFIX}" -name "liblto_plugin.a" -exec rm -v '{}' ';'
      find "${APP_PREFIX}" -name "liblto_plugin.dll.a" -exec rm -v '{}' ';'
    fi
  )
}

function strip_libs()
{
  if [ "${WITH_STRIP}" == "y" ]
  then
    (
      xbb_activate

      PATH="${APP_PREFIX}/bin:${PATH}"

      echo
      echo "Stripping libraries..."

      cd "${WORK_FOLDER_PATH}"

      # which "${GCC_TARGET}-objcopy"

      local libs=$(find "${APP_PREFIX}" -name '*.[ao]')
      for lib in ${libs}
      do
        echo "${GCC_TARGET}-objcopy -R ... ${lib}"
        "${APP_PREFIX}/bin/${GCC_TARGET}-objcopy" -R .comment -R .note -R .debug_info -R .debug_aranges -R .debug_pubnames -R .debug_pubtypes -R .debug_abbrev -R .debug_line -R .debug_str -R .debug_ranges -R .debug_loc "${lib}" || true
      done
    )
  fi
}

function final_tunings()
{
  # Create the missing LTO plugin links.
  # For `ar` to work with LTO objects, it needs the plugin in lib/bfd-plugins,
  # but the build leaves it where `ld` needs it. On POSIX, make a soft link.
  if [ "${FIX_LTO_PLUGIN}" == "y" ]
  then
    (
      cd "${APP_PREFIX}"

      echo
      if [ "${TARGET_PLATFORM}" == "win32" ]
      then
        echo
        echo "Copying ${LTO_PLUGIN_ORIGINAL_NAME}..."

        mkdir -pv "$(dirname ${LTO_PLUGIN_BFD_PATH})"

        if [ ! -f "${LTO_PLUGIN_BFD_PATH}" ]
        then
          local plugin_path="$(find * -type f -name ${LTO_PLUGIN_ORIGINAL_NAME})"
          if [ ! -z "${plugin_path}" ]
          then
            cp -v "${plugin_path}" "${LTO_PLUGIN_BFD_PATH}"
          else
            echo "${LTO_PLUGIN_ORIGINAL_NAME} not found."
            exit 1
          fi
        fi
      else
        echo
        echo "Creating ${LTO_PLUGIN_ORIGINAL_NAME} link..."

        mkdir -pv "$(dirname ${LTO_PLUGIN_BFD_PATH})"
        if [ ! -f "${LTO_PLUGIN_BFD_PATH}" ]
        then
          local plugin_path="$(find * -type f -name ${LTO_PLUGIN_ORIGINAL_NAME})"
          if [ ! -z "${plugin_path}" ]
          then
            ln -s -v "../../${plugin_path}" "${LTO_PLUGIN_BFD_PATH}"
          else
            echo "${LTO_PLUGIN_ORIGINAL_NAME} not found."
            exit 1
          fi
        fi
      fi
    )
  fi
}

# -----------------------------------------------------------------------------
