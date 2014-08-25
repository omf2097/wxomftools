#ifndef _SPRITEDIALOG_H
#define _SPRITEDIALOG_H

#include "shared.h"
#include <shadowdive/shadowdive.h>

class SpriteDialog : public SpriteBaseDialog {
protected:
    sd_sprite *m_sprite;
    sd_palette *m_pal;
    sd_sprite tmp_sprite;

    void onImportButton(wxCommandEvent& event);
    void onExportButton(wxCommandEvent& event);

    void updateImage();
    wxImage RGBAtoNative(sd_rgba_image *src);

public:
    SpriteDialog(wxWindow *parent, sd_sprite *sprite, sd_palette *pal);
    ~SpriteDialog();

    void save();
};

#endif // _SPRITEDIALOG_H
