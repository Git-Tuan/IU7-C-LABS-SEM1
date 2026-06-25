#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
$SCRIPT_DIR/clean.sh

$SCRIPT_DIR/build_debug.sh
if [ "$?" == "0" ]; then
    echo "DB status: SUCCESS"
fi

$SCRIPT_DIR/build_release.sh
if [ "$?" == "0" ]; then
    echo "RB status: SUCCESS"
fi

$SCRIPT_DIR/build_debug_asan.sh
if [ "$?" == "0" ]; then
    echo "Successfully built with asan"
fi

$SCRIPT_DIR/build_debug_msan.sh
if [ "$?" == "0" ]; then
    echo "Successfully built with msan"
fi

$SCRIPT_DIR/build_debug_ubsan.sh
if [ "$?" == "0" ]; then
    echo "Successfully built with ubsan"
fi

echo "Test results:"
$SCRIPT_DIR/collect_coverage.sh