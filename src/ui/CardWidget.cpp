#include "ui/CardWidget.h"

CardWidget::CardWidget(wxWindow* parent, Card* c)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(-1, 70)), card(c)
{   
    std::cout << "INIT1 " << std::endl;
    SetBackgroundColour(wxColour(50,50,50));
    selected = false;
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // ---- Title ----
    titleText = new wxStaticText(this, wxID_ANY,
        wxString::FromUTF8(card->getName())
    );

    wxFont titleFont(11, wxFONTFAMILY_DEFAULT,
                     wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    titleText->SetFont(titleFont);
    titleText->SetForegroundColour(*wxWHITE);
    // ---- Stats ----
    std::string stats;
    std::cout << "! " << std::endl;
    if (card->getType() == Card::Type::ENTITY) {
        std::cout << "ENTIT" << std::endl;
        EntityCard* e = dynamic_cast<EntityCard*>(card);
        std::cout << "a" << std::endl;
        stats = std::format("❤️ {}   ✊ {}   💵 {}",
            e->getHealth(),
            e->getAttack(),
            e->getCost()
        );
    } else if (card->getType() == Card::Type::INSTANT) {
        std::cout << "INSTANT" << std::endl;
        InstantCard* e = dynamic_cast<InstantCard*>(card);
        std::cout << "a" << std::endl;
        stats = std::format("💵 {}", card->getCost());
    }
    std::cout << "? " << std::endl;
    statsText = new wxStaticText(this, wxID_ANY, stats);

    wxFont statsFont(9, wxFONTFAMILY_DEFAULT,
                     wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    statsText->SetFont(statsFont);
    statsText->SetForegroundColour(wxColour(200,200,200));

    vbox->Add(titleText, 0, wxALIGN_CENTER | wxBOTTOM, 2);
    vbox->Add(statsText, 0, wxALIGN_CENTER);

    SetSizer(vbox);
    std::cout << "COMPLETED INIT " << std::endl;
}

void CardWidget::setSelected(bool t) {
    selected = t;

    if (selected)
        SetBackgroundColour(wxColour(70, 90, 160)); // blue highlight
    else
        SetBackgroundColour(wxColour(50,50,50));

    Refresh();
}
