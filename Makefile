default:
	tar xf ubuntu-14.04_amd64_lib.tar

	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/Attack.cpp -o Attack.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/Card.cpp -o Card.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/Deck.cpp -o Deck.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/DiceRoll.cpp -o DiceRoll.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/Game.cpp -o Game.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/main.cpp -o main.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/MoveTroops.cpp -o MoveTroops.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/Player.cpp -o Player.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/Territory.cpp -o Territory.o
	g++ -Wall -g -Iinclude/SDL2 -Iinclude -c src/World.cpp -o World.o

	g++ -Llib -Wl,-rpath,lib Attack.o Card.o Deck.o DiceRoll.o Game.o main.o MoveTroops.o Player.o Territory.o World.o -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lpthread -Wl,--no-undefined -lm -ldl -lpthread -lrt -o ConquestOfTheWorld

clean:
	rm -f *.o *~
	
