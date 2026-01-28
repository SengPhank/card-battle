#pragma once
#include <string>

class Character {
protected:
    int health;
    int rage;
    std::string name;
public:
    Character(int health, int rage, std::string name);
    virtual ~Character() = default;

    virtual void takeDamage(int atk);
    virtual bool special() = 0;  

    // Encapsulation
    int getHealth() const;
    int getRage() const;
    std::string getName() const;
};
