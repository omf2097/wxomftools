#include "spritedialog.h"
#include "spriteimportdialog.h"
#include "helpers.h"
#include <wx/dialog.h>
#include <wx/msgdlg.h>
#include <shadowdive/shadowdive.h>

SpriteDialog::SpriteDialog(wxWindow *parent, sd_sprite *sprite, sd_palette *pal) : SpriteBaseDialog(parent) {
    m_sprite = sprite;
    sd_sprite_copy(&tmp_sprite, m_sprite);
    m_pal = pal;
    updateImage();

    _cs(pos_x_field, tmp_sprite.pos_x);
    _cs(pos_y_field, tmp_sprite.pos_y);
    _cs(index_field, tmp_sprite.index);
    _cs(missing_field, tmp_sprite.missing);
}

SpriteDialog::~SpriteDialog() {
    sd_sprite_free(&tmp_sprite);
}

void SpriteDialog::save() {
    _cti16(pos_x_field, &tmp_sprite.pos_x);
    _cti16(pos_y_field, &tmp_sprite.pos_y);
    _ct8(index_field, &tmp_sprite.index);
    _ctb(missing_field, &tmp_sprite.missing);

    sd_sprite_free(m_sprite);
    sd_sprite_copy(m_sprite, &tmp_sprite);
}

void SpriteDialog::onImportButton(wxCommandEvent& event) {
    if(m_pal == NULL)
        return;

    SpriteImportDialog sid(this, &tmp_sprite, m_pal);
    if(sid.ShowModal() == wxID_OK) {
        sid.save();
        updateImage();
    }
}

void SpriteDialog::onExportButton(wxCommandEvent& event) {
    if(m_pal == NULL)
        return;

    wxFileDialog sd(this, 
        _("PNG (Portable Network Graphics)"), 
        _(""),
        _(""), 
        _("PNG files (*.png)|*.png"), 
        wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if(sd.ShowModal() != wxID_OK) {
        return;
    }

    // Decode and save
    sd_vga_image img;
    sd_sprite_vga_decode(&img, &tmp_sprite);
    if(sd_vga_image_to_png(&img, m_pal, (char*)sd.GetPath().mb_str().data()) != SD_SUCCESS) {
        wxMessageDialog md(
            this, 
            _("Error while exporting the sprite."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
    }
    sd_vga_image_free(&img);
}

wxImage SpriteDialog::RGBAtoNative(sd_rgba_image *src) {
    char *idata = (char*)malloc(src->w * src->h * 3);
    char *adata = (char*)malloc(src->w * src->h);

    for(unsigned int i = 0; i < src->w * src->h; i++) {
        idata[(i*3) + 0] = src->data[(i*4) + 0];
        idata[(i*3) + 1] = src->data[(i*4) + 1];
        idata[(i*3) + 2] = src->data[(i*4) + 2];
        adata[i] = src->data[(i*4) + 3];
    }

    return wxImage(src->w, src->h, (unsigned char*)idata, (unsigned char*)adata, false);
}

void SpriteDialog::updateImage() {
    if(m_pal == NULL)
        return;

    sd_rgba_image img;
    sd_sprite_rgba_decode(&img, &tmp_sprite, m_pal, -1);
    wxImage bgImg = RGBAtoNative(&img).Scale(640, 400);
    this->sprite_image->SetBitmap(wxBitmap(bgImg));
    sd_rgba_image_free(&img);
}
