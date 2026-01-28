#pragma once
#include "game/Lane.h"
#include "cards/Card.h"
#include <vector>

class MatchManager;

class MainBoard {
private:
    MatchManager* GM;
    std::vector<Lane*> Lanes;
    std::vector<Card*> allCards;
public:
    MainBoard(MatchManager* gm, int numLanes); 
    bool playCard(int player, int lane, Card* card);
    void enactBoard();

    // Encap
    std::vector<Lane*> getLanes() const;
    ~MainBoard();
};


