#!/bin/sh
# Copyright (c) 2017, ARM Limited
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#     * Redistributions of source code must retain the above copyright notice,
#       this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of Arm nor the names of its contributors may be used
#       to endorse or promote products derived from this software without
#       specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.


# Windows Python configuration script
#
# As per comment regarding --with-python in gdb/configure.ac, this script
# follows the interface of gdb/python/python-config.py but return path
# related to Windows Python.

if [ ! -d "${GNURM_PYTHON_WIN_DIR}" ]; then
  exit 1
fi

GNURM_PYTHON_WIN_DIR="$(readlink -f ${GNURM_PYTHON_WIN_DIR})"

while [ $# -ge 1 ]; do
  opt="$1"
  case ${opt} in
    --prefix)
      echo "${GNURM_PYTHON_WIN_DIR}";;
    --exec-prefix)
      echo "${GNURM_PYTHON_WIN_DIR}";;
    --includes|--cflags)
      cflags="-I${GNURM_PYTHON_WIN_DIR}"
      if [ "${opt}" = "--cflags" ]; then
        cflags="${cflags} ${CFLAGS}"
      fi
      echo ${cflags};;
    --libs|--ldflags)
      # Options to link to static libpython2.7 archive so as to avoid  an
      # external dependency on python
      echo "-L${GNURM_PYTHON_WIN_DIR} -lpython27";;
    --*)
      echo "Unknown option: ${opt}" >&2
      exit 1;;
    *)
      # Ignore non options since we are called with gdb provided
      # python-config.py as first parameter
      ;;
  esac
  shift
done

exit 0
