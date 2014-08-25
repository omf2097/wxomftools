///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "shared.h"

///////////////////////////////////////////////////////////////////////////

AnimationBaseDialog::AnimationBaseDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* animation_base_sizer;
	animation_base_sizer = new wxFlexGridSizer( 2, 1, 0, 0 );
	animation_base_sizer->AddGrowableCol( 0 );
	animation_base_sizer->AddGrowableRow( 0 );
	animation_base_sizer->SetFlexibleDirection( wxBOTH );
	animation_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ani_base_notebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* tab_settings_sizer;
	tab_settings_sizer = new wxGridBagSizer( 5, 5 );
	tab_settings_sizer->SetFlexibleDirection( wxBOTH );
	tab_settings_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* tab_settings_misc_sizer;
	tab_settings_misc_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_settings, wxID_ANY, wxT("Miscellaneous") ), wxVERTICAL );
	
	wxFlexGridSizer* tab_settings_misc_in_sizer1;
	tab_settings_misc_in_sizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	tab_settings_misc_in_sizer1->SetFlexibleDirection( wxBOTH );
	tab_settings_misc_in_sizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	static_chain_if_hit = new wxStaticText( tab_settings, wxID_ANY, wxT("Chain if hit"), wxDefaultPosition, wxDefaultSize, 0 );
	static_chain_if_hit->Wrap( -1 );
	tab_settings_misc_in_sizer1->Add( static_chain_if_hit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	chain_if_hit_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings_misc_in_sizer1->Add( chain_if_hit_field, 0, wxALL, 5 );
	
	static_chain_if_not_hit = new wxStaticText( tab_settings, wxID_ANY, wxT("Chain if not hit"), wxDefaultPosition, wxDefaultSize, 0 );
	static_chain_if_not_hit->Wrap( -1 );
	tab_settings_misc_in_sizer1->Add( static_chain_if_not_hit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	chain_if_not_hit_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings_misc_in_sizer1->Add( chain_if_not_hit_field, 0, wxALL, 5 );
	
	static_load_on_start = new wxStaticText( tab_settings, wxID_ANY, wxT("Load on Start"), wxDefaultPosition, wxDefaultSize, 0 );
	static_load_on_start->Wrap( -1 );
	tab_settings_misc_in_sizer1->Add( static_load_on_start, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	load_on_start_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings_misc_in_sizer1->Add( load_on_start_field, 0, wxALL, 5 );
	
	static_probability = new wxStaticText( tab_settings, wxID_ANY, wxT("Probability"), wxDefaultPosition, wxDefaultSize, 0 );
	static_probability->Wrap( -1 );
	tab_settings_misc_in_sizer1->Add( static_probability, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	probability_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings_misc_in_sizer1->Add( probability_field, 0, wxALL, 5 );
	
	static_hazard_damage = new wxStaticText( tab_settings, wxID_ANY, wxT("Hazard Damage"), wxDefaultPosition, wxDefaultSize, 0 );
	static_hazard_damage->Wrap( -1 );
	tab_settings_misc_in_sizer1->Add( static_hazard_damage, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	hazard_damage_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings_misc_in_sizer1->Add( hazard_damage_field, 0, wxALL, 5 );
	
	static_start_x = new wxStaticText( tab_settings, wxID_ANY, wxT("Start X"), wxDefaultPosition, wxDefaultSize, 0 );
	static_start_x->Wrap( -1 );
	tab_settings_misc_in_sizer1->Add( static_start_x, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	start_x_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings_misc_in_sizer1->Add( start_x_field, 0, wxALL, 5 );
	
	static_start_y = new wxStaticText( tab_settings, wxID_ANY, wxT("Start Y"), wxDefaultPosition, wxDefaultSize, 0 );
	static_start_y->Wrap( -1 );
	tab_settings_misc_in_sizer1->Add( static_start_y, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	start_y_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings_misc_in_sizer1->Add( start_y_field, 0, wxALL, 5 );
	
	
	tab_settings_misc_sizer->Add( tab_settings_misc_in_sizer1, 1, wxEXPAND, 5 );
	
	
	tab_settings_sizer->Add( tab_settings_misc_sizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* tab_settings_string_sizer;
	tab_settings_string_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_settings, wxID_ANY, wxT("Strings") ), wxVERTICAL );
	
	wxFlexGridSizer* tab_settings_misc_in_sizer;
	tab_settings_misc_in_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	tab_settings_misc_in_sizer->AddGrowableCol( 1 );
	tab_settings_misc_in_sizer->SetFlexibleDirection( wxBOTH );
	tab_settings_misc_in_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	static_anim_string = new wxStaticText( tab_settings, wxID_ANY, wxT("Animation string"), wxDefaultPosition, wxDefaultSize, 0 );
	static_anim_string->Wrap( -1 );
	tab_settings_misc_in_sizer->Add( static_anim_string, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	anim_string_field = new wxTextCtrl( tab_settings, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	anim_string_field->SetMinSize( wxSize( -1,160 ) );
	
	tab_settings_misc_in_sizer->Add( anim_string_field, 0, wxALL|wxEXPAND, 5 );
	
	
	tab_settings_string_sizer->Add( tab_settings_misc_in_sizer, 1, wxEXPAND, 5 );
	
	
	tab_settings_sizer->Add( tab_settings_string_sizer, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	tab_settings_sizer->AddGrowableCol( 1 );
	
	tab_settings->SetSizer( tab_settings_sizer );
	tab_settings->Layout();
	tab_settings_sizer->Fit( tab_settings );
	ani_base_notebook->AddPage( tab_settings, wxT("Settings"), true, wxNullBitmap );
	tab_animstr = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	ani_base_notebook->AddPage( tab_animstr, wxT("Animation String"), false, wxNullBitmap );
	tab_footerstr = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	ani_base_notebook->AddPage( tab_footerstr, wxT("Footer String"), false, wxNullBitmap );
	tab_extrastr = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	ani_base_notebook->AddPage( tab_extrastr, wxT("Extra Strings"), false, wxNullBitmap );
	tab_coords = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	ani_base_notebook->AddPage( tab_coords, wxT("Coordinates"), false, wxNullBitmap );
	tab_sprites = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	ani_base_notebook->AddPage( tab_sprites, wxT("Sprites"), false, wxNullBitmap );
	
	animation_base_sizer->Add( ani_base_notebook, 1, wxEXPAND | wxALL, 0 );
	
	ani_base_buttons = new wxStdDialogButtonSizer();
	ani_base_buttonsOK = new wxButton( this, wxID_OK );
	ani_base_buttons->AddButton( ani_base_buttonsOK );
	ani_base_buttonsCancel = new wxButton( this, wxID_CANCEL );
	ani_base_buttons->AddButton( ani_base_buttonsCancel );
	ani_base_buttons->Realize();
	
	animation_base_sizer->Add( ani_base_buttons, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	this->SetSizer( animation_base_sizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

AnimationBaseDialog::~AnimationBaseDialog()
{
}

SpriteBaseDialog::SpriteBaseDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* sprite_base_sizer;
	sprite_base_sizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	sprite_base_sizer->AddGrowableCol( 0 );
	sprite_base_sizer->AddGrowableRow( 0 );
	sprite_base_sizer->SetFlexibleDirection( wxBOTH );
	sprite_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	sprite_base_notebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings = new wxPanel( sprite_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* tab_settings_base_sizer;
	tab_settings_base_sizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	tab_settings_base_sizer->AddGrowableCol( 0 );
	tab_settings_base_sizer->SetFlexibleDirection( wxBOTH );
	tab_settings_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sprite_settings_sizer;
	sprite_settings_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_settings, wxID_ANY, wxT("General settings") ), wxVERTICAL );
	
	wxFlexGridSizer* settings_int_sizer;
	settings_int_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	settings_int_sizer->SetFlexibleDirection( wxBOTH );
	settings_int_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	static_pos_x = new wxStaticText( tab_settings, wxID_ANY, wxT("Position X"), wxDefaultPosition, wxDefaultSize, 0 );
	static_pos_x->Wrap( -1 );
	settings_int_sizer->Add( static_pos_x, 0, wxALL, 5 );
	
	pos_x_field = new wxTextCtrl( tab_settings, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	pos_x_field->SetMaxLength( 3 ); 
	settings_int_sizer->Add( pos_x_field, 0, wxALL, 5 );
	
	static_pos_y = new wxStaticText( tab_settings, wxID_ANY, wxT("Position Y"), wxDefaultPosition, wxDefaultSize, 0 );
	static_pos_y->Wrap( -1 );
	settings_int_sizer->Add( static_pos_y, 0, wxALL, 5 );
	
	pos_y_field = new wxTextCtrl( tab_settings, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	pos_y_field->SetMaxLength( 3 ); 
	settings_int_sizer->Add( pos_y_field, 0, wxALL, 5 );
	
	static_index = new wxStaticText( tab_settings, wxID_ANY, wxT("Index"), wxDefaultPosition, wxDefaultSize, 0 );
	static_index->Wrap( -1 );
	settings_int_sizer->Add( static_index, 0, wxALL, 5 );
	
	index_field = new wxTextCtrl( tab_settings, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	index_field->SetMaxLength( 3 ); 
	settings_int_sizer->Add( index_field, 0, wxALL, 5 );
	
	static_missing = new wxStaticText( tab_settings, wxID_ANY, wxT("Missing"), wxDefaultPosition, wxDefaultSize, 0 );
	static_missing->Wrap( -1 );
	settings_int_sizer->Add( static_missing, 0, wxALL, 5 );
	
	missing_field = new wxTextCtrl( tab_settings, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	missing_field->SetMaxLength( 1 ); 
	settings_int_sizer->Add( missing_field, 0, wxALL, 5 );
	
	
	sprite_settings_sizer->Add( settings_int_sizer, 1, wxEXPAND, 5 );
	
	
	tab_settings_base_sizer->Add( sprite_settings_sizer, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sprite_info_sizer;
	sprite_info_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_settings, wxID_ANY, wxT("Sprite information") ), wxVERTICAL );
	
	wxFlexGridSizer* sprite_int_sizer;
	sprite_int_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	sprite_int_sizer->SetFlexibleDirection( wxBOTH );
	sprite_int_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	static_width = new wxStaticText( tab_settings, wxID_ANY, wxT("Width"), wxDefaultPosition, wxDefaultSize, 0 );
	static_width->Wrap( -1 );
	sprite_int_sizer->Add( static_width, 0, wxALL, 5 );
	
	width_field = new wxStaticText( tab_settings, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	width_field->Wrap( -1 );
	sprite_int_sizer->Add( width_field, 0, wxALL, 5 );
	
	static_height = new wxStaticText( tab_settings, wxID_ANY, wxT("Height"), wxDefaultPosition, wxDefaultSize, 0 );
	static_height->Wrap( -1 );
	sprite_int_sizer->Add( static_height, 0, wxALL, 5 );
	
	height_field = new wxStaticText( tab_settings, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	height_field->Wrap( -1 );
	sprite_int_sizer->Add( height_field, 0, wxALL, 5 );
	
	static_size = new wxStaticText( tab_settings, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	static_size->Wrap( -1 );
	sprite_int_sizer->Add( static_size, 0, wxALL, 5 );
	
	m_staticText18 = new wxStaticText( tab_settings, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	sprite_int_sizer->Add( m_staticText18, 0, wxALL, 5 );
	
	
	sprite_info_sizer->Add( sprite_int_sizer, 1, wxEXPAND, 5 );
	
	
	tab_settings_base_sizer->Add( sprite_info_sizer, 1, wxALL|wxEXPAND, 5 );
	
	
	tab_settings->SetSizer( tab_settings_base_sizer );
	tab_settings->Layout();
	tab_settings_base_sizer->Fit( tab_settings );
	sprite_base_notebook->AddPage( tab_settings, wxT("Settings"), true, wxNullBitmap );
	tab_sprite = new wxPanel( sprite_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* tab_sprite_base_sizer;
	tab_sprite_base_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	tab_sprite_base_sizer->AddGrowableCol( 1 );
	tab_sprite_base_sizer->AddGrowableRow( 0 );
	tab_sprite_base_sizer->SetFlexibleDirection( wxBOTH );
	tab_sprite_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	tab_sprite_ctrl_panel = new wxPanel( tab_sprite, wxID_ANY, wxDefaultPosition, wxSize( 120,-1 ), wxTAB_TRAVERSAL );
	wxFlexGridSizer* tab_sprite_ctrl_sizer;
	tab_sprite_ctrl_sizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	tab_sprite_ctrl_sizer->AddGrowableCol( 0 );
	tab_sprite_ctrl_sizer->SetFlexibleDirection( wxBOTH );
	tab_sprite_ctrl_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* tab_sprite_sp_int_sizer;
	tab_sprite_sp_int_sizer = new wxStaticBoxSizer( new wxStaticBox( tab_sprite_ctrl_panel, wxID_ANY, wxT("PNG") ), wxVERTICAL );
	
	import_sprite_button = new wxButton( tab_sprite_ctrl_panel, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	tab_sprite_sp_int_sizer->Add( import_sprite_button, 0, wxALL|wxEXPAND, 5 );
	
	export_sprite_button = new wxButton( tab_sprite_ctrl_panel, wxID_ANY, wxT("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	tab_sprite_sp_int_sizer->Add( export_sprite_button, 0, wxALL|wxEXPAND, 5 );
	
	
	tab_sprite_ctrl_sizer->Add( tab_sprite_sp_int_sizer, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	
	tab_sprite_ctrl_panel->SetSizer( tab_sprite_ctrl_sizer );
	tab_sprite_ctrl_panel->Layout();
	tab_sprite_base_sizer->Add( tab_sprite_ctrl_panel, 1, wxALL|wxEXPAND, 0 );
	
	tab_sprite_image_panel = new wxPanel( tab_sprite, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	tab_sprite_image_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxBoxSizer* tab_sprite_image_sizer;
	tab_sprite_image_sizer = new wxBoxSizer( wxVERTICAL );
	
	sprite_image = new wxStaticBitmap( tab_sprite_image_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 640,400 ), 0 );
	sprite_image->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	tab_sprite_image_sizer->Add( sprite_image, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	tab_sprite_image_panel->SetSizer( tab_sprite_image_sizer );
	tab_sprite_image_panel->Layout();
	tab_sprite_image_sizer->Fit( tab_sprite_image_panel );
	tab_sprite_base_sizer->Add( tab_sprite_image_panel, 1, wxALL|wxEXPAND, 5 );
	
	
	tab_sprite->SetSizer( tab_sprite_base_sizer );
	tab_sprite->Layout();
	tab_sprite_base_sizer->Fit( tab_sprite );
	sprite_base_notebook->AddPage( tab_sprite, wxT("Sprite"), false, wxNullBitmap );
	
	sprite_base_sizer->Add( sprite_base_notebook, 1, wxEXPAND | wxALL, 0 );
	
	sprite_base_buttons = new wxStdDialogButtonSizer();
	sprite_base_buttonsOK = new wxButton( this, wxID_OK );
	sprite_base_buttons->AddButton( sprite_base_buttonsOK );
	sprite_base_buttonsCancel = new wxButton( this, wxID_CANCEL );
	sprite_base_buttons->AddButton( sprite_base_buttonsCancel );
	sprite_base_buttons->Realize();
	
	sprite_base_sizer->Add( sprite_base_buttons, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	this->SetSizer( sprite_base_sizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	import_sprite_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SpriteBaseDialog::onImportButton ), NULL, this );
	export_sprite_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SpriteBaseDialog::onExportButton ), NULL, this );
}

SpriteBaseDialog::~SpriteBaseDialog()
{
	// Disconnect Events
	import_sprite_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SpriteBaseDialog::onImportButton ), NULL, this );
	export_sprite_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SpriteBaseDialog::onExportButton ), NULL, this );
	
}

SpriteImportBaseDialog::SpriteImportBaseDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* spriteimport_base_sizer;
	spriteimport_base_sizer = new wxFlexGridSizer( 2, 1, 0, 0 );
	spriteimport_base_sizer->AddGrowableCol( 0 );
	spriteimport_base_sizer->AddGrowableRow( 0 );
	spriteimport_base_sizer->SetFlexibleDirection( wxBOTH );
	spriteimport_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* spriteimport_top_sizer;
	spriteimport_top_sizer = new wxFlexGridSizer( 1, 2, 0, 0 );
	spriteimport_top_sizer->AddGrowableCol( 1 );
	spriteimport_top_sizer->AddGrowableRow( 0 );
	spriteimport_top_sizer->SetFlexibleDirection( wxBOTH );
	spriteimport_top_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* import_file_sizer;
	import_file_sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("File") ), wxVERTICAL );
	
	file_field = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a PNG file"), wxT("*.PNG"), wxDefaultPosition, wxDefaultSize, wxFLP_CHANGE_DIR|wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	import_file_sizer->Add( file_field, 0, wxALL, 5 );
	
	
	fgSizer13->Add( import_file_sizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* import_config_sizer;
	import_config_sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Transparency Index") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer14;
	fgSizer14 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer14->SetFlexibleDirection( wxBOTH );
	fgSizer14->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	transparency_field = new wxTextCtrl( this, wxID_ANY, wxT("-1"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	transparency_field->SetMaxLength( 3 ); 
	fgSizer14->Add( transparency_field, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	preview_button = new wxButton( this, wxID_ANY, wxT("Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer14->Add( preview_button, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxTOP, 5 );
	
	
	import_config_sizer->Add( fgSizer14, 1, wxEXPAND, 5 );
	
	
	fgSizer13->Add( import_config_sizer, 1, wxEXPAND, 5 );
	
	
	spriteimport_top_sizer->Add( fgSizer13, 1, wxEXPAND, 5 );
	
	spriteimport_image_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	spriteimport_image_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxBoxSizer* spriteimport_image_panel;
	spriteimport_image_panel = new wxBoxSizer( wxVERTICAL );
	
	sprite_image = new wxStaticBitmap( spriteimport_image_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 320,200 ), 0 );
	spriteimport_image_panel->Add( sprite_image, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	spriteimport_image_panel1->SetSizer( spriteimport_image_panel );
	spriteimport_image_panel1->Layout();
	spriteimport_image_panel->Fit( spriteimport_image_panel1 );
	spriteimport_top_sizer->Add( spriteimport_image_panel1, 1, wxEXPAND | wxALL, 3 );
	
	
	spriteimport_base_sizer->Add( spriteimport_top_sizer, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	
	spriteimport_base_sizer->Add( m_sdbSizer3, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	this->SetSizer( spriteimport_base_sizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	file_field->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( SpriteImportBaseDialog::onFileChange ), NULL, this );
	transparency_field->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SpriteImportBaseDialog::onIndexChange ), NULL, this );
	preview_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SpriteImportBaseDialog::onPreviewClick ), NULL, this );
}

SpriteImportBaseDialog::~SpriteImportBaseDialog()
{
	// Disconnect Events
	file_field->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( SpriteImportBaseDialog::onFileChange ), NULL, this );
	transparency_field->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SpriteImportBaseDialog::onIndexChange ), NULL, this );
	preview_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SpriteImportBaseDialog::onPreviewClick ), NULL, this );
	
}
