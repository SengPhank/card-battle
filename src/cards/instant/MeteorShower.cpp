#include "cards/instant/MeteorShower.h"
#include "game/MatchManager.h"

// Name, Cost
MeteorShower::MeteorShower()
: InstantCard("Meteors 🌠", 5) {
    // Can use it whenever (even if no enemies)
    this->setUseAnyBoard(true);
}

MeteorShower::~MeteorShower() {}

Card* MeteorShower::clone() const {
    return new MeteorShower(*this);
}

std::string MeteorShower::getDescription() const {
    return "Deal 1 damage to all enemies on the board";
}

bool MeteorShower::onPlayed(MatchManager* manager, int lane, int plr) {
    // std::cout << "DEALING 1 DAMAGE TO ALL ENEMSS.. " << std::endl;
    std::vector<Lane*> allLanes = manager->getBoard()->getLanes();
    int dmg = 1;
    for (Lane* i : allLanes) {
        if (this->getOwner() == 1) i->damagePlrEntity(2, dmg);
        if (this->getOwner() == 2) i->damagePlrEntity(1, dmg);
    }
    return true;
}
