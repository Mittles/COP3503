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

    /*
        Distribute Territories randomly to each player, adds troops to each territory (Either 1 or 2 decided randomly)
    */

    srand(time(0));
    for (unsigned int i=0; i<players.size(); i++) {
       unsigned int bonus = 0;
       for (unsigned int j=0; j<maxTerritories; j++) {
          int r = rand()%42;                                    //Pick a random territory
          if (earth.getWorld()[r]->getOwner() == 5) {           //An owner value of '5' means the territory is not owned by a player
                earth.getWorld()[r]->setOwner(i);               //Set owner
                players[i].addControlledTerritory(earth.getWorld()[r]);
                earth.getWorld()[r]->setTroops(earth.getWorld()[r]->getTroops()+1); //Add an army to the territory
                if (bonus < 6-players.size()) {                                     //Add an extra army to the first few territories assigned (Number goes down as number of players increases)
                    earth.getWorld()[r]->setTroops(earth.getWorld()[r]->getTroops()+1);
                }
                cout << j << ") " << players[i].getName() << " added " << earth.getWorld()[r]->getName() << "  Troops: " << earth.getWorld()[r]->getTroops() << endl;
                bonus++;
          } else {
                j--;
          }
       }
    }
    unsigned int p=0;
    for (int i=0; i<42; i++) {
        if (earth.getWorld()[i]->getOwner() == 5) {
            earth.getWorld()[i]->setOwner(i);               //Set owner
            players[p].addControlledTerritory(earth.getWorld()[i]);
            earth.getWorld()[i]->setTroops(earth.getWorld()[i]->getTroops()+1); //Add an army to the territory
            cout << "Bonus Territory " << ") " << players[p].getName() << " added " << earth.getWorld()[i]->getName() << "  Troops: " << earth.getWorld()[i]->getTroops() << endl;
            p++;
        }
    }

    for (int i=0; i<players.size(); i++) {
        players[i].giveTroops(50 - 5*players.size());
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
