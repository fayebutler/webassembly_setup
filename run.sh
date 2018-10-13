#!/bin/bash


cd src/cpp/
make
cd ../../
mkdir -p dist/cpp
emcc --bind -o dist/cpp/appWASM.js src/cpp/test.bc
