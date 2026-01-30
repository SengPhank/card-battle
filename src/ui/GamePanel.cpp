#include "ui/GamePanelHelper.h"
#include "ui/GamePanel.h"
#include "game/MatchManager.h"
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
    selectedCard = nullptr;
    StoredMatch = nullptr;
    wxButton* selectedDeckButton = nullptr;
    defaultColour = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE);
    defaultFG = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT);
    // Init ui
    GamePanelHelper GPH;
    wxPanel* mainPanel = new wxPanel(this);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Receive data
    DataHeaderUI headerInfo = GPH.createHeader(mainPanel);
    DataTopUI topInf = GPH.createTop(mainPanel);
    DataBoardUI board1Inf = GPH.createBoard(mainPanel, CONSTANTS::NUM_LANES);
    DataBoardUI board2Inf = GPH.createBoard(mainPanel, CONSTANTS::NUM_LANES);
    DataBottomUI bottomInf = GPH.createBottom(mainPanel);
    
    // Unpack Header
    settingsBtn = headerInfo.settingsButton;
    headerMessage = headerInfo.topText;

    // Unpack topInfo
    enemyCards = topInf.cardsRemaining;
    enemyRage = topInf.rageText;
    enemyHealth = topInf.healthText;
    enemyTokens = topInf.tokensText;

    // Unpack boardInfo (into a sizer)
    wxBoxSizer* boardsSizer = new wxBoxSizer(wxVERTICAL);
    enemyBoard = board1Inf.buttons;
    yourBoard = board2Inf.buttons;
    boardsSizer->Add(board1Inf.panel, 1, wxEXPAND | wxALL, 8);
    boardsSizer->Add(board2Inf.panel, 1, wxEXPAND | wxALL, 8);
    
    // Unpack bottomPanel
    yourCards = bottomInf.cardsRemaining;
    yourRage = bottomInf.rageBtn;
    yourHealth = bottomInf.healthText;
    yourTokens = bottomInf.tokensText;
    yourDeck = bottomInf.deck;
    yourDeckPanel = bottomInf.deckPanel;
    endTurnBtn = bottomInf.endTurnBtn;
    deckLeft = bottomInf.leftDeck;
    deckRight = bottomInf.rightDeck;
    // =========== Bind key buttons ============
    settingsBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        std::cout << "Settings clicked" << std::endl;
    });
    deckLeft->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        RotateDeck(curPage-1);
    });
    deckRight->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        RotateDeck(curPage+1);
    });

    // ========== Assemble all UI ==========
    mainSizer->Add(headerInfo.panel, 5, wxEXPAND | wxALL, 5);
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
    selectedCard = nullptr;
    yourCards->SetLabel("Cards: " + std::to_string(plrDeck.size()));
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
    // Clear previous buttons
    yourDeck->Clear(true);  // destroys old buttons
    // Add new cards
    int from = page * CONSTANTS::DECK_VIEW;
    int to = from + CONSTANTS::DECK_VIEW;
    for (from; from < to; from++) {
        if (from >= plrDeck.size()) break;
        CardWidget* cardUI = new CardWidget(yourDeckPanel, plrDeck[from]);

        Card* curCard = plrDeck[from];
        cardUI->Bind(wxEVT_LEFT_DOWN, [this, cardUI, curCard](wxMouseEvent&) {
            this->tapCard(cardUI, curCard);
        });

        yourDeck->Add(cardUI, 1, wxEXPAND);

    }
    // Refresh layout
    yourDeckPanel->Layout();
    curPage = page;
    // Deselect any holding cards
    selectedCard = nullptr;
    selectedDeckButton = nullptr; 
    LightLane(true, *defaultColour, *defaultFG);
    LightLane(false, *defaultColour, *defaultFG);

}

void GamePanel::UpdatePlayerStats(int newHP, int newPlayerTokens, int newRage) {
    // Update the player's health and tokens
    yourHealth->SetLabel("Health: " + std::to_string(newHP));
    yourTokens->SetLabel("Tokens: " + std::to_string(newPlayerTokens));
    yourRage->SetLabel("Rage: " + std::to_string(newRage) + "%");
    if (newRage == 100) {
        yourRage->SetBackgroundColour(*wxGREEN);
        yourRage->SetForegroundColour(*wxBLACK);
    } else {
        yourRage->SetBackgroundColour(defaultColour);
        yourRage->SetForegroundColour(defaultFG);
    }
    yourRage->Refresh();

}

void GamePanel::UpdateEnemyStats(int newHP, int newEnemyTokens, int enemyDeckSize, int enemyRage) {
    // Update the enemy's health, tokens, and deck size
    enemyHealth->SetLabel("Health: " + std::to_string(newHP));
    enemyTokens->SetLabel("Tokens: " + std::to_string(newEnemyTokens));
    enemyCards->SetLabel("Cards: " + std::to_string(enemyDeckSize));
    this->enemyRage->SetLabel("Rage: " + std::to_string(enemyRage) + "%");
}

