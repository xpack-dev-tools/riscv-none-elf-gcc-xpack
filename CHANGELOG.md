
# Change & release log

Entries in this file are in reverse chronological order.

## 2022-08-29

- v12.2.0-1.1 published on npmjs.com
- v12.2.0-1 released

## 2022-08-28

- v12.2.0-1 prepared

## 2022-05-18

- v12.1.0-2.1 published on npmjs.com
- v12.1.0-2 released

## 2022-05-17

- v12.1.0-2 prepared
- patch nano.specs to use C++ nano libraries

## 2022-05-15

- v12.1.0-1.1 published on npmjs.com
- v12.1.0-1 released
- tests/eclipse update -march=rv32imac_zicsr

## 2022-05-14

- v12.1.0-1 prepared
- v11.3.0-1.1 published on npmjs.com
- v11.3.0-1 released
- bump gdb to 12.1, with patch

## 2022-04-22

- v11.3.0-1 prepared

## 2021-11-23

- v10.2.0-1.3 prepared, try to add support for Apple Silicon

## 2021-11-11

- v10.2.0-1.2.1 published on npmjs.com
- v10.2.0-1.2 released

## 2021-11-09

- v10.2.0-1.2 prepared
- [#12] - add non-C libraries
- [#11] - avoid `-g` for libraries

## 2021-11-06

- v10.2.0-1.1.1 published on npmjs.com
- v10.2.0-1.1 released

## 2021-11-05

- v10.2.0-1.1 prepared, based on SiFive v2020.12.0

## 2021-11-04

- v10.1.0-1.2 published on npmjs.com
- v10.1.0-1.2 released

## 2021-11-02

- v10.1.0-1.2 prepared
- update for new helper & XBB v3.3

## 2021-01-05

- v10.1.0-1.1 published on npmjs.com
- v10.1.0-1.1 released

## 2020-12-23

- v10.1.0-1.1 prepared

## 2020-10-25

- v8.3.0-2.3.1 published on npmjs.com
- v8.3.0-2.3 released

## 2020-10-24

- v8.3.0-2.3 prepared

## 2020-10-13

- v8.3.0-2.2.1 published on npmjs.com
- v8.3.0-2.2 released

## 2020-10-11

- v8.3.0-2.2 prepared

## 2020-10-10

- v8.3.0-2.1.1 published on npmjs.com
- v8.3.0-2.1 released

## 2020-10-09

- Python2 support discontinued (building with recent mingw-w64 is not possible)

## 2020-10-08

- v8.3.0-1.2 prepared
- update to follow SiFive 2020.04.0 release

## 2020-10-06

- update for new Python tricks

## 2020-07-04

- v8.3.0-1.2.1 published on npmjs.com
- v8.3.0-1.2 released

## 2019-11-01

- v8.3.0-1.1.1 published on npmjs.com
- v8.3.0-1.1 released

## 2019-10-30

- v8.3.0-1.1 prepared
- update to follow SiFive 2019.08.0 release

## 2019-07-31

- v8.2.0-3.1.1 published on npmjs.com
- v8.2.0-3.1 released
- update to follow SiFive May 2019.05.0 release

___

# Historical GNU MCU Eclipse change log

## 2019-05-22

- v8.2.0-2.2 released
- fix GDB build on macOS (use clang)
- add compiler tests
- add gdb set language tests

## 2019-04-25

- v8.2.0-2.1 released

## 2019-04-17

- prepare v8.2.0-2 (8.2.0-1 was skipped)
- update to the latest SiFive commits
  - `sifive-binutils-2.32`
  - `sifive-gcc-8.2.0`
  - `sifive-newlib-3.0.0`
- for GDB use the FSF c8aa0bb (28 Feb 2019)
- update for XBB v2.1; no need for static, libs are ok.
- the defaults were changed to rv32imac/ilp32

## 2018-10-19

- v8.1.0-2-20181019 released

## 2018-10-18

- prepare v8.1.0-2-*
- update to latest SiFive commits from the following branches:
  - riscv-binutils-2.30
  - riscv-gcc-8.1.0
  - riscv-newlib-3.0.0
- allow GDB to be built from a separate repo/commit

## 2018-06-06

- v7.2.0-4-20180606 released
- add -mcmodel=medany, lost during updates

## 2018-05-06

- v7.2.0-3-20180506 released
- update to latest SiFive commits from the following branches:
  - riscv-binutils-2.29
  - riscv-gcc-7.2.0
  - riscv-newlib-2.5.0

## 2018-05-04

- update the build scripts to follow the ARM XBB structure

## 2018-01-10

- v7.2.0-2-20180110 released
- update to latest SiFive commits from 2018-01-10
- dismiss the `data-list-register-names` patch, no longer needed

## 2017-11-09

- v7.2.0-1-20171109 released
- update to latest SiFive 2017-11-07 released, except newlib, where the
reference was too old, and a recent commit was used
- in GDB, the list of registers returned by `data-list-register-names`
no longer include the 4096 CSRs
- the tuple was renamed to `riscv-none-embed-`

## 2017-09-12

- v7.1.1-2-20170912 released
- add multilib support for rv32imaf/ilp32f
- remove mandatory link of libgloss

## 2017-07-02

- v7.1.1-1-20170702-0625 released

## 2017-06-27

- add support for `--specs=nano.specs`; this translates into a separate
build for `newlib` with specific configuration options and a separate
build of the C++ standard libraries with `-Os`.

