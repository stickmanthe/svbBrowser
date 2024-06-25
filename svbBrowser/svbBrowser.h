#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/html/htmlwin.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <wx/wx.h>
#include <curl/curl.h>
#include <string>

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};




class MyFrame1 : public wxFrame
{
private:

	//void OnClick(wxSizeEvent& event)
	//{
	//	puts("Click click epta");
	//}

protected:
	wxStatusBar* m_statusBar1;
	wxNotebook* m_notebook1;
	wxScrolledWindow* m_scrolledWindow1;
	wxHtmlWindow* m_htmlWin3;
	wxToolBar* m_toolBar1;
	wxStaticText* m_staticText12;
	wxToolBarToolBase* m_tool7;
	wxStaticText* m_staticText121;
	wxToolBarToolBase* m_tool1;
	wxToolBarToolBase* m_tool2;
	wxToolBarToolBase* m_tool3;
	wxStaticText* m_staticText1;
	wxTextCtrl* m_textCtrl1;
	wxStaticText* m_staticText11;
	wxTextCtrl* m_textCtrl11;
	wxStaticText* m_staticText111;
	wxToolBarToolBase* m_tool4;
	wxToolBarToolBase* m_tool5;
	wxToolBarToolBase* m_tool6;
	wxToolBarToolBase* m_tool31;
	wxToolBarToolBase* m_tool311;


