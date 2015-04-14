/*
#include "MoveTroops.h"
#include <string>
#include <vector>
#include "Territory.h"
#include "World.h"
#include "Game.h"

MoveTroops::MoveTroops()
{
}

bool validMove(Territory* origin, Territory* destination, int troopNum){
    //check adjacency
    bool adjacent = false;
    for (unsigned int i = 0; i < origin->borders.size(); i ++){
                if (origin->borders[i] == destination->name){
                    adjacent = true;
                } else {
                    adjacent = false;
                }
    }
    bool validm = false;
    //perform other checks for validity
    //this line will not run yet
    if(origin->owner == Game.getCurrentPlayer && destination->owner == Game.getCurrentPlayer){

        if (troopNum <= origin->troops-1){
            if (adjacent){
                validm = true;
            } else {
                validm = false;
            }
        } else {
            validm = false;
        }
    } else {
    validm = false;
    }
    return validm;
}

//call the validMove function prior to calling this function. if validMove does not return true this cannot be called
void moveTroops(Territory* origin, Territory* destination, int troopNum){
        origin->troops -= troopNum;
        destination->troops += troopNum;

        //still needs to update the map/display for the change in troop numbers somehow
}

MoveTroops::~MoveTroops()
{
    //dtor
}
*/
