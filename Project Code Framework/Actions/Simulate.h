#pragma once
#include "..\Actions\Action.h"
#include "..\GUI\UI_Info.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Components\LED.h"
#include "..\Components\Connection.h"
#include "..\Components\AND2.h"
#include "..\Components\AND3.h"
#include "..\Components\Buffer.h"
#include "..\Components\Gate.h"
#include "..\Components\INVERTER.h"
#include "..\Components\NAND.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\OR2.h"
#include "..\Components\XNOR.h"
#include "..\Components\XOR2.h"8
#include "..\Components\XOR3.h"
#include <string>
using namespace std;

class Simulate : public Action
{
private:
	bool mStopSimulation;
public:
	/* Constructor */
	Simulate(ApplicationManager* pAppMan);

	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute(Component* pComp);



	virtual void Undo();

	virtual void Redo();

	/* Destructor */
	virtual ~Simulate();
};
