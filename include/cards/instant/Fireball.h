#pragma once
#include "cards/InstantCard.h"

class Fireball : public InstantCard {
public:
    Fireball();
    ~Fireball();
    std::string getDescription() const override;
    Card* clone() const override;
    
    bool onPlayed(MatchManager* manager, int lane, int plr);
};

