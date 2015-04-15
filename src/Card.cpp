#include "Card.h"
#include <string>

using namespace std;
//default constructor
Card::Card(){
    cardOwner= 0;
    cardValue = 0;
}

void Card::setOwner(int o){
    cardOwner = o;
 }

int Card::getOwner(){
    return cardOwner;
 }

void Card::setValue(int v){
    cardValue = v;
 }

int Card::getValue(){
    return cardValue;
 }

Card::~Card(){
}
