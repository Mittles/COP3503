//#include "MoveTroops.h"
//#include <string>
//#include <vector>
//#include "Territory.h"
//#include "World.h"
//#include "Game.h"
//
//MoveTroops::MoveTroops()
//{
//}
//
//bool validMove(Territory* origin, Territory* destination, int troopNum){
//    //check adjacency
//    bool adjacent = false;
//    vector<string> borders = origin->getBorders();
//    for (unsigned int i = 0; i < borders.size(); i ++){
//                if (borders[i] == destination->getName()){
//                    adjacent = true;
//                } else {
//                    adjacent = false;
//                }
//    }
//
//    bool valida = false;
//    //perform other checks for validity
//    if(origin->getOwner() == Game.getCurrentPlayer && destination->getOwner() == Game.getCurrentPlayer){
//        if (troopNum <= origin->getTroops()-1){
//            if (adjacent){
//                valida = true;
//            } else {
//                valida = false;
//            }
//        } else {
//            valida = false;
//        }
//    } else {
//        valida = false;
//    }
//    reuturn valida;
//}
//
////call the validMove function prior to calling this function. if validMove does not return true this cannot be called
//void moveTroops(Territory* origin, Territory* destination, int troopNum){
//        //performs exchange of troop numbers
//        origin->setTroops(origin->getTroops() - troopNum);
//        destination->setTroops(destination->getTroops() + troopNum);
//
//        //still needs to update the map/display for the change in troop numbers somehow
//}
//
//MoveTroops::~MoveTroops()
//{
//    //dtor
//}

