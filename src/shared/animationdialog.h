#ifndef _ANIMATIONDIALOG_H
#define _ANIMATIONDIALOG_H

#include <shadowdive/shadowdive.h>
#include "shared.h"
#include "stringtreedataitem.h"

class AnimationDialog : public AnimationBaseDialog {
protected:
    sd_bk_anim *m_animation;
    sd_bk_anim m_tmp_anim;

public:
    AnimationDialog(wxWindow *parent, sd_bk_anim *animation);
    ~AnimationDialog();

    void onStringSelected(wxTreeEvent& event);
    void onStringFrameSelected(wxTreeEvent& event);

    void find_frames(StringType type, int number);
    wxString getStringByType(StringType type, int number);

    void load_strings();
    void save();
};

#endif // _ANIMATIONDIALOG_H
