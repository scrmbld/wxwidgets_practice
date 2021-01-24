#pragma once
#include <wx/wx.h>

class cMain : public wxFrame {
	public:
			cMain(const wxString& title);
			~cMain();
	public:
		int fieldWidth = 10;
		int fieldHeight = 10;
		
		wxButton **btn;
		int *nField = nullptr;
		bool bFirstClick = true;

		void OnButtonClicked(wxCommandEvent &evt);


		wxDECLARE_EVENT_TABLE();
};
