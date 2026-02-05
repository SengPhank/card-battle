/*
Manage matches by keeping track of player entities, cards, etc
*/
#pragma once
#include "boot/CardManager.h"
#include "ui/GamePanel.h"
#include "game/MainBoard.h"
#include "characters/Character.h"
#include "cards/Card.h"
#include "cards/InstantCard.h"
#include "cards/EntityCard.h"
#include <vector>

class BasicBot;

class MatchManager {
private:
    int turn; // what turn it currently is
    int awaiting; // whose turn it is // {1, 2}
    MainBoard* board;
    
    // Plr1 (YOU)
    Character* plr1;
    int plr1Token;
    std::vector<Card*> plr1Deck; 

    // Plr2 (ENEMY)
    BasicBot* botPlayer;
    Character* plr2;
    int plr2Token;
    std::vector<Card*> plr2Deck; 

    // Managers
    CardManager* cardManager;
    GamePanel* gamePanel;
    
    // Private
    bool verifyCardIntegrity(const std::vector<Card*>& deck, Card* card);
    bool removeCardFromPlr(std::vector<Card*>& plrDeck, Card* card);

public:
    MatchManager(GamePanel* gamePanel, CardManager* cardManager, Character* p1, Character* p2, int numLanes);

    // Player interaction
    bool requestPlay(int plr, int lane, Card* card);
    bool requestPlayEnemyBoard(int plr, int lane, InstantCard* card);
    bool requestPlaySelfChar(int plr, InstantCard* card);
    bool requestPlayEnemyChar(int plr, InstantCard* card);

    // Match interaction
    void damagePlr1(int atk);
    void damagePlr2(int atk);
    void healPlr1(int heal);
    void healPlr2(int heal);
    bool drawCard(int plr);
    void endTurn();
    
    // UI
    void updatePlrStatsUI() const;
    void updateEnemyStatsUI() const;

    // Encapsulation
    int getTurn() const;
    int getAwaiting() const;
    int getPlr1Token() const;
    int getPlr2Token() const;
    Character* getPlr1Char() const;
    Character* getPlr2Char() const;
    std::vector<Card*> getPlr1Deck() const;
    std::vector<Card*> getPlr2Deck() const;
    void setPlr1Token(int token);
    void setPlr2Token(int token);
    MainBoard* getBoard() const;
    ~MatchManager();
};

