#include "characters/Tank.h"
#include <iostream>

Tank::Tank(int health, int rage) : Character(health, rage, "Tank") {}

bool Tank::special() {
    if (rage < 100)
        return false;

    rage = 0;
    std::cout << "TAKES 50% LESS DAMAGE THIS TURN!\n";
    return true;
}
