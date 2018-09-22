#!/bin/bash

mkdir -p dist/cpp

# search in src/cpp for all files
# get the filename of each and compile
# export using filename to dist/cpp
for file in src/cpp/*; do
  filename_ext=${file##*/}
  filename=${filename_ext%.*}
  emcc --bind -o dist/cpp/$filename.js src/cpp/$filename.cpp
done
