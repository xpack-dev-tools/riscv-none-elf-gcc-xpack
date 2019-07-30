## µOS++ complementary C++ library functions

These are some files that complement or extend the C++ library:

- `cxx.cpp` add explicit handlers for C++ API functions, to be sure no othe heavy implementations are pulled from the (huge) standard library.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Prerequisites

A recent [`xpm`](https://www.npmjs.com/package/xpm), which is a portable [Node.js](https://nodejs.org/) command line application.

### Easy install

This package is available as [`@micro-os-plus/cpp-libs`](https://www.npmjs.com/package/@micro-os-plus/cpp-libs) from the `npmjs.com` registry; with `xpm` available, installing the latest version of the package is quite easy:

```console
$ xpm install @micro-os-plus/cpp-libs
```

This package is also available from [GitHub](https://github.com/micro-os-plus/cpp-libs-xpack):

```console
$ git clone https://github.com/micro-os-plus/cpp-libs-xpack.git cpp-libs-xpack.git
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
