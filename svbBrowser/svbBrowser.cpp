#include "svbBrowser.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;
	wxInitAllImageHandlers();
	MyFrame1* dlg = new MyFrame1(NULL);
	dlg->Show();

	return true;
}


MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetIcon(wxIcon(wxT("webbrowser.xpm"), wxBITMAP_TYPE_XPM));
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->DragAcceptFiles( true );

	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_scrolledWindow1 = new wxScrolledWindow( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_htmlWin3 = new wxHtmlWindow( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxSize( GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), wxHW_SCROLLBAR_AUTO);
	bSizer5->Add( m_htmlWin3, 0, wxALL, 5 );

	m_htmlWin3->SetPage("<img src='webbrowser.png' height='100' width='100'><font color='#00006C' face = 'Consolas' size = '10'><h1>svbBrowser< / h1><br>Home page. <hr> Try to open some links here : <br><br><a href = 'https://www.google.com/'>Google.com< / a> | <a href = 'http://old-dos.ru/'>Old - dos.ru< / a> | <a href = 'https://opnxng.com/'>SearXNG< / a> | <a href = 'https://wiby.me/'>Wiby.me< / a>");


	m_scrolledWindow1->SetSizer( bSizer5 );
	m_scrolledWindow1->Layout();
	bSizer5->Fit( m_scrolledWindow1 );
	m_notebook1->AddPage( m_scrolledWindow1, wxT("Home"), false );

	bSizer2->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_staticText12 = new wxStaticText( m_toolBar1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 10,-1 ), 0 );
	m_staticText12->Wrap( -1 );
	m_toolBar1->AddControl( m_staticText12 );
	m_tool7 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("plus-square.png"), wxBITMAP_TYPE_PNG ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_staticText121 = new wxStaticText( m_toolBar1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 10,-1 ), 0 );
	m_staticText121->Wrap( -1 );
	m_toolBar1->AddControl( m_staticText121 );
	m_tool1 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("chevron-left.png"), wxBITMAP_TYPE_PNG ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool2 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("chevron-right.png"), wxBITMAP_TYPE_PNG ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool3 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("refresh-cw.png"), wxBITMAP_TYPE_PNG ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_staticText1 = new wxStaticText( m_toolBar1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_staticText1->Wrap( -1 );
	m_toolBar1->AddControl( m_staticText1 );
	m_textCtrl1 = new wxTextCtrl( m_toolBar1, wxID_ANY, wxT("Web-adress..."), wxPoint( -1,-1 ), wxSize( 500,-1 ), 0 );
	m_textCtrl1->DragAcceptFiles( true );

	m_toolBar1->AddControl( m_textCtrl1 );

	m_tool31 = m_toolBar1->AddTool(wxID_ANY, wxT("tool"), wxBitmap(wxT("arrow-right-circle.png"), wxBITMAP_TYPE_PNG), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	m_staticText11 = new wxStaticText( m_toolBar1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_staticText11->Wrap( -1 );
	m_toolBar1->AddControl( m_staticText11 );
	m_textCtrl11 = new wxTextCtrl( m_toolBar1, wxID_ANY, wxT("Search..."), wxPoint( -1,-1 ), wxSize( 200,-1 ), 0 );
	m_textCtrl11->DragAcceptFiles( true );

	m_toolBar1->AddControl( m_textCtrl11 );

	m_tool311 = m_toolBar1->AddTool(wxID_ANY, wxT("tool"), wxBitmap(wxT("arrow-right-circle.png"), wxBITMAP_TYPE_PNG), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	m_staticText111 = new wxStaticText( m_toolBar1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_staticText111->Wrap( -1 );
	m_toolBar1->AddControl( m_staticText111 );
	m_tool4 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("star.png"), wxBITMAP_TYPE_PNG ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool5 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("globe.png"), wxBITMAP_TYPE_PNG ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool6 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("align-justify.png"), wxBITMAP_TYPE_PNG ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->Realize();


	this->Centre( wxBOTH );


	//m_textCtrl1->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(MyFrame1::newAdress), NULL, this);

	m_htmlWin3->Connect(wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler(MyFrame1::linkClick), NULL, this);
	//m_htmlWin3->SetScrollRate(50, 50);

	this->Connect(m_tool3->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::refreshPage));
	this->Connect(m_tool1->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::backToPage));
	this->Connect(m_tool31->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::newAdress));
	this->Connect(m_tool311->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::mkSearch));
}

MyFrame1::~MyFrame1()
{
	//m_textCtrl1->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(MyFrame1::newAdress), NULL, this);
	m_htmlWin3->Disconnect(wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler(MyFrame1::linkClick), NULL, this);
	this->Disconnect(m_tool1->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::backToPage));
	this->Disconnect(m_tool3->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::refreshPage));
	this->Disconnect(m_tool31->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::newAdress));
	this->Disconnect(m_tool311->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MyFrame1::mkSearch));
}
