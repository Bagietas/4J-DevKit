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
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::Description(L"Main Menu");
			Menu::AddSubOption(L"Better Options");
			Menu::AddSubOption(L"Mics Menu");
			Menu::AddSubOption(L"Settings Menu");
			Menu::AddSubOption(L"Credits Menu");
			switch (getOption()) {
			case(0): CurrentMenu = BetterMenu; CurrentOpt = 0; break;
			case(1): CurrentMenu = MicsMenu; CurrentOpt = 0; break;
			case(2): CurrentMenu = SettingsMenu; CurrentOpt = 0; break;
			case(3): CurrentMenu = CreditsMenu; CurrentOpt = 0; break;
			}
			break;

		case(BetterMenu):
			MaxSubOptions = 5;
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::Description(L"Better Options");
			Menu::AddBoolOption(L"Show Position", !TogglePosition);
			Menu::AddBoolOption(L"Show Gametime", !ToggleGametime);
			Menu::AddBoolOption(L"Show Ping", !TogglePing);
			Menu::AddBoolOption(L"Show Keystrokes", !ToggleKeystrokes);
			Menu::AddBoolOption(L"Show CPS", !ToggleCPS);
			switch (getOption()) {
			case(0): TogglePosition = !TogglePosition; break;
			case(1): ToggleGametime = !ToggleGametime; break;
			case(2): TogglePing = !TogglePing; break;
			case(3): ToggleKeystrokes = !ToggleKeystrokes; break;
			case(4): ToggleCPS = !ToggleCPS; break;
			}
			break;

		case(MicsMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::Description(L"Mics Menu");
			Menu::AddBoolOption(L"Show Title", !ToggleTitleSPRX);
			Menu::AddOption(L"Close Minecraft");
			switch (getOption()) {
			case(0): ToggleTitleSPRX = !ToggleTitleSPRX; break;
			case(1): Offsets::CLOSE_MINECRAFT(); break;
			}
			break;

		case(SettingsMenu):
			MaxSubOptions = 4;
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::Description(L"Settings Menu");
			Menu::AddOption(L"MenuX +");
			Menu::AddOption(L"MenuX -");
			Menu::AddOption(L"MenuY +");
			Menu::AddOption(L"MenuY -");
			switch (getOption()) {
			case(0): MenuX += 1; break;
			case(1): MenuX -= 1; break;
			case(2): MenuY += 1; break;
			case(3): MenuY -= 1; break;
			}
			break;

		case(CreditsMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::Description(L"Credits Menu");
			Menu::AddOption(L"Submenu 1");
			Menu::AddOption(L"Submenu 1");
			break;
		}
	}
}