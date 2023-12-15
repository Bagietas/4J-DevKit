#pragma once

enum eMenus
{
	MainMenu, MainOptions, TeleportMenu, SettingsPage, SettingsMenu, ColorMenu, InformationMenu, CreditsMenu
};

//Initial Vars
char* Username;
char* Region;
int MenuR = 0, MenuG = 147, MenuB = 255, MenuA = 200, MenuGradient1R = 0, MenuGradient1G = 0, MenuGradient1B = 255, MenuGradient2R = 0, MenuGradient2G = 255, MenuGradient2B = 0;
int MenuX = 0, MenuY = 0;

//Others vars
char* checkTxt = "";
wchar_t charA2wcharA_[1000];
uint32_t cpu_t = 0;
uint32_t rsx_t = 0;


//Scroller
bool gotTime[1000], keyPressed[100], freeFirst[100], resetWait[100], resetWait2[100], lockFirst[100];
int getTime[1000], firstWaitTime = 15, waitTime = 5, scrollTick = 0, timeMath[1000], scroll = 0;

//Menu settings
int boolStyle = 0;
int BackgroundStyle = 0;
int CurrentMenu, CurrentOpt, CurrentIndex, MaxOption, MaxSubOptions, MaxArrayList, optionPress, returnPress, SpaceBetweenText = 11;
bool ShowLogo = true, BtnLeftPressed, BtnRightPressed, Opened, Closed, FirstOpen, GradientMenu;
int MenuColorAlpha = 255, MenuColorAlphaTitle = 255, MenuColorAlphaDescription = 255, SavePosition, AnimationSpeed = 10, SaveMenuX, speedSlider = 10, menuLenght = 45, MenuBorderSize;
char* ThemeColors = "DEFAULT";

//Array Information
char GetUsername[0x100], GetPosition[0x100], GetResolution[0x100], GetChunk[0x100], GetDimension[0x100], GetEntityID[0x100], GetTemp[0x100], GetGametime[0x100];
wchar_t wGetUsername[0x100], wGetPosition[0x100], wGetResolution[0x100], wGetChunk[0x100], wGetDimension[0x100], wGetEntityID[0x100], wGetTemp[0x100], wGetGametime[0x100];
bool ShowUsername, ShowResolution, ShowPosition, ShowChunk, ShowDimension, ShowEntityID, ShowTemp, ShowGametime;

//Teleport options
int CoordX, CoordY, CoordZ;

//Main Options
bool RainbowMenu, RainbowGradient, GodMode, SuperSpeed;

//Rainbow color
int MenuColourTime = 0, RainbowTime = 0, RainbowRED1, RainbowGREEN1, RainbowBLUE1, RainbowRED2, RainbowGREEN2, RainbowBLUE2, RainbowColor[3];
int Rainbow[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };

//Get gametime
int milliseconds, seconds, minutes, hours;

int lastMenus[20];
int lastMenuCount = 0;