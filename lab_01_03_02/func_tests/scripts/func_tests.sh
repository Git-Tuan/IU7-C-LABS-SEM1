#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
DATA_DIR="$SCRIPT_DIR/../data"

passed=0
failed=0
num_of_tests=0
for file in "$DATA_DIR"/pos_*_in.txt; do
    name=$(basename "$file")
    num=${name#pos_}
    num=${num%_in.txt}
    num_of_tests=$((num_of_tests+1))

    out="$DATA_DIR/pos_${num}_out.txt"

    "$SCRIPT_DIR/pos_case.sh" "$file" "$out"
    
    if [ $? -eq 0 ]; then
        passed=$((passed+1))
        echo "Positive test $num_of_tests passed"
    else
        failed=$((failed+1))
        echo "Positive test $num_of_tests failed"
    fi
done


echo "$passed/$num_of_tests PASSED"
echo "$failed FAILED"

exit "$failed"