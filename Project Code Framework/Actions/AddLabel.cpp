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

}

void AddLabel::Execute()
{
	//Get the place where you'll start typing
	ReadActionParameters();
	
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	string s = pIn->GetSrting(pOut);
	//pOut->DrawString(Cx, Cy, s);
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}

