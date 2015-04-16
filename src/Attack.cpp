#include "Attack.h"
#include <string>
#include <vector>
#include <algorithm>
#include "Territory.h"
#include "World.h"
#include "Game.h"
#include "DiceRoll.h"

using namespace std;

Attack::Attack()
{}

DiceRoll d;

bool validAttack(Territory* origin, Territory* destination, int aTroops, int dTroops){
    //check adjacency
    bool adjacent = false;
    vector<string> borders = origin.getBorders;
    for (unsigned int i = 0; i < origin->borders.size(); i ++){
                if (borders[i] == destination.getName){
                    adjacent = true;
                } else {
                    adjacent = false;
                }
    }

    bool validm = false;
    //perform other validity checks
    if (origin.getOwner == Game.getCurrentPalyer && destination.getOwner != Game.getCurrentPlayer){
        if  (adjacent){
            if (aTroops >=1 && aTroops <= 3 && aTroops <= origin->troops-1){
                validm = true;
            } else {
                validm = false;
            }
        } else{
            validm = false;
        }
    } else {
        validm = false;
    }

    //check defender's troops number
    if (!(dTroops>=1 && dTroops<=2)){
        validm = false;
    }
    return validm;
}

//only call this function if the validAttack function has been called and returned true
void attack(Territory* origin, Territory* destination, int aTroops, int dTroops){
        // array to hold the results of the attacker's dice rolls
        int aRolls[aTroops];
        for (int i = 0; i <aTroops; i++){
            aRolls[i] = d.diceRoll(i);
        }
        //sort aRolls array so they can be compared to defenders rolls, ascending order
        sort(aRolls, aRolls+aTroops);

        //array to hold results of defender's rolls
        int dRolls[dTroops];
        for (int i = 0; i<dTroops; i++){
            dRolls[i]= d.diceRoll(i+9);
        }
        //sort dRolls array for comparison, ascending order
        sort(dRolls, dRolls+dTroops);

        //to determine results of battle, the highest dice of each player will be compared in order
        int d = dTroops; // helps keep track of the pairs of dice
        int a = aTroops;
        do {
            if (aRolls[a-1] > dRolls[d-1]){
                destination->troops -= 1;
            } else if (dRolls[d-1] >= aRolls[a-1]){
                origin.getTroops -= 1;
            }
            a--;
            d--;
        } while (d != 0);

        //still needs a way to update the map/display to show results in troop number changes
}

Attack::~Attack()
{}
