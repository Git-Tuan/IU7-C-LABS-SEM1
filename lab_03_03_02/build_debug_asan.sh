#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

CFLAGS="-std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -fsanitize=address -g -fno-omit-frame-pointer"

for file in ./*.c; do
    filename=$(basename "$file" .c)
    clang $CFLAGS -c "$file" -o "$filename.o"
    if [ $? -ne 0 ]; then 
    	echo "Error: failed to create $filename.o"
    	exit 1
    fi
done

clang  "$SCRIPT_DIR"/*.o -o "$SCRIPT_DIR/app.exe" -lm -fsanitize=address