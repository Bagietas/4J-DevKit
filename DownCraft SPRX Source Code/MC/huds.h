#define Color_s(a,r,g,b) (((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))

void DrawToggleONOFF(float x, float y, int *Color1, int *Color2, bool checked)
{
	if (UI::Settings::Rainbow)
	{
		int color1[3] = { 65, 65, 65 };
		if (checked)
		{
			drawRectBorder(x, y, 34, 7, Color1, Color2);
			DrawRectangle(x + 17, y, 17, 7, Color2);
			DrawTextC("OFF     ", x + 18, y, color(color1));
		}
		else
		{
			drawRectBorder(x, y, 34, 7, Color1, Color2);
			DrawRectangle(x, y, 17, 7, Color2);
			DrawTextC("ON     ", x + 2, y, color(UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE));
		}
	}
	else
	{
		int color1[3] = { 65, 65, 65 };
		if (checked)
		{
			drawRectBorder(x, y, 34, 7, Color1, Color2);
			DrawRectangle(x + 17, y, 17, 7, Color2);
			DrawTextC("OFF     ", x + 18, y, color(color1));
		}
		else
		{
			drawRectBorder(x, y, 34, 7, Color1, Color2);
			DrawRectangle(x, y, 17, 7, Color2);
			DrawTextC("ON     ", x + 2, y, color(UI::Color::BLUE));
		}
	}
}

void DrawToggleONOFFV2(float x, float y, int *Color1, int *Color2, bool checked)
{
	int ON[3] = { 37, 151, 68 };
	int OFF[3] = { 189, 26, 43 };
	if (checked)
	{
		DrawTextC("OFF     ", x + 2, y, color(OFF));
	}
	else
	{
		DrawTextC("ON     ", x + 2, y, color(ON));
	}
}




void SetNotify(wchar_t* notifmsg)
{
	if (UI::Settings::ShowNotif)
	{
		NotifMsg = notifmsg;
		SendNotif = false;
		SendNotif = true;
	}
}

void GetNotify()
{
	if (UI::Settings::ShowNotif)
	{
		if (SendNotif)
		{
			if (UI::Settings::Rainbow)
			{
				if (UI::Settings::GradientRGB)
				{
					drawRectBorderRGBV3(284, 21, 143, 15, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1);
					DrawText(NotifMsg, 289, 25, color(UI::Color::WHITE));
				}
				else
				{
					drawRectBorderRGB(284, 21, 143, 15, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE);
					DrawText(NotifMsg, 289, 25, color(UI::Color::WHITE));
				}
			}
			else
			{
				drawRectBorder(284, 21, 143, 15, UI::Color::BLACK, GetThemeColor());
				DrawText(NotifMsg, 289, 25, color(UI::Color::WHITE));
			}

			if (frameTime(200, 1, false))
			{
				SendNotif = false;
			}
		}
	}
}

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

	void SendMessageDebug(wchar_t* logsmsg = L"", int* color = UI::MCTextColors::White, int duration = 10000)//10sec
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
	}

	void draw_logs()
	{
		if (logs[0].message != NULL)
		{
			//Color BLACK_OPACITY = { 25, 25, 25, 200 };
			//(15, 246 - (logs_count * 10), 160, 12 + (10 * logs_count), BLACK_OPACITY);

			if (logs_count > -1)
			{
				DrawRectangle(0, 246 - (logs_count * 10), 190, 12 + (10 * logs_count), UI::Color::BLACK);
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

//MENU HUDS

void TitleMenu()
{
	DrawRectangle(15, 10, 80, 13, UI::Color::BLACK);
	DrawTextWithShadow(L"DownCraft SPRX", 20, 13, color(UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE));
}

void AddInstruction()
{
	if (UI::Settings::ShowInfosBar)
	{
		if (UI::Settings::Style)
		{
			if (UI::Settings::Rainbow)
			{
				if (UI::Settings::GradientRGB)
				{
					drawRectBorderRGBV3(33, 328, 160, 14, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1);
				}
				else
				{
					drawRectBorderRGB(33, 328, 160, 14, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE);
				}
				DrawText(L"Back: O   Scroll: UP / DOWN   Select: X", 37, 331, color(UI::Color::WHITE));
			}
			else
			{
				drawRectBorder(33, 328, 160, 14, UI::Color::BLACK, GetThemeColor());
				DrawText(L"Back: O   Scroll: UP / DOWN   Select: X", 37, 331, color(UI::Color::WHITE));
			}
		}
		else
		{
			DrawRectangle(33, 328, 160, 14, UI::Color::BLACK);
			DrawText(L"Back: O   Scroll: UP / DOWN   Select: X", 37, 331, color(UI::Color::WHITE));
		}

		if (!UI::Settings::CustomImage)
			*(int*)0x31E77830 = 0x44000000;
	}
}

void AddOpacityBG()
{
	if (UI::Settings::BGOpacity)
	{
		Color BLACK_OPACITY{ 15, 15, 15, shadowBG };
		if (submmenuMax == 1) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 48, BLACK_OPACITY); }
		else if (submmenuMax == 2) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 58, BLACK_OPACITY); }
		else if (submmenuMax == 3) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 68, BLACK_OPACITY); }
		else if (submmenuMax == 4) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 78, BLACK_OPACITY); }
		else if (submmenuMax == 5) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 88, BLACK_OPACITY); }
		else if (submmenuMax == 6) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 98, BLACK_OPACITY); }
		else if (submmenuMax == 7) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 108, BLACK_OPACITY); }
		else if (submmenuMax == 8) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 118, BLACK_OPACITY); }
		else if (submmenuMax == 9) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 121, BLACK_OPACITY); }
		else if (submmenuMax == 10) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 138, BLACK_OPACITY); }
		else if (submmenuMax == 11) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 148, BLACK_OPACITY); }
		else if (submmenuMax == 12) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 158, BLACK_OPACITY); }
		else if (submmenuMax == 13) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 168, BLACK_OPACITY); }
		else if (submmenuMax == 14) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 178, BLACK_OPACITY); }
		else if (submmenuMax == 15) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 188, BLACK_OPACITY); }
		else if (submmenuMax == 16) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 198, BLACK_OPACITY); }
		else if (submmenuMax == 17) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 208, BLACK_OPACITY); }
		else if (submmenuMax == 18) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 218, BLACK_OPACITY); }
		else if (submmenuMax == 19) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 228, BLACK_OPACITY); }
		else if (submmenuMax == 20) { DrawRectangleAlpha(bgX, bgY, bgW + 35 + menulenght, bgH + 238, BLACK_OPACITY); }
	}
}

