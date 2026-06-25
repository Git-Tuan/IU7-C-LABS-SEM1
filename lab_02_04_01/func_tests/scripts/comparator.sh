#!/bin/bash
file1="$1"
file2="$2"


num1=$(grep -Eo '[0-9]+' "$file1" | tr '\n' ' ')
num2=$(grep -Eo '[0-9]+' "$file2" | tr '\n' ' ')

if [ "$num1" = "$num2" ]; then
    exit 0
else
    exit 1
fi