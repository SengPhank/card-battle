#pragma once
#include "cards/InstantCard.h"

class Heal : public InstantCard {
public:
    Heal();
    ~Heal();
    std::string getDescription() const override;
    Card* clone() const override;
    
    bool onPlayed(MatchManager* manager, int lane, int plr);
};

