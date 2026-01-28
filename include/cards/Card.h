#pragma once
#include <format>
#include <string>
#include <vector>
class Card {
protected:
    int health;
    int attack;
    int cost;
    std::string name;
    std::vector<std::string> abilities;

    // Other data for assets
    // string path/to/image
    // string description

public:
    Card(std::string name, int health, int atk, int cost, std::vector<std::string> abilities);

    // Functionality
    void takeDamage(int atk);
    Card* clone();
    std::string statToString();
    
    // Encapsulation
    int getDamage() const;
    int getHealth() const;
    int getCost() const;
    std::string getName() const;
    std::vector<std::string> getAbilities() const;

    ~Card();
};
