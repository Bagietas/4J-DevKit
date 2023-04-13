#pragma once

enum eMenus
{
	MainMenu, HostMenu1
};

//Initial vars
const wchar_t* titleSPRX = L"DownCraft SPRX";
int MenuX = -51, MenuY = 6, menuLenght = 0,
MenuR = 0, MenuG = 147, MenuB = 255;

//Rainbow color
int MenuColourTime = 0, RainbowTime = 0, RainbowRED1, RainbowGREEN1, RainbowBLUE1, RainbowRED2, RainbowGREEN2, RainbowBLUE2, RainbowColor[3];
int Rainbow[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };

//Scroller
bool gotTime[1000], keyPressed[100], freeFirst[100], resetWait[100], resetWait2[100], lockFirst[100];
int getTime[1000], firstWaitTime = 15, waitTime = 5, scrollTick = 0, timeMath[1000], scroll = 0;

//Menu settings
int CurrentMenu, CurrentOpt, MaxOption, MaxSubOptions, optionPress, returnPress, SpaceBetweenText = 11;
bool UsableMenu = true, Opened, Closed, FirstOpen;
char* ThemeColors = "RGB";

//Main Page
bool GodMode, DemiGodMode;