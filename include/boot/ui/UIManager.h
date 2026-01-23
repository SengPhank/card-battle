#pragma once
#include "boot/ui/MainWindow.h"
#include "boot/ui/SettingsPanel.h"
#include "boot/ui/GamePanel.h"
#include "boot/ui/SettingsPanel.h"

#include <wx/wx.h>
#include <vector>

class UIManager {
private:
    wxFrame* mainWindow;
    std::vector<wxPanel*> panels;
    
public:
    UIManager(wxFrame* mainWindow, const std::vector<wxPanel*> panels);
    void showPanel(wxPanel* panel); // Show one but all
    ~UIManager();
};
