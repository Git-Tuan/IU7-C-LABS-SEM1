#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
CFLAGS="-std=c99 -Wall -Werror -g -O0 --coverage"

gcc  $CFLAGS -c "$SCRIPT_DIR/main.c" -o "$SCRIPT_DIR/main.o"

gcc $CFLAGS -c "$SCRIPT_DIR/matrix_io.c" -o "$SCRIPT_DIR/matrix_io.o"

gcc $CFLAGS -c "$SCRIPT_DIR/matrix_utils.c" -o "$SCRIPT_DIR/matrix_utils.o"

gcc $CFLAGS -c "$SCRIPT_DIR/arr_o.c" -o "$SCRIPT_DIR/arr_o.o"

gcc "$SCRIPT_DIR"/*.o -o "$SCRIPT_DIR/app.exe" --coverage -lm

"$SCRIPT_DIR/func_tests/scripts/func_tests.sh"

gcov "$SCRIPT_DIR"/*.c