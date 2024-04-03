#include <wx/wx.h>
#include <iostream>

class App : public wxApp {
public:
    bool OnInit() {
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "MLC media player", wxDefaultPosition, wxSize(1280, 720));
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        wxStaticText* text = new wxStaticText(window, wxID_ANY, "Test Message",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

        wxButton* button = new wxButton(window, wxID_ANY, "Test Button", 
            wxPoint(100, 100), wxSize(100, 100));

        text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        sizer->Add(button, 1, wxALIGN_CENTER);
        window->SetSizer(sizer);
        window->Show();
        return true;
    }

    void printHelloWorld() {
        std::cout << "Hello World!";
    }
};

wxIMPLEMENT_APP(App);