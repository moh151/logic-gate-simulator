#include "NOR2.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_Label = "NOR2";
	ID = 8;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
}


void NOR2::Operate()
{
	//caclulate the output status as the NORing of the two input pins
	if (m_InputPins[1].getStatus() == LOW && m_InputPins[0].getStatus() == LOW)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}

}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	if (m_GfxInfo.y1 >= 0 && m_GfxInfo.y2 < (UI.DesignBarHeight)) {
		pOut->PrintMsg("Invalid Postion");
	}
	else {
		pOut->ClearStatusBar();
	pOut->DrawNOR2(m_GfxInfo, mSelected);
	}
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR2::save(ofstream& Save)
{

	Save << "NOR2" << "  " << ID << "   " << m_Label << "  " << m_GfxInfo.x1 << "   " << m_GfxInfo.y1 << "  " << endl;

}
void NOR2::load(ifstream& Load)
{
	Load >> nameofcomp >> ID >> m_Label >> m_GfxInfo.x1 >> m_GfxInfo.y1;
}
void NOR2::edit(string l)
{
	m_Label = l;
}