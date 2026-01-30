#include "game/MatchManager.h"
#include "characters/Mage.h"
#include "characters/Tank.h"
#include "boot/CardManager.h"
#include "bots/BasicBot.h"
#include "boot/ui/MainWindow.h"
#include "constants.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class mainApp : public wxApp {
public:
    virtual bool OnInit();
};

// Treat as main
bool mainApp::OnInit() {
    // Seed randomness
    std::srand(std::time(nullptr));

    // Initialize Data
    CardManager* cardManager = new CardManager();
    std::cout << "CARD DATA LOADED! THERE ARE " << cardManager->getCardLength() << std::endl;

    // Initialize UI
    MainWindow* gameFrame = new MainWindow();
    std::cout << "UI INITIALIZED! " << std::endl;

    // Initialize a Match manager
    Mage* mage = new Mage(50, 10);
    Tank* tank = new Tank(100, 30);
    MatchManager* MM = new MatchManager(gameFrame->getGamePanel(), cardManager, mage, tank, CONSTANTS::NUM_LANES);
    std::cout << "MATCH INITIALIZED! " << std::endl;

    // Link the gamepanel to our current game (Match Manager)
    gameFrame->getGamePanel()->setMatchManager(MM);
    std::cout << "LINK GAME TO PANEL!" << std::endl;

    // Show frame
    gameFrame->Show(true);
    std::cout << "COMPLETED LOADING" << std::endl;
    return true;
}

wxIMPLEMENT_APP(mainApp);