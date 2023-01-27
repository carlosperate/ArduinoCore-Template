# Custom Tool

This folder and its contents are **not necessary** for the Arduino Core.
This is a very simple "hello world" program in the
[Go programming language](https://golang.org/), compiled to a wide range
of platforms to show how to integrate custom tools the with the Arduino Core.

A custom tool could be a compiler like GCC, a debugger/programmer like OpenOCD
or avrdude, or anything else needed to prepare/build/compile/load or anything
else the Arduino Core needs that is not provided by the Arduino IDE already.

The final executables can then be uploaded to an online storage service and
linked into the package_index.json file, so that they can be downloaded
with the rest of the Arduino Core.

## Building And Preparing This Tool

### Cross-compiling this programme for the different platforms

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

### Preparing the files for the package_index.json file

The following commands will zip the executables, calculates the SHA-256
checksum and calculate the file size of the zip files.
This data has to be added into the package_index.json file.

```bash
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

The executables can be uploaded to an online storage service (AWS, DropBox, or
others), and the final file URLs added to the the package_index.json file.

As this Arduino Core template is already hosted in GitHub, uploading the files
into a [GitHub Release](https://docs.github.com/en/repositories/releasing-projects-on-github/managing-releases-in-a-repository)
is the simplest and most effective way to host the files online.
The only restriction is that each file has a size limit of 2 GB, but there is
no limit in the number of files in a GitHub Release, or the number of Releases.

The custom tool should versioned and it is recommend to use that
version number as part of the git tag and GitHub release version and title.

### Why not host the executables in GitHub Pages?

The `package_index.json` file is hosted in GitHub pages because it is a growing
JSON file, and the latest version of the file should always be hosted with the
same URL.

Any custom tool to be added to an Arduino Core should be versioned, and all of
tools versions have to be always available, as older version of the
Arduino Core are likely to be linked a older versions of the tool.

Technically we could include all the different tool executables
inside the docs folder (which contents are published online with GitHub Pages),
but that is **not recommended**. Git is designed for text files, it will
struggle with these executable/binary files, and
[GitHub also has some limitations](https://docs.github.com/en/repositories/working-with-files/managing-large-files/about-git-large-file-storage).

### Should the tool source code be hosted here?

In this case, because this "custom tool" is a very simple example, the source
code is stored in the same repository as the rest of the Arduino Core. However
with more complex tools, it might be better to create a new repository just for
the tool and release it independently from the Arduino Core.

In that cases you can also create GitHub releases in that repository and
use those file URS in the `package_index.json` file hosted here.

### What about other tools from vendors or other sources?

If a vendor host their tools online in a downloadable format that can be
unzipped by the Arduino IDE you can use those URLs for the
`package_index.json` file.

If the tool has a permissive license that lets you re-host the file in a
different storage service, than you might want to consider to do that instead.
This is because a download link outside of your control can disappear at any
point, and that can break the installation of your Arduino Core.
