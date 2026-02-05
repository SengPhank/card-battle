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
#include "ui/CardWidget.h"
#include "ui/wxCustomColours.h"
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
    wxButton* enemyCharacter;

    // Your UI components
    wxStaticText* yourCards;
    wxButton* yourCharacter;
    wxStaticText* yourTokens;
    wxStaticText* yourHealth;
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
    CardWidget* selectedDeckButton;

    // Storage/Managers
    MatchManager* StoredMatch;
    wxCustomColours colourManager;
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
    // Occupied: 0 Not occupied, 1 = Has to be occupied, -1 = doesnt matter. 
    void LightLane(bool yourLane, const wxColor& bgColour, const wxColor& fgColour, int occupied=-1, int lane=-1, bool damagedOnly=false);
    void LightCharacter(bool yourChar, const wxColor& bgColour, const wxColor& fgColour, int fullHP=-1);
    void tapCard(CardWidget* widget, Card* card);

    // Encap
    wxButton* getEndTurnButton() const;
    wxButton* getYourRageButton() const;
    wxButton* getHelpPageButton() const;
    wxButton* getYourCharButton() const;
    wxButton* getEnemyCharButton() const;
    std::vector<wxButton*> getBoardButtons1() const;
    std::vector<wxButton*> getBoardButtons2() const;
    MatchManager* getMatchManager() const;
    void setMatchManager(MatchManager* manager);
    void setYourCharacter(std::string s);
    void setEnemyCharacter(std::string s);
    Card* getSelectedCard() const;

};
