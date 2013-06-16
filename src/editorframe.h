#ifndef _EDITORFRAME_H
#define _EDITORFRAME_H

#include "gui.h"

class EditorFrame: public BaseFrame {
protected:
    wxString fname;

    virtual void onMenuExit(wxCommandEvent& event);
    virtual void onMenuAbout(wxCommandEvent& event);
    
public:
    EditorFrame(wxFrame *frame);
    ~EditorFrame();
    
    void updateTitle();
};

#endif // _EDITORFRAME_H