void Scrollbar()
{
	if (UI::Settings::Scrollbar)
	{ 
		DrawRectangle(ScrollX, ScrollY + 10 + (CurrentOpt * 10), bgW + menulenght, 11, GetThemeColor());

		if (UI::Settings::Rainbow)
		{
			drawRectRGB(ScrollX, ScrollY + 10 + (CurrentOpt * 10), bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE);
			if (UI::Settings::GradientRGB)
			{
				drawGradientLeftRightRGB(ScrollX, ScrollY + 10 + (CurrentOpt * 10), bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1);
			}
		}
	}
}

void AddTitle(const wchar_t* title)
{
	if (UI::Settings::Rainbow)
	{
		if (UI::Settings::GradientRGB)
		{
			drawGradientLeftRightRGB(textX - 10, textY - 13, bgW + menulenght, textI + 4, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1);
		}
		else
		{
			drawRectRGB(textX - 10, textY - 13, bgW + menulenght, textI + 4, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE);
		}
	}
	else
	{
		DrawRectangle(textX - 10, textY - 13, bgW + menulenght, textI + 4, GetThemeColor());
	}

	Scrollbar();
	AddOpacityBG();

	DrawTextWithShadow(title, TitleTextX + menulenght, TitleTextY, color(UI::Color::WHITE));
}

