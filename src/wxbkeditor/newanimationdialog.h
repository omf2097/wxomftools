#ifndef _NEWANIMATIONDIALOG_H
#define _NEWANIMATIONDIALOG_H

#include "shared.h"
#include "gui.h"
#include <shadowdive/shadowdive.h>

class NewAnimationDialog : public NewAnimationBaseDialog {
public:
    NewAnimationDialog(wxWindow *parent);
    ~NewAnimationDialog();
    int getIndex();
};

#endif // _NEWANIMATIONDIALOG_H
