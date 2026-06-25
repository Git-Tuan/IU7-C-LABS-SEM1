#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
CFLAGS="-std=c99 -Wall -Werror -g -O0 --coverage"

for file in ./*.c; do
    filename=$(basename "$file" .c)
    gcc $CFLAGS -c "$file" -o "$filename.o"
    if [ $? -ne 0 ]; then 
    	echo "Error: failed to create $filename.o"
    	exit 1
    fi
done

gcc "$SCRIPT_DIR"/*.o -o "$SCRIPT_DIR/app.exe" --coverage -lm

"$SCRIPT_DIR/func_tests/scripts/func_tests.sh"

gcov "$SCRIPT_DIR"/*.c