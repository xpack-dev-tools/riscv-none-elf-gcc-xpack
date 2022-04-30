# -----------------------------------------------------------------------------
# This file is part of the xPacks distribution.
#   (https://xpack.github.io)
# Copyright (c) 2020 Liviu Ionescu.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
# -----------------------------------------------------------------------------

# Helper script used in the xPack Dev Tools build scripts.
# As the name implies, it should contain only functions and
# should be included with 'source' by the container build scripts.

# -----------------------------------------------------------------------------

function generate_multilib_file()
{
  # Not inside the previous if to allow multilib changes after download.
  if [ "${WITHOUT_MULTILIB}" != "y" ]
  then
    (
      echo
      echo "Running the multilib generator..."

      cd "${SOURCES_FOLDER_PATH}/${GCC_SRC_FOLDER_NAME}/gcc/config/riscv"

      xbb_activate_installed_dev

      GCC_MULTILIB_FILE=${GCC_MULTILIB_FILE:-"t-elf-multilib"}

      # Be sure the ${GCC_MULTILIB} has no quotes, since it defines
      # multiple strings.

      # Change IFS temporarily so that we can pass a simple string of
      # whitespace delimited multilib tokens to multilib-generator
      local IFS=$' '
      echo
      echo "[python3 ./multilib-generator ${GCC_MULTILIB}]"
      python3 ./multilib-generator ${GCC_MULTILIB} > "${GCC_MULTILIB_FILE}"

      echo "----------------------------------------------------------------"
      cat "${GCC_MULTILIB_FILE}"
      echo "----------------------------------------------------------------"
    )
  fi
}


# -----------------------------------------------------------------------------
