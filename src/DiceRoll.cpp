#include "DiceRoll.h"
#include <cstdlib>
#include <ctime>

int DiceRoll::diceRoll (int seed)
{
    srand(time(0) + seed + (5*seed));
    int result = rand() % 6 + 1;
    return result;
}
