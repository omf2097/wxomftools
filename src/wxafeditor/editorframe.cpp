#include <cstdio>

#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>

#include "license.h"
#include "editorframe.h"
#include "animationtreedataitem.h"

EditorFrame::EditorFrame(wxFrame *frame) : AFBaseFrame(frame) {
    // Initialize
    m_filedata = NULL;
    reset();

    // Disable stuff by default
    this->menuitem_save->Enable(false);
    this->menuitem_saveas->Enable(false);
    
    // Load wx image handlers
    wxImage::AddHandler(new wxPNGHandler);
}

EditorFrame::~EditorFrame() {
    if(m_filedata != NULL) {
        sd_af_delete(m_filedata);
    }
}

void EditorFrame::reset() {
    if(m_filedata != NULL) {
        sd_af_delete(m_filedata);
        m_filedata = NULL;
    }
    m_filename = "";
    updateTitle();
    m_filedata = sd_af_create();
}

void EditorFrame::updateTitle() {
    wxString title(_("wxAFEditor"));
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
    info.SetName(_("wxAFEditor"));
    info.SetVersion(_("0.1"));
    info.SetDescription(_("One Must Fall 2097 AF file editor"));
    info.SetCopyright(_T("(C) 2013 Tuomas Virtanen <katajakasa@gmail.com>"));
    info.SetWebSite(_("https://github.com/omf2097/wxomftools"));
    info.SetLicense(_(mit_license));
    wxAboutBox(info);
}