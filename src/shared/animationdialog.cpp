#include "animationdialog.h"
#include <wx/dialog.h>
#include "helpers.h"

AnimationDialog::AnimationDialog(wxWindow *parent, sd_bk_anim *animation) : AnimationBaseDialog(parent) {
    m_animation = animation;
    sd_bk_anim_copy(&m_tmp_anim, m_animation);

    _cs(chain_if_hit_field, m_tmp_anim.chain_hit);
    _cs(chain_if_not_hit_field, m_tmp_anim.chain_no_hit);
    _cs(load_on_start_field, m_tmp_anim.load_on_start);
    _cs(probability_field, m_tmp_anim.probability);
    _cs(hazard_damage_field, m_tmp_anim.hazard_damage);
    _cs(start_x_field, m_tmp_anim.animation->start_x);
    _cs(start_y_field, m_tmp_anim.animation->start_y);

    anim_string_field->SetValue(wxString(animation->animation->anim_string));
}

AnimationDialog::~AnimationDialog() {
    sd_bk_anim_free(&m_tmp_anim);
}

void AnimationDialog::save() {
    _ct8(chain_if_hit_field, &m_tmp_anim.chain_hit);
    _ct8(chain_if_not_hit_field, &m_tmp_anim.chain_no_hit);
    _ct8(load_on_start_field, &m_tmp_anim.load_on_start);
    _ct16(probability_field, &m_tmp_anim.probability);
    _ct8(hazard_damage_field, &m_tmp_anim.hazard_damage);
    _cti16(start_x_field, &m_tmp_anim.animation->start_x);
    _cti16(start_y_field, &m_tmp_anim.animation->start_y);
    sd_animation_set_anim_string(m_tmp_anim.animation, anim_string_field->GetValue().c_str());

    sd_bk_anim_free(m_animation);
    sd_bk_anim_copy(m_animation, &m_tmp_anim);
}
