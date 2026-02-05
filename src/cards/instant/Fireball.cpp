#include "cards/instant/Fireball.h"
#include "game/MatchManager.h"

// Name, Cost
Fireball::Fireball()
: InstantCard("Fireball ☄️", 2) {
    // Can use it whenever (even if no enemies)
    this->setUseEnemyEnt(true);
}

Fireball::~Fireball() {}

Card* Fireball::clone() const {
    return new Fireball(*this);
}

std::string Fireball::getDescription() const {
    return "Deal 4 damage to an enemy on board";
}

bool Fireball::onPlayed(MatchManager* manager, int lane, int plr) {
    // std::cout << "DEALING 4 DAMAGE TO LANE.. " << lane << std::endl;
    std::vector<Lane*> allLanes = manager->getBoard()->getLanes();
    if (lane < 0 || lane > allLanes.size()) return false;
    int dmg = 4;
    if (this->getOwner() == 1) {
        if (allLanes[lane]->getPlr2Entity() == nullptr) return false;
        allLanes[lane]->damagePlrEntity(2, dmg);
    }
    if (this->getOwner() == 2) {
        if (allLanes[lane]->getPlr1Entity() == nullptr) return false;
        allLanes[lane]->damagePlrEntity(1, dmg);
    }
    return true;
}
