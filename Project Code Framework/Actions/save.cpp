#include"save.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
save::save(ApplicationManager* pApp) :Action(pApp)
{

}

save::~save(void)
{
}
void save::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("saving the components info..click anywhere to continue");

	//giving the name of the file we are saving in
		 //Save;
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void save::Execute()
{

	ReadActionParameters();

	Saving.open("save.txt");
	//for checking errors
	if (Saving.fail())
	{
		cerr << "error opening file" << endl;
		exit(1);
	}
	else //sucsses
	{
			pManager->saveall(Saving);

		
		Saving.close();
	}
}
void save::Undo()
{}

void save::Redo()
{}