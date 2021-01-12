#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

class Copy : public Action
{
private:
	int mX, mY;				// The point clicked by the user
	Component* mComp;		// Pointer to the copied component
	Component* pComp;
public:
	/* Constructor */
	Copy(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
   virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Copy();
};