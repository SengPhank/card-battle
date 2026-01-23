#include "game/MatchManager.h"
#include "game/MainBoard.h"
#include <iostream>
// int turn;
// Character* plr1;
// Character* plr2;
// MainBoard* board;
    
MatchManager::MatchManager(Character* p1, Character* p2) : plr1(p1), plr2(p2) {
    this->turn = 1;
    board = nullptr;
    std::cout << "Initalized a game!\nPlayer1: " << plr1->getName() << " vs\nPlayer2: " << plr2->getName() << std::endl;
}

MainBoard* MatchManager::initGame(int numLanes) {
    this->board = new MainBoard(this, numLanes);
    return this->board;
}

void MatchManager::damagePlr1(int atk) {
    plr1->takeDamage(atk);
    std::cout << "plr1 took " << atk << " damage! current hp: " << plr1->getHealth() << std::endl;
}
void MatchManager::damagePlr2(int atk) {
    plr2->takeDamage(atk);
    std::cout << "plr2 took " << atk << " damage! current hp: " << plr2->getHealth() << std::endl;

}

// Encapsulation
int MatchManager::getTurn() const {
    return this->turn;
}
MatchManager::~MatchManager() {
    delete plr1;
    delete plr2;
    delete board;
}



    
    