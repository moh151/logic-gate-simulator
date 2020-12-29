#include "Pin.h"

Pin::Pin()
{
	m_Status = LOW;	//Default Status is LOW
	mGate = NULL;

}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
}

void Pin::SetGate(Gate* pGate) {
																									
	mGate = pGate;
}

Gate* Pin::GetGate() const {
	return mGate;
}


STATUS Pin::getStatus()
{
	return m_Status;
}