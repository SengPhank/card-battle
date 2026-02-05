#include "characters/Character.h"

Character::Character(int health, int rage, std::string name) : 
DEFAULT_HEALTH(health), DEFAULT_RAGE(rage), name(name) {
    this->health = DEFAULT_HEALTH;
    this->rage = DEFAULT_RAGE;
}

int Character::rageCalculation(int damageTaken) {
    // Gain rage proportion to damage
    int base = damageTaken * 6;
    int variance = base / 3;

    int gained = base + (rand() % (variance + 1));
    gained = std::min(gained, 40); // cap of 40 rage max
    return gained;
}

void Character::takeDamage(int atk) {
    health -= atk;
    rage += rageCalculation(atk);
    rage = std::min(100, rage);
}

int Character::getDFHEALTH() const {return this->DEFAULT_HEALTH;}
int Character::getDFRAGE() const {return this->DEFAULT_RAGE;}
int Character::getHealth() const { return this->health;}
int Character::getRage() const {return this->rage;}
int Character::getLastRageActive() const {return this->lastRageActive;}
int Character::getCurrentRound() const {return this->currentRound;}
void Character::setRage(int rage) {this->rage=rage;}
void Character::setHealth(int health) {this->health=health;}
void Character::setLastRageActive(int t) {this->lastRageActive = t;}
void Character::setCurrentRound(int t) {this->currentRound = t;}
std::string Character::getName() const {return this->name;}

