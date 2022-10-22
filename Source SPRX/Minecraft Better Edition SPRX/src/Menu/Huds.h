#pragma once

namespace Menu
{
	void Scrollbar()
	{
		int RAINBOW[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };
		DrawRectangle(MenuX + 508, MenuY + 58 + (10 * CurrentOpt), 132, 10, RAINBOW);
	}

	void AddHuds()
	{
		int BLACK[3] = { 32, 32, 32 };
		int RAINBOW[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };
		DrawRectangleBorder(MenuX + 508, MenuY + 23, 132, 299, BLACK, RAINBOW, 2);
	}

	void AddTitle(const wchar_t* title)
	{
		AddHuds();
		Scrollbar();
		DrawTextWithShadow(title, MenuX + 548, MenuY + 35, color(MC_Color::White));
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L">     ", MenuX + 630, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		int* insideColor = toggle ? MC_Color::Red : MC_Color::Green;
		int outsideColor[3] = { 32, 32, 32 };
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawRectangleBorder(MenuX + 630, MenuY + 61 + (10 * MaxOption), 5, 5, insideColor, outsideColor, 1);
		MaxOption += 1;
	}
}