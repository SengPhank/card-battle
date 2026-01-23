#pragma once
#include <string>
#include <vector>
class Card {
protected:
    int cardID; // 0-number of cards
    int health;
    int attack;
    std::string name;
    std::vector<std::string> abilities;

    // Other data for assets
    // string path/to/image
    // string description

public:
    Card(int id, std::string name, int health, int atk, std::vector<std::string> abilities);
    void takeDamage(int atk);
    
    // Encapsulation
    int getID() const;
    int getDamage() const;
    int getHealth() const;
    std::string getName() const;
    std::vector<std::string> getAbilities() const;
    ~Card();
};
