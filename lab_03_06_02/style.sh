#!/bin/bash

for c_file in ./*.c; do
	clang-format -i -style=Microsoft "$c_file"
done

for h_file in ./*.h; do
	clang-format -i -style=Microsoft "$h_file"
done

shfmt -s -w .
