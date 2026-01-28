#pragma once
#include "cards/InstantCard.h"

class MeteorShower : public InstantCard {
public:
    MeteorShower();
    ~MeteorShower();
    std::string getDescription() const override;
    Card* clone() const override;
    
    void onPlayed(MatchManager* manager, int lane);
};

