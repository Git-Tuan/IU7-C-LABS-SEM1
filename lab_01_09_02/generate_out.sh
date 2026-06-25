#!/bin/bash

SRC_DIR="$(cd "$(dirname "$0")" && pwd)"
FULL_PATH="$SRC_DIR/func_tests/data"

for file in "$FULL_PATH"/pos_*_in.txt; do
    [ -f "$file" ] || continue
    
    name=$(basename "$file")
    num=${name#pos_}
    num=${num%_in.txt}
    out="$FULL_PATH/pos_${num}_out.txt"

    if [ -e "$SRC_DIR/app.exe" ]; then
        ./app.exe < "$file" | grep -Eo "[0-9]+\.[0-9]+" > "$out"
    else
        echo "app.exe doesn't exist, please create it before using this function"
        exit 1
    fi
done