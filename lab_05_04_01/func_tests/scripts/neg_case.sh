#!/bin/bash

file_stream_in=$1
file_args=$2
out_file="error_output.txt"

if [[ ! -f $file_stream_in ]] || [[ ! -f $file_args ]]; then
    exit 100
fi

if ! ./app.exe $(cat "$file_args") <"$file_stream_in" >"$out_file"; then
    exit 0
else
    exit 101
fi