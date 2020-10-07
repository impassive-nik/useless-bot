#!/bin/bash
set -euo pipefail

SCRIPT_PATH=$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")

rm -rf $SCRIPT_PATH/build/
mkdir $SCRIPT_PATH/build
cd $SCRIPT_PATH/build

cmake ..