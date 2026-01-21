#include "GameManager.h"
#include "map/Lane.h"
#include "cards/Card.h"
#include <string>
#include <iostream>

// int lane_number;   
// Card* plr1_entity; 
// Card* plr2_entity;
    
Lane::Lane(GameManager* gm, int laneNumber) : GM(gm), lane_number(laneNumber) {
    plr1_entity = nullptr;
    plr2_entity = nullptr;
}

bool Lane::placeCard(int player, Card* card) {
    if (player == 1) {
        if (plr1_entity) return false;
        plr1_entity = card;
    } else {
        if (plr2_entity) return false;
        plr2_entity = card;
    }
    return true;
}
void Lane::enactLane() {
    std::cout << "Enacting in lane " << lane_number << std::endl;
    // Card1 do dmg to Card2 & vice versa
    if (plr2_entity != nullptr) {
        if (plr1_entity) {
            plr2_entity->takeDamage(plr1_entity->getDamage());
        } else {
            GM->damagePlr1(plr2_entity->getDamage());
        }
    }

    if (plr1_entity != nullptr) {
        if (plr2_entity) {
            plr1_entity->takeDamage(plr2_entity->getDamage());
        } else {
            GM->damagePlr2(plr1_entity->getDamage());
        }
    }

    // Clear any defeated cards
    if (plr1_entity != nullptr && plr1_entity->getHealth() <= 0) {
        delete plr1_entity;
        plr1_entity = nullptr;
    }

    if (plr2_entity != nullptr && plr2_entity->getHealth() <= 0) {
        delete plr2_entity;
        plr2_entity = nullptr;
    }

}

int Lane::getLane() const {
    return this->lane_number;
}

Lane::~Lane() {
    if (plr1_entity) delete plr1_entity;
    if (plr2_entity) delete plr2_entity;
}
