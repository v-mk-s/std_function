#!/usr/bin/env bash

set -x

set -e
set -o pipefail

#./a.out | true

#VAR=`./a.out | true`
if [[ $(echo "abc" | grep "a") == "abc" ]]; then
	echo "OK"
else
	echo "NOT OK"
	exit 1
fi

if [[ $(echo "abc" | grep -oE "[abq]+") == "abc" ]]; then
	echo "OK"
else
	echo "NOT OK"
	exit 1
fi


