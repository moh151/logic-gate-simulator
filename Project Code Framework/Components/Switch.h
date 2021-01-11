#pragma once
#ifndef _Switch_H
#define _Switch_H

/*
  Class Switch
  -----------
  represent the Switch
*/

#include "Gate.h"

class SWITCH :public Gate
{
	Pin m_OutputPin;
	Pin m_InputPin;
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the Switch
	virtual void Draw(Output* pOut);	//Draws 2-input gate


	virtual Pin* GetInputPin(int n);
	virtual Pin* GetOutputPin();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	void save(ofstream& Save);
	void load(ifstream& Load);
	void edit(string l);
};

#endif
