#include <wx/wx.h>
#include <iostream>

class App : public wxApp {
public:
    bool OnInit() {
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "MLC media player", wxDefaultPosition, wxSize(1280, 720));
        wxBoxSizer* app_sizer = new wxBoxSizer(wxVERTICAL);
        
        // MENU BAR
        wxMenuBar* menu_bar = new wxMenuBar(wxHORIZONTAL);

        /// FILE
        wxMenu* file_menu = new wxMenu();
        file_menu->Append(wxID_ANY, "open");
        menu_bar->Append(file_menu, "file");

        /// EDIT
        wxMenu* edit_menu = new wxMenu();
        edit_menu->Append(wxID_ANY, "preferences");
        menu_bar->Append(edit_menu, "edit");

        wxPanel* preview_panel = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxDefaultSize);
        preview_panel->SetMinSize(wxSize(200, 200));
        wxBoxSizer* preview_sizer = new wxBoxSizer(wxVERTICAL);
        preview_panel->SetSizer(preview_sizer);
        preview_sizer->AddStretchSpacer();
        preview_panel->SetBackgroundColour("black");


        wxPanel* playback_tools_panel = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxDefaultSize);
        wxBoxSizer* playback_tools_sizer = new wxBoxSizer(wxHORIZONTAL);
        wxButton* play_button = new wxButton(playback_tools_panel, wxID_ANY, "play", wxDefaultPosition, wxDefaultSize);
        wxButton* stop_button = new wxButton(playback_tools_panel, wxID_ANY, "stop", wxDefaultPosition, wxDefaultSize);

        playback_tools_panel->SetSizer(playback_tools_sizer);
        playback_tools_sizer->Add(play_button, 0);
        playback_tools_sizer->Add(stop_button, 0);

        app_sizer->Add(preview_panel, 1, wxEXPAND | wxALL, 5);
        app_sizer->Add(playback_tools_panel, 0, wxALIGN_BOTTOM | wxALL, 5);
        
        window->SetMenuBar(menu_bar);
        window->SetSizer(app_sizer);
        window->Show();
        return true;
    }





    void printHelloWorld() {
        std::cout << "Hello World!";
    }

    //wxStaticText* text = new wxStaticText(window, wxID_ANY, "Test Message",
        //    wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        //text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
};

wxIMPLEMENT_APP(App);