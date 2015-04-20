#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include "Territory.h"
#include "Deck.h"
#include "Card.h"
#include "World.h"

using namespace std;
class Player
{
    public:
        //Default constructor
        Player();
        //Normal constructor
        Player(string name, int ID);
        //Deconstructor
        virtual ~Player();
        //Returns the player's name
        string getName();
        //Returns the player's ID
        int getID();
        //Checks if 2 players are equal to each other, using their names
        bool equals(Player p);
        //Returns a pointer to the vector of territories the player owns
        vector<Territory*> getControlledTerritories();
        //Adds a territory to the vector of territories the player owns
        void addControlledTerritory(Territory* t);
        //Removes a territory to the vector of territories the player owns
        void removeControlledTerritory(Territory* t);
        //Sets the number of troops in the player's troop pool
        void setTroops(int troops);
        //Removes troops from the player's troop pool
        void takeTroops(int troops);
        //Returns the number of player's in the player's troop pool
        int getTroops();
        //Sets the troops per turn value for the player
        void setTroopsPerTurn(int troops);
        //Returns the troops per turn value for the player
        int getTroopsPerTurn();
        //Calculates the troops per turn, based on how many territories they own and if they own a complete continent
        int calculateTroopsPerTurn(World earth);
        //Sets the number of stars the player owns
        void setStars(int s);
        //Returns the number of stars the player owns
        int getStars();
        //Returns the player's hand of cards
        vector<Card> getHand();
    private:
        //The player's name
        string name;
        //The player's numeric ID number
        int ID;
        //The number of troops available to allocate
        int troopsPool;
        //The number of troops added to the player's troops pool at the beginning of the turn
        int troopsPerTurn;
        //The number of the stars the player owns, can be turn in for additional troops in the player's troops pool
        int stars;
        //The vector of territories that the player controls
        vector<Territory*> controlled_territories;
        //The player's hand of cards
        vector<Card> hand;
};

#endif // PLAYER_H
