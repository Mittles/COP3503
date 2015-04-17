#include "Card.h"
#include <string>

using namespace std;
//default constructor
Card::Card(){
    cardOwner= 0;
    cardValue = 0;
}

void Card::setOwner(int o){
    this->cardOwner = o;
}

void Card::setValue(int v){
    this->cardValue = v;
}

int Card::getOwner(){
    return this->cardOwner;
}

int Card::getValue(){
    return this->cardValue;
}

Card::~Card(){
}
