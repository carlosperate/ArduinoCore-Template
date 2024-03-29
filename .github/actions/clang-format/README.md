# Clang Format GitHub Action

This GitHub Action will run clang-format on the codebase using the
`run-clang-format.py` tool.

It will only show the diff on the terminal, it won't apply the changes to the
codebase.

To use create a workflow like this one:

```yml
name: Code Style Checker

on:
  push:
    branches:
    - master

jobs:
  style-checker:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3
    - name: Run local action clang-format
      uses: ./.github/actions/clang-format

  style-checker-args:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3
    - name: Run local action clang-format
      uses: ./.github/actions/clang-format
      with:
        args: -r . --style=Mozilla
```

Instead of running the default arguments you can pass your own arguments to
`run-clang-format.py`, see the available options in its documentation:
https://github.com/Sarcasm/run-clang-format


## `run-clang-format.py`

A wrapper script around clang-format, suitable for linting multiple files and
to use for continuous integration.

This script comes from https://github.com/Sarcasm/run-clang-format
commit `39081c9c42768ab5e8321127a7494ad1647c6a2f`.

### `run-clang-format.py` license

MIT License

Copyright (c) 2017 Guillaume Papin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
