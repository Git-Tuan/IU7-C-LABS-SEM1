#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"


clang -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion \
      -fsanitize=memory -g -fno-omit-frame-pointer \
      -c $SCRIPT_DIR/main.c -o $SCRIPT_DIR/main.o 

clang $SCRIPT_DIR/main.o -o $SCRIPT_DIR/app.exe \
      -lm -fsanitize=memory

