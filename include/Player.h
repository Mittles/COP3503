#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include "Territory.h"

using namespace std;
class Player
{
    public:
        Player(string name, int ID);
        virtual ~Player();
        string getName();
        int getID();
        vector<Territory*> getControlledTerritories();
    private:
        string name;
        int ID;
        vector<Territory*> controlled_territories;
        //vector<Card> hand;
};

#endif // PLAYER_H
