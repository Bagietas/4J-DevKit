#pragma once

namespace Buttons
{
	unsigned int buttonMonitoring = 0x3000CF79; //Address Buttons 1.84!
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
		JOYSTICK_L3_RIGHT = 0x00400000
		;

	unsigned int getMCButtons()
	{
		return *(unsigned int*)(buttonMonitoring);
	}

	bool IsMCButtonPressed(unsigned int Buttons)
	{
		return (getMCButtons() & Buttons) > 0;
	}
}

namespace Menu
{
	bool InWorld()
	{
		return !(*(char*)0x3000CF6B != 0);
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
}