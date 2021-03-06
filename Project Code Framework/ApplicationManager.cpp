#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddBuffer.h"
#include "Actions\AddLED.h"
#include "Actions\AddNOR3.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddXNORgate.h"
#include "Actions\Addswitch.h"
#include "Actions/AddLabel.h"
#include "Actions/Select.h"
#include "Actions\save.h"
#include "Actions\edit.h"
#include "Actions\load.h"
#include "Actions\AddConnection.h"
#include "Actions\Simulate.h"
#include "Actions/Copy.h"
#include "Actions/Cut.h"
#include "Actions/Paste.h"
#include "Actions/Delete.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
	
}
////////////////////////////////////////////////////////////////////

int ApplicationManager::GetExistingComponentsCount() const {
	int n = 0;

	for (int i = 0; i < CompCount; i++) {
			n++;
	}

	return n;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_Switch:
			pAct = new AddSWITCH(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case ADD_Buff:
			pAct = new AddBuffer(this);
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNOR3(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_INV:
			pAct = new AddNOTgate(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate(this);
			break;
		case ADD_Label:
			pAct = new AddLabel(this);
			break;
		case EXIT:
			///TODO: create ExitAction here
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case SAVE:
			pAct = new save(this);
			break;
		case EDIT_Label:
			pAct = new edit(this);
			break;
		case LOAD:
			pAct = new load(this);
			break;
		case SIM_MODE:
			pAct = new Simulate(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}

void ApplicationManager::loadall(ifstream& obj)
{

	for (int i = 0; i < CompCount; i++)
		CompList[i]->load(obj);
}
Component* ApplicationManager::GetCompenentList(int i)
{
	return CompList[i];
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{

		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}
int ApplicationManager::getNumberOfLEDS()
{
	int count = 0;
	for (int i = 0; i < CompCount; i++)
	{
		LED* L = dynamic_cast<LED*>(CompList[i]);
		if (L != NULL)
			count++;
	}
	return count;
}

int ApplicationManager::getNumberOfSwitchs()
{
	int count = 0;
	for (int i = 0; i < CompCount; i++)
	{
		SWITCH* S = dynamic_cast<SWITCH*>(CompList[i]);
		if (S != NULL)
			count++;
	}
	return count;
	


}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

int ApplicationManager::getComponentCount()
{
	return CompCount;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::saveall(ofstream& obj)
{

	for (int i = 0; i < CompCount; i++)
		CompList[i]->save(obj);


}
void ApplicationManager::editall(string labe)
{

	for (int i = 0; i < CompCount; i++)
		CompList[i]->edit(labe);

}


void ApplicationManager::SetCopiedComp(Component* pComp) {
	CopiedComp = pComp;
}
void ApplicationManager::SetSelectionOfComponents(bool s) {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetSelected(s);
	}
}

/* Returns the last copied/cut component */
Component* ApplicationManager::GetCopiedComp() const {
	return CopiedComp;
}
void ApplicationManager::DeleteComp(float x, float y) {
	int i = 0;
	while (i < CompCount && CompList[i] != NULL)
	{
		if (CompList[i]->IsSelected())
		{
			delete CompList[i];
			CompList[i] = NULL;
		}
		i++;
	}
	int a;
	for (int j = 0; j < CompCount; j++)
	{
		if (CompList[j] == NULL)
			a = j;
	}
	for (int k = a; k < CompCount; k++)
	{
		CompList[k] = CompList[k + 1];
	}
	CompList[CompCount] = NULL;
	CompCount--;
}
Component* ApplicationManager::selected(float x, float y)
{
	int i = 0;
	while (i < CompCount)
	{
		if (CompList[i]->IsSelected())
			return CompList[i];
		i++;
	}
	return NULL;
}


ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}