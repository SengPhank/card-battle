#include "ui/GamePanelHelper.h"
#include "constants.h"
// public:
//     GamePanelHelper();
//     wxPanel* createHeader();
//     wxPanel* createTop();
//     wxPanel* createBoard(int numLanes);
//     wxPanel* createBottom();
//     ~GamePanelHelper();

GamePanelHelper::GamePanelHelper() {}
DataHeaderUI GamePanelHelper::createHeader(wxPanel* parent) {
    DataHeaderUI ui{};
    // Create the header
    ui.panel = new wxPanel(parent);
    wxBoxSizer* headerSizer = new wxBoxSizer(wxHORIZONTAL);

    // Develop features
    ui.topText = new wxStaticText(ui.panel, wxID_ANY, "Match");
    ui.settingsButton = new wxButton(ui.panel, wxID_ANY, "Settings");

    // Move game name to the left, Settings to the right
    headerSizer->Add(ui.topText, 1, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    headerSizer->Add(ui.settingsButton, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    ui.panel->SetSizer(headerSizer);
    return ui;
}
DataTopUI GamePanelHelper::createTop(wxPanel* parent) {
    DataTopUI ui{};

    ui.panel = new wxPanel(parent);
    wxBoxSizer* enemySizer = new wxBoxSizer(wxHORIZONTAL);

    // ---- Left (Card / Rage)
    wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
    ui.cardsRemaining = new wxStaticText(ui.panel, wxID_ANY, "Card: X");
    ui.rageText  = new wxStaticText(ui.panel, wxID_ANY, "Rage: Y");
    leftSizer->Add(ui.cardsRemaining, 0, wxBOTTOM, 4);
    leftSizer->Add(ui.rageText, 0);

    // ---- Middle (Health)
    ui.healthText = new wxStaticText(ui.panel, wxID_ANY, "HEALTH: XXX");
    ui.healthText->SetFont(
        wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD)
    );

    // ---- Right (Tokens)
    ui.tokensText = new wxStaticText(ui.panel, wxID_ANY, "Tokens: XX");

    enemySizer->Add(leftSizer, 1, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    enemySizer->Add(ui.healthText, 1, wxALIGN_CENTER);
    enemySizer->Add(ui.tokensText, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    ui.panel->SetSizer(enemySizer);
    return ui;
}

DataBoardUI GamePanelHelper::createBoard(wxPanel* parent, int numLanes) {
    DataBoardUI ui{};
    // Create containers
    ui.panel = new wxPanel(parent);
    wxGridSizer* grid = new wxGridSizer(1, numLanes, 10, 10);

    // Populate with n lanes (buttons)
    for (int i = 0; i < numLanes; ++i) {
        wxButton* btn = new wxButton(
            ui.panel,
            wxID_ANY,
            // wxString::Format("%s %d", "Empty", i + 1)
            ""
        );
        grid->Add(btn, 1, wxEXPAND);
        ui.buttons.push_back(btn);
    }

    ui.panel->SetSizer(grid);
    return ui;
}

DataBottomUI GamePanelHelper::createBottom(wxPanel* parent) {
    DataBottomUI ui{};
    // Create YOUR UI
    /* [YOUR CARDS HERE] [<][>]  STATS HERE  (End Turn) */
    ui.panel = new wxPanel(parent);
    wxBoxSizer* bottomSizer = new wxBoxSizer(wxHORIZONTAL);

    // Cards container (LEFT)
    ui.deckPanel = new wxPanel(ui.panel);
    ui.deckPanel->SetBackgroundColour(wxColour(60, 60, 60));

    wxBoxSizer* cardsSizer = new wxBoxSizer(wxVERTICAL);

    // How many cards you have remaining
    ui.cardsRemaining = new wxStaticText(ui.deckPanel, wxID_ANY, "Cards: XX");
    ui.cardsRemaining->SetForegroundColour(*wxWHITE);

    // Cards grid (how many you can view at once)
    ui.deck = new wxGridSizer(1, CONSTANTS::DECK_VIEW, 8, 8);
    // for (int i = 0; i < CONSTANTS::DECK_VIEW; ++i) {
    //     wxButton* btn = new wxButton(
    //         ui.deckPanel,
    //         wxID_ANY,
    //         wxString::Format("C%d", i + 1),
    //         wxDefaultPosition,
    //         wxSize(-1, 70)
    //     );
    //     deck->Add(btn, 1, wxEXPAND);
    // }

    cardsSizer->Add(ui.cardsRemaining, 10, wxBOTTOM, 6);
    cardsSizer->Add(ui.deck, 90, wxEXPAND);
    ui.deckPanel->SetSizer(cardsSizer);

    // Navigation buttons 
    wxBoxSizer* navSizer = new wxBoxSizer(wxVERTICAL);

    ui.leftDeck = new wxButton(ui.panel, wxID_ANY, "<");
    ui.rightDeck = new wxButton(ui.panel, wxID_ANY, ">");

    navSizer->Add(ui.leftDeck, 0, wxBOTTOM, 5);
    navSizer->Add(ui.rightDeck, 0);

    // Your Stats panel
    wxBoxSizer* statsSizer = new wxBoxSizer(wxVERTICAL);
    ui.healthText = new wxStaticText(ui.panel, wxID_ANY, "Health: XX");
    ui.tokensText = new wxStaticText(ui.panel, wxID_ANY, "Tokens: XX");
    ui.rageBtn = new wxButton(ui.panel, wxID_ANY, "Rage: Y", wxDefaultPosition, wxSize(100, 50));

    statsSizer->Add(ui.healthText, 0, wxBOTTOM, 4);
    statsSizer->Add(ui.tokensText, 0, wxBOTTOM, 4);
    statsSizer->Add(ui.rageBtn, 0);

    // End Turn button
    ui.endTurnBtn = new wxButton(ui.panel, wxID_ANY, "End Turn", wxDefaultPosition, wxSize(100, 50));

    // Assemble bottom panel
    bottomSizer->Add(ui.deckPanel, 1, wxEXPAND | wxALL, 8);     
    bottomSizer->Add(navSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL, 8);
    bottomSizer->Add(statsSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL, 8);
    bottomSizer->Add(ui.endTurnBtn, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);

    ui.panel->SetSizer(bottomSizer);
    return ui;
}
GamePanelHelper::~GamePanelHelper() {}