#include "boot/CharacterManager.h"

// Include all characters
#include "characters/heroes/Tank.h"
#include "characters/heroes/Mage.h"

// std::vector<Character*> allCharacters;    

CharacterManager::CharacterManager() {
    // Push all characters seen
    allCharacters.push_back(new Tank());
    allCharacters.push_back(new Mage());
}
CharacterManager::~CharacterManager() {
    for (Character* i : allCharacters) {
        delete i;
    }
}
Character* CharacterManager::getRandomCharacter() const {
    int randomInd = rand()%allCharacters.size();
    if (randomInd < 0 || randomInd >= allCharacters.size()) return nullptr;
    return allCharacters[randomInd];
}

std::vector<Character*> CharacterManager::getAllCharacters() const {
    return this->allCharacters;
}
