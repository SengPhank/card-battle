// Read card data inside assets/cards/cards.json and returns vector for object construction
#pragma once

#include "cards/Card.h"
#include <map> 
#include <nlohmann/json.hpp> // Include the nlohmann/json header

class CardHandler {
private:
    // Ordered map for sorting by ID with UI
    std::map<int, Card> allCards;
public:
    CardHandler();
    
    // Encapsulation
    std::map<int, Card> getCards() const;
    int getTotalCards() const;

    ~CardHandler();
};