///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

BaseFrame::BaseFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	base_menu_bar = new wxMenuBar( 0 );
	menu_file = new wxMenu();
	wxMenuItem* menuitem_new;
	menuitem_new = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("New") ) + wxT('\t') + wxT("CTRL+N"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_new );
	
	wxMenuItem* menuitem_open;
	menuitem_open = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Open ...") ) + wxT('\t') + wxT("CTRL+O"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_open );
	
	menuitem_save = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_save );
	
	menuitem_saveas = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Save As ...") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_saveas );
	
	menu_file->AppendSeparator();
	
	wxMenuItem* menuitem_exit;
	menuitem_exit = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Exit") ) + wxT('\t') + wxT("Alt-F4"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_exit );
	
	base_menu_bar->Append( menu_file, wxT("File") ); 
	
	menu_help = new wxMenu();
	wxMenuItem* menu_about;
	menu_about = new wxMenuItem( menu_help, wxID_ANY, wxString( wxT("About") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	menu_help->Append( menu_about );
	
	base_menu_bar->Append( menu_help, wxT("Help") ); 
	
	this->SetMenuBar( base_menu_bar );
	
	wxBoxSizer* base_sizer;
	base_sizer = new wxBoxSizer( wxVERTICAL );
	
	base_tabs = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	tab_info = new wxPanel( base_tabs, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* info_base_sizer;
	info_base_sizer = new wxGridSizer( 2, 2, 0, 0 );
	
	wxStaticBoxSizer* info_generic_sizer;
	info_generic_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_info, wxID_ANY, wxT("File information") ), wxVERTICAL );
	
	wxFlexGridSizer* info_generic_fg;
	info_generic_fg = new wxFlexGridSizer( 0, 2, 0, 0 );
	info_generic_fg->SetFlexibleDirection( wxBOTH );
	info_generic_fg->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticText* info_key_fileid;
	info_key_fileid = new wxStaticText( tab_info, wxID_ANY, wxT("File ID:"), wxDefaultPosition, wxDefaultSize, 0 );
	info_key_fileid->Wrap( -1 );
	info_generic_fg->Add( info_key_fileid, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	info_value_fileid = new wxTextCtrl( tab_info, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	info_generic_fg->Add( info_value_fileid, 0, wxALL, 5 );
	
	
	info_generic_sizer->Add( info_generic_fg, 1, wxEXPAND, 0 );
	
	
	info_base_sizer->Add( info_generic_sizer, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* info_palette_sizer;
	info_palette_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_info, wxID_ANY, wxT("Palette information") ), wxVERTICAL );
	
	wxFlexGridSizer* info_palette_fg;
	info_palette_fg = new wxFlexGridSizer( 0, 2, 0, 0 );
	info_palette_fg->SetFlexibleDirection( wxBOTH );
	info_palette_fg->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticText* info_key_palettec;
	info_key_palettec = new wxStaticText( tab_info, wxID_ANY, wxT("Palette count:"), wxDefaultPosition, wxDefaultSize, 0 );
	info_key_palettec->Wrap( -1 );
	info_palette_fg->Add( info_key_palettec, 0, wxALL, 5 );
	
	info_value_palettec = new wxStaticText( tab_info, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	info_value_palettec->Wrap( -1 );
	info_palette_fg->Add( info_value_palettec, 0, wxALL, 5 );
	
	
	info_palette_sizer->Add( info_palette_fg, 1, wxEXPAND, 0 );
	
	
	info_base_sizer->Add( info_palette_sizer, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* info_bg_sizer;
	info_bg_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_info, wxID_ANY, wxT("Background information") ), wxVERTICAL );
	
	wxFlexGridSizer* info_bg_fg;
	info_bg_fg = new wxFlexGridSizer( 0, 2, 0, 0 );
	info_bg_fg->SetFlexibleDirection( wxBOTH );
	info_bg_fg->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticText* info_key_bgw;
	info_key_bgw = new wxStaticText( tab_info, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	info_key_bgw->Wrap( -1 );
	info_bg_fg->Add( info_key_bgw, 0, wxALL, 5 );
	
	info_value_bgw = new wxStaticText( tab_info, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	info_value_bgw->Wrap( -1 );
	info_bg_fg->Add( info_value_bgw, 0, wxALL, 5 );
	
	wxStaticText* info_key_bgh;
	info_key_bgh = new wxStaticText( tab_info, wxID_ANY, wxT("Height:"), wxDefaultPosition, wxDefaultSize, 0 );
	info_key_bgh->Wrap( -1 );
	info_bg_fg->Add( info_key_bgh, 0, wxALL, 5 );
	
	info_value_bgh = new wxStaticText( tab_info, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	info_value_bgh->Wrap( -1 );
	info_bg_fg->Add( info_value_bgh, 0, wxALL, 5 );
	
	
	info_bg_sizer->Add( info_bg_fg, 1, wxEXPAND, 0 );
	
	
	info_base_sizer->Add( info_bg_sizer, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* info_anim_sizer;
	info_anim_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_info, wxID_ANY, wxT("Animations information") ), wxVERTICAL );
	
	wxFlexGridSizer* info_anim_fg;
	info_anim_fg = new wxFlexGridSizer( 0, 2, 0, 0 );
	info_anim_fg->SetFlexibleDirection( wxBOTH );
	info_anim_fg->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticText* info_key_animationc;
	info_key_animationc = new wxStaticText( tab_info, wxID_ANY, wxT("Animation count:"), wxDefaultPosition, wxDefaultSize, 0 );
	info_key_animationc->Wrap( -1 );
	info_anim_fg->Add( info_key_animationc, 0, wxALL, 5 );
	
	info_value_animationc = new wxStaticText( tab_info, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	info_value_animationc->Wrap( -1 );
	info_anim_fg->Add( info_value_animationc, 0, wxALL, 5 );
	
	
	info_anim_sizer->Add( info_anim_fg, 1, wxEXPAND, 0 );
	
	
	info_base_sizer->Add( info_anim_sizer, 1, wxALL|wxEXPAND, 5 );
	
	
	tab_info->SetSizer( info_base_sizer );
	tab_info->Layout();
	info_base_sizer->Fit( tab_info );
	base_tabs->AddPage( tab_info, wxT("Information"), true, wxNullBitmap );
	tab_background = new wxPanel( base_tabs, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* bg_base_sizer;
	bg_base_sizer = new wxFlexGridSizer( 1, 2, 0, 0 );
	bg_base_sizer->AddGrowableCol( 1 );
	bg_base_sizer->AddGrowableRow( 0 );
	bg_base_sizer->SetFlexibleDirection( wxBOTH );
	bg_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxPanel* bg_ctrl_panel;
	bg_ctrl_panel = new wxPanel( tab_background, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* bg_ctrl_sizer;
	bg_ctrl_sizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	bg_ctrl_sizer->SetFlexibleDirection( wxBOTH );
	bg_ctrl_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	bg_ctrl_load_button = new wxButton( bg_ctrl_panel, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bg_ctrl_sizer->Add( bg_ctrl_load_button, 0, wxALL|wxEXPAND, 5 );
	
	bg_ctrl_save_button = new wxButton( bg_ctrl_panel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bg_ctrl_sizer->Add( bg_ctrl_save_button, 0, wxALL|wxEXPAND, 5 );
	
	
	bg_ctrl_panel->SetSizer( bg_ctrl_sizer );
	bg_ctrl_panel->Layout();
	bg_ctrl_sizer->Fit( bg_ctrl_panel );
	bg_base_sizer->Add( bg_ctrl_panel, 1, wxEXPAND | wxALL, 0 );
	
	bg_image_panel = new wxPanel( tab_background, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bg_image_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxFlexGridSizer* bg_image_sizer;
	bg_image_sizer = new wxFlexGridSizer( 1, 1, 0, 0 );
	bg_image_sizer->AddGrowableCol( 0 );
	bg_image_sizer->AddGrowableRow( 0 );
	bg_image_sizer->SetFlexibleDirection( wxBOTH );
	bg_image_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	bg_image_bitmap = new wxStaticBitmap( bg_image_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 640,400 ), wxNO_BORDER );
	bg_image_bitmap->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bg_image_sizer->Add( bg_image_bitmap, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	
	bg_image_panel->SetSizer( bg_image_sizer );
	bg_image_panel->Layout();
	bg_image_sizer->Fit( bg_image_panel );
	bg_base_sizer->Add( bg_image_panel, 1, wxEXPAND | wxALL, 0 );
	
	
	tab_background->SetSizer( bg_base_sizer );
	tab_background->Layout();
	bg_base_sizer->Fit( tab_background );
	base_tabs->AddPage( tab_background, wxT("Background"), false, wxNullBitmap );
	tab_palette = new wxPanel( base_tabs, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* palette_base_sizer;
	palette_base_sizer = new wxFlexGridSizer( 1, 2, 0, 0 );
	palette_base_sizer->AddGrowableCol( 1 );
	palette_base_sizer->AddGrowableRow( 0 );
	palette_base_sizer->SetFlexibleDirection( wxBOTH );
	palette_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	palette_ctrl_panel = new wxPanel( tab_palette, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* palette_ctrl_sizer;
	palette_ctrl_sizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	palette_ctrl_sizer->SetFlexibleDirection( wxBOTH );
	palette_ctrl_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxArrayString palette_ctrl_select_paletteChoices;
	palette_ctrl_select_palette = new wxChoice( palette_ctrl_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, palette_ctrl_select_paletteChoices, 0 );
	palette_ctrl_select_palette->SetSelection( 0 );
	palette_ctrl_sizer->Add( palette_ctrl_select_palette, 0, wxALL, 5 );
	
	wxArrayString palette_ctrl_select_remapChoices;
	palette_ctrl_select_remap = new wxChoice( palette_ctrl_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, palette_ctrl_select_remapChoices, 0 );
	palette_ctrl_select_remap->SetSelection( 0 );
	palette_ctrl_sizer->Add( palette_ctrl_select_remap, 0, wxALL, 5 );
	
	wxStaticBoxSizer* palette_ctrl_pal_box;
	palette_ctrl_pal_box = new wxStaticBoxSizer( new wxStaticBox( palette_ctrl_panel, wxID_ANY, wxT("Selected palette") ), wxVERTICAL );
	
	palette_ctrl_load_button = new wxButton( palette_ctrl_panel, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	palette_ctrl_pal_box->Add( palette_ctrl_load_button, 0, wxALL|wxEXPAND, 5 );
	
	palette_ctrl_save_button = new wxButton( palette_ctrl_panel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	palette_ctrl_pal_box->Add( palette_ctrl_save_button, 0, wxALL|wxEXPAND, 5 );
	
	palette_ctrl_delpal_button = new wxButton( palette_ctrl_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	palette_ctrl_pal_box->Add( palette_ctrl_delpal_button, 0, wxALL|wxEXPAND, 5 );
	
	
	palette_ctrl_sizer->Add( palette_ctrl_pal_box, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* palette_ctrl_remap_box;
	palette_ctrl_remap_box = new wxStaticBoxSizer( new wxStaticBox( palette_ctrl_panel, wxID_ANY, wxT("Selected remapping") ), wxVERTICAL );
	
	palette_ctrl_delremap_button = new wxButton( palette_ctrl_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	palette_ctrl_remap_box->Add( palette_ctrl_delremap_button, 0, wxALL|wxEXPAND, 5 );
	
	
	palette_ctrl_sizer->Add( palette_ctrl_remap_box, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* palette_ctrl_manage_box;
	palette_ctrl_manage_box = new wxStaticBoxSizer( new wxStaticBox( palette_ctrl_panel, wxID_ANY, wxT("Create ... ") ), wxVERTICAL );
	
	palette_ctrl_newpal_button = new wxButton( palette_ctrl_panel, wxID_ANY, wxT("New palette"), wxDefaultPosition, wxDefaultSize, 0 );
	palette_ctrl_manage_box->Add( palette_ctrl_newpal_button, 0, wxALL|wxEXPAND, 5 );
	
	palette_ctrl_newremap_button = new wxButton( palette_ctrl_panel, wxID_ANY, wxT("New remapping"), wxDefaultPosition, wxDefaultSize, 0 );
	palette_ctrl_manage_box->Add( palette_ctrl_newremap_button, 0, wxALL|wxEXPAND, 5 );
	
	
	palette_ctrl_sizer->Add( palette_ctrl_manage_box, 1, wxALL|wxEXPAND, 5 );
	
	
	palette_ctrl_panel->SetSizer( palette_ctrl_sizer );
	palette_ctrl_panel->Layout();
	palette_ctrl_sizer->Fit( palette_ctrl_panel );
	palette_base_sizer->Add( palette_ctrl_panel, 1, wxEXPAND | wxALL, 0 );
	
	palette_grid_panel = new wxPanel( tab_palette, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	palette_grid_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	palette_grid_sizer = new wxGridSizer( 16, 16, 0, 0 );
	
	
	palette_grid_panel->SetSizer( palette_grid_sizer );
	palette_grid_panel->Layout();
	palette_grid_sizer->Fit( palette_grid_panel );
	palette_base_sizer->Add( palette_grid_panel, 1, wxEXPAND | wxALL, 0 );
	
	
	tab_palette->SetSizer( palette_base_sizer );
	tab_palette->Layout();
	palette_base_sizer->Fit( tab_palette );
	base_tabs->AddPage( tab_palette, wxT("Palettes"), false, wxNullBitmap );
	tab_animations = new wxPanel( base_tabs, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* animations_base_sizer;
	animations_base_sizer = new wxFlexGridSizer( 1, 2, 0, 0 );
	animations_base_sizer->AddGrowableCol( 1 );
	animations_base_sizer->AddGrowableRow( 0 );
	animations_base_sizer->SetFlexibleDirection( wxBOTH );
	animations_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	animations_ctrl_panel = new wxPanel( tab_animations, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* animations_ctrl_sizer;
	animations_ctrl_sizer = new wxFlexGridSizer( 2, 1, 0, 0 );
	animations_ctrl_sizer->SetFlexibleDirection( wxBOTH );
	animations_ctrl_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* animations_ctrl_anim_sizer;
	animations_ctrl_anim_sizer = new wxStaticBoxSizer( new wxStaticBox( animations_ctrl_panel, wxID_ANY, wxT("Animation/Sprite") ), wxVERTICAL );
	
	animation_ctrl_delete_button = new wxButton( animations_ctrl_panel, wxID_ANY, wxT("Delete selected"), wxDefaultPosition, wxDefaultSize, 0 );
	animations_ctrl_anim_sizer->Add( animation_ctrl_delete_button, 0, wxALL|wxEXPAND, 5 );
	
	animation_ctrl_edit_button = new wxButton( animations_ctrl_panel, wxID_ANY, wxT("Edit selected"), wxDefaultPosition, wxDefaultSize, 0 );
	animations_ctrl_anim_sizer->Add( animation_ctrl_edit_button, 0, wxALL|wxEXPAND, 5 );
	
	animation_ctrl_add_button = new wxButton( animations_ctrl_panel, wxID_ANY, wxT("Add Animation"), wxDefaultPosition, wxDefaultSize, 0 );
	animations_ctrl_anim_sizer->Add( animation_ctrl_add_button, 0, wxALL|wxEXPAND, 5 );
	
	animation_ctrl_add_sprite_button = new wxButton( animations_ctrl_panel, wxID_ANY, wxT("Add Sprite"), wxDefaultPosition, wxDefaultSize, 0 );
	animations_ctrl_anim_sizer->Add( animation_ctrl_add_sprite_button, 0, wxALL|wxEXPAND, 5 );
	
	
	animations_ctrl_sizer->Add( animations_ctrl_anim_sizer, 1, wxEXPAND, 5 );
	
	
	animations_ctrl_panel->SetSizer( animations_ctrl_sizer );
	animations_ctrl_panel->Layout();
	animations_ctrl_sizer->Fit( animations_ctrl_panel );
	animations_base_sizer->Add( animations_ctrl_panel, 1, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* animations_selection_sizer;
	animations_selection_sizer = new wxFlexGridSizer( 2, 1, 0, 0 );
	animations_selection_sizer->AddGrowableCol( 0 );
	animations_selection_sizer->AddGrowableRow( 0 );
	animations_selection_sizer->SetFlexibleDirection( wxBOTH );
	animations_selection_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	animations_tree = new wxTreeCtrl( tab_animations, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	animations_selection_sizer->Add( animations_tree, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* animation_preview_sizer;
	animation_preview_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	animation_preview_sizer->AddGrowableCol( 1 );
	animation_preview_sizer->AddGrowableRow( 0 );
	animation_preview_sizer->SetFlexibleDirection( wxBOTH );
	animation_preview_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	animations_preview_bitmap = new wxStaticBitmap( tab_animations, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 160,100 ), wxSTATIC_BORDER );
	animations_preview_bitmap->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	animation_preview_sizer->Add( animations_preview_bitmap, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	animations_preview_data = new wxHtmlWindow( tab_animations, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER );
	animation_preview_sizer->Add( animations_preview_data, 0, wxBOTTOM|wxEXPAND|wxRIGHT, 5 );
	
	
	animations_selection_sizer->Add( animation_preview_sizer, 1, wxEXPAND, 5 );
	
	
	animations_base_sizer->Add( animations_selection_sizer, 1, wxEXPAND, 5 );
	
	
	tab_animations->SetSizer( animations_base_sizer );
	tab_animations->Layout();
	animations_base_sizer->Fit( tab_animations );
	base_tabs->AddPage( tab_animations, wxT("Animations"), false, wxNullBitmap );
	
	base_sizer->Add( base_tabs, 1, wxEXPAND | wxALL, 0 );
	
	
	this->SetSizer( base_sizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( menuitem_new->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuNew ) );
	this->Connect( menuitem_open->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuOpen ) );
	this->Connect( menuitem_save->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuSave ) );
	this->Connect( menuitem_saveas->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuSaveAs ) );
	this->Connect( menuitem_exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuExit ) );
	this->Connect( menu_about->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuAbout ) );
	bg_ctrl_load_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onBackgroundLoad ), NULL, this );
	bg_ctrl_save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onBackgroundSave ), NULL, this );
	palette_ctrl_select_palette->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseFrame::onPaletteChoice ), NULL, this );
	palette_ctrl_select_remap->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseFrame::onRemapChoice ), NULL, this );
	palette_ctrl_load_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onPaletteLoad ), NULL, this );
	palette_ctrl_save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onPaletteSave ), NULL, this );
	palette_ctrl_delpal_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onPaletteDelete ), NULL, this );
	palette_ctrl_delremap_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onOverlayDelete ), NULL, this );
	palette_ctrl_newpal_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onNewPalette ), NULL, this );
	palette_ctrl_newremap_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onNewOverlay ), NULL, this );
	animation_ctrl_delete_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onAnimationDelete ), NULL, this );
	animation_ctrl_edit_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onAnimationEdit ), NULL, this );
	animation_ctrl_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onAnimationAdd ), NULL, this );
	animation_ctrl_add_sprite_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onSpriteAdd ), NULL, this );
	animations_tree->Connect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( BaseFrame::onAnimTreeContextMenu ), NULL, this );
	animations_tree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( BaseFrame::onAnimTreeItemSelect ), NULL, this );
}

