#pragma once
#include "boot/ui/MainMenuPanel.h"
#include "boot/ui/UIManager.h"
#include "boot/ui/GamePanel.h"
#include <wx/wx.h>

class MainWindow : public wxFrame {
private:
    MainMenuPanel* mainMenuPanel;
    GamePanel* gamePanel;

    // Managers
    UIManager* uiManager;
public:
    MainWindow();
};
