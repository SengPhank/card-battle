#include "boot/ui/GamePanelHelper.h"
#include "boot/ui/GamePanel.h"
#include "constants.h"
/*// Enemy UI components
wxStaticText* enemyCards;
wxStaticText* enemyRage;
wxStaticText* enemyHealth;
wxStaticText* enemyTokens;

// Your UI components
wxStaticText* yourCards;
wxStaticText* yourRage;
wxStaticText* yourHealth;
wxStaticText* yourTokens;
wxGridSizer* deck;

// Dfault Game UI
wxButton* endTurnBtn;
std::vector<wxButton*> enemyBoard;
std::vector<wxButton*> yourBoard; 
*/

GamePanel::GamePanel(wxWindow* parent)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(CONSTANTS::SCREENX, CONSTANTS::SCREENY)) {
    // Init variables
    curPage = 0;
    plrDeck = {};
    GamePanelHelper GPH;
    wxPanel* mainPanel = new wxPanel(this);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Receive data
    wxPanel* headerPanel = GPH.createHeader(mainPanel);
    DataTopUI topInf = GPH.createTop(mainPanel);
    DataBoardUI board1Inf = GPH.createBoard(mainPanel, 4);
    DataBoardUI board2Inf = GPH.createBoard(mainPanel, 4);
    DataBottomUI bottomInf = GPH.createBottom(mainPanel);
   
    // Unpack topInfo
    enemyCards = topInf.cardsRemaining;
    enemyRage = topInf.rageText;
    enemyHealth = topInf.healthText;
    enemyTokens = topInf.tokensText;

    // Unpack boardInfo (into a sizer)
    wxBoxSizer* boardsSizer = new wxBoxSizer(wxVERTICAL);
    boardsSizer->Add(board1Inf.panel, 1, wxEXPAND | wxALL, 8);
    boardsSizer->Add(board2Inf.panel, 1, wxEXPAND | wxALL, 8);
    
    // Unpack bottomPanel
    yourCards = bottomInf.cardsRemaining;
    yourRage = bottomInf.rageText;
    yourHealth = bottomInf.healthText;
    yourTokens = bottomInf.tokensText;
    yourDeck = bottomInf.deck;
    yourDeckPanel = bottomInf.deckPanel;
    endTurnBtn = bottomInf.endTurnBtn;
    deckLeft = bottomInf.leftDeck;
    deckRight = bottomInf.rightDeck;
    // =========== Bind key buttons ============
    deckLeft->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        RotateDeck(curPage-1);
    });
    deckRight->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        RotateDeck(curPage+1);
    });

    // ========== Initialize a game ===========

    // ========== Assemble all UI ==========
    mainSizer->Add(headerPanel, 5, wxEXPAND | wxALL, 5);
    mainSizer->Add(topInf.panel, 10, wxEXPAND | wxALL, 5);
    mainSizer->Add(boardsSizer, 55, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);
    mainSizer->Add(bottomInf.panel, 30, wxEXPAND | wxALL, 5);

    mainPanel->SetSizer(mainSizer);

    wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->Add(mainPanel, 1, wxEXPAND);
    this->SetSizer(panelSizer);
}

void GamePanel::UpdateDeck(std::vector<Card*> plrDeck) {
    // Update player's cards
    this->plrDeck = plrDeck;
    // Update the player's cards UI
    RotateDeck(curPage);
}
void GamePanel::RotateDeck(int page) {
    int groups = plrDeck.size()/CONSTANTS::DECK_VIEW;
    // If currentPage is invalid, (played a last card on page x), 
    // then snap to the last page
    if (page > groups) {
        if (groups == 0) { // base case
            page = 0;
        } else if (page%CONSTANTS::DECK_VIEW == 0) { // exactly 4 cards, no need for a new page
            page = groups-1;
        } else {
            page = groups;
        }
    } else if (page < 0) {
        page = 0;
    }
    std::cout << "clearing children. std: " << plrDeck.size() << std::endl;
    // Clear previous buttons
    yourDeck->Clear(true);  // destroys old buttons

    // Add new cards
    int from = page * CONSTANTS::DECK_VIEW;
    int to = from + CONSTANTS::DECK_VIEW;
    for (from; from < to; from++) {
        if (from >= plrDeck.size()) break;
        wxButton* btn = new wxButton(
            yourDeckPanel,
            wxID_ANY,
            // wxString::Format("C%d", from + i + 1),
            wxString::Format("Name: %s", plrDeck[from]->getName()),
            wxDefaultPosition,
            wxSize(-1, 70)
        );
        yourDeck->Add(btn, 1, wxEXPAND);
    }
    // Refresh layout
    yourDeckPanel->Layout();
    curPage = page;
    std::cout << "on page " << curPage << " out of " << groups << std::endl;

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

// Encap
wxButton* GamePanel::getEndTurnButton() {
    return this->endTurnBtn;
}

GamePanel::~GamePanel() {
}