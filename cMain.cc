#include <wx/wx.h>
#include <iostream>
#include <sstream>
#include <string>
#include "cApp.h"
#include "cMain.h"

//event table - currently unused, button events are using button.Bind()
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
wxEND_EVENT_TABLE()

cMain::cMain(const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 800)) {
	Centre();

	//create the field
	//create array for buttons
	btn = new wxButton*[fieldWidth * fieldHeight];
	//button placement & size managed by wxwidgets grid
	wxGridSizer *grid = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);

	//create array for mine data
	nField = new int [fieldWidth * fieldHeight];

	//initialize buttons and nField
	for (int i = 0; i < fieldWidth; i++) {
		for (int j = 0; j < fieldHeight; j++) {
			//construct button
			btn[i*fieldWidth + j] = new wxButton(this, 10'000 + (i*fieldWidth + j));
			//add to grid
			grid->Add(btn[i*fieldWidth + j], 1, wxEXPAND | wxALL);
			//bind event for button press
			btn[i*fieldWidth + j]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
			
			//set every spot in the mine array to 0
			nField[i*fieldWidth + j] = 0;
		}
	}

	//run the grid
	this->SetSizer(grid);
	grid->Layout();
}

cMain::~cMain() {
	//vectors are better
	delete[] btn;
	delete[] nField;
}

void cMain::OnButtonClicked(wxCommandEvent &evt) {
	//get location of the button that's been pressed
	int x = (evt.GetId() - 10'000) % fieldWidth;
	int y = (evt.GetId() - 10'000) / fieldWidth;

	//if it's the first one to be clicked
	if (bFirstClick) {
		//generate the mines
		int mines = 30;
		while (mines) {
			int rx = rand() % fieldWidth;
			int ry = rand() % fieldHeight;

			//make sure that the initial spot doesn't have one
			//that way the player can't die instantly
			if (nField[ry*fieldWidth + rx] == 0 && rx != x && ry != y) {
				nField[ry* fieldWidth + rx] = -1; // -1 == mine
				--mines;
			}
		}
		
		bFirstClick = false;
	}

	//disable the pressed button
	btn[y*fieldWidth + x]->Enable(false);

	//check if player hit mine
	if (nField[y*fieldWidth + x] == -1) {
		//inform the player that they're bad
		wxMessageBox("BOOOOM!! - Game Over :(");

		//reset game
		bFirstClick = true;

		//set every spot in mine array to 0, blank out the buttons, and enable them
		for (int i = 0; i < fieldWidth; i++) {
			for (int j = 0; j < fieldHeight; j++) {
				nField[i*fieldWidth + j] = 0;
				btn[i*fieldWidth + j]->SetLabel("");
				btn[i*fieldWidth + j]->Enable(true);
			}
		}
	
	} else {
		//count neighboring mines
		int mine_count = 0;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (x + i >= 0 && x + i < fieldWidth && y + j >= 0 && y + j < fieldHeight) {
					if (nField[(y + j)*fieldWidth + (x + i)] == -1) 
						mine_count++;
				}
			}
		}

		//dislay the number of neighboring mines on the button
		if (mine_count > 0)
			btn[y*fieldWidth + x]->SetLabel(std::to_string(mine_count));
	}

	evt.Skip();
}
