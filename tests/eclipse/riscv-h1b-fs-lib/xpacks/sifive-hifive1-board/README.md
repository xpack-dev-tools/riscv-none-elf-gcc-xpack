## SiFive HiFive1 board specific files

This project provides support for the SiFive HiFive1 development board.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Prerequisites

A recent [`xpm`](https://www.npmjs.com/package/xpm), which is a portable [Node.js](https://nodejs.org/) command line application.

Compiling the source code requires a modern C++ compiler, preferably GCC 5 or higher. 

### Easy install

This package is available as [`@sifive/hifive1-board`](https://www.npmjs.com/package/@sifive/hifive1-board) from the `npmjs.com` registry; with `xpm` available, installing the latest version of the package is quite easy:

```console
$ xpm install @sifive/hifive1-board
```

This package is also available from [GitHub](https://github.com/micro-os-plus/sifive-hifive1-board-xpack):

```console
$ git clone https://github.com/micro-os-plus/sifive-hifive1-board-xpack.git sifive-hifive1-board-xpack.git
```

### How to use

The standard way to include the board files is

```c
#include <micro-os-plus/board.h>
```

### Macros

* `SIFIVE_HIFIVE1_BOARD`

## Maintainer info

### How to publish

* commit all changes
* update `CHANGELOG.md`; commit with a message like _CHANGELOG: prepare v0.1.2_
* `npm version patch`
* push all changes to GitHub
* `npm publish`

## License

The original content is released under the [MIT License](https://opensource.org/licenses/MIT), with all rights reserved to [Liviu Ionescu](https://github.com/ilg-ul).
