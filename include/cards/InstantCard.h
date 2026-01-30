// EntityCard.h
#pragma once
#include "cards/Card.h"

class InstantCard : public Card {
protected:
    /* Determines if the current card can be used on  specific card/character types */
    bool useEnemyChar;
    bool useEnemyEnt;
    bool useSelfChar;
    bool useSelfEnt;
    bool useAnyBoard;

    void setUseEnemyChar(bool t);
    void setUseEnemyEnt(bool t);
    void setUseSelfChar(bool t);
    void setUseSelfEnt(bool t);
    void setUseAnyBoard(bool t);
public:
    InstantCard(std::string name, int cost);
    virtual ~InstantCard() = default;

    // Encap
    Type getType() const override;
    bool getUseEnemyChar() const;
    bool getUseEnemyEnt() const;
    bool getUseSelfChar() const;
    bool getUseSelfEnt() const;
    bool getUseAnyBoard() const;
    
    // Functionality
    Card* clone() const override;
    virtual std::string getDescription() const;
    std::string displayCard() override;

    // On play effects (returns true for successful, false if not)
    bool onPlayed(MatchManager* manager, int lane) override;
    
};
