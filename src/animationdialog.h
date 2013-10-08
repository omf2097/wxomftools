#ifndef _ANIMATIONDIALOG_H
#define _ANIMATIONDIALOG_H

#include "gui.h"
#include <shadowdive/shadowdive.h>

class AnimationDialog : public AnimationBaseDialog {
protected:
public:
    AnimationDialog(wxFrame *parent);
    ~AnimationDialog();
};

#endif // _ANIMATIONDIALOG_H
