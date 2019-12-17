rm build/ -rf
mkdir build
cd build
#source /Users/tgg/Github/emsdk/emsdk_env.sh
emcc --bind ../cpp/Deconv.cpp  -std=c++11 -I/usr/local/include/eigen3 -s WASM=1 -o deconv.js
mv deconv.js ../web/gen/
mv deconv.wasm ../web/gen/

