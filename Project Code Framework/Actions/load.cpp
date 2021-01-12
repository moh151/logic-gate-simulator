#include "load.h"
#include "..\ApplicationManager.h"
#include "..\Components\AND2.h"
#include "..\Components\AND3.h"
#include "..\Components\Buffer.h"
#include "..\Components\INVERTER.h"
#include "..\Components\LED.h"
#include "..\Components\NAND.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\OR2.h"
#include "..\Components\Switch.h"
#include "..\Components\XNOR.h"
#include "..\Components\XOR2.h"
#include "..\Components\XOR3.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
load::load(ApplicationManager* pApp) :Action(pApp)
{
}

load::~load(void)
{
}
void load::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("loads the component from the pre-saved file...click anywhere to continue");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	//Print Action Message
	pOut->PrintMsg("click where u want to add the loaded component");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();
}
void load::Execute()
{
	//calling readaction parameters
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//clears the drawing area to load the new component in a clean enviroment
	pOut->ClearDrawingArea();


	Loading.open("save.txt");
	//for checking errors
	if (Loading.fail())
	{
		cerr << "error opening file" << endl;
		exit(1);
	}
	else //sucsses
	{
		pManager->loadall(Loading);
		for (int i = 0; i < pManager->GetExistingComponentsCount(); i++)
		{
			Component* obj = pManager->GetCompenentList(i);

			int x = obj->getID();

			GraphicsInfo GInfo;
			GInfo.x1 = Cx;
			GInfo.x2 = Cy;


			Component* pComp2 = NULL;

			obj->load(Loading);
			switch (x)
			{
			case 2:
				pComp2 = new AND2(GInfo, AND2_FANOUT);
				break;
			case 4:
				pComp2 = new Buffer(GInfo, AND2_FANOUT);
				break;
			case 5:
				pComp2 = new INVERTER(GInfo, AND2_FANOUT);
				break;
			case 6:
				pComp2 = new LED(GInfo, AND2_FANOUT);
				break;

			case 7:
				pComp2 = new NAND(GInfo, AND2_FANOUT);
				break;

			case 9:
				pComp2 = new NOR3(GInfo, AND2_FANOUT);
				break;
			case 11:
				pComp2 = new XNOR(GInfo, AND2_FANOUT);
				break;
			case 12:
				pComp2 = new XOR2(GInfo, AND2_FANOUT);
				break;
			case 13:
				pComp2 = new XOR3(GInfo, AND2_FANOUT);
				break;
			case 14:
				pComp2 = new SWITCH(GInfo, AND2_FANOUT);
				break;
			default:
				pOut->PrintMsg("there is no component with that id");
				break;



				pManager->AddComponent(pComp2);

			}

		}
	}
}



void load::Undo()
{}

void load::Redo()
{}
							