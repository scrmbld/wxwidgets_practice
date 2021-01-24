#include <wx/wx.h>
#include "cApp.h"
#include "cMain.h"

bool cApp::OnInit() {
	//create the window
	cMain *minesweeper = new cMain(wxT("Minesweeper"));
	minesweeper->Show(true);
	return true;
}

wxIMPLEMENT_APP(cApp);
