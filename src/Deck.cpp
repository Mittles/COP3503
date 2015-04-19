#include "Deck.h"
//#include "Card.h"
//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <ctime>
//#include <cstdlib>
//#include "Player.h"
#include "Game.h"

using namespace std;

Deck::Deck()
{
    //initializes the deck
    deckOfCards = Deck::createDeck();
    //seeds random number generator for shuffling
    srand(time(0));
    //shuffles deck
    deckOfCards = deckShuffle(deckOfCards);
}

void Deck::printDeck() {
    for (unsigned int i=0; i<deckOfCards.size(); i++) {
        cout << deckOfCards[i].getValue() << endl;
    }
}

//creates initial deck
vector<Card> Deck::createDeck(){
    vector<Card> cardArray;
    for (int i = 0; i < 42; i++){
        Card currentCard;
        if (i==6 || i==7 || i==12 || i==13 || i==19 || i==20){
            currentCard.setValue(2);
            cardArray.push_back(currentCard);
        } else if (i==21 || i==29 || i==30 || i==36 || i==37 || i==38){
            currentCard.setValue(2);
            cardArray.push_back(currentCard);
        } else {
            currentCard.setValue(1);
            cardArray.push_back(currentCard);
        }
    }
    return cardArray;
}

//void Deck::deal(vector<Card> vc) {
//    for (unsigned int i=0; i<deckOfCards.size(); i++) {
//        if (!deckOfCards[i].isDrawn()) {
//            deckOfCards[i].changeDraw(true);
//            vc.push_back(deckOfCards[i]);
//        }
//        else {
//            cout << "No Cards to draw!" << endl;
//
//        }
//    }
//
//    for (unsigned int i=0; i<deckOfCards.size(); i++) {
//        deckOfCards[i].changeDraw(false);
//    }
//
//    deckShuffle(deckOfCards);
//    deckOfCards[0].changeDraw(true);
//}

//pseudo-randomly shuffles the deck
vector<Card> Deck::deckShuffle(vector<Card> deckOfCards){
    random_shuffle(deckOfCards.begin(), deckOfCards.end());
    return deckOfCards;
}
