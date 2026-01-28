#pragma once
#include "cards/EntityCard.h"

class Bank : public EntityCard {
public:
    Bank();
    ~Bank();
    std::string getDescription() const override;
    Card* clone() const override;

    // Optional behaviours
    void onNewRound(MatchManager* manager) override;
};
