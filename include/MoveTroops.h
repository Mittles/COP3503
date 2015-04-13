#ifndef MOVETROOPS_H
#define MOVETROOPS_H

#include "Territoty.h"
#include "World.h"
class MoveTroops
{
    public:

        MoveTroops();

        /*checks to see if the user's requested move is from a territory owned by that player to an adjacent
        territory owned by that player, and if the number of troops being moved leaves the origin territory with
        at least one troop left over.
        */
        bool validMove();

        //performs the troop movement only if the validMove function returns true`
        void moveTroops();
        virtual ~MoveTroops();
    protected:
    private:
};

#endif // MOVETROOPS_H
