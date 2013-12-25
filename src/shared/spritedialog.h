#ifndef _SPRITEDIALOG_H
#define _SPRITEDIALOG_H

#include "shared.h"
#include <shadowdive/shadowdive.h>

class SpriteDialog : public SpriteBaseDialog {
protected:
    sd_sprite *m_sprite;

public:
    SpriteDialog(wxWindow *parent, sd_sprite *sprite);
    ~SpriteDialog();

    void save();
};

#endif // _SPRITEDIALOG_H