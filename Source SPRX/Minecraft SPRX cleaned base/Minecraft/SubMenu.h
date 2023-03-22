#pragma once

void RenderSubMenu()
{
	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 3;
			Menu::AddTitle(L"DownCraft Utility Menu");
			Menu::AddOption(L"Test options");
			Menu::AddBoolOption(L"Toggle Title", ToggleTitle);
			Menu::AddBoolOption(L"Toggle Position", TogglePosition);
			Menu::AddOption(L"Restart Game");
			switch (Menu::getOption()) {
			case(1): ToggleTitle = !ToggleTitle; break;
			case(2): TogglePosition = !TogglePosition; break;
			case(3): RestartGame(); break;
			}
			break;
		}
	}
}