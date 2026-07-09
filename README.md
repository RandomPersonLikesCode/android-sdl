# SDL3 Demo (Built On-Device Using Termux)
## HELP

With the upcoming Google's policy regarding Android
developer verification, open source Android projects
is in danger, so please spread this information to
everyone including fellow Android developers and don't
forget to send a link to [KeepAndroidOpen](https://keepandroidopen.org)!

## About

This just a demo using C and Java, and also SDL3 to build Android Games,
This project is also tested on-device using Termux to build.

## Build Command

To build, make sure to have a keystore file using `keytool`, set bash script named
`conf.bash` with this inside:

```bash
ks_file=<file>
ks_alias=<alias>
ks_pass=<pass>

min_sdk_ver=<min-sdk-version>
target_sdk_ver=<target-sdk-version>
ndk_ver=<ndk-version>

c_src=(
  "main.c"
  "sdl_window_context.c"
  # Other C source files
)
```

then run:

```sh
./build.bash --conf=conf.bash
```

To just clean build artifacts, run:

```sh
./build.bash --clean
```

Note: make sure to replace `<file>`, `<alias>`, `<pass>` and others with the appropriate value.

# License

This project is licensed under MIT license (see `LICENSE`), this project
also uses third-party libraries, license copy for each third-party libraries can
be found in each subdirectory inside `third_party/` folder.
