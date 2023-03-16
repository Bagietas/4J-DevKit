#pragma once

void RenderSubMenu()
{
	if (Opened)
	{
		Menu::AddHuds();

		switch (CurrentMenu)
		{
		case(MainMenu):
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Main Menu");
			Menu::AddSubOption(L"Main Options");
			Menu::AddSubOption(L"Mics Menu");
			Menu::AddSubOption(L"Teleport Menu");
			Menu::AddSubOption(L"Name Menu");
			Menu::AddSubOption(L"Settings Menu");
			Menu::AddSubOption(L"Credits Menu");
			switch (getOption()) {
			case(0): openSubmenu(eMenus::MainOptions); break;
			case(1): openSubmenu(eMenus::MicsMenu); break;
			case(2): openSubmenu(eMenus::TeleportMenu); break;
			case(3): openSubmenu(eMenus::NameMenu); break;
			case(4): openSubmenu(eMenus::SettingsMenu); break;
			case(5): openSubmenu(eMenus::CreditsMenu); break;
			}
			break;

		case(MainOptions):
			MaxSubOptions = 10;
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Main Options");
			Menu::AddOption(L"Show Title");
			switch (getOption()) {
			}
			break;

		case(MicsMenu):
			MaxSubOptions = 1;
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Mics Menu");
			Menu::AddOption(L"No Clip");
			switch (getOption()) {
			case(0): mc->theMinecraft->cMultiplayerLocalPlayer->noClip = true; break;
			}
			break;

		case(TeleportMenu):
			MaxSubOptions = 5;
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Teleport Options");
			Menu::AddOption(L"Save Current Coordinates");
			Menu::AddOption(L"Set Teleport");
			switch (getOption()) {
			}
			break;

		case(NameMenu):
			MaxSubOptions = 1;
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Name Menu");
			Menu::AddOption(L"Enter a text");
			switch (getOption()) {
			}
			break;

		case(SettingsMenu):
			MaxSubOptions = 2;
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Settings Menu");
			Menu::AddSubOption(L"Colors Menu");
			Menu::AddSubOption(L"Editable Value");
			switch (getOption()) {
			case(0): openSubmenu(eMenus::ColorsMenu); break;
			case(1): openSubmenu(eMenus::EditableValMenu); break;
			}
			break;

		case(ColorsMenu):
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Colors Menu");
			Menu::AddIntOption(L"Red  ", 0, 0, 255, MenuR);
			Menu::AddIntOption(L"Green", 1, 0, 255, MenuG);
			Menu::AddIntOption(L"Blue ", 2, 0, 255, MenuB);
			break;

		case(EditableValMenu):
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Settings Menu");
			Menu::AddIntOption(L"MenuX", 0, -550, 600, MenuX);
			Menu::AddIntOption(L"MenuY", 1, -500, 600, MenuY);
			break;

		case(CreditsMenu):
			Menu::AddTitle(titleSPRX);
			Menu::Description(L"Credits Menu");
			Menu::AddOption(L"Misaki (Creator)");
			Menu::AddOption(L"YT: Misakiii");
			break;
		}
	}
}