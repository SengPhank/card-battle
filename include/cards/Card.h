// Card.h
#pragma once
#include <string>
#include <vector>
#include <format>
#include <iostream>

class MatchManager;

class Card {
protected:
    std::string name;        // Name
    int cost;                // Cost (Tokens)

public:
    Card(std::string name, int cost);
    virtual ~Card() = default;
    enum class Type { ENTITY, INSTANT };

    // Encapsulation
    std::string getName() const;
    int getCost() const ;
    virtual Type getType() const = 0;
    virtual std::string getDescription() const = 0;  // More accurate new window description
    virtual std::string displayCard() = 0;           // String readability placement
    
    
    // Call for easy cloning
    virtual Card* clone() const = 0;
    // Is used on both Instants and Entities (sometimes)
    virtual void onPlayed(MatchManager* manager, int lane);
};
