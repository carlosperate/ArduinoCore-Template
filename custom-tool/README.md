# Custom Tool

This folder and its contents are **not necessary** for the Arduino Core.
This is a very simple "hello world" program in the
[Go programming language](https://golang.org/), compiled to a wide range
of platforms to show how to integrate custom tools the with the Arduino core.

A custom tool could be a compiler like GCC, a debugger/programmer like OpenOCD
or avrdude, or anything else needed to prepare/build/compile/load or anything
else the Arduino Core needs that is not provided by the Arduino IDE already.

The final executables can then be uploaded online and linked into the
package_index.json file, so that they can be downloaded with the rest of the
Arduino Core.


## Cross-compiling this programme for the different platforms

This program is trivial, and the Go language was chosen because it's very easy
to cross-compile from a single platform:

```
GOOS=windows GOARCH=386           go build -o ./BUILD/custom-tool-windows-32/hello.exe
GOOS=windows GOARCH=amd64         go build -o ./BUILD/custom-tool-windows-64/hello.exe
GOOS=linux   GOARCH=386           go build -o ./BUILD/custom-tool-linux-32/hello
GOOS=linux   GOARCH=amd64         go build -o ./BUILD/custom-tool-linux-64/hello
GOOS=linux   GOARCH=arm   GOARM=6 go build -o ./BUILD/custom-tool-linux-armv6/hello
GOOS=linux   GOARCH=arm64         go build -o ./BUILD/custom-tool-linux-armv8/hello
GOOS=darwin  GOARCH=386           go build -o ./BUILD/custom-tool-mac-32/hello
GOOS=darwin  GOARCH=amd64         go build -o ./BUILD/custom-tool-mac-64/hello
```


## Preparing files for package_index.json file

The following lines will zip the executables, calculates the SHA-256 checksum
and calculate the file size of the zip files. This data has to be added into
the package_index.json file.

```
mkdir zip
cd BUILD/
zip -r ../zip/custom-tool-windows-32.zip  ./custom-tool-windows-32/  && shasum -a 256 ../zip/custom-tool-windows-32.zip  && ls -l ../zip/custom-tool-windows-32.zip
zip -r ../zip/custom-tool-windows-64.zip  ./custom-tool-windows-64/  && shasum -a 256 ../zip/custom-tool-windows-64.zip  && ls -l ../zip/custom-tool-windows-64.zip
zip -r ../zip/custom-tool-linux-32.zip    ./custom-tool-linux-32/    && shasum -a 256 ../zip/custom-tool-linux-32.zip    && ls -l ../zip/custom-tool-linux-32.zip
zip -r ../zip/custom-tool-linux-64.zip    ./custom-tool-linux-64/    && shasum -a 256 ../zip/custom-tool-linux-64.zip    && ls -l ../zip/custom-tool-linux-64.zip
zip -r ../zip/custom-tool-linux-armv6.zip ./custom-tool-linux-armv6/ && shasum -a 256 ../zip/custom-tool-linux-armv6.zip && ls -l ../zip/custom-tool-linux-armv6.zip
zip -r ../zip/custom-tool-linux-armv8.zip ./custom-tool-linux-armv8/ && shasum -a 256 ../zip/custom-tool-linux-armv8.zip && ls -l ../zip/custom-tool-linux-armv8.zip
zip -r ../zip/custom-tool-mac-32.zip      ./custom-tool-mac-32/      && shasum -a 256 ../zip/custom-tool-mac-32.zip      && ls -l ../zip/custom-tool-mac-32.zip
zip -r ../zip/custom-tool-mac-64.zip      ./custom-tool-mac-64/      && shasum -a 256 ../zip/custom-tool-mac-64.zip      && ls -l ../zip/custom-tool-mac-64.zip
```


## Uploading the executables

The executables can be attached to a GitHub release, and the final URLs added
to the the package_index.json file.

The custom tool should have a version number and it is recommend to use that
version number as part of the git tag and GitHub release version and title.

### Why not host the executables in GitHub Pages?

The package_index.json file is hosted in GitHub pages because it is a growing
JSON file, and the latest version of the file should always be hosted in the
same URL.

Any custom tool to be added to an Arduino Core should be versioned, and all of
the versions of tool are have to be available online, as each version of the
Arduino Core can be linked a different version of the tool. The versions linked
are indicated in the package_index.json file.

Technically we could include all the different versions of the executables
inside the docs folder (the folder published in GitHub Pages), but that is
**not** recommended.

A compiled version of a project shouldn't be hosted in the repository, together
with the source code. So, the best way to host these large executables is to add
them into a GitHub release.

In this case, because this "custom tool" is a very simple example, the source
code is stored in the same repository as the rest of the Arduino Core. However
with more complex tools, it might be better to create a new repository just for
the tool and release it independently from the Arduino Core.
