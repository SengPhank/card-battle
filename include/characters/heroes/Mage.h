#pragma once
#include "characters/Character.h"

// SPECIAL:
/*
For each enemy cards, deal 2 damage
For each of your cards, give them +2 health
*/
class Mage : public Character {
public:
    Mage();
    ~Mage();
    Character* clone() const override;
    bool activateRage(MatchManager* manager, int turn) override;
};
