# Custom Tool

This folder and its contents are **not necessary** for the Arduino Core.
This is a very simple hello world program in the
[Go programming language](https://golang.org/), compiled to a wide range
of platforms to show how to integrate custom tools the with the Arduino core.

A custom tool could be a compiler like GCC, a debugger/programmer like OpenOCD
or avrdude, or anything else needed to prepare/build/compile/load/etc.

## Compiling to the different platforms

This program is trivial, and the Go language was chosen because it's very easy
to cross-compile from a single platform:

```
GOOS=windows GOARCH=386           go build -o ./BUILD/hello-windows-32.exe
GOOS=windows GOARCH=amd64         go build -o ./BUILD/hello-windows-64.exe
GOOS=linux   GOARCH=386           go build -o ./BUILD/hello-linux-32
GOOS=linux   GOARCH=amd64         go build -o ./BUILD/hello-linux-64
GOOS=linux   GOARCH=arm   GOARM=6 go build -o ./BUILD/hello-linux-armv6
GOOS=linux   GOARCH=arm64         go build -o ./BUILD/hello-linux-armv8
GOOS=darwin  GOARCH=386           go build -o ./BUILD/hello-mac-32
GOOS=darwin  GOARCH=amd64         go build -o ./BUILD/hello-mac-64
```

## Preparing files for package_index.json file

The following lines zip the executables, calculates the SHA-256 checksum and
file size.

```
mkdir zip
zip ./zip/hello-windows-32.zip  ./BUILD/hello-windows-32.exe && shasum -a 256 ./zip/hello-windows-32.zip  && ls -l ./zip/hello-windows-32.zip
zip ./zip/hello-windows-64.zip  ./BUILD/hello-windows-64.exe && shasum -a 256 ./zip/hello-windows-64.zip  && ls -l ./zip/hello-windows-64.zip
zip ./zip/hello-linux-32.zip    ./BUILD/hello-linux-32       && shasum -a 256 ./zip/hello-linux-32.zip    && ls -l ./zip/hello-linux-32.zip
zip ./zip/hello-linux-64.zip    ./BUILD/hello-linux-64       && shasum -a 256 ./zip/hello-linux-64.zip    && ls -l ./zip/hello-linux-64.zip
zip ./zip/hello-linux-armv6.zip ./BUILD/hello-linux-armv6    && shasum -a 256 ./zip/hello-linux-armv6.zip && ls -l ./zip/hello-linux-armv6.zip
zip ./zip/hello-linux-armv8.zip ./BUILD/hello-linux-armv8    && shasum -a 256 ./zip/hello-linux-armv8.zip && ls -l ./zip/hello-linux-armv8.zip
zip ./zip/hello-mac-32.zip      ./BUILD/hello-mac-32         && shasum -a 256 ./zip/hello-mac-32.zip      && ls -l ./zip/hello-mac-32.zip
zip ./zip/hello-mac-64.zip      ./BUILD/hello-mac-64         && shasum -a 256 ./zip/hello-mac-64.zip      && ls -l ./zip/hello-mac-64.zip
```
