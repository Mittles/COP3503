#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
    public:
        //constructor automatically sets cardOwner and cardValue both to 0 to be changed later in the Deck class
        Card();

        //indicates which player owns the card
        int cardOwner;

        //indicates how many stars and therefore troops the card is worth
        int cardValue;
        ~Card();

    protected:
    private:
};

#endif // CARD_H

