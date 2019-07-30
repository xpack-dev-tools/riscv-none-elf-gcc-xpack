## µOS++ complementary C library functions

These are some files that complement or extend the C library:

- `c-syscalls-empty.c` define weak empty syscalls to keep the linker happy; redefine those needed for retargeted configurations;
- `_sbrk.c` allocates block of memory in the free store (the heap) at the end of RAM, up to the stack; must match the definitons in the linker script;
- `stdlib/assert.c` defines the function to be called when assertions are taken;
- `stdlib/atexit.cpp` defines a simple registry for functions to be called when the program is terminated; useful for semihosting applications that terminate normally; the size of the static array is `OS_INTEGER_ATEXIT_ARRAY_SIZE`, default 3;
- `stdlib/exit.c` defines the functionality of `exit()` and `abort()`
- `stdlib/init-fini.c` defines weak empty `_init()` and `_fini()`, to keep linker happy.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Prerequisites

A recent [`xpm`](https://www.npmjs.com/package/xpm), which is a portable [Node.js](https://nodejs.org/) command line application.

### Easy install

This package is available as [`@micro-os-plus/c-libs`](https://www.npmjs.com/package/@micro-os-plus/c-libs) from the `npmjs.com` registry; with `xpm` available, installing the latest version of the package is quite easy:

```console
$ xpm install @micro-os-plus/c-libs
```

This package is also available from [GitHub](https://github.com/micro-os-plus/c-libs-xpack):

```console
$ git clone https://github.com/micro-os-plus/c-libs-xpack.git c-libs-xpack.git
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

