#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
    public:
        //constructor automatically sets cardOwner and cardValue both to 0 to be changed later in the Deck class
        Card();
        //Sets the owner value of the card
        void setOwner(int o);
        //Sets the card value
        void setValue(int v);
        //Returns the owner integer value
        int getOwner();
        //Returns the integer for value
        int getValue();
        //Checks if the card has been drawn or not
        bool isDrawn();
        //Either draws or "undraws" a card
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

