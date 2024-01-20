#pragma once

#pragma region "Menu Functions"

//thanks to NyTekCFW
namespace logs
{
	Color BLACK_OPACITY{ 15, 15, 15, 200 };
	typedef int64_t _QWORD;
	signed char logs_count = -1;
	uint64_t get_time_now()
	{
		return sys_time_get_system_time() / 1000;
	}
	struct timer_fade
	{
		wchar_t* message;
		int color[3];
		_QWORD start_time;
		_QWORD end_time;
		int duration;
	};
	timer_fade logs[12];

	void SendNotification(wchar_t* logsmsg = L"", int* color = MC_Color::White, int duration = 10000)//10sec
	{
		for (byte a = 11; a > 0; a--)
		{
			logs[a].message = logs[a - 1].message;
			logs[a].color[0] = logs[a - 1].color[0];
			logs[a].color[1] = logs[a - 1].color[1];
			logs[a].color[2] = logs[a - 1].color[2];
			logs[a].color[3] = 0xFF;
			logs[a].start_time = logs[a - 1].start_time;
			logs[a].end_time = logs[a - 1].end_time;
		}
		logs[0].message = logsmsg;
		logs[0].color[0] = color[0];
		logs[0].color[1] = color[1];
		logs[0].color[2] = color[2];
		logs[0].start_time = get_time_now();
		logs[0].end_time = logs[0].start_time + duration;
		if (logs_count < 11)
			logs_count++;

		PlayUISound(SoundEvent::RANDOM_ORB);
	}

	void draw_logs()
	{
		if (logs[0].message != NULL)
		{
			//Color BLACK_OPACITY = { 25, 25, 25, 200 };
			//(15, 246 - (logs_count * 10), 160, 12 + (10 * logs_count), BLACK_OPACITY);

			if (logs_count > -1)
			{
				//DrawRectangle(0, 246 - (logs_count * 10), 190, 12 + (10 * logs_count), MC_Color::Black);
				Color BLACK_OPACITY{ 15, 15, 15, 210 };
				DrawRectangleAlpha(0, 257, 190, 246 - (10 * logs_count), BLACK_OPACITY);
			}

			for (byte a = 0; a < logs_count + 1; a++)
			{
				DrawText(logs[a].message, 5, 248 - ((a * 10)), color(logs[a].color));
				if (get_time_now() >= logs[a].end_time)
				{
					logs[a].message = L"";
					logs_count--;
				}
			}
		}
	}
}

typedef union RGB
{
	struct
	{
		union { int red; int R; };
		union { int green; int G; };
		union { int blue; int B; };
	};
	int color[3];
} RGB;

RGB MenuColour1 = { 90, 0, 0 };
RGB MenuColour2 = { 0, 0, 180 };

void DoRainbowColor()
{
	if (RainbowTime < mc->gameTime)
	{
		if (MenuColourTime == 0)
		{
			MenuColour1.B++;
			if (MenuColour1.B == 255)
				MenuColourTime = 1;
		}
		else if (MenuColourTime == 1)
		{
			MenuColour1.R--;
			if (MenuColour1.R == 0)
				MenuColourTime = 2;
		}
		else if (MenuColourTime == 2)
		{
			MenuColour1.G++;
			if (MenuColour1.G == 255)
				MenuColourTime = 3;
		}
		else if (MenuColourTime == 3)
		{
			MenuColour1.B--;
			if (MenuColour1.B == 0)
				MenuColourTime = 4;
		}
		else if (MenuColourTime == 4)
		{
			MenuColour1.R++;
			if (MenuColour1.R == 255)
				MenuColourTime = 5;
		}
		else if (MenuColourTime == 5)
		{
			MenuColour1.G--;
			if (MenuColour1.G == 0)
				MenuColourTime = 0;
		}

		if (RainbowTime < mc->gameTime)
		{
			if (MenuColourTime == 0)
			{
				MenuColour2.B++;
				if (MenuColour2.B == 255)
					MenuColourTime = 1;
			}
			else if (MenuColourTime == 1)
			{
				MenuColour2.R--;
				if (MenuColour2.R == 0)
					MenuColourTime = 2;
			}
			else if (MenuColourTime == 2)
			{
				MenuColour2.G++;
				if (MenuColour2.G == 255)
					MenuColourTime = 3;
			}
			else if (MenuColourTime == 3)
			{
				MenuColour2.B--;
				if (MenuColour2.B == 0)
					MenuColourTime = 4;
			}
			else if (MenuColourTime == 4)
			{
				MenuColour2.R++;
				if (MenuColour2.R == 255)
					MenuColourTime = 5;
			}
			else if (MenuColourTime == 5)
			{
				MenuColour2.G--;
				if (MenuColour2.G == 0)
					MenuColourTime = 0;
			}

			if (RainbowGradient)
			{
				MenuGradient1R = MenuColour1.R;
				MenuGradient1G = MenuColour1.G;
				MenuGradient1B = MenuColour1.B;

				MenuGradient2R = MenuColour2.R;
				MenuGradient2G = MenuColour2.G;
				MenuGradient2B = MenuColour2.B;
			}

			if (RainbowMenu)
			{
				MenuR = MenuColour1.R;
				MenuG = MenuColour1.G;
				MenuB = MenuColour1.B;
			}

			RainbowRED1 = MenuColour1.R;
			RainbowGREEN1 = MenuColour1.G;
			RainbowBLUE1 = MenuColour1.B;

			RainbowRED2 = MenuColour2.R;
			RainbowGREEN2 = MenuColour2.G;
			RainbowBLUE2 = MenuColour2.B;

			RainbowTime = mc->gameTime;
		}
	}
}

