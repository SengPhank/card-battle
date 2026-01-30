#include "cards/instant/MeteorShower.h"

MeteorShower::MeteorShower()
: InstantCard("Meteor Shower", 5) {
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
    return true;
}
