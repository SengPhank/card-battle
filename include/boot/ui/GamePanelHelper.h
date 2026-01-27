#pragma once
#include <vector>
#include "wx/wx.h"

// Structs for cleaner data sending
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
    wxStaticText* rageText;
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
    wxPanel* createHeader(wxPanel* parent);
    DataTopUI createTop(wxPanel* parent);
    DataBoardUI createBoard(wxPanel* parent, int numLanes);
    DataBottomUI createBottom(wxPanel* parent);
    ~GamePanelHelper();
};