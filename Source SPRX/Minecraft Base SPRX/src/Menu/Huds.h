#pragma once

namespace Menu
{
	void AddHuds()
	{
		for (byte a = 0; a < MaxSubOptions + 1; a++)
		{
			DrawRectangleAlpha(MenuX + 49, MenuY + 82, 190, 86 + (10 * a), Color(32, 32, 32, MenuColorAlpha));
		}
	}

	void Scrollbar()
	{
		DrawRectangleAlpha(MenuX + 49, MenuY + 85 + (10 * CurrentOpt), 190, 96 + (10 * CurrentOpt), Color(0, 147, 255, MenuColorAlpha));
	}

	void AddTitle(const wchar_t* title)
	{
		AddHuds();
		Scrollbar();

		DrawRectangleAlpha(MenuX + 49, MenuY + 59, 190, 72, Color(0, 147, 255, MenuColorAlphaTitle));
		DrawTextWithShadow(title, MenuX + 84, MenuY + 62, color(MC_Color::White));
	}

	void AddDescription(const wchar_t* desc)
	{
		DrawRectangleAlpha(MenuX + 49, MenuY + 72, 190, 85, Color(22, 22, 22, MenuColorAlphaDescription));
		DrawTextWithShadow(desc, MenuX + 53, MenuY + 75, color(MC_Color::White));
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 55, MenuY + 87 + (10 * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}
}