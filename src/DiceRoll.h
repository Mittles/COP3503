#ifndef DICEROLL_H
#define DICEROLL_H


class DiceRoll
{
    public:

        /*
        When calling the diceRoll function multiple times at once, pass in different
        integers for each to ensure they return different values that are random.
        */
        int diceRoll(int seed);
};

#endif // DICEROLL_H
