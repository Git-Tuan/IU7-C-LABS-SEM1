#!/bin/bash

file_stream_in=$1
file_stream_out_expect=$2 
file_args=$3             

if [[ ! -f $file_stream_in ]] || [[ ! -f $file_stream_out_expect ]] || [[ ! -f $file_args ]]; then
    exit 100
fi

base_name="${file_stream_in%_in.txt}"
in_file="${base_name}_in_file.txt"
out_file_txt="${base_name}_out_file.txt"
stdout_expected="$file_stream_out_expect"


read -r key arg2 arg3 arg4 < "$file_args"

temp_export="temp_export_$$.txt"
temp_stdout="temp_stdout_$$.txt"

case "$key" in
    sb)
        bin_file="$arg2"
        if [[ -f "$in_file" ]]; then
            ./app.exe import "$in_file" "$bin_file"
        fi
        ./app.exe sb "$bin_file" > "$temp_stdout"
        return_code=$?
        if [[ $return_code -ne 0 ]]; then
            exit $return_code
        fi
        ./func_tests/scripts/comparator.sh "$stdout_expected" "$temp_stdout"
        exit $?
        ;;

    fb)
        src_bin="$arg2"
        dst_bin="$arg3"
        substr="$arg4"
        if [[ -f "$in_file" ]]; then
            ./app.exe import "$in_file" "$src_bin"
        fi
        ./app.exe fb "$src_bin" "$dst_bin" "$substr"
        return_code=$?
        if [[ $return_code -ne 0 ]]; then
            exit $return_code
        fi
        ./app.exe export "$dst_bin" "$temp_export"
        ./func_tests/scripts/comparator.sh "$out_file_txt" "$temp_export"
        exit $?
        ;;

    db)
        bin_file="$arg2"
        if [[ -f "$in_file" ]]; then
            ./app.exe import "$in_file" "$bin_file"
        fi
        ./app.exe db "$bin_file"
        return_code=$?
        if [[ $return_code -ne 0 ]]; then
            exit $return_code
        fi
        ./app.exe export "$bin_file" "$temp_export"
        ./func_tests/scripts/comparator.sh "$out_file_txt" "$temp_export"
        exit $?
        ;;

    import)
        txt_file="$arg2"
        bin_file="$arg3"
        ./app.exe import "$txt_file" "$bin_file"
        return_code=$?
        if [[ $return_code -ne 0 ]]; then
            exit $return_code
        fi
        ./app.exe export "$bin_file" "$temp_export"
        ./func_tests/scripts/comparator.sh "$out_file_txt" "$temp_export"
        exit $?
        ;;

    export)
        bin_file="$arg2"
        txt_file="$arg3"
        if [[ -f "$in_file" ]]; then
            ./app.exe import "$in_file" "$bin_file"
        fi
        ./app.exe export "$bin_file" "$txt_file"
        return_code=$?
        if [[ $return_code -ne 0 ]]; then
            exit $return_code
        fi
        ./func_tests/scripts/comparator.sh "$out_file_txt" "$txt_file"
        exit $?
        ;;

    *)
        args=$(cat "$file_args")
        ./app.exe $args < "$file_stream_in" > "$temp_stdout"
        return_code=$?
        if [[ $return_code -ne 0 ]]; then
            exit $return_code
        fi
        ./func_tests/scripts/comparator.sh "$stdout_expected" "$temp_stdout"
        exit $?
        ;;
esac