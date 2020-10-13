# How to publish the xPack GNU RISC-V Embedded GCC binaries

## Build

Before starting the build, perform some checks.

### Check possible open issues

Check GitHub [issues](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues)
and fix them; do not close them yet.

### Check if repos are up-to-date

Be sure everything is committed and pushed

- `xpack-dev-tools/riscv-binutils-gdb.git`
- `xpack-dev-tools/riscv-gcc.git`
- `xpack-dev-tools/riscv-newlib.git`

### Check tags

The names should look like `v8.3.0-2.2`.

For the binutils-gdb repo, a separate tag like `v8.3.0-2.2-gdb` should be
present, for the gdb build.

### Check the `CHANGELOG.md` file

Open the `CHANGELOG.txt` file and check if
all new entries are in.

Note: if you missed to update the `CHANGELOG.md` before starting the build,
edit the file and rerun the build, it should take only a few minutes to
recreate the archives with the correct file.

### Check the version

The `VERSION` file should refer to the actual release.

### Push the build scripts

In this Git repo:

- if necessary, merge the `xpack-develop` branch into `xpack`
- push it to GitHub.
- possibly push the helper project too.

### Run the build scripts

When everything is ready, follow the instructions from the
[build](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/blob/xpack/README-BUILD.md)
page.

## Test

Install the binaries on all supported platforms and check if they are
functional.

For this, on each platform (Mac, GNU/Linux 64/32, Windows 64/32):

- unpack the archive in `Desktop` or in `Downloads`, and rename the version 
  folder, by replacing a dash with a space; this will test paths with spaces;
  on Windows the current paths always use spaces, so renaming is not needed;
- clone this repo locally; on Windows use the Git console;

```console
$ git clone --recurse-submodules https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git \
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
- commit and push the repo
- go to the [GitHub Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases) page
- click **Draft a new release**
- name the tag like **v8.3.0-2.2** (mind the dash in the middle!)
- select the target branch (like sifive-gcc-8.3.0-gme)
- name the release like **xPack GNU RISC-V Embedded GCC v8.3.0-2.2**
(mind the dash and the space)
- as description
  - add a downloads badge like `![Github Releases (by Release)](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-embed-gcc-xpack/v8.3.0-2.2/total.svg)`; use empty URL for now
  - draft a short paragraph explaining what are the main changes
- **attach binaries** and SHA (drag and drop from the archives folder will do it)
- **enable** the **pre-release** button
- click the **Publish Release** button

Note: at this moment the system should send a notification to all clients
watching this project.

## Run the Travis tests

Run the tests on **stable** and **latest** platforms. This may take about 30
minutes.

The test results are available at
[Travis](https://travis-ci.org/github/xpack-dev-tools/riscv-none-embed-gcc-xpack/builds/).

For more details, see `tests/scripts/README.md`.

## Prepare a new blog post

In the `xpack.github.io` web Git:

- add a new file to `_posts/releases/riscv-none-embed-gcc`
- name the file like `2020-10-10-riscv-none-embed-gcc-v8-3-0-2-1-released.md`
- name the post like: **xPack GNU RISC-V Embedded GCC v8.3.0-2.2 released**.
- as `download_url` use the tagged URL like 
`https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v8.3.0-2.2/`
- update the `date:` field with the current date
- copy the list of commit IDs from the `README-<version>.sh` file
- generate the list of multilibs and copy/paste

If any, close [issues](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/issues)
on the way. Refer to them as:

- **[Issue:\[#1\]\(...\)]**.

### Update the SHA sums

Copy/paste the build report at the end of the post as:

```console
## Checksums
The SHA-256 hashes for the files are:

2009f256e59291e1025cc099e4300d7662dda040b304fe3462b4cb7c35c71378  
xpack-riscv-none-embed-gcc-8.3.0-2.2-darwin-x64.tar.gz

751f28a28148ddaec8cfcbf7eb794a70d24ee6650dc29da91e6aa672b9deae52  
xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-arm64.tar.gz

63f232cbeddbe968130f4c8386cca24c5e1410cc2551738d071b279a94cd8b75  
xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-arm.tar.gz

1d99730d6e1e5d3a60fa0ccfbbcf0276e77dd83d58b6d8d1543cef40a1dd96ca  
xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-x32.tar.gz

079a88d7f7c18cfd735a9ed1f0eefa28ab28d3007b5f7591920ab25225c89248  
xpack-riscv-none-embed-gcc-8.3.0-2.2-linux-x64.tar.gz

8e7e98117900f3eed717b20555b346c2473dcbb9090e05c456412008f39fb62d  
xpack-riscv-none-embed-gcc-8.3.0-2.2-win32-x32.zip

5b7a4e3a2bb22566fed951972d726d10ff43bc35db17f9287eed52766e80ecee  
xpack-riscv-none-embed-gcc-8.3.0-2.2-win32-x64.zip
```

If you missed this, `cat` the content of the `.sha` files:

```console
$ cd ~Downloads/xpack-binaries/riscv
$ cat *.sha
```

## Update the Web

- commit the `xpack.github.io` web Git; use a message
  like **xPack GNU RISC-V Embedded GCC v8.3.0-2.2 released**
- adjust timestamps
- wait for the GitHub Pages build to complete
- remember the post URL, since it must be updated in the release page

## Publish on the npmjs.com server

- open [GitHub Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases)
  and select the latest release
- update the `baseUrl:` with the file URLs (including the tag/version)
- from the release, copy the SHA & file names
- check the executable names
- commit all changes, use a message like `package.json: update urls for 8.3.0-2.2 release` (without `v`)
- check the latest commits `npm run git-log`
- update `CHANGELOG.md`; commit with a message like
  _CHANGELOG: prepare npm v8.3.0-2.2.1_
- `npm version 8.3.0-2.2.1`; the first 5 numbers are the same as the
  GitHub release; the sixth number is the npm specific version
- `npm pack` and check the content of the archive
- push all changes to GitHub
- `npm publish --tag next` (use `--access public` when publishing for the first time)

## Test the npm binaries with xpm

Run the `tests/scripts/trigger-travis-xpm-install.sh` file, this
will install the package on Intel Linux 64-bit, macOS and Windows 64-bit.

For 32-bit Windows, 32-bit Intel GNU/Linux and 32-bit Arm, install manually.

```console
$ xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@next
```

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`
- `npm dist-tag add @xpack-dev-tools/riscv-none-embed-gcc@8.3.0-2.2.1 latest`
- `npm dist-tag ls @xpack-dev-tools/riscv-none-embed-gcc`

## Create a final GitHub release

- go to the [GitHub Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases) page
- check the download counter, it should match the number of tests
- add a link to the Web page `[Continue reading »]()`; use an same blog URL
- **disable** the **pre-release** button
- click the **Update Release** button

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@xpack_project` account
- paste the release name like **xPack GNU RISC-V Embedded GCC v8.3.0-2.2 released**
- paste the link to the Web Page release
- click the **Tweet** button

## Announce to RISC-V community

Add a new topic in the **Announcements** category of the
[SiFive forums](https://forums.sifive.com/c/announcements).

Send an email to <sw-dev@groups.riscv.org>.
