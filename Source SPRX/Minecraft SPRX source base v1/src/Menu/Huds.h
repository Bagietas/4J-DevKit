#pragma once

namespace Menu
{
	void AddArrayText(const wchar_t* text, int color)
	{
		DrawArrayText(text, color);
		MaxArrayList += 1;
	}

	void AddHudsOpacity(int sub)
	{
		int Gradient1[3] = { MenuGradient1R, MenuGradient1G, MenuGradient1B };
		int Gradient2[3] = { MenuGradient2R, MenuGradient2G, MenuGradient2B };

		if (BackgroundStyle == 1)
		{
			Color BLACK_OPACITY = { 15, 15, 15, MenuA };
			if (GradientMenu)
				DrawGradientBorder(60 + MenuX, 40 + MenuY, 110 + menuLenght, 15 + (11 * sub), Gradient1, Gradient2, MC_Color::BlackTheme, MenuBorderSize, true);
			else
				DrawRectangleAlpha(60 + MenuX, 55 + MenuY, 170 + menuLenght, 55 + (11 * sub), BLACK_OPACITY);
			}
	}

	void AddHuds(int sub)
	{
		int Gradient1[3] = { MenuGradient1R, MenuGradient1G, MenuGradient1B };
		int Gradient2[3] = { MenuGradient2R, MenuGradient2G, MenuGradient2B };

		for (byte a = 0; a < sub + 1; a++)
		{
			if (BackgroundStyle == 0)
			{
				if (GradientMenu)
					DrawGradientBorder(60 + MenuX, 40 + MenuY, 110 + menuLenght, 15 + (11 * sub), Gradient1, Gradient2, MC_Color::BlackTheme, MenuBorderSize, true);
				else
					DrawRectangleBorder(60 + MenuX, 40 + MenuY, 110 + menuLenght, 15 + (11 * sub), MC_Color::BlackTheme, GetThemeColor(), MenuBorderSize);
			}
		}
	}

	void AddDescription()
	{
		CountIndexPage();
		char option4[0x100];
		wchar_t woption4[0x100];
		_sys_memset(option4, 0, 0x100);
		_sys_memset(woption4, 0, 0x200);
		_sys_snprintf(option4, 0x100, "%i/%i     ", (CurrentIndex), (MaxSubOptions));
		StringToWideCharacter(woption4, option4, strlen(option4));
		if (CurrentIndex > 9)
		{
			DrawTextWithShadow(woption4, 141 + MenuX + menuLenght, 44 + MenuY, color(MC_Color::White));
		}
		else
		{
			DrawTextWithShadow(woption4, 150 + MenuX + menuLenght, 44 + MenuY, color(MC_Color::White));
		}
	}

	void AddTitle(const wchar_t* title)
	{
		int Gradient1[3] = { MenuGradient1R, MenuGradient1G, MenuGradient1B };
		int Gradient2[3] = { MenuGradient2R, MenuGradient2G, MenuGradient2B };

		//HUD TITLE
		if (GradientMenu)
			DrawGradientRectangle(60 + MenuX, 40 + MenuY, 110 + menuLenght, 15, Gradient1, Gradient2, true);
		else
			DrawRectangle(60 + MenuX, 40 + MenuY, 110 + menuLenght, 15, GetThemeColor());

		//TITLE TEXT
		DrawTextWithShadow(title, 63 + MenuX, 44 + MenuY, color(MC_Color::White));

		AddDescription();
		AddHudsOpacity(MaxSubOptions);

		//SCROLL BAR
		if (GradientMenu)
			DrawGradientRectangle(60 + MenuX, 55 + MenuY + (SpaceBetweenText * CurrentOpt), 110 + menuLenght, 11, Gradient1, Gradient2, true);
		else
			DrawRectangle(60 + MenuX, 55 + MenuY + (SpaceBetweenText * CurrentOpt), 110 + menuLenght, 11, GetThemeColor());
	}

