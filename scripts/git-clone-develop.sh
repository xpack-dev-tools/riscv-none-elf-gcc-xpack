#!/usr/bin/env bash
rm -rf "${HOME}/Downloads/riscv-none-embed-gcc-xpack.git"
git clone --branch xpack-develop --recurse-submodules https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git "${HOME}/Downloads/riscv-none-embed-gcc-xpack.git"
