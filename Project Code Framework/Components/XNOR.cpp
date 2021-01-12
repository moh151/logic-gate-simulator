#include "XNOR.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

XNOR::XNOR(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_Label = "XNOR";
	ID = 11;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
}


void XNOR::Operate()
{
	//caclulate the output status as the XNORing of the two input pins
	if (this->m_InputPins[0].getStatus() == HIGH && this->m_InputPins[1].getStatus() == HIGH)
	{
		this->m_OutputPin.setStatus(HIGH);
	}
	else if(this->m_InputPins[0].getStatus() == LOW && this->m_InputPins[1].getStatus() == LOW)
	{
		this->m_OutputPin.setStatus(HIGH);
	}
	else
	{
		this->m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws XNOR gate
void XNOR::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	if (m_GfxInfo.y1 >= 0 && m_GfxInfo.y2 < (UI.DesignBarHeight)) {
		pOut->PrintMsg("Invalid Postion");
	}
	else {
		pOut->ClearStatusBar();
	pOut->DrawXNOR2(m_GfxInfo, mSelected);
	}
}

//returns status of outputpin
int XNOR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XNOR::save(ofstream& Save)
{
	Save << "XNOR2" << "  " << ID << "  " << m_Label << "  " << m_GfxInfo.x1 << "   " << m_GfxInfo.y1 << "  " << endl;

}
void XNOR::load(ifstream& Load)
{
	Load >> nameofcomp >> ID >> m_Label >> m_GfxInfo.x1 >> m_GfxInfo.y1;
}
void XNOR::edit(string l)
{
	m_Label = l;
}