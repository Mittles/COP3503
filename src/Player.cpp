#include "Player.h"

Player::Player(string name, int ID)
{
    this->name = name;
    this->ID = ID;
    stars = 0;
}

string Player::getName() {
    return this->name;
}

void Player::setTroops(int troops) {
    this->troopsPool = troops;
}

void Player::takeTroops(int troops) {
    this->troopsPool -= troops;
}

void Player::setStars(int s){
    this->stars = s;
}

int Player::getStars() {
    return this->stars;
}

void Player::setTroopsPerTurn(int troops) {
    this->troopsPerTurn = troops;
}

int Player::getTroopsPerTurn() {
    return this->troopsPerTurn;
}

int Player::calculateTroopsPerTurn(World earth) {
    /*
        RULES TO DETERMINE TROOPS PER TURN
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        - Everyone gets 3 troops no matter what
        - Get troops for the number of territories you own
        - Continent Bonus
    */
    int tpt = 0;

    //Territory Bonus
    if (controlled_territories.size() < 9) {
        tpt += 3;
    } else {
        tpt += (controlled_territories.size()/3);
    }

    //Continent Bonuses

    //Australia Check
    int counter = 0;
    for (unsigned int i=0; i<4; i++) {
        for (unsigned int j=0; j<controlled_territories.size(); j++) {
            if (earth.getWorld()[i]->getName() == controlled_territories[j]->getName()) {
                counter++;
            }
        }
    }
    if (counter == 4) {
        tpt += 2;
    }

    //Asia
    counter = 0;
    for (unsigned int i=4; i<16; i++) {
        for (unsigned int j=0; j<controlled_territories.size(); j++) {
            if (earth.getWorld()[i]->getName() == controlled_territories[j]->getName()) {
                counter++;
            }
        }
    }
    if (counter == 12) {
        tpt += 7;
    }

    //Europe
    counter = 0;
    for (unsigned int i=16; i<23; i++) {
        for (unsigned int j=0; j<controlled_territories.size(); j++) {
            if (earth.getWorld()[i]->getName() == controlled_territories[j]->getName()) {
                counter++;
            }
        }
    }
    if (counter == 7) {
        tpt += 5;
    }

    //Africa
    counter = 0;
    for (unsigned int i=23; i<29; i++) {
        for (unsigned int j=0; j<controlled_territories.size(); j++) {
            if (earth.getWorld()[i]->getName() == controlled_territories[j]->getName()) {
                counter++;
            }
        }
    }
    if (counter == 6) {
        tpt += 3;
    }

    //South America
    counter = 0;
    for (unsigned int i=29; i<33; i++) {
        for (unsigned int j=0; j<controlled_territories.size(); j++) {
            if (earth.getWorld()[i]->getName() == controlled_territories[j]->getName()) {
                counter++;
            }
        }
    }
    if (counter == 4) {
        tpt += 2;
    }

    //North America
    counter = 0;
    for (unsigned int i=33; i<42; i++) {
        for (unsigned int j=0; j<controlled_territories.size(); j++) {
            if (earth.getWorld()[i]->getName() == controlled_territories[j]->getName()) {
                counter++;
            }
        }
    }
    if (counter == 9) {
        tpt += 5;
    }
    return tpt;
}

int Player::getTroops() {
    return this->troopsPool;
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

//void Player::addCard(Deck d) {
//    hand.push_back(d.deal());
//}

vector<Card> Player::getHand(){
    return this->hand;
}

vector<Territory*> Player::getControlledTerritories() {
    return this->controlled_territories;
}

void Player::addControlledTerritory(Territory* t) {
    controlled_territories.push_back(t);
}

void Player::removeControlledTerritory(Territory* t) {
    for (int i=0; i<controlled_territories.size(); i++) {
        if (controlled_territories[i]->getName() == t->getName()) {
            controlled_territories.erase(controlled_territories.begin()+i);
        }
    }
}

Player::~Player()
{

}
