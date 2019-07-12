# GNU MCU Eclipse RISC-V Embedded GCC

This is the **GNU MCU Eclipse** (formerly GNU ARM Eclipse) version of the 
**RISC-V Embedded GCC** toolchain.

## Compliance

This release closely follows the official 
[RISC-V distribution](https://github.com/riscv/riscv-gcc) maintained by 
[SiFive](https://www.sifive.com).

It is more or less similar to the 20180928 release, except support for 
SiFive specific CLIC interrupts, which was not included.

The following commits were used:

- the [riscv/riscv-gcc](https://github.com/riscv/riscv-gcc) project, 
branch `riscv-gcc-8.1.0`, commit
[3c148a7e6ea](https://github.com/gnu-mcu-eclipse/riscv-none-gcc/commit/3c148a7e6ea1379e3a8e8b5350ec03a72e5d4137)
from from July 3rd, 2018
- the [riscv/riscv-binutils-gdb](https://github.com/riscv/riscv-binutils-gdb) 
project, branch `riscv-binutils-2.30`, commit 
[0d2fb1b7ff](https://github.com/gnu-mcu-eclipse/riscv-binutils-gdb/commit/0d2fb1b7ff9b94e40352306f1f8857b863c6f787)
from Aug 11th, 2018
- the [riscv/riscv-newlib](https://github.com/riscv/riscv-newlib) project,
commit [77e11e180](https://github.com/gnu-mcu-eclipse/riscv-newlib/commit/77e11e1800f57cac7f5468b2bd064100a44755d4)
from July 12th, 2018

GDB is a bit special, since it is only partly upstreamed and the RISC-V repos 
are no longer updated, so the current build uses 
`git://sourceware.org/git/binutils-gdb.git`, the `7dd36a6f1c` commit from 
Aug 23rd, 2018 (same as the SiFive release).

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