void CountIndexPage()
{
	if (CurrentOpt == 0){ CurrentIndex = 1; }
	else if (CurrentOpt == 1) { CurrentIndex = 2; }
	else if (CurrentOpt == 2) { CurrentIndex = 3; }
	else if (CurrentOpt == 3) { CurrentIndex = 4; }
	else if (CurrentOpt == 4) { CurrentIndex = 5; }
	else if (CurrentOpt == 5) { CurrentIndex = 6; }
	else if (CurrentOpt == 6) { CurrentIndex = 7; }
	else if (CurrentOpt == 7) { CurrentIndex = 8; }
	else if (CurrentOpt == 8) { CurrentIndex = 9; }
	else if (CurrentOpt == 9) { CurrentIndex = 10; }
	else if (CurrentOpt == 10) { CurrentIndex = 11; }
	else if (CurrentOpt == 11) { CurrentIndex = 12; }
	else if (CurrentOpt == 12) { CurrentIndex = 13; }
	else if (CurrentOpt == 13) { CurrentIndex = 14; }
	else if (CurrentOpt == 14) { CurrentIndex = 15; }
	else if (CurrentOpt == 15) { CurrentIndex = 16; }
	else if (CurrentOpt == 16) { CurrentIndex = 17; }
	else if (CurrentOpt == 17) { CurrentIndex = 18; }
	else if (CurrentOpt == 18) { CurrentIndex = 19; }
	else if (CurrentOpt == 19) { CurrentIndex = 20; }
	else if (CurrentOpt == 20) { CurrentIndex = 21; }
}

void AddDescription(const wchar_t* desc)
{
	if (!UI::Settings::BO2Design)
	{
		CountIndexPage();
		DrawRectangle(ScrollX, ScrollY, bgW + menulenght, 11, UI::Color::BLACK2);
		DrawTextWithShadow(desc, AddOptX - 3, AddOptY - 10, color(UI::Color::WHITE));

		char option4[0x100];
		wchar_t woption4[0x100];
		_sys_memset(option4, 0, 0x100);
		_sys_memset(woption4, 0, 0x200);
		_sys_snprintf(option4, 0x100, "%i/%i     ", (CurrentIndex), (submmenuMax));
		StringToWideCharacter(woption4, option4, _sys_strlen(option4));

		if (CurrentIndex > 9)
		{
			DrawText(woption4, TitleTextX + 76 + menulenght, TitleTextY + 12, color(UI::Color::WHITE)); //574
		}
		else
		{
			DrawText(woption4, TitleTextX + 81 + menulenght, TitleTextY + 12, color(UI::Color::WHITE)); //579 title = 448
		}
	}
}

