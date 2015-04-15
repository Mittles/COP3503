#ifndef MOVETROOPS_H
#define MOVETROOPS_H

#include "Territory.h"
#include "World.h"
#include <string>
#include <vector>
#include "Game.h"
class MoveTroops
{
    public:

        MoveTroops();

        /*checks to see if the user's requested move is from a territory owned by that player to an adjacent
        territory owned by that player, and if the number of troops being moved leaves the origin territory with
        at least one troop left over.
        */
        bool validMove(Territory origin, Territory destination, int troopNum);

        //performs the troop movement only if the validMove function returns true`
        void moveTroops(Territory origin, Territory destination, int troopNum);

        virtual ~MoveTroops();
    protected:
    private:
};

#endif // MOVETROOPS_H
