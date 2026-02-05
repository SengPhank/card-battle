#include "cards/Card.h"
#include "game/MatchManager.h"
/*
std::string name;        // Name
int cost;                // Cost (Tokens)
std::string description; // Information about this card (what it does, etc)
std::vector<std::string> abilities;
*/

Card::Card(std::string name, int cost, int owner) 
: name(name), cost(cost), owner(owner) {}

// Encapsulation
std::string Card::getName() const {
    return this->name;
}
int Card::getCost() const {
    return this->cost;
}
int Card::getOwner() const {
    return this->owner;
}
void Card::setOwner(int owner) {
    this->owner = owner;
}
// Default does nothing
bool Card::onPlayed(MatchManager* manager, int lane, int plr) {return false;}
