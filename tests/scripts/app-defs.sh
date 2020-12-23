
# -----------------------------------------------------------------------------
# This file is part of the xPack distribution.
#   (https://xpack.github.io)
# Copyright (c) 2020 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software 
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# Appliction specific definitions, common to multiple scripts.

# -----------------------------------------------------------------------------

app_lc_name="riscv-none-embed-gcc"
app_description="xPack RISC-V Embed GCC "

github_org="xpack-dev-tools"
github_repo="riscv-none-embed-gcc-xpack"
github_pre_releases="pre-releases"

branch="xpack-develop"

version="$(cat $(dirname $(dirname ${script_folder_path}))/scripts/VERSION)"

base_url="https://github.com/${github_org}/${github_repo}/releases/download/v${version}/"
# base_url="https://github.com/${github_org}/${github_pre_releases}/releases/download/test/"
# base_url="https://github.com/${github_org}/${github_pre_releases}/releases/download/experimental/"

npm_package="@xpack-dev-tools/riscv-none-embed-gcc@next"

# -----------------------------------------------------------------------------
