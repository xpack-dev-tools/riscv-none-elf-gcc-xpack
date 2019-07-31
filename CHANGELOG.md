
## Change & release log

Releases in reverse chronological order.

### 2019-07-31

- v8.2.0-3.1.1 published on npmjs.com 
- v8.2.0-3.1 released 
- update to follow SiFive May 2019 release

___

## Historical GNU MCU Eclipse change log

### 2019-05-22

- v8.2.0-2.2 released
- fix GDB build on macOS (use clang)
- add compiler tests
- add gdb set language tests

### 2019-04-25

- v8.2.0-2.1 released

### 2019-04-17

- prepare v8.2.0-2 (8.2.0-1 was skipped)
- update to the latest SiFive commits
  - `sifive-binutils-2.32`
  - `sifive-gcc-8.2.0`
  - `sifive-newlib-3.0.0`
- for GDB use the FSF c8aa0bb (28 Feb 2019)
- update for XBB v2.1; no need for static, libs are ok.
- the defaults were changed to rv32imac/ilp32

### 2018-10-19

- v8.1.0-2-20181019 released

### 2018-10-18

- prepare v8.1.0-2-*
- update to latest SiFive commits from the following branches:
  - riscv-binutils-2.30
  - riscv-gcc-8.1.0
  - riscv-newlib-3.0.0
- allow GDB to be built from a separate repo/commit

### 2018-06-06

- v7.2.0-4-20180606 released
- add -mcmodel=medany, lost during updates

### 2018-05-06

- v7.2.0-3-20180506 released
- update to latest SiFive commits from the following branches:
  - riscv-binutils-2.29
  - riscv-gcc-7.2.0
  - riscv-newlib-2.5.0

### 2018-05-04

- update the build scripts to follow the ARM XBB structure 

### 2018-01-10

- v7.2.0-2-20180110 released
- update to latest SiFive commits from 2018-01-10
- dismiss the `data-list-register-names` patch, no longer needed

### 2017-11-09

- v7.2.0-1-20171109 released
- update to latest SiFive 2017-11-07 released, except newlib, where the 
reference was too old, and a recent commit was used
- in GDB, the list of registers returned by `data-list-register-names` 
no longer include the 4096 CSRs
- the tuple was renamed to `riscv-none-embed-`

### 2017-09-12

- v7.1.1-2-20170912 released
- add multilib support for rv32imaf/ilp32f
- remove mandatory link of libgloss

### 2017-07-02

- v7.1.1-1-20170702-0625 released

### 2017-06-27

- add support for `--specs=nano.specs`; this translates into a separate 
build for `newlib` with specific configuration options and a separate 
build of the C++ standard libraries with `-Os`.

