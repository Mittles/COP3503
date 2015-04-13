#include "MoveTroops.h"
#include <string>
#include "Territory.h"
#include "World.h"
#include "Game.h"

MoveTroops::MoveTroops()
{
}

bool validMove(Territory origin, Territory destination, int troopNum){
    if(origin.owner == Game::currentPlayer && destination.owner == Game::currentPlayer){
        if (troopNum <= origin.troops-1){
            return true;
        }
    } else {
    return false;
    }
}

void moveTroops(Territory origin, Territory destination, int troopNum){
    if (validMove(origin, destination, troopNum)){
        origin.troops -= troopNum;
        destination.troops += troopNum;
    }
}

MoveTroops::~MoveTroops()
{
    //dtor
}
