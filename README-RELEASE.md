# How to make a new release (maintainer info)

## Prepare the build

Before starting the build, perform some checks and tweaks.

### Check Git

- switch to the `xpack-develop` branch
- if needed, merge the `xpack` branch

### Identify SiFive commit IDs

- check the [SiFive Releases](https://github.com/sifive/freedom-tools/releases)
for new releases
- identify the tag of the latest release (like `v2019.08.0`)
- switch to Code view and select the tag
- open the `src` folder to identify the commit IDs used for the linked repos
- copy/paste the submodule links to common-versions-sources.sh
- get binutils version from binutils/CHANGELOG
- get gcc version from gcc/BASE_VER (gcc/ChangeLog)
- get newlib version from newlib/configure, VERSION= (newlib/README)
- get gdb version from gdb/VERSION.in (gdb/ChangeLog)

### Identify the main GCC version

Determine the GCC version (like `8.3.0`) and update the `scripts/VERSION`
  file; the format is `8.3.0-2.3`. The fourth digit is the number of the
  SiFive release of the same GCC version, and the fifth digit is the xPack
  GNU RISC-V Embedded GCC release number of this version.

### Update binutils

With Sourcetree in
[xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)

Check if there is a `sifive` remote pointing to
https://github.com/sifive/riscv-binutils-gdb.

If the changes apply to an existing branch:

- checkout the current SiFive branch (like `sifive-binutils-2.32`)
- merge the commit with the desired ID from the corresponding branch in
the `sifive` remote
- checkout the corresponding xpack branch (like `sifive-binutils-2.32-xpack`)
- merge the previous merge
- check the differences from the non-xpack branch; it should be only the
addition of `embed)` in `config.sub`

If the changes are on a new branch (most likely):

- from the `sifive` remote
checkout the new SiFive branch (like `sifive-binutils-2.32`) into a new local
branch
- identify the commit ID and switch to it
- create a new branch with a similar name, but suffixed by `-xpack`
(like `sifive-binutils-2.32-xpack`)
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
which adds `-embed)`
- commit as **add support for riscv-none-embed-***

In both cases:

- push the two modified branches (like `sifive-binutils-2.32` and
`sifive-binutils-2.32-xpack`)
- add a tag with the current version (like `v8.3.0-2.3`), and push
it to `origin`

- copy/paste the branch name and commit id tp common-versions-source.sh

### Update gcc

With Sourcetree in
[xpack-dev-tools/riscv-gcc](https://github.com/xpack-dev-tools/riscv-gcc)

Check if there is a `sifive` remote pointing to
https://github.com/sifive/riscv-gcc.

If the changes apply to an existing branch:

- checkout the current SiFive branch (like `sifive-gcc-8.3.0`)
- merge the commit with the desired ID from the corresponding branch in
the `sifive` remote
- checkout the corresponding xpack branch (like `sifive-gcc-8.3.0-xpack`)
- merge the previous merge
- check the differences from the non-xpack branch; there should be tree files:
  - `elf-embed.h` with the `LIB_SPEC` definitions without libgloss
  - `config.gcc` with `tm_file` definition that uses `elf-embed.h`
  - `config.sub` which adds `riscv0*)` and `-embed)`

If this is a new branch:

- from the `sifive` remote
checkout the new SiFive branch (like `sifive-gcc-8.3.0`) into a new local
branch
- identify the commit ID and switch to it
- create a new branch with a similar name, but suffixed by `-xpack`
(like `sifive-gcc-8.3.0-xpack`)
- identify the commit which adds the xPaack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be tree files:
  - `elf-embed.h` with the `LIB_SPEC` definitions without libgloss
  - `config.gcc` with `tm_file` definition that uses `elf-embed.h`
  - `config.sub` which adds `riscv0*)` and `-embed)`
- commit as **add support for riscv-none-embed-***

In both cases:

- push the two modified branches (like `sifive-gcc-8.3.0` and
`sifive-gcc-8.3.0-xpack`)
- add a tag with the current version (like `v8.3.0-2.3`), and push
it to `origin`.

### Update newlib

With Sourcetree in
[xpack-dev-tools/riscv-newlib](https://github.com/xpack-dev-tools/riscv-newlib)

Check if there is a `sifive` remote pointing to
https://github.com/sifive/riscv-newlib.

If the changes apply to an existing branch:

- checkout the current SiFive branch (like `master`)
- merge the commit with the desired ID from the corresponding branch in
the `sifive` remote
- checkout the corresponding xpack branch (like `sifive-binutils-2.32-xpack`)
- merge the previous merge
- check the differences from the non-xpack branch; it should be only the
addition of `embed)` in `config.sub`

- from the `sifive` remote
checkout the new SiFive branch (like `master`) into a new local
branch (like `sifive-master`)
- identify the commit ID and switch to it
- create a new branch with a similar name, but suffixed by `-xpack`
(like `sifive-master-xpack`)
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
which adds `-embed)`
- commit as **add support for riscv-none-embed-***

In both cases:

- push the two modified branches (like `sifive--master` and
`sifive--master-xpack`)
- add a tag with the current version (like `v8.3.0-2.3`), and push
it to `origin`.

### Update gdb

With Sourcetree in
[xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)

Check if there is a `gdb` remote pointing to
git://sourceware.org/git/binutils-gdb.git.

For GDB, it is a bit tricky, since it must identify the GNU code in line
with what was used by SiFive; create a branch like `sifive-gdb-8.3`

- branch it into `sifive-gdb-8.3-xpack` and edit the prefix code
- add a tag like `v8.3.0-2.3-gdb`

### Increase the version

Determine the GCC version (like `8.3.0`) and update the `scripts/VERSION`
file; the format is `8.3.0-2.3`. The fourth number is the xPack release number
of this version. A fifth number will be added when publishing
the package on the `npm` server.

### Fix possible open issues

Check GitHub issues and pull requests:

- https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues

and fix them; assign them to a milestone (like `8.3.0-2.3`).

### Check `README.md`

Normally `README.md` should not need changes, but better check.
Information related to the new version should not be included here,
but in the version specific file (below).

## Update `CHANGELOG.md`

- open the `CHANGELOG.md` file
- check if all previous fixed issues are in
- add a new entry like _v8.3.0-2.3 prepared_
- commit commit with a message like _CHANGELOG: prepare v8.3.0-2.3_

Note: if you missed to update the `CHANGELOG.md` before starting the build,
edit the file and rerun the build, it should take only a few minutes to
recreate the archives with the correct file.

### Update the version specific code

- open the `common-versions-source.sh` file
- add a new `if` with the new version before the existing code
- update `GH_RELEASE` to the new version (like `8.3.0-2.3`, without `v`)
- in SiFive [releases](https://github.com/sifive/freedom-tools/releases)
for new releases
- identify the tag of the latest release (like `v2019.08.0`)
- switch to Code view and select the tag
- open the `Makefile` file to identify the `MULTILIBS_GEN` definition;
- copy/paste it into `GCC_MULTILIB` (mind the tabs!)
- add `rv32imaf-ilp32f--` after `rv32imf-` (already in for recent versions)

### Update helper

With Sourcetree, go to the helper repo and update to the latest master commit.

## Build

Before starting the build, perform some checks.

### Check if repos are up-to-date

Be sure everything is committed and pushed

- `xpack-dev-tools/riscv-binutils-gdb.git`
- `xpack-dev-tools/riscv-gcc.git`
- `xpack-dev-tools/riscv-newlib.git`

### Check tags

The names should look like `v8.3.0-2.3`.

For the binutils-gdb repo, a separate tag like `v8.3.0-2.3-gdb` should be
present, for the GDB build.

### Development run the build scripts

Before the real build, run a test build on the development machine (`wks`):

```bash
sudo rm -rf ~/Work/riscv-none-embed-gcc-*

caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --develop --without-pdf --disable-tests --disable-multilib --linux64 --win64 --linux32 --win32
```

Work on the scripts until all 4 platforms pass the build.

### Push the build scripts

- push the `xpack-develop` branch to GitHub
- possibly push the helper project too

From here it'll be cloned on the production machines.

### Run the build scripts without multilibs

Move to the three production machines.

On the macOS build machine (`xbbm`):

- empty the trash bin
- create three new terminals

Connect to the Intel Linux (`xbbi`):

```bash
caffeinate ssh xbbi
```

Connect to the Arm Linux (`xbba`):

```bash
caffeinate ssh xbba
```

On all machines, clone the `xpack-develop` branch:

```bash
rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git; \
  git clone \
  --recurse-submodules \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git
```

On all machines, remove any previous build:

```bash
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
```

On the macOS machine (`xbbm`):

```bash
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --osx --disable-multilib
```

A typical run takes about 80 minutes.

On both Linux machines (`xbbi` and `xbba`):

```bash
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --all --disable-multilib
```

A typical run on the Intel machine takes about 105 minutes;
on the Arm machine it takes about 370 minutes.

### Clean the destination folder for the test binaries

On the development machine (`wks`) clear the folder where binaries from all
build machines will be collected.

```bash
rm -f ~/Downloads/xpack-binaries/riscv/*
```

Note: this step is very important, to avoid using test binaries!

### Copy the test binaries to the development machine

On all three machines:

```console
(cd ~/Work/riscv-none-embed-gcc-*/deploy; scp * ilg@wks:Downloads/xpack-binaries/riscv)
```

## Publish the binaries as pre-release/experimental

For really new versions, test before making the release.

Use the [experimental pre-release](https://github.com/xpack-dev-tools/pre-releases/releases/tag/experimental)
to publish the binaries, to run the Travis tests and to allow for
others to test them.

## Run the pre-release Travis tests

In the `tests/scripts/trigger-travis-*.sh` files, check and update the
URL to use something like

```
base_url="https://github.com/xpack-dev-tools/pre-releases/releases/download/experimental/"
```

Trigger the stable and latest Travis builds (on a Mac by double-clicking
on the command scripts):

- `trigger-travis-quick.mac.command` (optional)
- `trigger-travis-stable.mac.command`
- `trigger-travis-latest.mac.command`

The test results are available from:

- https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack

### Run the build scripts with multilibs

On all machines, clone the `xpack-develop` branch:

```bash
rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git; \
  git clone \
  --recurse-submodules \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git
```

On all machines, remove any previous build:

```bash
sudo rm -rf ~/Work/riscv-none-embed-gcc-*
```

Empty trash.

On the macOS machine (`xbbm`):

```bash
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --osx
```

A typical run takes about 250 minutes.

On both Linux machines (`xbbi` and `xbba`):

```bash
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/build.sh --all
```

A typical run on the Intel machine takes about 300 minutes;
on the Arm machine it takes about 945 minutes.

### Clean the destination folder

On the development machine (`wks`) clear the folder where binaries from all
build machines will be collected.

```bash
rm -f ~/Downloads/xpack-binaries/riscv/*
```

### Copy the binaries to the development machine

On all three machines:

```console
(cd ~/Work/riscv-none-embed-gcc-*/deploy; scp * ilg@wks:Downloads/xpack-binaries/riscv)
```

## Testing

Install the binaries on all supported platforms and check if they are
functional.

For this, on each platform (Mac, GNU/Linux 64/32, Windows 64/32):

- unpack the archive in `Desktop` or in `Downloads`, and rename the version
  folder, by replacing a dash with a space; this will test paths with spaces;
  on Windows the current paths always use spaces, so renaming is not needed;
- clone this repo locally; on Windows use the Git console;

```bash
git clone \
  --recurse-submodules \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git
```

- in a separate workspace, Import → General → Existing Projects into Workspace
  the Eclipse projects available in the
  `tests/eclipse` folder of the build repo; more details in the
  [README.md](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/blob/xpack/tests/eclipse/README.md)
- define the **Workspace RISC-V Toolchain path** to use the `Downloads`
  temporary location
- to test the compiler: for all projects
  - remove all build folders, or **Clean all**
  - build all configs, with the hammer, in `riscv-h1b-fs`
  - build all configs, with the hammer, in `riscv-h1b-fs-lib`; this should
    also run the builds in `riscv-static-lib`
- to test the debugger: for all OpenOCD debug configurations
  - start the OpenOCD debug session,
  - single step a few lines (Step Over)
  - start continuous run (Resume)
  - halt (Suspend)
  - start (Resume)
  - stop (Terminate)
  - (don't miss the LTO cases, since in the past they had problems)
- to test the Python debugger, start it with `--version`; on Windows, to
  test with different versions, set the path with:

## Create a new GitHub pre-release

- in `CHANGELOG.md`, add release date
- commit and push the `xpack-develop` branch
- go to the GitHub [releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases) page
- click **Draft a new release**
- name the tag like **v8.3.0-2.3** (mind the dash in the middle!)
- select the target branch (like sifive-gcc-8.3.0-gme)
- name the release like **xPack GNU RISC-V Embedded GCC v8.3.0-2.3**
(mind the dash and the space)
- as description
  - add a downloads badge like `![Github Releases (by Release)](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-embed-gcc-xpack/v8.3.0-2.3/total.svg)`; use empty URL for now
  - draft a short paragraph explaining what are the main changes
  - add _At this moment these binaries are provided for tests only!_
- **attach binaries** and SHA (drag and drop from the archives folder will do it)
- **enable** the **pre-release** button
- click the **Publish Release** button

Note: at this moment the system should send a notification to all clients
watching this project.

## Run the release Travis tests

Using the scripts in `tests/scripts/`, start:

- `trigger-travis-quick.mac.command` (optional)
- `trigger-travis-stable.mac.command`
- `trigger-travis-latest.mac.command`

The test results are available from:

- https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack

For more details, see `tests/scripts/README.md`.

## Prepare a new blog post

In the `xpack/web-jekyll` GitHub repo:

- select the `develop` branch
- add a new file to `_posts/riscv-none-embed-gcc/releases`
- name the file like `2020-07-03-riscv-none-embed-gcc-v8-3-0-2-3-released.md`
- name the post like: **xPack GNU RISC-V Embedded GCC v8.3.0-2.3 released**
- as `download_url` use the tagged URL like `https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v8.3.0-2.3/`
- update the `date:` field with the current date
- update the Travis URLs using the actual test pages
- update the SHA sums via copy/paste from the original build machines
  (it is very important to use the originals!)

If any, refer to closed
[issues](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues)
as:

- **[Issue:\[#1\]\(...\)]**.

### Update the SHA sums

Copy/paste the build report at the end of the post as:

```console
## Checksums
The SHA-256 hashes for the files are:

2009f256e59291e1025cc099e4300d7662dda040b304fe3462b4cb7c35c71378  
xpack-riscv-none-embed-gcc-8.3.0-2.3-darwin-x64.tar.gz

751f28a28148ddaec8cfcbf7eb794a70d24ee6650dc29da91e6aa672b9deae52  
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-arm64.tar.gz

63f232cbeddbe968130f4c8386cca24c5e1410cc2551738d071b279a94cd8b75  
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-arm.tar.gz

1d99730d6e1e5d3a60fa0ccfbbcf0276e77dd83d58b6d8d1543cef40a1dd96ca  
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-x32.tar.gz

079a88d7f7c18cfd735a9ed1f0eefa28ab28d3007b5f7591920ab25225c89248  
xpack-riscv-none-embed-gcc-8.3.0-2.3-linux-x64.tar.gz

8e7e98117900f3eed717b20555b346c2473dcbb9090e05c456412008f39fb62d  
xpack-riscv-none-embed-gcc-8.3.0-2.3-win32-x32.zip

5b7a4e3a2bb22566fed951972d726d10ff43bc35db17f9287eed52766e80ecee  
xpack-riscv-none-embed-gcc-8.3.0-2.3-win32-x64.zip
```

## Check the SHA sums

On the development machine (`wks`):

```bash
cd ~Downloads/xpack-binaries/riscv
cat *.sha
```

## Update the preview Web

- commit the `develop` branch of `xpack/web-jekyll` GitHub repo; use a message
  like **xPack GNU RISC-V Embedded GCC v8.3.0-2.3 released**
- wait for the GitHub Pages build to complete
- the preview web is https://xpack.github.io/web-preview/

## Publish on the npmjs.com server

- select the `xpack-develop` branch
- open the `package.json` file
- open the GitHub [releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases)
  page and select the latest release
- check the download counter, it should match the number of tests
- update the `baseUrl:` with the file URLs (including the tag/version);
  no terminating `/` is required
- from the release, copy the SHA & file names
- compare the SHA sums with those shown by `cat *.sha`
- check the executable names
- commit all changes, use a message like
  `package.json: update urls for 8.3.0-2.3 release` (without `v`)
- check the latest commits `npm run git-log`
- update `CHANGELOG.md`; commit with a message like
  _CHANGELOG: prepare npm v8.3.0-2.3.1_
- `npm version 8.3.0-2.3.1`; the first 5 numbers are the same as the
  GitHub release; the sixth number is the npm specific version
- `npm pack` and check the content of the archive, which should list
  only the `package.json`, the `README.md`, `LICENSE` and `CHANGELOG.md`
- push the `xpack-develop` branch to GitHub
- `npm publish --tag next` (use `--access public` when publishing for
  the first time)

The version is visible at:

- https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-embed-gcc?activeTab=versions

## Test if the npm binaries can be installed with xpm

Run the `tests/scripts/trigger-travis-xpm-install.sh` file, this
will install the package on Intel Linux 64-bit, macOS and Windows 64-bit.

The test results are available from:

- https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack

For 32-bit Windows, 32-bit Intel GNU/Linux and 32-bit Arm, install manually.

```console
$ xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@next
```

## Test the npm binaries

Install the binaries on all platforms.

```bash
xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@next
```

On GNU/Linux systems, including Raspberry Pi, use the following commands:

```bash
~/opt/xPacks/@xpack-dev-tools/riscv-none-embed-gcc/8.3.0-2.3.1/.content/bin/riscv-none-embed-gcc --version

TODO
```

On macOS, use:

```bash
~/Library/xPacks/@xpack-dev-tools/riscv-none-embed-gcc/8.3.0-2.3.1/.content/bin/riscv-none-embed-gcc --version

TODO
```

On Windows use:

```
%HOMEPATH%\AppData\Roaming\xPacks\@xpack-dev-tools\riscv-none-embed-gcc\8.3.0-2.3.1\.content\bin\riscv-none-embed-gcc --version

TODO
```

## Update the repo

- merge `xpack-develop` into `xpack`
- push

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`
- `npm dist-tag add @xpack-dev-tools/riscv-none-embed-gcc@8.3.0-2.3.1 latest`
- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`

## Update the Web

- in the `master` branch, merge the `develop` branch
- wait for the GitHub Pages build to complete
- the result is in https://xpack.github.io/news/
- remember the post URL, since it must be updated in the release page

## Create the final GitHub release

- go to the GitHub [releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases) page
- check the download counter, it should match the number of tests
- add a link to the Web page `[Continue reading »]()`; use an same blog URL
- **disable** the **pre-release** button
- click the **Update Release** button

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@xpack_project` account
- paste the release name like **xPack GNU RISC-V Embedded GCC v8.3.0-2.3 released**
- paste the link to the Web Page release
- click the **Tweet** button

## Announce to RISC-V community

Add a new topic in the **Announcements** category of the
[SiFive forums](https://forums.sifive.com/c/announcements).

Send an email to <sw-dev@groups.riscv.org>.
