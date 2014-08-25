#include "spriteimportdialog.h"
#include <wx/dialog.h>
#include <wx/msgdlg.h>

SpriteImportDialog::SpriteImportDialog(wxWindow *parent, sd_sprite *sprite, sd_palette *pal) : SpriteImportBaseDialog(parent) {
    m_sprite = sprite;
    m_pal = pal;
    m_transparent_index = -1;
    m_hasfile = 0;
    sd_vga_image_create(&m_img, 320, 200);
}

SpriteImportDialog::~SpriteImportDialog() {
    sd_vga_image_free(&m_img);
}

void SpriteImportDialog::save() {
    if(m_sprite == NULL || m_pal == NULL)
        return;

    sd_vga_image_stencil_index(&m_img, m_transparent_index);
    sd_sprite_vga_encode(m_sprite, &m_img);
}

void SpriteImportDialog::onFileChange(wxFileDirPickerEvent& event) {
    m_hasfile = 1;

    // Attempt to load
    sd_vga_image_free(&m_img);
    int ret = sd_vga_image_from_png(&m_img, (char*)event.GetPath().mb_str().data());
    if(ret != SD_SUCCESS) {
        sd_vga_image_create(&m_img, 320, 200);
        wxMessageDialog md(
            this, 
            wxString::Format("Error while attempting to load image. Make sure the image is a 8bit paletted PNG file smaller than 320x200 pixels."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }

    updateImage();
}

void SpriteImportDialog::onIndexChange(wxCommandEvent& event) {
    long value;
    if(!transparency_field->GetValue().ToLong(&value)) {
        value = -1;
    }
    m_transparent_index = value;
}

void SpriteImportDialog::onPreviewClick(wxCommandEvent& event) {
    if(!m_hasfile || m_pal == NULL)
        return;
    updateImage();
}

wxImage SpriteImportDialog::RGBAtoNative(sd_rgba_image *src) {
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

void SpriteImportDialog::updateImage() {
    if(m_pal == NULL)
        return;

    sd_rgba_image img;
    sd_vga_image_stencil_index(&m_img, m_transparent_index);
    sd_vga_image_decode(&img, &m_img, m_pal, -1);
    wxImage bgImg = RGBAtoNative(&img).Scale(320, 200);
    this->sprite_image->SetBitmap(wxBitmap(bgImg));
    sd_rgba_image_free(&img);
}
