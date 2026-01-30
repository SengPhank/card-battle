#include "game/MatchManager.h"
#include "game/Lane.h"
#include "cards/EntityCard.h"
#include <string>

// int lane_number;   
// EntityCard* plr1_entity; 
// EntityCard* plr2_entity;
    
Lane::Lane(MatchManager* gm, int laneNumber) : GM(gm), lane_number(laneNumber) {
    plr1_entity = nullptr;
    plr2_entity = nullptr;
}

bool Lane::placeCard(int player, EntityCard* card) {
    // Verify player and entity
    if (player == 1) {
        if (plr1_entity) return false;
        plr1_entity = card;
    } else if (player == 2) {
        if (plr2_entity) return false;
        plr2_entity = card;
    } else { // invalid player
        return false;
    }
    return true;
}
void Lane::enactLane() {
    // Plr1 card -> plr2, vice versa
    if (plr1_entity && plr2_entity) {
        plr2_entity->takeDamage(plr1_entity->getAttack());
    } else if (plr1_entity) {
        GM->damagePlr2(plr1_entity->getAttack());
    }

    if (plr1_entity && plr2_entity) {
        plr1_entity->takeDamage(plr2_entity->getAttack());
    } else if (plr2_entity) {
        GM->damagePlr1(plr2_entity->getAttack());
    }
    clearDefeated();
}
bool Lane::damagePlrEntity(int plr, int dmg) {
    if (plr == 1) {
        if (plr1_entity == nullptr) return false;
        plr1_entity->takeDamage(dmg);
    } else if (plr == 2) {
        if (plr2_entity == nullptr) return false;
        plr2_entity->takeDamage(dmg);
    }

    clearDefeated();
    return true;
}
void Lane::clearDefeated() {
    // Clear any defeated cards
    if (plr1_entity && plr1_entity->getHealth() <= 0) {
        delete plr1_entity;
        plr1_entity = nullptr;
    }

    if (plr2_entity && plr2_entity->getHealth() <= 0) {
        delete plr2_entity;
        plr2_entity = nullptr;
    }
}

int Lane::getLane() const {return this->lane_number;}
EntityCard* Lane::getPlr1Entity() const {return this->plr1_entity;}
EntityCard* Lane::getPlr2Entity() const {return this->plr2_entity;}

Lane::~Lane() {
    if (plr1_entity) delete plr1_entity;
    if (plr2_entity) delete plr2_entity;
}
