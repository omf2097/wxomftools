#ifndef _SPRITEDIALOG_H
#define _SPRITEDIALOG_H

#include "gui.h"
#include <shadowdive/shadowdive.h>

class SpriteDialog : public SpriteBaseDialog {
protected:
    sd_sprite *m_sprite;

public:
    SpriteDialog(wxFrame *parent, sd_sprite *sprite);
    ~SpriteDialog();

    void save();
};

#endif // _SPRITEDIALOG_H
