#ifndef _EDITORFRAME_H
#define _EDITORFRAME_H

#include "gui.h"
#include "animationdialog.h"
#include <shadowdive/shadowdive.h>

class EditorFrame: public BaseFrame {
protected:
    sd_bk_file *m_filedata;
    wxString m_filename;
    
    int m_pal;
    int m_remap;
    
    // From parent
    virtual void onMenuExit(wxCommandEvent& event);
    virtual void onMenuAbout(wxCommandEvent& event);
    virtual void onMenuOpen(wxCommandEvent& event);
    virtual void onBackgroundSave(wxCommandEvent& event);
    virtual void onPaletteChoice(wxCommandEvent& event);
	virtual void onRemapChoice(wxCommandEvent& event);
    virtual void onPaletteLoad(wxCommandEvent& event);
    virtual void onPaletteSave(wxCommandEvent& event);
    virtual void onAnimTreeContextMenu(wxTreeEvent& event);
    virtual void onAnimTreeItemSelect(wxTreeEvent& event);
    virtual void onMenuSave(wxCommandEvent& event);
    virtual void onMenuSaveAs(wxCommandEvent& event);
    
    // Local
    virtual void onAnimItemEdit(wxCommandEvent& event);
    
public:
    EditorFrame(wxFrame *frame);
    ~EditorFrame();
    
    void convertRGBAtoRGB(char *dst, char *src, int size);
    wxImage RGBAtoNative(sd_rgba_image *src);
    
    void updateTitle();
    void reset();
    void refreshFields();
    void showSelectedPalette();
};

#endif // _EDITORFRAME_H
