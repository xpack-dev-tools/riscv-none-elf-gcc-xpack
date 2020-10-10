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
$ xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@8.3.0-1.2.1
```

For more details on how to install the toolchain, please see
[How to install the RISC-V toolchain?](http://xpack.github.io/toolchain/riscv-bone-embed-gcc/install/) page.

## Compliance

Starting with 8.2.0-2, the xPack GNU RISC-V Embedded GCC (formerly
GNU MCU Eclipse RISC-V GCC) follows
the official [SiFive releases](https://github.com/sifive/freedom-tools/releases),
with as little differences as possible.

This release is based on the
[v2020.04.0-Toolchain.Only](https://github.com/sifive/freedom-tools/releases/tag/v2020.04.0-Toolchain.Only)
release, and includes the SiFive extensions.

The following commits (from [sifive/freedom-tools](https://github.com/sifive/freedom-tools/tree/v2020.04.0-Toolchain.Only)) were used:

- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
project, branch `sifive-binutils-2.32`, commit
[ac7ecc4](https://github.com/sifive/riscv-binutils-gdb/tree/ac7ecc464d0b0466c056a29e357da0f38aec4705)
from 3 Feb 2020
- the [sifive/riscv-gcc](https://github.com/sifive/riscv-gcc) project,
branch `sifive-gcc-8.3.0`, commit
[e195042](https://github.com/sifive/riscv-gcc/tree/e195042babe2dc30d9fabb88d336d8c8679b3702)
from from 7 Aug 2019
- the [sifive/riscv-newlib](https://github.com/sifive/riscv-newlib) project, the `fix-S5CSD-1486` branch,
commit [6c668f8](https://github.com/sifive/riscv-newlib/tree/6c668f856bdd678ac1885aa07ffcfcc7483221b8)
from 6 Dec 2019
- the [sifive/riscv-binutils-gdb](https://github.com/sifive/riscv-binutils-gdb)
project, branch `gdb-8.3-release-cache-control-patch`, commit
[ac7ecc4](https://github.com/sifive/riscv-binutils-gdb/tree/62a5c5e36b338bd15c7671332bb49c4ef1e5db15)
from 3 Feb 2020

## Changes

Compared to the original SiFive version, the **same architecture and API**
options are supported, and there are minimal functional changes

- `libgloss` was removed from the list of libraires always linked to the
  application, since it issues `ECALL`
  instructions that fail in bare metal environments

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

## Python

Support for Python in GDB is provided via a separate binary,
`riscv-none-embed-gdb-py3`. It requires a Python 3.7 installed
on the development machine.

For more details, please see the
[GDB with Python support](https://xpack.github.io/arm-none-eabi-gcc/python/)
page.

## Documentation

The original PDF documentation is available in the `share/doc` folder.

## Support

For support, please read the
[support](https://xpack.github.io/riscv-none-embed-gcc/support/) page.

## More info

For more details, please read the corresponding release page:

- https://xpack.github.io/riscv-none-embed-gcc/releases/

Thank you for using open source software,

Liviu Ionescu
