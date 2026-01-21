#include "cards/Card.h"

/*
int health;
int attack;
std::string name;
std::vector<std::string> abilities;
*/

Card::Card(std::string name, int health, int atk) 
: health(health), attack(atk), name(name) {}

void Card::takeDamage(int atk) {
    health -= atk;
}

// Encapsulation
int Card::getDamage() const {
    return this->attack;
}
int Card::getHealth() const {
    return this->health;
}

Card::~Card() {}
