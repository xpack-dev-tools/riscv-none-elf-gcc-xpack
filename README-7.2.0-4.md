# GNU MCU Eclipse RISC-V Embedded GCC

This is the **GNU MCU Eclipse** (formerly GNU ARM Eclipse) version of the 
**RISC-V Embedded GCC** toolchain.

## Compliance

This release closely follows the official 
[RISC-V distribution](https://github.com/riscv/riscv-gcc) maintained by 
[SiFive](https://www.sifive.com).

By the date of this release, the `riscv-gcc-7.3.0` branch is not yet 
stable, thus the current version is still based on GCC 7.2, using the 
following commits:

- the [riscv/riscv-gcc](https://github.com/riscv/riscv-gcc) project, 
branch `riscv-gcc-7.2.0`, commit
[36e932c](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/commit/36e932c683490ddfa5225ad8d842b002a8a74ed4)
from from Jan 16th, 2018
- the [riscv/riscv-binutils-gdb](https://github.com/riscv/riscv-binutils-gdb) 
project, branch `riscv-binutils-2.29`, commit 
[f60a065](https://github.com/gnu-mcu-eclipse/riscv-binutils-gdb/commit/f60a065a25cc54169a34ed351931097a44703a5c)
from May 3rd, 2018
- the [riscv/riscv-newlib](https://github.com/riscv/riscv-newlib) project,
commit [1e50b13](https://github.com/gnu-mcu-eclipse/riscv-newlib/commit/1e50b130fe1514a96eb4dc12f4a661d14f5cf6d4)
from Feb 27th, 2018

## Changes

Compared to the original RISC-V version, the **same architecture and API** 
options are supported, and there are minimal functional changes 

* newlib-nano is supported
* `march=rv32imaf/mabi=ilp32f` was added to the list of multilibs

## newlib-nano

The only notable addition is support for **newlib-nano**, using the 
`--specs=nano.specs` option. For better results, this option must be 
added to both compile and link time (the next release of the GNU MCU 
Eclipse plug-ins will add support for this).

If no syscalls are needed, `--specs=nosys.specs` can be used at link 
time to provide empty implementations for the POSIX system calls.

The libraries are compiled with `-O2 -mcmodel=medany`.

## Documentation

Another addition compared to the SiFive distribution is the presence 
of the documentation, including the PDF manuals for all tools.

## Support

For issues related to the procedure used to build the 
GNU MCU Eclipse RISC-V Embedded GCC binaries, please report them via 
[gnu-mcu-eclipse/riscv-none-gcc-build GitHub Issues](https://github.com/gnu-mcu-eclipse/riscv-none-gcc-build/issues).

For issues related to the xPack used to install the binaries, 
please report them via
[gnu-mcu-eclipse/riscv-none-gcc-xpack GitHub issues](https://github.com/gnu-mcu-eclipse/riscv-none-gcc-xpack/issues).

For issues related to the toolchain functionality (compiler, newlib
gdb, etc) please report them via their original RISC-V projects:

- [riscv/riscv-gcc](https://github.com/riscv/riscv-gcc/issues)
- [riscv/riscv-newlib](https://github.com/riscv/riscv-newlib/issues)
- [riscv/riscv-binutils-gdb](https://github.com/riscv/riscv-binutils-gdb/issues)

## More info

For more info and support, please see the GNU MCU Eclipse project pages from:

  http://gnu-mcu-eclipse.github.io


Thank you for using **GNU MCU Eclipse**,

Liviu Ionescu

