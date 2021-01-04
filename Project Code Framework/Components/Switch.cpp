#include "Switch.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_Label = "Switch";
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_OutputPin.SetGate(this);
}


void SWITCH::Operate()
{
	bool out = 0;


	if (m_OutputPin.getStatus() == STATUS::HIGH || out) {
		out = 1;
	}
	else {
		out = 0;
	}

	m_OutputPin.setStatus(out ? STATUS::HIGH : STATUS::LOW);	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws the Switch
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(m_GfxInfo, false, m_OutputPin.getStatus() == STATUS::HIGH);
}

Pin* SWITCH::GetInputPin(int n) {
	return NULL;
}
Pin* SWITCH::GetOutputPin() {
	return &m_OutputPin;
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}
