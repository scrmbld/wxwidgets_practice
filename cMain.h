#pragma once
#include <wx/wx.h>

class cMain : public wxFrame {
	public:
			cMain(const wxString& title);

	public:
		wxListBox *m_list1 = nullptr;
		wxTextCtrl *m_text1 = nullptr;
		wxButton *m_btn1 = nullptr;
	
		void OnButtonClicked(wxCommandEvent &evt);


		wxDECLARE_EVENT_TABLE();
};
