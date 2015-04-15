//#include "Game.h"
//
//
//Game::Game(vector<Player> players, vector<vector<Territory> > world, Deck playDeck)
//{
//    this->players = players;
//    this->world = world;
//    this->playDeck = playDeck;
//    *currentPlayer = players[0];
//}
//
//void Game::init_game()
//{
//    /*
//        Initialize the game, i.e assign territories, deal cards, ect
//
//
//    srand(time(0));
//    for (int i = 1; i <42; i++){
//        int cont;
//        switch(i) {
//        case (i<5):
//            cont = 1;
//            break;
//        case (i<17):
//            cont = 2;
//            break;
//        case (i<24) :
//            cont = 3;
//            break;
//        case (i<30) :
//            cont = 4;
//            break;
//        case (i<34) :
//            cont = 5;
//            break;
//        case (i<43) :
//            cont = 6;
//            break;
//        }
//        for (unsigned int j = 1; j < world[cont].size(); j++){
//            int pAssign = rand()% players.size()-1;
//            world[cont][i].setOwner(pAssign);
//        }
//
//    }
//
//    */
//}
//
//void Game::nextTurn() //Sets the current turn to the next player, wraps around if necessary
//{
//    int index;
//    for (unsigned int i=0; i<players.size(); i++) { //If something isnt working here check that currenPlayer is derefrencing correctly
//        if (players[i].equals(*currentPlayer)) {
//            index = i;
//        }
//    }
//
//    if (index = players.size()-1) {
//        *currentPlayer = players[0];
//    } else {
//        *currentPlayer = players[index+1];
//    }
//
//    */
//}
//
//
//Game::~Game()
//{
//    delete(currentPlayer);
//}
