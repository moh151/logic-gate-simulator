#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	int CompCount; //Actual number of Components
	Component* obj;  //component object for label setter and getter
	Component* CopiedComp;

public:

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	Component* GetCompenentList(int i);
	void UpdateInterface();	//Redraws all the drawing window
	int GetExistingComponentsCount() const;
	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	int getComponentCount();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	//saving loop
	void saveall(ofstream& obj);
	//editing loop
	void editall(string labe);
	int getNumberOfLEDS(); 
	int getNumberOfSwitchs();
	void loadall(ifstream& obj);
	// Sets a selection value to all components 
	void SetSelectionOfComponents(bool s);
	// Sets the last copied/cut component 
	void SetCopiedComp(Component* pComp);

	// Returns the last copied/cut component 
	Component* GetCopiedComp()const;
	//Removes a component to the list of components 
	void ApplicationManager::DeleteComp(float x, float y);
	Component* ApplicationManager::selected(float x, float y);
	//destructor
	~ApplicationManager();
};

#endif