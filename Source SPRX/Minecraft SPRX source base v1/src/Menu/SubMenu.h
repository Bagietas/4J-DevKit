#pragma once

void RenderSubMenu()
{
	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 3;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(titleSPRX);
			Menu::AddSubOption(L"Main Options");
			Menu::AddSubOption(L"Settings Menu");
			Menu::AddSubOption(L"Credits Menu");
			switch (getOption()) {
			case(0): openSubmenu(eMenus::MainOptions); break;
			case(1): openSubmenu(eMenus::SettingsMenu); break;
			case(2): openSubmenu(eMenus::CreditsMenu); break;
			}
			break;

		case(MainOptions):
			MaxSubOptions = 4;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Main Options");
			Menu::AddBoolOption(L"God Mode", GodMode);
			Menu::AddBoolOption(L"Super Speed", SuperSpeed);
			Menu::AddOption(L"Sub Option 3");
			Menu::AddOption(L"Sub Option 4");
			switch (getOption()) {
			case(0): GodMode = !GodMode; break;
			case(1): SuperSpeed = !SuperSpeed; break;
			}
			break;

		case(SettingsMenu):
			MaxSubOptions = 8;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Settings Menu");
			Menu::AddIntOption(L"Menu Lenght", 0, 0, 455, menuLenght);
			Menu::AddIntOption(L"Menu Border", 1, 0, 5, MenuBorderSize);
			Menu::AddIntOption(L"Menu X", 2, 0, 500, MenuX);
			Menu::AddIntOption(L"Menu Y", 3, 0, 500, MenuY);
			Menu::AddIntOption(L"Menu Color R", 4, 0, 255, MenuR);
			Menu::AddIntOption(L"Menu Color G", 5, 0, 255, MenuG);
			Menu::AddIntOption(L"Menu Color B", 6, 0, 255, MenuB);
			Menu::AddBoolOption(L"Menu Gradient", GradientMenu);
			switch (getOption()) {
			case(7): GradientMenu = !GradientMenu; break;
			}
			break;

		case(CreditsMenu):
			MaxSubOptions = 1;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Credits Menu");
			Menu::AddOption(L"Misaki (creator)");
			break;
		}
	}
}