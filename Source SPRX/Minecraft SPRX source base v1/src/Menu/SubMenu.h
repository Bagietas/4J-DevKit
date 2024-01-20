#pragma once

void RenderSubMenu()
{
	if (ShowUsername)
		Menu::AddArrayText(wGetUsername, color(MC_Color::White));
	if (ShowResolution)
		Menu::AddArrayText(wGetResolution, color(MC_Color::White));
	if (ShowPosition)
		Menu::AddArrayText(wGetPosition, color(MC_Color::White));
	if (ShowChunk)
		Menu::AddArrayText(wGetChunk, color(MC_Color::White));
	if (ShowDimension)
		Menu::AddArrayText(wGetDimension, color(MC_Color::White));
	if (ShowEntityID)
		Menu::AddArrayText(wGetEntityID, color(MC_Color::White));
	if (ShowTemp)
		Menu::AddArrayText(wGetTemp, color(MC_Color::White));
	if (ShowGametime)
		Menu::AddArrayText(wGetGametime, color(MC_Color::White));

	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 4;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"DownCraft SPRX");
			Menu::AddSubOption(L"Main Options");
			Menu::AddSubOption(L"Teleport Options");
			Menu::AddSubOption(L"Settings Menu");
			Menu::AddSubOption(L"Credits Menu");
			switch (getOption()) {
			case(0): openSubmenu(eMenus::MainOptions); break;
			case(1): openSubmenu(eMenus::TeleportMenu); break;
			case(2): openSubmenu(eMenus::SettingsPage); break;
			case(3): openSubmenu(eMenus::CreditsMenu); break;
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
			case(0): GodMode =! GodMode; Options::GOD_MODE(GodMode); break;
			case(1): SuperSpeed = !SuperSpeed; Options::SUPER_SPEED(SuperSpeed); break;
			}
			break;

		case(TeleportMenu):
			MaxSubOptions = 5;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Teleport Menu");
			Menu::AddIntOption(L"CoordX", 0, -430, 450, CoordX);
			Menu::AddIntOption(L"CoordY", 1, -999, 510, CoordY);
			Menu::AddIntOption(L"CoordZ", 2, -430, 450, CoordZ);
			Menu::AddOption(L"Save Current Coord");
			Menu::AddOption(L"Set Teleport");
			switch (getOption()) {
			case(3): Options::getTeleport(); break;
			case(4): Options::setTeleport(CoordX, CoordY, CoordZ); break;
			}
			break;

		case(SettingsPage):
			MaxSubOptions = 3;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Settings Menu");
			Menu::AddSubOption(L"Color Menu");
			Menu::AddSubOption(L"Settings Menu");
			Menu::AddSubOption(L"Information Menu");
			switch (getOption()) {
			case(0): openSubmenu(eMenus::ColorMenu); break;
			case(1): openSubmenu(eMenus::SettingsMenu); break;
			case(2): openSubmenu(eMenus::InformationMenu); break;
			}
			break;

		case(ColorMenu):
			MaxSubOptions = 14;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Color Menu");
			Menu::AddBoolOption(L"Rainbow Color", RainbowMenu);
			Menu::AddBoolOption(L"Rainbow Gradient", RainbowGradient);
			Menu::AddIntOption(L"Background Opacity", 2, 0, 255, MenuA);
			Menu::AddCategory(L"- Menu Colors");
			Menu::AddIntOption(L"Menu R", 4, 0, 255, MenuR);
			Menu::AddIntOption(L"Menu G", 5, 0, 255, MenuG);
			Menu::AddIntOption(L"Menu B", 6, 0, 255, MenuB);
			Menu::AddCategory(L"- Gradient Colors");
			Menu::AddIntOption(L"Gradient1 R", 8, 0, 255, MenuGradient1R);
			Menu::AddIntOption(L"Gradient1 G", 9, 0, 255, MenuGradient1G);
			Menu::AddIntOption(L"Gradient1 B", 10, 0, 255, MenuGradient1B);
			Menu::AddIntOption(L"Gradient2 R", 11, 0, 255, MenuGradient2R);
			Menu::AddIntOption(L"Gradient2 G", 12, 0, 255, MenuGradient2G);
			Menu::AddIntOption(L"Gradient2 B", 13, 0, 255, MenuGradient2B);
			switch (getOption()) {
			case(0): RainbowMenu =! RainbowMenu; if (RainbowMenu == true) { ThemeColors = "RAINBOW"; } else { ThemeColors = "DEFAULT"; } break;
			case(1): RainbowGradient =! RainbowGradient; break;
			}
			break;

		case(SettingsMenu):
			MaxSubOptions = 8;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Settings Menu");
			Menu::AddIntOption(L"Menu Lenght", 0, 0, 455, menuLenght);
			Menu::AddIntOption(L"Menu Border", 1, 0, 10, MenuBorderSize);
			Menu::AddIntOption(L"Menu X", 2, -200, 800, MenuX);
			Menu::AddIntOption(L"Menu Y", 3, -200, 800, MenuY);
			Menu::AddIntOption(L"Checkbox Style", 4, 0, 3, boolStyle);
			Menu::AddIntOption(L"Background Style", 5, 0, 1, BackgroundStyle);
			Menu::AddBoolOption(L"Gradient Menu", GradientMenu);
			Menu::AddBoolOption(L"Show Logo", ShowLogo);
			switch (getOption()) {
			case(6): GradientMenu =! GradientMenu; break;
			case(7): ShowLogo =! ShowLogo; break;
			}
			break;

		case(InformationMenu):
			MaxSubOptions = 8;
			Menu::AddHuds(MaxSubOptions);
			Menu::AddTitle(L"Information Menu");
			Menu::AddBoolOption(L"Show Username", ShowUsername);
			Menu::AddBoolOption(L"Show Resolution", ShowResolution);
			Menu::AddBoolOption(L"Show Position", ShowPosition);
			Menu::AddBoolOption(L"Show Chunk", ShowChunk);
			Menu::AddBoolOption(L"Show Dimension", ShowDimension);
			Menu::AddBoolOption(L"Show EntityID", ShowEntityID);
			Menu::AddBoolOption(L"Show CPU & RSX", ShowTemp);
			Menu::AddBoolOption(L"Show GameTime", ShowGametime);
			switch (getOption()) {
			case(0): ShowUsername =! ShowUsername; break;
			case(1): ShowResolution =! ShowResolution; break;
			case(2): ShowPosition =! ShowPosition; break;
			case(3): ShowChunk =! ShowChunk; break;
			case(4): ShowDimension =! ShowDimension; break;
			case(5): ShowEntityID =! ShowEntityID; break;
			case(6): ShowTemp =! ShowTemp; break;
			case(7): ShowGametime =! ShowGametime; break;
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