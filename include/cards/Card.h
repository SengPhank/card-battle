#pragma once
#include <string>
#include <vector>
class Card
{
protected:
    int health;
    int attack;
    std::string name;
    std::vector<std::string> abilities;

public:
    Card(std::string name, int health, int atk);
    void takeDamage(int atk);
    
    // Encapsulation
    int getDamage() const;
    int getHealth() const;
    ~Card();
};
