#pragma once

int DebugX = 49, DebugY = 69, DebugW = 190, DebugH = 82;
void DebugHud()
{
	if (Buttons::IsMCButtonPressed(Buttons::LEFT)) { NyTekCFW::sleep(200); DebugX += 1; }
	if (Buttons::IsMCButtonPressed(Buttons::RIGHT)) { NyTekCFW::sleep(200); DebugX -= 1; }
	if (Buttons::IsMCButtonPressed(Buttons::UP)) { NyTekCFW::sleep(200); DebugY += 1; }
	if (Buttons::IsMCButtonPressed(Buttons::DOWN)) { NyTekCFW::sleep(200); DebugY -= 1; }
	if (Buttons::IsMCButtonPressed(Buttons::O)) { NyTekCFW::sleep(200); DebugW += 1; }
	if (Buttons::IsMCButtonPressed(Buttons::SQUARE)) { NyTekCFW::sleep(200); DebugW -= 1; }
	if (Buttons::IsMCButtonPressed(Buttons::TRIANGLE)) { NyTekCFW::sleep(200); DebugH += 1; }
	if (Buttons::IsMCButtonPressed(Buttons::X)) { NyTekCFW::sleep(200); DebugH -= 1; }
	if (Buttons::IsMCButtonPressed(Buttons::L1)) { printf("Coords: %i %i %i %i \n", DebugX, DebugY, DebugW, DebugH); }
}

void Render()
{
	RenderSubMenu();
}