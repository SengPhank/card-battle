#pragma once
#include <wx/wx.h>

class UIManager;

// Forward declaration for event handling
class MainMenuPanel : public wxPanel {
private:
public:
    MainMenuPanel(wxWindow* parent);

    wxButton* playButton;
    wxButton* settingsButton;
};
