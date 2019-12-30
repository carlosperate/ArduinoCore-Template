#!/bin/sh
# Stop execution on first error encountered
set -e

if [ -z $1 ]; then
    # No arguments passed to the script, run default (set -x prints cmds run)
    set -x
    for f in $(find . -name '*.h' -or -name '*.c' -or -name '*.cpp' -or -name '*.ino'); do
        echo "Check format for ${f}"
        set -x
        clang-format -style=Google ${f}
    done
else
    # Pass arguments to clang-format, run default (set -x prints cmds run
    for f in $(find . -name '*.h' -or -name '*.c' -or -name '*.cpp' -or -name '*.ino'); do
        echo "Check format for ${f}"
        set -x
        clang-format "$@" ${f}
    done
fi
