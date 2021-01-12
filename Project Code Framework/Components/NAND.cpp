#include "NAND.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

NAND::NAND(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_Label = "NAND2";
	ID = 7;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
}


void NAND::Operate()
{
	//caclulate the output status as the NANDing of the two input pins
	if (this->m_InputPins[0].getStatus() == HIGH && this->m_InputPins[1].getStatus() == HIGH)
	{
		this->m_OutputPin.setStatus(LOW);
	}
	else
	{
		this->m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws NAND gate
void NAND::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	if (m_GfxInfo.y1 >= 0 && m_GfxInfo.y2 < (UI.DesignBarHeight)) {
		pOut->PrintMsg("Invalid Postion");
	}
	else {
		pOut->ClearStatusBar();
	pOut->DrawNAND2(m_GfxInfo, mSelected);
	}
}

//returns status of outputpin
int NAND::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NAND::save(ofstream& Save)
{
	Save << "NAND2" << "  " << ID << "  " << m_Label << "  " << m_GfxInfo.x1 << "   " << m_GfxInfo.y1 << "  " << endl;

}
void NAND::load(ifstream& Load)
{
	Load >> nameofcomp >> m_Label >> m_GfxInfo.x1 >> m_GfxInfo.y1;
}
void NAND::edit(string l)
{
	m_Label = l;
}