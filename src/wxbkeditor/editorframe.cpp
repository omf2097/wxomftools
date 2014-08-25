#include <cstdio>

#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <wx/sizer.h>
#include <wx/colordlg.h>

#include "license.h"
#include "editorframe.h"
#include "animationtreedataitem.h"

class UserdataWrapper: public wxObject {
public:
    UserdataWrapper(void *data) : wxObject(), m_data(data) {}
    void* m_data;
};

EditorFrame::EditorFrame(wxFrame *frame) : BKBaseFrame(frame) {
    // Initialize
    m_filedata = NULL;
    reset();

    // Disable stuff by default
    this->menuitem_save->Enable(false);
    this->menuitem_saveas->Enable(false);
    this->base_tabs->Enable(false);
}

EditorFrame::~EditorFrame() {
    if(m_filedata != NULL) {
        sd_bk_free(m_filedata);
        delete m_filedata;
    }
}

void EditorFrame::reset() {
    if(m_filedata != NULL) {
        sd_bk_free(m_filedata);
        delete m_filedata;
        m_filedata = NULL;
    }
    m_filename = "";
    m_pal = 0;
    m_remap = 0;
    updateTitle();
    m_filedata = new sd_bk_file;
    sd_bk_create(m_filedata);
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
    
    int ret = sd_bk_save(m_filedata, m_filename);
    if(ret != SD_SUCCESS) {
        wxMessageDialog md(
            this, 
            wxString("Error while attempting to save BK file."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
    }
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
    if(sd.ShowModal() != wxID_OK) {
        return;
    }
    
    int ret = sd_bk_save(m_filedata, (char*)sd.GetPath().mb_str().data());
    if(ret != SD_SUCCESS) {
        wxMessageDialog md(
            this, 
            wxString("Error while attempting to save BK file."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
    }
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
    sd_bk_file *new_data = new sd_bk_file;
    sd_bk_create(new_data);
    int success = sd_bk_load(new_data, new_name);
    if(success != SD_SUCCESS) {
        wxMessageDialog md(this, 
            wxString("Error while attempting to parse BK file."), 
            _("Error"), wxICON_ERROR|wxOK);
        md.ShowModal();
        sd_bk_free(new_data);
        return;
    }
    
    // Kill old data & set new
    if(m_filedata != NULL) {
        sd_bk_free(m_filedata);
        delete m_filedata;
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

void EditorFrame::onMenuNew(wxCommandEvent& event) {
    event.StopPropagation();
    
    // Kill old data & set new
    if(m_filedata != NULL) {
        sd_bk_free(m_filedata);
        delete m_filedata;
        m_filedata = NULL;
    }

    // Open file
    m_filename = wxString("New");
    m_filedata = new sd_bk_file;
    sd_bk_create(m_filedata);

    updateTitle();

    // Enable items
    this->menuitem_save->Enable(true);
    this->menuitem_saveas->Enable(true);
    this->base_tabs->Enable(true);
    
    // Refresh editor fields
    this->refreshFields();
    this->clearPreview();
}

wxImage EditorFrame::RGBAtoNative(sd_rgba_image *src) {
    char *idata = (char*)malloc(src->w * src->h * 3);
    char *adata = (char*)malloc(src->w * src->h);

    for(unsigned int i = 0; i < src->w * src->h; i++) {
        idata[(i*3) + 0] = src->data[(i*4) + 0];
        idata[(i*3) + 1] = src->data[(i*4) + 1];
        idata[(i*3) + 2] = src->data[(i*4) + 2];
        adata[i] = src->data[(i*4) + 3];
    }

    return wxImage(src->w, src->h, (unsigned char*)idata, (unsigned char*)adata, false);
}

void EditorFrame::updateBgImage() {
    // Load up background image
    if(m_filedata->background == NULL)
        return;
    sd_rgba_image img;
    sd_vga_image_decode(&img, m_filedata->background, m_filedata->palettes[m_pal], m_remap-1);
    wxImage bgImg = RGBAtoNative(&img).Scale(640, 400);
    this->bg_image_bitmap->SetBitmap(wxBitmap(bgImg));
    sd_rgba_image_free(&img);
}

void EditorFrame::refreshFields() {
    info_value_fileid->SetValue(wxString::Format("%d", m_filedata->file_id));
	info_value_palettec->SetLabel(wxString::Format("%d", m_filedata->palette_count));
    if(m_filedata->background) {
	    info_value_bgw->SetLabel(wxString::Format("%d", m_filedata->background->w));
	    info_value_bgh->SetLabel(wxString::Format("%d", m_filedata->background->h));
    } else {
	    info_value_bgw->SetLabel(_("0"));
	    info_value_bgh->SetLabel(_("0"));
    }
    
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
        wxTreeItemData *anim_data = new AnimationTreeDataItem(bka, i);
        wxTreeItemId anim_index = animations_tree->AppendItem(root_index, anim_name, -1, -1, anim_data);

        // Load Sprites
        for(int n = 0; n < a->sprite_count; n++) {
            sd_sprite *s = a->sprites[n];
        
            wxString sprite_name(_("Sprite "));
            sprite_name << (wxChar)(65 + n);
            wxTreeItemData *spriteData = new AnimationTreeDataItem(s, i, n);
            animations_tree->AppendItem(anim_index, sprite_name, -1, -1, spriteData);
        }
    }
    
    // Palettes & overlays
    if(m_filedata->palette_count > 0) {
        palette_ctrl_select_palette->Clear();
        for(int i = 0; i < m_filedata->palette_count; i++) {
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
    }

    // Update soundstable
    for(int i = 0; i < 30; i++) {
        unsigned char s = m_filedata->soundtable[i];
        sound_grid->SetCellValue(i, 0, wxString::Format("%d", s));
        sound_grid->SetColFormatNumber(i);
    }
    
    // Request for refresh
    this->Refresh();
}

void EditorFrame::onSoundChange(wxGridEvent& event) {
    int row = event.GetRow();
    long value;
    sound_grid->GetCellValue(row, 0).ToLong(&value);
    if(value < 0 || value >= 256) {
        wxMessageDialog md(
            this, 
            wxString("Sound ID must be between 0 and 255!"), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        unsigned char s = m_filedata->soundtable[row];
        sound_grid->SetCellValue(row, 0, wxString::Format("%d", s));
    } else {
        unsigned char s = value;
        m_filedata->soundtable[row] = s;
    }
    this->refreshFields();
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
    // Get palette table
    sd_palette *pal = m_filedata->palettes[m_pal];

    this->Freeze();

    // Create a sizer
    wxFlexGridSizer *palette_grid_sizer = new wxFlexGridSizer(16, 16, 0, 0);
    palette_grid_sizer->SetFlexibleDirection( wxBOTH );
    palette_grid_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    for(int i = 0; i < 16; i++) {
        palette_grid_sizer->AddGrowableCol(i);
        palette_grid_sizer->AddGrowableRow(i);
    }

    // Draw buttons
    wxStaticText *label;
    wxPanel *panel;
    wxGridSizer *sizer;
    uint8_t r,g,b;
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

        // Create a panel
        panel = new wxPanel(palette_grid_panel, wxID_ANY);
        panel->SetBackgroundColour(wxColour(r,g,b));
        panel->SetForegroundColour(wxColour(r,g,b));
        sizer = new wxGridSizer(1,1,0,0);

        // Create color area + add it to the panel
        label = new wxStaticText(panel, wxID_ANY, wxDecToHex(i));
        label->SetForegroundColour(wxColour(255,255,255));
        UserdataWrapper *udata = new UserdataWrapper(label);
        label->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(EditorFrame::onChangePaletteColor), udata, this);
        
        sizer->Add(label, 0, wxEXPAND, 0);
        panel->SetSizer(sizer);

        // Add sizer to palette sizer
        palette_grid_sizer->Add(panel, 0, wxEXPAND|wxALL, 0);
    }

    // Update panel and sizer contents
    palette_grid_panel->SetSizer(palette_grid_sizer);
    palette_grid_panel->Layout();
    this->Thaw();
}

void EditorFrame::onNewPalette(wxCommandEvent& event) {
    sd_palette pal;
    sd_palette_create(&pal);
    sd_bk_push_palette(m_filedata, &pal);
    sd_palette_free(&pal);
    refreshFields();
}

void EditorFrame::onChangePaletteColor(wxMouseEvent& event) {
    UserdataWrapper *u = (UserdataWrapper*)event.GetEventUserData();
    wxStaticText *t = (wxStaticText*)u->m_data;
    long pal_index;
    t->GetLabelText().ToLong(&pal_index, 16);

    wxColourData d_color;
    d_color.SetColour(wxColour(
        m_filedata->palettes[m_pal]->data[pal_index][0],
        m_filedata->palettes[m_pal]->data[pal_index][1],
        m_filedata->palettes[m_pal]->data[pal_index][2]));

    wxColourDialog dlg(this, &d_color);
    if(dlg.ShowModal() != wxID_OK) {
        return;
    }

    wxColourData data = dlg.GetColourData();
    wxColour current = data.GetColour();
    m_filedata->palettes[m_pal]->data[pal_index][0] = current.Red();
    m_filedata->palettes[m_pal]->data[pal_index][1] = current.Green();
    m_filedata->palettes[m_pal]->data[pal_index][2] = current.Blue();
    showSelectedPalette();
    updateBgImage();
}

void EditorFrame::onPaletteLoad(wxCommandEvent& event) {
    sd_palette *pal;
    pal = sd_bk_get_palette(m_filedata, m_pal);
    if(pal == NULL) {
        wxMessageDialog md(
            this, 
            wxString("Unable load palette; select a valid target palette first."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }

    // Ask the user where to save
    wxFileDialog sd(this, 
        _("GPL (Gimp Palette)"), 
        _(""), 
        _(""), 
        _("GPL files (*.gpl)|*.gpl"), 
        wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if(sd.ShowModal() != wxID_OK) {
        return;
    }

    // Save
    int ret = sd_palette_from_gimp_palette(pal, (char*)sd.GetPath().mb_str().data());
    if(ret != SD_SUCCESS) {
        wxMessageDialog md(
            this, 
            wxString("Error while attempting to load palette."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }
}

void EditorFrame::onPaletteSave(wxCommandEvent& event) {
    sd_palette *pal;
    pal = sd_bk_get_palette(m_filedata, m_pal);
    if(pal == NULL) {
        wxMessageDialog md(
            this, 
            wxString("Unable save palette; select a valid source palette first."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }

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
    int ret = sd_palette_to_gimp_palette(
        m_filedata->palettes[m_pal],
        (char*)sd.GetPath().mb_str().data());
    if(ret != SD_SUCCESS) {
        wxMessageDialog md(
            this, 
            wxString("Error while attempting to save palette."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }
}

// Gets called when animation menu "add sprite" button is clicked.
void EditorFrame::onSpriteAdd(wxCommandEvent& event) {
    wxTreeItemId id = animations_tree->GetSelection();
    if(id.IsOk()) {
        cbSpriteAddFunc(id);
    }
}

// Gets called by context menu Add sprite item
void EditorFrame::onAnimSpriteAdd(wxCommandEvent& event) {
    event.StopPropagation();
    if(m_last_treeindex.IsOk()) {
        cbSpriteAddFunc(m_last_treeindex);
    }
}

void EditorFrame::cbSpriteAddFunc(wxTreeItemId id) {
    AnimationTreeDataItem *item = (AnimationTreeDataItem*)animations_tree->GetItemData(id);

    // Make sure we have animation selected
    if(item->getType() != AnimationTreeDataItem::ANIMATION) {
        wxMessageDialog md(
            this, 
            wxString("Select an animation for the sprite first!"), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }

    // Add new sprite
    sd_sprite sprite;
    sd_sprite_create(&sprite);
    sd_animation *ani = sd_bk_get_anim(m_filedata, item->anim_id)->animation;
    sd_animation_push_sprite(ani, &sprite);
    sd_sprite_free(&sprite);

    // Show in tree
    int index = ani->sprite_count - 1;
    sd_sprite *s = ani->sprites[index];
    wxString sprite_name(_("Sprite "));
    sprite_name << (wxChar)(65 + index);
    wxTreeItemData *spriteData = new AnimationTreeDataItem(s, item->anim_id, index);
    animations_tree->AppendItem(id, sprite_name, -1, -1, spriteData);
}

// Gets called when animation menu "add animation" button is clicked.
void EditorFrame::onAnimationAdd(wxCommandEvent& event) {
    NewAnimationDialog dlg(this);
    if(dlg.ShowModal() != wxID_OK) {
        return;
    }

    // Make sure index is correct
    int index = dlg.getIndex();
    if(index < 0 || index >= 50) {
        wxMessageDialog md(
            this, 
            wxString("Animation index must be between 0 and 49 (inclusive)."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }

    // Make sure the index doesn't already exist
    if(sd_bk_get_anim(m_filedata, index) != NULL) {
        wxMessageDialog md(
            this, 
            wxString("Animation index is reserved! Choose another one."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }

    // Add new animation to index
    sd_bk_anim bka;
    sd_bk_anim_create(&bka);
    sd_animation ani;
    sd_animation_create(&ani);
    sd_bk_anim_set_animation(&bka, &ani);
    sd_bk_set_anim(m_filedata, index, &bka);
    sd_bk_anim_free(&bka);
    sd_animation_free(&ani);

    // Add animation to tree
    wxTreeItemId root_index = animations_tree->GetRootItem();
    wxString anim_name(_("Animation "));
    anim_name << index;
    sd_bk_anim *n_bka = sd_bk_get_anim(m_filedata, index);
    wxTreeItemData *anim_data = new AnimationTreeDataItem(n_bka, index);
    animations_tree->AppendItem(root_index, anim_name, -1, -1, anim_data);
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
    if(m_last_treeindex.IsOk()) {
        cbAnimEditFunc(m_last_treeindex);
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
    if(m_last_treeindex.IsOk()) {
        cbAnimDeleteFunc(m_last_treeindex);
    }
}

void EditorFrame::cbAnimEditFunc(wxTreeItemId id) {
    AnimationTreeDataItem *item = (AnimationTreeDataItem*)animations_tree->GetItemData(id);
    if(item->getType() == AnimationTreeDataItem::SPRITE) {
        sd_sprite *sprite = item->getSprite();
        SpriteDialog dlg(this, sprite, m_filedata->palettes[0]);
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
        int sprite_id = item->sprite_id;
        int ani_id = item->anim_id;
        sd_animation *ani = sd_bk_get_anim(m_filedata, ani_id)->animation;

        // Make sure we are deleting the last item
        if(sprite_id != ani->sprite_count-1) {
            wxMessageDialog md(
                this, 
                wxString::Format("You may only remove the last sprite in animation!"), 
                _("Error"), 
                wxICON_ERROR|wxOK);
            md.ShowModal();
            return;
        }

        // Ask if we want to continue for sure.
        wxMessageDialog md(
            this, 
            wxString::Format("Are you sure you wish to delete sprite index %d from animation %d ?", item->sprite_id, item->anim_id), 
            _("Delete sprite ?"), 
            wxICON_QUESTION|wxOK|wxCANCEL);

        // If yes, kill it with fire.
        if(md.ShowModal() == wxID_OK) {
            sd_animation_pop_sprite(ani);
            animations_tree->Delete(id);
            animations_tree->Update();
        }
    } else if(item->getType() == AnimationTreeDataItem::ANIMATION) {
        wxMessageDialog md(
            this, 
            wxString::Format("Are you sure you wish to delete animation index %d ?", item->anim_id), 
            _("Delete animation ?"), 
            wxICON_QUESTION|wxOK|wxCANCEL);
        if(md.ShowModal() == wxID_OK) {
            sd_bk_set_anim(m_filedata, item->anim_id, NULL);
            animations_tree->Delete(id);
            animations_tree->Update();
        }
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
    sd_palette *pal = sd_bk_get_palette(m_filedata, 0);
    if(pal == NULL)
        return;

    sd_rgba_image img;
    sd_sprite_rgba_decode(&img, sprite, pal, m_remap-1);

    // Scale & reposition
    int w = img.w;
    int h = img.h;
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

    wxImage spImg = RGBAtoNative(&img).Scale(nw, nh);
    wxImage bg = wxImage(160, 100, true);
    bg.Paste(spImg, pos_x, pos_y);
    this->animations_preview_bitmap->SetBitmap(wxBitmap(bg));
    sd_rgba_image_free(&img);
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
        wxString size_x = wxString::Format("%d", sprite->width);
        wxString size_y = wxString::Format("%d", sprite->height);
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
        if(bkanim->animation->sprite_count > 0) {
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
    m_last_treeindex = event.GetItem();
    int type = ((AnimationTreeDataItem*)animations_tree->GetItemData(m_last_treeindex))->getType();

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

    if(type == AnimationTreeDataItem::ANIMATION) {
        wxMenuItem *addSpriteItem = new wxMenuItem(&menu, wxID_ANY, _("Add Sprite"));
        this->Connect(
            addSpriteItem->GetId(), 
            wxEVT_COMMAND_MENU_SELECTED, 
            wxCommandEventHandler(EditorFrame::onAnimSpriteAdd));
        menu.Append(addSpriteItem);
    } 

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
    sd_rgba_image img;
    sd_vga_image_decode(&img, m_filedata->background, m_filedata->palettes[0], 0);
    RGBAtoNative(&img).SaveFile(sd.GetPath());
    sd_rgba_image_free(&img);
}

void EditorFrame::onBackgroundLoad(wxCommandEvent& event) {
    // Ask the user where to load from
    wxFileDialog sd(this, 
        _("PNG (PNG Image)"), 
        _(""), 
        _(""), 
        _("PNG files (*.png)|*.png"), 
        wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(sd.ShowModal() != wxID_OK) {
        return;
    }

    // Attempt to load
    sd_vga_image img;
    int ret = sd_vga_image_from_png(&img, (char*)sd.GetPath().mb_str().data());
    if(ret != SD_SUCCESS) {
        wxMessageDialog md(
            this, 
            wxString::Format("Error while attempting to load image. Make sure the image is a 8bit paletted PNG file smaller than 320x200 pixels."), 
            _("Error"), 
            wxICON_ERROR|wxOK);
        md.ShowModal();
        return;
    }

    sd_bk_set_background(m_filedata, &img);
    sd_vga_image_free(&img);
    updateBgImage();
}

void EditorFrame::onMenuAbout(wxCommandEvent &event) {
    wxAboutDialogInfo info;
    info.SetName(_("wxBKEditor"));
    info.SetVersion(_("0.2"));
    info.SetDescription(_("One Must Fall 2097 BK file editor"));
    info.SetCopyright(_T("(C) 2013 Tuomas Virtanen <katajakasa@gmail.com>"));
    info.SetWebSite(_("https://github.com/omf2097/wxomftools"));
    info.SetLicense(_(mit_license));
    wxAboutBox(info);
}
