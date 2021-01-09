#include "AddLabel.h"
#include "..\ApplicationManager.h"

AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{
}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click where you want to add the label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	//Print Action Message
	pOut->PrintMsg("Click on the gate you want to attach the label to");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLabel::Execute()
{
	//Get the place where you'll start typing
	ReadActionParameters();

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	
	for (int i = 0; i < pManager->getComponentCount(); i++)
	{
		Component* pComp = pManager->GetCompenentList(i);
		if (pComp->getGraphicsinfo().x1 < x && pComp->getGraphicsinfo().x2 > x && pComp->getGraphicsinfo().y1 < y && pComp->getGraphicsinfo().y2 > y)
		{
			pOut->PrintMsg("Enter label: ");
			string s = pIn->GetSrting(pOut);
			pOut->DrawString(Cx, Cy, s);
			pComp->setLabel(s);
		}
	}
	
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}

