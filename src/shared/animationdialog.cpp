#include "animationdialog.h"
#include <wx/dialog.h>

void _cs(wxTextCtrl *ctrl, int num) {
    wxString v = wxString::Format("%d", num);
    ctrl->SetValue(v);
}

void _ct8(wxTextCtrl *ctrl, uint8_t *num) {
    long v;
    if(!ctrl->GetValue().ToLong(&v)) {
        return;
    }
    if(v < 0) v = 0;
    if(v > 0xFF) v = 0xFF;
    *num = v;
}

void _ct16(wxTextCtrl *ctrl, uint16_t *num) {
    long v;
    if(!ctrl->GetValue().ToLong(&v)) {
        return;
    }
    if(v < 0) v = 0;
    if(v > 0xFFFF) v = 0xFFFF;
    *num = v;
}

void _cti16(wxTextCtrl *ctrl, int16_t *num) {
    long v;
    if(!ctrl->GetValue().ToLong(&v)) {
        return;
    }
    if(v < -0x7FFF) v = -0x7FFF;
    if(v > 0x7FFF) v = 0x7FFF;
    *num = v;
}

AnimationDialog::AnimationDialog(wxWindow *parent, sd_bk_anim *animation) : AnimationBaseDialog(parent) {
    m_animation = animation;

    _cs(chain_if_hit_field, m_animation->chain_hit);
    _cs(chain_if_not_hit_field, m_animation->chain_no_hit);
    _cs(load_on_start_field, m_animation->load_on_start);
    _cs(probability_field, m_animation->probability);
    _cs(hazard_damage_field, m_animation->hazard_damage);
    _cs(start_x_field, m_animation->animation->start_x);
    _cs(start_y_field, m_animation->animation->start_y);

    anim_string_field->SetValue(wxString(animation->animation->anim_string));
}

AnimationDialog::~AnimationDialog() {

}

void AnimationDialog::save() {
    _ct8(chain_if_hit_field, &m_animation->chain_hit);
    _ct8(chain_if_not_hit_field, &m_animation->chain_no_hit);
    _ct8(load_on_start_field, &m_animation->load_on_start);
    _ct16(probability_field, &m_animation->probability);
    _ct8(hazard_damage_field, &m_animation->hazard_damage);
    _cti16(start_x_field, &m_animation->animation->start_x);
    _cti16(start_y_field, &m_animation->animation->start_y);
    sd_animation_set_anim_string(m_animation->animation, anim_string_field->GetValue().c_str());
}
