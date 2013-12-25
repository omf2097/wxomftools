///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/choice.h>
#include <wx/treectrl.h>
#include <wx/html/htmlwin.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BaseFrame
///////////////////////////////////////////////////////////////////////////////
class BaseFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* base_menu_bar;
		wxMenu* menu_file;
		wxMenuItem* menuitem_save;
		wxMenuItem* menuitem_saveas;
		wxMenu* menu_help;
		wxAuiNotebook* base_tabs;
		wxPanel* tab_info;
		wxTextCtrl* info_value_fileid;
		wxStaticText* info_value_palettec;
		wxStaticText* info_value_bgw;
		wxStaticText* info_value_bgh;
		wxStaticText* info_value_animationc;
		wxPanel* tab_background;
		wxButton* bg_ctrl_load_button;
		wxButton* bg_ctrl_save_button;
		wxPanel* bg_image_panel;
		wxStaticBitmap* bg_image_bitmap;
		wxPanel* tab_palette;
		wxPanel* palette_ctrl_panel;
		wxChoice* palette_ctrl_select_palette;
		wxChoice* palette_ctrl_select_remap;
		wxButton* palette_ctrl_load_button;
		wxButton* palette_ctrl_save_button;
		wxButton* palette_ctrl_delpal_button;
		wxButton* palette_ctrl_delremap_button;
		wxButton* palette_ctrl_newpal_button;
		wxButton* palette_ctrl_newremap_button;
		wxPanel* palette_grid_panel;
		wxGridSizer* palette_grid_sizer;
		wxPanel* tab_animations;
		wxPanel* animations_ctrl_panel;
		wxButton* animation_ctrl_delete_button;
		wxButton* animation_ctrl_edit_button;
		wxButton* animation_ctrl_add_button;
		wxButton* animation_ctrl_add_sprite_button;
		wxTreeCtrl* animations_tree;
		wxStaticBitmap* animations_preview_bitmap;
		wxHtmlWindow* animations_preview_data;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onMenuNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBackgroundLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBackgroundSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaletteChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onRemapChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaletteLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaletteSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaletteDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOverlayDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNewPalette( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNewOverlay( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAnimationDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAnimationEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAnimationAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSpriteAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAnimTreeContextMenu( wxTreeEvent& event ) { event.Skip(); }
		virtual void onAnimTreeItemSelect( wxTreeEvent& event ) { event.Skip(); }
		
	
	public:
		
		BaseFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxBKEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~BaseFrame();
	
};

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

#endif //__GUI_H__