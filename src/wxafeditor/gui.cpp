///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

AFBaseFrame::AFBaseFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	base_menu_bar = new wxMenuBar( 0 );
	menu_file = new wxMenu();
	menuitem_new = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("New") ) + wxT('\t') + wxT("CTRL+N"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_new );
	
	menuitem_open = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Open") ) + wxT('\t') + wxT("CTRL+O"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_open );
	
	menuitem_save = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_save );
	
	menuitem_saveas = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Save As ...") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_saveas );
	
	menu_file->AppendSeparator();
	
	menuitem_exit = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Exit") ) + wxT('\t') + wxT("ALT+F4"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menuitem_exit );
	
	base_menu_bar->Append( menu_file, wxT("File") ); 
	
	menu_help = new wxMenu();
	menuitem_about = new wxMenuItem( menu_help, wxID_ANY, wxString( wxT("About") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	menu_help->Append( menuitem_about );
	
	base_menu_bar->Append( menu_help, wxT("Help") ); 
	
	this->SetMenuBar( base_menu_bar );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( menuitem_new->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuNew ) );
	this->Connect( menuitem_open->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuOpen ) );
	this->Connect( menuitem_save->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuSave ) );
	this->Connect( menuitem_saveas->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuSaveAs ) );
	this->Connect( menuitem_exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuExit ) );
	this->Connect( menuitem_about->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuAbout ) );
}

AFBaseFrame::~AFBaseFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuNew ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuOpen ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuSaveAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuExit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AFBaseFrame::onMenuAbout ) );
	
}
