#pragma once

enum eMenus
{
	MainMenu, MainOptions, SettingsMenu, CreditsMenu
};

enum eColors
{
	DarkRed, Red, Gold, Yellow, DarkGreen, Green, Aqua, DarkAqua, DarkBlue, Blue, LightPurple, DarkPurple, White, Gray, DarkGray, Black
};

namespace MC_Color
{
	int DarkRed[3] = { 170, 0, 0 };
	int Red[3] = { 255, 85, 85 };
	int Gold[3] = { 255, 170, 0 };
	int Orange[3] = { 255, 143, 16 };
	int Yellow[3] = { 255, 255, 85 };
	int DarkGreen[3] = { 0, 170, 0 };
	int Green[3] = { 85, 255, 85 };
	int Aqua[3] = { 85, 255, 255 };
	int DarkAqua[3] = { 0, 170, 170 };
	int DarkBlue[3] = { 0, 0, 170 };
	int Blue[3] = { 85, 85, 255 };
	int LightPurple[3] = { 255, 85, 255 };
	int DarkPurple[3] = { 170, 0, 170 };
	int White[3] = { 255, 255, 255 };
	int Gray[3] = { 170, 170, 170 };
	int DarkGray[3] = { 85, 85, 85 };
	int Black[3] = { 0, 0, 0 };
	int BlackTheme[3] = { 32, 32, 32 };
	int TitleColor[3] = { 10, 253, 240 };
};

//Initial Vars
const wchar_t* titleSPRX = L"Minecraft SPRX";
int MenuR = 0, MenuG = 147, MenuB = 255;
int MenuX, MenuY;

//Others vars
char* checkTxt = "";
wchar_t charA2wcharA_[1000];
uint32_t cpu_t = 0;
uint32_t rsx_t = 0;


//Scroller
bool gotTime[1000], keyPressed[100], freeFirst[100], resetWait[100], resetWait2[100], lockFirst[100];
int getTime[1000], firstWaitTime = 15, waitTime = 5, scrollTick = 0, timeMath[1000], scroll = 0;

//Menu settings
int CurrentMenu, CurrentOpt, MaxOption, MaxSubOptions, optionPress, returnPress, SpaceBetweenText = 11;
bool BtnLeftPressed, BtnRightPressed;
bool Opened, Closed, FirstOpen, GradientMenu;
int MenuColorAlpha = 255, MenuColorAlphaTitle = 255, MenuColorAlphaDescription = 255;
int SavePosition, AnimationSpeed = 10;
int SaveMenuX, speedSlider = 10, menuLenght, MenuBorderSize;
char* ThemeColors = "RGB";

//Main Options
bool GodMode, SuperSpeed;

//Rainbow color
int MenuColourTime = 0, RainbowTime = 0, RainbowRED1, RainbowGREEN1, RainbowBLUE1, RainbowRED2, RainbowGREEN2, RainbowBLUE2, RainbowColor[3];
int Rainbow[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };

int lastMenus[20];
int lastMenuCount = 0;