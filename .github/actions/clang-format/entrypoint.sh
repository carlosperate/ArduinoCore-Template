#!/bin/sh
# Stop execution on first error encountered
set -e

if [ -z $1 ]; then
    # No arguments passed, run default with run-clang-format.py (set -x prints cmds run)
    set -x
    python .github/actions/clang-format/run-clang-format.py \
        --recursive . \
        --extensions c,h,C,H,cpp,hpp,cc,hh,c++,h++,cxx,hxx,ino \
        --color always \
        --style Google
else
    # Pass arguments to run-clang-format (set -x prints cmds run)
    set -x
    python .github/actions/clang-format/run-clang-format.py $@
fi