	void AddSubOption(const wchar_t* option)
	{
		DrawText(option, 63 + MenuX, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		DrawText(L">     ", 163 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, 63 + MenuX, 58 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddCategory(const wchar_t* option)
	{
		DrawRectangle(60 + MenuX, 55 + MenuY + (SpaceBetweenText * MaxOption), 110 + menuLenght, 11, GetThemeColor());
		DrawTextWithShadow(option, 63 + MenuX, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		DrawText(option, 63 + MenuX, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));

		if (boolStyle == 0)
		{
			if (toggle)
				DrawTextC("ON     ", 158 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::Green));
			else
				DrawTextC("OFF     ", 154 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::Red));
		}
		else if (boolStyle == 1)
		{
			int* insideColor = toggle ? MC_Color::Green : MC_Color::Red;
			DrawRectangleBorder(158 + MenuX + menuLenght, 58 + MenuY + (SpaceBetweenText * MaxOption), 5, 5, insideColor, MC_Color::Black, 0.5f);
		}
		else if (boolStyle == 2)
		{
			int color1[3] = { 65, 65, 65 }; int color2[3] = { 40, 40, 40 }; int toggledRec = toggle ? 17 : 0; int toggledText = toggle ? 19 : 0;
			char* text; if (toggle) { text = "ON     "; } else { text = "OFF     "; } 
			DrawRectangleBorder(132 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), 34, 7, color1, MC_Color::Black, 0.5f);
			DrawRectangle(132 + MenuX + menuLenght + toggledRec, 57 + MenuY + (SpaceBetweenText * MaxOption), 17, 7, color2);
			DrawTextC(text, 132 + MenuX + menuLenght + toggledText, 57 + MenuY + (SpaceBetweenText * MaxOption), color(color1));;
		}
		else if (boolStyle == 3)
		{
			if (toggle)
				DrawTextC("+     ", 158 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
			else
				DrawTextC("-     ", 158 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		}

		MaxOption += 1;
	}

	void AddBoolOptionV2(const wchar_t* option, void(*function)(), bool toggle)
	{
		toggle =! toggle;
		DrawText(option, 63 + MenuX, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));

		if (boolStyle == 0)
		{
			if (toggle)
				DrawTextC("ON     ", 158 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::Green));
			else
				DrawTextC("OFF     ", 154 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::Red));
		}
		else if (boolStyle == 1)
		{
			int* insideColor = toggle ? MC_Color::Green : MC_Color::Red;
			DrawRectangleBorder(158 + MenuX + menuLenght, 58 + MenuY + (SpaceBetweenText * MaxOption), 5, 5, insideColor, MC_Color::Black, 0.5f);
		}
		else if (boolStyle == 2)
		{
			int color1[3] = { 65, 65, 65 }; int color2[3] = { 40, 40, 40 }; int toggledRec = toggle ? 17 : 0; int toggledText = toggle ? 19 : 0;
			char* text; if (toggle) { text = "ON     "; }
			else { text = "OFF     "; }
			DrawRectangleBorder(132 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), 34, 7, color1, MC_Color::Black, 0.5f);
			DrawRectangle(132 + MenuX + menuLenght + toggledRec, 57 + MenuY + (SpaceBetweenText * MaxOption), 17, 7, color2);
			DrawTextC(text, 132 + MenuX + menuLenght + toggledText, 57 + MenuY + (SpaceBetweenText * MaxOption), color(color1));;
		}
		else if (boolStyle == 3)
		{
			if (toggle)
				DrawTextC("+     ", 158 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
			else
				DrawTextC("-     ", 158 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		}

		MaxOption += 1;
	}

	void AddIntOption(const wchar_t* option, int currentopt, int min, int max, int& IntOption)
	{
		int value = { IntOption };
		DrawText(option, 63 + MenuX, 57 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));

		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(4, 1, false))
				{
					if (IntOption < min + 1)
						IntOption = max;
					else
						IntOption = IntOption - 1;
				}
			}
			if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(4, 1, false))
				{
					if (IntOption > max - 1)
						IntOption = min;
					else
						IntOption = IntOption + 1;
				}
			}
		}

		if (value > 99)
			DrawSnprintf("< %i >    ", value, 140 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption));
		else
			DrawSnprintf("< %i >    ", value, 145 + MenuX + menuLenght, 57 + MenuY + (SpaceBetweenText * MaxOption));
		MaxOption += 1;
	}

	//using MediaPS3.arc for add custom image
	void AddCustomImage(float x, float y, float w, float h)
	{

	}
}