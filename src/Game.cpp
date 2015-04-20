#include "Game.h"

DiceRoll d;

Game::Game(vector<Player> players, World earth, Deck playDeck)
{
    this->players = players;
    this->earth = earth;
    this->playDeck = playDeck;
    currentPlayer = 0;
    turnPhase = 0;
    turn = 1;
    capturedTerritory = false;
    gameOver = false;
    redeployed = false;
}
int Game::getCurrentPlayer(){
    return this->currentPlayer;
}

vector<string> Game::getNames(){
    for (int i =0; i < 4; i++){
        cout << "Enter Player " << i+1 << "'s name: " << endl;
        string input = "";
        cin >> input;
        while (input.length() >20){
            cout << "Choose a nickname, buddy!" << endl;
            cin >> input;
        }
        this->names.push_back(input);
     }
}

vector<Player>* Game::getPlayers() {
    return &players;
}
//Calculate every Player's troops per turn to display
void Game::calculatePlayerTPT() {
    for (int i=0; i<players.size(); i++) {
        players[i].setTroopsPerTurn(players[i].calculateTroopsPerTurn(earth));
    }
}

bool Game::isGameOver() {
    return this->gameOver;
}

void Game::allocate_Troops(Territory* t) {
    if (turnPhase != 0) {
        cout << "You can't allocate troops after you move!" << endl;
        cout << "The turn phase is " << turnPhase << endl;
        return;
    }
    if (t->getOwner() != currentPlayer) {
        cout << "Error: You don't own that territory" << endl;
        return;
    }

    if (players[currentPlayer].getTroops() == 0) {
        cout << "Error: You don't have any troops!" << endl;
    }
    cout << players[currentPlayer].getTroops() << " troops to allocate" << endl;
    cout << "Enter number of troops to allocate to " << t->getName() << endl;
    int troopCount;
    cin >> troopCount;
    while (!cin) {
        cout << "Enter a valid input" << endl;;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cin >> troopCount;
    }

    if (troopCount <= 0) {
        cout << "Error: Enter a valid positive value!" << endl;
        return;
    }

    if (troopCount > players[currentPlayer].getTroops())  {
        cout << "Error: You don't have that many troops to allocate." << endl;
        return;
    } else {
        t->setTroops(t->getTroops() + troopCount);
        players[currentPlayer].takeTroops(troopCount);
        cout << "Troops in " << t->getName() << ": " << t->getTroops() << endl;
    }
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
            p++;
        }
    }

    for (int i=0; i<players.size(); i++) {
        players[i].setTroops(50 - 5*players.size());
    }

    calculatePlayerTPT();
    cout << "Instructions: \n-Select a territory box then 'Allocate Troops' to assign troops\n-Select 2 territories then 'Attack/Move' to attack or move."  << endl;
    cout << "-You can't move or allocate troops after you attack.\n-To redeploy after you attack select 2 adjacent territories you own and select 'Redeploy Troops'" << endl;
    cout << "-If you capture a territory in your turn you will be rewarded stars. \n-Select 'Exchange Stars' to exchange stars for additional troops!" << endl;
    cout << "-Conquer the entire world to win, good luck!" << endl;
}
void Game::endGame() {
    cout << players[currentPlayer].getName() << "\n wins on turn " << turn << "!!!!" << endl;

    cout << "Press 1 to exit game." << endl;
    int choice=0;
    cin >> choice;
    while (!cin) {
        cout << "Enter a valid input" << endl;;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cin >> choice;
    }
    this->gameOver = true;
}

void Game::nextTurn() //Sets the current turn to the next player, wraps around if necessary
{
    cout << "Ending " << players[currentPlayer].getName() << "'s turn" << endl;
    if (capturedTerritory) {
        int r = rand()%4+1;
        players[currentPlayer].setStars(players[currentPlayer].getStars() + r);
        cout << "Added " << r << " stars to " << players[currentPlayer].getName() << "." << endl;
    }

    calculatePlayerTPT();

    //Check if a player has won, ends the
    if (players[currentPlayer].getControlledTerritories().size() == 42) {
        endGame();
        return;
    }
    if (this->currentPlayer == players.size()-1) {
        this->currentPlayer = 0;
        turn++;
    } else {
        this->currentPlayer += 1;
    }
    if (players[currentPlayer].getControlledTerritories().size() == 0) {  //Checks if the next player has lost
        cout << "Skipping " << players[currentPlayer].getName() << " because he/she lost" << endl;
        nextTurn();
        return;
    }

    turnPhase = 0;
    capturedTerritory = false;
    redeployed = false;
    cout << "Turn changed to " << players[currentPlayer].getName() << "'s turn" << endl;
    //Drafting doesn't occur on the first turn so make sure no troops are drafted
    if (turn == 1) {
        return;
    }    //Calculate every Player's troops per turn to display
    //Logic to check if a player has lost
    int drafted = players[currentPlayer].calculateTroopsPerTurn(earth);
    cout << players[currentPlayer].getName() << " drafts " << drafted << " troops." << endl;
    players[currentPlayer].setTroops(players[currentPlayer].getTroops() + drafted);
}

