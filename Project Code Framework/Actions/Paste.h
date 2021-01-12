#pragma once
#include "..\Actions\Action.h"
#include "..\Actions\AddConnection.h"
#include "..\ApplicationManager.h"
#include "..\Components\Gate.h"
#include "..\Components\AND2.h"
#include "..\Components\AND3.h"
#include "..\Components\NAND.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\OR2.h"
#include "..\Components\XOR2.h"
#include "..\Components\XOR3.h"
#include "..\Components\XNOR.h"
#include "..\Components\INVERTER.h"

class Paste : public Action
{
private:
	Component* mComp;		// Pointer to the pasted component
	Action* mAct;			// Add component action
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	/* Constructor */
	Paste(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Paste();
};

