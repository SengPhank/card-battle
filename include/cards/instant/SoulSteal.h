#pragma once
#include "cards/InstantCard.h"

class SoulSteal : public InstantCard {
public:
    SoulSteal();
    ~SoulSteal();
    std::string getDescription() const override;
    Card* clone() const override;
    
    bool onPlayed(MatchManager* manager, int lane, int plr);
};

