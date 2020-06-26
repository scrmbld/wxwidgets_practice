#include <wx/wx.h>
#include "cApp.h"
#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, cMain::OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain(const wxString &title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 800)) {
	Centre();

	m_btn1 = new wxButton(this, 10001, "click me", wxPoint(10, 10), wxSize(150, 50));
	m_text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 60), wxSize(300, 50));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));

}

void cMain::OnButtonClicked(wxCommandEvent &evt) {
	m_list1->AppendString(m_text1->GetValue());
	m_text1->SetValue("");
	evt.Skip();
}
