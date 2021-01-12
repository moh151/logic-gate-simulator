#include "Paste.h"
/* Constructor */
Paste::Paste(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void Paste::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
}

/* Executes action */
void Paste::Execute() {
	//Get Center point of the Gate
	ReadActionParameters();
	//Calculate the rectangle Corners
	int Len = UI.GATE_Width;
	int Wdth = UI.GATE_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	mComp = pManager->GetCopiedComp();
	if (dynamic_cast<AND2*>(pManager->GetCopiedComp()))
	{
		AND2* pA = new AND2(GInfo, AND2_FANOUT);
	}
	else if (dynamic_cast<NAND*>(pManager->GetCopiedComp()))
	{
		NAND* pA = new NAND(GInfo, AND2_FANOUT);
	}
	//else if (dynamic_cast<OR2*>(pManager->GetCopiedComp()))
	//{OR2* pA = new OR2(GInfo, AND2_FANOUT);}
	else if (dynamic_cast<XOR2*>(pManager->GetCopiedComp()))
	{
		XOR2* pA = new XOR2(GInfo, AND2_FANOUT);
	}
	else if (dynamic_cast<XNOR*>(pManager->GetCopiedComp()))
	{
		XNOR* pA = new XNOR(GInfo, AND2_FANOUT);
	}
	else if (dynamic_cast<INVERTER*>(pManager->GetCopiedComp()))
	{
		INVERTER* pA = new INVERTER(GInfo, AND2_FANOUT);
	}
	//else if(dynamic_cast<AND3*>(pManager->GetCopiedComp()))
	//{AND3* pA = new AND3(GInfo, AND2_FANOUT);}
	else if (dynamic_cast<XOR3*>(pManager->GetCopiedComp()))
	{
		XOR3* pA = new XOR3(GInfo, AND2_FANOUT);
	}
	pManager->AddComponent(mComp);
}

/* Undo action */
void Paste::Undo() {
	mAct->Undo();
}

/* Redo action */
void Paste::Redo() {
	mAct->Redo();
}

/* Destructor */
Paste::~Paste() {
		delete mAct;
}