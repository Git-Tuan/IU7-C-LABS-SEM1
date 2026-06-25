#!/bin/bash

pos_in_count=$(find func_tests/data/ -name 'pos_??_in.txt' | wc -w)
pos_args_count=$(find func_tests/data/ -name 'pos_??_args.txt' | wc -w)
pos_out_count=$(find func_tests/data/ -name 'pos_??_out.txt' | wc -w)

total_errors=0

if [[ $pos_in_count -ne $pos_args_count ]] || [[ $pos_in_count -ne $pos_out_count ]]; then
    echo "Positive testing cancelled: insufficient test files"
elif [[ $pos_in_count -ne 0 ]]; then
    pos_test_files=$(ls func_tests/data/pos_??_in.txt)
    test_num=1

    echo "Positive testing:"

    for input_file in $pos_test_files; do
        base_path="${input_file:0:23}"
        expected_output="${base_path}out.txt"
        args_file="${base_path}args.txt"

        if [[ $(wc -m < "$expected_output") -eq 0 ]] && [[ -f "${base_path}out_file.txt" ]]; then
            expected_output="${base_path}out_file.txt"
        fi

        if ./func_tests/scripts/pos_case.sh "$input_file" "$expected_output" "$args_file"; then
            echo "positive test $test_num PASSED"
        else
            echo "positive test $test_num FAILED"
            total_errors=$((total_errors + 1))
        fi

        test_num=$((test_num + 1))
    done
else
    echo "No positive tests found"
fi

neg_in_count=$(find func_tests/data/ -name 'neg_??_in.txt' | wc -w)
neg_args_count=$(find func_tests/data/ -name 'neg_??_args.txt' | wc -w)

if [[ $neg_in_count -ne $neg_args_count ]]; then
    echo "Negative testing cancelled: insufficient test files"
elif [[ $neg_in_count -ne 0 ]]; then
    neg_test_files=$(ls func_tests/data/neg_??_in.txt)
    test_num=1

    echo
    echo "Negative testing:"

    for input_file in $neg_test_files; do
        base_path="${input_file:0:23}"
        args_file="${base_path}args.txt"

        if ./func_tests/scripts/neg_case.sh "$input_file" "$args_file"; then
            echo "negative test $test_num PASSED"
        else
            echo "negative test $test_num FAILED"
            total_errors=$((total_errors + 1))
        fi

        test_num=$((test_num + 1))
    done
else
    echo "No negative tests found"
fi

exit $total_errors