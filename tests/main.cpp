#include "game/MatchManager.h"
#include "characters/Mage.h"
#include "characters/Tank.h"
#include "boot/CardHandler.h"

#include "boot/ui/MainWindow.h"
#include "constants.h"
#include <iostream>

class mainApp : public wxApp {
public:
    virtual bool OnInit();
};

// Treat as main
bool mainApp::OnInit() {
    // Initialize Data
    CardHandler* CH = new CardHandler;
    std::vector<Card> allCards = CH->getCards();
    for (Card& i : allCards) {
        std::cout << i.getName() << std::endl;
    }
    std::cout << "CARD DATA LOADED" << std::endl;

    // Initialize UI
    MainWindow* gameFrame = new MainWindow();

    // Initialize a Match manager
    Mage* mage = new Mage(50, 10);
    Tank* tank = new Tank(100, 30);
    MatchManager* MM = new MatchManager(gameFrame->getGamePanel(), CH, mage, tank, CONSTANTS::NUM_LANES);

    // Show frame
    gameFrame->Show(true);
    std::cout << "COMPLETED LOADING" << std::endl;
    return true;
}

wxIMPLEMENT_APP(mainApp);