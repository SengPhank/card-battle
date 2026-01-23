#include "boot/ui/MainWindow.h"
#include <vector>
#include <iostream>
MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "Card Battle", wxDefaultPosition, wxSize(1800, 1600)) {

    // Create panels
    mainMenuPanel = new MainMenuPanel(this);
    gamePanel = new GamePanel(this);
    std::vector<wxPanel*> v = {mainMenuPanel, gamePanel};

    // Set up UI Manager
    uiManager = new UIManager(this, v);

    // Initially show main menu
    uiManager->showPanel(mainMenuPanel);

    // Set sizer for the main window
    wxBoxSizer* mainWindowSizer = new wxBoxSizer(wxVERTICAL);
    mainWindowSizer->Add(mainMenuPanel, 1, wxEXPAND | wxALL, 5);
    mainWindowSizer->Add(gamePanel, 1, wxEXPAND | wxALL, 5);

    // Set the main sizer for the frame (will manage the panels)
    this->SetSizerAndFit(mainWindowSizer);

    // Bind Play button
    mainMenuPanel->playButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        // Switch to the game panel when Play button is clicked
        uiManager->showPanel(gamePanel);
        std::cout << "Play Clicked!\n";
    });

    // Bind Settings button
    mainMenuPanel->settingsButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        std::cout << "Settings Clicked!\n";
    });
}