#include "cards/instant/Heal.h"
#include "game/MatchManager.h"

Heal::Heal() : InstantCard("Heal⛑️", 2) {
    // Can use it on your own character, or a selected card
    this->setUseSelfChar(true);
    this->setUseSelfEnt(true);
}
Heal::~Heal() {}

Card* Heal::clone() const {
    return new Heal(*this);
}

std::string Heal::getDescription() const {
    std::string s = std::format("--{}--\nCost: ${}\nHeals a card for +5 Health",
        name, cost
    );
    return s;
}

bool Heal::onPlayed(MatchManager* manager, int lane) {
    std::cout << "HEALING LANE " << lane << std::endl;
    int healing = 5;
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
    cur->setHealth(std::max(cur->getDFHEALTH(), cur->getHealth()+healing));
    return true;
}