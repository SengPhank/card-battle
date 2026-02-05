#include "bots/BasicBot.h"
#include <vector>
#include <iostream>

BasicBot::BasicBot(int playerId, Character* character, MatchManager* matchManager, MainBoard* board) {
    this->playerId = playerId;
    this->matchManager = matchManager;
    this->board = board;
    this->character = character;

}

// Private Decision making
Card* BasicBot::chooseMostExpensiveCard(const std::vector<Card*>& deck, int tokens) {
    // MOST EXPENSIVEV *PLAYABLE*
    std::vector<Card*> mostExpensive;
    int ms = INT_MIN;
    for (Card* i : deck) {
        int curCost = i->getCost();
        if (curCost < ms || curCost > tokens) continue;
        if (curCost > ms) {
            mostExpensive.clear();
            ms = curCost;
        }
        mostExpensive.push_back(i);
    }

    
    if (mostExpensive.empty()) return nullptr;
    // Choose a random card
    int rando = rand() % mostExpensive.size();
    return mostExpensive[rando];
}
Lane* BasicBot::chooseDefensiveLane() {
    // Find lanes with all free space and opposing a card
    std::vector<Lane*> allLanes = matchManager->getBoard()->getLanes();
    std::vector<Lane*> validLanes;
    for (Lane* i : allLanes) {
        EntityCard* ent1 = i->getPlr1Entity();
        EntityCard* ent2 = i->getPlr2Entity();
        if (ent1 != nullptr && ent2 == nullptr) validLanes.push_back(i);
    }
    if (validLanes.empty()) return nullptr;
    return validLanes[rand()%validLanes.size()];
}
// Take turn
void BasicBot::takeTurn(const std::vector<Card*>& deck, int availableTokens) {
    std::cout << "BOT IS THINKING... " << std::endl;
    int oppo = (playerId == 1) ? 2 : 1;
    // It'll initially want to play its rage ability first
    while (character->getRage() == 100) {
        character->activateRage(matchManager, matchManager->getTurn());
    }
    // Then play some cards        
    Card* cardPlay = chooseMostExpensiveCard(deck, availableTokens);
    Lane* lanePlay = chooseDefensiveLane(); // Try strategy
    if (!lanePlay) lanePlay = board->getRandomLane(playerId, false); // Play on free space

    bool accepted = true;
    while (cardPlay && lanePlay && accepted) {
        accepted = matchManager->requestPlay(playerId, lanePlay->getLane(), cardPlay);
        availableTokens -= cardPlay->getCost();
        cardPlay = chooseMostExpensiveCard(deck, availableTokens);
        lanePlay = chooseDefensiveLane();
        if (!lanePlay) lanePlay = board->getRandomLane(playerId, false);
    }
    std::cout << "BOT IS COMPLETED THINKING!" << std::endl;
}

BasicBot::~BasicBot() {}