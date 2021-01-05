#include "Select.h"


/* Constructor */
Select::Select(ApplicationManager* pApp) : Action(pApp) {
	
}

/* Reads parameters required for action to execute */
void Select::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("");

	//Wait for User Input


	//Clear Status Bar

	pIn->GetPointClicked(xs, ys);
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
		if (xs >= M->GetCompenentList(i)->getGraphicsinfo().x1 && xs <= M->GetCompenentList(i)->getGraphicsinfo().x2 && ys >= M->GetCompenentList(i)->getGraphicsinfo().y1 && ys <= M->GetCompenentList(i)->getGraphicsinfo().y2 && M->GetCompenentList(i)->IsSelected() == false) {
			pManager->GetCompenentList(i)->SetSelected(true);
		}
		else if (M->GetCompenentList(i)->IsSelected() == true) {
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