void AddInformation(int sub, const wchar_t* desc)
{
	if (!UI::Settings::BO2Design)
	{
		if (UI::Settings::Rainbow)
		{
			if (UI::Settings::GradientRGB)
			{
				if (sub == 1) { drawGradientLeftRightRGB(bgX, bgY + 10, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 2) { drawGradientLeftRightRGB(bgX, bgY + 20, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 3) { drawGradientLeftRightRGB(bgX, bgY + 30, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 4) { drawGradientLeftRightRGB(bgX, bgY + 40, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 5) { drawGradientLeftRightRGB(bgX, bgY + 50, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 6) { drawGradientLeftRightRGB(bgX, bgY + 60, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 7) { drawGradientLeftRightRGB(bgX, bgY + 70, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 8) { drawGradientLeftRightRGB(bgX, bgY + 80, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 9) { drawGradientLeftRightRGB(bgX, bgY + 90, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 10) { drawGradientLeftRightRGB(bgX, bgY + 100, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 11) { drawGradientLeftRightRGB(bgX, bgY + 110, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 12) { drawGradientLeftRightRGB(bgX, bgY + 120, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 13) { drawGradientLeftRightRGB(bgX, bgY + 130, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 14) { drawGradientLeftRightRGB(bgX, bgY + 140, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 15) { drawGradientLeftRightRGB(bgX, bgY + 150, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 16) { drawGradientLeftRightRGB(bgX, bgY + 160, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 17) { drawGradientLeftRightRGB(bgX, bgY + 170, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 18) { drawGradientLeftRightRGB(bgX, bgY + 180, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 19) { drawGradientLeftRightRGB(bgX, bgY + 190, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				else if (sub == 20) { drawGradientLeftRightRGB(bgX, bgY + 200, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
			}
			else
			{
				if (sub == 1) { drawRectRGB(bgX, bgY + 10, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 2) { drawRectRGB(bgX, bgY + 20, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 3) { drawRectRGB(bgX, bgY + 30, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 4) { drawRectRGB(bgX, bgY + 40, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 5) { drawRectRGB(bgX, bgY + 50, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 6) { drawRectRGB(bgX, bgY + 60, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 7) { drawRectRGB(bgX, bgY + 70, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 8) { drawRectRGB(bgX, bgY + 80, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 9) { drawRectRGB(bgX, bgY + 90, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 10) { drawRectRGB(bgX, bgY + 100, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 11) { drawRectRGB(bgX, bgY + 110, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 12) { drawRectRGB(bgX, bgY + 120, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 13) { drawRectRGB(bgX, bgY + 130, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 14) { drawRectRGB(bgX, bgY + 140, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 15) { drawRectRGB(bgX, bgY + 150, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 16) { drawRectRGB(bgX, bgY + 160, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 17) { drawRectRGB(bgX, bgY + 170, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 18) { drawRectRGB(bgX, bgY + 180, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 19) { drawRectRGB(bgX, bgY + 190, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				else if (sub == 20) { drawRectRGB(bgX, bgY + 200, bgW + menulenght, 11, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
			}
		}
		else
		{
			if (sub == 1) { DrawRectangle(bgX, bgY + 10, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 2) { DrawRectangle(bgX, bgY + 20, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 3) { DrawRectangle(bgX, bgY + 30, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 4) { DrawRectangle(bgX, bgY + 40, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 5) { DrawRectangle(bgX, bgY + 50, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 6) { DrawRectangle(bgX, bgY + 60, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 7) { DrawRectangle(bgX, bgY + 70, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 8) { DrawRectangle(bgX, bgY + 80, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 9) { DrawRectangle(bgX, bgY + 90, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 10) { DrawRectangle(bgX, bgY + 100, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 11) { DrawRectangle(bgX, bgY + 110, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 12) { DrawRectangle(bgX, bgY + 120, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 13) { DrawRectangle(bgX, bgY + 130, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 14) { DrawRectangle(bgX, bgY + 140, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 15) { DrawRectangle(bgX, bgY + 150, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 16) { DrawRectangle(bgX, bgY + 160, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 17) { DrawRectangle(bgX, bgY + 170, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 18) { DrawRectangle(bgX, bgY + 180, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 19) { DrawRectangle(bgX, bgY + 190, bgW + menulenght, 11, GetThemeColor()); }
			else if (sub == 20) { DrawRectangle(bgX, bgY + 200, bgW + menulenght, 11, GetThemeColor()); }
		}

		//TEXT

		if (sub == 1) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 10, color(UI::Color::WHITE)); }
		else if (sub == 2) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 20, color(UI::Color::WHITE)); }
		else if (sub == 3) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 30, color(UI::Color::WHITE)); }
		else if (sub == 4) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 40, color(UI::Color::WHITE)); }
		else if (sub == 5) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 50, color(UI::Color::WHITE)); }
		else if (sub == 6) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 60, color(UI::Color::WHITE)); }
		else if (sub == 7) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 70, color(UI::Color::WHITE)); }
		else if (sub == 8) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 80, color(UI::Color::WHITE)); }
		else if (sub == 9) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 90, color(UI::Color::WHITE)); }
		else if (sub == 10) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 100, color(UI::Color::WHITE)); }
		else if (sub == 11) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 110, color(UI::Color::WHITE)); }
		else if (sub == 12) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 120, color(UI::Color::WHITE)); }
		else if (sub == 13) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 130, color(UI::Color::WHITE)); }
		else if (sub == 14) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 140, color(UI::Color::WHITE)); }
		else if (sub == 15) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 150, color(UI::Color::WHITE)); }
		else if (sub == 16) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 160, color(UI::Color::WHITE)); }
		else if (sub == 17) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 170, color(UI::Color::WHITE)); }
		else if (sub == 18) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 180, color(UI::Color::WHITE)); }
		else if (sub == 19) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 190, color(UI::Color::WHITE)); }
		else if (sub == 20) { DrawTextWithShadow(desc, AddOptX - 3, AddOptY + 200, color(UI::Color::WHITE)); }
	}
}

void AddHud(int sub)
{
	if (!UI::Settings::BO2Design)
	{
		if (UI::Settings::Style)
		{
			if (UI::Settings::Rainbow)
			{
				if (UI::Settings::GradientRGB)
				{
					if (sub == 1) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, bgH - 2, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 2) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 21, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 3) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 31, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 4) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 41, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 5) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 51, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 6) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 61, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 7) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 71, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 8) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 81, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 9) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 91, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 10) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 101, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 11) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 111, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 12) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 121, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 13) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 131, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 14) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 141, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 15) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 151, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 16) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 161, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 17) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 171, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 18) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 181, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 19) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 191, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
					else if (sub == 20) { drawRectBorderRGBV3(bgX + 1, bgY, bgW - 2 + menulenght, 201, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::RainbowRED1, UI::Color::RainbowGREEN1, UI::Color::RainbowBLUE1); }
				}
				else
				{
					if (sub == 1) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, bgH - 2, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 2) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 21, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 3) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 31, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 4) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 41, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 5) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 51, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 6) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 61, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 7) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 71, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 8) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 81, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 9) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 91, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 10) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 101, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 11) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 111, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 12) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 121, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 13) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 131, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 14) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 141, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 15) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 151, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 16) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 161, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 17) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 171, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 18) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 181, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 19) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 191, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
					else if (sub == 20) { drawRectBorderRGB(bgX + 1, bgY, bgW - 2 + menulenght, 201, UI::Color::BLACK, UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE); }
				}
			}
			else
			{
				if (sub == 1) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, bgH - 2, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 2) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 21, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 3) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 31, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 4) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 41, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 5) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 51, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 6) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 61, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 7) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 71, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 8) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 81, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 9) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 91, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 10) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 101, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 11) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 111, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 12) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 121, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 13) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 131, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 14) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 141, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 15) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 151, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 16) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 161, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 17) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 171, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 18) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 181, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 19) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 191, UI::Color::BLACK, GetThemeColor()); }
				else if (sub == 20) { drawRectBorder(bgX + 1, bgY, bgW - 2 + menulenght, 201, UI::Color::BLACK, GetThemeColor()); }
			}
		}
		else
		{
			if (UI::Settings::BGOpacity)
			{

			}
			else
			{
				if (sub == 1) { DrawRectangle(bgX, bgY, bgW + menulenght, bgH, UI::Color::BLACK); }
				else if (sub == 2) { DrawRectangle(bgX, bgY, bgW + menulenght, 21, UI::Color::BLACK); }
				else if (sub == 3) { DrawRectangle(bgX, bgY, bgW + menulenght, 31, UI::Color::BLACK); }
				else if (sub == 4) { DrawRectangle(bgX, bgY, bgW + menulenght, 41, UI::Color::BLACK); }
				else if (sub == 5) { DrawRectangle(bgX, bgY, bgW + menulenght, 51, UI::Color::BLACK); }
				else if (sub == 6) { DrawRectangle(bgX, bgY, bgW + menulenght, 61, UI::Color::BLACK); }
				else if (sub == 7) { DrawRectangle(bgX, bgY, bgW + menulenght, 71, UI::Color::BLACK); }
				else if (sub == 8) { DrawRectangle(bgX, bgY, bgW + menulenght, 81, UI::Color::BLACK); }
				else if (sub == 9) { DrawRectangle(bgX, bgY, bgW + menulenght, 91, UI::Color::BLACK); }
				else if (sub == 10) { DrawRectangle(bgX, bgY, bgW + menulenght, 101, UI::Color::BLACK); }
				else if (sub == 11) { DrawRectangle(bgX, bgY, bgW + menulenght, 111, UI::Color::BLACK); }
				else if (sub == 12) { DrawRectangle(bgX, bgY, bgW + menulenght, 121, UI::Color::BLACK); }
				else if (sub == 13) { DrawRectangle(bgX, bgY, bgW + menulenght, 131, UI::Color::BLACK); }
				else if (sub == 14) { DrawRectangle(bgX, bgY, bgW + menulenght, 141, UI::Color::BLACK); }
				else if (sub == 15) { DrawRectangle(bgX, bgY, bgW + menulenght, 151, UI::Color::BLACK); }
				else if (sub == 16) { DrawRectangle(bgX, bgY, bgW + menulenght, 161, UI::Color::BLACK); }
				else if (sub == 17) { DrawRectangle(bgX, bgY, bgW + menulenght, 171, UI::Color::BLACK); }
				else if (sub == 18) { DrawRectangle(bgX, bgY, bgW + menulenght, 181, UI::Color::BLACK); }
				else if (sub == 19) { DrawRectangle(bgX, bgY, bgW + menulenght, 191, UI::Color::BLACK); }
				else if (sub == 20) { DrawRectangle(bgX, bgY, bgW + menulenght, 201, UI::Color::BLACK); }
			}
		}
	}
	else
	{
		drawRectBorder(bgX + 1, bgY - 200, bgW - 2 + menulenght, bgH + 800, UI::Color::BLACK, GetThemeColor());
	}
}

