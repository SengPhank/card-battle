#include "game/MainBoard.h"
// std::vector<Lane*> Lanes;
// std::vector<Card*> allCards;

MainBoard::MainBoard(MatchManager* gm, int numLanes) : GM(gm) {
    for (int i = 0; i < numLanes; i++) {
        Lane* newLane = new Lane(GM, i);
        Lanes.push_back(newLane);
    }
}

bool MainBoard::playCard(int player, int lane, EntityCard* card) {
    // Verify lane
    if (lane < 0 || lane >= Lanes.size()) return false;
    return Lanes[lane]->placeCard(player, card);
}

void MainBoard::enactBoard() {
    for (Lane* i : Lanes) {
        i->enactLane();
    }
}
Lane* MainBoard::getRandomLane(int plr, bool occupied) {
    // if plr invalid, just get ANY lane
    if (plr != 1 && plr != 2) {
        if (Lanes.empty()) return nullptr;
        return Lanes[rand() % Lanes.size()];
    }

    std::vector<Lane*> available;
    for (Lane* l : Lanes) {
        Card* ent;
        if (plr == 1) {
            ent = l->getPlr1Entity();
        } else {
            ent = l->getPlr2Entity();
        }
        // Store occupied, or not occupied
        if (ent == nullptr && !occupied) {
            available.push_back(l);
        } else if (ent != nullptr && occupied) {
            available.push_back(l);
        }
    }

    if (available.size() == 0) return nullptr;
    return available[rand()%available.size()];
}

std::vector<Lane*> MainBoard::getLanes() const {
    return this->Lanes;
}
MainBoard::~MainBoard() {
    for (int i = 0; i < Lanes.size(); i++) {
        delete Lanes[i];
    }
}