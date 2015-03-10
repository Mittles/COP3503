#!/bin/sh
JOPTS=-j5
BDIR=$(pwd)/SDL2

mkdir -p $BDIR

mkdir -p ./src/SDL/build
cd ./src/SDL/build
../configure --prefix=$BDIR 
make $JOPTS && make install-lib && make install-hdrs && make install-bin
