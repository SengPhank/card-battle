#include "cards/entity/Bank.h"
#include "game/MatchManager.h"

Bank::Bank() 
: EntityCard("Bank 🏦", 3, 2, 1) {}
Bank::~Bank() {}

Card* Bank::clone() const {
    return new Bank(*this);
}

std::string Bank::getDescription() const {
    return "On a new round, gain +1 token this turn";
}

void Bank::onNewRound(MatchManager* manager) {
    int owner = this->getOwner();
    if (owner == 1) {
        manager->setPlr1Token(manager->getPlr1Token()+1);
    } else if (owner == 2) {
        manager->setPlr2Token(manager->getPlr2Token()+1);
    }
}

