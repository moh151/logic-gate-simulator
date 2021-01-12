#include "Cut.h"

/* Constructor */
Cut::Cut(ApplicationManager* pAppMan) : Action(pAppMan) {
	mDeleteAct = new Delete(pManager);
}

/* Reads parameters required for action to execute */
void Cut::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pManager->SetSelectionOfComponents(false);
	pManager->UpdateInterface();
	pOut->PrintMsg("Please select a component to cut");
	pIn->GetPointClicked(mX, mY);
	pOut->ClearStatusBar();
}

/* Executes action */
void Cut::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	for (int i = 0; i < pManager->getComponentCount(); i++)
	{
		Component* pComp = pManager->GetCompenentList(i);
		if (pComp->getGraphicsinfo().x1 <= mX && pComp->getGraphicsinfo().x2 >= mX && pComp->getGraphicsinfo().y1 <= mY && pComp->getGraphicsinfo().y2 >= mY)
		{
		 pManager->SetCopiedComp(mComp);
		 pManager->DeleteComp(mX, mY);
		 pOut->PrintMsg("Cut");
		}
	   else if (pComp == NULL)
	   {
		 pOut->PrintMsg("No component was selected. Operation was cancelled");
	   }
	  else if (dynamic_cast<Connection*>(pComp) != NULL)
	  {
	    pOut->PrintMsg("Connection can't be copied. Operation was cancelled");
	  }
	}
}

/* Undo action */
void Cut::Undo() {
	mDeleteAct->Undo();
}

/* Redo action */
void Cut::Redo() {
	mDeleteAct->Redo();
}

/* Destructor */
Cut::~Cut() {
	delete mDeleteAct;
}