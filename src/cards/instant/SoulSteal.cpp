#include "cards/instant/SoulSteal.h"
#include "game/MatchManager.h"

// Name, Cost
SoulSteal::SoulSteal()
: InstantCard("Soul Stealer 👻", 3) {
    this->setUseEnemyChar(true);
    this->setUseEnemyEnt(true);
}

SoulSteal::~SoulSteal() {}

Card* SoulSteal::clone() const {
    return new SoulSteal(*this);
}

std::string SoulSteal::getDescription() const {
    return "Drain health from your opponent's entity or character, and heal yourself for that much (Max 5)";
}

bool SoulSteal::onPlayed(MatchManager* manager, int lane, int plr) {
    // std::cout << "Soul Stealing... " << lane << ", " << plr << std::endl;
    int maxSteal = 5;
    int healthStolen = 0;
    int owner = this->getOwner();
    // Healing face
    if (plr != -1) {
        if (plr == 1) {
            int hp = manager->getPlr1Char()->getHealth();
            healthStolen = std::min(maxSteal, hp);
            manager->damagePlr1(healthStolen);
        }
        if (plr == 2) {
            int hp = manager->getPlr2Char()->getHealth();
            healthStolen = std::min(maxSteal, hp);
            manager->damagePlr2(healthStolen);
        }
    } else {
        // Healing a lane
        std::vector<Lane*> allLanes = manager->getBoard()->getLanes();
        if (lane < 0 || lane >= allLanes.size()) return false;
        Lane* curLane = allLanes[lane];
        if (owner == 1) {
            if (!curLane->getPlr2Entity()) return false;
            healthStolen = std::min(curLane->getPlr2Entity()->getHealth(), maxSteal);
            curLane->damagePlrEntity(2, healthStolen);
        } else if (owner == 2) {
            if (!curLane->getPlr1Entity()) return false;
            healthStolen = std::min(curLane->getPlr1Entity()->getHealth(), maxSteal);
            curLane->damagePlrEntity(1, healthStolen);
        }
    }

    if (owner == 1) manager->healPlr1(healthStolen);
    if (owner == 2) manager->healPlr2(healthStolen);
    // std::cout << "stole " << healthStolen << " health" << std::endl;
    return true;
}
