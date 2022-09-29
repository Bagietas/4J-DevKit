#pragma once

char* checkTxt = "";
wchar_t charA2wcharA_[1000];

//Scroller
bool gotTime[1000], keyPressed[100], freeFirst[100], resetWait[100], resetWait2[100], lockFirst[100];
int getTime[1000], firstWaitTime = 15, waitTime = 5, scrollTick = 0, timeMath[1000], scroll = 0;

//menu
int CurrentMenu, CurrentOpt, MaxOption, MaxSubOptions;
bool Opened, Closed;
int MenuColorAlpha = 255, MenuColorAlphaTitle = 255, MenuColorAlphaDescription = 255;