bool InWorld()
{
	return !(*(char*)0x3000CF6B != 0);
}

bool Initialized = false;
void Loader()
{
	if (Initialized == false)
	{
		if (InWorld)
		{
			Initialized = true;

			Username = PS3LibV2::ReadString(0x3000ACC4);
			Region = PS3LibV2::ReadString(0x3000AD48);

			logs::SendNotification(L"Welcome to DownCraft SPRX V5.0", MC_Color::White);
			logs::SendNotification(L"Press L1 + DPAD UP for open the menu", MC_Color::White);
			logs::SendNotification(L"Menu made by Misaki", MC_Color::White);
		}
	}
}

void DrawLogo()
{
	if (ShowLogo)
	{
		DrawTextWithRectangle(L"DownCraft SPRX", 12, 12, MC_Color::BlackTheme, MC_Color::White, true, 0.5f);
	}
}

void CountIndexPage() {
	const int maxOpt = 20; // Limite maximale pour CurrentOpt
	if (CurrentOpt >= 0 && CurrentOpt < maxOpt) {
		CurrentIndex = CurrentOpt + 1;
	}
}

int* GetThemeColor()
{
	int* THEME;
	int DEFAULT[3] = { MenuR, MenuG, MenuB };
	int RAINBOW[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };
	if (ThemeColors == "DEFAULT") { THEME = DEFAULT; }
	else if (ThemeColors == "RAINBOW") { THEME = RAINBOW; }
	return THEME;
}

int getOption()
{
	if (optionPress)
	{
		optionPress = false;
		return CurrentOpt;
	}
	else return -1;
}

void openSubmenu(int menu)
{
	lastMenus[lastMenuCount] = CurrentMenu;
	lastMenuCount++;
	CurrentOpt = 0;
	CurrentMenu = menu;
}

void closeMenu() {
	lastMenuCount = 0;
	CurrentOpt = 0;
	Opened = false;
}

void goBack() {
	if (lastMenuCount == 0) {
		closeMenu();
	}
	else {
		lastMenuCount--;
		CurrentMenu = lastMenus[lastMenuCount];
		CurrentOpt = 0;
	}
}

void Controller()
{
	int wI = 0;
	keyPressed[wI] = false;

	if (Buttons::IsMCButtonPressed(Buttons::L1) && Buttons::IsMCButtonPressed(Buttons::UP))
	{
		if (!Opened)
		{
			Opened = true;
			CurrentMenu = MainMenu;
			lastMenuCount = 0;
			CurrentOpt = 0;
		}
	}

	if (Opened)
	{
		if (Buttons::IsMCButtonPressed(Buttons::UP))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				CurrentOpt = CurrentOpt - 1;
				return;
			}
		}

		if (Buttons::IsMCButtonPressed(Buttons::DOWN))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				CurrentOpt = CurrentOpt + 1;
				return;
			}
		}

		int fix = MaxSubOptions;
		fix -= 1;

		if (CurrentOpt > fix)
			CurrentOpt = 0;

		if (CurrentOpt < 0)
			CurrentOpt = fix;

		if (Buttons::IsMCButtonPressed(Buttons::X))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				optionPress = true;
				return;
			}
		}

		if (Buttons::IsMCButtonPressed(Buttons::O))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				goBack();
				return;
			}
		}

		if (!keyPressed[wI])
		{
			lockFirst[wI] = false;
			freeFirst[wI] = true;
			resetWait[wI] = true;
			resetWait2[wI] = true;
		}
	}
}

