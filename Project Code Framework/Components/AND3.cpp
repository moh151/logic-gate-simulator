#include "AND3.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "..\Actions\load.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_Label = "AND3";
	ID = 3;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the three input pins
	if (m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == HIGH && m_InputPins[0].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}

}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (m_GfxInfo.y1 >= 0 && m_GfxInfo.y2 < (UI.DesignBarHeight)) {
		pOut->PrintMsg("Invalid Postion");
	}
	else {
		pOut->DrawAND3(m_GfxInfo, mSelected);
	}
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void AND3::save(ofstream& Save)
{
	Save << "AND3" << "  " << ID << "  " << m_Label << "  " << m_GfxInfo.x1 << "   " << m_GfxInfo.y1 << "  " << endl;
}

void AND3::load(ifstream& Load)
{
	/*ifstream load;
	load.open("save.text");
	//for checking errors

	if (load.fail())
	{
		cerr << "error opening file" << endl;
		exit(1);
	}*/

	Load >> nameofcomp >> ID >> m_Label >> m_GfxInfo.x1 >> m_GfxInfo.y1;


}
void AND3::edit(string l)
{
	m_Label = l;
}