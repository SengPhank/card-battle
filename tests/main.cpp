#include "game/MatchManager.h"
#include "characters/Mage.h"
#include "characters/Tank.h"
#include "boot/CardHandler.h"

#include "boot/ui/MainWindow.h"
#include "boot/ui/UIManager.h"
#include <iostream>

class mainApp : public wxApp
{
public:
    virtual bool OnInit();
};
DECLARE_APP(mainApp)

// Treat as main
bool mainApp::OnInit() {
    // Initialize Data
    CardHandler CH;
    std::map<int, Card> allCards = CH.getCards();
    for (auto [id, Card] : allCards) {
        std::cout << id << " : " << Card.getName() << std::endl;
    }
    std::cout << "CARD DATA LOADED" << std::endl;
    // Initialize UI
    MainWindow* gameFrame = new MainWindow();
    std::cout << "UI LOADED" << std::endl;
    // Show frame
    gameFrame->Show(true);
    std::cout << "COMPLETED LOADING" << std::endl;
    return true;
}
