#pragma once

namespace Menu
{
	void AddTitle(const wchar_t* title)
	{
		DrawText(title, 460, 13, color(MC_Color::DarkGray));
	}

	void AddHuds()
	{
		DrawRectangle(0, 0, 0, 0, MC_Color::BlackTheme);
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, 438, 45 + (SpaceBetweenText * MaxOption), (MaxOption == CurrentOpt) ? color(MC_Color::Green) : color(MC_Color::White));
		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		DrawText(option, 438, 45 + (SpaceBetweenText * MaxOption), (MaxOption == CurrentOpt) ? color(MC_Color::Green) : color(MC_Color::White));
		MaxOption += 1;
	}
}