#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	UI.ConnColor = BLACK;
	UI.ConnOnColor = color(139, 195, 74);
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\and.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\or.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\exit.jpg";
	MenuItemImages[ITM_Buffer] = "images\\Menu\\buffer.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\not.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\nand.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\xor.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\nor.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\nor3.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\xnor.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\led.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\connection.jpg";
	MenuItemImages[ITM_DEL] = "images\\toolbar\\delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\toolbar\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\toolbar\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\toolbar\\paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\toolbar\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\toolbar\\load.jpg";
	MenuItemImages[ITM_EDIT] = "images\\toolbar\\edit.jpg";
	MenuItemImages[ITM_SWITCH_SIM] = "images\\toolbar\\play.jpg";
	//MenuItemImages[ITM_LABEL] = "images\\toolbar\\label.jpg";


int j=0;
//TODO: Prepare image for each menu item and add it to the list
for (int i = 0; i < ITM_DSN_CNT; i++) {
	if (i < 15) {
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	else {

				pWind->DrawImage(MenuItemImages[i], j * UI.ActionItemWidth, UI.ToolBarHeight, UI.ActionItemWidth, UI.ActionItemHeight);
				j++;
	}
}
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\and.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\or.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\exit.jpg";
	MenuItemImages[ITM_Buffer] = "images\\Menu\\buffer.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\not.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\nand.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\xor.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\nor.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\nor3.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\xnor.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\led.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\connection.jpg";
	

//	for (int i = 0; i < ITM_DSN_CNT; i++)
	//	pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth,0, UI.ToolItemWidth,UI.ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//
void Output::DrawString(string str) const
{
	ClearDrawingArea();
	pWind->SetBrush(RED);
	pWind->DrawString(350, 425, str);
}

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\and.jpg";
	else
		GateImage = "Images\\Gates\\active\\and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}
//TODO: Add similar functions to draw all components

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\nand.jpg";
	else
		GateImage = "Images\\Gates\\active\\nand.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\or.jpg";
	else
		GateImage = "Images\\Gates\\active\\or.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\nor.jpg";
	else
		GateImage = "Images\\Gates\\active\\nor.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\xnor.jpg";
	else
		GateImage = "Images\\Gates\\active\\xnor.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\xor.jpg";
	else
		GateImage = "Images\\Gates\\active\\xor.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\buffer.jpg";
	else
		GateImage = "Images\\Gates\\active\\buffer.jpg";

	//Draw Buffer Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by Buffer Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\not.jpg";
	else
		GateImage = "Images\\Gates\\active\\not.jpg";

	//Draw INV Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by INV Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\and3.jpg";
	else
		GateImage = "Images\\Gates\\active\\and3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\nor3.jpg";
	else
		GateImage = "Images\\Gates\\active\\nor3.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\highlighted\\xor3.jpg";
	else
		GateImage = "Images\\Gates\\active\\xor3.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected, bool on) const
{
	string GateImage;
	if (UI.AppMode == MODE::SIMULATION && on)	//use image in the highlighted case
		GateImage = "Images\\Gates\\active\\switch_on.jpg";
	else if (selected)
		GateImage = "Images\\Gates\\highlighted\\switch_off.jpg";
	else
		GateImage = "Images\\Gates\\active\\switch_off.jpg";
	//Draw SWITCH Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by SWITCH Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_LED_Width, UI.Switch_LED_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected, bool on) const
{
	string GateImage;
	if (UI.AppMode == MODE::SIMULATION && on)	//use image in the highlighted case
		GateImage = "Images\\Gates\\active\\led_on.jpg";
	else if (selected)
		GateImage = "Images\\Gates\\highlighted\\led_off.jpg";
	else
		GateImage = "Images\\Gates\\active\\led_off.jpg";
	//Draw LED Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_LED_Width, UI.Switch_LED_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected,bool on) const
{
	//TODO: Add code to draw connection
	color c;

	if (UI.AppMode == MODE::SIMULATION)
		c = (on ? UI.ConnOnColor : UI.ConnColor);
	else
		c = (selected ? UI.SelectColor : UI.ConnColor);

	pWind->SetPen(c, 2);

	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1 ,r_GfxInfo.x2, r_GfxInfo.y2);
	
}


Output::~Output()
{
	delete pWind;
}
