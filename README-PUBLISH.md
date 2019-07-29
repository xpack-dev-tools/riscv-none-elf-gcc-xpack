# How to publish the xPack GNU RISC-V Embedded GCC binaries?

## Build

Before starting the build, perform some checks.

### Check if repos are up-to-date

Be sure everything is committed and pushed

- `xpack-dev-tools/riscv-binutils-gdb.git`
- `xpack-dev-tools/riscv-gcc.git`
- `xpack-dev-tools/riscv-newlib.git`

### Check tags

The names should look like `v8.2.0-2.2`.

For the binutils-gdb repo, a separate tag like `v8.2.0-2.2-gdb` should be 
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

- if necessary, merge the `xpack-develop` branch into `xpack`.
- push it to GitHub.
- possibly push the helper project too.

### Run the build scripts

When everything is ready, follow the instructions from the 
[build](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/blob/xpack/README-BUILD.md) 
page.

## Test

Install the binaries on all supported platforms and check if they are 
functional.

For this, on each platform:

- unpack the archive in `Downloads`, and rename the version folder,
  by replacing a dash with a space; this will test paths with spaces;
  on Windows the current paths always use spaces, so renaming is not needed;
- clone this repo locally; on Windows use the Git console;
```
$ git clone --recurse-submodules https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack.git
```
- in a separate workspace, Import -> General -> Existing Projects into Workspace
  the Eclipse projects available in the 
  `tests/eclipse` folder of the build repo; more details in the 
  [README.md](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/blob/xpack/tests/eclipse/README.md)
- define the **Workspace RISC-V Toolchain path** to use the `Downloads` 
  temporary location
- to test the compiler: for all projects
  - remove all build folders 
  - build all configs
- to test the debugger: for all OpenOCD debug configurations
  - start the OpenOCD debug session, 
  - single step a few lines (Step Over)
  - start continuous run (Resume)
  - halt (Suspend)
  - start (Resume)
  - stop (Terminate)
  - (don't miss the LTO cases, since in the past they had problems)

## Create a new GitHub release

- go to the [GitHub Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc/releases) page
- click **Draft a new release**
- name the tag like **v8.2.0-2.2** (mind the dash in the middle!)
- select the target branch (like sifive-gcc-8.2.0-gme)
- name the release like **xPack GNU RISC-V Embedded GCC v8.2.0-2.2** 
(mind the dash and the space)
- as description
  - add a downloads badge like `[![Github Releases (by Release)](https://img.shields.io/github/downloads/xpack-dev-tools/riscv-none-embed-gcc/v8.2.0-2.2/total.svg)]()`; use empty URL for now
  - draft a short paragraph explaining what are the main changes
- **attach binaries** and SHA (drag and drop from the archives folder will do it)
- **enable** the **pre-release** button
- click the **Publish Release** button

Note: at this moment the system should send a notification to all clients 
watching this project.


## Prepare a new blog post 

In the `xpack.github.io` web Git:

- add a new file to `_posts/riscv-none-embed-gcc/releases`
- name the file like `2018-05-06-riscv-none-embed-gcc-v8-2-0-2-2-released.md`
- name the post like: **xPack GNU RISC-V Embedded GCC v8.2.0-2.2 released**.
- as `download_url` use the generic `https://github.com/xpack-dev-tools/riscv-none-embed-gcc/releases/tag/v8.2.0-2.2/` 
- update the `date:` field with the current date

If any, close [issues](https://github.com/xpack-dev-tools/riscv-none-embed-gcc/issues) 
on the way. Refer to them as:

- **[Issue:\[#1\]\(...\)]**.

### Update the SHA sums

Copy/paste the build report at the end of the post as:

```console
## Checksums
The SHA-256 hashes for the files are:

5e10320563e49dd31a33a032496547375d0e07191df727d393e26daa14d3f526
xpack-riscv-none-embed-gcc-8.2.0-3.1-darwin-x64.tgz

fdb6ab5badd0820e0562c288b1ec88566f8589f5fa26d81a0f57a2b95213d0cc
xpack-riscv-none-embed-gcc-8.2.0-3.1-linux-x32.tgz

dd6985729df5c2182cc5ce699013146b4addc80cbe231a7b62ec89d095e81aca
xpack-riscv-none-embed-gcc-8.2.0-3.1-linux-x64.tgz

737f95fb3129b0e7f67c48fea39b844f574c379768bd0ea5088a6e976f8f7b14
xpack-riscv-none-embed-gcc-8.2.0-3.1-win32-x32.zip

98ac277287d8c51cc1c5f83a5a9945951bd8d5806b4570b41eea2c306e141a3b
xpack-riscv-none-embed-gcc-8.2.0-3.1-win32-x64.zip
```

## Update the Web

- commit the `xpack.github.io` web Git; use a message 
  like **xPack GNU RISC-V Embedded GCC v8.2.0-2.2 released**
- wait for the GitHub Pages build to complete
- remember the post URL, since it must be updated in the release page

## Publish on the npmjs.com server

- open [GitHub Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases) 
  and select the latest release
- update the `baseUrl:` with the file URLs (including the tag/version)
- from the release, copy the SHA & file names
- check the executable names
- commit all changes, use a message like `package.json: update urls for 8.2.1-2.2 release` (without `v`)
- update `CHANGELOG.md`; commit with a message like 
  _CHANGELOG: prepare npm v8.2.1-2.2.1_
- `npm version 8.2.1-2.2.1`; the first 5 numbers are the same as the 
  GitHub release; the sixth number is the npm specific version
- `npm pack` and check the content of the archive
- push all changes to GitHub
- `npm publish` (use `--access public` when publishing for the first time)


## Test npm binaries

Install the binaries on all platforms.

```console
$ xpm install --global @xpack-dev-tools/riscv-none-embed-gcc@latest
```

## Create a final GitHub release

- go to the [GitHub Releases](https://github.com/xpack-dev-tools/riscv-none-embed-gcc/releases) page
- check the download counter, it should match the number of tests
- add a link to the Web page `[Continue reading »]()`; use an same blog URL
- **disable** the **pre-release** button
- click the **Update Release** button

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@xpack_project` account
- paste the release name like **xPack GNU RISC-V Embedded GCC v8.2.0-2.2 released**
- paste the link to the Github release
- click the **Tweet** button
