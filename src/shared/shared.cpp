///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 26 2014)
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
	
	animation_base_sizer->Add( ani_base_notebook, 1, wxEXPAND | wxALL, 0 );
	
	ani_base_buttons = new wxStdDialogButtonSizer();
	ani_base_buttonsOK = new wxButton( this, wxID_OK );
	ani_base_buttons->AddButton( ani_base_buttonsOK );
	ani_base_buttonsCancel = new wxButton( this, wxID_CANCEL );
	ani_base_buttons->AddButton( ani_base_buttonsCancel );
	ani_base_buttons->Realize();
	
	animation_base_sizer->Add( ani_base_buttons, 1, wxEXPAND, 5 );
	
	
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
	sprite_base_sizer = new wxFlexGridSizer( 2, 1, 0, 0 );
	sprite_base_sizer->AddGrowableCol( 0 );
	sprite_base_sizer->AddGrowableRow( 0 );
	sprite_base_sizer->SetFlexibleDirection( wxBOTH );
	sprite_base_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	sprite_base_notebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	tab_settings = new wxPanel( sprite_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sprite_base_notebook->AddPage( tab_settings, wxT("Settings"), true, wxNullBitmap );
	tab_sprite = new wxPanel( sprite_base_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sprite_base_notebook->AddPage( tab_sprite, wxT("Sprite"), false, wxNullBitmap );
	
	sprite_base_sizer->Add( sprite_base_notebook, 1, wxEXPAND | wxALL, 0 );
	
	sprite_base_buttons = new wxStdDialogButtonSizer();
	sprite_base_buttonsOK = new wxButton( this, wxID_OK );
	sprite_base_buttons->AddButton( sprite_base_buttonsOK );
	sprite_base_buttonsCancel = new wxButton( this, wxID_CANCEL );
	sprite_base_buttons->AddButton( sprite_base_buttonsCancel );
	sprite_base_buttons->Realize();
	
	sprite_base_sizer->Add( sprite_base_buttons, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( sprite_base_sizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

SpriteBaseDialog::~SpriteBaseDialog()
{
}
