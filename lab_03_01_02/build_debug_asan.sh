#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

CFLAGS="-std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -fsanitize=address -g -fno-omit-frame-pointer"

clang $CFLAGS -c "$SCRIPT_DIR/matrix_io.c" -o "$SCRIPT_DIR/matrix_io.o"
clang $CFLAGS -c "$SCRIPT_DIR/matrix_utils.c" -o "$SCRIPT_DIR/matrix_utils.o"
clang $CFLAGS -c "$SCRIPT_DIR/arr_o.c" -o "$SCRIPT_DIR/arr_o.o"
clang $CFLAGS -c "$SCRIPT_DIR/main.c" -o "$SCRIPT_DIR/main.o"

clang "$SCRIPT_DIR/main.o" "$SCRIPT_DIR/arr_o.o" \
      "$SCRIPT_DIR/matrix_utils.o" "$SCRIPT_DIR/matrix_io.o" \
      -o "$SCRIPT_DIR/app.exe" -lm -fsanitize=address