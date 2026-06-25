#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
DATA_DIR="$SCRIPT_DIR/../data"

passed=0
failed=0
pos_tests=0
neg_tests=0

for file in "$DATA_DIR"/pos_*_in.txt; do
    name=$(basename "$file")
    num=${name#pos_}
    num=${num%_in.txt}

    out="$DATA_DIR/pos_${num}_out.txt"
    pos_tests=$((pos_tests+1))

    "$SCRIPT_DIR/pos_case.sh" "$file" "$out"
    ret=$?

    if [ $ret -eq 0 ]; then
        passed=$((passed+1))
        echo "Positive test $pos_tests passed"
    else
        failed=$((failed+1))
        echo "Positive test $pos_tests failed"
    fi
done

for file in "$DATA_DIR"/neg_*_in.txt; do
    "$SCRIPT_DIR/neg_case.sh" "$file"
    ret=$?
    neg_tests=$((neg_tests+1))
    if [ $? -eq 0 ]; then
        passed=$((passed+1))
        echo "Negative test $neg_tests passed"
    else
        failed=$((failed+1))
        echo "Negative test $neg_tests failed"
    fi
done

num_of_tests=$(($pos_tests+$neg_tests))
echo "$passed/$num_of_tests PASSED"
echo "$failed FAILED"

exit "$failed"