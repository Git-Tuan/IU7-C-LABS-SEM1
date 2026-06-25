#!/bin/bash

file1="$1"
file2="$2"

num1=$(grep -Eo '\-[0-9]+.[0-9]+' "$file1")
num2=$(grep -Eo '\-[0-9]+.[0-9]+' "$file2")

if [ "$num1" = "$num2" ]; then
    exit 0
else
    exit 1
fi