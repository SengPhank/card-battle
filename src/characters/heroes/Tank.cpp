#include "characters/heroes/Tank.h"
#include "game/MatchManager.h"

Tank::Tank() : Character(35, 0, "Tank") {}
Tank::~Tank() {}

Character* Tank::clone() const {
    return new Tank(*this);
}

void Tank::takeDamage(int atk) {
    int healthLoss = atk;
    if (protectionTime > 0) {
        healthLoss = (atk+1)/2;
    }
    health -= healthLoss;
    rage += rageCalculation(healthLoss);

    // Cap rage
    rage = std::min(100, rage);
}
bool Tank::activateRage(MatchManager* manager) {
    if (rage < 100)
        return false;
    std::cout << "ACTIVIATING TANK ABILITY" << std::endl;
    protectionTime += 2;
    rage = 0;
    return true;
}

int Tank::getProtectionTime() const { return protectionTime;}
