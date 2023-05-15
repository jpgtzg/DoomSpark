#! /bin/bash

echo "Compiling..."

set -u -e

make -f MakeFile

echo "Running..."

./app