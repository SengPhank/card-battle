#pragma once
#include "characters/Character.h"
#include <vector>
#include <cstdlib>

class CharacterManager
{
private:
    std::vector<Character*> allCharacters;

public:
    CharacterManager();
    Character* getRandomCharacter() const;
    std::vector<Character*> getAllCharacters() const;
    ~CharacterManager();
};
