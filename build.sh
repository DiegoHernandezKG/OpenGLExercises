#!/bin/bash

mkdir -p build
cd build
cmake ..
make -j$(nproc)

# Ensure bin/ exists
mkdir -p ../bin

# Copy resources to bin/
cp -r ../resources ../bin/

echo "Build complete! Executable is in bin/"
