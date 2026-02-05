// EntityCard.h
#include "cards/EntityCard.h"

EntityCard::EntityCard(std::string name, int cost, int health, int attack, std::vector<std::string> abilities) 
: Card(name, cost), abilities(abilities), DEFAULT_HEALTH(health), DEFAULT_ATTACK(attack) {
    this->health = DEFAULT_HEALTH;
    this->attack = DEFAULT_ATTACK;
}

std::string EntityCard::displayCard() {
    std::string s = std::format("ENTITY\n{}\n✊ {} | ❤️ {}\n💵 {}",
        name, attack, health, cost
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
int EntityCard::getDFHEALTH() const {return this->DEFAULT_HEALTH;}
int EntityCard::getDFATTACK() const {return this->DEFAULT_ATTACK;}
int EntityCard::getHealth() const {return this->health;}
int EntityCard::getAttack() const {return this->attack;}
void EntityCard::setHealth(int health) { this->health = health; }
void EntityCard::setAttack(int attack) { this->attack = attack; }
std::vector<std::string> EntityCard::getAbilities() const {
    return this->abilities;
}
Card::Type EntityCard::getType() const { 
    return Type::ENTITY; 
}

// Default do nothing
bool EntityCard::onPlayed(MatchManager* manager, int lane) { return false; }

std::string EntityCard::getDescription() const {
    return "INSERT_ENTITY_CARD_DESCRIPTION_HERE";
}
// Behaviours
void EntityCard::onNewRound(MatchManager* manager) {}
void EntityCard::onCardDraw(MatchManager* manager) {}
void EntityCard::onRage(MatchManager* manager) {}