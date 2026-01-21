#pragma once
#include "Character.h"

class Tank : public Character {
public:
    Tank(int health, int rage);
    bool special() override;
};
