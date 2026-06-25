#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
DATA_DIR="$SCRIPT_DIR/../data"

num_of_tests=0
passed=0
failed=0

for file in "$DATA_DIR"/pos_*_in.txt; do
    name=$(basename "$file")
    num=${name#pos_}
    num=${num%_in.txt}

    out="$DATA_DIR/pos_${num}_out.txt"

    num_of_tests=$((num_of_tests+1))
    "$SCRIPT_DIR/pos_case.sh" "$file" "$out"

    if [ $? -eq 0 ]; then
        passed=$((passed+1))
    else
        failed=$((failed+1))
    fi
done

for file in "$DATA_DIR"/neg_*_in.txt; do

    num_of_tests=$((num_of_tests+1))

    "$SCRIPT_DIR/neg_case.sh" "$file"
    
    if [ $? -eq 0 ]; then
        passed=$((passed+1))
    else
        failed=$((failed+1))
    fi
done

echo "$passed/$num_of_tests PASSED"
echo "$failed FAILED"

exit "$failed"