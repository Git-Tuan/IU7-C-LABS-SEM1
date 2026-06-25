#!/bin/bash

file1=$1
file2=$2

if [[ ! -f $file1 ]] || [[ ! -f $file2 ]]; then
    exit 200
fi

diff -w -q "$file1" "$file2" > /dev/null 2>&1

if [ $? -eq 0 ]; then
    exit 0
else
    exit 201
fi