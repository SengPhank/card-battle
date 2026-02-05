#include "ui/CardWidget.h"

CardWidget::CardWidget(wxWindow* parent, Card* c)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(-1, 70)), card(c)
{   
    SetBackgroundColour(wxColour(50,50,50));
    selected = false;
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // Title
    titleText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(card->getName()));

    wxFont titleFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    titleText->SetFont(titleFont);
    titleText->SetForegroundColour(*wxWHITE);

    // Stats
    std::string stats;
    if (card->getType() == Card::Type::ENTITY) {
        EntityCard* e = dynamic_cast<EntityCard*>(card);
        stats = std::format("     💵 {}\n✊ {} ❤️ {}",
            e->getCost(), e->getAttack(), e->getHealth()
        );
    } else if (card->getType() == Card::Type::INSTANT) {
        InstantCard* e = dynamic_cast<InstantCard*>(card);
        stats = std::format("💵 {}", card->getCost());
    }
    statsText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(stats));

    wxFont statsFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    statsText->SetFont(statsFont);
    statsText->SetForegroundColour(wxColour(200,200,200));

    // Description
    descriptionText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(card->getDescription()), wxDefaultPosition, wxSize(150, -1), wxALIGN_CENTER
    );
    wxFont descFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    descriptionText->Wrap(150);
    descriptionText->SetFont(descFont);
    descriptionText->SetForegroundColour(wxColour(180,180,180));

    // Add to sizer
    vbox->Add(titleText, 0, wxALIGN_CENTER | wxBOTTOM, 2);
    vbox->Add(statsText, 0, wxALIGN_CENTER | wxBOTTOM, 2);
    vbox->Add(descriptionText, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 5);

    SetSizer(vbox);

    // FOrward clicks from all children to the cardWidget
    auto forwardClick = [this](wxMouseEvent& evt) {
        wxMouseEvent e(evt);
        e.SetEventObject(this); 
        wxPostEvent(this, e); 
    };

    for (auto child : GetChildren()) {
        child->Bind(wxEVT_LEFT_DOWN, forwardClick);
    }
}

void CardWidget::setSelected(bool t) {
    selected = t;

    if (selected)
        SetBackgroundColour(wxColour(70, 90, 160)); // blue highlight
    else
        SetBackgroundColour(wxColour(50,50,50));

    Refresh();
}
