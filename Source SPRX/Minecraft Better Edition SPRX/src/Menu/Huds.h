#pragma once

namespace Menu
{
	void TitleSPRX(const wchar_t* title)
	{
		if (ToggleTitleSPRX)
			DrawTextWithRectangle(title, 10, 10, MC_Color::BlackTheme, true);
	}

	void Scrollbar()
	{
		DrawRectangle(MenuX + 508, MenuY + 70 + (SpaceBetweenText * CurrentOpt), 132, 10, MC_Color::ColorTheme);
	}

	void Description(const wchar_t* description)
	{
		DrawText(description, MenuX + 510, MenuY + 54 , color(MC_Color::White));

		char option4[0x100];
		wchar_t woption4[0x100];
		_sys_memset(option4, 0, 0x100);
		_sys_memset(woption4, 0, 0x200);
		_sys_snprintf(option4, 0x100, "%i/%i     ", (CurrentOpt + 1), (MaxSubOptions));
		StringToWideCharacter(woption4, option4, strlen(option4));
		DrawText(woption4, MenuX + 621, MenuY + 54, color(MC_Color::White));
	}

	void AddHuds()
	{
		DrawRectangleBorder(MenuX + 508, MenuY + 23, 132, 299, MC_Color::BlackTheme, MC_Color::ColorTheme, 2);
		DrawRectangle(MenuX + 508, MenuY + 63, 132, 1, MC_Color::ColorTheme);
	}

	void AddTitle(const wchar_t* title)
	{
		AddHuds();
		Scrollbar();

		int width = Font_width(title);
		DrawRectangle(MenuX + 537, MenuY + 33, 1, 12, MC_Color::White);
		DrawRectangle(MenuX + 537, MenuY + 45, 11, 1, MC_Color::White);
		DrawRectangle(MenuX + 535 + width + 7, MenuY + 33, 1, 12, MC_Color::White);
		DrawRectangle(MenuX + 535 + width - 4, MenuY + 32, 12, 1, MC_Color::White);
		DrawTextWithShadow(title, MenuX + 540, MenuY + 35, color(MC_Color::ColorTheme));
	}

	void AddSubOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 71 + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		DrawText(L">     ", MenuX + 630, MenuY + 71 + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 71 + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		int* insideColor = toggle ? MC_Color::Red : MC_Color::Green;
		int outsideColor[3] = { 32, 32, 32 };
		DrawText(option, MenuX + 513, MenuY + 71 + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		DrawRectangleBorder(MenuX + 630, MenuY + 72 + (SpaceBetweenText * MaxOption), 5, 5, insideColor, outsideColor, 1);
		MaxOption += 1;
	}
}