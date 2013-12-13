#include "editorframe.h"
#include "animationtreedataitem.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>

#include <cstdio>

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

void EditorFrame::onMenuSave(wxCommandEvent& event) {
    event.StopPropagation();
    
    sd_bk_save(m_filedata, m_filename);
}

void EditorFrame::onMenuSaveAs(wxCommandEvent& event) {
    event.StopPropagation();
    
    // Ask the user where to save
    wxFileDialog sd(this, 
        _("Save BK file"),
        _(""), 
        _(""), 
        _("BK files (*.BK)|*.BK"), 
        wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (sd.ShowModal() != wxID_OK) {
        return;
    }
    
    sd_bk_save(m_filedata, (char*)sd.GetPath().mb_str().data());
}

void EditorFrame::onMenuExit(wxCommandEvent& event) {
    Destroy();
}

void EditorFrame::onMenuOpen(wxCommandEvent& event) {
    event.StopPropagation();

    // Let the user select file
    wxFileDialog fd(this, 
        _("Open BK file"), 
        _(""), 
        _(""), 
        _("BK files (*.BK)|*.BK"), 
        wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(fd.ShowModal() != wxID_OK) {
        return;
    }
    
    // Open file
    wxString new_name = fd.GetPath();
    sd_bk_file *new_data = sd_bk_create();
    int success = sd_bk_load(new_data, new_name);
    if(success != SD_SUCCESS) {
        wxMessageDialog md(this, 
            wxString("Error while attempting to parse BK file."), 
            _("Error"), wxICON_ERROR|wxOK);
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
    this->clearPreview();
}

void EditorFrame::convertRGBAtoRGB(char *dst, char *src, int size) {
    for(int i = 0; i < size; i++) {
        dst[(i*3) + 0] = src[(i*4) + 0];
        dst[(i*3) + 1] = src[(i*4) + 1];
        dst[(i*3) + 2] = src[(i*4) + 2];
    }
}

wxImage EditorFrame::RGBAtoNative(sd_rgba_image *src) {
    char *idata = (char*)malloc(src->w * src->h * 3);
    this->convertRGBAtoRGB(idata, src->data, src->w*src->h);
    return wxImage(src->w, src->h, (unsigned char*)idata, false);
}

void EditorFrame::updateBgImage() {
    // Load up background image
    sd_rgba_image *img = sd_vga_image_decode(m_filedata->background, m_filedata->palettes[m_pal], m_remap-1);
    wxImage bgImg = RGBAtoNative(img).Scale(640, 400);
    this->bg_image_bitmap->SetBitmap(wxBitmap(bgImg));
    sd_rgba_image_delete(img);
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
    
    // Background image
    updateBgImage();
    
    // Load up animations
    animations_tree->DeleteAllItems();
    wxTreeItemData *root_data = new AnimationTreeDataItem();
    wxTreeItemId root_index = animations_tree->AddRoot(_("Animations"), -1, -1, root_data);
    for(int i = 0; i < 50; i++) {
        if(m_filedata->anims[i] == NULL) continue;
        sd_bk_anim *bka = m_filedata->anims[i];
        sd_animation *a = bka->animation;
        
        wxString anim_name(_("Animation "));
        anim_name << i;
        wxTreeItemData *anim_data = new AnimationTreeDataItem(bka);
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
    
    // Palettes & overlays
    palette_ctrl_select_palette->Clear();
    for(int i = 0; i < m_filedata->num_palettes; i++) {
        wxString pal_name(_("Palette "));
        pal_name << i;
        palette_ctrl_select_palette->Append(pal_name);
    }
    palette_ctrl_select_palette->SetSelection(m_pal);
    
    // Overlays
    palette_ctrl_select_remap->Clear();
    palette_ctrl_select_remap->Append(_("None"));
    for(int i = 0; i < 18; i++) {
        wxString remap_name(_("Remapping "));
        remap_name << i;
        palette_ctrl_select_remap->Append(remap_name);
    }
    palette_ctrl_select_remap->SetSelection(m_remap);
    
    // Show palette
    this->showSelectedPalette();
    
    // Request for refresh
    this->Refresh();
}

void EditorFrame::onPaletteChoice(wxCommandEvent& event) {
    event.StopPropagation();
    m_pal = palette_ctrl_select_palette->GetSelection();
    showSelectedPalette();
    updateAnimationViews();
    updateBgImage();
    this->Update();
}

void EditorFrame::onRemapChoice(wxCommandEvent& event) {
    event.StopPropagation();
    m_remap = palette_ctrl_select_remap->GetSelection();
    showSelectedPalette();
    updateAnimationViews();
    updateBgImage();
    this->Update();
}

void EditorFrame::showSelectedPalette() {
    this->palette_grid_sizer->Clear(true);

    // Get palette table
    sd_palette *pal = m_filedata->palettes[m_pal];

    // Draw buttons
    wxStaticText *label;
    uint8_t r,g,b;
    palette_grid_panel->Freeze();
    for(int i = 0; i < 256; i++) {
        // Find color
        if(m_remap > 0) {
            r = pal->data[(int)pal->remaps[m_remap-1][i]][0];
            g = pal->data[(int)pal->remaps[m_remap-1][i]][1];
            b = pal->data[(int)pal->remaps[m_remap-1][i]][2];
        } else {
            r = pal->data[i][0];
            g = pal->data[i][1];
            b = pal->data[i][2];
        }

        // Create color area + add it to the sizer
        label = new wxStaticText(palette_grid_panel, wxID_ANY, wxDecToHex(i));
        label->SetBackgroundColour(wxColour(r,g,b));
        label->SetForegroundColour(wxColour(255,255,255));
        //label->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(wxBKEditorFrame::onChangePaletteColor), NULL, this);
        this->palette_grid_sizer->Add(label, 1, wxEXPAND, 0);
    }

    // Update panel and sizer contents
    palette_grid_panel->Thaw();
    this->palette_grid_panel->Layout();
    this->palette_grid_sizer->FitInside(this->palette_grid_panel);
    this->Update();
}

void EditorFrame::onPaletteLoad(wxCommandEvent& event) {

}

void EditorFrame::onPaletteSave(wxCommandEvent& event) {
    // Ask the user where to save
    wxFileDialog sd(this, 
        _("GPL (Gimp Palette)"), 
        _(""), 
        _(""), 
        _("GPL files (*.gpl)|*.gpl"), 
        wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

    if(sd.ShowModal() != wxID_OK) {
        return;
    }

    // Save
    sd_palette_to_gimp_palette((char*)sd.GetPath().mb_str().data(), m_filedata->palettes[m_pal]);
}

// Gets called when animation menu "edit" button is clicked.
void EditorFrame::onAnimationEdit(wxCommandEvent& event) {
    event.StopPropagation();
    wxTreeItemId id = animations_tree->GetSelection();
    if(id.IsOk()) {
        cbAnimEditFunc(id);
    }
}

// Gets called by context menu Edit item
void EditorFrame::onAnimItemEdit(wxCommandEvent& event) {
    event.StopPropagation();
    wxPoint m_point = EditorFrame::ScreenToClient(wxGetMousePosition());
    wxPoint m_obj = EditorFrame::ScreenToClient(animations_tree->GetScreenPosition());
    wxPoint r = m_point - m_obj;
    r.y -= 10;

    wxTreeItemId id = animations_tree->HitTest(r);
    if(id.IsOk()) {
        cbAnimEditFunc(id);
    }
}

// Gets called when animation menu "delete" button is clicked.
void EditorFrame::onAnimationDelete(wxCommandEvent& event) {
    event.StopPropagation();
    wxTreeItemId id = animations_tree->GetSelection();
    if(id.IsOk()) {
        cbAnimDeleteFunc(id);
    }
}

// Gets called by context menu Delete item
void EditorFrame::onAnimItemDelete(wxCommandEvent& event) {
    event.StopPropagation();
    wxPoint m_point = EditorFrame::ScreenToClient(wxGetMousePosition());
    wxPoint m_obj = EditorFrame::ScreenToClient(animations_tree->GetScreenPosition());
    wxPoint r = m_point - m_obj;
    r.y -= 10;

    wxTreeItemId id = animations_tree->HitTest(r);
    if(id.IsOk()) {
        cbAnimDeleteFunc(id);
    }
}

void EditorFrame::cbAnimEditFunc(wxTreeItemId id) {
    AnimationTreeDataItem *item = (AnimationTreeDataItem*)animations_tree->GetItemData(id);
    if(item->getType() == AnimationTreeDataItem::SPRITE) {
        sd_sprite *sprite = item->getSprite();
        SpriteDialog dlg(this, sprite);
        if(dlg.ShowModal() == wxID_OK) {
            dlg.save();
        }
    } else if(item->getType() == AnimationTreeDataItem::ANIMATION) {
        sd_bk_anim *animation = item->getAnimation();
        AnimationDialog dlg(this, animation);
        if(dlg.ShowModal() == wxID_OK) {
            dlg.save();
        }
    }
}

void EditorFrame::cbAnimDeleteFunc(wxTreeItemId id) {
    AnimationTreeDataItem *item = (AnimationTreeDataItem*)animations_tree->GetItemData(id);
    if(item->getType() == AnimationTreeDataItem::SPRITE) {
        //sd_sprite *sprite = item->getSprite();

    } else if(item->getType() == AnimationTreeDataItem::ANIMATION) {
        //sd_bk_anim *animation = item->getAnimation();

    }
}

void EditorFrame::updateAnimationViews() {
    wxTreeItemId id = animations_tree->GetSelection();
    if(id.IsOk()) {
        showAnimationTreeInfo(id);
    }
}

// Shows a given sprite in sprite preview wxstaticbitmap
void EditorFrame::loadPreviewSprite(sd_sprite *sprite) {
    sd_rgba_image *img = sd_sprite_image_decode(
        sprite->img, 
        m_filedata->palettes[m_pal], 
        m_remap-1);

    // Scale & reposition
    int w = img->w;
    int h = img->h;
    int nw,nh;
    if(w > h) {
        nw = 160;
        nh = 100 * h / w;
    } else {
        nh = 100;
        nw = 160 * w / h;
    }
    int pos_x = (160 - nw) / 2;
    int pos_y = (100 - nh) / 2;

    wxImage spImg = RGBAtoNative(img).Scale(nw, nh);
    wxImage bg = wxImage(160, 100, true);
    bg.Paste(spImg, pos_x, pos_y);
    this->animations_preview_bitmap->SetBitmap(wxBitmap(bg));
    sd_rgba_image_delete(img);
}

void EditorFrame::clearPreview() {
    this->animations_preview_data->SetPage(wxString());
    wxImage bg = wxImage(160, 100, true);
    this->animations_preview_bitmap->SetBitmap(wxBitmap(bg));
}

// Updates preview info with the information from animation tree with given treeitem
void EditorFrame::showAnimationTreeInfo(wxTreeItemId id) {
    // Handle information
    AnimationTreeDataItem *item = (AnimationTreeDataItem*)animations_tree->GetItemData(id);
    if(item->getType() == AnimationTreeDataItem::SPRITE) {
        sd_sprite *sprite = item->getSprite();
        loadPreviewSprite(sprite);

        wxString pos_x = wxString::Format("%d", sprite->pos_x);
        wxString pos_y = wxString::Format("%d", sprite->pos_y);
        wxString size_x = wxString::Format("%d", sprite->img->w);
        wxString size_y = wxString::Format("%d", sprite->img->h);
        wxString index = wxString::Format("%d", sprite->index);
        wxString missing = wxString::Format("%d", sprite->missing);
        wxString content(" \
            <html> \
            <body> \
                <strong>Sprite</strong><br />\
                Position = " + pos_x + "," + pos_y + "<br /> \
                Size = " + size_x + "," + size_y + "<br /> \
                Index/Missing = " + index + "/" + missing + " \
            </body> \
            </html> \
        ");
        this->animations_preview_data->SetPage(content);

    } else if(item->getType() == AnimationTreeDataItem::ANIMATION) {
        sd_bk_anim *bkanim = item->getAnimation();
        if(bkanim->animation->frame_count > 0) {
            loadPreviewSprite(bkanim->animation->sprites[0]);
        }

        wxString astr(bkanim->animation->anim_string);
        wxString content(" \
            <html> \
            <body> \
                <strong>Animation</strong><br />\
                String: " + astr + "\
            </body> \
            </html> \
        ");
        this->animations_preview_data->SetPage(content);
    } else {
        clearPreview();
    }
}

// Creates and shows a context menu for animation tree control
void EditorFrame::onAnimTreeContextMenu(wxTreeEvent& event) {
    event.StopPropagation();

    wxPoint point = ScreenToClient(wxGetMousePosition());

    wxMenu menu;
    wxMenuItem *editItem = new wxMenuItem(&menu, wxID_ANY, _("Edit"));
    wxMenuItem *deleteItem = new wxMenuItem(&menu, wxID_ANY, _("Delete"));
    this->Connect(
        editItem->GetId(), 
        wxEVT_COMMAND_MENU_SELECTED, 
        wxCommandEventHandler(EditorFrame::onAnimItemEdit));
    this->Connect(
        deleteItem->GetId(), 
        wxEVT_COMMAND_MENU_SELECTED, 
        wxCommandEventHandler(EditorFrame::onAnimItemDelete));
    menu.Append(editItem);
    menu.Append(deleteItem);
    PopupMenu(&menu, point.x, point.y);
}

// Action for selecting animation tree item (animation,sprite)
void EditorFrame::onAnimTreeItemSelect(wxTreeEvent& event) {
    event.StopPropagation();
    showAnimationTreeInfo(event.GetItem());
    this->Update();
}

void EditorFrame::onBackgroundSave(wxCommandEvent& event) {
    // Ask the user where to save
    wxFileDialog sd(this, 
        _("PNG (Portable Network Graphics)"), 
        _(""),
        _(""), 
        _("PNG files (*.png)|*.png"), 
        wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
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
    info.SetCopyright(_T("(C) 2013-2014 Tuomas Virtanen <katajakasa@gmail.com>"));
    info.SetWebSite(_("https://github.com/omf2097/wxBKEditor"));
    wxAboutBox(info);
}