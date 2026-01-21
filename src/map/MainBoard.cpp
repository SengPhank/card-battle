#include "map/MainBoard.h"
#include <iostream>
// std::vector<Lane*> Lanes;
// std::vector<Card*> allCards;

MainBoard::MainBoard(GameManager* gm, int numLanes) : GM(gm) {
    for (int i = 0; i < numLanes; i++) {
        Lane* newLane = new Lane(GM, i);
        Lanes.push_back(newLane);
    }
}

bool MainBoard::playCard(int player, int lane, Card* card) {
    if (lane < 0 || lane >= Lanes.size()) return false;
    return Lanes[lane]->placeCard(player, card);
}

void MainBoard::enactBoard() {
    for (Lane* i : Lanes) {
        i->enactLane();
    }
}

MainBoard::~MainBoard() {
    for (int i = 0; i < Lanes.size(); i++) {
        delete Lanes[i];
    }
}