#include "Card.h"
#include <string>

using namespace std;
//default constructor
Card::Card(){
    cardOwner= 5;
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

bool Card::isDrawn() {
    return this->isDrawn();
}

void Card::changeDraw(bool b) {
    this->drawn = b;
}

Card::~Card(){
}
