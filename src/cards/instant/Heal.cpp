#include "cards/instant/Heal.h"
#include "game/MatchManager.h"

// Name, Cost
Heal::Heal() : InstantCard("Heal ⛑️", 2) {
    // Can use it on your own character, or a selected card
    this->setUseSelfChar(true);
    this->setUseSelfEnt(true);
    this->setDamagedOnly(true);
}
Heal::~Heal() {}

Card* Heal::clone() const {
    return new Heal(*this);
}

std::string Heal::getDescription() const {
    return "Heals your Character or entity for +3 Health";
}

bool Heal::onPlayed(MatchManager* manager, int lane, int plr) {
    // std::cout << "HEALING LANE " << lane << std::endl;
    int healing = 3;
    int owner = this->getOwner();
    // Healing face
    if (plr != -1) {
        if (owner != plr) return false; // can't heal enemy
        if (plr == 1) {
            if (manager->getPlr1Char()->getHealth() == manager->getPlr1Char()->getDFHEALTH()) return false;
            manager->healPlr1(healing);
        }
        if (plr == 2) {
            if (manager->getPlr2Char()->getHealth() == manager->getPlr2Char()->getDFHEALTH()) return false;
            manager->healPlr2(healing);
        }
    } else {
        // Healing a lane
        std::vector<Lane*> allLanes = manager->getBoard()->getLanes();
        if (lane < 0 || lane >= allLanes.size()) return false;
        int owner = this->getOwner();
        EntityCard* cur;
        if (owner == 1) {
            cur = allLanes[lane]->getPlr1Entity();
        } else if (owner == 2) {
            cur = allLanes[lane]->getPlr2Entity();
        }
        if (cur == nullptr) return false;
        cur->setHealth(std::min(cur->getDFHEALTH(), cur->getHealth()+healing));
    }
    
    return true;
}