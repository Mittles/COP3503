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
        Player(string name, int ID);
        virtual ~Player();
        string getName();
        int getID();
        bool equals(Player p);
        vector<Territory*> getControlledTerritories();
        void addControlledTerritory(Territory* t);
        void setTroops(int troops);
        void takeTroops(int troops);
        int getTroops();
        void setTroopsPerTurn(int troops);
        int getTroopsPerTurn();
        int calculateTroopsPerTurn(World earth);
        int getStars();
    private:
        string name;
        int ID;
        int troopsPool;
        int troopsPerTurn;
        vector<Territory*> controlled_territories;
        vector<Card> hand;
};

#endif // PLAYER_H
