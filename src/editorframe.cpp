#include "editorframe.h"

#include <wx/filedlg.h>
#include <wx/aboutdlg.h>

EditorFrame::EditorFrame(wxFrame *frame) : BaseFrame(frame) {
    // Initialize
    m_filedata = NULL;
    reset();

    // Load wx image handlers
    wxImage::AddHandler(new wxPNGHandler);
}

EditorFrame::~EditorFrame() {
    if(m_filedata != NULL) {
        sd_bk_delete(m_filedata);
    }
}

void EditorFrame::reset() {
    m_filename = "";
    if(m_filedata != NULL) {
        sd_bk_delete(m_filedata);
        m_filedata = NULL;
    }
    updateTitle();
    m_filedata = sd_bk_create();
}

void EditorFrame::updateTitle() {
    wxString title(_("wxBKEditor"));
    if(m_filename.length() > 128) {
        title.append(" - ");
        title.append(m_filename.SubString(0, 48));
        title.append(_(" ... "));
        title.append(m_filename.SubString(m_filename.length()-48, 48));
    } else if(m_filename.length() > 0) {
        title.append(" - ");
        title.append(m_filename);
    }
    SetTitle(title);
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