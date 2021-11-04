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
- identify the tag of the latest release (like `v2020.12.0`)
- switch to Code view and select the tag
- open the `src` folder to identify the commit IDs used for the linked repos
- copy/paste the submodule links to common-versions-sources.sh
- get binutils version from binutils/CHANGELOG
- get gcc version from gcc/BASE_VER (gcc/ChangeLog)
- get newlib version from newlib/configure, VERSION= (newlib/README)
- get gdb version from gdb/VERSION.in (gdb/ChangeLog)

### Identify the main GCC version

Determine the GCC version (like `10.1.0`) and update the `scripts/VERSION`
file; the format is `10.1.0-1.2`. The fourth digit is the number of the
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
- tag it with the SiFive release name (`v2020.12.0`)
- checkout
- create new branch with the SiFive release name (`v2020.12.0`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.12.0-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
  which adds `-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.2`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Update gcc

With Sourcetree in
[xpack-dev-tools/riscv-gcc](https://github.com/xpack-dev-tools/riscv-gcc)

Check if there is a `sifive` remote pointing to
<https://github.com/sifive/riscv-gcc>.

- in the Search View, identify the commit id
- tag it with the SiFive release name (`v2020.12.0`)
- checkout
- create new branch with the SiFive release name (`v2020.12.0`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.12.0-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the differences from the non-xpack branch; there should be tree files:
  - `elf-embed.h` with the `LIB_SPEC` definitions without libgloss
  - `config.gcc` with `tm_file` definition that uses `elf-embed.h`
  - `config.sub` which adds `*-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.2`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Update newlib

With Sourcetree in
[xpack-dev-tools/riscv-newlib](https://github.com/xpack-dev-tools/riscv-newlib)

Check if there is a `sifive` remote pointing to
<https://github.com/sifive/riscv-newlib>.

- in the Search View, identify the commit id
- tag it with the SiFive release name (`v2020.12.0`)
- checkout
- create a new branch with the SiFive release name (`v2020.12.0`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.12.0-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
  which adds `-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.2`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Update gdb

With Sourcetree in
[xpack-dev-tools/riscv-binutils-gdb](https://github.com/xpack-dev-tools/riscv-binutils-gdb)

Check if there is a `gdb` remote pointing to
git://sourceware.org/git/binutils-gdb.git.

- in the Search View, identify the commit id
- tag it with the SiFive release name (`v2020.12.0-gdb`)
- checkout
- create a new branch with the SiFive release name (`v2020.12.0-gdb`)
- create a new branch with a similar name, but suffixed with `-xpack`
  (like `v2020.12.0-gdb-xpack`
- identify the commit which adds the xPack specific changes
- cherry pick it; do not commit immediately
- check the uncommited changes; there should be one file `config.sub`
  which adds `-embed)`
- commit as **add support for riscv-none-embed-***
- add a tag with the current version (like `v10.1.0-1.2-gdb`),
- push both new branches to `origin`, together with all tags

Copy/paste the branch name and commit id to common-versions-source.sh

### Increase the version

Determine the GCC version (like `10.1.0`) and update the `scripts/VERSION`
file; the format is `10.1.0-1.2`. The fourth number is the xPack release number
of this version. A fifth number will be added when publishing
the package on the `npm` server.

### Fix possible open issues

Check GitHub issues and pull requests:

- <https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues/>

and fix them; assign them to a milestone (like `10.1.0-1.2`).

### Check `README.md`

Normally `README.md` should not need changes, but better check.
Information related to the new version should not be included here,
but in the version specific release page.

### Update versions in `README` files

- update version in `README-RELEASE.md`
- update version in `README-BUILD.md`
- update version in `README.md`

### Update `CHANGELOG.md`

- open the `CHANGELOG.md` file
- check if all previous fixed issues are in
- add a new entry like _- v10.1.0-1.2 prepared_
- commit with a message like _prepare v10.1.0-1.2_

Note: if you missed to update the `CHANGELOG.md` before starting the build,
edit the file and rerun the build, it should take only a few minutes to
recreate the archives with the correct file.

### Update the version specific code

- open the `common-versions-source.sh` file
- add a new `if` with the new version before the existing code
- update `GH_RELEASE` to the new version (like `10.1.0-1.2`, without `v`)
- in SiFive [releases](https://github.com/sifive/freedom-tools/releases/)
for new releases
- identify the tag of the latest release (like `v2020.12.0`)
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

The names should look like `v10.1.0-1.2`.

For the binutils-gdb repo, a separate tag like `v10.1.0-1.2-gdb` should be
present, for the GDB build.

### Development run the build scripts

Before the real build, run a test build on the development machine (`wks`)
or the production machine (`xbbm`):

```sh
sudo rm -rf ~/Work/riscv-none-embed-gcc-*

caffeinate bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --osx
```

Similarly on the Intel Linux (`xbbi`):

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --linux64
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --linux32

bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --win64
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --win32
```

And on the RISC-V Linux (`xbba`):

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --arm64
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/build.sh --develop --disable-multilib --arm32
```

Work on the scripts until all platforms pass the build.

Possibly add binutils & gdb patches.

### Push the build scripts

- push the `xpack-develop` branch to GitHub
- possibly push the helper project too

From here it'll be cloned on the production machines.

## Run the CI build

The automation is provided by GitHub Actions and three self-hosted runners.

It is recommended to do **a first run without the multi-libs**
(see the `defs-source.sh` file), test it,
and, when ready, rerun the full build.

Run the `generate-workflows` to re-generate the
GitHub workflow files; commit and push if necessary.

- on the macOS machine (`xbbm`) open ssh sessions to both Linux
machines (`xbbi` and `xbba`):

```sh
caffeinate ssh xbbi

caffeinate ssh xbba
```

Start the runner on all three machines:

```sh
~/actions-runner/run.sh
```

Check that both the project Git and the submodule are pushed to GitHub.

To trigger the GitHub Actions build, use the xPack actions:

- `trigger-workflow-build-xbbi`
- `trigger-workflow-build-xbba`
- `trigger-workflow-build-xbbm`

This is equivalent to:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/trigger-workflow-build.sh --machine xbbi
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/trigger-workflow-build.sh --machine xbba
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/trigger-workflow-build.sh --machine xbbm
```

These scripts require the `GITHUB_API_DISPATCH_TOKEN` variable to be present
in the environment.

These commands use the `xpack-develop` branch of this repo.

The Arm build take about 16-17 hours
to complete, and the other about 11 hours.

The workflows results and logs are available from the
[Actions](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/actions/) page.

The resulting binaries are available for testing from
[pre-releases/test](https://github.com/xpack-dev-tools/pre-releases/releases/tag/test/).

## Testing

### CI tests

The automation is provided by GitHub Actions.

To trigger the GitHub Actions tests, use the xPack actions:

- `trigger-workflow-test-prime`
- `trigger-workflow-test-docker-linux-intel`
- `trigger-workflow-test-docker-linux-arm`

These are equivalent to:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/tests/trigger-workflow-test-prime.sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/tests/trigger-workflow-test-docker-linux-intel.sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/tests/trigger-workflow-test-docker-linux-arm.sh
```

These scripts require the `GITHUB_API_DISPATCH_TOKEN` variable to be present
in the environment.

These actions use the `xpack-develop` branch of this repo and the
[pre-releases/test](https://github.com/xpack-dev-tools/pre-releases/releases/tag/test/)
binaries.

The tests results are available from the
[Actions](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/actions/) page.

Since GitHub Actions provides a single version of macOS, the
multi-version macOS tests run on Travis.

To trigger the Travis test, use the xPack action:

- `trigger-travis-macos`

This is equivalent to:

```sh
bash ~/Downloads/riscv-none-embed-gcc-xpack.git/scripts/helper/tests/trigger-travis-macos.sh
```

This script requires the `TRAVIS_COM_TOKEN` variable to be present
in the environment.

The test results are available from
[travis-ci.com](https://app.travis-ci.com/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/).

### Manual tests

Install the binaries on all supported platforms and check if they are
functional.

For this, on each platform (Mac, GNU/Linux 64/32, Windows 64/32):

- download archive from
  [pre-releases](https://github.com/xpack-dev-tools/pre-releases/releases/tag/test);
- unpack the archive in `Desktop` or in `Downloads`;
- on macOS it is necessarry to remove the `com.apple.quarantine`
  attribute of archive and possibly the expanded folder:

```sh
xattr -dr com.apple.quarantine xpack-riscv-none-embed-gcc-*
```

- rename the version
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
- define the **Eclipse** → **Preferences...** → **MCU** →
  **Workspace RISC-V Toolchain path** to use the `Downloads`
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
- to test the Python debugger, start it with `--version`

## Create a new GitHub pre-release draft

- in `CHANGELOG.md`, add the release date and a message like _- v10.1.0-1.2 released_
- commit and push the `xpack-develop` branch
- run the xPack action `trigger-workflow-publish-release`

The result is a
[draft pre-release](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/)
tagged like **v10.1.0-1.2** (mind the dash in the middle!) and
named like **xPack GNU RISC-V Embedded GCC v10.1.0-1.2** (mind the dash),
with all binaries attached.

- edit the draft and attach it to the `xpack-develop` branch (important!)
- save the draft (do **not** publish yet!)

## Prepare a new blog post

Run the xPack action `generate-jekyll-post`; this will leave a file
on the Desktop.

In the `xpack/web-jekyll` GitHub repo:

- select the `develop` branch
- copy the new file to `_posts/releases/riscv-none-embed-gcc`

If any, refer to closed
[issues](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues/).

## Update the preview Web

- commit the `develop` branch of `xpack/web-jekyll` GitHub repo;
  use a message like **xPack GNU RISC-V Embedded GCC v10.1.0-1.2 released**
- push to GitHub
- wait for the GitHub Pages build to complete
- the preview web is <https://xpack.github.io/web-preview/news/>

## Create the pre-release

- go to the GitHub [Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/) page
- perform the final edits and check if everything is fine
- temporarily fill in the _Continue Reading »_ with the URL of the
  web-preview release
- keep the pre-release button enabled
- publish the release

Note: at this moment the system should send a notification to all clients
watching this project.

## Update package.json binaries

- select the `xpack-develop` branch
- run the xPack action `update-package-binaries`
- open the `package.json` file
- check the `baseUrl:` it should match the file URLs (including the tag/version);
  no terminating `/` is required
- from the release, check the SHA & file names
- compare the SHA sums with those shown by `cat *.sha`
- check the executable names
- commit all changes, use a message like
  `package.json: update urls for 10.1.0-1.2 release` (without `v`)

## Publish on the npmjs.com server

- select the `xpack-develop` branch
- check the latest commits `npm run git-log`
- update `CHANGELOG.md`, add a line like _- v10.1.0-1.2 published on npmjs.com_
- commit with a message like _CHANGELOG: publish npm v10.1.0-1.2_
- `npm pack` and check the content of the archive, which should list
  only the `package.json`, the `README.md`, `LICENSE` and `CHANGELOG.md`;
  possibly adjust `.npmignore`
- `npm version 10.1.0-1.2.1`; the first 5 numbers are the same as the
  GitHub release; the sixth number is the npm specific version
- push the `xpack-develop` branch to GitHub
- push tags with `git push origin --tags`
- `npm publish --tag next` (use `--access public` when publishing for
  the first time)

After a few moments the version will be visible at:

- <https://www.npmjs.com/package/@xpack-dev-tools/riscv-none-embed-gcc?activeTab=versions>

## Test if the npm binaries can be installed with xpm

Run the xPack action `trigger-workflow-test-xpm`, this
will install the package via `xpm install` on all supported platforms.

The tests results are available from the
[Actions](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/actions/) page.

## Update the repo

- merge `xpack-develop` into `xpack`
- push to GitHub

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`
- `npm dist-tag add @xpack-dev-tools/riscv-none-embed-gcc@10.1.0-1.2.1 latest`
- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`

In case the previous version is not functional and needs to be unpublished:

- `npm unpublish @xpack-dev-tools/riscv-none-embed-gcc@10.1.0-1.2.X`

## Update the Web

- in the `master` branch, merge the `develop` branch
- wait for the GitHub Pages build to complete
- the result is in <https://xpack.github.io/news/>
- remember the post URL, since it must be updated in the release page

## Create the final GitHub release

- go to the GitHub [Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/) page
- check the download counter, it should match the number of tests
- add a link to the Web page `[Continue reading »]()`; use an same blog URL
- remove the _tests only_ notice
- **disable** the **pre-release** button
- click the **Update Release** button

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@xpack_project` account
- paste the release name like **xPack GNU RISC-V Embedded GCC v10.1.0-1.2 released**
- paste the link to the Web page
  [release](https://xpack.github.io/riscv-none-embed-gcc/releases/)
- click the **Tweet** button

## Remove pre-release binaries

- go to <https://github.com/xpack-dev-tools/pre-releases/releases/tag/test/>
- remove the test binaries

## Announce to RISC-V community

Add a new topic in the **Announcements** category of the
[RISC-V forums]<https://groups.google.com/a/groups.riscv.org/g/sw-dev>).

```console
Subject: xPack GNU RISC-V Embedded GCC v10.1.0-1.2 released

Version 10.1.0-1.2 is a new release of the xPack GNU RISC-V Embedded GCC; it follows the SiFive release 2020-08.0 from Dec 19th, 2020.

https://xpack.github.io/blog/2021/01/05/riscv-none-embed-gcc-v10-1-0-1-1-released/
```
