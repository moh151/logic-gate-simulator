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
	


}
void load::Execute()
{
	//calling readaction parameters
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
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
		//pManager->loadall(Loading);
		for (int i = 0; i < pManager->GetExistingComponentsCount(); i++)
		{
			Component* obj= pManager->GetCompenentList(i);
			
				int x = obj->getID();
				if (x == i)
				{
					Component* newobj = obj;
					newobj->load(Loading);
					pManager->AddComponent(newobj);
				}
			
			
		}
		Loading.close();
	}
	
}
void load::Undo()
{}

void load::Redo()
{}
/*switch (pComp->getID())
		{
		case 2:
			AND2 *obj;
			pComp =obj;
			break;
		/*case 3:
			//AND3 *obj3;
			pComp = obj3;
			break;
			*/
			/*case 4:
				Buffer * obj4;
				pComp = obj4;
					break;
			case 5:
				INVERTER * obj5;
				pComp = obj5;
				break;
			case 6:
				LED * obj6;
				pComp = obj6;
				break;

			case 7:
				NAND * obj7;
				pComp = obj7;
				break;
			/*case 8:
				NOR2 * obj8;
				pComp = obj8;
				break;

				*/
				/*case 9:
					NOR3 * obj9;
					pComp = obj9;
					break;

				/*case 10:
					OR2 * obj10;
					pComp = obj10;
					break;
					*/
					/*case 11:
						XNOR * obj11;
						pComp = obj11;
						break;
					case 12:
						XOR2 * obj12;
						pComp = obj12;
						break;
					case 13:
						XOR3 * obj13;
						pComp = obj13;
						break;
					/*case 14:
						Switch * obj14;
						pComp = obj14;
						break;*/
						/*default :
							pOut->PrintMsg("there is no component with that id");
							break;

						}*/
						//pComp->load();