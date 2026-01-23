#include "boot/ui/GamePanel.h"

/*
wxStaticText* enemyCards;
wxButton* enemyHealth;
wxStaticText* enemyToken;

*/
GamePanel::GamePanel(wxWindow* parent)
    : wxPanel(parent) {
    // Create the sizer for GamePanel
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Create a wxStaticText to display some text
    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "Hello, this is some text!", wxDefaultPosition, wxDefaultSize);
    wxButton* backButton = new wxButton(this, wxID_ANY, "Back", wxDefaultPosition, wxSize(120, 40));
    // Add the text to the sizer (with some padding)
    mainSizer->Add(staticText, 0, wxALIGN_CENTER | wxALL, 10);
    mainSizer->Add(backButton, 1, wxALIGN_LEFT | wxALL, 10);
    
    backButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        std::cout << "Back Clicked!\n";
    });
    // Set the sizer for the panel (so that it handles the layout)
    this->SetSizerAndFit(mainSizer);
}

void GamePanel::UpdateDeck(const std::vector<Card*>& plrDeck) {
    // Update the player's cards UI
}

void GamePanel::UpdatePlayerStats(int newHP, int newPlayerTokens) {
    // Update the player's health and tokens
}

void GamePanel::UpdateEnemyStats(int newHP, int newEnemyTokens, int enemyDeckSize) {
    // Update the enemy's health, tokens, and deck size
}

void GamePanel::UpdateBoard(const MainBoard*& board) {
    // Update the game board based on the MainBoard state
}

GamePanel::~GamePanel() {
}