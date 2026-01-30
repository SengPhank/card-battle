#include "cards/entity/Troll.h"

Troll::Troll() : EntityCard("Troll", 1, 10, 1) {}
Troll::~Troll() {}

Card* Troll::clone() const {
    return new Troll(*this);
}

std::string Troll::getDescription() const {
    std::string s = std::format("--{}--\nHp: {}, Atk: {}\nCost: ${}\n\nJust a beefy guy",
        name, health, attack, cost
    );
    return s;
}