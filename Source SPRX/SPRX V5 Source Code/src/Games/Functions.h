#pragma once

#pragma region "Function Colors"

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

int* GetThemeRainbow()
{
	int RAINBOW[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };
	return RAINBOW;
}

int* GetThemeColor()
{
	int RGB[] = { MenuR, MenuG, MenuB };
	int* THEME[3];
	if (ThemeColors == "RAINBOW") { THEME[3] = GetThemeRainbow(); }
	else if (ThemeColors == "RGB") { THEME[3] = { RGB }; }
	return THEME[3];
}

#pragma endregion
#pragma region "Buttons"

namespace Buttons
{
	unsigned int
		X = 0x100,
		O = 0x200,
		SQUARE = 0x400,
		TRIANGLE = 0x800,
		UP = 0x40000,
		DOWN = 0x80000,
		LEFT = 0x100000,
		RIGHT = 0x200000,
		R1 = 0x4000,
		R2 = 0x0, //NEED FOUND
		R3 = 0x10000,
		L1 = 0x8000,
		L2 = 0x0, //NEED FOUND
		L3 = 0x20000,
		START = 0x2000,
		SELECT = 0x1000,
		JOYSTICK_L3_UP = 0x20000000,
		JOYSTICK_L3_DOWN = 0x10000000,
		JOYSTICK_L3_LEFT = 0x00800000,
		JOYSTICK_L3_RIGHT = 0x00400000;

	unsigned int getMCButtons()
	{
		return *(unsigned int*)(0x3000CF79);
	}

	bool IsMCButtonPressed(unsigned int Buttons)
	{
		return (getMCButtons() & Buttons) > 0;
	}
}

#pragma endregion
#pragma region "Menu Function"
int getOption()
{
	if (optionPress)
	{
		optionPress = false;
		return CurrentOpt;
	}
	else return -1;
}

int lastMenus[20];
int lastMenuCount = 0;
void openSubmenu(int menu)
{
	lastMenus[lastMenuCount] = CurrentMenu;
	lastMenuCount++;
	CurrentOpt = 0;
	CurrentMenu = menu;
}

void closeSubmenu()
{
	lastMenuCount = 0;
	CurrentOpt = 0;
	Opened = false;
}

void goBack()
{
	if (lastMenuCount == 0)
	{
		closeSubmenu();
	}
	else
	{
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

typedef int64_t _QWORD;
struct timer_fade
{
	wchar_t* message;
	int color[3];
	_QWORD start_time;
	_QWORD end_time;
	int duration;
};
timer_fade logs[12];

void AddNotification(wchar_t* notification = L"", int* color = MC_Color::WHITE, int duration = 10000)
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
	logs[0].message = notification;
	logs[0].color[0] = color[0];
	logs[0].color[1] = color[1];
	logs[0].color[2] = color[2];
	logs[0].start_time = get_time_now();
	logs[0].end_time = logs[0].start_time + duration;
	if (logs_count < 11)
		logs_count++;
}

void draw_notif()
{
	if (logs[0].message != NULL)
	{
		if (logs_count > -1)
		{
			DrawRectangleAlpha(0, 257, 190, 246 - (10 * logs_count), MC_Color::BLACK_OPACITY);
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
#pragma endregion