void AddOption(const wchar_t* opt)
{
	//bgH * subMax;
	//DrawRectangle(textX - 5, textY - 5 + (scroll * 13), bgW, textI + 2, UI::Color::RED);
	if (UI::Settings::Rainbow)
	{
		if (menulenght > 25)
		{
			if (UI::Settings::Scrollbar)
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
				DrawText(L">    ", AddOptX + 80 + menulenght, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
			}
			else
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE) : color(UI::Color::WHITE));
				DrawText(L">    ", AddOptX + 80 + menulenght, AddOptY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE) : color(UI::Color::WHITE));
			}
		}
		else
		{
			if (UI::Settings::Scrollbar)
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
			}
			else
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE) : color(UI::Color::WHITE));
			}
		}
	}
	else
	{
		if (menulenght > 25)
		{
			if (UI::Settings::Scrollbar)
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
				DrawText(L">    ", AddOptX + 80 + menulenght, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
			}
			else
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(GetThemeColor()) : color(UI::Color::WHITE));
				DrawText(L">    ", AddOptX + 80 + menulenght, AddOptY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(GetThemeColor()) : color(UI::Color::WHITE));
			}
		}
		else
		{
			if (UI::Settings::Scrollbar)
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
			}
			else
			{
				DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(GetThemeColor()) : color(UI::Color::WHITE));
			}
		}
	}
	MaxOption += 1;
}

