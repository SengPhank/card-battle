/*
Manage matches by keeping track of player entities, cards, etc
*/
#pragma once
#include "boot/CardHandler.h"
#include "boot/ui/GamePanel.h"
#include "game/MainBoard.h"
#include "characters/Character.h"
#include "cards/Card.h"
#include <vector>

class MatchManager {
private:
    int turn; // what turn it currently is
    int awaiting; // whose turn it is // {1, 2}
    MainBoard* board;
    
    Character* plr1;
    int plr1Token;
    std::vector<Card*> plr1Deck; 

    Character* plr2;
    int plr2Token;
    std::vector<Card*> plr2Deck; 

    // Managers
    CardHandler* CH;
    GamePanel* gamePanel;
    
public:
    MatchManager(GamePanel* gamePanel, CardHandler* CH, Character* p1, Character* p2, int numLanes);

    // Player interaction
    bool requestPlay(int plr, int lane, Card* card);

    // Match interaction
    void damagePlr1(int atk);
    void damagePlr2(int atk);
    bool drawCard(int plr);
    void endTurn();
    
    // Encapsulation
    int getTurn() const;
    int getAwaiting() const;
    ~MatchManager();
};

