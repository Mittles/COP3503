#!/bin/zsh
JOPTS=-j5
BDIR=$(pwd)
GNAME=game.run

tar xf ubuntu-14.04_amd64_lib.tar

g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/Attack.cpp -o Attack.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/Card.cpp -o Card.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/Deck.cpp -o Deck.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/DiceRoll.cpp -o DiceRoll.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/Game.cpp -o Game.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/main.cpp -o main.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/MoveTroops.cpp -o MoveTroops.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/Player.cpp -o Player.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/Territory.cpp -o Territory.o
g++ -Wall -g -Iinclude/SDL2 -Iinclude -c $BDIR/src/World.cpp -o World.o

g++ -Llib -o $GNAME Attack.o Card.o Deck.o DiceRoll.o Game.o main.o MoveTroops.o Player.o Territory.o World.o -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.:$BDIR/lib 

./$GNAME

echo "Please run export 'LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.:lib' because SDL is not installed on this system. It is dynamically linked for cross-platform development reasons."  
