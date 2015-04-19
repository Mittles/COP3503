#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Territory.h"
#include "World.h"
#include "Deck.h"
#include "DiceRoll.h"
#include "Attack.h"
#include <ctime>
#include <cstdlib>


class Game
{
    public:
        Game(vector<Player> players, World earth, Deck playDeck);
        int getCurrentPlayer();
        void init_game();
        void nextTurn();
        void moveTroops(Territory* origin, Territory* destination, int troopNum);
        void attack(Territory* origin, Territory* destination, int aTroops, int dTroops);
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
