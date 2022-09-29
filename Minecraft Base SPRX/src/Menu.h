#pragma once

int DebugX = 49;
int DebugY = 69;
int DebugW = 190;
int DebugH = 82;

void DebugHud()
{
	if (Buttons::IsMCButtonPressed(Buttons::LEFT)) {
		NyTekCFW::sleep(200);
		DebugX += 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::RIGHT)) {
		NyTekCFW::sleep(200);
		DebugX -= 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::UP)) {
		NyTekCFW::sleep(200);
		DebugY += 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::DOWN)) {
		NyTekCFW::sleep(200);
		DebugY -= 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::O)) {
		NyTekCFW::sleep(200);
		DebugW += 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::SQUARE)) {
		NyTekCFW::sleep(200);
		DebugW -= 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::TRIANGLE)) {
		NyTekCFW::sleep(200);
		DebugH += 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::X)) {
		NyTekCFW::sleep(200);
		DebugH -= 1;
	}

	if (Buttons::IsMCButtonPressed(Buttons::L1)) {
		printf("Coords: %i %i %i %i \n", DebugX, DebugY, DebugW, DebugH);
	}
}

namespace Menu
{
	void AddHud(int sub)
	{
		if (sub == 1) { DrawRectangleAlpha(49, 85, 190, 97, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 2) { DrawRectangleAlpha(49, 85, 190, 107, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 3) { DrawRectangleAlpha(49, 85, 190, 117, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 4) { DrawRectangleAlpha(49, 85, 190, 127, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 5) { DrawRectangleAlpha(49, 85, 190, 137, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 6) { DrawRectangleAlpha(49, 85, 190, 147, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 7) { DrawRectangleAlpha(49, 85, 190, 157, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 8) { DrawRectangleAlpha(49, 85, 190, 167, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 9) { DrawRectangleAlpha(49, 85, 190, 177, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 10) { DrawRectangleAlpha(49, 85, 190, 187, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 11) { DrawRectangleAlpha(49, 85, 190, 197, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 12) { DrawRectangleAlpha(49, 85, 190, 207, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 13) { DrawRectangleAlpha(49, 85, 190, 217, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 14) { DrawRectangleAlpha(49, 85, 190, 227, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 15) { DrawRectangleAlpha(49, 85, 190, 237, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 16) { DrawRectangleAlpha(49, 85, 190, 247, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 17) { DrawRectangleAlpha(49, 85, 190, 257, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 18) { DrawRectangleAlpha(49, 85, 190, 267, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 29) { DrawRectangleAlpha(49, 85, 190, 277, Color(50, 50, 50, MenuColorAlpha)); }
		else if (sub == 20) { DrawRectangleAlpha(49, 85, 190, 287, Color(50, 50, 50, MenuColorAlpha)); }
	}
						
	void AddTitle(const wchar_t* title)
	{
		DrawRectangleAlpha(49, 59, 190, 72, Color(0, 147, 255, MenuColorAlphaTitle));
		DrawTextWithShadow(title, 84, 62, color(MC_Colors::White));
	}

	void AddDescription(const wchar_t* desc)
	{
		DrawRectangleAlpha(49, 72, 190, 85, Color(32, 32, 32, MenuColorAlphaDescription));
		DrawTextWithShadow(desc, 53, 75, color(MC_Colors::White));
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, 55, 87 + (10 * MaxOption), color(MC_Colors::White));
		MaxOption += 1;
	}
}

void Render()
{
	MaxOption = 0;
	DebugHud();
	Menu::AddHud(5);
	Menu::AddTitle(L"DownCraft SPRX");
	Menu::AddDescription(L"Main Menu");
	Menu::AddOption(L"Host Options");
	Menu::AddOption(L"Non-Host Options");
	Menu::AddOption(L"Mics Options");
	Menu::AddOption(L"Teleport Options");
	Menu::AddOption(L"Credits Options");
}