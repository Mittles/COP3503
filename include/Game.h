#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Territory.h"
#include "World.h"
#include "Deck.h"

class Game
{
    public:
        Game(vector<Player> players, vector<vector<Territory> > world, Deck playDeck);
        void init_game();
        void nextTurn();
        virtual ~Game();
    protected:
    private:
        Player *currentPlayer;
        vector<Player> players;
        vector<vector<Territory> > world;
        Deck playDeck;
};

#endif // GAME_H
