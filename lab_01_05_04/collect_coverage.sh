#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
gcc -std=c99 -Wall -Werror -g -O0 --coverage -c $SCRIPT_DIR/main.c -o $SCRIPT_DIR/main.o
gcc $SCRIPT_DIR/main.o -o $SCRIPT_DIR/app.exe --coverage -lm
$SCRIPT_DIR/func_tests/scripts/func_tests.sh
gcov $SCRIPT_DIR/main.c
