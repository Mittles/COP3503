#!/bin/sh
JOPTS=-j5
BDIR=$(pwd)

mkdir -p $BDIR/bin
mkdir -p $BDIR/lib

mkdir -p ./src/SDL/build
cd ./src/SDL/build
../configure --prefix=$BDIR --bindir=$BDIR/bin --libdir=$BDIR/lib
make $JOPTS && make install-lib
