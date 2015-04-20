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
#include <limits>
#include <algorithm>


class Game
{
    public:
        Game(vector<Player> players, World earth, Deck playDeck);
        int getCurrentPlayer();
        vector<Player> getPlayers();
        void init_game();
        void nextTurn();
        void moveTroops(Territory* origin, Territory* destination, int troopNum);
        void attack(Territory* origin, Territory* destination, int aTroops, int dTroops);
        void moveAttack(Territory* a, Territory* b);
        void allocate_Troops(Territory* t);
        void exchangeStars();
        void redeploy(Territory* a, Territory* b);
        bool isGameOver();
        virtual ~Game();
    protected:
    private:
        int currentPlayer;
        int turnPhase;
        int turn;
        bool capturedTerritory;
        bool gameOver;
        vector<Player> players;
        World earth;
        Deck playDeck;
};

#endif // GAME_H
