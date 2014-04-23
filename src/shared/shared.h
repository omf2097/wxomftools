///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 26 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SHARED_H__
#define __SHARED_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/gbsizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/aui/auibook.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class AnimationBaseDialog
///////////////////////////////////////////////////////////////////////////////
class AnimationBaseDialog : public wxDialog 
{
	private:
	
	protected:
		wxAuiNotebook* ani_base_notebook;
		wxPanel* tab_settings;
		wxStaticText* static_chain_if_hit;
		wxTextCtrl* chain_if_hit_field;
		wxStaticText* static_chain_if_not_hit;
		wxTextCtrl* chain_if_not_hit_field;
		wxStaticText* static_load_on_start;
		wxTextCtrl* load_on_start_field;
		wxStaticText* static_probability;
		wxTextCtrl* probability_field;
		wxStaticText* static_hazard_damage;
		wxTextCtrl* hazard_damage_field;
		wxStaticText* static_start_x;
		wxTextCtrl* start_x_field;
		wxStaticText* static_start_y;
		wxTextCtrl* start_y_field;
		wxStaticText* static_anim_string;
		wxTextCtrl* anim_string_field;
		wxStdDialogButtonSizer* ani_base_buttons;
		wxButton* ani_base_buttonsOK;
		wxButton* ani_base_buttonsCancel;
	
	public:
		
		AnimationBaseDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Animation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AnimationBaseDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SpriteBaseDialog
///////////////////////////////////////////////////////////////////////////////
class SpriteBaseDialog : public wxDialog 
{
	private:
	
	protected:
		wxAuiNotebook* sprite_base_notebook;
		wxPanel* tab_settings;
		wxPanel* tab_sprite;
		wxStdDialogButtonSizer* sprite_base_buttons;
		wxButton* sprite_base_buttonsOK;
		wxButton* sprite_base_buttonsCancel;
	
	public:
		
		SpriteBaseDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sprite"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SpriteBaseDialog();
	
};

#endif //__SHARED_H__
