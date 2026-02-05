#include "characters/heroes/Tank.h"
#include "game/MatchManager.h"

Tank::Tank() : Character(35, 0, "Tank") {
    this->protectionTime = -1;
}
Tank::~Tank() {}

Character* Tank::clone() const {
    return new Tank(*this);
}

void Tank::takeDamage(int atk) {
    int healthLoss = atk;
    if (protectionTime - currentRound > 0) {
        healthLoss = (atk+1) * 0; // 100% damage reduction!
    }
    health -= healthLoss;
    rage += rageCalculation(healthLoss);

    // Cap rage
    rage = std::min(100, rage);
}
bool Tank::activateRage(MatchManager* manager, int turn) {
    if (rage < 100)
        return false;
    std::cout << "ACTIVIATING TANK ABILITY" << std::endl;
    protectionTime = turn + 2; // give this and next turn immunity
    rage = 0;

    this->setLastRageActive(turn);
    return true;
}

int Tank::getProtectionTime() const { return protectionTime;}
void Tank::setProtectionTime(int t) { this->protectionTime = t;}
