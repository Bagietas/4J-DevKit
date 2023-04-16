#pragma once

class draw_menu 
{
public:

	void AddTitle(const wchar_t* title)
	{
		DrawRectangle(MenuX + 508, MenuY + 35, 152, 13, GetThemeColor());
		DrawRectangle(MenuX + 508, MenuY + 61 + (SpaceBetweenText * CurrentOpt), 152, 11, GetThemeColor());
		DrawTextShadow(title, MenuX + 550, MenuY + 38, color(MC_TextColor::White));
	}

	void AddHuds(int sub)
	{
		for (byte a = 0; a < sub + 1; a++)
		{
			DrawRectangle(MenuX + 508, MenuY + 61, 152, + (SpaceBetweenText * sub), MC_Color::BLACK_THEME);
		}
	}

	void Description(const wchar_t* description)
	{
		DrawRectangle(MenuX + 508, MenuY + 48, 152, 13, MC_Color::DESC_COLOR);
		DrawText(description, MenuX + 510, MenuY + 51, color(MC_TextColor::White));
		int index[] = { CurrentOpt + 1, MaxSubOptions };

		if (MaxSubOptions > 9)
			DrawTextSnprintfV2("%i/%i     ", index, MenuX + 636, MenuY + 51);
		else
			DrawTextSnprintfV2("%i/%i     ", index, MenuX + 641, MenuY + 51);

		if (CurrentOpt > 9)
			DrawTextSnprintfV2("%i/%i     ", index, MenuX + 628, MenuY + 51);
	}

	void AddSubOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));
		DrawText(L">     ", MenuX + 650, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));
		MaxOption += 1;
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));
		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));

		if (toggle)
		{
			DrawTextC("ON     ", MenuX + 622 + 18, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::GREEN));
		}
		else
		{
			DrawTextC("OFF     ", MenuX + 622 + 18, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::RED));
		}
		MaxOption += 1;
	}

	void AddIntOption(const wchar_t* option, int currentopt, int min, int max, int& IntOption)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::WHITE));

		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(3, 1, false))
				{
					if (IntOption < min + 1)
						IntOption = max;
					else
						IntOption = IntOption - 1;
				}
			}
			if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(3, 1, false))
				{
					if (IntOption > max - 1)
						IntOption = min;
					else
						IntOption = IntOption + 1;
				}
			}
		}

		DrawTextSnprintf("< %i >    ", (int)IntOption, MenuX + 630, MenuY + 63 + (SpaceBetweenText * MaxOption));
		MaxOption += 1;
	}
};

draw_menu* Menu;