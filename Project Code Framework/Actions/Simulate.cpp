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

void Simulate::Execute(Component* pComp)
{
	int count = pManager->GetExistingComponentsCount();
	Output* pOut = pManager->GetOutput();
	//Circuit Validation To ADD
	pOut->CreateSimulationToolBar();
		if (pComp != NULL) {
			if (dynamic_cast<SWITCH*>(pComp)) {
				pComp->GetOutPinStatus();
			}
			else if (dynamic_cast<Gate*>(pComp)) {
				pComp->Operate();
			}
		}
}




/* Undo action */
void Simulate::Undo() {
}

/* Redo action */
void Simulate::Redo() {
}

/* Destructor */
Simulate::~Simulate() {

}