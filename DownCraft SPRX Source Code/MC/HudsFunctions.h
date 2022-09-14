#pragma once

#pragma region "Draw Functions"

void drawLineLocation(const float* start, const float* end)
{
	int color[3] = { 50, 50, 50 };
	float startl[3] = { start[0] - mc->theMinecraft->cLevelRenderer->location[0], start[1] - mc->theMinecraft->cLevelRenderer->location[1], start[2] - mc->theMinecraft->cLevelRenderer->location[2] };
	float endl[3] = { end[0] - mc->theMinecraft->cLevelRenderer->location[0], end[1] - mc->theMinecraft->cLevelRenderer->location[1], end[2] - mc->theMinecraft->cLevelRenderer->location[2] };
	//float startl[3] = { start[0] - mc->theMinecraft->cMultiplayerLocalPlayer->LocationX, start[1] - mc->theMinecraft->cMultiplayerLocalPlayer->LocationY, start[2] - mc->theMinecraft->cMultiplayerLocalPlayer->LocationZ };
	//float endl[3] = { end[0] - mc->theMinecraft->cMultiplayerLocalPlayer->LocationX, end[1] - mc->theMinecraft->cMultiplayerLocalPlayer->LocationY, end[2] - mc->theMinecraft->cMultiplayerLocalPlayer->LocationZ };

	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, start[0], start[1], start[2], color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, end[0], end[1], end[2], color);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawLine(const Vector2& start, const Vector2& end, int* color)
{
	float modX = 0 - (start.y - end.y);
	float modY = start.x - end.x;

	float len = sqrtf(modX * modX + modY * modY);

	modX /= len;
	modY /= len;

	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, start.x + modX, start.y + modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, start.x - modX, start.y - modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, end.x - modX, end.y - modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, start.x + modX, start.y + modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, end.x + modX, end.y + modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, end.x - modX, end.y - modY, 0, color);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawLineWidth(const Vector2& start, const Vector2& end, float lineWidth)
{
	int color[3] = { 50, 50, 50 };
	float modX = 0 - (start.y - end.y);
	float modY = start.x - end.x;

	float len = sqrtf(modX * modX + modY * modY);

	modX /= len;
	modY /= len;
	modX *= lineWidth;
	modY *= lineWidth;

	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, start.x + modX, start.y + modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, start.x - modX, start.y - modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, end.x - modX, end.y - modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, start.x + modX, start.y + modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, end.x + modX, end.y + modY, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, end.x - modX, end.y - modY, 0, color);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawRectBorder(float x, float y, float w, float h, int* Color1, int* Color2)
{
	DrawRectangle(x - 1, y - 1, w + 2, h + 2, Color2);
	DrawRectangle(x, y, w, h, Color1);
}

void drawRectRGB(float x, float y, float w, float h, int R, int G, int B)
{
	int colored[3] = { R, G, B };
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, colored);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, colored);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, colored);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, colored);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawGradientLeftRight(float x, float y, float w, float h, int* Color, int* Color2)
{
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, Color2); //left down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, Color); //right down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, Color); //right up
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, Color2); //left up
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawGradientUpDown(float x, float y, float w, float h, int* Color, int* Color2)
{
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, Color2); //left down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, Color2); //right down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, Color); //right up
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, Color); //left up
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawGradient(float x, float y, float w, float h, int* Color, int* Color2)
{
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, Color2);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, Color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, Color2);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, Color);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawGradientLeftRightRGB(float x, float y, float w, float h, int R, int G, int B, int R1, int G1, int B1)
{
	int colored1[3] = { R, G, B };
	int colored2[3] = { R1, G1, B1 };
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, colored2); //left down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, colored1); //right down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, colored1); //right up
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, colored2); //left up
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawGradientUpDownRGB(float x, float y, float w, float h, int R, int G, int B, int R1, int G1, int B1)
{
	int colored1[3] = { R, G, B };
	int colored2[3] = { R1, G1, B1 };
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, colored1); //left down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, colored1); //right down
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, colored2); //right up
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, colored2); //left up
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawGradientRGB(float x, float y, float w, float h, int R, int G, int B, int R1, int G1, int B1)
{
	int colored1[3] = { R, G, B };
	int colored2[3] = { R1, G1, B1 };
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, colored1);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, colored2);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, colored1);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, colored2);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void drawRectBorderRGB(float x, float y, float w, float h, int* Color1, int R, int G, int B)
{
	drawRectRGB(x - 1, y - 1, w + 2, h + 2, R, G, B);
	DrawRectangle(x, y, w, h, Color1);
}

