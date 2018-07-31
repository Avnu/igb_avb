#!/bin/bash
set -ev

ROOT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

make kmod
make lib
