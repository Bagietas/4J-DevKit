#pragma once

void RenderSubMenu()
{
	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 4;
			Menu->AddHuds(MaxSubOptions);
			Menu->AddTitle(titleSPRX);
			Menu->Description(L"Main Menu");
			Menu->AddSubOption(L"Host Options");
			Menu->AddSubOption(L"Non Host Options");
			Menu->AddSubOption(L"Players Options");
			Menu->AddSubOption(L"Weather Options");
			switch (getOption()) {
			case(0): openSubmenu(HostMenu1); break;
			}
			break;

		case(HostMenu1):
			MaxSubOptions = 4;
			Menu->AddHuds(MaxSubOptions);
			Menu->AddTitle(titleSPRX);
			Menu->Description(L"Host Menu");
			Menu->AddBoolOption(L"God Mode", GodMode);
			Menu->AddBoolOption(L"Demi God Mode", DemiGodMode);
			Menu->AddOption(L"Test options 3");
			Menu->AddOption(L"Test options 4");
			switch (getOption()) {
			case(0): GodMode = !GodMode; Offsets->GOD_MODE(GodMode); break;
			case(1): DemiGodMode = !DemiGodMode; Offsets->DEMI_GOD_MODE(DemiGodMode); break;
			}
			break;
		}
	}
}