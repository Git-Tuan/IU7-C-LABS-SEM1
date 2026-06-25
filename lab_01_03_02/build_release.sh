#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

clang -std=c99 -Wall -Werror -Wpedantic -O2 -Wfloat-equal -Wfloat-conversion \
    -c "$SCRIPT_DIR/main.c" -o "$SCRIPT_DIR/main.o"
if [ "$?" != "0" ]; then
    echo "Failed to compile the code"
    exit 1
fi

clang "$SCRIPT_DIR/main.o" -o "$SCRIPT_DIR/app.exe" -lm

if [ "$?" != "0" ]; then
    echo "Failed to link the code"
    exit 1
fi