#include "boot/ui/UIManager.h"

UIManager::UIManager(wxFrame* mainWindow, const std::vector<wxPanel*> panels)
: mainWindow(mainWindow), panels(panels) {}

void UIManager::showPanel(wxPanel* panel) {
    // Hide all panels
    for (auto p : panels) {
        if (p) p->Hide();
    }

    // Show the selected panel
    if (panel) {
        panel->Show();

        // Refresh layout of the main window after switching panels
        mainWindow->Layout();  // Refresh layout
    }
}

UIManager::~UIManager() {
    // UI deletes itself after the main frame is gone, so no need to delete manually
}