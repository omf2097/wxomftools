#ifndef _SPRITEIMPORTDIALOG_H
#define _SPRITEIMPORTDIALOG_H

#include "shared.h"
#include <shadowdive/shadowdive.h>

class SpriteImportDialog : public SpriteImportBaseDialog {
protected:
    sd_sprite *m_sprite;
    sd_palette *m_pal;
    sd_vga_image m_img;
    int m_transparent_index;
    int m_hasfile;

    void onFileChange(wxFileDirPickerEvent& event);
    void onIndexChange(wxCommandEvent& event);
    void onPreviewClick(wxCommandEvent& event);

    void updateImage();
    wxImage RGBAtoNative(sd_rgba_image *src);

public:
    SpriteImportDialog(wxWindow *parent, sd_sprite *sprite, sd_palette *pal);
    ~SpriteImportDialog();

    void save();
};

#endif // _SPRITEIMPORTDIALOG_H
