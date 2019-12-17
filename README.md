## activate emb & g++ properly
export PATH=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin:/Applications/Xcode.app/Contents/Developer/usr/bin:$PATH
echo "source /Users/tgg/Github/emsdk/emsdk_env.sh --build=Release > /dev/null" >> ~/.bashrc
This directory contains the C++ Eigen-NNLS for emscripten.
## how to compile for c++:
g++ -o nnls -std=c++11 -I/usr/local/include/eigen3 nnls.cpp
## how to compile for webasm/js:
emcc --bind ../cpp/Deconv.cpp  -std=c++11 -I/usr/local/include/eigen3 -s WASM=1 -o deconv.js
mv deconv.js web/gen/
mv deconv.wasm web/gen/