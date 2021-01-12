#include "AddConnection.h"
#include "..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on source gate");

	//Wait for User Input
	pIn->GetPointClicked(x1, y1);

	//Print Action Message
	pOut->PrintMsg("Click on destination gate");

	//Wait for User Input
	pIn->GetPointClicked(x2, y2);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int px1 = 0;
	int py1 = 0;
	int px2 = 0;
	int py2 = 0;
	for (int i = 0; i < pManager->getComponentCount(); i++)
	{
		Component* pComp = pManager->GetCompenentList(i);
		if (pComp->getGraphicsinfo().x1 < x1 && pComp->getGraphicsinfo().x2 > x1 && pComp->getGraphicsinfo().y1 < y1 && pComp->getGraphicsinfo().y2 > y1)
		{
			py1 = pComp->getGraphicsinfo().y1 + 24;
			px1 = pComp->getGraphicsinfo().x2;
		}
	}

	for (int i = 0; i < pManager->getComponentCount(); i++)
	{
		Component* pComp = pManager->GetCompenentList(i);
		if (pComp->getGraphicsinfo().x1 < x2 && pComp->getGraphicsinfo().x2 > x2 && pComp->getGraphicsinfo().y1 < y2 && pComp->getGraphicsinfo().y2 > y2)
		{
			int length = pComp->getGraphicsinfo().y2 - pComp->getGraphicsinfo().y1;
			if (((Gate*)pComp)->getInputPins() == 3)
			{
				if (y2 > pComp->getGraphicsinfo().y1 && y2 < (pComp->getGraphicsinfo().y1 + (length / 3))) {
					py2 = (pComp->getGraphicsinfo().y1 + 12);
					px2 = pComp->getGraphicsinfo().x1;
				}
				else if (y2 > (pComp->getGraphicsinfo().y1 + (length / 3)) && y2 < (pComp->getGraphicsinfo().y2 - (length / 3))) {
					py2 = (pComp->getGraphicsinfo().y1 + 24);
					px2 = pComp->getGraphicsinfo().x1;
				}
				else if (y2 > (pComp->getGraphicsinfo().y2 - (length / 3)) && y2 < pComp->getGraphicsinfo().y2) {
					py2 = (pComp->getGraphicsinfo().y1 + 36);
					px2 = pComp->getGraphicsinfo().x1;
				}
			}

			else if (((Gate*)pComp)->getInputPins() == 2)
			{
				if (y2 > pComp->getGraphicsinfo().y1 && y2 < (pComp->getGraphicsinfo().y1 + (length / 2))) {
					py2 = (pComp->getGraphicsinfo().y1 + 12);
					px2 = (pComp->getGraphicsinfo().x1);
				}
				else if (y2 > (pComp->getGraphicsinfo().y1 + (length / 2)) && y2 < pComp->getGraphicsinfo().y2) {
					py2 = (pComp->getGraphicsinfo().y2 - 12);
					px2 = (pComp->getGraphicsinfo().x1);
				}
			}

			else if (((Gate*)pComp)->getInputPins() == 1)
			{
				py2 = (pComp->getGraphicsinfo().y1 + 24);
				px2 = (pComp->getGraphicsinfo().x1);
			}
			else
			{
				pOut->PrintMsg("Invalid input pin");
			}
		}
	}
	GraphicsInfo GInfo;

	GInfo.y1 = py1;
	GInfo.x1 = px1;
	GInfo.x2 = px2;
	GInfo.y2 = py2;
	pOut->DrawConnection(GInfo);

	//Connection* pA = new Connection(GInfo);
	//pManager->AddComponent(pA);
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}