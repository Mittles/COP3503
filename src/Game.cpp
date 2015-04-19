#include "Game.h"

DiceRoll d;
Game::Game(vector<Player> players, World earth, Deck playDeck)
{
    this->players = players;
    this->earth = earth;
    this->playDeck = playDeck;
    currentPlayer = 0;
}
int Game::getCurrentPlayer(){
    return this->currentPlayer;
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
            earth.getWorld()[i]->setOwner(p);               //Set owner
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

void Game::moveTroops(Territory* origin, Territory* destination, int troopNum){
        //performs exchange of troop numbers
        origin->setTroops(origin->getTroops() - troopNum);
        destination->setTroops(destination->getTroops() + troopNum);

        //still needs to update the map/display for the change in troop numbers somehow
}

void Game::attack(Territory* origin, Territory* destination, int aTroops, int dTroops){
        // array to hold the results of the attacker's dice rolls
        int aRolls[aTroops];
        for (int i = 0; i <aTroops; i++){
            aRolls[i] = d.diceRoll(i);
            //needs to update GUI for the results of the dice roll still
        }
        //sort aRolls array so they can be compared to defenders rolls, ascending order
        sort(aRolls, aRolls+aTroops);

        //array to hold results of defender's rolls
        int dRolls[dTroops];
        for (int i = 0; i<dTroops; i++){
            dRolls[i]= d.diceRoll(i+9);
            //needs to update GUI
        }
        //sort dRolls array for comparison, ascending order
        sort(dRolls, dRolls+dTroops);

        //to determine results of battle, the highest dice of each player will be compared in order
        int d = dTroops; // helps keep track of the pairs of dice
        int a = aTroops;
        do {
            if (aRolls[a-1] > dRolls[d-1]){
                destination->setTroops(destination->getTroops() - 1);
            } else if (dRolls[d-1] >= aRolls[a-1]){
                origin->setTroops(origin->getTroops() - 1);
            }
            a--;
            d--;
        } while (d != 0);

        //still needs a way to update the map/display to show results in troop number changes
}

void Game::moveAttack(Territory* a, Territory* b) {
    a->setOwner(0);
    a->setTroops(4);
    b->setOwner(0);
    std::cout << this->getCurrentPlayer() << endl;
    std::cout << "Terr1: " << a->getName() << ", owner:" << a->getOwner() << "troops: " << a->getTroops() << endl;
    std::cout << "Terr2: " << b->getName() << ", owner:" << b->getOwner() << "troops: " << b->getTroops() << endl;
    bool hasAttacked = false;
    //Check that a is owned by current player
    if (a->getOwner() != currentPlayer) {
        cout << "You don't own " << a->getName() << "!" << endl;
        return;
    }
    //Check that b is adjacent to a
    bool isbordering = false;
    for (int i=0; i< a->getBorders().size(); i++) {
        if (a->getBorders()[i] == b->getName()) {
            isbordering = true;
        }
    }
    if (isbordering == false) {
        cout << b->getName() << " doesn't border " << a->getName() << endl;
        return;
    }

    if (a->getOwner() == b->getOwner()) {
        if (!hasAttacked) {
            cout << "Enter number of troops to move(Must leave 1): " << endl;
            int troops;
            cin >> troops;
            if (a->getTroops() - troops < 1) {
                cout << "Error: Leave at least 1 troop in " << a->getName() << endl;
            } else {
                moveTroops(a, b, troops);
            }
        }
    } else if (a->getOwner() != b->getOwner()){
        cout << "Enter number of troops to move(Must leave 1), up to 3 troops: " << endl;
        int atroops;
        int btroops;
        cin >> atroops;
        if (atroops >= 1 && atroops <= 3){
            if (b->getTroops() >1){
                btroops = 2;
            } else {
                btroops = 1;
            }
            attack(a, b, atroops, btroops);
        }
    }
    std::cout << "origin after move: " << a->getTroops() << endl;
    std::cout << "destination after move: " << b->getTroops() << endl;

}


Game::~Game()
{
}
