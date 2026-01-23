// Read card data inside assets/cards/cards.json and returns vector for object construction
#pragma once

#include "cards/Card.h"
#include <vector> 
#include <nlohmann/json.hpp> // Include the nlohmann/json heade

class CardHandler {
private:
    // Ordered map for sorting by ID with UI
    std::vector<Card> allCards;
public:
    CardHandler();
    Card getRandomCard();

    // Encapsulation
    std::vector<Card> getCards() const;
    int getTotalCards() const;

    ~CardHandler();
};