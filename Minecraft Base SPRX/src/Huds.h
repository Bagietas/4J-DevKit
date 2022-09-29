#pragma once

namespace Menu
{
	void Scrollbar()
	{
		DrawRectangleAlpha(49, 85 + (10 * CurrentOpt), 190, 97 + (10 * CurrentOpt), Color(0, 147, 255, MenuColorAlpha));
	}

	void AddHud(int sub)
	{
		if (sub == 1) { DrawRectangleAlpha(49, 85, 190, 97, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 2) { DrawRectangleAlpha(49, 85, 190, 107, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 3) { DrawRectangleAlpha(49, 85, 190, 117, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 4) { DrawRectangleAlpha(49, 85, 190, 127, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 5) { DrawRectangleAlpha(49, 85, 190, 137, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 6) { DrawRectangleAlpha(49, 85, 190, 147, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 7) { DrawRectangleAlpha(49, 85, 190, 157, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 8) { DrawRectangleAlpha(49, 85, 190, 167, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 9) { DrawRectangleAlpha(49, 85, 190, 177, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 10) { DrawRectangleAlpha(49, 85, 190, 187, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 11) { DrawRectangleAlpha(49, 85, 190, 197, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 12) { DrawRectangleAlpha(49, 85, 190, 207, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 13) { DrawRectangleAlpha(49, 85, 190, 217, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 14) { DrawRectangleAlpha(49, 85, 190, 227, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 15) { DrawRectangleAlpha(49, 85, 190, 237, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 16) { DrawRectangleAlpha(49, 85, 190, 247, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 17) { DrawRectangleAlpha(49, 85, 190, 257, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 18) { DrawRectangleAlpha(49, 85, 190, 267, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 29) { DrawRectangleAlpha(49, 85, 190, 277, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 20) { DrawRectangleAlpha(49, 85, 190, 287, Color(50, 50, 50, MenuColorAlpha)); }
	}

	void AddTitle(const wchar_t* title)
	{
		Scrollbar();
		DrawRectangleAlpha(49, 59, 190, 72, Color(0, 147, 255, MenuColorAlphaTitle));
		DrawTextWithShadow(title, 84, 62, color(MC_Colors::White));
	}

	void AddDescription(const wchar_t* desc)
	{
		DrawRectangleAlpha(49, 72, 190, 85, Color(32, 32, 32, MenuColorAlphaDescription));
		DrawTextWithShadow(desc, 53, 75, color(MC_Colors::White));
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, 55, 87 + (10 * MaxOption), color(MC_Colors::White));
		MaxOption += 1;
	}
}