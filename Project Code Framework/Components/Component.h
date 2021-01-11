#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
protected:
	string m_Label;
	bool mSelected;			
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	int ID = 0;  // the ID of each component
	string nameofcomp; //to save the name of the component away from it's label given by the user
public:
	GraphicsInfo getGraphicsinfo();
	Component(const GraphicsInfo& r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1
	void SetSelected(bool s);
	bool IsSelected() const;
	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.
	void setLabel(string s);
	////////////////////////////////////
	//to save this action
	virtual void save(ofstream& Save) = 0;
	//to load this action
	virtual void load(ifstream& Load) = 0;
	//label setter
	//void setLabel(string l);
	virtual void edit(string l) = 0;
	int getID();
	//virtual void edit(string newlabel);
	/////////////////////////////////////
	Component();

	//Destructor must be virtual
	virtual ~Component();
};

#endif
