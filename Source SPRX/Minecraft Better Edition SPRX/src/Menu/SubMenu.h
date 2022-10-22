#pragma once

int getOption()
{
	if (optionPress) 
	{
		optionPress = false;
		return CurrentOpt;
	}
	else return -1;
}

void RenderClosePage()
{
	if (returnPress)
	{
		returnPress = false;
		CurrentOpt = 0;
		if (CurrentMenu == MainMenu)
			Closed = true;
		else if (CurrentMenu == BetterMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == MicsMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == SettingsMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == CreditsMenu)
			CurrentMenu = MainMenu;
	}
}

void RenderSubMenu()
{
	RenderClosePage();
	Controller();

	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 4;
			Menu::AddTitle(L"Better Menu    >");
			Menu::AddOption(L"Better Menu");
			Menu::AddOption(L"Mics Menu");
			Menu::AddOption(L"Settings Menu");
			Menu::AddOption(L"Credits Menu");
			switch (getOption()) {
			case(0): CurrentMenu = BetterMenu; break;
			case(1): CurrentMenu = MicsMenu; break;
			case(2): CurrentMenu = SettingsMenu; break;
			case(3): CurrentMenu = CreditsMenu; break;
			}
			break;

		case(BetterMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(L"Better Menu    >");
			Menu::AddBoolOption(L"Show Position", !TogglePosition);
			Menu::AddBoolOption(L"Show Gametime", !ToggleGametime);
			switch (getOption()) {
			case(0): TogglePosition = !TogglePosition; break;
			case(1): ToggleGametime = !ToggleGametime; break;
			}
			break;

		case(MicsMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(L"Better Menu    >");
			Menu::AddOption(L"Submenu 1");
			Menu::AddOption(L"Submenu 1");
			break;

		case(SettingsMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(L"Better Menu    >");
			Menu::AddOption(L"Close Minecraft");
			Menu::AddOption(L"Submenu 1");
			switch (getOption()) {
			case(0): *(int*)0xAD8320 = 0x408000CC; *(int*)0x785DBC = 0x40800028; break;
			}
			break;

		case(CreditsMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(L"Better Menu    >");
			Menu::AddOption(L"Submenu 1");
			Menu::AddOption(L"Submenu 1");
			break;
		}
	}
}