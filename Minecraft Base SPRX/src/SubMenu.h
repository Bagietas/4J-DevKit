#pragma once

enum eMenus
{
	MainMenu,
	HostMenu,
	NonHostMenu
};

void RenderOptions()
{
	switch (CurrentMenu)
	{
	case(MainMenu):
		switch (CurrentOpt)
		{
		case(0):
			CurrentMenu = HostMenu;
			CurrentOpt = 0;
			break;
		case(1):
			CurrentMenu = NonHostMenu;
			CurrentOpt = 0;
			break;
		}
		break;
	}
}

void RenderClosePage()
{
	if (CurrentMenu == MainMenu)
		Opened = false;
	else if (CurrentMenu == HostMenu)
		CurrentMenu = MainMenu;
	else if (CurrentMenu == NonHostMenu)
		CurrentMenu = MainMenu;
}

void RenderSubMenu()
{
	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 5;
			Menu::AddHud(5);
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
			Menu::AddHud(2);
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::AddDescription(L"Host Menu");
			Menu::AddOption(L"God Mode");
			Menu::AddOption(L"Instant Damage");
			break;
		}
	}
}