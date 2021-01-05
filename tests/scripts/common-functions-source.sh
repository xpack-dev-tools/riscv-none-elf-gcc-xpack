# -----------------------------------------------------------------------------
# This file is part of the xPack distribution.
#   (https://xpack.github.io)
# Copyright (c) 2020 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software 
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Common functions used in various tests.
#
# Requires 
# - app_folder_path
# - test_folder_path
# - archive_platform (win32|linux|darwin)

# -----------------------------------------------------------------------------

# Without Arm 32-bit, without opensuse/leap:15
function create_stable_data_file()
{
  local message="$1"
  local branch="$2"
  local base_url="$3"
  local data_file_path="$4"

# Note: __EOF__ is NOT quoted to allow substitutions.
cat <<__EOF__ > "${data_file_path}"
{
  "request": {
    "message": "${message}",
    "branch": "${branch}",
    "config": {
      "merge_mode": "replace",
      "jobs": [
        {
          "name": "Ubuntu 12, 14, 16, 18, 20 (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:20.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:18.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:16.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:14.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:12.04 ${base_url} "
          ]
        },
        {
          "name": "Ubuntu 14, 16, 18 (Intel 32-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/ubuntu:18.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/ubuntu:16.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/ubuntu:14.04 ${base_url} "
          ]
        },
        {
          "name": "Ubuntu 16, 18, 20 (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:20.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:18.04 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:16.04 ${base_url} "
          ]
        },
        {
          "name": "Debian 8, 9, 10 (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:buster ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:stretch ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:jessie ${base_url} "
          ]
        },
        {
          "name": "Debian 8, 9, 10 (Intel 32-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/debian:buster ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/debian:stretch ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/debian:jessie ${base_url} "
          ]
        },
        {
          "name": "Debian 9, 10 (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:buster ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:stretch ${base_url} "
          ]
        },
        {
          "name": "CentOS 7, 8 (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh centos:8 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh centos:7 ${base_url} "
          ]
        },
        {
          "name": "CentOS 7 (Intel 32-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/centos:7 ${base_url} "
          ]
        },
        {
          "name": "CentOS 7, 8 (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh centos:8 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh centos:7 ${base_url} "
          ]
        },
        {
          "name": "OpenSUSE 13, 15 (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh opensuse/leap:15 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh opensuse/amd64:13.2 ${base_url} "
          ]
        },
        {
          "name": "Fedora 20, 25, 27, 29, 31 (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:31 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:29 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:27 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:25 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:20 ${base_url} "
          ]
        },
        {
          "name": "Fedora 27, 29, 31 (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:31 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:29 ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:27 ${base_url} "
          ]
        },
        {
          "name": "macOS 10.15 Intel",
          "os": "osx",
          "arch": "amd64",
          "osx_image": "xcode11.5",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh ${base_url}" 
          ]
        },
        {
          "name": "macOS 10.14 Intel",
          "os": "osx",
          "arch": "amd64",
          "osx_image": "xcode11.3",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh ${base_url}" 
          ]
        },
        {
          "name": "macOS 10.13 Intel",
          "os": "osx",
          "arch": "amd64",
          "osx_image": "xcode10.1",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh ${base_url}" 
          ]
        },
        {
          "name": "macOS 10.12 Intel",
          "os": "osx",
          "arch": "amd64",
          "osx_image": "xcode9.2",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh ${base_url}" 
          ]
        },
        {
          "name": "macOS 10.11 Intel",
          "os": "osx",
          "arch": "amd64",
          "osx_image": "xcode8",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh ${base_url}" 
          ]
        },
        {
          "name": "macOS 10.10 Intel",
          "os": "osx",
          "arch": "amd64",
          "osx_image": "xcode6.4",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh ${base_url}" 
          ]
        },
        {
          "name": "Windows 10 (Intel 64-bit)",
          "os": "windows",
          "arch": "amd64",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh ${base_url} " 
          ]
        },
        {
          "name": "Windows 10 (Intel 32-bit)",
          "os": "windows",
          "arch": "amd64",
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/native-test.sh --32 ${base_url} " 
          ]
        }
      ],
      "notifications": {
        "email": {
          "on_success": "always",
          "on_failure": "always"
        }
      }
    }
  }
}
__EOF__

}


# --32 i386/ubuntu:rolling fails during update
# Arm 32-bit removed
function create_latest_data_file()
{
  local message="$1"
  local branch="$2"
  local base_url="$3"
  local data_file_path="$4"

# Note: __EOF__ is NOT quoted to allow substitutions.
cat <<__EOF__ > "${data_file_path}"
{
  "request": {
    "message": "${message}",
    "branch": "${branch}",
    "config": {
      "merge_mode": "replace",
      "jobs": [
        {
          "name": "Ubuntu rolling, latest (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:latest ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:rolling ${base_url} "
          ]
        },
        {
          "name": "Ubuntu rolling, latest (Intel 32-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/ubuntu:latest ${base_url} "
          ]
        },
        {
          "name": "Ubuntu rolling, latest (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:latest ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh ubuntu:rolling ${base_url} "
          ]
        },
        {
          "name": "Debian latest, testing (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:testing ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:latest ${base_url} "
          ]
        },
        {
          "name": "Debian testing (Intel 32-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/debian:testing ${base_url} "
          ]
        },
        {
          "name": "Debian latest, testing (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:testing ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh debian:latest ${base_url} "
          ]
        },
        {
          "name": "CentOS latest (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh centos:latest ${base_url} "
          ]
        },
        {
          "name": "CentOS latest (Intel 32-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh --32 i386/centos:latest ${base_url} "
          ]
        },
        {
          "name": "CentOS latest (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh centos:latest ${base_url} "
          ]
        },
        {
          "name": "OpenSUSE tumbleweed (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh opensuse/tumbleweed ${base_url} "
          ]
        },
        {
          "name": "OpenSUSE tumbleweed (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh opensuse/tumbleweed ${base_url} "
          ]
        },
        {
          "name": "Fedora latest, rawhide (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:rawhide ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:latest ${base_url} "
          ]
        },
        {
          "name": "Fedora latest, rawhide (Arm 64-bit)",
          "os": "linux",
          "arch": "arm64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:rawhide ${base_url} ",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh fedora:latest ${base_url} "
          ]
        },
        {
          "name": "Arch latest (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh archlinux:latest ${base_url} "
          ]
        },
        {
          "name": "Manjaro base (Intel 64-bit)",
          "os": "linux",
          "arch": "amd64",
          "dist": "bionic",
          "services": [ "docker" ],
          "language": "minimal",
          "script": [
            "env | sort",
            "pwd",
            "DEBUG=${DEBUG} bash tests/scripts/docker-test.sh manjarolinux/base ${base_url} "
          ]
        },
        {}
      ],
      "notifications": {
        "email": {
          "on_success": "always",
          "on_failure": "always"
        }
      }
    }
  }
}
__EOF__

}