void drawRectBorderRGBV2(float x, float y, float w, float h, int R, int G, int B, int* Color1)
{
	DrawRectangle(x - 1, y - 1, w + 2, h + 2, Color1);
	drawRectRGB(x, y, w, h, R, G, B);
}

void drawRectBorderRGBV3(float x, float y, float w, float h, int* Color1, int R, int G, int B, int R1, int G1, int B1)
{
	drawGradientLeftRightRGB(x - 1, y - 1, w + 2, h + 2, R, G, B, R1, G1, B1);
	DrawRectangle(x, y, w, h, Color1);
}

void DrawHorizontalLine(int startX, int endX, int y, int* color)
{
	if (endX < startX)
	{
		int i = startX;
		startX = endX;
		endX = i;
	}
	//		x pos, Y Pos,  W Pos, H Pos, Color
	DrawRectangle(startX + 1, y, endX + 1, 1, color);
}

void DrawVerticalLine(int x, int startY, int endY, int* color)
{
	int width = 1;
	if (x < startY)
	{
		int i = startY;
		startY = endY;
		endY = i;
	}//		x pos, Y Pos,  W Pos, H Pos, Color
	DrawRectangle(x, startY + 1, 1, endY, color);
}

void snprintf(const char* text, int valeur, int X, int Y)
{
	char option4[0x100];
	wchar_t woption4[0x100];
	_sys_memset(option4, 0, 0x100);
	_sys_memset(woption4, 0, 0x200);
	_sys_snprintf(option4, 0x100, text, (valeur));
	StringToWideCharacter(woption4, option4, _sys_strlen(option4));
	DrawText(woption4, X, Y, color(UI::Color::WHITE));
}

#pragma endregion

void InventoryCreativeTumble()
{
	int wI = 0;
	keyPressed[wI] = false;

	if (InventoryCreaTumbleActive)
	{
		if (InventoryCreaTumble)
			DrawText(L"Press DPAD LEFT for Disable", 27, 335, color(UI::Color::WHITE));
		else
			DrawText(L"Press DPAD LEFT for Enable", 27, 335, color(UI::Color::WHITE));

		if (Buttons::IsMCButtonPressed(Buttons::LEFT))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				if (!InventoryCreaTumble)
				{
					*(int*)0x00AD8480 = 0x41820024;
					*(int*)0x0098871C = 0x38600001;
					*(int*)0x002F0348 = 0x38800001;
					*(int*)0x002F0398 = 0x38800000;
					InventoryCreaTumble = true;
				}
				else
				{
					*(int*)0x00AD8480 = 0x40820024;
					*(int*)0x0098871C = 0x38600000;
					*(int*)0x002F0348 = 0x38800000;
					*(int*)0x002F0398 = 0x38800001;
					InventoryCreaTumble = false;
				}
			}
		}
	}
}

void VersionText()
{
	if (devmenu)
	{
		DrawTextWithShadow(L"DEV Edition", 98, 13, color(UI::Color::WHITE));
	}
	else
	{
		DrawTextWithShadow(L"Public Edition", 98, 13, color(UI::Color::WHITE));
	}
}

