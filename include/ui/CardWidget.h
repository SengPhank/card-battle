#pragma once
#include "cards/Card.h"
#include "cards/EntityCard.h"
#include "cards/InstantCard.h"
#include <string>
#include <format>
#include <wx/wx.h>
#include <iostream>

class CardWidget : public wxPanel {
private:
    Card* card;

    wxStaticText* titleText;
    wxStaticText* statsText;

    bool selected = false;

public:
    CardWidget(wxWindow* parent, Card* card);

    Card* getCard() const { return card; }
    void setSelected(bool t);


};