# -----------------------------------------------------------------------------

function test_binutils()
{
  echo
  echo "Testing if binutils start properly..."

  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-ar"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-as"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-ld"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-nm"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-objcopy"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-objdump"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-ranlib"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-size"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-strings"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-strip"

  run_app "${app_folder_path}/bin/${gcc_target_prefix}-ar" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-as" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-ld" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-nm" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-objcopy" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-objdump" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-ranlib" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-size" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-strings" --version
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-strip" --version
}

function test_gcc()
{
  echo
  echo "Testing if gcc starts properly..."

  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-gcc"
  show_libs "${app_folder_path}/bin/${gcc_target_prefix}-g++"

  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" --help
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" -dumpversion
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" -dumpmachine
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" -print-multi-lib
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" -dumpspecs | wc -l
 
  echo
  echo "Testing if gcc compiles simple programs..."

  local tmp="${test_folder_path}-gcc"
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

  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" -o hello-c.elf -specs=nosys.specs hello.c

  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" -o hello.c.o -c -flto hello.c
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-gcc" -o hello-c-lto.elf -specs=nosys.specs -flto -v hello.c.o

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

  run_app "${app_folder_path}/bin/${gcc_target_prefix}-g++" -o hello-cpp.elf -specs=nosys.specs hello.cpp

  run_app "${app_folder_path}/bin/${gcc_target_prefix}-g++" -o hello.cpp.o -c -flto hello.cpp
  run_app "${app_folder_path}/bin/${gcc_target_prefix}-g++" -o hello-cpp-lto.elf -specs=nosys.specs -flto -v hello.cpp.o

  cd ..
  rm -rf "${tmp}"
}

function test_gdb()
{
  local suffix=""
  if [ $# -ge 1 ]
  then
    suffix="$1"
  fi

  local exe=""
  if [ "${node_platform}" == "win32" ]
  then
    exe=".exe"
  fi

  if [ ! -x "${app_folder_path}/bin/${gcc_target_prefix}-gdb${suffix}${exe}" ]
  then
    echo
    echo ">>> ${gcc_target_prefix}-gdb${suffix} not present, tests skipped."
    return
  fi

  (
    echo
    echo "Testing if gdb${suffix} starts properly..."

    # rm -rf "${app_folder_path}/bin/python27.dll"
    show_libs "${app_folder_path}/bin/${gcc_target_prefix}-gdb${suffix}"

    echo
    run_app "${app_folder_path}/bin/${gcc_target_prefix}-gdb${suffix}" --version
    run_app "${app_folder_path}/bin/${gcc_target_prefix}-gdb${suffix}" --config

    # This command is known to fail with 'Abort trap: 6' (SIGABRT)
    run_app "${app_folder_path}/bin/${gcc_target_prefix}-gdb${suffix}" \
      --nh \
      --nx \
      -ex='show language' \
      -ex='set language auto' \
      -ex='quit'
    
    if [ "${suffix}" == "-py3" ]
    then
      # Show Python paths.
      run_app "${app_folder_path}/bin/${gcc_target_prefix}-gdb${suffix}" \
        --nh \
        --nx \
        -ex='set pagination off' \
        -ex='python import sys; print(sys.prefix)' \
        -ex='python import sys; import os; print(os.pathsep.join(sys.path))' \
        -ex='quit'
    fi

    if [ ! -z "${suffix}" ]
    then
      local out=$("${app_folder_path}/bin/${gcc_target_prefix}-gdb${suffix}" \
        --nh \
        --nx \
        -ex='set pagination off' \
        -ex='python print("babu"+"riba")' \
        -ex='quit' | grep 'baburiba')
      if [ "${out}" == "baburiba" ]
      then
        echo
        echo "gdb${suffix} python print() functional."
      else
        echo
        echo "gdb${suffix} python print() not functional."
        exit 1
      fi
    fi
  )
}

# -----------------------------------------------------------------------------

function run_tests()
{
  local gcc_target_prefix="riscv-none-embed"

  test_binutils

  test_gcc

  test_gdb

  if [ "${has_gdb_py3}" == "y" ]
  then
    test_gdb "-py3"
  else
    echo
    echo ">>> gdb-py3 tests skipped."
  fi

  if [ "${node_platform}" == "linux" ]
  then
    echo
    echo "Checking the Python shared libraries."

    for file_path in $(find "${app_folder_path}" -name 'libpython*so*')
    do
      run_app file "${file_path}"
      run_app ldd -v "${file_path}" || true
    done
  fi
}

# -----------------------------------------------------------------------------
