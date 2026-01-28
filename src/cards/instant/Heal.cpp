#include "cards/instant/Heal.h"

Heal::Heal() : InstantCard("Heal", 2) {}
Heal::~Heal() {}

Card* Heal::clone() const {
    return new Heal(*this);
}

std::string Heal::getDescription() const {
    std::string s = std::format("--{}--\nCost: ${}\nGives a card +5 Health",
        name, cost
    );
    return s;
}

void Heal::onPlayed(MatchManager* manager, int lane) {
    std::cout << "HEALING LANE " << lane << std::endl;
}