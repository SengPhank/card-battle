#include "boot/ui/MainMenuPanel.h"

MainMenuPanel::MainMenuPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    // Create buttons
    playButton = new wxButton(this, wxID_ANY, "Play", wxPoint(50, 50), wxSize(120, 40));
    settingsButton = new wxButton(this, wxID_ANY, "Settings", wxPoint(50, 110), wxSize(120, 40));
}

// wxPanelBase::Create(wxWindow*, int, wxPoint const&, wxSize const&, long, wxString const&