void GamePanel::UpdateBoard(MainBoard* board) {
    // Update the game board based on the MainBoard state
    std::vector<Lane*> allLanes = board->getLanes();
    for (int i = 0; i < allLanes.size(); i++) {
        Lane* curLane = allLanes[i];
        Card* enemy = curLane->getPlr2Entity();
        Card* yours = curLane->getPlr1Entity();
        if (enemy) {
            enemyBoard[i]->SetLabel(wxString::FromUTF8(enemy->displayCard()));
        } else {
            enemyBoard[i]->SetLabel("");
        }
        if (yours) {
            yourBoard[i]->SetLabel(wxString::FromUTF8(yours->displayCard()));
        } else {
            yourBoard[i]->SetLabel("");
        }
    }
}
void GamePanel::tapCard(CardWidget* widget, Card* card) {

    // Deselect if clicking same card
    if (selectedCard == card) {
        widget->setSelected(false);
        selectedCard = nullptr;

        LightLane(true, *defaultColour, *defaultFG);
        LightLane(false, *defaultColour, *defaultFG);
        return;
    }

    // Clear previous selection
    if (selectedDeckButton) {
        selectedDeckButton->setSelected(false);
    }

    selectedDeckButton = widget;
    selectedCard = card;

    widget->setSelected(true);

    // Highlight lanes
    if (card->getType() == Card::Type::INSTANT) {
        InstantCard* curCard = (InstantCard*)card;
        if (curCard->getUseEnemyEnt())
            LightLane(false, *wxRED, *wxWHITE, 1);
        if (curCard->getUseSelfEnt())
            LightLane(true, *wxGREEN, *wxBLACK, 1);
    }
    else {
        LightLane(true, *wxGREEN, *wxBLACK, 0);
    }
}

// Default, light all X lane to colour
void GamePanel::LightLane(bool yourLane, const wxColor& bgColour, const wxColor& fgColour, int occupied, int lane) {
    std::vector<Lane*> allLanes;
    if (StoredMatch) allLanes = StoredMatch->getBoard()->getLanes();

    if (yourLane) {
        if (lane == -1) {
            for (int i = 0; i < yourBoard.size(); i++) {
                if (occupied == 1) { // must have entity
                    if (allLanes.empty() || !allLanes[i]->getPlr1Entity())
                        continue;
                } else if (occupied == 0) { // must be empty
                    if (allLanes.empty() || allLanes[i]->getPlr1Entity())
                        continue;
                }
                yourBoard[i]->SetBackgroundColour(bgColour);
                yourBoard[i]->SetForegroundColour(fgColour);
            }
        } else {
            if (lane < 0 || lane >= yourBoard.size()) return;
            yourBoard[lane]->SetBackgroundColour(bgColour);
            yourBoard[lane]->SetForegroundColour(fgColour);
        }
    } else {
        if (lane == -1) {
            for (int i = 0; i < enemyBoard.size(); i++) {
                if (occupied == 1) { // must have entity
                    if (allLanes.empty() || !allLanes[i]->getPlr2Entity())
                        continue;
                } else if (occupied == 0) { // must be empty
                    if (allLanes.empty() || allLanes[i]->getPlr2Entity())
                        continue;
                }
                enemyBoard[i]->SetBackgroundColour(bgColour);
                enemyBoard[i]->SetForegroundColour(fgColour);
            } 
        } else {
            if (lane < 0 || lane >= enemyBoard.size()) return;
            enemyBoard[lane]->SetBackgroundColour(bgColour);
            enemyBoard[lane]->SetForegroundColour(fgColour);
        }
    }
}

void GamePanel::UpdateHeaderText(std::string s) {
    headerMessage->SetLabel(s);
}

// Encap
wxButton* GamePanel::getEndTurnButton() const {return this->endTurnBtn;}
wxButton* GamePanel::getYourRageButton() const {return this->yourRage;}
wxButton* GamePanel::getHelpPageButton() const {return nullptr;} // TBA
std::vector<wxButton*> GamePanel::getBoardButtons1() const {
    return this->enemyBoard;
}
std::vector<wxButton*> GamePanel::getBoardButtons2() const {
    return this->yourBoard;
}
Card* GamePanel::getSelectedCard() const {
    return this->selectedCard;
}
MatchManager* GamePanel::getMatchManager() const {
    return this->StoredMatch;
}
void GamePanel::setMatchManager(MatchManager* manager) {
    this->StoredMatch = manager;
}
GamePanel::~GamePanel() {}