void AddBoolOption(const wchar_t* opt, bool boolOption)
{
	int color1[3] = { 65, 65, 65 };
	int color2[3] = { 40, 40, 40 };
	//drawRectBorder(115, 52 + (10 * MaxOption), 4, 4, (boolOption) ? UI::Color::BLACK : THEME, UI::Color::WHITE);
	if (UI::Settings::Rainbow)
	{
		if (UI::Settings::Scrollbar)
		{
			DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
		}
		else
		{
			DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE) : color(UI::Color::WHITE));
		}
		if (UI::Settings::Checkbox)
		{
			if (menulenght > 25)
			{
				DrawToggleONOFF(CheckBoxX - 50 + menulenght, CheckBoxY + (10 * MaxOption), color1, UI::Color::BLACK, boolOption);
			}
			else
			{
				drawRectBorderRGBV2(CheckBoxX + menulenght, CheckBoxY + 2 + (10 * MaxOption), 4, 4, (boolOption) ? 15, 15, 15 : UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE, UI::Color::WHITE);
			}
		}
		else
		{
			if (UI::Settings::Scrollbar)
			{
				if (UI::Settings::CheckboxV2)
				{

				}
				else
				{
					DrawText(boolOption ? L"" : L"+     ", CheckBoxX + menulenght - 21, CheckBoxY + (10 * MaxOption), color(UI::Color::WHITE));
				}
			}
			else
			{
				if (UI::Settings::CheckboxV2)
				{

				}
				else
				{
					DrawText(boolOption ? L"" : L"+     ", CheckBoxX + menulenght - 21, CheckBoxY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE) : color(UI::Color::WHITE));
				}
			}
		}
		if (UI::Settings::CheckboxV2 && !UI::Settings::Checkbox)
		{
			DrawToggleONOFFV2(CheckBoxX - 30 + menulenght, CheckBoxY + (10 * MaxOption), color1, UI::Color::BLACK, boolOption);
		}
	}
	else
	{
		if (UI::Settings::Scrollbar)
		{
			DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
		}
		else
		{
			DrawText(opt, (MaxOption == CurrentOpt) ? AddOptX + 5 : AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
			DrawRectangle(AddOptX, (MaxOption == CurrentOpt) ? AddOptY - 2 + (10 * MaxOption) : AddOptY - 2, 1, 10, (MaxOption == CurrentOpt) ? GetThemeColor() : UI::Color::BLACK);
			DrawRectangle(AddOptX, AddOptY + 8 + (10 * MaxOption), bgW + menulenght - 6, 1, (MaxOption == CurrentOpt) ? GetThemeColor() : UI::Color::BLACK);
		}
		if (UI::Settings::Checkbox)
		{
			if (menulenght > 25)
			{
				int color1[3] = { 65, 65, 65 };
				int color2[3] = { 40, 40, 40 };
				DrawToggleONOFF(CheckBoxX  - 50 + menulenght, CheckBoxY + (10 * MaxOption), color1, UI::Color::BLACK, boolOption);
			}
			else
			{
				drawRectBorder(CheckBoxX + menulenght, CheckBoxY + 2 + (10 * MaxOption), 4, 4, (boolOption) ? UI::Color::BLACK : GetThemeColor(), UI::Color::WHITE);
			}
		}
		else
		{
			if (UI::Settings::Scrollbar)
			{
				if (UI::Settings::CheckboxV2)
				{

				}
				else
				{
					DrawText(boolOption ? L"" : L"+     ", CheckBoxX + menulenght - 21, CheckBoxY + (10 * MaxOption), color(UI::Color::WHITE));
				}
			}
			else
			{
				if (UI::Settings::CheckboxV2)
				{

				}
				else
				{
					DrawText(boolOption ? L"" : L"+     ", CheckBoxX + menulenght - 21, CheckBoxY + (10 * MaxOption), (MaxOption == CurrentOpt) ? color(GetThemeColor()) : color(UI::Color::WHITE));
				}
			}
		}
		if (UI::Settings::CheckboxV2 && !UI::Settings::Checkbox)
		{
			DrawToggleONOFFV2(CheckBoxX - 30 + menulenght, CheckBoxY + (10 * MaxOption), color1, UI::Color::BLACK, boolOption);
		}
	}
	MaxOption += 1;
}

