#ifndef _PIN_H
#define _PIN_H

#include "..\Defs.h"
class Gate;
class Pin
{
protected:
	STATUS m_Status;	//Status of the Pin
public:
	Pin();
	void setStatus(STATUS r_Status);
	STATUS getStatus();
	void SetGate(Gate* pGate);
	Gate* mGate;
	Gate* GetGate() const;
};

#endif