#include "Select.h"
#include <Windows.h>


/* Constructor */
Select::Select(ApplicationManager* pApp) : Action(pApp) {
	xs = 0;
	ys = 0;
}

/* Reads parameters required for action to execute */
void Select::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("");

	//Wait for User Input

	//Clear Status Bar
	pIn->getLastPointClicked(xs, ys);
	pOut->ClearStatusBar();
}


/* Executes action */
void Select::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int compcount = pManager->getComponentCount();
	ApplicationManager* M = pManager;
	for (int i = 0; i < compcount; i++) {
		if (GetKeyState(VK_CONTROL) & 0x8000 || M->GetCompenentList(i)->IsSelected() == false)
		{
			if (xs >= M->GetCompenentList(i)->getGraphicsinfo().x1 && xs <= M->GetCompenentList(i)->getGraphicsinfo().x2 && ys >= M->GetCompenentList(i)->getGraphicsinfo().y1 && ys <= M->GetCompenentList(i)->getGraphicsinfo().y2) {
				pManager->GetCompenentList(i)->SetSelected(true);
			}
		}
		else if (xs >= M->GetCompenentList(i)->getGraphicsinfo().x1 && xs <= M->GetCompenentList(i)->getGraphicsinfo().x2 && ys >= M->GetCompenentList(i)->getGraphicsinfo().y1 && ys <= M->GetCompenentList(i)->getGraphicsinfo().y2 && M->GetCompenentList(i)->IsSelected() == true) {
			pManager->GetCompenentList(i)->SetSelected(false);
		}
	}
}

/* Undo action */
void Select::Undo() {
	return;
}

/* Redo action */
void Select::Redo() {
	return;
}

