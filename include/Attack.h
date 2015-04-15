#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <vector>
#include <algorithm>
#include "Territory.h"
#include "World.h"
#include "Game.h"
#include "DiceRoll.h"

class Attack
{
    public:
        //default constructor
        Attack();

        /* checks to see if the requested attack is valid. takes in the current player's
        territory of origin and number of troops used to attack (no greater than 3) as well as attack
        destination territory and defending troops.
        does the following checks:
            destination territory is adjacent to the origin territory
            origin territory belongs to current player
            destination territory belongs to any other player besides the current player
            that the attacker has the proper number of troops to attack
        returns true if the attack is a valid attack to perform
        */
        bool validAttack(Territory* origin, Territory* destination, int aTroops, int dTroops);

        /*performs the attacking by calling the diceRoll function in DiceRoll class and
        resolves the winner of each battle
        */
        void attack(Territory* origin, Territory* destination, int aTroops, int dTroops);

        virtual ~Attack();
    protected:
    private:
};

#endif // ATTACK_H
