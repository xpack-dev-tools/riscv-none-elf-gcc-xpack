# xPack GNU RISC-V Embedded GCC

This is the **xPack** version of the 
**GNU RISC-V Embedded GCC** toolchain.

For details, see 
[The xPack GNU RISC-V Embedded GCC](https://xpack.github.io/riscv-none-embed-gcc/) pages.

## Easy install

The **xPack RISC-V Embedded GCC** toolchain is also available as a 
binary [xPack](https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-embed-gcc) 
and can be conveniently installed with [xpm](https://www.npmjs.com/package/xpm):

```console
$ xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@8.2.0-3.1.1
```

For more details on how to install the toolchain, please see 
[How to install the RISC-V toolchain?](http://xpack.github.io/toolchain/riscv-bone-embed-gcc/install/) page.

## Compliance

Starting with 8.2.0-2, the xPack GNU RISC-V Embedded GCC (formerly 
GNU MCU Eclipse RISC-V GCC) follows
the official [SiFive releases](https://github.com/sifive/freedom-tools/releases), 
with as little differences as possible.

This release is based on the 
[v2019.05.0](https://github.com/sifive/freedom-tools/releases/tag/v2019.05.0) 
release, and includes the SiFive extensions (like CLIC interrupts).

The following commits (from [sifive/freedom-tools](https://github.com/sifive/freedom-tools/tree/master/src)) were used:

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
`git://sourceware.org/git/binutils-gdb.git`, the `9b40759` commit from 
28 Feb 2019.

## Changes

Compared to the original SiFive version, the **same architecture and API** 
options are supported, and there are minimal functional changes 

- `libgloss` was removed from the list of libraires always linked to the 
  application, since it issues `ECALL`
  instructions that fail in bare metal environments
- `march=rv32imaf/mabi=ilp32f` was added to the list of multilibs

## newlib-nano

Support for **newlib-nano** is available using the 
`--specs=nano.specs` option. For better results, this option must be 
added to both compile and link time.

## nosys.specs

If no syscalls are needed, `--specs=nosys.specs` can be used at link 
time to provide empty implementations for the POSIX system calls.

## Compile options

The libraries are compiled with `-O2 -mcmodel=medany`. The nano version is
compiled with `-Os -mcmodel=medany`.

> Important: It is mandatory for the applications to be compiled with 
`-mcmodel=medany`, otherwise the link will fail.

## Documentation

The original PDF documentation is available in the `share/doc` folder.

## Support

For support, please read the 
[support](https://xpack.github.io/riscv-none-embed-gcc/support/) page.

## More info

For more info, please see the xPack project site:

  http://xpack.github.io/riscv-none-embed-gcc


Thank you for using open source software,

Liviu Ionescu

