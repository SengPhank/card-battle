#include "characters/Mage.h"
#include <iostream>

Mage::Mage(int health, int rage): Character(health, rage, "Mage") {}

bool Mage::special() {
    if (rage < 100)
        return false;

    rage = 0;
    std::cout << "ATTACKED ALL ENTITIES ON BOARD!\n";
    return true;
}
