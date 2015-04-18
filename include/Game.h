#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Territory.h"
#include "World.h"
#include "Deck.h"
#include <ctime>
#include <cstdlib>


class Game
{
    public:
        Game(vector<Player> players, World earth, Deck playDeck);
        void init_game();
        void nextTurn();
        void moveTroops(Territory* origin, Territory* destination, int troopNum);
        void moveAttack(Territory* a, Territory* b);
        virtual ~Game();
    protected:
    private:
        int currentPlayer;
        vector<Player> players;
        World earth;
        Deck playDeck;
};

#endif // GAME_H
