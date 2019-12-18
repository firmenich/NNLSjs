This is a wrapper of Eigen-NNLS package into webassambly javascript

original code comes from: https://github.com/hmatuschek/eigen3-nnls


## Need to have emscripten installed

## activate g++
export PATH=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin:/Applications/Xcode.app/Contents/Developer/usr/bin:$PATH

## how to compile for c++/g++:
g++ -o nnls -std=c++11 -I/usr/local/include/eigen3 nnls.cpp

## activate emb
echo "source /Users/tgg/Github/emsdk/emsdk_env.sh --build=Release > /dev/null" >> ~/.bashrc
This directory contains the C++ Eigen-NNLS for emscripten.

## how to compile for webasm/js:

./build.sh

## launch web page:
./serve.sh


## manual compilation
emcc --bind cpp/Deconv.cpp  -std=c++11 -I/usr/local/include/eigen3 -s WASM=1 -o deconv.js
mv deconv.js web/gen/
mv deconv.wasm web/gen/
