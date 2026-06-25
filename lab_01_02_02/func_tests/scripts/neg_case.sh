#!/bin/bash

input="$1"

./app.exe < "$input" > /dev/null 2>&1
ret=$?

if [ "$ret" -ne 0 ]; then
    exit 0
else
    exit 1
fi