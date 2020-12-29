#include "AddXNORgate.h"
#include "..\ApplicationManager.h"

AddXNORgate::AddXNORgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddXNORgate::~AddXNORgate(void)
{
}

void AddXNORgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.GATE_Width;
	int Wdth = UI.GATE_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the XNOR gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XNOR* pA = new XNOR(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddXNORgate::Undo()
{}

void AddXNORgate::Redo()
{}
