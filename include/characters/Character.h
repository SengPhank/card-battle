#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

class MatchManager;

class Character {
protected:
    const int DEFAULT_HEALTH;
    const int DEFAULT_RAGE;
    int health;
    int rage;
    std::string name;
public:
    Character(int health, int rage, std::string name);
    virtual ~Character() = default;
    virtual Character* clone() const = 0;

    // Helper
    int rageCalculation(int damageTaken);
    virtual void takeDamage(int atk);
    virtual bool activateRage(MatchManager* manager) = 0;  

    // Encapsulation
    int getDFHEALTH() const;
    int getDFRAGE() const;
    int getHealth() const;
    int getRage() const;
    void setRage(int rage);
    void setHealth(int health);
    std::string getName() const;
};
