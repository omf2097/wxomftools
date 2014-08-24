#ifndef _EDITORFRAME_H
#define _EDITORFRAME_H

#include <shadowdive/shadowdive.h>
#include "gui.h"
#include "animationdialog.h"
#include "spritedialog.h"

class EditorFrame : public BKBaseFrame {
protected:
    sd_bk_file *m_filedata;
    wxString m_filename;
    wxTreeItemId m_last_treeindex;

    int m_pal;
    int m_remap;
    
    // From parent
    virtual void onMenuExit(wxCommandEvent& event);
    virtual void onMenuAbout(wxCommandEvent& event);
    virtual void onMenuOpen(wxCommandEvent& event);
    virtual void onMenuNew(wxCommandEvent& event);
    virtual void onBackgroundSave(wxCommandEvent& event);
    virtual void onPaletteChoice(wxCommandEvent& event);
	virtual void onRemapChoice(wxCommandEvent& event);
    virtual void onPaletteLoad(wxCommandEvent& event);
    virtual void onPaletteSave(wxCommandEvent& event);
    virtual void onNewPalette(wxCommandEvent& event);
    virtual void onChangePaletteColor(wxMouseEvent& event);
    virtual void onAnimTreeContextMenu(wxTreeEvent& event);
    virtual void onAnimTreeItemSelect(wxTreeEvent& event);
    virtual void onMenuSave(wxCommandEvent& event);
    virtual void onMenuSaveAs(wxCommandEvent& event);
    virtual void onAnimationEdit(wxCommandEvent& event);
    virtual void onAnimationDelete(wxCommandEvent& event);
    void onSoundChange(wxGridEvent& event);
    
    // Local
    virtual void onAnimItemEdit(wxCommandEvent& event);
    virtual void onAnimItemDelete(wxCommandEvent& event);
    
public:
    EditorFrame(wxFrame *frame);
    ~EditorFrame();
    
    void convertRGBAtoRGB(char *dst, char *src, int size);
    wxImage RGBAtoNative(sd_rgba_image *src);
    
    void updateTitle();
    void reset();
    void refreshFields();
    void showSelectedPalette();

    void cbAnimEditFunc(wxTreeItemId id);
    void cbAnimDeleteFunc(wxTreeItemId id);
    void updateAnimationViews();
    void showAnimationTreeInfo(wxTreeItemId id);
    void updateBgImage();
    void loadPreviewSprite(sd_sprite *ani);
    void clearPreview();
};

#endif // _EDITORFRAME_H
