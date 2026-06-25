#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
CFLAGS="-std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O2"

clang -c $CFLAGS main.c -o main.o
clang -c $CFLAGS file_utils.c -o file_utils.o

clang "$SCRIPT_DIR"/*.o -o "$SCRIPT_DIR/app.exe" -lm