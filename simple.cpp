#include "simple.h"
#include "control_id.h"

Simple::Simple(const wxString& title): 
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(320, 240)),
number(0) {
    wxIcon icon(wxT("icon-32.ico"), wxBITMAP_TYPE_ICO);

    if (!icon.IsOk()) {
        wxLogError(wxT("Fuck it's error loading icon."));
    } else {
        SetIcon(icon);
    }

    // Add Panel
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    // Add Button
    wxButton *button = new wxButton(panel, wxID_EXIT, wxT("&Quit"), wxPoint(20, 20));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Simple::OnQuit));

    button->SetFocus();

    // Add plus button
    wxButton *btnAdd = new wxButton(panel, ID_PLUS, wxT("+"), wxPoint(20, 60));
    Connect(ID_PLUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Simple::OnBtnPressed));

    wxButton *btnSub = new wxButton(panel, ID_MINUS, wxT("-"), wxPoint(20, 90));
    Connect(ID_MINUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Simple::OnBtnPressed));

    lblNumber = new wxStaticText(panel, wxID_ANY, wxString::Format(wxT("Number: %d"), number), wxPoint(180, 90));
    
    Center();
}

void Simple::OnQuit(wxCommandEvent & WXUNUSED(event) ) {
    Close(true);
}

void Simple::OnBtnPressed(wxCommandEvent & event ) {
    switch (event.GetId())
    {
    case ID_PLUS:
        number++;
        break;

    case ID_MINUS:
        number--;
        break;
    
    default:
        break;
    }

    // wxLogWarning(wxString::Format(wxT("Number is now %d"), number));

    lblNumber->SetLabelText(wxString::Format(wxT("Number: %d"), number));
}