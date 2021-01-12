#include "LED.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_Label = "LED";
	ID = 6;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPin.SetGate(this);
	mSelected = false;
}


void LED::Operate()
{
	bool out = 0;

	for (int i = 0; i < m_Inputs; i++) {
		if (m_InputPins[i].getStatus() == STATUS::HIGH || out) {
			out = 1;
		}
		else {
			out = 0;
		}
	}

	m_OutputPin.setStatus(out ? STATUS::HIGH : STATUS::LOW);	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	if (m_GfxInfo.y1 >= 0 && m_GfxInfo.y2 < (UI.DesignBarHeight)) {
		pOut->PrintMsg("Invalid Postion");
	}
	else {
		pOut->ClearStatusBar();
	pOut->DrawLED(m_GfxInfo,mSelected, m_InputPin.getStatus() == STATUS::HIGH);

	}
}

Pin* LED::GetInputPin(int n) {
	return &m_InputPin;
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPin.getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}

void LED::save(ofstream& Save)
{

	Save << "LED" << "  " << ID << "   " << m_Label << "  " << m_GfxInfo.x1 << "   " << m_GfxInfo.y1 << "  " << endl;

}
void LED::load(ifstream& Load)
{
	Load >> nameofcomp >> ID >> m_Label >> m_GfxInfo.x1 >> m_GfxInfo.y1;
}
void LED::edit(string l)
{
	m_Label = l;
}