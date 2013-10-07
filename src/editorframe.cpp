#include "editorframe.h"
#include "animationtreedataitem.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>

EditorFrame::EditorFrame(wxFrame *frame) : BaseFrame(frame) {
    // Initialize
    m_filedata = NULL;
    reset();

    // Disable stuff by default
    this->menuitem_save->Enable(false);
    this->menuitem_saveas->Enable(false);
    this->base_tabs->Enable(false);
    
    // Load wx image handlers
    wxImage::AddHandler(new wxPNGHandler);
}

EditorFrame::~EditorFrame() {
    if(m_filedata != NULL) {
        sd_bk_delete(m_filedata);
    }
}

void EditorFrame::reset() {
    if(m_filedata != NULL) {
        sd_bk_delete(m_filedata);
        m_filedata = NULL;
    }
    m_filename = "";
    m_pal = 0;
    m_remap = 0;
    updateTitle();
    m_filedata = sd_bk_create();
}

void EditorFrame::updateTitle() {
    wxString title(_("wxBKEditor"));
    if(m_filename.length() > 128) {
        title.append(" - ");
        title.append(m_filename.SubString(0, 48));
        title.append(_(" ... "));
        title.append(m_filename.SubString(m_filename.length()-48, 48));
    } else if(m_filename.length() > 0) {
        title.append(" - ");
        title.append(m_filename);
    }
    SetTitle(title);
}

void EditorFrame::onMenuExit(wxCommandEvent& event) {
    Destroy();
}

void EditorFrame::onMenuOpen(wxCommandEvent& event) {
    event.StopPropagation();

    // Let the user select file
    wxFileDialog fd(this, _("Open BK file"), _(""), _(""), _("BK files (*.BK)|*.BK"), wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(fd.ShowModal() != wxID_OK) {
        return;
    }
    
    // Open file
    wxString new_name = fd.GetPath();
    sd_bk_file *new_data = sd_bk_create();
    int success = sd_bk_load(new_data, new_name);
    if(success != SD_SUCCESS) {
        wxMessageDialog md(this, wxString("Error while attempting to parse BK file."), _("Error"), wxICON_ERROR|wxOK);
        md.ShowModal();
        sd_bk_delete(new_data);
        return;
    }
    
    // Kill old data & set new
    if(m_filedata != NULL) {
        sd_bk_delete(m_filedata);
        m_filedata = NULL;
    }
    m_filedata = new_data;
    m_filename = new_name;
    updateTitle();

    // Enable items
    this->menuitem_save->Enable(true);
    this->menuitem_saveas->Enable(true);
    this->base_tabs->Enable(true);
    
    // Refresh editor fields
    this->refreshFields();
}

void EditorFrame::convertRGBAtoRGB(char *dst, char *src, int size) {
    for(int i = 0; i < size; i++) {
        dst[(i*3) + 0] = src[(i*4) + 0];
        dst[(i*3) + 1] = src[(i*4) + 1];
        dst[(i*3) + 2] = src[(i*4) + 2];
    }
}

wxImage EditorFrame::RGBAtoNative(sd_rgba_image *src) {
    char *idata = (char*)malloc(320 * 200 * 3);
    this->convertRGBAtoRGB(idata, src->data, 320*200);
    return wxImage(320, 200, (unsigned char*)idata, false);
}

void EditorFrame::refreshFields() {
    info_value_fileid->SetValue(wxString::Format("%d", m_filedata->file_id));
	info_value_palettec->SetLabel(wxString::Format("%d", m_filedata->num_palettes));
	info_value_bgw->SetLabel(wxString::Format("%d", m_filedata->background->w));
	info_value_bgh->SetLabel(wxString::Format("%d", m_filedata->background->h));
    
    int anim_num = 0;
    for(int i = 0; i < 50; i++) {
        if(m_filedata->anims[i] != NULL) anim_num++;
    }
	info_value_animationc->SetLabel(wxString::Format("%d", anim_num));
    
    // Load up background image
    sd_rgba_image *img = sd_vga_image_decode(m_filedata->background, m_filedata->palettes[0], 0);
    wxImage bgImg = RGBAtoNative(img).Scale(640, 400);
    this->bg_image_bitmap->SetBitmap(wxBitmap(bgImg));
    sd_rgba_image_delete(img);
    
    // Load up animations
    animations_tree->DeleteAllItems();
    wxTreeItemId root_index = animations_tree->AddRoot(_("Animations"));
    for(int i = 0; i < 50; i++) {
        if(m_filedata->anims[i] == NULL) continue;
        sd_bk_anim *bka = m_filedata->anims[i];
        sd_animation *a = bka->animation;
        
        wxString anim_name(_("Animation "));
        anim_name << i;
        wxTreeItemData *anim_data = new AnimationTreeDataItem(a);
        wxTreeItemId anim_index = animations_tree->AppendItem(root_index, anim_name, -1, -1, anim_data);

        // Load Sprites
        for(int n = 0; n < a->frame_count; n++) {
            sd_sprite *s = a->sprites[n];
        
            wxString sprite_name(_("Sprite "));
            sprite_name << (wxChar)(65 + n);
            wxTreeItemData *spriteData = new AnimationTreeDataItem(s);
            animations_tree->AppendItem(anim_index, sprite_name, -1, -1, spriteData);
        }
    }
    
    // Request for refresh
    this->Refresh();
}

void EditorFrame::onBackgroundSave(wxCommandEvent& event) {
    // Ask the user where to save
    wxFileDialog sd(this, _("PNG (Portable Network Graphics)"), _(""), _(""), _("PNG files (*.png)|*.png"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (sd.ShowModal() != wxID_OK) {
        return;
    }

    // Decode and save
    sd_rgba_image *img = sd_vga_image_decode(m_filedata->background, m_filedata->palettes[0], 0);
    RGBAtoNative(img).SaveFile(sd.GetPath());
    sd_rgba_image_delete(img);
}

void EditorFrame::onMenuAbout(wxCommandEvent &event) {
    wxAboutDialogInfo info;
    info.SetName(_("wxBKEditor"));
    info.SetVersion(_("0.1 Alpha"));
    info.SetDescription(_("One Must Fall 2097 BK file editor"));
    info.SetCopyright(_T("(C) 2013 Tuomas Virtanen <katajakasa@gmail.com>"));
    info.SetWebSite(_("https://github.com/omf2097/wxBKEditor"));
    wxAboutBox(info);
}