	// Функция при подтвреждении появления нового веб-адреса
	virtual void newAdress(wxCommandEvent& event)
	{
		laterAdress = m_textCtrl1->GetValue().ToStdString();
		std::string webAdress = m_textCtrl1->GetValue().ToStdString();

		if (webAdress == "Web-adress...")
		{
			m_htmlWin3->SetPage("<img src='webbrowser.png' height='100' width='100'><font color='#00006C' face = 'Consolas' size = '10'><h1>svbBrowser< / h1><br>Hello again! <hr> Try to open some links here : <br><br><a href = 'https://www.google.com/'>Google.com< / a> | <a href = 'http://old-dos.ru/'>Old - dos.ru< / a> | <a href = 'https://opnxng.com/'>SearXNG< / a> | <a href = 'https://wiby.me/'>Wiby.me< / a>");
			m_notebook1->SetPageText(0, "Home");
		}
		else {
			typedef size_t(*curl_write)(char*, size_t, size_t, std::string*);

			CURLcode res_code = CURLE_FAILED_INIT;
			CURL* curl = curl_easy_init();
			std::string result;
			std::string url = webAdress;

			curl_easy_setopt(curl,
				CURLOPT_WRITEFUNCTION,
				static_cast <curl_write> ([](char* contents, size_t size,
					size_t nmemb, std::string* data) -> size_t {
						size_t new_size = size * nmemb;
						if (data == NULL) {
							return 0;
						}
						data->append(contents, new_size);
						return new_size;
					}));
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_USERAGENT, "svbBrowser");

			res_code = curl_easy_perform(curl);

			if (res_code != CURLE_OK) {
				m_htmlWin3->SetPage(curl_easy_strerror(res_code));
			}

			curl_easy_cleanup(curl);

			curl_global_cleanup();

			m_htmlWin3->SetPage(result);
			m_notebook1->SetPageText(0, m_htmlWin3->GetOpenedPageTitle());
		}
	}

	// Функция при нажатии на ссылку что ведет на новый веб-адрес
	virtual void linkClick(wxHtmlLinkEvent& event)
	{
		laterAdress = m_textCtrl1->GetValue().ToStdString();
		wxHtmlLinkInfo linkInfo = event.GetLinkInfo();
		m_textCtrl1->SetValue(linkInfo.GetHref());
		if (m_textCtrl1->GetValue().ToStdString().substr(0, 4) != "http")
		{
			m_textCtrl1->SetValue(laterAdress + linkInfo.GetHref());
		}
		std::string webAdress = m_textCtrl1->GetValue().ToStdString();

		typedef size_t(*curl_write)(char*, size_t, size_t, std::string*);

		CURLcode res_code = CURLE_FAILED_INIT;
		CURL* curl = curl_easy_init();
		std::string result;
		std::string url = webAdress;

		curl_easy_setopt(curl,
			CURLOPT_WRITEFUNCTION,
			static_cast <curl_write> ([](char* contents, size_t size,
				size_t nmemb, std::string* data) -> size_t {
					size_t new_size = size * nmemb;
					if (data == NULL) {
						return 0;
					}
					data->append(contents, new_size);
					return new_size;
				}));
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "svbBrowser");

		res_code = curl_easy_perform(curl);

		if (res_code != CURLE_OK) {
			m_htmlWin3->SetPage(curl_easy_strerror(res_code));
		}

		curl_easy_cleanup(curl);

		curl_global_cleanup();

		m_htmlWin3->SetPage(result);
		m_notebook1->SetPageText(0, m_htmlWin3->GetOpenedPageTitle());
	}

	// Функция при подтверждении возвращения на прошлую страницу
	virtual void backToPage(wxCommandEvent& event)
	{
		m_textCtrl1->SetValue(laterAdress);
		std::string webAdress = m_textCtrl1->GetValue().ToStdString();

		if (webAdress == "Web-adress...")
		{
			m_htmlWin3->SetPage("<img src='webbrowser.png' height='100' width='100'><font color='#00006C' face = 'Consolas' size = '10'><h1>svbBrowser< / h1><br>Hello again! <hr> Try to open some links here : <br><br><a href = 'https://www.google.com/'>Google.com< / a> | <a href = 'http://old-dos.ru/'>Old - dos.ru< / a> | <a href = 'https://opnxng.com/'>SearXNG< / a> | <a href = 'https://wiby.me/'>Wiby.me< / a>");
			m_notebook1->SetPageText(0, "Home");
		}
		else {
			typedef size_t(*curl_write)(char*, size_t, size_t, std::string*);

			CURLcode res_code = CURLE_FAILED_INIT;
			CURL* curl = curl_easy_init();
			std::string result;
			std::string url = webAdress;

			curl_easy_setopt(curl,
				CURLOPT_WRITEFUNCTION,
				static_cast <curl_write> ([](char* contents, size_t size,
					size_t nmemb, std::string* data) -> size_t {
						size_t new_size = size * nmemb;
						if (data == NULL) {
							return 0;
						}
						data->append(contents, new_size);
						return new_size;
					}));
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_USERAGENT, "svbBrowser");

			res_code = curl_easy_perform(curl);

			if (res_code != CURLE_OK) {
				m_htmlWin3->SetPage(curl_easy_strerror(res_code));
			}

			curl_easy_cleanup(curl);

			curl_global_cleanup();

			m_htmlWin3->SetPage(result);
			m_notebook1->SetPageText(0, m_htmlWin3->GetOpenedPageTitle());
		}
	}

	// Функция при подтверждении перезагрузки страницы
	virtual void refreshPage(wxCommandEvent& event)
	{
		std::string webAdress = m_textCtrl1->GetValue().ToStdString();

		if (webAdress == "Web-adress...")
		{
			m_htmlWin3->SetPage("<img src='webbrowser.png' height='100' width='100'><font color='#00006C' face = 'Consolas' size = '10'><h1>svbBrowser< / h1><br>Hello again! <hr> Try to open some links here : <br><br><a href = 'https://www.google.com/'>Google.com< / a> | <a href = 'http://old-dos.ru/'>Old - dos.ru< / a> | <a href = 'https://opnxng.com/'>SearXNG< / a> | <a href = 'https://wiby.me/'>Wiby.me< / a>");
			m_notebook1->SetPageText(0, "Home");
		}
		else {
			typedef size_t(*curl_write)(char*, size_t, size_t, std::string*);

			CURLcode res_code = CURLE_FAILED_INIT;
			CURL* curl = curl_easy_init();
			std::string result;
			std::string url = webAdress;

			curl_easy_setopt(curl,
				CURLOPT_WRITEFUNCTION,
				static_cast <curl_write> ([](char* contents, size_t size,
					size_t nmemb, std::string* data) -> size_t {
						size_t new_size = size * nmemb;
						if (data == NULL) {
							return 0;
						}
						data->append(contents, new_size);
						return new_size;
					}));
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_USERAGENT, "svbBrowser");

			res_code = curl_easy_perform(curl);

			if (res_code != CURLE_OK) {
				m_htmlWin3->SetPage(curl_easy_strerror(res_code));
			}

			curl_easy_cleanup(curl);

			curl_global_cleanup();

			m_htmlWin3->SetPage(result);
			m_notebook1->SetPageText(0, m_htmlWin3->GetOpenedPageTitle());
		}
	}

	// Функция при подтверждении нового поискового запроса
	virtual void mkSearch(wxCommandEvent& event)
	{
		std::string webAdress = "https://wiby.me/?q=" + m_textCtrl11->GetValue().ToStdString();
		m_textCtrl1->SetValue(webAdress);

		typedef size_t(*curl_write)(char*, size_t, size_t, std::string*);

		CURLcode res_code = CURLE_FAILED_INIT;
		CURL* curl = curl_easy_init();
		std::string result;
		std::string url = webAdress;

		curl_easy_setopt(curl,
			CURLOPT_WRITEFUNCTION,
			static_cast <curl_write> ([](char* contents, size_t size,
				size_t nmemb, std::string* data) -> size_t {
					size_t new_size = size * nmemb;
					if (data == NULL) {
						return 0;
					}
					data->append(contents, new_size);
					return new_size;
				}));
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "svbBrowser");

		res_code = curl_easy_perform(curl);

		if (res_code != CURLE_OK) {
			m_htmlWin3->SetPage(curl_easy_strerror(res_code));
		}

		curl_easy_cleanup(curl);

		curl_global_cleanup();

		m_htmlWin3->SetPage(result);
		m_notebook1->SetPageText(0, m_htmlWin3->GetOpenedPageTitle());
	}

	public:

		MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("svbBrowser"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1213, 705), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

		~MyFrame1();

		std::string laterAdress = "Web-adress...";


};


