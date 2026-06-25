#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
CFLAGS="-std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O2"

clang -c $CFLAGS main.c -o main.o
clang -c $CFLAGS string_funcs.c -o string_funcs.o
clang -c $CFLAGS string_io.c -o string_io.o

clang "$SCRIPT_DIR"/*.o -o "$SCRIPT_DIR/app.exe" -lm