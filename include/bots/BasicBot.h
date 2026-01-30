/*
Basic bot to play other side of the game!

This bot's strategy is:
- Always play the most expensive card when available
- Always block an available opposing card
- Always use their rage ability, and target a random opponent with it (if offense)
- DOES NOT PLAY INSTANT CARDS (therefore can not draw them)
*/
#pragma once
#include "game/MatchManager.h"
#include <cstdlib> // for randomness

class BasicBot {
private:
    int playerId;                 // Which player this bot controls (1 or 2)
    Character* character;         // Who is this bot playing as?
    MatchManager* matchManager;   // Interface to perform actions
    MainBoard* board;             // Read-only game state

    // Decision helpers
    Card* chooseMostExpensiveCard(const std::vector<Card*>& deck, int tokens);
    Lane* chooseDefensiveLane();

public:
    BasicBot(int playerId, Character* character, MatchManager* matchManager, MainBoard* board);

    // Called when it's this bot's turn
    void takeTurn(const std::vector<Card*>& deck, int availableTokens);

    ~BasicBot();
};