#ifndef _ADD_LABEL_H
#define _ADD_LABEL_H

#include "..\Actions\Action.h"

class AddLabel : public Action
{
private:
	int Cx, Cy;	//Centre of the text
public:
	AddLabel(ApplicationManager* pApp);
	virtual ~AddLabel(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

#endif
