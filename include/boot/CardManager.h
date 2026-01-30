#pragma once
#include "cards/EntityCard.h"
#include "cards/InstantCard.h"
#include <vector>
#include <cstdlib>

class CardManager {
private:
    std::vector<EntityCard*> entityStore;
    std::vector<InstantCard*> instantStore;
    std::vector<Card*> allCards;

    int randomIndex(int n);
public:
    CardManager();
    ~CardManager();

    // Functionality
    EntityCard* chooseRandomEntity();
    InstantCard* chooseRandomInstant();
    Card* chooseRandomCard();

    // Encap
    int getEntityLength() const;
    int getInstantLength() const;

};