BaseFrame::~BaseFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuNew ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuOpen ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuSaveAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuExit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BaseFrame::onMenuAbout ) );
	bg_ctrl_load_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onBackgroundLoad ), NULL, this );
	bg_ctrl_save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onBackgroundSave ), NULL, this );
	palette_ctrl_select_palette->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseFrame::onPaletteChoice ), NULL, this );
	palette_ctrl_select_remap->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseFrame::onRemapChoice ), NULL, this );
	palette_ctrl_load_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onPaletteLoad ), NULL, this );
	palette_ctrl_save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onPaletteSave ), NULL, this );
	palette_ctrl_delpal_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onPaletteDelete ), NULL, this );
	palette_ctrl_delremap_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onOverlayDelete ), NULL, this );
	palette_ctrl_newpal_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onNewPalette ), NULL, this );
	palette_ctrl_newremap_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onNewOverlay ), NULL, this );
	animation_ctrl_delete_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onAnimationDelete ), NULL, this );
	animation_ctrl_edit_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onAnimationEdit ), NULL, this );
	animation_ctrl_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onAnimationAdd ), NULL, this );
	animation_ctrl_add_sprite_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFrame::onSpriteAdd ), NULL, this );
	animations_tree->Disconnect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( BaseFrame::onAnimTreeContextMenu ), NULL, this );
	animations_tree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( BaseFrame::onAnimTreeItemSelect ), NULL, this );
	
}
