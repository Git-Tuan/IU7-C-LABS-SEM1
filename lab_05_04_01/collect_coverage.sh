#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
CFLAGS="-std=c99 -Wall -Werror -g -O0 --coverage"

gcc -c $CFLAGS main.c -o main.o
gcc -c $CFLAGS file_utils.c -o file_utils.o
gcc -c $CFLAGS import_export.c -o import_export.o

gcc "$SCRIPT_DIR"/*.o -o "$SCRIPT_DIR/app.exe" --coverage -lm

"$SCRIPT_DIR/func_tests/scripts/func_tests.sh"

gcov "$SCRIPT_DIR"/*.c