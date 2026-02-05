#include "cards/InstantCard.h"

InstantCard::InstantCard(std::string name, int cost) 
: Card(name, cost) {
    // Can't use it anywhere by default
    this->useEnemyChar = false;
    this->useEnemyEnt = false;
    this->useSelfChar = false;
    this->useSelfEnt = false;
    this->useAnyBoard = false;
    this->damagedOnly = false;
}

std::string InstantCard::displayCard() {
    std::string s = std::format("INSTANT\n{}\n💵 {}",
        name, cost
    );
    return s;
}
Card* InstantCard::clone() const {
    return new InstantCard(*this);
}
Card::Type InstantCard::getType() const { 
    return Type::INSTANT; 
}

std::string InstantCard::getDescription() const {
    return "INSERT_INSTANT_CARD_DESCRIPTION_HERE";
}

bool InstantCard::onPlayed(MatchManager* manager, int lane, int plr) { return false; }

// Encap
bool InstantCard::getUseEnemyChar() const { return this->useEnemyChar; }
bool InstantCard::getUseEnemyEnt() const { return this-> useEnemyEnt; }
bool InstantCard::getUseSelfChar() const { return this->useSelfChar; }
bool InstantCard::getUseSelfEnt() const { return this->useSelfEnt; }
bool InstantCard::getUseAnyBoard() const { return this->useAnyBoard; }
bool InstantCard::getDamagedOnly() const { return this->damagedOnly; }
void InstantCard::setUseEnemyChar(bool t) { this->useEnemyChar = t; }
void InstantCard::setUseEnemyEnt(bool t) { this->useEnemyEnt = t;}
void InstantCard::setUseSelfChar(bool t) { this->useSelfChar = t;}
void InstantCard::setUseSelfEnt(bool t) { this->useSelfEnt = t;}
void InstantCard::setUseAnyBoard(bool t) { this->useAnyBoard = t;}
void InstantCard::setDamagedOnly(bool t) { this->damagedOnly = t;}
