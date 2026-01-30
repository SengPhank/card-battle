#include "cards/instant/MeteorShower.h"
#include "game/MatchManager.h"

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
    std::string s = std::format("--{}--\nCost: ${}\n\nDeal 1 damage to all enemies on the board",
        name, cost
    );
    return s;
}

bool MeteorShower::onPlayed(MatchManager* manager, int lane) {
    std::cout << "DEALING 1 DAMAGE TO ALL ENEMSS.. " << std::endl;
    std::vector<Lane*> allLanes = manager->getBoard()->getLanes();
    int dmg = 1;
    for (Lane* i : allLanes) {
        if (this->getOwner() == 1) i->damagePlrEntity(2, dmg);
        if (this->getOwner() == 2) i->damagePlrEntity(1, dmg);
    }
    return true;
}
