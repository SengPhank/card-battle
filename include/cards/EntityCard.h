// EntityCard.h
#pragma once
#include "cards/Card.h"

class EntityCard : public Card {
protected:
    int health;
    int attack;
    std::vector<std::string> abilities;
public:
    EntityCard(std::string name, int cost, int health, int attack, std::vector<std::string> abilities={});
    virtual ~EntityCard() = default;
    
    // Functionality
    void takeDamage(int dmg);
    std::string displayCard() override;
    Card* clone() const override;

    // Encapsulation
    int getHealth() const;
    int getAttack() const;
    std::vector<std::string> getAbilities() const;
    Type getType() const override;
    virtual std::string getDescription() const;

    // Behaviours/Hooks
    void onPlayed(MatchManager* manager, int lane) override; // REQUIRED, everything does nothing by default
    virtual void onNewRound(MatchManager* manager);
    virtual void onCardDraw(MatchManager* manager);
    virtual void onRage(MatchManager* manager);
};
