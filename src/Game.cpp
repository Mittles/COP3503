//#include "Game.h"
//
//Game::Game(vector<Player> players, vector<vector<Territory> > world, Deck playDeck)
//{
//    this->players = players;
//    this->world = world;
//    this->playDeck = playdeck;
//    *currentPlayer = players[0];
//}
//
//Game::init()
//{
//    /*
//        Initialize the game, i.e assign territories, deal cards, ect
//    */
//}
//
//Game::nextTurn() //Sets the current turn to the next player, wraps around if necessary
//{
//    int index = find(players.begin(), players.end(), *currentPlayer);
//
//    if (index = players.size()-1) {
//        *currentPlayer = players[0];
//    } else
//        *currentPlayer = players[index+1];
//    }
//}
//
//Game::~Game()
//{
//    delete(currentPlayer);
//}