void Game::moveTroops(Territory* origin, Territory* destination, int troopNum){
        //performs exchange of troop numbers
        origin->setTroops(origin->getTroops() - troopNum);
        destination->setTroops(destination->getTroops() + troopNum);

        //still needs to update the map/display for the change in troop numbers somehow
}

void Game::setDie(int i, int r){
    this->dieResults[i] = r;
}

int* Game::getDie(){
    return this->dieResults;
}

void Game::clearDie(){
    for(unsigned int i = 0; i < 5; i++){
        dieResults[1] =0;
    }
}

void Game::attack(Territory* origin, Territory* destination, int aTroops, int dTroops){

        // array to hold the results of the attacker's dice rolls
        int rollsofA;
        if (aTroops > 3) {
            rollsofA = 3;
        } else {
            rollsofA = aTroops;
        }
        int aRolls[rollsofA];
        cout << "Attackers: " ;
        for (int i = 0; i <rollsofA; i++){
            aRolls[i] = d.diceRoll(i);
            cout << aRolls[i] << " ";
            //needs to update GUI for the results of the dice roll still
        }
        //sort aRolls array so they can be compared to defenders rolls, ascending order
        sort(aRolls, aRolls+rollsofA);

        //array to hold results of defender's rolls
        int dt = dTroops;
        int dRolls[dt];
        cout << "\n" << "defenders: ";
        for (int i = 0; i<dt; i++){
            dRolls[i]= d.diceRoll(i+4);
            cout << dRolls[i] << " ";
            //needs to update GUI
        }
        cout << endl;
        //sort dRolls array for comparison, ascending order
        sort(dRolls, dRolls+dTroops);

        //make results of rolls retrievable for GUI
        clearDie();
        for (int i = 0; i < 5; i++){
            if (i <=2){
                setDie(i, aRolls[i]);

            } else {
                setDie(i, dRolls[i]);
            }
        }


        //to determine results of battle, the highest dice of each player will be compared in order
        int d = dTroops; // helps keep track of the pairs of dice
        int a = rollsofA;
        do {
            if (aRolls[a-1] > dRolls[d-1]){
                destination->setTroops(destination->getTroops() - 1);
            } else if (dRolls[d-1] >= aRolls[a-1]){
                origin->setTroops(origin->getTroops() - 1);
                cout << players[destination->getOwner()].getName() << " won the battle, " << players[currentPlayer].getName() << " lost." << endl;
            }
            a--;
            d--;
            if (destination->getTroops() == 0){
                int loser = destination->getOwner();
                destination->setOwner(origin->getOwner());
                players[destination->getOwner()].addControlledTerritory(destination);
                players[loser].removeControlledTerritory(destination);
                capturedTerritory = true;
                cout << players[currentPlayer].getName() << " won the battle!" << endl;
                cout << players[currentPlayer].getName() << " now has " << players[currentPlayer].getControlledTerritories().size() << " territories." << endl;
                cout << players[loser].getName() << " now only has " << players[loser].getControlledTerritories().size() << " territories." << endl;
                destination->setTroops(aTroops);
                origin->setTroops((origin->getTroops()) - aTroops);
                turnPhase = 2;
            }
        } while (d != 0);
        int tempAr[5] = {0, 0, 0, 0, 0};
        for (int i = 0; i <3; i++){
            tempAr[i]=aRolls[i];
        }
        for (int i = 3; i<5; i++){
            tempAr[i]=dRolls[i-3];
        }
//        cout<< "array being passed: ";
//        for (int i = 0; i<5; i++){
//            dieResults[i]=tempAr[i];
//            cout << dieResults[i] << " ";
//        }

}

