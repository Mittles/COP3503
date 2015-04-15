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

bool validMove(Territory origin, Territory destination, int troopNum){
    //check adjacency
    bool adjacent = false;
    for (int i = 0; i < origin.borders.size(); i ++){
                if (origin.borders[i] == destination){
                    adjacent = true;
                } else {
                    adjacent = false;
                }
    }

    //perform other checks for validity
    if(origin.owner == Game::currentPlayer && destination.owner == Game::currentPlayer){
        if (troopNum <= origin.troops-1){
            if (adjacent){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
    return false;
    }
}

//call the validMove function prior to calling this function. if validMove does not return true this cannot be called
void moveTroops(Territory origin, Territory destination, int troopNum){
        origin.troops -= troopNum;
        destination.troops += troopNum;

        //still needs to update the map/display for the change in troop numbers somehow
}

MoveTroops::~MoveTroops()
{
    //dtor
}
*/
