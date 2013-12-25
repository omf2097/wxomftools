#ifndef _EDITORFRAME_H
#define _EDITORFRAME_H

#include <shadowdive/shadowdive.h>
#include "gui.h"
#include "animationdialog.h"
#include "spritedialog.h"

class EditorFrame : public AFBaseFrame {
protected:
    sd_af_file *m_filedata;
    wxString m_filename;
    
    void reset();
    void updateTitle();

    // From parent
    virtual void onMenuExit(wxCommandEvent& event);
    virtual void onMenuAbout(wxCommandEvent& event);

public:
    EditorFrame(wxFrame *frame);
    ~EditorFrame();
};

#endif // _EDITORFRAME_H
