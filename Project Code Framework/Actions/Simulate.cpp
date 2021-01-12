#include "Simulate.h"
#include<iostream>
using namespace std;
/* Constructor */
Simulate::Simulate(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void Simulate::ReadActionParameters() {
	return;
}

void Simulate::Execute()
{
	Output* pOut = pManager->GetOutput();
	int countLeds = pManager->getNumberOfLEDS();
	int count = pManager->GetExistingComponentsCount();
	int countSwitch = pManager->getNumberOfSwitchs();
	if (count == 0) {
		pOut->PrintMsg("Invalid no components in the circuit");
		return;
	}
	else if (countLeds == 0) {
		pOut->PrintMsg("Invalid no LEDS in the circuit");
		return;
	}
	else if (countSwitch == 0) {
		pOut->PrintMsg("Invalid no Switchs in the circuit");
		return;
	}
	else {
		pOut->CreateSimulationToolBar();

	}
}

	//Circuit Validation To ADD 


		//if (pComp != NULL) {
			//if (dynamic_cast<SWITCH*>(pComp)) {
				//pComp->GetOutPinStatus();
			//}
//			else if (dynamic_cast<Gate*>(pComp)) {
//				pComp->Operate();
//			}
//		}
//}




	void Simulate::Undo() {
		return;
	}

	/* Redo action */
	void Simulate::Redo() {
		return;
	}


/* Destructor */
Simulate::~Simulate() {

}