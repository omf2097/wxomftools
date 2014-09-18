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

    m_script = 0;
    m_loaded_type = NONE_STRING;
    m_loaded_extra = 0;
    m_selected_frame = -1;

    load_strings();
}

AnimationDialog::~AnimationDialog() {
    if(m_script) {
        sd_script_free(m_script);
        free(m_script);
        m_script = 0;
    }
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
    string_tree->Expand(root_index);
}

void AnimationDialog::find_frames(StringType type, int number) {
    wxString str = getStringByType(type, number);
    if(str.length() > 0) {
        if(type != m_loaded_type) {
            if(m_script) {
                saveCurrentScript(); // Save
                sd_script_free(m_script);
                free(m_script);
            }
            m_script = (sd_script*)malloc(sizeof(sd_script));
            sd_script_create(m_script);
            sd_script_decode(m_script, str.c_str(), NULL);
            m_loaded_type = type;
            m_loaded_extra = number;
        }

        // Load up string frames
        frame_tree->DeleteAllItems();
        wxTreeItemId root_index = frame_tree->AddRoot(_("Frames"), -1, -1, NULL);
        if(m_script->frame_count > 0) {
            for(int i = 0; i < m_script->frame_count; i++) {
                wxString str_name(_("Frame "));
                str_name << i << ": " << (char)(65+m_script->frames[i].sprite) << m_script->frames[i].tick_len;
                frame_tree->AppendItem(root_index, str_name, -1, -1, new StringTreeDataItem(type, number, i));
            }
        }
        frame_tree->Expand(root_index);
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
    if(item == NULL) {
        m_selected_frame = -1;
        return;
    }

    sd_script_frame *frame = &m_script->frames[item->getFrame()];
    m_selected_frame = item->getFrame();
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

    _cs(frameSpriteNumberField, frame->sprite);
    _cs(frameSpriteDurationField, frame->tick_len);
}

void AnimationDialog::saveCurrentScript() {
    // Encode and save current animation string
    if(m_script) {
        char *tmp = (char*)calloc(1, sd_script_encoded_length(m_script)+1);
        printf("Length: %d -- %s\n", (int)strlen(tmp), tmp);
        if(sd_script_encode(m_script, tmp) != SD_SUCCESS) {
            wxMessageDialog md(
                this,
                wxString("Error while encoding animation string!"),
                _("Error"),
                wxICON_ERROR|wxOK);
            md.ShowModal();
        } else {
            switch(m_loaded_type) {
                case ANIM_STRING: sd_animation_set_anim_string(m_tmp_anim.animation, tmp); break;
                case EXTRA_STRING: sd_animation_set_extra_string(m_tmp_anim.animation, m_loaded_extra, tmp); break;
                case FOOTER_STRING: sd_bk_set_anim_string(&m_tmp_anim, tmp); break;
                default: break;
            }
        }
        free(tmp);
    }
}

void AnimationDialog::onStringTagChange(wxGridEvent& event) {

}

void AnimationDialog::onFrameSpriteChanged(wxCommandEvent& event) {
    if(m_selected_frame >= 0) {
        sd_script_frame *frame = &m_script->frames[m_selected_frame];
        _cti32(frameSpriteNumberField, &frame->sprite);
    }
}

void AnimationDialog::onFrameDurationChanged(wxCommandEvent& event) {
    if(m_selected_frame >= 0) {
        sd_script_frame *frame = &m_script->frames[m_selected_frame];
        _cti32(frameSpriteDurationField, &frame->tick_len);
    }
}

void AnimationDialog::save() {
    _ct8(chain_if_hit_field, &m_tmp_anim.chain_hit);
    _ct8(chain_if_not_hit_field, &m_tmp_anim.chain_no_hit);
    _ct8(load_on_start_field, &m_tmp_anim.load_on_start);
    _ct16(probability_field, &m_tmp_anim.probability);
    _ct8(hazard_damage_field, &m_tmp_anim.hazard_damage);
    _cti16(start_x_field, &m_tmp_anim.animation->start_x);
    _cti16(start_y_field, &m_tmp_anim.animation->start_y);

    saveCurrentScript();

    sd_bk_anim_free(m_animation);
    sd_bk_anim_copy(m_animation, &m_tmp_anim);
}
