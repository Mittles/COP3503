#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include "Territory.h"
#include "Deck.h"
#include "Card.h"

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
    private:
        string name;
        int ID;
        vector<Territory*> controlled_territories;
        vector<Card> hand;
};

#endif // PLAYER_H
