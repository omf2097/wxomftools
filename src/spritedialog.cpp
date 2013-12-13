#include "spritedialog.h"
#include <wx/dialog.h>

SpriteDialog::SpriteDialog(wxFrame *parent, sd_sprite *sprite) : SpriteBaseDialog(parent) {
    m_sprite = sprite;

}

SpriteDialog::~SpriteDialog() {

}

void SpriteDialog::save() {

}