#ifndef _EDITORFRAME_H
#define _EDITORFRAME_H

#include "gui.h"
#include <shadowdive/shadowdive.h>

class EditorFrame: public BaseFrame {
protected:
    sd_bk_file *m_filedata;
    wxString m_filename;

    virtual void onMenuExit(wxCommandEvent& event);
    virtual void onMenuAbout(wxCommandEvent& event);
    virtual void onMenuOpen(wxCommandEvent& event);
    
public:
    EditorFrame(wxFrame *frame);
    ~EditorFrame();
    
    void updateTitle();
    void reset();
    void refreshFields();
};

#endif // _EDITORFRAME_H
