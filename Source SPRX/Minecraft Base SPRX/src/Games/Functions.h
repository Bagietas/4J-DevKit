#pragma once

#pragma region "Menu Functions"

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

#pragma endregion

#pragma region "Functions Caller"

void PlayUISound(uintptr_t* SoundEvent) {
	uintptr_t ConsoleUIController = 0x1558228;
	FUNCTIONS::ConsoleUIController_PlayUISFX(ConsoleUIController, *SoundEvent);
}

void mc_printf(const char* format, ...) {
	FUNCTIONS::__printf(format);
}

int Font_width(const wchar_t* text) {
	FUNCTIONS::Font_width(mc->theMinecraft->fontRenderer, (uint32_t)&getString(text));
}

void DrawText(const wchar_t* text, float x, float y, uint32_t color) {
	FUNCTIONS::DrawText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color, 0, 1);
}

void DrawTextC(char* text, float x, float y, uint32_t color) {
	FUNCTIONS::DrawText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(c2wc(text)), x, y, color, 0, 1);
}

void DrawTextWithShadow(const wchar_t* text, uint32_t x, uint32_t y, uint32_t color) {
	FUNCTIONS::DrawTextWithShadow(g_GuiComponent, mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color);
}

void DrawRectangleAlpha(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color) {
	FUNCTIONS::DrawRectangleAlpha(g_GuiComponent, x, y, width, height, color.ToHex());
}

void DrawRectancle(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color) {
	FUNCTIONS::DrawRectangleAlpha(g_GuiComponent, x, y, width, height, color.ToHex());
}

void DrawGradientRectangle(float x, float y, float w, float h, int* color1, int* color2, bool LeftOrUp) 
{
	if (LeftOrUp)
	{
		uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
		FUNCTIONS::Tesselator_End(pTesselator);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, color2);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, color1);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, color1);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, color2);
		FUNCTIONS::Tesselator_End(pTesselator);
	}
	else
	{
		uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
		FUNCTIONS::Tesselator_End(pTesselator);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, color1);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, color1);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, color2);
		FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, color2);
		FUNCTIONS::Tesselator_End(pTesselator);
	}
}

#pragma endregion