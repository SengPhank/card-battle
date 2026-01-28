#pragma once
#include <vector>
#include "wx/wx.h"

// Structs for cleaner data sending
struct DataHeaderUI {
    wxPanel* panel;
    wxStaticText* topText;
    wxButton* settingsButton;
};
struct DataTopUI {
    wxPanel* panel;
    wxStaticText* cardsRemaining;
    wxStaticText* rageText;
    wxStaticText* healthText;
    wxStaticText* tokensText;
};

struct DataBoardUI {
    wxPanel* panel;
    std::vector<wxButton*> buttons;
};
struct DataBottomUI {
    wxPanel* panel;
    wxStaticText* cardsRemaining;
    wxStaticText* tokensText;
    wxStaticText* healthText;
    wxButton* rageBtn;
    wxButton* endTurnBtn;
    wxButton* leftDeck;
    wxButton* rightDeck;
    wxPanel* deckPanel;
    wxGridSizer* deck;
};

// Class
class GamePanelHelper {
public:
    GamePanelHelper();
    // Initialization functions
    DataHeaderUI createHeader(wxPanel* parent);
    DataTopUI createTop(wxPanel* parent);
    DataBoardUI createBoard(wxPanel* parent, int numLanes);
    DataBottomUI createBottom(wxPanel* parent);
    ~GamePanelHelper();
};