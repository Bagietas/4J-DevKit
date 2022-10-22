#pragma once

void RenderSubMenu()
{
	Controller();

	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 5;
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::AddDescription(L"Main Menu");
			Menu::AddOption(L"Host Options");
			Menu::AddOption(L"Non-Host Options");
			Menu::AddOption(L"Sub Menu 3");
			Menu::AddOption(L"Sub Menu 4");
			Menu::AddOption(L"Sub Menu 5");
			break;

		case(HostMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::AddDescription(L"Host Menu");
			Menu::AddOption(L"God Mode");
			Menu::AddOption(L"Instant Damage");
			break;
		}
	}
}