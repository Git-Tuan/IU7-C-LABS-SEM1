#!/bin/bash

input="$1"

./app.exe < "$input"
ret=$?

if [ "$ret" -ne 0 ]; then
    exit 0
else
    exit 1
fi