///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
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
#include <wx/choice.h>
#include <wx/treectrl.h>
#include <wx/html/htmlwin.h>
#include <wx/splitter.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>

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
		wxMenu* menu_help;
		wxAuiNotebook* base_tabs;
		wxPanel* tab_info;
		wxTextCtrl* info_value_fileid;
		wxStaticText* info_value_palettec;
		wxStaticText* info_value_overlayc;
		wxStaticText* info_value_bgw;
		wxStaticText* info_value_bgh;
		wxStaticText* info_value_animationc;
		wxPanel* tab_background;
		wxButton* bg_ctrl_load_button;
		wxButton* bg_ctrl_save_button;
		wxPanel* bg_image_panel;
		wxPanel* tab_palette;
		wxPanel* palette_ctrl_panel;
		wxChoice* palette_ctrl_select_palette;
		wxChoice* palette_ctrl_select_overlay;
		wxButton* palette_ctrl_load_button;
		wxButton* palette_ctrl_save_button;
		wxButton* palette_ctrl_delpal_button;
		wxButton* palette_ctrl_deloverlay_button;
		wxButton* palette_ctrl_newpal_button;
		wxButton* palette_ctrl_newoverlay_button;
		wxPanel* palette_grid_panel;
		wxGridSizer* palette_grid_sizer;
		wxPanel* tab_animations;
		wxTreeCtrl* animations_tree;
		wxSplitterWindow* animations_splitter;
		wxPanel* animations_sprite_panel;
		wxHtmlWindow* animations_info;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onMenuNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBackgroundLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBackgroundSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBackgroundMouseEvent( wxMouseEvent& event ) { event.Skip(); }
		virtual void onBackgroundPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void onPaletteChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOverlayChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaletteLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaletteSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaletteDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOverlayDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNewPalette( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNewOverlay( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSpriteMouseEvent( wxMouseEvent& event ) { event.Skip(); }
		
	
	public:
		
		BaseFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxBKEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~BaseFrame();
		
		void animations_splitterOnIdle( wxIdleEvent& )
		{
			animations_splitter->SetSashPosition( 361 );
			animations_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( BaseFrame::animations_splitterOnIdle ), NULL, this );
		}
	
};

#endif //__GUI_H__
