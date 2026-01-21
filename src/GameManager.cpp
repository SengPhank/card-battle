#include "GameManager.h"
#include "map/MainBoard.h"
#include <iostream>
// int turn;
// Character* plr1;
// Character* plr2;
// MainBoard* board;
    
GameManager::GameManager(Character* p1, Character* p2) : plr1(p1), plr2(p2) {
    this->turn = 1;
    board = nullptr;
    std::cout << "Initalized a game!\nPlayer1: " << plr1->getName() << " vs\nPlayer2: " << plr2->getName() << std::endl;
}

MainBoard* GameManager::initGame(int numLanes) {
    this->board = new MainBoard(this, numLanes);
    return this->board;
}

void GameManager::damagePlr1(int atk) {
    plr1->takeDamage(atk);
    std::cout << "plr1 took " << atk << " damage! current hp: " << plr1->getHealth() << std::endl;
}
void GameManager::damagePlr2(int atk) {
    plr2->takeDamage(atk);
    std::cout << "plr2 took " << atk << " damage! current hp: " << plr2->getHealth() << std::endl;

}

// Encapsulation
int GameManager::getTurn() const {
    return this->turn;
}
GameManager::~GameManager() {
    delete plr1;
    delete plr2;
    delete board;
}



    
    