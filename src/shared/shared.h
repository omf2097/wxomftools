///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
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
#include <wx/treectrl.h>
#include <wx/grid.h>
#include <wx/statbmp.h>
#include <wx/aui/auibook.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>

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
		wxPanel* tab_strings;
		wxPanel* m_panel13;
		wxStaticText* m_staticText19;
		wxTreeCtrl* string_tree;
		wxPanel* m_panel14;
		wxStaticText* m_staticText20;
		wxTreeCtrl* frame_tree;
		wxPanel* m_panel15;
		wxStaticText* m_staticText35;
		wxStaticText* m_staticText26;
		wxTextCtrl* frameSpriteNumberField;
		wxStaticText* m_staticText27;
		wxTextCtrl* frameSpriteDurationField;
		wxStaticText* m_staticText21;
		wxGrid* tag_grid;
		wxPanel* tab_coords;
		wxPanel* m_panel131;
		wxStaticText* m_staticText22;
		wxTreeCtrl* sprite_tree;
		wxPanel* m_panel141;
		wxStaticText* m_staticText23;
		wxGrid* coord_grid;
		wxPanel* m_panel151;
		wxStaticText* m_staticText24;
		wxPanel* m_panel16;
		wxStaticBitmap* coord_preview;
		wxStdDialogButtonSizer* ani_base_buttons;
		wxButton* ani_base_buttonsOK;
		wxButton* ani_base_buttonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onStringSelected( wxTreeEvent& event ) { event.Skip(); }
		virtual void onStringFrameSelected( wxTreeEvent& event ) { event.Skip(); }
		virtual void onFrameSpriteChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFrameDurationChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void onStringTagChange( wxGridEvent& event ) { event.Skip(); }
		
	
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
		wxStaticText* static_pos_x;
		wxTextCtrl* pos_x_field;
		wxStaticText* static_pos_y;
		wxTextCtrl* pos_y_field;
		wxStaticText* static_index;
		wxTextCtrl* index_field;
		wxStaticText* static_missing;
		wxTextCtrl* missing_field;
		wxStaticText* static_width;
		wxStaticText* width_field;
		wxStaticText* static_height;
		wxStaticText* height_field;
		wxStaticText* static_size;
		wxStaticText* m_staticText18;
		wxPanel* tab_sprite;
		wxPanel* tab_sprite_ctrl_panel;
		wxButton* import_sprite_button;
		wxButton* export_sprite_button;
		wxPanel* tab_sprite_image_panel;
		wxStaticBitmap* sprite_image;
		wxStdDialogButtonSizer* sprite_base_buttons;
		wxButton* sprite_base_buttonsOK;
		wxButton* sprite_base_buttonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onImportButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void onExportButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SpriteBaseDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sprite"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SpriteBaseDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SpriteImportBaseDialog
///////////////////////////////////////////////////////////////////////////////
class SpriteImportBaseDialog : public wxDialog 
{
	private:
	
	protected:
		wxFilePickerCtrl* file_field;
		wxTextCtrl* transparency_field;
		wxButton* preview_button;
		wxPanel* spriteimport_image_panel1;
		wxStaticBitmap* sprite_image;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onFileChange( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void onIndexChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPreviewClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SpriteImportBaseDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Import Sprite"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 586,305 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SpriteImportBaseDialog();
	
};

#endif //__SHARED_H__
