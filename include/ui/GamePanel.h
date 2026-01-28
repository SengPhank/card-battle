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
#include "ui/GamePanelHelper.h"
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
    wxStaticText* yourHealth;
    wxStaticText* yourTokens;
    wxButton* yourRage;
    wxPanel* yourDeckPanel;
    wxGridSizer* yourDeck;

    // Dfault Game UI
    wxButton* endTurnBtn;
    std::vector<wxButton*> enemyBoard;
    std::vector<wxButton*> yourBoard;   
    wxButton* deckLeft;
    wxButton* deckRight;

    // Other UI
    wxButton* settingsBtn;
    wxStaticText* headerMessage;
    wxButton* selectedDeckButton;
    wxColour defaultColour;
    wxColour defaultFG;

    // Storage
    std::vector<Card*> plrDeck; // the last stored player deck
    int curPage;
    Card* selectedCard;

public:
    GamePanel(wxWindow* parent);
    ~GamePanel();

    // UI Updates
    void UpdateHeaderText(std::string s);
    void UpdateDeck(std::vector<Card*> plrDeck);
    void RotateDeck(int page);
    void UpdatePlayerStats(int newHP, int newPlayerTokens, int newRage);
    void UpdateEnemyStats(int newHP, int newEnemyTokens, int enemyDeckSize, int enemyRage);
    void UpdateBoard(MainBoard* board);
    
    // Encap
    wxButton* getEndTurnButton();
    std::vector<wxButton*> getBoardButtons1() const;
    std::vector<wxButton*> getBoardButtons2() const;
    Card* getSelectedCard() const;

};
