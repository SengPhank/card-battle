#pragma once
#include "map/Lane.h"
#include "cards/Card.h"
#include <vector>

class GameManager;

class MainBoard {
private:
    GameManager* GM;
    std::vector<Lane*> Lanes;
    std::vector<Card*> allCards;
public:
    MainBoard(GameManager* gm, int numLanes); 
    bool playCard(int player, int lane, Card* card);
    void enactBoard();
    ~MainBoard();
};


