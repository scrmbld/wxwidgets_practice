#include <wx/wx.h>
#include "cApp.h"
#include "cMain.h"

bool cApp::OnInit() {
	cMain *simple = new cMain(wxT("test"));
	simple->Show(true);
	return true;
}

wxIMPLEMENT_APP(cApp);
