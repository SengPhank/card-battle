/* 
  cardsRemaining  [ENEMY HP]    Their Tokens

[                   BOARD                    ]
[                   BOARD                    ]

Your Tokens       [YOUR HP]
[           YOUR CARDS           ]  [END TURN]
           
*/
#pragma once

#include "game/MainBoard.h"
#include "game/MatchManager.h"
#include <wx/wx.h>
#include <wx/grid.h>
#include <vector>
#include <string>

class GamePanel : public wxPanel {
private:
    std::vector<wxButton*> playerCards;  // To represent player's cards

    // UI components (buttons, grids, etc.)
    wxStaticText* playerHPLabel;
    wxStaticText* enemyHPLabel;
    wxStaticText* playerTokensLabel;
    wxStaticText* enemyTokensLabel;

    wxGrid* gameBoardGrid;  // For board representation
    wxBoxSizer* mainSizer;

public:
    GamePanel(wxWindow* parent);
    ~GamePanel();

    // UI Updates
    void UpdateDeck(const std::vector<Card*>& plrDeck);
    void UpdatePlayerStats(int newHP, int newPlayerTokens);
    void UpdateEnemyStats(int newHP, int newEnemyTokens, int enemyDeckSize);
    void UpdateBoard(const MainBoard*& board);

};
