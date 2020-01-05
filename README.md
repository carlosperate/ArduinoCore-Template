# Arduino Core Template

This is a template to create an Arduino Hardware Core.

WIP - Explain what is an Arduino Core.


## Information used to populate project files

- Vendor name: `Your Name`
- Maintainer: `Your Name`
- Core full name: `Arduino Core Template`
- Core short name: `template`
    - WIP - used in boards.txt
- Architecture: `template-arch`
    - This is the processor architecture for the core, e.g. `avr`, `samd`, etc.
- Board 1 name: `Arduino Core Template Board One`
- Board 2 name: `Arduino Core Template Board Two`
- Version: `0.0.1`
    - All versions should follow the
      [Semantic Versioning 2.0.0](https://semver.org/spec/v2.0.0.html)
      specification
- Website: https://carlosperate.github.io/ArduinoCore-Template
- Docs: https://carlosperate.github.io/ArduinoCore-Template/docs


## Directory Structure

- `.github`: This folder contains a GitHub Action to do cody style check using
  ClangFormat and a GitHub Workflow to run the GH Action on each commit.
- `cores`: This folder contains the Arduino Core C/C++ source code (the files
  that implement the Arduino API and libraries).
- `docs`: This folder is not part of the Arduino Core, but it is used to be able
  host static files online via [GitHub Pages](https://pages.github.com/). This
  is needed to provide a JSON file URL to the Arduino IDE, so that the IDE can
  install the Arduino Core.
- `custom-tools`: This folder and its contents are **not necessary** for the
  Arduino Core. They contain a hello world program, compiled to a wide range
  of platforms to show how to integrate custom tools the your Arduino core.
  The custom tools for your core could be a new compiler, programmer or build
  tool.


## Files

- `boards.txt`: Defines the Arduino boards for this core.
- `platform.txt`: Defines how to use the tooling to build with this core.
- `package_info.json`: This files is not packaged inside the core, instead it is
  hosted online and contains the information for the Arduino IDE to install
  this core. The URL to this files is added by the user to the Arduino IDE
  so that this Arduino Core Template can appear in the Arduino Boards Manager.
  More information can be found in the `docs/README.md` file.
- `programmers.txt`: WIP.
- `keywords.txt`: WIP.


## Installing

WIP - Explain this process a bit better.

1. Run a static server from the repository:
    ```
    python -m SimpleHTTPServer
    ```
2. Add this URL to the Arduino IDE Settings > Additional Board Manager URLS:
    ```
    http://localhost:8000/docs/package_YourName_ArduinoCoreTemplate_index.json
    ```
3. Install the ArduinoCoreTemplate Core from the Arduino IDE Boards Manager.
4. Close the Arduino IDE
5. Find the Arduino `SKETCHBOOK` directory, which is the Operating System
    dependent:
    - Windows: `%USERPROFILE%\Documents\Arduino`
    - macOS: `~/Documents/Arduino`
    - Linux: `~/Arduino`
6. Open the terminal at the `SKETCHBOOK` directory and git clone into a
    specific subdirectory:
    ```
    git clone https://github.com/carlosperate/ArduinoCore-Template.git hardware/ArduinoCoreTemplate/template-arch/
    ```
7. Reopen the Arduino IDE


## Arduino IDE minimum version

Some of the features used in this template are not available in earlier version
of the Arduino IDE, so the currently minimum version is:

- 1.6.6
