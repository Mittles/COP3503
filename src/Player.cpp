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

bool Player::equals(Player p) {
    if (this->ID == p.getID()) {
        return true;
    } else {
        return false;
    }
}

vector<Territory*> Player::getControlledTerritories() {
    return this->controlled_territories;
}

void Player::addControlledTerritory(Territory* t) {
    controlled_territories.push_back(t);
}

Player::~Player()
{

}
