#include "characters/heroes/Mage.h"
#include "game/MatchManager.h"

Mage::Mage() : Character(30, 0, "Mage") {}
Mage::~Mage() {}

Character* Mage::clone() const {
    return new Mage(*this);
}

bool Mage::activateRage(MatchManager* manager) {
    if (rage < 100)
        return false;
    std::cout << "ACTIVIATING MAGE ABILITY" << std::endl;
    std::vector<Lane*> allLanes = manager->getBoard()->getLanes();
    int dmg = 2, heal = 2;
    // Deal X damage to all enemy card
    for (Lane* i : allLanes) {
        EntityCard* ent = i->getPlr2Entity();
        if (!ent) continue;
        ent->setHealth(ent->getHealth()-dmg);
    }
    for (Lane* i : allLanes) {
        EntityCard* ent = i->getPlr1Entity();
        if (!ent) continue;
        ent->setHealth(std::min(ent->getHealth()+heal, ent->getDFHEALTH()));
    }
    rage = 0;

    return true;
}
