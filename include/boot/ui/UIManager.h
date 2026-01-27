#pragma once
#include "boot/ui/GamePanel.h"
#include "game/MatchManager.h"

// This module allows connection between game manager and game panel.
// Once turn is ended, card is drawn, entity damaged, update the UI.

class UIManager
{
private:
    /* data */
public:
    UIManager(/* args */);
    ~UIManager();
};
