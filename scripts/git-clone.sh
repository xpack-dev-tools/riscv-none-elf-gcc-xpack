#!/usr/bin/env bash
rm -rf "${HOME}/Downloads/riscv-none-gcc-build.git"
git clone --recurse-submodules https://github.com/gnu-mcu-eclipse/riscv-none-gcc-build.git "${HOME}/Downloads/riscv-none-gcc-build.git"
