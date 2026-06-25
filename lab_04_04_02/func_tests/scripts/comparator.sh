#!/bin/bash
file1="$1"
file2="$2"


res1=$(grep -Eo '[a-zA-Z]+' "$file1" | tr '\n' ' ')
res2=$(grep -Eo '[a-zA-Z]+' "$file2" | tr '\n' ' ')

if [ "$res1" = "$res2" ]; then
    exit 0
else
    exit 1
fi