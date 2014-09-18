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
	
	
	tab_settings_sizer->AddGrowableCol( 1 );
	
	tab_settings->SetSizer( tab_settings_sizer );
	tab_settings->Layout();
	tab_settings_sizer->Fit( tab_settings );
	ani_base_notebook->AddPage( tab_settings, wxT("Settings"), false, wxNullBitmap );
	tab_strings = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer15;
	fgSizer15 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer15->AddGrowableCol( 2 );
	fgSizer15->AddGrowableRow( 0 );
	fgSizer15->SetFlexibleDirection( wxBOTH );
	fgSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel13 = new wxPanel( tab_strings, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer16;
	fgSizer16 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer16->AddGrowableCol( 0 );
	fgSizer16->AddGrowableRow( 1 );
	fgSizer16->SetFlexibleDirection( wxBOTH );
	fgSizer16->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText19 = new wxStaticText( m_panel13, wxID_ANY, wxT("Strings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer16->Add( m_staticText19, 0, wxALL, 3 );
	
	string_tree = new wxTreeCtrl( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	string_tree->SetMinSize( wxSize( 150,-1 ) );
	
	fgSizer16->Add( string_tree, 0, wxALL|wxEXPAND, 3 );
	
	
	m_panel13->SetSizer( fgSizer16 );
	m_panel13->Layout();
	fgSizer16->Fit( m_panel13 );
	fgSizer15->Add( m_panel13, 1, wxEXPAND | wxALL, 5 );
	
	m_panel14 = new wxPanel( tab_strings, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer17->AddGrowableCol( 0 );
	fgSizer17->AddGrowableRow( 1 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText20 = new wxStaticText( m_panel14, wxID_ANY, wxT("Frames"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	fgSizer17->Add( m_staticText20, 0, wxALL, 3 );
	
	frame_tree = new wxTreeCtrl( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	frame_tree->SetMinSize( wxSize( 150,-1 ) );
	
	fgSizer17->Add( frame_tree, 0, wxALL|wxEXPAND, 3 );
	
	
	m_panel14->SetSizer( fgSizer17 );
	m_panel14->Layout();
	fgSizer17->Fit( m_panel14 );
	fgSizer15->Add( m_panel14, 1, wxEXPAND | wxALL, 5 );
	
	m_panel15 = new wxPanel( tab_strings, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer18->AddGrowableCol( 0 );
	fgSizer18->AddGrowableRow( 3 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText35 = new wxStaticText( m_panel15, wxID_ANY, wxT("Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	fgSizer18->Add( m_staticText35, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 1, 4, 0, 0 );
	fgSizer22->AddGrowableCol( 1 );
	fgSizer22->AddGrowableCol( 3 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26 = new wxStaticText( m_panel15, wxID_ANY, wxT("Sprite Number:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer22->Add( m_staticText26, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	frameSpriteNumberField = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer22->Add( frameSpriteNumberField, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( m_panel15, wxID_ANY, wxT("Duration:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer22->Add( m_staticText27, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	frameSpriteDurationField = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer22->Add( frameSpriteDurationField, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer18->Add( fgSizer22, 1, wxEXPAND, 5 );
	
	m_staticText21 = new wxStaticText( m_panel15, wxID_ANY, wxT("Tags"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer18->Add( m_staticText21, 0, wxALL, 3 );
	
	tag_grid = new wxGrid( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER );
	
	// Grid
	tag_grid->CreateGrid( 0, 2 );
	tag_grid->EnableEditing( true );
	tag_grid->EnableGridLines( true );
	tag_grid->EnableDragGridSize( false );
	tag_grid->SetMargins( 0, 0 );
	
	// Columns
	tag_grid->EnableDragColMove( false );
	tag_grid->EnableDragColSize( true );
	tag_grid->SetColLabelSize( 30 );
	tag_grid->SetColLabelValue( 0, wxT("Tag") );
	tag_grid->SetColLabelValue( 1, wxT("Value") );
	tag_grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	tag_grid->AutoSizeRows();
	tag_grid->EnableDragRowSize( true );
	tag_grid->SetRowLabelSize( 80 );
	tag_grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	tag_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer18->Add( tag_grid, 0, wxALL|wxEXPAND, 3 );
	
	
	m_panel15->SetSizer( fgSizer18 );
	m_panel15->Layout();
	fgSizer18->Fit( m_panel15 );
	fgSizer15->Add( m_panel15, 1, wxEXPAND | wxALL, 5 );
	
	
	tab_strings->SetSizer( fgSizer15 );
	tab_strings->Layout();
	fgSizer15->Fit( tab_strings );
	ani_base_notebook->AddPage( tab_strings, wxT("Strings"), true, wxNullBitmap );
	tab_coords = new wxPanel( ani_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* coord_base_sizer;
	coord_base_sizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	coord_base_sizer->AddGrowableCol( 2 );
	coord_base_sizer->AddGrowableRow( 0 );
	coord_base_sizer->SetFlexibleDirection( wxBOTH );
	coord_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel131 = new wxPanel( tab_coords, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer191;
	fgSizer191 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer191->AddGrowableCol( 0 );
	fgSizer191->AddGrowableRow( 1 );
	fgSizer191->SetFlexibleDirection( wxBOTH );
	fgSizer191->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText22 = new wxStaticText( m_panel131, wxID_ANY, wxT("Sprite"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer191->Add( m_staticText22, 0, wxALL, 3 );
	
	sprite_tree = new wxTreeCtrl( m_panel131, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), wxTR_DEFAULT_STYLE );
	fgSizer191->Add( sprite_tree, 0, wxALL|wxEXPAND, 3 );
	
	
	m_panel131->SetSizer( fgSizer191 );
	m_panel131->Layout();
	fgSizer191->Fit( m_panel131 );
	coord_base_sizer->Add( m_panel131, 1, wxEXPAND | wxALL, 5 );
	
	m_panel141 = new wxPanel( tab_coords, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer20;
	fgSizer20 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer20->AddGrowableCol( 0 );
	fgSizer20->AddGrowableRow( 1 );
	fgSizer20->SetFlexibleDirection( wxBOTH );
	fgSizer20->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText23 = new wxStaticText( m_panel141, wxID_ANY, wxT("Coordinates"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer20->Add( m_staticText23, 0, wxALL, 3 );
	
	coord_grid = new wxGrid( m_panel141, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	coord_grid->CreateGrid( 0, 2 );
	coord_grid->EnableEditing( true );
	coord_grid->EnableGridLines( true );
	coord_grid->EnableDragGridSize( false );
	coord_grid->SetMargins( 0, 0 );
	
	// Columns
	coord_grid->EnableDragColMove( false );
	coord_grid->EnableDragColSize( true );
	coord_grid->SetColLabelSize( 30 );
	coord_grid->SetColLabelValue( 0, wxT("X") );
	coord_grid->SetColLabelValue( 1, wxT("Y") );
	coord_grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	coord_grid->EnableDragRowSize( true );
	coord_grid->SetRowLabelSize( 0 );
	coord_grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	coord_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer20->Add( coord_grid, 0, wxALL|wxEXPAND, 3 );
	
	
	m_panel141->SetSizer( fgSizer20 );
	m_panel141->Layout();
	fgSizer20->Fit( m_panel141 );
	coord_base_sizer->Add( m_panel141, 1, wxEXPAND | wxALL, 5 );
	
	m_panel151 = new wxPanel( tab_coords, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer21->AddGrowableCol( 0 );
	fgSizer21->AddGrowableRow( 1 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText24 = new wxStaticText( m_panel151, wxID_ANY, wxT("Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer21->Add( m_staticText24, 0, wxALL, 3 );
	
	m_panel16 = new wxPanel( m_panel151, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel16->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	coord_preview = new wxStaticBitmap( m_panel16, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( coord_preview, 0, wxALL, 5 );
	
	
	m_panel16->SetSizer( bSizer3 );
	m_panel16->Layout();
	bSizer3->Fit( m_panel16 );
	fgSizer21->Add( m_panel16, 1, wxEXPAND | wxALL, 3 );
	
	
	m_panel151->SetSizer( fgSizer21 );
	m_panel151->Layout();
	fgSizer21->Fit( m_panel151 );
	coord_base_sizer->Add( m_panel151, 1, wxEXPAND | wxALL, 5 );
	
	
	tab_coords->SetSizer( coord_base_sizer );
	tab_coords->Layout();
	coord_base_sizer->Fit( tab_coords );
	ani_base_notebook->AddPage( tab_coords, wxT("Coordinates"), false, wxNullBitmap );
	
	animation_base_sizer->Add( ani_base_notebook, 1, wxEXPAND | wxALL, 0 );
	
	ani_base_buttons = new wxStdDialogButtonSizer();
	ani_base_buttonsOK = new wxButton( this, wxID_OK );
	ani_base_buttons->AddButton( ani_base_buttonsOK );
	ani_base_buttonsCancel = new wxButton( this, wxID_CANCEL );
	ani_base_buttons->AddButton( ani_base_buttonsCancel );
	ani_base_buttons->Realize();
	
	animation_base_sizer->Add( ani_base_buttons, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( animation_base_sizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	string_tree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( AnimationBaseDialog::onStringSelected ), NULL, this );
	frame_tree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( AnimationBaseDialog::onStringFrameSelected ), NULL, this );
	frameSpriteNumberField->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( AnimationBaseDialog::onFrameSpriteChanged ), NULL, this );
	frameSpriteDurationField->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( AnimationBaseDialog::onFrameDurationChanged ), NULL, this );
	tag_grid->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( AnimationBaseDialog::onStringTagChange ), NULL, this );
}

AnimationBaseDialog::~AnimationBaseDialog()
{
	// Disconnect Events
	string_tree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( AnimationBaseDialog::onStringSelected ), NULL, this );
	frame_tree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( AnimationBaseDialog::onStringFrameSelected ), NULL, this );
	frameSpriteNumberField->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( AnimationBaseDialog::onFrameSpriteChanged ), NULL, this );
	frameSpriteDurationField->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( AnimationBaseDialog::onFrameDurationChanged ), NULL, this );
	tag_grid->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( AnimationBaseDialog::onStringTagChange ), NULL, this );
	
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
	
	sprite_base_sizer->Add( sprite_base_buttons, 1, wxALL|wxEXPAND, 5 );
	
	
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
	
	
	spriteimport_base_sizer->Add( spriteimport_top_sizer, 1, wxEXPAND, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	
	spriteimport_base_sizer->Add( m_sdbSizer3, 1, wxALL|wxEXPAND, 5 );
	
	
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
