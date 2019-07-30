## SiFive device specific files

This project provides support for SiFive RISC-V microcontrollers.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Prerequisites

A recent [`xpm`](https://www.npmjs.com/package/xpm), which is a portable [Node.js](https://nodejs.org/) command line application.

Compiling the source code requires a modern C++ compiler, preferably GCC 5 or higher. 

### Easy install

This package is available as [`@sifive/devices`](https://www.npmjs.com/package/@sifive/devices) from the `npmjs.com` registry; with `xpm` available, installing the latest version of the package is quite easy:

```console
$ xpm install @sifive/devices
```

This package is also available from [GitHub](https://github.com/micro-os-plus/sifive-devices-xpack):

```console
$ git clone https://github.com/micro-os-plus/sifive-devices-xpack.git sifive-devices-xpack.git
```

### How to use

The standard way to include the device files is

```c
#include <micro-os-plus/device.h>
```

### Macros

* `SIFIVE_FE310`
* `SIFIVE_E31ARTY`
* `SIFIVE_E51ARTY`

### Known problems

* the `os_terminate()` function is not fully implemented, it must use either the Watchdog or PMU+RTC to trigger a system reset.

## Maintainer info

### How to publish

* commit all changes
* update `CHANGELOG.md`; commit with a message like _CHANGELOG: prepare v0.1.2_
* `npm version patch`
* push all changes to GitHub
* `npm publish`

## License

The original content is released under the [MIT License](https://opensource.org/licenses/MIT), with all rights reserved to [Liviu Ionescu](https://github.com/ilg-ul).

