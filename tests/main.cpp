#include "GameManager.h"
#include "map/MainBoard.h"
#include "characters/Mage.h"
#include "characters/Tank.h"
#include "cards/Card.h"

int main(void) {
    Mage* plr1 = new Mage(50, 100);
    Tank* plr2 = new Tank(100, 0);
    
    GameManager* GM = new GameManager(plr1, plr2);
    MainBoard* board = GM->initGame(3);

    Card* goblin = new Card("Goblin", 10, 15);
    Card* archer = new Card("Archer", 5, 20);
    board->playCard(1,2,goblin);
    board->playCard(2,0,archer);
    board->enactBoard();
    

    delete GM;
    return 0;
}