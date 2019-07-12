# GNU MCU Eclipse RISC-V Embedded GCC

This is the **GNU MCU Eclipse** (formerly GNU ARM Eclipse) version of the 
**RISC-V Embedded GCC** toolchain.

## Compliance

Starting with 8.2.0-2, the GNU MCU Eclipse RISC-V GCC follows
the official [SiFive releases](https://github.com/sifive/freedom-tools/releases), 
with as little differences as possible. Previously it followed the generic
[RISC-V releases](https://github.com/riscv/riscv-gnu-toolchain/releases).

This release is based on the 
[v2019.02.0](https://github.com/sifive/freedom-tools/releases/tag/v2019.02.0) 
release, and includes the SiFive extensions (like CLIC interrupts).

The following commits were used:

- the [sifive/riscv-gcc](https://github.com/sifive/riscv-gcc) project, 
branch `sifive-gcc-8.2.0`, commit
[242abcaff6](https://github.com/sifive/riscv-gcc/tree/242abcaff697d0a1ea12dccc975465e1bfeb8331)
from from 5 April 2019
- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb) 
project, branch `sifive-binutils-2.32`, commit 
[164267155c](https://github.com/sifive/riscv-binutils-gdb/tree/164267155c96f91472a539ca78ac919993bc5b4e)
from 28 February 2019
- the [sifive/riscv-newlib](https://github.com/sifive/riscv-newlib) project,
commit [42c2e3fb9f](https://github.com/sifive/riscv-newlib/tree/42c2e3fb9f557d59b76d1a64bb6fb32707ff4530)
from 17 November 2018

GDB was upstreamed and does not require SiFive specific patches, 
so the current build uses 
`git://sourceware.org/git/binutils-gdb.git`, the `c8aa0bb` commit from 
28 Feb 2019.

## Changes

Compared to the original RISC-V version, the **same architecture and API** 
options are supported, and there are minimal functional changes 

* newlib-nano is supported
* `march=rv32imaf/mabi=ilp32f` was added to the list of multilibs

## newlib-nano

Support for **newlib-nano** is available using the 
`--specs=nano.specs` option. For better results, this option must be 
added to both compile and link time.

If no syscalls are needed, `--specs=nosys.specs` can be used at link 
time to provide empty implementations for the POSIX system calls.

The libraries are compiled with `-O2 -mcmodel=medany`.

Warning: It is mandatory for the applications to be compiled with 
`-mcmodel=medany`, otherwise the link will fail.

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

- [sifive/riscv-gcc](https://github.com/sifive/riscv-gcc/issues)
- [sifive/riscv-newlib](https://github.com/sifive/riscv-newlib/issues)
- [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb/issues)

## More info

For more info and support, please see the GNU MCU Eclipse project pages from:

  http://gnu-mcu-eclipse.github.io


Thank you for using **GNU MCU Eclipse**,

Liviu Ionescu

