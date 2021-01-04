#include "Select.h"


/* Constructor */
Select::Select(ApplicationManager* pApp) : Action(pApp) {
	
}

/* Reads parameters required for action to execute */
void Select::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(xs, ys);
	xe = xs;
	ye = ys;
}


/* Executes action */
void Select::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int compcount = pManager->getComponentCount();

	for (int i = 0; i < compcount; i++) {
		pManager->GetCompenentList(i);
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

