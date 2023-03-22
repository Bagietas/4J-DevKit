#pragma once

namespace Menu
{
	void AddTitle(const wchar_t* title)
	{
		drawText(title, 460, 13, color(MC_Color::DarkGray));
	}

	void AddHuds()
	{
		drawRectangle(0, 0, 0, 0, MC_Color::BlackTheme);
	}

	void AddOption(const wchar_t* option)
	{
		drawText(option, 438, 45 + (SpaceBetweenText * MaxOption), (MaxOption == CurrentOpt) ? color(MC_Color::Green) : color(MC_Color::White));
		MaxOption += 1;
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		drawText(option, 465, 45 + (SpaceBetweenText * MaxOption), (MaxOption == CurrentOpt) ? color(MC_Color::Green) : color(MC_Color::White));
		MaxOption += 1;
	}
}