void GetPlayerInfo()
{
	char* dimension;
	switch (mc->theMinecraft->cMultiplayerLocalPlayer->dimension) {
	case -1: dimension = "Nether"; break;
	case 0: dimension = "Overworld"; break;
	case 1: dimension = "The End"; break;
	default: dimension = "Unknown"; 
	}

	if (ShowTemp) 
	{
		if (frameTime(120, 1, false)) 
		{
			char systemperature[100];
			get_temperature(0, &cpu_t);//0 cpu
			get_temperature(1, &rsx_t);//1 rsx
			cpu_t = cpu_t >> 24;
			rsx_t = rsx_t >> 24;
		}
	}


	if (ShowGametime)
	{
		int pos[2] = { 18, 74 };
		milliseconds = mc->gameTime;
		seconds = (milliseconds / 60);
		minutes = seconds / 60;
		hours = minutes / 60;
	}

	_sys_memset(GetResolution, 0, 0x100); _sys_memset(wGetResolution, 0, 0x200);
	_sys_snprintf(GetResolution, 0x100, "Resolution: %ix%i", mc->theMinecraft->displayWidth, mc->theMinecraft->displayHeight);
	StringToWideCharacter(wGetResolution, GetResolution, strlen(GetResolution));
	_sys_memset(GetPosition, 0, 0x100); _sys_memset(wGetPosition, 0, 0x200);
	_sys_snprintf(GetPosition, 0x100, "Position: %i, %i, %i", (int)mc->theMinecraft->cMultiplayerLocalPlayer->posX - 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->posY + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->posZ);
	StringToWideCharacter(wGetPosition, GetPosition, strlen(GetPosition));
	_sys_memset(GetChunk, 0, 0x100); _sys_memset(wGetChunk, 0, 0x200);
	_sys_snprintf(GetChunk, 0x100, "Chunk: (% i, % i, % i)", (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordX + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordY + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordZ + 1);
	StringToWideCharacter(wGetChunk, GetChunk, strlen(GetChunk));
	_sys_memset(GetDimension, 0, 0x100); _sys_memset(wGetDimension, 0, 0x200);
	_sys_snprintf(GetDimension, 0x100, "Dimension: %s", dimension);
	StringToWideCharacter(wGetDimension, GetDimension, strlen(GetDimension));
	_sys_memset(GetUsername, 0, 0x100); _sys_memset(wGetUsername, 0, 0x200);
	_sys_snprintf(GetUsername, 0x100, "Username: %s", Username);
	StringToWideCharacter(wGetUsername, GetUsername, strlen(GetUsername));
	_sys_memset(GetEntityID, 0, 0x100); _sys_memset(wGetEntityID, 0, 0x200);
	_sys_snprintf(GetEntityID, 0x100, "Entity ID: %i", (int)mc->theMinecraft->cMultiplayerLocalPlayer->entityId);
	StringToWideCharacter(wGetEntityID, GetEntityID, strlen(GetEntityID));
	_sys_memset(GetTemp, 0, 0x100); _sys_memset(wGetTemp, 0, 0x200);
	_sys_snprintf(GetTemp, 0x100, "CPU: %iC / RSX: %iC", cpu_t, rsx_t);
	StringToWideCharacter(wGetTemp, GetTemp, strlen(GetTemp));
	_sys_memset(GetGametime, 0, 0x100); _sys_memset(wGetGametime, 0, 0x200);
	_sys_snprintf(GetGametime, 0x100, "Gametime: %ih:%imin:%isec", int(hours % 24), int(minutes % 60), int(seconds % 60));
	StringToWideCharacter(wGetGametime, GetGametime, strlen(GetGametime));
}

#pragma endregion