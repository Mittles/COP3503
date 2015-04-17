#include "Game.h"


Game::Game(vector<Player> players, World earth, Deck playDeck)
{
    this->players = players;
    this->earth = earth;
    this->playDeck = playDeck;
    *currentPlayer = players[0];
}

void Game::init_game()
{
    /*
    Initialize the game, i.e assign territories, deal cards, ect
    */

    int maxTerritories = 42/players.size();
    int leftover = 42%players.size();

    /*
        Distribute Territories randomly to each player
    */

    srand(time(0));
    for (unsigned int i=0; i<players.size(); i++) {
       for (unsigned int j=0; j<maxTerritories; j++) {
          int r = rand()%42;
          if (earth.getWorld()[r]->getOwner() == 0) {
                earth.getWorld()[r]->setOwner(i);
          }
       }
    }

    //Deal leftover Territories
    for (int i=0;i<42; i++) {

    }


}

void Game::nextTurn() //Sets the current turn to the next player, wraps around if necessary
{
    int index;
    for (unsigned int i=0; i<players.size(); i++) { //If something isn't working here check that currentPlayer is dereferencing correctly
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
