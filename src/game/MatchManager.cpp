#include "game/MatchManager.h"
#include "game/MainBoard.h"
#include "boot/CardManager.h"
#include "bots/BasicBot.h"
#include "constants.h"
#include <iostream>

// int turn; // what turn it currently is
// int awaiting; // whose turn it is // {1, 2}
// Character* plr1;
// std::vector<Card*> plr1Deck; 
// Character* plr2;
// std::vector<Card*> plr2Deck; 
// MainBoard* board;
    
MatchManager::MatchManager(GamePanel* gamePanel, CardManager* cardManager, Character* p1, Character* p2, int numLanes) : cardManager(cardManager), plr1(p1), plr2(p2) {
    this->turn = 1;
    this->awaiting = 1;  // default plr1 starts 
    this->plr1Token = 1; // default token start
    this->plr2Token = 1;
    this->gamePanel = gamePanel;
    this->botPlayer = nullptr;
    board = new MainBoard(this, numLanes);

    // Link the end-turn button to this game
    gamePanel->getEndTurnButton()->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        this->endTurn();
    });
    // Link lane buttons to this game
    std::vector<wxButton*> enemyBoard = gamePanel->getBoardButtons1();
    std::vector<wxButton*> yourBoard = gamePanel->getBoardButtons2();

    // Link to choosing specific attacks
    for (int i = 0; i < enemyBoard.size(); i++) {
        enemyBoard[i]->Bind(wxEVT_BUTTON, [this, i](wxCommandEvent&) {
            // std::cout << "Clicked Enemy lane " << i << std::endl;
            Card* cCard = this->gamePanel->getSelectedCard();
            if (cCard == nullptr) return;
            if (cCard->getType() != Card::Type::INSTANT) return;

            InstantCard* curCard = dynamic_cast<InstantCard*>(cCard);
            this->requestPlayEnemyBoard(1, i, curCard);
        });
    }
    // Link to playing lane
    for (int i = 0; i < yourBoard.size(); i++) {
        yourBoard[i]->Bind(wxEVT_BUTTON, [this, i](wxCommandEvent&) {
            this->requestPlay(1, i, this->gamePanel->getSelectedCard());
        });
    }
    // Link to rage button
    gamePanel->getYourRageButton()->Bind(wxEVT_BUTTON, [this, gamePanel](wxCommandEvent&) {
        // Rebind if player 1 is no longer strictly the player
        if (this->getAwaiting() == 1) {
            bool rageActivated = this->plr1->activateRage(this, turn);
            if (rageActivated) {
                updatePlrStatsUI();
                gamePanel->UpdateDeck(this->getPlr1Deck());
                gamePanel->UpdateBoard(this->getBoard());
            }
        }
    });
    // Link to enemy character
    gamePanel->getEnemyCharButton()->Bind(wxEVT_BUTTON, [this, gamePanel](wxCommandEvent&) {
        // Rebind if player 1 is no longer strictly the player
        if (this->getAwaiting() == 1) {
            std::cout << "Clicked enemy character's face " << std::endl;
            Card* cCard = this->gamePanel->getSelectedCard();
            if (cCard == nullptr) return;
            if (cCard->getType() != Card::Type::INSTANT) return;

            InstantCard* curCard = dynamic_cast<InstantCard*>(cCard);
            this->requestPlayEnemyChar(1, curCard);
        }
    });
    // Link to your character
    gamePanel->getYourCharButton()->Bind(wxEVT_BUTTON, [this, gamePanel](wxCommandEvent&) {
        // Rebind if player 1 is no longer strictly the player
        if (this->getAwaiting() == 1) {
            std::cout << "Clicked your character's face " << std::endl;
            Card* cCard = this->gamePanel->getSelectedCard();
            if (cCard == nullptr) return;
            if (cCard->getType() != Card::Type::INSTANT) return;

            InstantCard* curCard = dynamic_cast<InstantCard*>(cCard);
            this->requestPlaySelfChar(1, curCard);
        }
    });

    // OPTIONAL, INIT A BOT TO PLAY
    this->botPlayer = new BasicBot(2, p2, this, board);

    // Draw starting cards
    for (int i = 0; i < CONSTANTS::START_DECK; i++) {
        drawCard(1), drawCard(2);
    }
    // Init UI
    gamePanel->UpdateDeck(plr1Deck);
    gamePanel->setYourCharacter(plr1->getName());
    gamePanel->setEnemyCharacter(plr2->getName());
    this->updatePlrStatsUI();
    this->updateEnemyStatsUI();
    std::cout << "Initalized a game!\nPlayer1: " << plr1->getName() << " vs\nPlayer2: " << plr2->getName() << std::endl;
}

// Privates
bool MatchManager::verifyCardIntegrity(const std::vector<Card*>& deck, Card* card) {
    for (Card* i : deck) {
        if (i == card) return true;
    }
    std::cout << "WHERE DID YOU FIND THIS CARD???" << std::endl;
    return false;
}
bool MatchManager::removeCardFromPlr(std::vector<Card*>& plrDeck, Card* card) {
    // Remove it from the deck in-place
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
    return cardFound;
}

