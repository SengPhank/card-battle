#pragma once
#include "characters/Character.h"

// SPECIAL:
/*
Takes 50% less damage (rounded up) for the next 2 turns
Also receives less rage as a result
*/
class Tank : public Character {
private:
    // How many rounds left til protection wares off
    int protectionTime; 
public:
    Tank();
    ~Tank();
    Character* clone() const override;
    void takeDamage(int atk) override;
    bool activateRage(MatchManager* manager) override;
    // Encap
    int getProtectionTime() const;
};
