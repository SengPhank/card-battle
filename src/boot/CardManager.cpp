#include "boot/CardManager.h"

// === Include all cards ===
// Entities
#include "cards/entity/Bank.h"
#include "cards/entity/Troll.h"
// Instants
#include "cards/instant/Heal.h"
#include "cards/instant/MeteorShower.h"

#include <cstdlib>
#include <ctime>

CardManager::CardManager() {
    // Push all cards
    // Entites
    entityStore.push_back(new Bank());
    entityStore.push_back(new Troll());
    // Instants 
    instantStore.push_back(new Heal());
    instantStore.push_back(new MeteorShower());

    // Build combined list
    for (auto c : entityStore)
        allCards.push_back(c);

    for (auto c : instantStore)
        allCards.push_back(c);
}

CardManager::~CardManager() {
    for (auto c : allCards)
        delete c;
}

int CardManager::randomIndex(int n) {
    return std::rand() % n;
}

// Functionality
EntityCard* CardManager::chooseRandomEntity() {
    if (entityStore.empty()) return nullptr;

    return static_cast<EntityCard*>(
        entityStore[randomIndex(entityStore.size())]
    );
}

InstantCard* CardManager::chooseRandomInstant() {
    if (instantStore.empty()) return nullptr;

    return static_cast<InstantCard*>(
        instantStore[randomIndex(instantStore.size())]
    );
}

Card* CardManager::chooseRandomCard() {
    if (allCards.empty()) return nullptr;

    return allCards[randomIndex(allCards.size())];
}

// Encap
int CardManager::getEntityLength() const {
    return this->entityStore.size();
}
int CardManager::getInstantLength() const {
    return this->instantStore.size();
}
