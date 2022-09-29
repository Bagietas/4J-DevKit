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

void Controller()
{
	int wI = 0;
	keyPressed[wI] = false;


	if (Buttons::IsMCButtonPressed(Buttons::L1) && Buttons::IsMCButtonPressed(Buttons::UP))
	{
		if (!Opened)
		{
			Opened = true;
			CurrentMenu = MainMenu;
		}
	}

	if (Opened)
	{
		if (Buttons::IsMCButtonPressed(Buttons::UP))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				CurrentOpt = CurrentOpt - 1;
				return;
			}
		}

		if (Buttons::IsMCButtonPressed(Buttons::DOWN))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				CurrentOpt = CurrentOpt + 1;
				return;
			}
		}

		int fix = MaxSubOptions;
		fix -= 1;

		if (CurrentOpt > fix)
		{
			CurrentOpt = 0;
		}

		if (CurrentOpt < 0)
		{
			CurrentOpt = fix;
		}

		if (Buttons::IsMCButtonPressed(Buttons::X))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				RenderOptions();
				return;
			}
		}

		if (Buttons::IsMCButtonPressed(Buttons::O))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				RenderClosePage();
				return;
			}
		}

		if (!keyPressed[wI])
		{
			lockFirst[wI] = false;
			freeFirst[wI] = true;
			resetWait[wI] = true;
			resetWait2[wI] = true;
		}
	}
}

void Render()
{
	//DebugHud();
	Controller();
	RenderSubMenu();
}