#include "game/MatchManager.h"
#include "game/MainBoard.h"
#include "boot/CardHandler.h"
#include <iostream>

// int turn; // what turn it currently is
// int awaiting; // whose turn it is // {1, 2}
// Character* plr1;
// std::vector<Card*> plr1Deck; 
// Character* plr2;
// std::vector<Card*> plr2Deck; 
// MainBoard* board;
    
MatchManager::MatchManager(CardHandler* CH, Character* p1, Character* p2, int numLanes) : CH(CH), plr1(p1), plr2(p2) {
    this->turn = 1;
    this->awaiting = 1;  // default plr1 starts 
    this->plr1Token = 1; // default token start
    this->plr2Token = 1;
    board = new MainBoard(this, numLanes);
    std::cout << "Initalized a game!\nPlayer1: " << plr1->getName() << " vs\nPlayer2: " << plr2->getName() << std::endl;
}

// Player interaction
bool MatchManager::requestPlay(int plr, int lane, Card* card) {
    // Verify turn and cost
    if (awaiting != plr) return false;
    int& plrToken = (awaiting == 1) ? plr1Token : plr2Token;
    if (card->getCost() > plrToken) return false;

    // Verify card was placed to pay the price;
    if (!board->playCard(plr, lane, card)) return false;
    plrToken -= card->getCost();

    // Remove it from the deck in-place
    std::vector<Card*>& plrDeck = (plr == 1) ? plr1Deck : plr2Deck;

    bool cardFound = false;
    for (int i = 0; i < plrDeck.size(); i++) {
        if (plrDeck[i] == card) {
            cardFound = true;
        }
        // Shift the right-card to the current
        if (cardFound && i < plrDeck.size()-1) {
            plrDeck[i] = plrDeck[i+1];
        }
    }
    // Remove last card, which is most likely a duplicate
    if (cardFound) plrDeck.pop_back();

    // TODO: Call ui frame updates here.

    return true;
}

// Match interaction
void MatchManager::damagePlr1(int atk) {
    plr1->takeDamage(atk);
    std::cout << "plr1 took " << atk << " damage! current hp: " << plr1->getHealth() << std::endl;
}
void MatchManager::damagePlr2(int atk) {
    plr2->takeDamage(atk);
    std::cout << "plr2 took " << atk << " damage! current hp: " << plr2->getHealth() << std::endl;

}
bool MatchManager::drawCard(int plr) {
    // CARD CAP
    int maxCap = 5;
    std::vector<Card*>& plrDeck = (plr == 1) ? plr1Deck : plr2Deck;
    if (plrDeck.size() >= maxCap) return false; 
    Card randoCard = CH->getRandomCard();
    return randoCard.clone();
}

void MatchManager::endTurn() {
    if (awaiting == 1) {
        awaiting = 2;
        return;
    }
    // New turn, gain new tokens and draw a card each
    awaiting = 1;
    turn++;
    plr1Token = turn, plr2Token = turn;
    drawCard(1), drawCard(2);
    // TODO: Call only frame updates here.
}


    

// Encapsulation
int MatchManager::getTurn() const {
    return this->turn;
}
int MatchManager::getAwaiting() const {
    return this->awaiting;
}

MatchManager::~MatchManager() {
    delete plr1;
    delete plr2;
    delete board;
    for (Card* i : plr1Deck) {
        delete i;
    }
    for (Card* i : plr2Deck) {
        delete i;
    }
}



    
    