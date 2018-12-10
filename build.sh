#bin/sh

g++ src/*.cpp -o transmiter
cd src/binaries && make clean && make
