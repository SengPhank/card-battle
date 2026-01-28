// EntityCard.h
#include "cards/EntityCard.h"

EntityCard::EntityCard(std::string name, int cost, int health, int attack, std::vector<std::string> abilities) 
: Card(name, cost), abilities(abilities), health(health), attack(attack) {}

std::string EntityCard::displayCard() {
    std::string s = std::format("ENTITY\n{}\nHp: {}, Atk: {}\nCost: ${}",
        name, health, attack, cost
    );
    return s;
}

Card* EntityCard::clone() const {
    return new EntityCard(*this);
}
void EntityCard::takeDamage(int dmg) {
    this->health -= dmg;
}

// Encapsulation
int EntityCard::getHealth() const {
    return this->health;
}
int EntityCard::getAttack() const {
    return this->attack;
}
std::vector<std::string> EntityCard::getAbilities() const {
    return this->abilities;
}
Card::Type EntityCard::getType() const { 
    return Type::ENTITY; 
}

// Default do nothing
void EntityCard::onPlayed(MatchManager* manager, int lane) {}

std::string EntityCard::getDescription() const {
    return "INSERT_ENTITY_CARD_DESCRIPTION_HERE";
}
// Behaviours
void EntityCard::onNewRound(MatchManager* manager) {}
void EntityCard::onCardDraw(MatchManager* manager) {}
void EntityCard::onRage(MatchManager* manager) {}