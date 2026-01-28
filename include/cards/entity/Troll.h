#pragma once
#include "cards/EntityCard.h"

class Troll : public EntityCard {
public:
    Troll();
    ~Troll();
    std::string getDescription() const override;
    Card* clone() const override;
};
