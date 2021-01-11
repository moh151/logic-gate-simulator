#include "edit.h"
#include "..\ApplicationManager.h"

edit::edit(ApplicationManager* pApp) :Action(pApp)
{
}

edit::~edit(void)
{
}
void edit::ReadActionParameters()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("enter the new editing label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	
	//Clear Status Bar
	pOut->ClearStatusBar();
	//Print Action Message
	pOut->PrintMsg("Click on the gate you want to attach the new label to");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void edit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	for (int i = 0; i < pManager->getComponentCount(); i++)
	{//had yfhmne eh hewar <=x da wel leela de
		Component* pComp = pManager->GetCompenentList(i);
		if (pComp->getGraphicsinfo().x1 <= x && pComp->getGraphicsinfo().x2 >= x && pComp->getGraphicsinfo().y1 <= y && pComp->getGraphicsinfo().y2 >= y)
		{
			pOut->PrintMsg("Enter label: ");
			string newl = pIn->GetSrting(pOut);
			
			pManager->editall(newl);
		}
	}
	
	
	
}

void edit::Undo()
{}

void edit::Redo()
{}