#include "cards/Card.h"

/*
int health;
int attack;
std::string name;
std::vector<std::string> abilities;
*/

Card::Card(std::string name, int health, int atk, int cost, std::vector<std::string> abilities) 
: health(health), attack(atk), name(name), cost(cost), abilities(abilities) {}

void Card::takeDamage(int atk) {
    health -= atk;
}
Card* Card::clone() {
    Card* newCard = new Card(name, health, attack, cost, abilities);
    return newCard;
}
std::string Card::statToString() {
    std::string s = std::format("{}\nHp: {}, Atk: {}\nCost: {}",
        this->name,
        this->health,
        this->attack,
        this->cost
    );
    return s;
}

// Encapsulation
int Card::getDamage() const {
    return this->attack;
}
int Card::getHealth() const {
    return this->health;
}
int Card::getCost() const {
    return this->cost;
}
std::string Card::getName() const {
    return this->name;
}
std::vector<std::string> Card::getAbilities() const {
    return this->abilities;
}

Card::~Card() {}
