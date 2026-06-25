#!/bin/bash

input_file=$1
expected_output=$2
args_file=$3
temp_output="output.txt"

if [[ ! -f $input_file ]] || [[ ! -f $expected_output ]] || [[ ! -f $args_file ]]; then
    exit 100
fi

read -r mode param <"$args_file"

if [[ $mode == "s" ]]; then
    input_file="${input_file:0:23}in_file.txt"
    expected_output="${input_file:0:23}out_file.txt"
    
    ./app.exe import "$input_file" "$param"
    ./app.exe s "$param"
    ./app.exe export "$param" "$temp_output"
elif [[ $mode == "p" ]]; then
    input_file="${input_file:0:23}in_file.txt"
    
    ./app.exe import "$input_file" "$param"
    ./app.exe p "$param" >"$temp_output"
else
    ./app.exe $args <"$input_file" >"$temp_output"
    exit_code=$?
    
    if [[ $exit_code != 0 ]]; then
        exit $exit_code
    fi
fi

./func_tests/scripts/comparator.sh "$expected_output" "$temp_output"
exit $?