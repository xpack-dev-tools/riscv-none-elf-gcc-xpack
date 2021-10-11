# How to make a new release (maintainer info)

## Release schedule

The xPack GNU RISC-V Embedded GCC release schedule generally follows the
[SiFive Releases](https://github.com/sifive/freedom-tools/releases/)
release schedule, which, although not fixed, is about one-two releases
per year.

## Prepare the build

Before starting the build, perform some checks and tweaks.

### Check Git

- switch to the `xpack-develop` branch
- if needed, merge the `xpack` branch

### Identify SiFive commit IDs

- check the [SiFive Releases](https://github.com/sifive/freedom-tools/releases/)
for new releases
- identify the tag of the latest release (like `v2020.08.0`)
- switch to Code view and select the tag
- open the `src` folder to identify the commit IDs used for the linked repos
- copy/paste the submodule links to common-versions-sources.sh
- get binutils version from binutils/CHANGELOG
- get gcc version from gcc/BASE_VER (gcc/ChangeLog)
- get newlib version from newlib/configure, VERSION= (newlib/README)
- get gdb version from gdb/VERSION.in (gdb/ChangeLog)

### Identify the main GCC version

Determine the GCC version (like `10.1.0`) and update the `scripts/VERSION`
file; the format is `10.1.0-1.1`. The fourth digit is the number of the
SiFive release of the same GCC version, and the fifth digit is the xPack
GNU RISC-V Embedded GCC release number of this version.

### Enable Sourcetree Search View

To easily find commits by id, enable the Search View, and search in Commit SHA.

### Update binutils

With Sourcetree in
[xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)

Check if there is a `sifive` remote pointing to
<https://github.com/sifive/riscv-binutils-gdb>.

- in the Search View, identify the commit id
- tag it with the SiFive release name (`v2020.08.0`)
- checkout
- create new branch with the SiFive release name (`v2020.08.0`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.08.0-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
  which adds `-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.1`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Update gcc

With Sourcetree in
[xpack-dev-tools/riscv-gcc](https://github.com/xpack-dev-tools/riscv-gcc)

Check if there is a `sifive` remote pointing to
<https://github.com/sifive/riscv-gcc>.

- in the Search View, identify the commit id
- tag it with the SiFive release name (`v2020.08.0`)
- checkout
- create new branch with the SiFive release name (`v2020.08.0`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.08.0-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the differences from the non-xpack branch; there should be tree files:
  - `elf-embed.h` with the `LIB_SPEC` definitions without libgloss
  - `config.gcc` with `tm_file` definition that uses `elf-embed.h`
  - `config.sub` which adds `*-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.1`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Update newlib

With Sourcetree in
[xpack-dev-tools/riscv-newlib](https://github.com/xpack-dev-tools/riscv-newlib)

Check if there is a `sifive` remote pointing to
<https://github.com/sifive/riscv-newlib>.

- in the Search View, identify the commit id
- tag it with the SiFive release name (`v2020.08.0`)
- checkout
- create a new branch with the SiFive release name (`v2020.08.0`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.08.0-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
  which adds `-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.1`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Update gdb

With Sourcetree in
[xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)

Check if there is a `gdb` remote pointing to
git://sourceware.org/git/binutils-gdb.git.

- in the Search View, identify the commit id
- tag it with the SiFive release name (`v2020.08.0-gdb`)
- checkout
- create a new branch with the SiFive release name (`v2020.08.0-gdb`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.08.0-gdb-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
  which adds `-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.1-gdb`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Increase the version

Determine the GCC version (like `10.1.0`) and update the `scripts/VERSION`
file; the format is `10.1.0-1.1`. The fourth number is the xPack release number
of this version. A fifth number will be added when publishing
the package on the `npm` server.

### Fix possible open issues

Check GitHub issues and pull requests:

- <https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues/>

and fix them; assign them to a milestone (like `10.1.0-1.1`).

### Check `README.md`

Normally `README.md` should not need changes, but better check.
Information related to the new version should not be included here,
but in the version specific release page.

## Update `CHANGELOG.md`

- open the `CHANGELOG.md` file
- check if all previous fixed issues are in
- add a new entry like _v10.1.0-1.1 prepared_
- commit with a message like _prepare v10.1.0-1.1_

Note: if you missed to update the `CHANGELOG.md` before starting the build,
edit the file and rerun the build, it should take only a few minutes to
recreate the archives with the correct file.

### Update the version specific code

- open the `common-versions-source.sh` file
- add a new `if` with the new version before the existing code
- update `GH_RELEASE` to the new version (like `10.1.0-1.1`, without `v`)
- in SiFive [releases](https://github.com/sifive/freedom-tools/releases/)
for new releases
- identify the tag of the latest release (like `v2020.08.0`)
- switch to Code view and select the tag
- open the `Makefile` file to identify the `MULTILIBS_GEN` definition;
- copy/paste it into `GCC_MULTILIB` (mind the tabs that must be removed!)
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

The names should look like `v10.1.0-1.1`.

For the binutils-gdb repo, a separate tag like `v10.1.0-1.1-gdb` should be
present, for the GDB build.

### Development run the build scripts

Before the real build, run a test build on the development machine (`wks`)
or the production machine (`xbbm`):

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*

caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --without-pdf --disable-tests --disable-multilib --osx
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --without-pdf --disable-tests --disable-multilib --linux64 --win64
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --without-pdf --disable-tests --disable-multilib --linux32 --win32
```

Work on the scripts until all platforms pass the build.

### Push the build scriptss

- push the `xpack-develop` branch to GitHub
- possibly push the helper project too

From here it'll be cloned on the production machines.

### Run the build scripts without multilibs

On the macOS machine (`xbbm`) open ssh sessions to both Linux machines
(`xbbi` and `xbba`):

```sh
caffeinate ssh xbbi

caffeinate ssh xbba
```

On all machines, clone the `xpack-develop` branch and remove previous builds

```sh
rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git \
git clone \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git -C ~/Downloads/riscv-none-embed-gcc-xpack.git submodule update --init --recursive

sudo rm -rf ~/Work/riscv-none-embed-gcc-*
```

On the macOS machine (`xbbm`):

```sh
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --osx --disable-multilib
```

A typical run takes about 215 minutes (was 80 without rvv).

On `xbbi`:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --all --disable-multilib

bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --linux64 --windows64 --disable-multilib
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --linux32 --windows32 --disable-multilib
```

A typical run takes about 160+150 minutes.

On `berry`:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --arm64 --disable-multilib
```

A typical run takes about 545 minutes (was 374 without rvv).

Please note that the 32-bit build fails with 'out of memory'.

### Clean the destination folder for the test binaries

On the development machine (`wks`) clear the folder where binaries from all
build machines will be collected.

```sh
rm -f ~/Downloads/xpack-binaries/riscv-none-embed-gcc/*
```

Note: this step is very important, to avoid using test binaries!

### Copy the test binaries to the development machine

On all three machines:

```sh
(cd ~/Work/riscv-none-embed-gcc-*/deploy; scp * ilg@wks:Downloads/xpack-binaries/riscv-none-embed-gcc)
```

## Publish the binaries as pre-release/experimental

For really new versions, test before making the release.

Use the [experimental pre-release](https://github.com/xpack-dev-tools/pre-releases/releases/tag/experimental)
to publish the binaries, to run the Travis tests and to allow for
others to test them.

## Run the pre-release Travis tests

In the `tests/scripts/trigger-travis-*.sh` files, check and update the
URL to use something like

```console
base_url="https://github.com/xpack-dev-tools/pre-releases/releases/download/experimental/"
```

Trigger the stable and latest Travis builds (on a Mac by double-clicking
on the command scripts):

- `trigger-travis-quick.mac.command` (optional)
- `trigger-travis-stable.mac.command`
- `trigger-travis-latest.mac.command`

The test results are available from:

- <https://travis-ci.com/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/>

### Run the build scripts with multilibs

On all machines, clone the `xpack-develop` branch:

```sh
rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git \

git clone \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git -C ~/Downloads/riscv-none-embed-gcc-xpack.git submodule update --init --recursive

sudo rm -rf ~/Work/riscv-none-embed-gcc-*
```

Empty trash.

On the macOS machine (`xbbm`):

```sh
caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --osx
```

A typical run takes about 500 minutes (was 250 minutes without rvv).

On `xbbi`:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --all
```

A typical run takes about 570 minutes (was 300 minutes without rvv).

On `berry`:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --arm64
```

A typical run takes about 1100 minutes.

Please note that the 32-bit build fails.

### Clean the destination folder

On the development machine (`wks`) clear the folder where binaries from all
build machines will be collected.

```sh
rm -f ~/Downloads/xpack-binaries/riscv-none-embed-gcc/*
```

### Copy the binaries to the development machine

On all three machines:

```sh
(cd ~/Work/riscv-none-embed-gcc-*/deploy; scp * ilg@wks:Downloads/xpack-binaries/riscv-none-embed-gcc)
```

## Testing

Install the binaries on all supported platforms and check if they are
functional.

For this, on each platform (Mac, GNU/Linux 64/32, Windows 64/32):

- unpack the archive in `Desktop` or in `Downloads`, and rename the version
  folder, by replacing a dash with a space; this will test paths with spaces;
  on Windows the current paths always use spaces, so renaming is not needed;
- clone this repo locally; on Windows use the Git console;

```sh
git clone \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
  ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git -C ~/Downloads/riscv-none-embed-gcc-xpack.git submodule update --init --recursive
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
- go to the GitHub [releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/) page
- click **Draft a new release**
- name the tag like **v10.1.0-1.1** (mind the dash in the middle!)
- select the target branch (like sifive-gcc-10.1.0-gme)
- name the release like **xPack GNU RISC-V Embedded GCC v10.1.0-1.1**
(mind the dash and the space)
- as description, use:

```markdown
![Github Releases (by Release)](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-embed-gcc-xpack/v10.1.0-1.1/total.svg)

Version v10.1.0-1.1 is a new release of the **xPack GNU RISC-V Embedded GCC** package, following the SiFive release v2020.08.0 from Dec 19th, 2020.

_At this moment these binaries are provided for tests only!_
```

- **attach binaries** and SHA (drag and drop from the
  `~/Downloads/xpack-binaries/*` folder will do it)
- **enable** the **pre-release** button
- click the **Publish Release** button

Note: at this moment the system should send a notification to all clients
watching this project.

## Run the native tests

Run the native tests on all platforms:

```sh
rm -rf ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git clone \
  --branch xpack-develop \
  https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git  \
  ~/Downloads/riscv-none-embed-gcc-xpack.git; \
git -C ~/Downloads/riscv-none-embed-gcc-xpack.git submodule update --init --recursive

rm -rf ~/Work/cache/xpack-riscv-none-embed-gcc-*

bash ~/Downloads/riscv-none-embed-gcc-xpack.git/tests/scripts/native-test.sh \
  "https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/download/v10.1.0-1.1/"
```

## Run the release CI tests

Using the scripts in `tests/scripts/`, start:

TODO:

The test results are available from:

- TODO

For more details, see `tests/scripts/README.md`.

Using the scripts in `tests/scripts/`, start:

- `trigger-travis-quick.mac.command` (optional)
- `trigger-travis-stable.mac.command`
- `trigger-travis-latest.mac.command`

The test results are available from:

- <https://travis-ci.com/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/>

For more details, see `tests/scripts/README.md`.

## Prepare a new blog post

In the `xpack/web-jekyll` GitHub repo:

- select the `develop` branch
- add a new file to `_posts/riscv-none-embed-gcc/releases`
- name the file like `021-01-05-riscv-none-embed-gcc-v10-1-0-1-1-released.md`
- name the post like: **xPack GNU RISC-V Embedded GCC v10.1.0-1.1 released**
- as `download_url` use the tagged URL like `https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v10.1.0-1.1/`
- update the `date:` field with the current date
- update the Travis URLs using the actual test pages
- update the SHA sums via copy/paste from the original build machines
  (it is very important to use the originals!)

If any, refer to closed
[issues](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues/)
as:

- **[Issue:\[#1\]\(...\)]**.

### Update the SHA sums

On the development machine (`wks`):

```sh
cat ~/Downloads/xpack-binaries/riscv-none-embed-gcc/*.sha
```

Copy/paste the build report at the end of the post as:

```console
## Checksums
The SHA-256 hashes for the files are:

2009f256e59291e1025cc099e4300d7662dda040b304fe3462b4cb7c35c71378  
xpack-riscv-none-embed-gcc-10.1.0-1.1-darwin-x64.tar.gz

751f28a28148ddaec8cfcbf7eb794a70d24ee6650dc29da91e6aa672b9deae52  
xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-arm64.tar.gz

63f232cbeddbe968130f4c8386cca24c5e1410cc2551738d071b279a94cd8b75  
xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-arm.tar.gz

1d99730d6e1e5d3a60fa0ccfbbcf0276e77dd83d58b6d8d1543cef40a1dd96ca  
xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-ia32.tar.gz

079a88d7f7c18cfd735a9ed1f0eefa28ab28d3007b5f7591920ab25225c89248  
xpack-riscv-none-embed-gcc-10.1.0-1.1-linux-x64.tar.gz

8e7e98117900f3eed717b20555b346c2473dcbb9090e05c456412008f39fb62d  
xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-ia32.zip

5b7a4e3a2bb22566fed951972d726d10ff43bc35db17f9287eed52766e80ecee  
xpack-riscv-none-embed-gcc-10.1.0-1.1-win32-x64.zip
```

## Update the preview Web

- commit the `develop` branch of `xpack/web-jekyll` GitHub repo; use a message
  like **xPack GNU RISC-V Embedded GCC v10.1.0-1.1 released**
- push
- wait for the GitHub Pages build to complete
- the preview web is <https://xpack.github.io/web-preview/news/>

## Update package.json binaries

- select the `xpack-develop` branch
- run `xpm-dev binaries-update`

```sh
xpm-dev binaries-update \
  -C "${HOME}/Downloads/riscv-none-embed-gcc-xpack.git" \
  '10.1.0-1.1' \
  "${HOME}/Downloads/xpack-binaries/riscv-none-embed-gcc"
```

- open the GitHub [releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/)
  page and select the latest release
- check the download counter, it should match the number of tests
- open the `package.json` file
- update the `baseUrl:` with the file URLs (including the tag/version);
  no terminating `/` is required
- from the release, check the SHA & file names
- compare the SHA sums with those shown by `cat *.sha`
- check the executable names
- commit all changes, use a message like
  `package.json: update urls for 10.1.0-1.1 release` (without `v`)

## Publish on the npmjs.com server

- select the `xpack-develop` branch
- open the `package.json` file
- check the latest commits `npm run git-log`
- update `CHANGELOG.md`; commit with a message like
  _CHANGELOG: publish npm v10.1.0-1.1.1_
- `npm version 10.1.0-1.1.1`; the first 5 numbers are the same as the
  GitHub release; the sixth number is the npm specific version
- `npm pack` and check the content of the archive, which should list
  only the `package.json`, the `README.md`, `LICENSE` and `CHANGELOG.md`
- push the `xpack-develop` branch to GitHub
- push tags with `git push origin --tags`
- `npm publish --tag next` (use `--access public` when publishing for
  the first time)

After a few moments the version will be visible at:

- <https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-embed-gcc?activeTab=versions>

## Test if the npm binaries can be installed with xpm

Run the `tests/scripts/trigger-travis-xpm-install.sh` script, this
will install the package on Intel Linux 64-bit, macOS and Windows 64-bit.

The test results are available from:

- <https://travis-ci.com/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/>

For 32-bit Windows, 32-bit Intel GNU/Linux and 32-bit Arm, install manually.

```sh
xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@next
```

## Test the npm binaries

Install the binaries on all platforms.

```sh
xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@next
```

On GNU/Linux systems, including Raspberry Pi, use the following commands:

```sh
~/opt/xPacks/@xpack-dev-tools/riscv-none-embed-gcc/10.1.0-1.1.1/.content/bin/riscv-none-embed-gcc --version

riscv-none-embed-gcc (xPack GNU RISC-V Embedded GCC, 64-bit) 10.1.0
Copyright (C) 2020 Free Software Foundation, Inc.
```

On macOS, use:

```sh
~/Library/xPacks/@xpack-dev-tools/riscv-none-embed-gcc/10.1.0-1.1.1/.content/bin/riscv-none-embed-gcc --version

riscv-none-embed-gcc (xPack GNU RISC-V Embedded GCC, 64-bit) 10.1.0
Copyright (C) 2020 Free Software Foundation, Inc.
```

On Windows use:

```doscon
%USERPROFILE%\AppData\Roaming\xPacks\@xpack-dev-tools\riscv-none-embed-gcc\10.1.0-1.1.1\.content\bin\riscv-none-embed-gcc --version

riscv-none-embed-gcc (xPack GNU RISC-V Embedded GCC, 64-bit) 10.1.0
Copyright (C) 2020 Free Software Foundation, Inc.
...
```

## Update the repo

- merge `xpack-develop` into `xpack`
- push

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`
- `npm dist-tag add @xpack-dev-tools/riscv-none-embed-gcc@10.1.0-1.1.1 latest`
- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`

## Update the Web

- in the `master` branch, merge the `develop` branch
- wait for the GitHub Pages build to complete
- the result is in <https://xpack.github.io/news/>
- remember the post URL, since it must be updated in the release page

## Create the final GitHub release

- go to the GitHub [releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/) page
- check the download counter, it should match the number of tests
- add a link to the Web page `[Continue reading »]()`; use an same blog URL
- **disable** the **pre-release** button
- click the **Update Release** button

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@xpack_project` account
- paste the release name like **xPack GNU RISC-V Embedded GCC v10.1.0-1.1 released**
- paste the link to the Web Page release
- click the **Tweet** button

## Remove pre-release binaries

- got to <https://github.com/xpack-dev-tools/pre-releases/releases/tag/test>
- remove the test binaries

## Announce to RISC-V community

Add a new topic in the **Announcements** category of the
[RISC-V forums]<https://groups.google.com/a/groups.riscv.org/g/sw-dev>).

```console
Subject: xPack GNU RISC-V Embedded GCC v10.1.0-1.1 released

Version 10.1.0-1.1 is a new release of the xPack GNU RISC-V Embedded GCC; it follows the SiFive release 2020-08.0 from Dec 19th, 2020.

https://xpack.github.io/blog/2021/01/05/riscv-none-embed-gcc-v10-1-0-1-1-released/
```
