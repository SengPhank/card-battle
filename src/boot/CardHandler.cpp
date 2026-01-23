#include "boot/CardHandler.h"
#include "cards/Card.h"
#include <fstream>
#include <iostream>

CardHandler::CardHandler() {
    std::ifstream file("assets/cards/cards.json");
    nlohmann::json data;
    file >> data;

    for (const auto& cardJson : data["cards"]) {
        int id = cardJson["id"];
        std::string name = cardJson["name"];
        int health = cardJson["health"];
        int attack = cardJson["attack"];
        std::vector<std::string> abilities =
            cardJson["abilities"].get<std::vector<std::string>>();

        Card card(id, name, health, attack, abilities);
        allCards.emplace(id, card);
    }
}

// Encapsulation
std::map<int, Card> CardHandler::getCards() const {
    return this->allCards;
}
int CardHandler::getTotalCards() const {
    return this->allCards.size();
}

CardHandler::~CardHandler() {}
