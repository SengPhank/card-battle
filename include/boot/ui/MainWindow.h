#pragma once
#include "ui/MainMenuPanel.h"
#include "ui/GamePanel.h"
#include "game/MatchManager.h"
#include <wx/wx.h>
#include <wx/simplebook.h>

class MainWindow : public wxFrame {
private:
    wxSimplebook* book;
    MainMenuPanel* mainMenuPanel;
    GamePanel* gamePanel;

public:
    MainWindow();

    // Encap
    GamePanel* getGamePanel() const;
    MainMenuPanel* getMainMenuPanel() const;
    ~MainWindow();
};
