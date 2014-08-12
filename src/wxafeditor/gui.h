///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
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
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class AFBaseFrame
///////////////////////////////////////////////////////////////////////////////
class AFBaseFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* base_menu_bar;
		wxMenu* menu_file;
		wxMenuItem* menuitem_new;
		wxMenuItem* menuitem_open;
		wxMenuItem* menuitem_save;
		wxMenuItem* menuitem_saveas;
		wxMenuItem* menuitem_exit;
		wxMenu* menu_help;
		wxMenuItem* menuitem_about;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onMenuNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMenuAbout( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AFBaseFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxAFEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~AFBaseFrame();
	
};

#endif //__GUI_H__