void AddIntOption(const wchar_t* opt, int def, int IntOptions)
{
	if (UI::Settings::Scrollbar)
	{
		DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
	}
	else
	{
		DrawText(opt, (MaxOption == CurrentOpt) ? AddOptX + 5 : AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
	}

	if (IntOptions > 99)
	{
		if (!UI::Settings::Scrollbar)
		{
			DrawRectangle(AddOptX, (MaxOption == CurrentOpt) ? AddOptY - 2 + (10 * MaxOption) : AddOptY - 2, 1, 10, (MaxOption == CurrentOpt) ? GetThemeColor() : UI::Color::BLACK);
			DrawRectangle(AddOptX, AddOptY + 8 + (10 * MaxOption), bgW + menulenght - 6, 1, (MaxOption == CurrentOpt) ? GetThemeColor() : UI::Color::BLACK);
		}

		if (IntOptions == def)
		{
			DrawText(L"< Default >    ", CheckBoxX - 56 + menulenght, CheckBoxY + (10 * MaxOption), color(UI::Color::WHITE));
		}
		else
		{
			snprintf("< %i >    ", (int)IntOptions, CheckBoxX - 40 + menulenght, CheckBoxY + (10 * MaxOption));
		}
	}
	else
	{
		if (!UI::Settings::Scrollbar)
		{
			DrawRectangle(AddOptX, (MaxOption == CurrentOpt) ? AddOptY - 2 + (10 * MaxOption) : AddOptY - 2, 1, 10, (MaxOption == CurrentOpt) ? GetThemeColor() : UI::Color::BLACK);
			DrawRectangle(AddOptX, AddOptY + 8 + (10 * MaxOption), bgW + menulenght - 6, 1, (MaxOption == CurrentOpt) ? GetThemeColor() : UI::Color::BLACK);
		}
		if (IntOptions == def)
		{
			DrawText(L"< Default >    ", CheckBoxX - 56 + menulenght, CheckBoxY + (10 * MaxOption), color(UI::Color::WHITE));
		}
		else
		{
			snprintf("< %i >    ", (int)IntOptions, CheckBoxX - 35 + menulenght, CheckBoxY + (10 * MaxOption));
		}
	}
	MaxOption += 1;
}

void AddFloatOption(const wchar_t* opt, float FloatOptions)
{
	if (UI::Settings::Scrollbar)
	{
		DrawText(opt, AddOptX, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
	}
	else
	{
		DrawText(opt, AddOptX + 5, AddOptY + (10 * MaxOption), color(UI::Color::WHITE));
	}
	char option46[0x100];
	wchar_t woption46[0x100];
	_sys_memset(option46, 0, 0x100);
	_sys_memset(woption46, 0, 0x200);
	_sys_snprintf(option46, 0x100, "< %i >   ", (int)FloatOptions);
	StringToWideCharacter(woption46, option46, _sys_strlen(option46));
	DrawText(woption46, CheckBoxX - 3 + menulenght, CheckBoxY + (10 * MaxOption), color(UI::Color::WHITE));
	MaxOption += 1;
}