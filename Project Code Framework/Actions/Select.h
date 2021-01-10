#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

class ApplicationManager;

class Select : public Action 
{
private:
	int xs;
	int ys;
public:
	/* Constructor */
	Select(ApplicationManager* pApp);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();
	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();
};