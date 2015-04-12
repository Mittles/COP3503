#include "Card.h"
#include <string>

using namespace std;

Card::Card(string name, int owner, int value)
{
    setName(name);
    setOwner(owner);
    setValue(value);
}

string cardName;
int cardOwner;
int cardValue;

void setName(string n){
    cardName=n;
}

void setOwner(int o){
    cardOwner=o;
}

void setValue(int v){
    cardValue=v;
}

string getName(){
    return cardName;
}

int getOwner(){
    return cardOwner;
}

int getValue(){
    return cardValue;
}
