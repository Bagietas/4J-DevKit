#pragma once

void RenderSubMenu()
{
	if (Opened)
	{
		Menu::AddHuds();

		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 3;
			Menu::AddTitle(L"DownCraft Utility Menu");
			Menu::AddOption(L"Test options");
			Menu::AddBoolOption(L"Toggle Title", ToggleTitle);
			Menu::AddBoolOption(L"Toggle Position", TogglePosition);
			switch (getOption()) {
			case(1): ToggleTitle = !ToggleTitle; break;
			case(2): TogglePosition = !TogglePosition; break;
			}
			break;
		}
	}
}