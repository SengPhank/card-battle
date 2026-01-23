#pragma once
#include "boot/ui/MainMenuPanel.h"
#include "boot/ui/UIManager.h"
#include <wx/wx.h>

class MainWindow : public wxFrame {
private:
    MainMenuPanel* mainMenuPanel;

public:
    MainWindow();
};
