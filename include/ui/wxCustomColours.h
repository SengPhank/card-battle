// Wx widget colours
#include <string>
#include <unordered_map>
#include <wx/wx.h>

class wxCustomColours {
private:
    /* data */
public:
    wxCustomColours();
    ~wxCustomColours();
    wxColour query(const std::string& s) const;
    std::unordered_map<std::string, wxColour> strToColour;
    
};
