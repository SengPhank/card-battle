#include "boot/ui/MainWindow.h"
#include <vector>
#include <iostream>
MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "Card Battle", wxDefaultPosition, wxSize(800, 600))
{
    // Create panels
    mainMenuPanel = new MainMenuPanel(this);
    std::vector<wxPanel*> v = {mainMenuPanel};

    // Set up UI Manager
    uiManager = new UIManager(this, v);

    // Initially show main menu
    uiManager->showPanel(mainMenuPanel);

    // Bind Play button
    mainMenuPanel->playButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        // Here you would create the game panel and show it
        // if (!gamePanel) {
        //     gamePanel = new wxPanel(this);
        //     // TODO: add game UI inside gamePanel
        //     uiManager->showPanel(gamePanel);
        // } else {
        //     uiManager->showPanel(gamePanel);
        // }
        std::cout << "Play Clicked!\n";
    });

    // Bind Settings button
    mainMenuPanel->settingsButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        std::cout << "Settings Clicked!\n";
        // wxMessageBox("Settings clicked!");
    });
}