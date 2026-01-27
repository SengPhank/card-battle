#include "boot/ui/MainWindow.h"
#include "constants.h"
#include <vector>
#include <iostream>
MainWindow::MainWindow() 
: wxFrame(nullptr, wxID_ANY, "Card Battle", wxDefaultPosition, wxSize(CONSTANTS::SCREENX, CONSTANTS::SCREENY), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {

    book = new wxSimplebook(this, wxID_ANY);

    // Create panels inside the book
    mainMenuPanel = new MainMenuPanel(book);
    gamePanel = new GamePanel(book);

    book->AddPage(mainMenuPanel, "Menu");
    book->AddPage(gamePanel, "Game");

    // Initially show menu
    book->ChangeSelection(0);
    book->Layout();

    // Bind Play button
    mainMenuPanel->playButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        std::cout << "pressed play!" << std::endl;
        book->ChangeSelection(1);});
}

GamePanel* MainWindow::getGamePanel() const {
    return this->gamePanel;
}
MainMenuPanel* MainWindow::getMainMenuPanel() const {
    return this->mainMenuPanel;
}

MainWindow::~MainWindow() {}