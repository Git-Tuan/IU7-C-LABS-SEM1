#!/bin/bash

in_file="$1"
out_expect="$2"

SCRIPT_DIR="$(dirname "$0")"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
APP="$PROJECT_ROOT/app.exe"

out_actual=$(mktemp)

"$APP" <"$in_file" >"$out_actual"

ret=$?

if [ "$ret" -ne 0 ]; then
	exit 1
fi

"$SCRIPT_DIR/comparator.sh" "$out_actual" "$out_expect"
exit $?
