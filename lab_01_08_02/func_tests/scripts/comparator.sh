#!/bin/bash

file1="$1"
file2="$2"

content1=$(sed -n '/Result:/,$p' "$file1" | tail -n +2 | cat -v)
content2=$(sed -n '/Result:/,$p' "$file2" | tail -n +2 | cat -v)

num1=$(echo "$content1" | grep -Eo '[0-9]+' | tr '\n' ' ')
num2=$(echo "$content2" | grep -Eo '[0-9]+' | tr '\n' ' ')

if [ "$num1" = "$num2" ]; then
    exit 0
else
    exit 1
fi