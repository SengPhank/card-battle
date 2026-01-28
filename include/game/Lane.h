#pragma once
#include "cards/EntityCard.h"
#include <string>

class MatchManager;

class Lane {
private:
    MatchManager* GM;
    int lane_number;    // For sorting (lane 1 goes first, etc)
    EntityCard* plr1_entity;  // Could possible add multiple cards to more lane later. for now, 1 each
    EntityCard* plr2_entity;
public:
    Lane(MatchManager* gm, int laneNumber);       // Initializes empty lane
    bool placeCard(int player, EntityCard* card);      // Returns true or false if successful
    void enactLane();                                // Play this lane

    // Encapsulation
    int getLane() const;
    EntityCard* getPlr1Entity() const;
    EntityCard* getPlr2Entity() const;
    ~Lane();
};
