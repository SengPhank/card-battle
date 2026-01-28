// EntityCard.h
#pragma once
#include "cards/Card.h"

class InstantCard : public Card {
private:
    /* data */
public:
    InstantCard(std::string name, int cost);
    virtual ~InstantCard() = default;

    // Encap
    Type getType() const override;
    
    // Functionality
    Card* clone() const override;
    virtual std::string getDescription() const;
    std::string displayCard() override;

    // On play effects
    void onPlayed(MatchManager* manager, int lane) override;
    
};
