#include "characters/Character.h"

Character::Character(int health, int rage, std::string name) : 
health(health), rage(rage), name(name) {}

void Character::takeDamage(int atk) {
    health -= atk;
    rage += 5;
    if (rage > 100)
        rage = 100;
}

int Character::getHealth() const {
    return this->health;
}
int Character::getRage() const {
    return this->rage;
}

std::string Character::getName() const {
    return this->name;
}
