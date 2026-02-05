// Wx widget colours
#include "ui/wxCustomColours.h"


wxCustomColours::wxCustomColours() {
    // Initialize all the colours
    strToColour["defaultbg"] = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE);
    strToColour["defaultfg"] = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT);
    strToColour["purple"] = wxColour(120, 80, 160);
    strToColour["blue"]   = wxColour(70, 120, 200);
    strToColour["red"]    = wxColour(200, 70, 70);
    strToColour["white"]  = wxColour(230, 230, 230);
    strToColour["black"]  = wxColour(30, 30, 30);
    strToColour["green"]  = wxColour(70, 160, 90);
    strToColour["yellow"] = wxColour(220, 200, 80);

}
wxCustomColours::~wxCustomColours() {}

wxColour wxCustomColours::query(const std::string& s) const{
    // turn to all lowercase
    std::string cleaned = std::string();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cleaned += s[i] + 32;
        } else if (s[i] < 'a' || s[i] > 'z') {
            // invalid char, like . or space
            return strToColour.at("defaultbg");
        } else {
            cleaned += s[i];
        }
    }
    if (!strToColour.count(cleaned)) return strToColour.at("defaultbg");;
    return strToColour.at(cleaned);
}
    
