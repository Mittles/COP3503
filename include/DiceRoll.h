#ifndef DICEROLL_H
#define DICEROLL_H

#include "DiceRoll.h"
#include <cstdlib>
#include <ctime>

class DiceRoll
{
    public:
        /*
        When calling the diceRoll function, pass in different ints for each call
        being made if there are multiple calls being made at the same time. This
        will help keep return values more random.
        */
        int diceRoll(int seed);
    protected:
    private:
};

#endif // DICEROLL_H
