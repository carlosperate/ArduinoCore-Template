# Arduino Core Template

This is a template to create an Arduino Hardware Core.

WIP - Explain what is an Arduino Core.


## Information used to populate project files

- Vendor name: Your Name
- Maintainer: Your Name
- Core full name: Arduino Core Template
- Core short name: template
    - WIP - used in boards.txt
- Architecture: template-arch
    - This is the processor architecture for the core, e.g. `avr`, `samd`, etc.
- Board 1 name: Arduino Core Template Board One
- Version: 0.0.1
    - All versions should follow the
      [Semantic Versioning 2.0.0](https://semver.org/spec/v2.0.0.html)
      specification
- Website: https://carlosperate.github.io/ArduinoCore-Template
- Docs: https://carlosperate.github.io/ArduinoCore-Template/docs


## Directory Structure

- `cores`: This folder contains the Arduino Core C/C++ source code (the files
  that implement the Arduino API and libraries).
- `docs`: This folder is not part of the Arduino Core, but it is used to be able
  host static files online via [GitHub Pages](https://pages.github.com/). This
  is needed to provide a JSON file URL to the Arduino IDE, so that the IDE can
  install the Arduino Core.
- `custom-tools`: This folder and its contents are **not necessary** for the
  Arduino Core. They contain a hello world program, compiled to a wide range
  of platforms to show how to integrate custom tools the your Arduino core.


## Files

- `boards.txt`: Defines the Arduino boards for this core.
- `platform.txt`: Defines how to use the tooling to build with this core.
- `package_info.json`: This files is not packaged inside the core, instead it is
  hosted online and contains the information for the Arduino IDE to install
  this core. The URL to this files is added by the user to the Arduino IDE
  so that this Arduino Core Template can appear in the Arduino Boards Manager.
  More information can be found in the `docs/README.md` file.


## Arduino IDE minimum version

- 1.6.4
