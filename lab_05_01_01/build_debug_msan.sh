#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
CFLAGS="-std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -fsanitize=memory -g -fno-omit-frame-pointer"

clang -c $CFLAGS main.c -o main.o
clang -c $CFLAGS file_utils.c -o file_utils.o

clang "$SCRIPT_DIR"/*.o -o "$SCRIPT_DIR/app.exe" -lm -fsanitize=memory

