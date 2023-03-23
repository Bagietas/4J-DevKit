#pragma once

void RenderSubMenu()
{
	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 5;
			Menu::AddTitle(L"DownCraft Utility Menu");
			Menu::AddOption(L"Test options");
			Menu::AddBoolOption(L"Toggle Title", ToggleTitle);
			Menu::AddBoolOption(L"Toggle Position", TogglePosition);
			Menu::AddOption(L"Restart Game");
			Menu::AddOption(L"Send Notif");
			switch (getOption()) {
			case(1): ToggleTitle = !ToggleTitle; break;
			case(2): TogglePosition = !TogglePosition; break;
			case(3): HTTP::SendRequest("xmb.ps3$reloadgame"); break;
			case(4): HTTP::SendURLRequestV2("webhook.php?details=DiscordMessage&message=Test"); break;
			}
			break;
		}
	}
}