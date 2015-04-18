#include "Game.h"


Game::Game(vector<Player> players, World earth, Deck playDeck)
{
    this->players = players;
    this->earth = earth;
    this->playDeck = playDeck;
    currentPlayer = 1;
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
          if (earth.getWorld()[r]->getOwner() == 5) {
                earth.getWorld()[r]->setOwner(i);
                players[i].addControlledTerritory(earth.getWorld()[r]);
                cout << j << ") " << players[i].getName() << " added " << earth.getWorld()[r]->getName() << endl;
          } else {
                j--;
          }
       }
    }

    //Deal leftover Territories
    for (unsigned int i=0;i<42; i++) {

    }



}

void Game::nextTurn() //Sets the current turn to the next player, wraps around if necessary
{
    if (currentPlayer = players.size()-1) {
        currentPlayer = 0;
    } else {
        currentPlayer++;
    }
}


Game::~Game()
{
}
