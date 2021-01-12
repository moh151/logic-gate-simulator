#include "NOR3.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_Label = "NOR3";
	ID = 9;
	m_Label= "NOR3";
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
}


void NOR3::Operate()
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
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	if (m_GfxInfo.y1 >= 0 && m_GfxInfo.y2 < (UI.DesignBarHeight)) {
		pOut->PrintMsg("Invalid Postion");
	}
	else {
		pOut->ClearStatusBar();
	pOut->DrawNOR3(m_GfxInfo, mSelected);

	}
}


//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR3::save(ofstream& Save)
{
	Save << "NOR3" << "  " << ID << "  " << m_Label << "  " << m_GfxInfo.x1 << "   " << m_GfxInfo.y1 << "  " << endl;

}
void NOR3::load(ifstream& Load)
{
	Load >> nameofcomp >> ID >> m_Label >> m_GfxInfo.x1 >> m_GfxInfo.y1;

}
void NOR3::edit(string l)
{
	m_Label = l;
}