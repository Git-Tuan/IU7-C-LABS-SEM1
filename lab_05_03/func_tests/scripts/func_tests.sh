#!/bin/bash

error_count=0

positive_inputs=$(find func_tests/data/ -name 'pos_??_in.txt' | wc -w)
positive_args=$(find func_tests/data/ -name 'pos_??_args.txt' | wc -w)
positive_outputs=$(find func_tests/data/ -name 'pos_??_out.txt' | wc -w)

if [[ positive_inputs -ne positive_args ]] || [[ positive_inputs -ne positive_outputs ]]; then
    echo "Positive testing failed"
elif [[ positive_inputs -ne 0 ]]; then
    test_files=$(ls func_tests/data/pos_??_in.txt)
    test_num=1

    for input_file in $test_files; do
        base_name="${input_file:0:23}"
        expected_output="${base_name}out.txt"
        args_file="${base_name}args.txt"

        if [[ $(wc -m <"$expected_output") -eq 0 ]]; then
            expected_output="${base_name}out_file.txt"
        fi

        if ./func_tests/scripts/pos_case.sh "$input_file" "$expected_output" "$args_file"; then
            echo "positive test $test_num PASSED"
        else
            echo "positive test $test_num FAILED"
            error_count=$((error_count + 1))
        fi

        test_num=$((test_num + 1))
    done
fi

negative_inputs=$(find func_tests/data/ -name 'neg_??_in.txt' | wc -w)
negative_args=$(find func_tests/data/ -name 'neg_??_args.txt' | wc -w)

if [[ negative_inputs -ne negative_args ]]; then
    echo "Negative testing failed"
elif [[ negative_inputs -ne 0 ]]; then
    test_files=$(ls func_tests/data/neg_??_in.txt)
    test_num=1

    for input_file in $test_files; do
        base_name="${input_file:0:23}"
        args_file="${base_name}args.txt"

        if ./func_tests/scripts/neg_case.sh "$input_file" "$args_file"; then
            echo "negative test $test_num PASSED"
        else
            echo "negative test $test_num FAILED"
            error_count=$((error_count + 1))
        fi

        test_num=$((test_num + 1))
    done
fi

exit $error_count