// Player interaction
bool MatchManager::requestPlay(int plr, int lane, Card* card) {
    // Verify turn and cost
    if (awaiting != plr) return false;
    int& plrToken = (awaiting == 1) ? plr1Token : plr2Token;
    std::vector<Card*>& plrDeck = (plr == 1) ? plr1Deck : plr2Deck;
    if (card == nullptr) return false;
    if (card->getCost() > plrToken) return false;
    if (!verifyCardIntegrity(plrDeck, card)) return false; // WHERE DID YOU FIND THIS CARD?

    // Check type of card requesting to be played
    if (card->getType() == Card::Type::ENTITY) {
        // std::cout << "PLAYING ENTITY " << std::endl;
        EntityCard* eCard = dynamic_cast<EntityCard*>(card);
        if (!eCard || !board->playCard(plr, lane, eCard)) return false;
    } else if (card->getType() == Card::Type::INSTANT) {
        // std::cout << "PLAYING INSTANT " << std::endl;
        InstantCard* eCard = dynamic_cast<InstantCard*>(card);
        // This card says they dont wanna be played on self entity or all board
        if (!eCard->getUseSelfEnt() && !eCard->getUseAnyBoard()) return false;
    } else {
        // Unknown card type
        return false; 
    }

    // Play any (on played) effects. If its an instant, make sure its actually played
    bool played = card->onPlayed(this, lane);
    if (card->getType() == Card::Type::INSTANT && !played) {
        std::cout << card->getName() << " refused to be played" << std::endl;
        return false; 
    }

    // Verify card was placed before paying
    plrToken -= card->getCost();
    removeCardFromPlr(plrDeck, card);

    // Update deck, then board, then player
    gamePanel->UpdateDeck(plr1Deck);
    gamePanel->UpdateBoard(board);
    updatePlrStatsUI();
    updateEnemyStatsUI();
    return true;
}
bool MatchManager::requestPlayEnemyBoard(int plr, int lane, InstantCard* card) {
    // Play on enemy territory (INSTANT CARD ONLY)
    if (awaiting != plr) return false;
    int& plrToken = (awaiting == 1) ? plr1Token : plr2Token;
    std::vector<Card*>& plrDeck = (plr == 1) ? plr1Deck : plr2Deck;
    if (card == nullptr) return false;
    if (card->getCost() > plrToken) return false;
    if (!verifyCardIntegrity(plrDeck, card)) return false; // WHERE DID YOU FIND THIS CARD?

    // This card says they dont wanna be played on an entity or all board
    if (!card->getUseEnemyEnt() && !card->getUseAnyBoard()) return false;

    // Attempt to play the card
    bool played = card->onPlayed(this, lane);
    if (!played) return false;
    // Verify card was placed before paying
    plrToken -= card->getCost();
    removeCardFromPlr(plrDeck, card);

    // Update deck, then board, then player
    gamePanel->UpdateDeck(plr1Deck);
    gamePanel->UpdateBoard(board);
    updatePlrStatsUI();
    updateEnemyStatsUI();
    return true;
}

bool MatchManager::requestPlaySelfChar(int plr, InstantCard* card) {
    // Verify some stuff
    if (awaiting != plr) return false;
    int& plrToken = (awaiting == 1) ? plr1Token : plr2Token;
    std::vector<Card*>& plrDeck = (plr == 1) ? plr1Deck : plr2Deck;
    if (card == nullptr) return false;
    if (card->getCost() > plrToken) return false;
    if (!verifyCardIntegrity(plrDeck, card)) return false;

    // This card says they dont wanna be played on yourself
    if (!card->getUseSelfChar()) return false;

    // Attempt play
    bool played = card->onPlayed(this, -1, 1);
    if (!played) return false;
    // Verify card was placed before paying
    plrToken -= card->getCost();
    removeCardFromPlr(plrDeck, card);

    // Update deck, then board, then player
    gamePanel->UpdateDeck(plr1Deck);
    gamePanel->UpdateBoard(board);
    updatePlrStatsUI();
    updateEnemyStatsUI();
    return true;
}

bool MatchManager::requestPlayEnemyChar(int plr, InstantCard* card) {
    // Verify some stuff
    if (awaiting != plr) return false;
    int& plrToken = (awaiting == 1) ? plr1Token : plr2Token;
    std::vector<Card*>& plrDeck = (plr == 1) ? plr1Deck : plr2Deck;
    if (card == nullptr) return false;
    if (card->getCost() > plrToken) return false;
    if (!verifyCardIntegrity(plrDeck, card)) return false;

    // This card says they dont wanna be played on enemy
    if (!card->getUseEnemyChar()) return false;

    // Attempt play
    bool played = card->onPlayed(this, -1, 2);
    if (!played) return false;
    // Verify card was placed before paying
    plrToken -= card->getCost();
    removeCardFromPlr(plrDeck, card);

    // Update deck, then board, then player
    gamePanel->UpdateDeck(plr1Deck);
    gamePanel->UpdateBoard(board);
    updatePlrStatsUI();
    updateEnemyStatsUI();
    return true;
}

