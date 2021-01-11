#pragma once
#include "action.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class load : public Action
{
private:
	int Cx, Cy;
public:
	ifstream Loading;
	load(ApplicationManager* pApp);
	virtual ~load(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	

};
