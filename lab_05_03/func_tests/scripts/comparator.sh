#!/bin/bash

file1=$1
file2=$2

if [[ ! -f $file1 ]] || [[ ! -f $file2 ]]; then
    exit 200
fi

regex="[+-]?[0-9][0-9]*(\.[0-9]+)?"

extract_numbers() {
    local file=$1
    local numbers=""
    
    while read -r line; do
        matches=$(echo "$line" | grep -Eo "$regex")
        numbers="$numbers $matches"
    done <"$file"
    
    matches=$(echo "$line" | grep -Eo "$regex")
    numbers="$numbers $matches"
    
    echo "$numbers"
}

numbers1=$(extract_numbers "$file1")
numbers2=$(extract_numbers "$file2")

normalized1=$(echo "$numbers1" | xargs)
normalized2=$(echo "$numbers2" | xargs)

if [ "$normalized1" == "$normalized2" ]; then
    exit 0
else
    exit 201
fi