void Game::moveAttack(Territory* a, Territory* b) {
    if (turn==1){
        cout << "You may not attack or move in the Allocation Turn."<< endl;
        return;
    }
    if (turnPhase == 0) {
        turnPhase = 1;
    }
    std::cout << this->getCurrentPlayer() << endl;
    std::cout << "Origin: " << a->getName() << ", owner:" << players[a->getOwner()].getName() << "  Troops: " << a->getTroops() << endl;
    std::cout << "Destination: " << b->getName() << ", owner:" << players[b->getOwner()].getName() << "  Troops: " << b->getTroops() << endl;
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
        if (turnPhase == 1) {
            cout << "Enter number of troops to move(Must leave 1): " << endl;
            int troops;
            cin >> troops;
            while (!cin) {
                cout << "Enter a valid input" << endl;
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cin >> troops;
            }
            if (troops <= 0) {
                cout << "Enter a valid positive value." << endl;
                return;
            }
            if (a->getTroops() - troops < 1) {
                cout << "Error: Leave at least 1 troop in " << a->getName() << endl;
            } else {
                moveTroops(a, b, troops);
            }
        } else {
            cout << "You can't move after you attack." << endl;
            cout << "Turn phase: " << turnPhase << endl;
        }
    } else if (a->getOwner() != b->getOwner()){\
        if (turnPhase == 3) {
            cout << "You can't attack after you redeploy." << endl;
            cout << "Turn phase: " << turnPhase << endl;
        }
        cout << "Enter number of troops to attack with(Must leave 1): " << endl;
        int atroops;
        int btroops;
        cin >> atroops;
        while (!cin) {
            cout << "Enter a valid input" << endl;
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cin >> atroops;
        }
        if (atroops == a->getTroops()) {
            cout << "Error: You must leave at least 1 troop behind" << endl;
        }
        if (atroops > a->getTroops()-1) {
            cout << "Error: You don't have that many troops" << endl;
            return;
        }
        if (atroops <= 0) {
            cout << "Enter a valid positive number greater than 0!" << endl;
            return;
        }
        if (b->getTroops() >1){
            btroops = 2;
        } else {
            btroops = 1;
        }
        attack(a, b, atroops, btroops);
        turnPhase = 2;
        //std::cout << "origin after move: owner- " << a->getOwner()<< " troops- " << a->getTroops() << endl;
        //std::cout << "destination after move:  owner- " << b->getOwner()<< " troops- " << b->getTroops() << endl;
        cout << a->getName() << ": " << a->getTroops() << " troops ; " << b->getName() <<": " << b->getTroops() << " troops" << endl;
    }




    calculatePlayerTPT();
}

void Game::redeploy(Territory* a, Territory* b) {
    if (a->getOwner() != currentPlayer) {
        cout << "You don't own " << a->getName() << "!" << endl;
        return;
    }
    //Check that b is adjacent to a
    bool isbordering = false;
    for (unsigned int i=0; i< a->getBorders().size(); i++) {
        if (a->getBorders()[i] == b->getName()) {
            isbordering = true;
        }
    }
    if (isbordering == false) {
        cout << b->getName() << " doesn't border " << a->getName() << endl;
        return;
    }

    if (a->getOwner() == b->getOwner()) {
            if (redeployed) {
                cout << "You can only redeploy once per turn." << endl;
            }
            cout << "Enter number of troops to move(Must leave 1): " << endl;
            int troops;
            cin >> troops;
            while (!cin) {
                cout << "Enter a valid input" << endl;
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cin >> troops;
            }
            if (troops <= 0) {
                cout << "Enter a valid positive number." << endl;
                return;
            }
            if (a->getTroops() - troops < 1) {
                cout << "Error: Leave at least 1 troop in " << a->getName() << endl;
            } else {
                moveTroops(a, b, troops);
                cout << "Moved " << troops << " troops to " << b->getName() << endl;
                turnPhase = 3;
            }
    } else if (a->getOwner() != b->getOwner()){
        cout << "You don't own " << b->getName() << endl;
    }
}

void Game::exchangeStars() {
   if (turnPhase != 0) {
        cout << "You can't exchange stars after you move or attack!" << endl;
        cout << "Current Phase: " << turnPhase << endl;
        return;
   }

   if (players[currentPlayer].getStars() == 0) {
        cout << "You don't have any stars." << endl;
        return;
   }

   cout << "Enter the number of stars to cash out (at least 3)." << endl;
   cout << "You have " << players[currentPlayer].getStars() << " stars." << endl;
   int stars;
   cin >> stars;
   while (!cin) {
        cout << "Enter a valid input" << endl;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cin >> stars;
    }
    if (stars <= 0) {
        cout << "Enter a valid positive value" << endl;
        return;
    }

    if (stars < 3) {
        cout << "You must turn in at least 3 stars." << endl;
        return;
    }

    if (players[currentPlayer].getStars() < stars) {
        cout << "You don't have that many stars!" << endl;
        return;
    }

    players[currentPlayer].setTroops(players[currentPlayer].getTroops() + stars);
    cout << "Gave " << stars << " troops to " << players[currentPlayer].getName() << endl;
}



Game::~Game()
{
}
