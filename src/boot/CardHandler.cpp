#include "boot/CardHandler.h"
#include "cards/Card.h"
#include <fstream>
#include <iostream>

#include <cstdlib> // Random
#include <ctime>

CardHandler::CardHandler() {
    // Seed random for card retrieval
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::ifstream file("assets/cards/cards.json");
    nlohmann::json data;
    file >> data;
    for (const auto& cardJson : data["cards"]) {
        std::string name = cardJson["name"];
        int health = cardJson["health"];
        int attack = cardJson["attack"];
        int cost = cardJson["cost"];
        std::vector<std::string> abilities =
            cardJson["abilities"].get<std::vector<std::string>>();

        Card card(name, health, attack, cost, abilities);
        allCards.push_back(card);
    }
}

Card CardHandler::getRandomCard() {
    int maxID = this->allCards.size();
    int randomCardID = std::rand() % maxID;
    return this->allCards[randomCardID];
}

// Encapsulation
std::vector<Card> CardHandler::getCards() const {
    return this->allCards;
}
int CardHandler::getTotalCards() const {
    return this->allCards.size();
}

CardHandler::~CardHandler() {}
