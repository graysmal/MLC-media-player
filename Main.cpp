#include <wx/wx.h>
#include <iostream>

namespace MenuIds {
    const int open = 100;
}

class MyFrame : public wxFrame {
public:

    // MAINFRAME ELEMENT INITIALIZATION
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size) {
        wxBoxSizer* app_sizer = new wxBoxSizer(wxVERTICAL);

        // MENU BAR
        wxMenuBar* menu_bar = new wxMenuBar(wxHORIZONTAL);
        /// FILE
        wxMenu* file_menu = new wxMenu();
        file_menu->Append(MenuIds::open, "open");
        menu_bar->Append(file_menu, "file");

        /// EDIT
        wxMenu* edit_menu = new wxMenu();
        edit_menu->Append(wxID_ANY, "preferences");
        menu_bar->Append(edit_menu, "edit");

        wxPanel* preview_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
        preview_panel->SetMinSize(wxSize(200, 200));
        wxBoxSizer* preview_sizer = new wxBoxSizer(wxVERTICAL);
        preview_panel->SetSizer(preview_sizer);
        preview_sizer->AddStretchSpacer();
        preview_panel->SetBackgroundColour("black");


        wxPanel* playback_tools_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
        wxBoxSizer* playback_tools_sizer = new wxBoxSizer(wxHORIZONTAL);
        wxButton* play_button = new wxButton(playback_tools_panel, wxID_ANY, "play", wxDefaultPosition, wxDefaultSize);
        wxButton* stop_button = new wxButton(playback_tools_panel, wxID_ANY, "stop", wxDefaultPosition, wxDefaultSize);

        playback_tools_panel->SetSizer(playback_tools_sizer);
        playback_tools_sizer->Add(play_button, 0);
        playback_tools_sizer->Add(stop_button, 0);

        app_sizer->Add(preview_panel, 1, wxEXPAND | wxALL, 5);
        app_sizer->Add(playback_tools_panel, 0, wxEXPAND | wxALL, 5);

        this->SetMenuBar(menu_bar);
        this->SetSizer(app_sizer);
    }

private:

    void OnOpen(wxCommandEvent& event) {
        AllocConsole();
        freopen("conin$", "r", stdin);
        freopen("conout$", "w", stdout);
        freopen("conout$", "w", stdout);
        std::cout << "pressed!";

        wxString file_path = wxFileSelector("please select a media item");
        std::cout << file_path;
    }

    wxDECLARE_EVENT_TABLE();
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(MenuIds::open, MyFrame::OnOpen)
wxEND_EVENT_TABLE();

// EXE APP
class App : public wxApp {
public:
    bool OnInit() {
        MyFrame* frame = new MyFrame("MLC media player", wxDefaultPosition, wxSize(1280, 720));
        frame->Show(true);
        return true;
    }
};




wxIMPLEMENT_APP(App);