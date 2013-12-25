#ifndef _ANIMATIONDIALOG_H
#define _ANIMATIONDIALOG_H

#include "gui.h"
#include <shadowdive/shadowdive.h>

class AnimationDialog : public AnimationBaseDialog {
protected:
    sd_bk_anim *m_animation;

public:
    AnimationDialog(wxFrame *parent, sd_bk_anim *animation);
    ~AnimationDialog();

    void save();
};

#endif // _ANIMATIONDIALOG_H
