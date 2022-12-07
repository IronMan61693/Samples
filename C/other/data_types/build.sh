#!/bin/bash

BUILD="${PWD}/out/build"
FLAGS="-Wall"

if [ ! -d "$BUILD" ]; then
    mkdir -p $BUILD
fi

cmake -D CMAKE_C_FLAGS="$FLAGS" "${PWD}/CMakeLists.txt" -B "$BUILD"

(cd "$BUILD" && make)
echo "Your executable(s) will be found in $BUILD/executables "