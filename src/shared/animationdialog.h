#ifndef _ANIMATIONDIALOG_H
#define _ANIMATIONDIALOG_H

#include <shadowdive/shadowdive.h>
#include "shared.h"
#include "stringtreedataitem.h"

class AnimationDialog : public AnimationBaseDialog {
protected:
    sd_bk_anim *m_animation;
    sd_bk_anim m_tmp_anim;
    sd_script *m_script;
    StringType m_loaded_type;
    int m_loaded_extra;
    int m_selected_frame;

public:
    AnimationDialog(wxWindow *parent, sd_bk_anim *animation);
    ~AnimationDialog();

    void onStringSelected(wxTreeEvent& event);
    void onStringFrameSelected(wxTreeEvent& event);
    void onStringTagChange(wxGridEvent& event);
    void onFrameSpriteChanged(wxCommandEvent& event);
    void onFrameDurationChanged(wxCommandEvent& event);

    void find_frames(StringType type, int number);
    wxString getStringByType(StringType type, int number);
    void saveCurrentScript();

    void load_strings();
    void save();
};

#endif // _ANIMATIONDIALOG_H
