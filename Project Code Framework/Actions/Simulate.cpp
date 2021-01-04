#include "Simulate.h"
#include<iostream>
using namespace std;
/* Constructor */
Simulate::Simulate(ApplicationManager* pApp) : Action(pApp) {
	mStopSimulation = false;
}

/* Reads parameters required for action to execute */
void Simulate::ReadActionParameters() {

}

void Simulate::Execute(Component* pComp)
{

	//pManager->SetSelectionOfComponents(false);

	int count = pManager->GetExistingComponentsCount();
	Output* pOut = pManager->GetOutput();
	if (mStopSimulation || count == 0) {
		ActionType act = ActionType::DSN_MODE;
		pOut->PrintMsg("Circuit is not valid. Cannot start simulation.");

		pManager->ExecuteAction(act);
	}
	else {
		ActionType act = ActionType::SIM_MODE;

		pManager->ExecuteAction(act);
		pOut->CreateSimulationToolBar();
		if (pComp != NULL) {
			if (dynamic_cast<AND2*>(pComp)) {
				((AND2*)pComp)->Operate();
			}
			else if (dynamic_cast<XOR2*>(pComp)) {
				((XOR2*)pComp)->Operate();
			}
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