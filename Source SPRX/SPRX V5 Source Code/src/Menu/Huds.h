#pragma once

class draw_menu 
{
public:
	void AddTitle(const wchar_t* title)
	{
		if (CustomBanner)
		{
			if (Opened)
			{
				*(int*)0x31E7781C = 0x3F384000; *(int*)0x31E77828 = 0x3F300000;
				*(int*)0x31E7782C = 0x443A1000; *(int*)0x31E77830 = 0xC3DB0000;
			}
			else
			{
				*(int*)0x31E7782C = 0x48410000; *(int*)0x31E77830 = 0xC8EE0000;
			}
		}
		else
		{
			*(int*)0x31E7782C = 0x48410000; *(int*)0x31E77830 = 0xC8EE0000;

			if (!DescInfo)
			{
				DrawRectangle(MenuX + 508, MenuY + 48, 152 + menuLenght, 13, GetThemeColor());
				DrawTextShadow(title, MenuX + 550, MenuY + 51, color(MC_TextColor::White));
			}
			else
			{
				DrawRectangle(MenuX + 508, MenuY + 35, 152 + menuLenght, 13, GetThemeColor());
				DrawTextShadow(title, MenuX + 550, MenuY + 38, color(MC_TextColor::White));
			}
		}
		DrawRectangle(MenuX + 508, MenuY + 61 + (SpaceBetweenText * CurrentOpt), 152 + menuLenght, 11, GetThemeColor());
	}

	void AddHuds(int sub)
	{
		for (byte a = 0; a < sub + 1; a++)
		{
			if (BorderMenu)
			{
				DrawRectangleBorder(MenuX + 508, MenuY + 61, 152 + menuLenght, + (SpaceBetweenText * sub), MC_Color::BLACK_THEME, GetThemeColor(), 1);
			}
			else
			{
				DrawRectangle(MenuX + 508, MenuY + 61, 152 + menuLenght, +(SpaceBetweenText * sub), MC_Color::BLACK_THEME);
			}
		}
	}

	void Description(const wchar_t* description)
	{
		if (DescInfo)
		{
			DrawRectangle(MenuX + 508, MenuY + 48, 152 + menuLenght, 13, MC_Color::DESC_COLOR);

			DrawText(description, MenuX + 510, MenuY + 51, color(MC_TextColor::White));
			int index[] = { CurrentOpt + 1, MaxSubOptions };

			if (MaxSubOptions > 9)
				DrawTextSnprintfV2("%i/%i     ", index, MenuX + 636 + menuLenght, MenuY + 51);
			else
				DrawTextSnprintfV2("%i/%i     ", index, MenuX + 641 + menuLenght, MenuY + 51);

			if (CurrentOpt > 9)
				DrawTextSnprintfV2("%i/%i     ", index, MenuX + 628 + menuLenght, MenuY + 51);
		}
	}

	void AddSubOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));
		DrawText(L">     ", MenuX + 650 + menuLenght, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));
		MaxOption += 1;
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));
		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle, const wchar_t* description = L"")
	{
		DrawText(option, MenuX + 513, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::White));

		if (toggle)
		{
			DrawTextC("ON     ", MenuX + 622 + 18 + menuLenght, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::GREEN));
		}
		else
		{
			DrawTextC("OFF     ", MenuX + 622 + 18 + menuLenght, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_Color::RED));
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

		DrawTextSnprintf("< %i >    ", (int)IntOption, MenuX + 630 + menuLenght, MenuY + 63 + (SpaceBetweenText * MaxOption));
		MaxOption += 1;
	}
};

draw_menu* Menu;