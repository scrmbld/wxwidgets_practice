#include <wx/wx.h>
#include <iostream>
#include <sstream>
#include <string>
#include "cApp.h"
#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, cMain::OnButtonClicked)
wxEND_EVENT_TABLE()

bool all_digits(std::string s) {
	for (char c : s) {
		if (!isdigit(c)) return false;
	}
	return true;
}

cMain::cMain(const wxString &title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 800)) {
	Centre();

	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 10), wxSize(300, 100));
	
	m_text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 110), wxSize(200, 50));

	m_btn1 = new wxButton(this, 10001, "click me", wxPoint(220, 110), wxSize(100, 50));
}

void cMain::OnButtonClicked(wxCommandEvent &evt) {
	std::cout << "button clicked" << std::endl;
	std::stringstream input;
	input << m_text1->GetValue();
	int lhs = 0;
	int rhs = 0;
	input >> lhs;
	std::cout << lhs << std::endl;
	while (input) {
		std::string s;
		input >> s;
		if (!input) break;
		if (!all_digits(s)) {
			std::cout << "performing an operation (" << s << ")" << std::endl;
			if (s == "+") {
				lhs += rhs;
			} else if (s == "-") {
				lhs -= rhs;
			} else if (s == "*") {
				lhs *= rhs;
			} else if (s == "/") {
				lhs /= rhs;
			} else if (s == "^") {
				lhs = std::pow(lhs, rhs);
			} else {
				std::cout << "syntax error" << std::endl;
				break;
			}
			
			rhs = 0;
		} else {
			std::cout << "getting a number" << std::endl;
			rhs = stoi(s);
		}

	}

	std::cout << "outputting result (" << lhs << ")" << std::endl;
	std::cout << std::to_string(lhs) << std::endl;
	m_list1->AppendString(std::to_string(lhs));
	m_text1->SetValue("");
	evt.Skip();
}
