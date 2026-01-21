#pragma once
#include "Character.h"

class Mage : public Character {
public:
    Mage(int health, int rage);
    bool special() override;
};
