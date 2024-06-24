# Arduino Core Template

This is a template to create an Arduino Core (an Arduino port for a new board
or platform).

This template is currently under development, so the code and documentation
are not yet complete. Nevertheless, if you are creating a new Arduino Core,
you can build on top of what is already here as a base, and go from there.


## Information used to populate project files

- Vendor name: `vendorname`
- Maintainer: `Your Name`
- Core full name: `Arduino Core Template`
- Architecture: `template-arch`
    - This is the processor architecture for the core, e.g. `avr`, `samd`, etc.
- Board 1 name: `Arduino Core Template Board One`
- Board 2 name: `Arduino Core Template Board Two`
- Version: `0.0.1`
    - All versions should follow
      [Semantic Versioning 2.0.0](https://semver.org/spec/v2.0.0.html).
- Website: https://carlosperate.github.io/ArduinoCore-Template
- Docs: https://carlosperate.github.io/ArduinoCore-Template/docs


## Directory Structure

- `.github`: This folder contains a GitHub Action to do code style check using
  ClangFormat, and a GitHub Action Workflow to run it on each commit.
- `cores`: This folder contains the Arduino Core C/C++ source code (the files
  that implement the Arduino API and libraries).
- `docs`: This folder is not part of the Arduino Core, but it is used to be
  able host static files online via [GitHub Pages](https://pages.github.com/).
  This is needed to provide a JSON file URL for the users to add the Arduino
  IDE, so that the Arduino Core can be installed via the Boards Manager.
- `custom-tools`: This folder and its contents are **not necessary** for the
  Arduino Core. They contain a hello world program, compiled to a wide range
  of platforms to use it as an example showing how to integrate custom tools
  (like compilers, build tools, or debuggers, etc) with your Arduino core.


## Special Files

- `boards.txt`: Defines the Arduino boards for this core. 
- `platform.txt`: Defines how the Arduino IDE/CLI use the tooling to build
  and upload with this core.
- `docs/package_info.json`: This files is not packaged inside the Arduino Core,
  and it is instead hosted online using GitHub Pages. This file contains the
  information required by the Arduino IDE/CLI to be able to install the Arduino
  Core into their environment.
  The URL to this files is added by the user to the Arduino IDE, so that the
  Arduino Board Manager can install this Core.
  More information can be found in the `docs/README.md` file.
- `programmers.txt`: Contains definitions to use external programmers, for
  example to flash a bootloader (which is usually only required once) or to
  flash a compiled Arduino Sketch.
- `keywords.txt`: WIP.


## Installing

### Install for development

For development these are the instructions to install this Arduino Core from
the GitHub repository:

1. Locate the Arduino `SKETCHBOOK` directory, which depends on your Operating
  System:
    - Windows: `%USERPROFILE%\Documents\Arduino`
    - macOS: `~/Documents/Arduino`
    - Linux: `~/Arduino`
2. Clone this repository in the following `SKETCHBOOK` subdirectory:
    ```
    git clone https://github.com/carlosperate/ArduinoCore-Template.git <SKETCHBOOK_PATH>/hardware/vendorname/template/
    ```
3. The ArduinoCore-API sources have to be added to the Arduino Core. There are
  two options for this step:
    1. In a different directory, clone the repo ArduinoCore-API repo and
      create a symlink to into the `cores/api` directory inside 
      ArduinoCore-Template project:
        ```
        git clone https://github.com/arduino/ArduinoCore-API.git
        ln -s <ArduinoCore-API_PATH>/api <SKETCHBOOK_PATH>/hardware/vendorname/template/cores/template/api/
        ```
    2. Or simply copy the contents of the `api` folder from
      [ArduinoCore-API](https://github.com/arduino/ArduinoCore-API) into the
      `<SKETCHBOOK_PATH>/hardware/vendorname/template/cores/template/api/`
      directory.
4. Open (or restart) the Arduino IDE
5. The "Arduino Core Template Boards" option should now appear in the
  `tools/board` menu.

### Install as a user

As this is just a template, it is not intended to be used directly by users.
However, for your own release of an Arduino Core (based on this template,
created from scratch, or from a different Core), these would an example
of the user instructions:

- Download, install, and start the Arduino IDE
- Open the IDE preferences or settings
- In the "Additional boards manager URLs" section add the following URL:
  `https://carlosperate.github.io/ArduinoCore-Template/docs/package_YourName_ArduinoCoreTemplate_index.json`
- Open the Board Manager from the `tools/board` menu.
- Find the "Arduino Core Template" core and click its "Install" button
- Done! 🎉
  You can now select the "Arduino Core Template" from the `tools/board` menu.


## ArduinoCore-API library

WIP - Include info about the API repo and why it is not included here.


## Missing features

The list itself is not yet updated, but will soon contain all items still left
to implement.

- Variants

## Arduino IDE minimum version

Some of the features used in this template are not available in earlier version
of the Arduino IDE, so the currently minimum version is:

- 1.6.6
