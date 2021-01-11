#pragma once
#include "action.h"
class edit : public Action 
{
private:
	int Cx, Cy;	//Center point of the gate
	int x, y;
public:
	edit(ApplicationManager* pApp);
	virtual ~edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	
	virtual void Undo();
	virtual void Redo();

};
