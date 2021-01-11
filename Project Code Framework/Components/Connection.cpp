#include "Connection.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>


Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::editconnection(string newlabel, OutputPin* newSrcPin, InputPin* newDstPin)
{
	m_Label = newlabel;
	SrcPin = newSrcPin;
	DstPin = newDstPin;
}
void Connection::save(ofstream& Save)
{
	OutputPin* n = getSourcePin();
	InputPin* m = getDestPin();
	Save << n << "   " << m << "  " << DstPine << endl;

}
void Connection::load(ifstream& Load)
{

	//Load >> SrcCmpnt >> DstCmpnt>>DstPine ;

}
void Connection::edit(string l, OutputPin* source, InputPin* dest)
{
	m_Label = l;
	setSourcePin(source);
	setDestPin(dest);

}