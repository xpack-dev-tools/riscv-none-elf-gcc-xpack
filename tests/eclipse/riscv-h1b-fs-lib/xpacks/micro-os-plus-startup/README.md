## The µOS++ portable startup code for bare-metal platforms

This project provides a portable startup code for bare-metal platforms.

The myth that startup code must be written in assembly because 'the C environment is not ready' is plainly wrong.

The 'C environment' is mainly the stack (and maybe other architecture ABI registers, like GP on RISC-V), and this can be set in a short assembly entry code and then the standard `_start()` function can be safely called.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Prerequisites

A recent [`xpm`](https://www.npmjs.com/package/xpm), which is a portable [Node.js](https://nodejs.org/) command line application.

Compiling the source code requires a modern C++ compiler, preferably GCC 5 or higher. 

### Easy install

This package is available as [`@micro-os-plus/startup`](https://www.npmjs.com/package/@micro-os-plus/startup) from the `npmjs.com` registry; with `xpm` available, installing the latest version of the package is quite easy:

```console
$ xpm install @micro-os-plus/startup
```

This package is also available from [GitHub](https://github.com/micro-os-plus/startup-xpack):

```console
$ git clone https://github.com/micro-os-plus/startup-xpack.git startup-xpack.git
```
## Maintainer info

### How to publish

* commit all changes
* update `CHANGELOG.md`; commit with a message like _CHANGELOG: prepare v0.1.2_
* `npm version patch`
* push all changes to GitHub
* `npm publish`

## License

The original content is released under the [MIT License](https://opensource.org/licenses/MIT), with all rights reserved to [Liviu Ionescu](https://github.com/ilg-ul).

