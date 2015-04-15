#include "Player.h"

Player::Player(string name, int ID)
{
    this->name = name;
    this->ID = ID;
}

string Player::getName() {
    return this->name;
}

int Player::getID() {
    return this->ID;
}

vector<Territory*> Player::getControlledTerritories() {
    return controlled_territories;
}


Player::~Player()
{

}
