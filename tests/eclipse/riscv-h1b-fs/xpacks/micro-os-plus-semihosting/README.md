## The µOS++ semihosting support

This project provides support for semihosting.

Although initially an ARM solution, it is quite portable and can be used on other architectures too.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Prerequisites

A recent [`xpm`](https://www.npmjs.com/package/xpm), which is a portable [Node.js](https://nodejs.org/) command line application.

Compiling the source code requires a modern C++ compiler, preferably GCC 5 or higher. 

### Easy install

This package is available as [`@micro-os-plus/semihosting`](https://www.npmjs.com/package/@micro-os-plus/semihosting) from the `npmjs.com` registry; with `xpm` available, installing the latest version of the package is quite easy:

```console
$ xpm install @micro-os-plus/semihosting
```

This package is also available from [GitHub](https://github.com/micro-os-plus/semihosting-xpack):

```console
$ git clone https://github.com/micro-os-plus/semihosting-xpack.git semihosting-xpack.git
```

### C++ API

The following functions are available:

```c++
namespace os
{
  namespace semihosting
  {
    int
    call_host (int reason, void* arg);
  } 
} 
```

### C API

All C++ functions have C equivalents:

```c
  static int
  os_semihosting_call_host (int reason, void* arg);

```


### Implementation

The architecture should provide a definition of the following function:

```c
  static inline int
  __attribute__ ((always_inline))
  os_semihosting_call_host (int reason, void* arg);
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
