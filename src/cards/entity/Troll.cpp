#include "cards/entity/Troll.h"

// Name, Cost, Health, Atk
Troll::Troll() : EntityCard("Troll 🧌", 1, 2, 1) {}
Troll::~Troll() {}

Card* Troll::clone() const {
    return new Troll(*this);
}

std::string Troll::getDescription() const {
    return "Beefy";
}