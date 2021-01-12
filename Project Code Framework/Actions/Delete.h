#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"


class Delete : public Action
{
private:
	
	int dX, dY;
	Component* Comp;
public:
	/* Constructor */
	Delete(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	/* Destructor */
	virtual ~Delete();
};
