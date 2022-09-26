#pragma once
#include "framework.h"
#include "globals.h"
#include "sdk.h"
#include "ui.h"

extern ImFont* MainCaps;
extern ImFont* Main;
extern ImFont* FMenu;

#define WND_SIZEX GetSystemMetrics(SM_CXSCREEN) 
#define WND_SIZEY GetSystemMetrics(SM_CYSCREEN)

class cMenu
{
public:
	void DrawMenu();
	void DisplaySettings();
};