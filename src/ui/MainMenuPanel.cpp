#include "ui/MainMenuPanel.h"
#include "constants.h"
#include <wx/sizer.h>

MainMenuPanel::MainMenuPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(CONSTANTS::SCREENX, CONSTANTS::SCREENY))
{
    // Create buttons
    playButton = new wxButton(this, wxID_ANY, "Play", wxDefaultPosition, wxSize(240, 80));
    settingsButton = new wxButton(this, wxID_ANY, "Settings", wxDefaultPosition, wxSize(240, 80));

    // Use a vertical box sizer to stack buttons
    wxBoxSizer* vSizer = new wxBoxSizer(wxVERTICAL);

    // Add some spacing between buttons
    vSizer->AddSpacer(20);
    vSizer->Add(playButton, 0, wxALIGN_CENTER | wxALL, 10);
    vSizer->Add(settingsButton, 0, wxALIGN_CENTER | wxALL, 10);
    // vSizer->Add(exitButton, 0, wxALIGN_CENTER | wxALL, 10);

    // Center everything vertically in the panel
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddStretchSpacer(1);           // Top spacing
    mainSizer->Add(vSizer, 0, wxALIGN_CENTER);
    mainSizer->AddStretchSpacer(1);           // Bottom spacing

    // Set sizer to the panel
    this->SetSizer(mainSizer);
}
