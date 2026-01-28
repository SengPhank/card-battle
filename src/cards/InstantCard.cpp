#include "cards/InstantCard.h"

InstantCard::InstantCard(std::string name, int cost) 
: Card(name, cost) {}

std::string InstantCard::displayCard() {
    std::string s = std::format("INSTANT\n{}\nCost: ${}",
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

void InstantCard::onPlayed(MatchManager* manager, int lane) {}