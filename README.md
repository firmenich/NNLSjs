This is a wrapper of Eigen-NNLS package into webassambly javascript

original code comes from: https://github.com/hmatuschek/eigen3-nnls


## Need to have emscripten installed

## activate g++
export PATH=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin:/Applications/Xcode.app/Contents/Developer/usr/bin:$PATH

## how to compile for c++/g++:
you will need to change -I path to eigen3 include files based on your installation setup:
for me it's:
g++ -o nnls -std=c++11 -I/usr/local/include/eigen3 nnls.cpp

## activate emb
echo "source /Users/tgg/Github/emsdk/emsdk_env.sh --build=Release > /dev/null" >> ~/.bashrc
This directory contains the C++ Eigen-NNLS for emscripten.

## how to compile for webasm/js:
code is already compile if you want to make modification you need to recompile:
./build.sh

## manual compilation
you will need to change -I path to eigen3 include files based on your installation setup:
for me it's:
run those command lines in a terminal:
emcc --bind cpp/Deconv.cpp  -std=c++11 -I/usr/local/include/eigen3 -s WASM=1 -o deconv.js
mv deconv.js web/gen/
mv deconv.wasm web/gen/


## js example:
there is a initial example available in nnls.js

./serve.sh

this will open your browser, in the browser console copy paste the full code

Guillaume
