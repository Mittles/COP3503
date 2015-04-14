#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Deck
{
    public:
        //constructor for deck, calls createDeck and deckShuffle functions automatically on creation of Deck object
        Deck();

        //initializes the deck
        vector<Card> createDeck();

        //this is the actual deck of cards, a vector of 42 cards
        vector<Card> deckOfCards;

        //shuffles the cards in the deck pseudo-randomly
        vector<Card> deckShuffle(vector<Card> deckOfCards);
    protected:
    private:
};

#endif // DECK_H
