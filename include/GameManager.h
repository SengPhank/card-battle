/*
Manage matches by keeping track of player entities, cards, etc
*/
#pragma once
#include "map/MainBoard.h"
#include "characters/Character.h"

#include <vector>

class GameManager {
private:
    int turn;
    Character* plr1;
    Character* plr2;
    MainBoard* board;
    
public:
    GameManager(Character* p1, Character* p2);
    MainBoard* initGame(int numLanes);

    void damagePlr1(int atk);
    void damagePlr2(int atk);
    
    // Encapsulation
    int getTurn() const;

    ~GameManager();
};

