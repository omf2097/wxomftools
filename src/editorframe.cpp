#include "editorframe.h"

#include <wx/filedlg.h>
#include <wx/aboutdlg.h>

EditorFrame::EditorFrame(wxFrame *frame) : BaseFrame(frame) {
    // Load handlers
    wxImage::AddHandler(new wxPNGHandler);
    
    this->updateTitle();
}

EditorFrame::~EditorFrame() {

}

void EditorFrame::updateTitle() {
    wxString title(_("wxBKEditor - "));
    if(fname.length() > 128) {
        title.append(fname.SubString(0, 48));
        title.append(_(" ... "));
        title.append(fname.SubString(fname.length()-48, 48));
    } else {
        title.append(fname);
    }
    this->SetTitle(title);
}

void EditorFrame::onMenuExit(wxCommandEvent& event) {
    Destroy();
}

void EditorFrame::onMenuAbout(wxCommandEvent &event) {
    wxAboutDialogInfo info;
    info.SetName(_("wxBKEditor"));
    info.SetVersion(_("0.1 Alpha"));
    info.SetDescription(_("One Must Fall 2097 BK file editor"));
    info.SetCopyright(_T("(C) 2013 Tuomas Virtanen <katajakasa@gmail.com>"));
    info.SetWebSite(_("https://github.com/omf2097/wxBKEditor"));
    wxAboutBox(info);
}