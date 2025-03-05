#!/bin/bash

mkdir -p build_linux
cd build_linux
cmake ..
make -j$(nproc)

# Ensure bin/ exists
mkdir -p ../bin_linux

# Copy resources to bin/
cp -r ../resources ../bin_linux/

echo "Build complete! Executable is in bin_linux/"