void DEBUG_FUNCTIONS_MESSAGES()
{
	if (UI::Settings::ShowPosition)
	{
		DEBUG_FUNCTIONS_MESSAGE = 34;

		if (UI::Settings::ShowPING)
		{
			DEBUG_FUNCTIONS_MESSAGE = 44;

			if (UI::Settings::ShowChunks)
			{
				DEBUG_FUNCTIONS_MESSAGE = 54;

				if (UI::Settings::ShowResolution)
				{
					DEBUG_FUNCTIONS_MESSAGE = 64;

					if (UI::Settings::ShowCPURSX)
					{
						DEBUG_FUNCTIONS_MESSAGE = 74;
					}
				}
			}
		}
	}

	if (mc->theMinecraft->cMultiplayerLocalPlayer->isInWeb == true)
	{
		DrawTextWithShadow(L"[In Web]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	if (mc->theMinecraft->cMultiplayerLocalPlayer->IsSprinting())
	{
		DrawTextWithShadow(L"[Sprinting]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	else if (mc->theMinecraft->cMultiplayerLocalPlayer->IsSneaking())
	{
		DrawTextWithShadow(L"[Sneaking]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	else if (mc->theMinecraft->cMultiplayerLocalPlayer->IsSpectator())
	{
		DrawTextWithShadow(L"[Spectator]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	else if (mc->theMinecraft->cMultiplayerLocalPlayer->IsBurning())
	{
		DrawTextWithShadow(L"[Burning]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	else if (mc->theMinecraft->cMultiplayerLocalPlayer->isInWater())
	{
		DrawTextWithShadow(L"[In Water]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	else if (mc->theMinecraft->cMultiplayerLocalPlayer->fallDistance > 0)
	{
		DrawTextWithShadow(L"[Falling]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	else if (mc->theMinecraft->cMultiplayerLocalPlayer->onGround == true)
	{
		DrawTextWithShadow(L"[On Ground]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
	else if (mc->theMinecraft->cMultiplayerLocalPlayer->isDead == true)
	{
		DrawTextWithShadow(L"[Is Dead]", 20, DEBUG_FUNCTIONS_MESSAGE, color(UI::Color::WHITE));
	}
}

void Welcome_Message()
{
	if (UI::Settings::ShowPosition)
	{

	}
	else
	{
		if (UI::Settings::ShowPING)
		{
			DrawText(L"Welcome: ", 20, 23, color(UI::Color::WHITE));
			DrawTextC(PSN_NAME, 60, 23, color(UI::Color::ORANGE));
		}
		else
		{
			DrawText(L"Welcome: ", 20, 24, color(UI::Color::WHITE));
			DrawTextC(PSN_NAME, 60, 24, color(UI::Color::ORANGE));
		}
	}
}

void get_temperature(uint32_t a, uint32_t* b)
{
	system_call_2(383, (uint64_t)(uint32_t)a, (uint64_t)(uint32_t)b);
}

void get_temp()
{
	if (UI::Settings::ShowCPURSX)
	{
		if (frameTime(120, 1, false))
		{
			char systemperature[100];
			get_temperature(0, &cpu_t);//0 cpu
			get_temperature(1, &rsx_t);//1 rsx
			cpu_t = cpu_t >> 24;
			rsx_t = rsx_t >> 24;
		}

		char option[0x100];
		wchar_t woption[0x100];
		_sys_memset(option, 0, 0x100);
		_sys_memset(woption, 0, 0x200);
		_sys_snprintf(option, 0x100, "CPU :  %iC / RSX :  %iC", cpu_t, rsx_t);
		StringToWideCharacter(woption, option, strlen(option));
		DrawRectangle(15, 61, 100, 13, UI::Color::BLACK);
		DrawTextWithShadow(woption, 20, 64, color(UI::MCTextColors::White));
	}
}


void GetPosition()
{
	if (UI::Settings::ShowPosition)
	{
		char option[0x100];
		wchar_t woption[0x100];
		_sys_memset(option, 0, 0x100);
		_sys_memset(woption, 0, 0x200);
		_sys_snprintf(option, 0x100, "Position: (%i, %i, %i)", (int)mc->theMinecraft->cMultiplayerLocalPlayer->posX - 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->posY + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->posZ);
		StringToWideCharacter(woption, option, strlen(option));
		DrawRectangle(15, 20, 115, 13, UI::Color::BLACK);
		DrawTextWithShadow(woption, 20, 23, color(UI::MCTextColors::White));
	}
}

void GetDebugXY()
{
	char option4[0x100];
	wchar_t woption4[0x100];
	_sys_memset(option4, 0, 0x100);
	_sys_memset(woption4, 0, 0x200);
	_sys_snprintf(option4, 0x100, "Text X: %i", (DebugTextX));
	StringToWideCharacter(woption4, option4, _sys_strlen(option4));
	DrawTextWithShadow(woption4, 130, 55, color(UI::MCTextColors::White));

	char option8[0x100];
	wchar_t woption8[0x100];
	_sys_memset(option8, 0, 0x100);
	_sys_memset(woption8, 0, 0x200);
	_sys_snprintf(option8, 0x100, "Text Y: %i", (DebugTextY));
	StringToWideCharacter(woption8, option8, _sys_strlen(option8));
	DrawTextWithShadow(woption4, 130, 65, color(UI::MCTextColors::White));

	char option16[0x100];
	wchar_t woption16[0x100];
	_sys_memset(option16, 0, 0x100);
	_sys_memset(woption16, 0, 0x200);
	_sys_snprintf(option16, 0x100, "Hud X: %i", (DebugHudX));
	StringToWideCharacter(woption16, option16, _sys_strlen(option16));
	DrawTextWithShadow(woption16, 130, 75, color(UI::MCTextColors::White));

	char option26[0x100];
	wchar_t woption26[0x100];
	_sys_memset(option26, 0, 0x100);
	_sys_memset(woption26, 0, 0x200);
	_sys_snprintf(option26, 0x100, "Hud Y: %i", (DebugHudY));
	StringToWideCharacter(woption26, option26, _sys_strlen(option26));
	DrawTextWithShadow(woption26, 130, 85, color(UI::MCTextColors::White));

	char option36[0x100];
	wchar_t woption36[0x100];
	_sys_memset(option36, 0, 0x100);
	_sys_memset(woption36, 0, 0x200);
	_sys_snprintf(option36, 0x100, "Hud W: %i", (DebugHudW));
	StringToWideCharacter(woption36, option36, _sys_strlen(option36));
	DrawTextWithShadow(woption36, 130, 95, color(UI::MCTextColors::White));

	char option46[0x100];
	wchar_t woption46[0x100];
	_sys_memset(option46, 0, 0x100);
	_sys_memset(woption46, 0, 0x200);
	_sys_snprintf(option46, 0x100, "Hud H: %i", (DebugHudH));
	StringToWideCharacter(woption46, option46, _sys_strlen(option46));
	DrawTextWithShadow(woption46, 130, 105, color(UI::MCTextColors::White));

	char option47[0x100];
	wchar_t woption47[0x100];
	_sys_memset(option47, 0, 0x100);
	_sys_memset(woption47, 0, 0x200);
	_sys_snprintf(option47, 0x100, "Line Start X: %i", (DebugLineStartX));
	StringToWideCharacter(woption47, option47, _sys_strlen(option47));
	DrawTextWithShadow(woption47, 130, 115, color(UI::MCTextColors::White));

	char option48[0x100];
	wchar_t woption48[0x100];
	_sys_memset(option48, 0, 0x100);
	_sys_memset(woption48, 0, 0x200);
	_sys_snprintf(option48, 0x100, "Line Start Y: %i", (DebugLineStartY));
	StringToWideCharacter(woption48, option48, _sys_strlen(option48));
	DrawTextWithShadow(woption47, 130, 125, color(UI::MCTextColors::White));

	char option49[0x100];
	wchar_t woption49[0x100];
	_sys_memset(option49, 0, 0x100);
	_sys_memset(woption49, 0, 0x200);
	_sys_snprintf(option49, 0x100, "Line End X: %i", (DebugLineEndX));
	StringToWideCharacter(woption49, option49, _sys_strlen(option49));
	DrawTextWithShadow(woption49, 130, 135, color(UI::MCTextColors::White));

	char option50[0x100];
	wchar_t woption50[0x100];
	_sys_memset(option50, 0, 0x100);
	_sys_memset(woption50, 0, 0x200);
	_sys_snprintf(option50, 0x100, "Line End Y: %i", (DebugLineEndY));
	StringToWideCharacter(woption50, option50, _sys_strlen(option50));
	DrawTextWithShadow(woption49, 130, 145, color(UI::MCTextColors::White));
}

void GetPingz()
{
	if (frameTime(30, 1, false))
	{
		_sys_memset(PING, 0, 0x100);
		_sys_memset(wPING, 0, 0x200);
		_sys_snprintf(PING, 0x100, "Ping: %i", (mc->FPS));
		StringToWideCharacter(wPING, PING, _sys_strlen(PING));
	}
}

void GetPing()
{
	if (UI::Settings::ShowPING)
	{
		GetPingz();
		DrawRectangle(15, 30, 47, 13, UI::Color::BLACK);
		DrawTextWithShadow(wPING, 20, 33, color(UI::MCTextColors::White));
	}
}

void GetChunks()
{
	if (UI::Settings::ShowChunks)
	{
		char option[0x100];
		wchar_t woption[0x100];
		_sys_memset(option, 0, 0x100);
		_sys_memset(woption, 0, 0x200);
		_sys_snprintf(option, 0x100, "Chunk: (%i, %i, %i)", (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordX + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordY + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordZ + 1);
		StringToWideCharacter(woption, option, strlen(option));
		DrawRectangle(15, 41, 90, 13, UI::Color::BLACK);
		DrawTextWithShadow(woption, 20, 44, color(UI::MCTextColors::White));
	}
}

void GetResolution()
{
	if (UI::Settings::ShowResolution)
	{
		char option[0x100];
		wchar_t woption[0x100];
		_sys_memset(option, 0, 0x100);
		_sys_memset(woption, 0, 0x200);
		_sys_snprintf(option, 0x100, "Resolution: %ix%i", mc->theMinecraft->displayWidth, mc->theMinecraft->displayHeight);
		StringToWideCharacter(woption, option, strlen(option));
		DrawRectangle(15, 51, 105, 13, UI::Color::BLACK);
		DrawTextWithShadow(woption, 20, 54, color(UI::MCTextColors::White));
	}
}

void GetTeleportXYZ()
{
	char option4[0x100];
	wchar_t woption4[0x100];
	_sys_memset(option4, 0, 0x100);
	_sys_memset(woption4, 0, 0x200);
	_sys_snprintf(option4, 0x100, "TP X: %i", (TeleportX));
	StringToWideCharacter(woption4, option4, _sys_strlen(option4));
	DrawTextWithShadow(woption4, 130, 55, color(UI::MCTextColors::White));

	char option8[0x100];
	wchar_t woption8[0x100];
	_sys_memset(option8, 0, 0x100);
	_sys_memset(woption8, 0, 0x200);
	_sys_snprintf(option8, 0x100, "TP Y: %i", (TeleportY));
	StringToWideCharacter(woption8, option8, _sys_strlen(option8));
	DrawTextWithShadow(woption8, 130, 65, color(UI::MCTextColors::White));

	char option16[0x100];
	wchar_t woption16[0x100];
	_sys_memset(option16, 0, 0x100);
	_sys_memset(woption16, 0, 0x200);
	_sys_snprintf(option16, 0x100, "TP Z: %i", (TeleportZ));
	StringToWideCharacter(woption16, option16, _sys_strlen(option16));
	DrawTextWithShadow(woption8, 130, 75, color(UI::MCTextColors::White));
}

void GetInfosLastPlayer()
{
	if (PlayersInfos)
	{

		if (*(int*)0x30F46AD8 == 0xFFFFFFFF)
		{
			PLR_NAME = "N/A    ";
			PLR_REGION = "N/A    ";
		}
		else
		{
			if (*(int*)0x30F46AC4 == 0xFFFFFFFF)
			{
				PLR_NAME = "N/A    ";
				PLR_REGION = "N/A    ";
			}
			else
			{
				PLR_NAME = PS3Lib::ReadString(0x30F46AC4);
				PLR_REGION = PS3Lib::ReadString(0x30F46AD8);
			}
		}

		strcpy((char*)0x3000AF0A, PLR_NAME); //unique ID
		if (PLR_NAME == "cry_naegga")
		{
			DrawText(L"Misaki is here !", 37, 312, color(UI::Color::WHITE));
		}

		DrawRectangle(15, 70, 90, 24, UI::Color::BLACK);
		DrawTextC(PLR_NAME, 20, 74, color(UI::Color::WHITE));
		DrawTextC(PLR_REGION, 20, 84, color(UI::Color::WHITE));
	}
}

void Custom_Crosshair(int value)
{
	if (custom_crosshair)
	{
		if (value == 0)
		{
			drawLine(Vector2(322, 181), Vector2(312, 194), GetThemeColor());
			drawLine(Vector2(322, 181), Vector2(333, 194), GetThemeColor());
			*(int*)0x0155847C = 0x01000000;
		}
		else if (value == 1)
		{
			DrawRectangle(316, 176, 8, 8, GetThemeColor());
		}
		else if (value == 2)
		{
			DrawRectangle(317, 177, 6, 1, UI::Color::WHITE);
			DrawRectangle(317, 182, 6, 1, UI::Color::WHITE);
			DrawRectangle(317, 177, 1, 6, UI::Color::WHITE);
			DrawRectangle(322, 177, 1, 6, UI::Color::WHITE);
		}
	}
}

int ColorHair[3] = { 250, 140, 17 };
int ColorSkins[3] = { 248, 197, 170 };
int ColorEyesWhite[3] = { 255, 255, 255 };
int ColorEyes[3] = { 11, 139, 16 };
int ColorMouth[3] = { 252, 172, 197 };
int pos[2] = { 150, 12 };
int size[2] = { 2, 2 };
int space[7] = { 5, 10, 15, 20, 25, 30, 35 };

float AlexBlinkEyes = 0;
float AlexBlinkEyesTimer = 0;

void DrawAlexHead()
{
	if (size[1] == 2)
	{
		space[0] = 2; space[1] = 4; space[2] = 6; space[3] = 8; space[4] = 10; space[5] = 12; space[6] = 14;
	}
	else if (size[1] == 3)
	{
		space[0] = 3; space[1] = 6; space[2] = 9; space[3] = 12; space[4] = 15; space[5] = 18; space[6] = 21;
	}
	else if (size[1] == 5)
	{
		space[0] = 5; space[1] = 10; space[2] = 15; space[3] = 20; space[4] = 25; space[5] = 30; space[6] = 35;
	}
	else if (size[1] == 10)
	{
		space[0] = 10; space[1] = 20; space[2] = 30; space[3] = 40; space[4] = 50; space[5] = 60; space[6] = 70;
	}

	DrawRectangle(pos[0], pos[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[0], pos[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[1], pos[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[2], pos[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[3], pos[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[4], pos[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[5], pos[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[6], pos[1], size[0], size[1], ColorHair);

	DrawRectangle(pos[0], pos[1] + space[0], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[0], pos[1] + space[0], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[1], pos[1] + space[0], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[2], pos[1] + space[0], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[3], pos[1] + space[0], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[4], pos[1] + space[0], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[5], pos[1] + space[0], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[6], pos[1] + space[0], size[0], size[1], ColorHair);

	DrawRectangle(pos[0], pos[1] + space[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[0], pos[1] + space[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[1], pos[1] + space[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[2], pos[1] + space[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[3], pos[1] + space[1], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[4], pos[1] + space[1], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[5], pos[1] + space[1], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[6], pos[1] + space[1], size[0], size[1], ColorHair);

	DrawRectangle(pos[0], pos[1] + space[2], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[0], pos[1] + space[2], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[1], pos[1] + space[2], size[0], size[1], ColorHair);
	DrawRectangle(pos[0] + space[2], pos[1] + space[2], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[3], pos[1] + space[2], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[4], pos[1] + space[2], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[5], pos[1] + space[2], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[6], pos[1] + space[2], size[0], size[1], ColorHair);

	if (AlexBlinkEyes > -1)
		AlexBlinkEyes += 5;

	if (AlexBlinkEyes > 1500)
	{
		DrawRectangle(pos[0], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[0], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[1], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[2], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[3], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[4], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[5], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[6], pos[1] + space[3], size[0], size[1], ColorSkins);

		if (AlexBlinkEyesTimer > -1)
			AlexBlinkEyesTimer += 1;

		if (AlexBlinkEyesTimer > 30)
		{
			AlexBlinkEyesTimer = 0;
			AlexBlinkEyes = 0;
		}
	}
	else
	{
		DrawRectangle(pos[0], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[0], pos[1] + space[3], size[0], size[1], ColorEyesWhite);
		DrawRectangle(pos[0] + space[1], pos[1] + space[3], size[0], size[1], ColorEyes);
		DrawRectangle(pos[0] + space[2], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[3], pos[1] + space[3], size[0], size[1], ColorSkins);
		DrawRectangle(pos[0] + space[4], pos[1] + space[3], size[0], size[1], ColorEyes);
		DrawRectangle(pos[0] + space[5], pos[1] + space[3], size[0], size[1], ColorEyesWhite);
		DrawRectangle(pos[0] + space[6], pos[1] + space[3], size[0], size[1], ColorSkins);
	}


	DrawRectangle(pos[0], pos[1] + space[4], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[0], pos[1] + space[4], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[1], pos[1] + space[4], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[2], pos[1] + space[4], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[3], pos[1] + space[4], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[4], pos[1] + space[4], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[5], pos[1] + space[4], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[6], pos[1] + space[4], size[0], size[1], ColorSkins);

	DrawRectangle(pos[0], pos[1] + space[5], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[0], pos[1] + space[5], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[1], pos[1] + space[5], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[2], pos[1] + space[5], size[0], size[1], ColorMouth);
	DrawRectangle(pos[0] + space[3], pos[1] + space[5], size[0], size[1], ColorMouth);
	DrawRectangle(pos[0] + space[4], pos[1] + space[5], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[5], pos[1] + space[5], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[6], pos[1] + space[5], size[0], size[1], ColorSkins);

	DrawRectangle(pos[0], pos[1] + space[6], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[0], pos[1] + space[6], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[1], pos[1] + space[6], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[2], pos[1] + space[6], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[3], pos[1] + space[6], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[4], pos[1] + space[6], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[5], pos[1] + space[6], size[0], size[1], ColorSkins);
	DrawRectangle(pos[0] + space[6], pos[1] + space[6], size[0], size[1], ColorSkins);
}
