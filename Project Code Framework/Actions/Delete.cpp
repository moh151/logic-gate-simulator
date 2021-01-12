#include "Delete.h"

/* Constructor */
Delete::Delete(ApplicationManager* pAppMan) : Action(pAppMan) {
	
}

/* Reads parameters required for action to execute */
void Delete::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Please select a component to delete");
	pIn->GetPointClicked(dX, dY);
	pOut->ClearStatusBar();


}

/* Executes action */
void Delete::Execute() {

	ReadActionParameters();
	Comp = pManager->selected(dX, dY);
	if (Comp != NULL)
	{
		pManager->DeleteComp(dX, dY);
	}
	pManager->GetOutput()->PrintMsg("Deleted");
}
/* Undo action */
void Delete::Undo() {
	return;
}

/* Redo action */
void Delete::Redo() {
	return;
}


/* Destructor */
Delete::~Delete() {

}