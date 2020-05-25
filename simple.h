#ifndef _SIMPLE_HPP_
#define _SIMPLE_HPP_

#include <wx/wx.h>

class Simple : public wxFrame {
public:
    Simple(const wxString&);

    void OnQuit(wxCommandEvent &event);
    void OnBtnPressed(wxCommandEvent &event);

private:
    wxStaticText *lblNumber;
    int number;
};

#endif
