#!/bin/sh
JOPTS=-j5
BDIR=$(pwd)/build

mkdir -p $BDIR

mkdir -p ./src/SDL/build
cd ./src/SDL/build
../configure --prefix=$BDIR 
make $JOPTS && make install-lib && make install-hdrs

GFLAGS=$(sdl2-config --cflags --libs)

cd ../../


