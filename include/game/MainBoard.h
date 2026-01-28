#pragma once
#include "game/Lane.h"
#include "cards/Card.h"
#include <vector>
#include <cstdlib>

class MatchManager;

class MainBoard {
private:
    MatchManager* GM;
    std::vector<Lane*> Lanes;
    std::vector<Card*> allCards;
public:
    MainBoard(MatchManager* gm, int numLanes); 
    // Functionality
    bool playCard(int player, int lane, EntityCard* card);
    void enactBoard();

    // QoL
    Lane* getRandomLane(int plr=0, bool occupied=false);

    // Encap
    std::vector<Lane*> getLanes() const;
    ~MainBoard();
};


