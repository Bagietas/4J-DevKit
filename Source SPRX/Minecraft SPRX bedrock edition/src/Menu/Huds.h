#pragma once

namespace Menu
{
	void AddHuds()
	{
		int title_color_1[3] = { 198, 198, 198 };
		int title_color_2[3] = { 88, 86, 89 };
		int title_color_3[3] = { 6, 6, 6 };
		int bg_color[3] = {49, 50, 51};

		DrawRectangle(450, 0, 1000, 1000, bg_color);
		DrawRectangle(450, 0, 1, 1000, title_color_3);
		DrawRectangle(450, 0, 1000, 30, title_color_1);
		DrawRectangle(450, 30, 1000, 5, title_color_2);
		DrawRectangle(450, 35, 1000, 1, title_color_3);
	}

	void Scrollbar()
	{
		DrawRectangle(MenuX + 508, MenuY + 61 + (SpaceBetweenText * CurrentOpt), 152, 11, MC_Color::Blue);
	}

	void AddTitle(const wchar_t* title)
	{
		Scrollbar();
		DrawRectangle(MenuX + 508, MenuY + 35, 152, 13, MC_Color::Blue);
		DrawTextWithShadow(title, MenuX + 550, MenuY + 38, color(MC_Color::White));
	}

	void Description(const wchar_t* description)
	{
		DrawRectangle(MenuX + 508, MenuY + 48, 152, 13, MC_Color::DescColor);
		DrawText(description, MenuX + 510, MenuY + 51 , color(MC_Color::White));
		int index[] = {CurrentOpt + 1, MaxSubOptions};

		if (MaxSubOptions > 9)
			DrawsnprintfText("%i/%i     ", index, MenuX + 636, MenuY + 51, false, false);
		else
			DrawsnprintfText("%i/%i     ", index, MenuX + 641, MenuY + 51, false, false);
		
		if (CurrentOpt > 9)
			DrawsnprintfText("%i/%i     ", index, MenuX + 628, MenuY + 51, false, false);
	}

	void AddSubOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		DrawText(L">     ", MenuX + 650, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddIntOption(const wchar_t* option, int currentopt, int min, int max, int& IntOption)
	{
		int value = { IntOption };
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::White));

		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(2, 1, false))
				{
					if (IntOption < min + 1)
						IntOption = max;
					else
						IntOption = IntOption - 1;
				}
			}
			if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(2, 1, false))
				{
					if (IntOption > max - 1)
						IntOption = min;
					else
						IntOption = IntOption + 1;
				}
			}
		}

		if (value < -99)
			DrawSnprintf("< %i >    ", value, MenuX + 625, MenuY + 63 + (SpaceBetweenText * MaxOption));
		else
			DrawSnprintf("< %i >    ", value, MenuX + 630, MenuY + 63 + (SpaceBetweenText * MaxOption));

		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::White));

		if (toggle)
		{
			DrawRectangleBorder(MenuX + 622, MenuY + 63 + (SpaceBetweenText * MaxOption), 34, 7, MC_Color::BoolColors, MC_Color::BlackTheme, 1);
			DrawRectangle(MenuX + 622 + 17, MenuY + 63 + (SpaceBetweenText * MaxOption), 17, 7, MC_Color::BlackTheme);
			DrawTextC("OFF     ", MenuX + 622 + 18, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::BoolColors));
		}
		else
		{
			DrawRectangleBorder(MenuX + 622, MenuY + 63 + (SpaceBetweenText * MaxOption), 34, 7, MC_Color::BoolColors, MC_Color::BlackTheme, 1);
			DrawRectangle(MenuX + 622, MenuY + 63 + (SpaceBetweenText * MaxOption), 17, 7, MC_Color::BlackTheme);
			DrawTextC("ON     ", MenuX + 622 + 1, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::Blue));
		}
		MaxOption += 1;
	}
}