#include "cards/entity/Bank.h"
#include "game/MatchManager.h"

Bank::Bank() 
: EntityCard("Bank", 3, 2, 1) {}
Bank::~Bank() {}

Card* Bank::clone() const {
    return new Bank(*this);
}

std::string Bank::getDescription() const {
    std::string s = std::format("--{}--\nHp: {}, Atk: {}\nCost: ${}\n\nOn new match: Gain +1 Token",
        name, health, attack, cost
    );
    return s;
}

void Bank::onNewRound(MatchManager* manager) {
    std::cout << "Bank gives+1" << std::endl; 
}

