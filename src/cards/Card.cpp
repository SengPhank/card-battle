#include "cards/Card.h"
#include "game/MatchManager.h"
/*
std::string name;        // Name
int cost;                // Cost (Tokens)
std::string description; // Information about this card (what it does, etc)
std::vector<std::string> abilities;
*/

Card::Card(std::string name, int cost) 
: name(name), cost(cost) {}

// Encapsulation
std::string Card::getName() const {
    return this->name;
}
int Card::getCost() const {
    return this->cost;
}

// Default does nothing
void Card::onPlayed(MatchManager* manager, int lane) {}
