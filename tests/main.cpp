#include "game/MatchManager.h"
#include "boot/CardManager.h"
#include "boot/CharacterManager.h"
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
    CharacterManager* characterManager = new CharacterManager();
    std::cout << "Card Loaded, " << cardManager->getEntityLength() << " entities and " << cardManager->getInstantLength() << " instant cards found" << std::endl;
    std::cout << "Character Loaded, " << characterManager->getAllCharacters().size() << " characters found" << std::endl;

    // Initialize UI
    MainWindow* gameFrame = new MainWindow();
    std::cout << "UI INITIALIZED! " << std::endl;

    // Initialize a Match manager
    Character* hero1 = characterManager->getRandomCharacter()->clone();
    Character* hero2 = characterManager->getRandomCharacter()->clone();
    MatchManager* matchManager = new MatchManager(gameFrame->getGamePanel(), cardManager, hero1, hero2, CONSTANTS::NUM_LANES);

    // Link the gamepanel to our current game (Match Manager)
    gameFrame->getGamePanel()->setMatchManager(matchManager);
    std::cout << "LINK GAME TO PANEL!" << std::endl;

    // Show frame
    gameFrame->Show(true);
    std::cout << "COMPLETED LOADING" << std::endl;
    return true;
}

wxIMPLEMENT_APP(mainApp);