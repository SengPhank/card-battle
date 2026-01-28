#pragma once
#include "cards/Card.h"
#include <string>

class MatchManager;

class Lane {
private:
    MatchManager* GM;
    int lane_number;    // For sorting (lane 1 goes first, etc)
    Card* plr1_entity;  // Could possible add multiple cards to more lane later. for now, 1 each
    Card* plr2_entity;
public:
    Lane(MatchManager* gm, int laneNumber);       // Initializes empty lane
    bool placeCard(int player, Card* card);      // Returns true or false if successful
    void enactLane();                                // Play this lane

    // Encapsulation
    int getLane() const;
    Card* getPlr1Entity() const;
    Card* getPlr2Entity() const;
    ~Lane();
};
