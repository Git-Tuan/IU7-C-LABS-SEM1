#!/bin/bash

input_file=$1
args_file=$2
error_output="error_output.txt"

if [[ ! -f $input_file ]] || [[ ! -f $args_file ]]; then
    exit 100
fi

if ! ./app.exe $(cat "$args_file") <"$input_file" >"$error_output"; then
    exit 0
else
    exit 101
fi