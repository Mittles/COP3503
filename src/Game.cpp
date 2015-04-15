#include "Game.h"

Game::Game(vector<Player> players, vector<vector<Territory> > world, Deck playDeck)
{
    this->players = players;
    this->world = world;
    this->playDeck = playDeck;
    *currentPlayer = players[0];
}

void Game::init_game()
{
    /*
        Initialize the game, i.e assign territories, deal cards, ect
    */
}

void Game::nextTurn() //Sets the current turn to the next player, wraps around if necessary
{
    int index;
    for (unsigned int i=0; i<players.size(); i++) { //If something isnt working here check that currenPlayer is derefrencing correctly
        if (players[i].equals(*currentPlayer)) {
            index = i;
        }
    }

    if (index = players.size()-1) {
        *currentPlayer = players[0];
    } else {
        *currentPlayer = players[index+1];
    }
}


Game::~Game()
{
    delete(currentPlayer);
}
