This is a wrapper of Eigen-NNLS package into webassambly javascript

original code comes from: https://github.com/hmatuschek/eigen3-nnls

## Need to have emscripten installed

## activate emb
source /Users/tgg/Github/emsdk/emsdk_env.sh --build=Release
This directory contains the C++ Eigen-NNLS for emscripten.

## how to compile nnls-wrapper.cpp for webasm/js:
you need to update the path to eigen3 in compile.sh file and than run it in the terminal:
./compile.sh 


## examples:
there is severals examples in NNLS.html 

./serve.sh

this will open your browser localhost:8080/NNLS.html, and activate your brower console. Click on one of the examples.

Guillaume
