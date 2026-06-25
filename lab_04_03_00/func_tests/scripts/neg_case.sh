#!/bin/bash

input="$1"

/home/tunathebasic/Documents/C_labs/iu7-cprog-labs-2026-daoa/lab_02_03_02/app.exe < "$input" > /dev/null 2>&1
ret=$?

if [ "$ret" -ne 0 ]; then
    exit 0
else
    exit 1
fi