// Match interaction
void MatchManager::damagePlr1(int atk) {
    plr1->takeDamage(atk);
    // std::cout << "plr1 took " << atk << " damage! current hp: " << plr1->getHealth() << std::endl;
}
void MatchManager::damagePlr2(int atk) {
    plr2->takeDamage(atk);
    // std::cout << "plr2 took " << atk << " damage! current hp: " << plr2->getHealth() << std::endl;
}
void MatchManager::healPlr1(int heal) {
    plr1->setHealth(std::min(plr1->getDFHEALTH(), plr1->getHealth() + heal));
    // std::cout << "plr1 healed " << heal << "! current hp: " << plr1->getHealth() << std::endl;
}
void MatchManager::healPlr2(int heal) {
    plr2->setHealth(std::min(plr2->getDFHEALTH(), plr2->getHealth() + heal));
    // std::cout << "plr2 healed " << heal << "! current hp: " << plr2->getHealth() << std::endl;
}

bool MatchManager::drawCard(int plr) {
    // CARD CAP
    std::vector<Card*>& plrDeck = (plr == 1) ? plr1Deck : plr2Deck;
    if (plrDeck.size() >= CONSTANTS::MAX_DECK_SIZE) return false; 
    Card* randomCard;
    // BASIC BOT DOES NOT DRAW INSTANT CARDS
    if (botPlayer && plr == 2) {
        randomCard = cardManager->chooseRandomEntity()->clone();
    } else {
        randomCard = cardManager->chooseRandomCard()->clone();
    }
    randomCard->setOwner(plr); // Provide ownership
    plrDeck.push_back(randomCard);
    // update plrs card
    if (plr == 1) {
        gamePanel->UpdateDeck(plr1Deck);
    } else if (plr == 2) {
        updateEnemyStatsUI();
    }
    return true;
}

void MatchManager::endTurn() {
    std::cout << "Turn ended. Current round: " << turn << std::endl;
    if (awaiting == 1) {
        gamePanel->UpdateHeaderText("Plr2's Turn");
        awaiting = 2;
        // Bot makes their plays
        if (botPlayer != nullptr) {
            botPlayer->takeTurn(plr2Deck, plr2Token);
        }
        gamePanel->UpdateHeaderText("Waiting to enact board...");
        return;
    }
    // Play the board
    board->enactBoard();
    gamePanel->UpdateBoard(board);

    // New Round, gain new tokens and draw a card each
    gamePanel->UpdateHeaderText("Plr1's Turn");
    awaiting = 1;
    turn++;
    plr1Token = turn, plr2Token = turn;
    drawCard(1), drawCard(2);
    // Run any (new round) here
    for (Lane* i : this->board->getLanes()) {
        EntityCard* yours = i->getPlr1Entity();
        EntityCard* enemies = i->getPlr2Entity();
        if (yours) yours->onNewRound(this);
        if (enemies) enemies->onNewRound(this);
    }
    // Update our player of the new turn
    plr1->setCurrentRound(turn);
    plr2->setCurrentRound(turn);
    
    
    // TODO: Call only frame updates here.
    this->updatePlrStatsUI();
    this->updateEnemyStatsUI();
}

// UI assistants
void MatchManager::updatePlrStatsUI() const {
    if (gamePanel == nullptr) return;
    gamePanel->UpdatePlayerStats(plr1->getHealth(), plr1Token, plr1->getRage());
}
void MatchManager::updateEnemyStatsUI() const {
    if (gamePanel == nullptr) return;
    gamePanel->UpdateEnemyStats(plr2->getHealth(), plr2Token, plr2Deck.size(), plr2->getRage());
}
// Encapsulation
int MatchManager::getTurn() const { return this->turn; }
int MatchManager::getAwaiting() const { return this->awaiting; }
MainBoard* MatchManager::getBoard() const { return this->board; }
int MatchManager::getPlr1Token() const { return this->plr1Token; }
int MatchManager::getPlr2Token() const { return this->plr2Token; }
std::vector<Card*> MatchManager::getPlr1Deck() const {return this->plr1Deck;}
std::vector<Card*> MatchManager::getPlr2Deck() const {return this->plr2Deck;}
void MatchManager::setPlr1Token(int token) {this->plr1Token = token;}
void MatchManager::setPlr2Token(int token) {this->plr2Token = token;}
Character* MatchManager::getPlr1Char() const {return this->plr1;}
Character* MatchManager::getPlr2Char() const {return this->plr2;}

MatchManager::~MatchManager() {
    delete plr1;
    delete plr2;
    delete board;
    if (botPlayer) delete botPlayer;
    for (Card* i : plr1Deck) {
        delete i;
    }
    for (Card* i : plr2Deck) {
        delete i;
    }
}



    
    