#pragma once

class draw_menu 
{
public:

	void AddHuds(int sub)
	{
		for (byte a = 0; a < sub + 1; a++)
		{
			DrawRectangle(MenuX + 508, MenuY + 61, 152, +(SpaceBetweenText * sub), MC_Color::BLACK_THEME);
		}
	}

	void Scrollbar()
	{
		DrawRectangle(MenuX + 508, MenuY + 61 + (SpaceBetweenText * CurrentOpt), 152, 11, GetThemeColor());
	}

	void AddTitle(const wchar_t* title)
	{
		Scrollbar();
		DrawRectangle(MenuX + 508, MenuY + 35, 152, 13, GetThemeColor());
		DrawTextShadow(title, MenuX + 550, MenuY + 38, color(MC_TextColor::White));
	}

	void Description(const wchar_t* description)
	{
		DrawRectangle(MenuX + 508, MenuY + 48, 152, 13, MC_Color::DESC_COLOR);
		DrawText(description, MenuX + 510, MenuY + 51, color(MC_TextColor::White));
		int index[] = { CurrentOpt + 1, MaxSubOptions };

		/*
		if (MaxSubOptions > 9)
			DrawsnprintfText("%i/%i     ", index, MenuX + 636, MenuY + 51, false);
		else
			DrawsnprintfText("%i/%i     ", index, MenuX + 641, MenuY + 51, false);

		if (CurrentOpt > 9)
			DrawsnprintfText("%i/%i     ", index, MenuX + 628, MenuY + 51, false);
		*/
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
			DrawRectangleBorder(MenuX + 622, MenuY + 63 + (SpaceBetweenText * MaxOption), 34, 7, MC_Color::BLACK1, MC_Color::BLACK_THEME, 1);
			DrawRectangle(MenuX + 622, MenuY + 63 + (SpaceBetweenText * MaxOption), 17, 7, MC_Color::BLACK_THEME);
			DrawTextC("ON     ", MenuX + 622 + 1, MenuY + 63 + (SpaceBetweenText * MaxOption), color(GetThemeColor()));
		}
		else
		{
			DrawRectangleBorder(MenuX + 622, MenuY + 63 + (SpaceBetweenText * MaxOption), 34, 7, MC_Color::BLACK_THEME, MC_Color::BLACK_THEME, 1);
			DrawRectangle(MenuX + 622 + 17, MenuY + 63 + (SpaceBetweenText * MaxOption), 17, 7, MC_Color::BLACK_THEME);
			DrawTextC("OFF     ", MenuX + 622 + 18, MenuY + 63 + (SpaceBetweenText * MaxOption), color(MC_TextColor::Gray));
		}
		MaxOption += 1;
	}
};

draw_menu* Menu;