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
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <iterator>


class Game
{
    public:
        //Constructor for game initializes with the data structure for the world, the deck, and a vector of Players
        Game(vector<Player> players, World earth, Deck playDeck);
        //Returns the int ID value of the current player
        int getCurrentPlayer();
        //Returns a pointer to the vector of players
        vector<Player>* getPlayers();
        //Calculates the troops per turn of every player, used to update the GUI
        void calculatePlayerTPT();
        //Initializes the game e.i. assigns territories, gives initial troops, ect
        void init_game();
        //Makes dice results available for GUI
        void setDie(int i, int r);
        //Returns a pointer to the dice, used in Main.cpp
        int* getDie();
        //Resets the values for the die
        void clearDie();
        //Ends the game and changes the game's "gameOver" field to true, the GUI checks for that bool and ends the process if it is
        void endGame();
        //Ends the current turn, does upkeep such as assigning stars, resets logic such as if the player has attacked or redeployed, ect.
        void nextTurn();
        //Moves troops from one friendly territory to another
        void moveTroops(Territory* origin, Territory* destination, int troopNum);
        //Attacks and resolves the dice rolls for attacking an enemy territory
        void attack(Territory* origin, Territory* destination, int aTroops, int dTroops);
        //Unified function utilizing moveTroops() and attack(), decides if the move is valid, and if it is a move or an attack, called by main
        void moveAttack(Territory* a, Territory* b);
        //Allocates troops to a territory from the player's troop pool
        void allocate_Troops(Territory* t);
        //Converts stars from a player's star pool into troops for the player to allocate
        void exchangeStars();
        //Allows the player to move their troops once per turn after attacking
        void redeploy(Territory* a, Territory* b);
        //Checks if the game is over
        bool isGameOver();
        //Deconstructer
        virtual ~Game();
    protected:
    private:
        //Int value tracks who's turn it is
        unsigned int currentPlayer;
        //Int value tracks what phase of the turn the player is in
        int turnPhase;
        //Tracks what turn it is
        int turn;
        //Tracks if a territory has been captured by the current player this turn
        bool capturedTerritory;
        //Tracks if the game is over
        bool gameOver;
        //Tracks if the current player has redeployed this turn
        bool redeployed;
        //Stores the players
        vector<Player> players;
        //The data structure containing all the Territory objects
        World earth;
        //The data structure containing all the cards
        Deck playDeck;
        //The data structure containing the results of a dice roll, utilized to draw the dice in the GUI
        int dieResults[5];
};

#endif // GAME_H
