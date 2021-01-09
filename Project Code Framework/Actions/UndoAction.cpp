#include "UndoAction.h"

/* Constructor */
UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void UndoAction::ReadActionParameters() {

}

/* Executes action */
void UndoAction::Execute() {
	pManager->Undo();
	pManager->GetOutput()->ClearStatusBar();

}

/* Undo action */
void UndoAction::Undo() {
	return;
}

/* Redo action */
void UndoAction::Redo() {
	return;
}

/* Destructor */
UndoAction::~UndoAction() {

}