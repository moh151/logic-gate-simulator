#include "XOR3.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_Label = "XOR3";
	ID = 13;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
}


void XOR3::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH || m_InputPins[1].getStatus() == HIGH || m_InputPins[1].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else if(m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	//caclulate the output status as the XORing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 3-input XOR gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	if (m_GfxInfo.y1 >= 0 && m_GfxInfo.y2 < (UI.DesignBarHeight)) {
		pOut->PrintMsg("Invalid Postion");
	}
	else {
	pOut->DrawXOR3(m_GfxInfo, mSelected);
	}
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR3::save(ofstream& Save)
{
	Save << "XOR3" << "  " << ID << "  " << m_Label << "  " << m_GfxInfo.x1 << "   " << m_GfxInfo.y1 << "  " << endl;

}
void XOR3::load(ifstream& Load)
{
	Load >> nameofcomp >> ID >> m_Label >> m_GfxInfo.x1 >> m_GfxInfo.y1;
}
void XOR3::edit(string l)
{
	m_Label = l;
}