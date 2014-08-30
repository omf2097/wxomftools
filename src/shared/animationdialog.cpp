#include <wx/dialog.h>
#include <wx/msgdlg.h>
#include <shadowdive/shadowdive.h>
#include "animationdialog.h"
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

    load_strings();

    anim_string_field->SetValue(wxString(animation->animation->anim_string));
}

AnimationDialog::~AnimationDialog() {
    sd_bk_anim_free(&m_tmp_anim);
}

void AnimationDialog::load_strings() {
    // Load up animations
    string_tree->DeleteAllItems();
    wxTreeItemData *root_data = new StringTreeDataItem(NONE_STRING, 0);
    wxTreeItemId root_index = string_tree->AddRoot(_("Strings"), -1, -1, root_data);

    // Animation, footer string
    string_tree->AppendItem(root_index, _("Animation String"), -1, -1, new StringTreeDataItem(ANIM_STRING, 0));
    string_tree->AppendItem(root_index, _("Footer String"), -1, -1, new StringTreeDataItem(FOOTER_STRING, 0));

    // Extra strings
    if(m_animation->animation->extra_string_count > 0) {
        wxTreeItemId extra_index = string_tree->AppendItem(
            root_index,
            _("Extra Strings"),
            -1,
            -1,
            new StringTreeDataItem(EXTRA_STRING, -1)
        );
        for(int i = 0; i < m_animation->animation->extra_string_count; i++) {
            wxString str_name(_("Extra "));
            str_name << i;
            string_tree->AppendItem(extra_index, str_name, -1, -1, new StringTreeDataItem(EXTRA_STRING, i));
        }
    }
}

void AnimationDialog::find_frames(StringType type, int number) {
    wxString str = getStringByType(type, number);
    if(str.length() > 0) {
        sd_script script;
        sd_script_create(&script);
        sd_script_decode(&script, str.c_str(), NULL);

        // Load up string frames
        frame_tree->DeleteAllItems();
        wxTreeItemId root_index = frame_tree->AddRoot(_("Frames"), -1, -1, NULL);
        if(script.frame_count > 0) {
            for(int i = 0; i < script.frame_count; i++) {
                wxString str_name(_("Frame "));
                str_name << i << ": " << (char)(65+script.frames[i].sprite) << script.frames[i].tick_len;
                frame_tree->AppendItem(root_index, str_name, -1, -1, new StringTreeDataItem(type, number, i));
            }
        }

        sd_script_free(&script);
    } else {
        frame_tree->DeleteAllItems();
    }
}

wxString AnimationDialog::getStringByType(StringType type, int number) {
    switch(type) {
        case ANIM_STRING:
            return wxString(m_animation->animation->anim_string);
            break;
        case FOOTER_STRING:
            return wxString(m_animation->footer_string);
            break;
        case EXTRA_STRING:
            return wxString(m_animation->animation->extra_strings[number]);
            break;
        default:
            return wxString();
            break;
    }
}

void AnimationDialog::onStringSelected(wxTreeEvent& event) {
    event.StopPropagation();
    StringTreeDataItem *item = (StringTreeDataItem*)string_tree->GetItemData(event.GetItem());
    find_frames(item->getType(), item->getNumber());
}

void AnimationDialog::onStringFrameSelected(wxTreeEvent& event) {
    event.StopPropagation();
    StringTreeDataItem *item = (StringTreeDataItem*)string_tree->GetItemData(event.GetItem());
    if(item == NULL)
        return;

    sd_script script;
    sd_script_create(&script);
    sd_script_decode(&script, getStringByType(item->getType(), item->getNumber()).c_str(), NULL);

    sd_script_frame *frame = &script.frames[item->getFrame()];
    if(tag_grid->GetNumberRows() > 0) {
        tag_grid->ClearSelection();
        tag_grid->DeleteRows(0, tag_grid->GetNumberRows());
    }
    tag_grid->AppendRows(frame->tag_count);
    for(int i = 0; i < frame->tag_count; i++) {
        tag_grid->SetCellValue(i, 0, frame->tags[i].key);
        if(frame->tags[i].has_param) {
            tag_grid->SetCellValue(i, 1, wxString::Format("%d", frame->tags[i].value));
        }
        tag_grid->SetColFormatNumber(1);
    }

    sd_script_free(&script);
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
