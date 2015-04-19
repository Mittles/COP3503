#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
    public:
        //constructor automatically sets cardOwner and cardValue both to 0 to be changed later in the Deck class
        Card();
        void setOwner(int o);
        void setValue(int v);
        int getOwner();
        int getValue();
        bool isDrawn();
        void changeDraw(bool b);

        ~Card();

    protected:
    private:
        //indicates which player owns the card
        int cardOwner;

        //indicates how many stars and therefore troops the card is worth
        int cardValue;

        //indicates if the card has been drawn from the deck
        bool drawn;
};

#endif // CARD_H

