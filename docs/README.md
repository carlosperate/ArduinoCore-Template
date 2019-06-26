# package_index.json

This file has to be hosted online to be able to add this Arduino Core to the
Arduino IDE. It contains metadata about the project and download URL for the
source code and tools required to use the Arduino Core.

More info about this file can be found in the
[official documentation](https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.6.x-package_index.json-format-specification).

When the file is hosted (more info in the
[Serving the file section](#serving-the-file)), its URL has to be entered in the
Arduino IDE settings > "Additional Boards Manager URLS" field.

![Board Manager ULR](https://user-images.githubusercontent.com/4189262/59982732-9ed55380-960e-11e9-90ef-d07b87e1179b.png)


## Populating the data

- package_index.json file name:
    - The file name format for this file is
      `package_YOURNAME_PACKAGENAME_index.json`.
    - So the file name used in this template is
    `package_YourName_ArduinoCoreTemplate_index.json`.
- General entries like `name`, `maintainer`, etc are covered in the general
  project README.md at the root of the repository.
- `category`: This field is reserved by the Arduino team, all external cores
  have to set this value to `Contributed`.
- `boards`: The values listed here will appear in this core description within
  the Arduino Boards Manager. Although not mandatory it should be the same
  as the board names listed in the `boards.txt` file.
- `toolsDependencies`: More info in the
  [Tools Dependencies](#tools-dependencies) section.
- `tools`: More info in the [Tools Dependencies](#tools-dependencies) section.
- `url`: The URL to a compressed file. Accepted formats are `zip`, `.tar.gz.`,
  or `.tar.bz2`
- `size`: The unit for all the size keys is bytes.
- `checksum`: Accepted formats are `MD5`, `SHA-1`, or `SHA-256`.


## This is a growing file

WIP - Explain how new versions are added to the package_index.json file.


## Serving the file

The package_xxx_index.json file has to be available online as a valid text or
JSON content type URL, so that users can add it to the Arduino IDE.
To do that the file has been included in the docs folder, so that it can be
statically served via GitHub pages. The option should be in the repository 
settings:

![Publishing the docs folder in GH Pages](https://user-images.githubusercontent.com/4189262/58943144-0bc79d00-8777-11e9-8aea-23d93d890dde.png)


## URLs inside package_index.json

The URLs inside this template package_index.json are real, and created from
this repository.

WIP - Indicate how to upload the repo source code in a GH release and link it.

WIP - Indicate how to upload all the custom-tools.


## Tools Dependencies

This package_index.json file includes 3 tools:

- custom-tool
- arm-none-eabi-gcc
- OpenOCD

The last two are provided by Arduino (denoted by the `"packager": "arduino",`
key in the JSON file), so the Arduino IDE will be able to find those tools and
install them without any additional information.

The first entry is a "custom tool" created from this repository to show how to
package and include additional tools into the Arduino Core.

The "custom tool" source code can be found in the `./custom-tool/` folder.
