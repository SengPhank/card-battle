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

    // some local variables about the game
    int lastRageActive;
    int currentRound;
public:
    Character(int health, int rage, std::string name);
    virtual ~Character() = default;
    virtual Character* clone() const = 0;

    // Helper
    int rageCalculation(int damageTaken);
    virtual void takeDamage(int atk);
    virtual bool activateRage(MatchManager* manager, int turn) = 0;  

    // Encapsulation
    int getDFHEALTH() const;
    int getDFRAGE() const;
    int getHealth() const;
    int getRage() const;
    int getLastRageActive() const;
    int getCurrentRound() const;
    void setRage(int rage);
    void setHealth(int health);
    void setLastRageActive(int t);
    void setCurrentRound(int t);

    std::string getName() const;
};
