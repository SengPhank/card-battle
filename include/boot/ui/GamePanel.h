/* 
  cardsRemaining  [ENEMY HP]    Their Tokens

[                   BOARD                    ]
[                   BOARD                    ]

Your Tokens       [YOUR HP]
[           YOUR CARDS           ]  [END TURN]
           
*/

/*
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
    wxGridSizer* deck;
    wxStaticText* tokensText;
    wxStaticText* healthText;
    wxStaticText* rageText;
    wxButton* endTurnBtn;
};
*/
#pragma once

#include "game/MainBoard.h"
#include "boot/ui/GamePanelHelper.h"
#include <wx/wx.h>
#include <wx/grid.h>
#include <vector>
#include <string>
#include <iostream>

class MatchManager;

class GamePanel : public wxPanel {
private:
    // Enemy UI components
    wxStaticText* enemyCards;
    wxStaticText* enemyRage;
    wxStaticText* enemyHealth;
    wxStaticText* enemyTokens;

    // Your UI components
    wxStaticText* yourCards;
    wxStaticText* yourRage;
    wxStaticText* yourHealth;
    wxStaticText* yourTokens;
    wxPanel* yourDeckPanel;
    wxGridSizer* yourDeck;

    // Dfault Game UI
    wxButton* endTurnBtn;
    std::vector<wxButton*> enemyBoard;
    std::vector<wxButton*> yourBoard;   
    wxButton* deckLeft;
    wxButton* deckRight;

    // Storage
    std::vector<Card*> plrDeck; // the last stored player deck
    int curPage;

public:
    GamePanel(wxWindow* parent);
    ~GamePanel();

    // UI Updates
    void UpdateDeck(std::vector<Card*> plrDeck);
    void RotateDeck(int page);
    void UpdatePlayerStats(int newHP, int newPlayerTokens);
    void UpdateEnemyStats(int newHP, int newEnemyTokens, int enemyDeckSize);
    void UpdateBoard(const MainBoard*& board);

    // Encap
    wxButton* getEndTurnButton();

};
