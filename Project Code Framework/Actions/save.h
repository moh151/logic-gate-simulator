#pragma once
#include "action.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class save : public Action
{
private:
	int Cx, Cy;	
public:
	ofstream Saving;
	save(ApplicationManager* pApp);
	virtual ~save(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	
};
