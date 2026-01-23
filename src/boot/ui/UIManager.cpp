#include "boot/ui/UIManager.h"

UIManager::UIManager(wxFrame* mainWindow, const std::vector<wxPanel*> panels)
: mainWindow(mainWindow), panels(panels) {}

void UIManager::showPanel(wxPanel* panel) {
    for (auto p : panels) {
        if (p) p->Hide();
    }
    if (panel) panel->Show();
    mainWindow->Layout(); // refresh layout
}
UIManager::~UIManager() {
    // UI deletes itself after main frame is gone so no need
}
