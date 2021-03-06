#!/bin/sh
JOPTS=-j5
BDIR=$(pwd)/lib

mkdir -p $BDIR/SDL2

mkdir -p ./src/SDL/build
cd ./src/SDL/build
../configure --prefix=$BDIR/SDL2
make $JOPTS && make install-lib && make install-hdrs && make install-bin

cd ../../

##tar -xzf ./SDL2_image.tar.gz
##tar -xzf ./SDL2_ttf.tar.gz

cd ./SDL2_image
./configure --prefix=$BDIR/SDL2
make $JOPTS all && make install

cd ../SDL2_ttf
./configure --prefix=$BDIR/SDL2
make $JOPTS all && make install

##cd ../../
##mkdir -p bin/Debug
##cp lib/SDL2/lib/* bin/Debug/
