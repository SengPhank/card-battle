#include "cards/Card.h"

/*
int health;
int attack;
std::string name;
std::vector<std::string> abilities;
*/

Card::Card(int id, std::string name, int health, int atk, std::vector<std::string> abilities) 
: health(health), attack(atk), name(name), cardID(id), abilities(abilities) {}

void Card::takeDamage(int atk) {
    health -= atk;
}

// Encapsulation
int Card::getID() const {
    return this->cardID;
}
int Card::getDamage() const {
    return this->attack;
}
int Card::getHealth() const {
    return this->health;
}
std::string Card::getName() const {
    return this->name;
}
std::vector<std::string> Card::getAbilities() const {
    return this->abilities;
}

Card::~Card() {}
