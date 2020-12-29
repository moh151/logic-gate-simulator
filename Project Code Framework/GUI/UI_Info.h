#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)

	static const int	width = 1445, height = 750,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 96;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color
	color ConnOnColor;


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	GATE_Width = 80,		// Gates Image default width
		GATE_Height = 48;		// Gates Image default height
	static const int Switch_LED_Width = 48, Switch_LED_Height = 48;




}UI;	//create a single global object UI


#endif