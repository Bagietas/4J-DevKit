#pragma once

void ModuleLoop()
{
	Modules::AntiVoid();
	Modules::BunnyJump();
	Modules::SkyboxRGB();
	Modules::Scaffold();
	Modules::NoFall();
}

void ChangeValueLoop()
{
	Offsets::BIG_MODEL(BigModel);
	Offsets::CHANGE_FOV(ValueFOV);
	Offsets::INSTANT_DAMAGE(InstantDamage);
	Offsets::SUPER_SPEED(SuperSpeed);

	Offsets::ADD_CUSTOM_BANNER();
	Offsets::ANIMATED_BANNER_GIF();
	Offsets::ALL_PLAYERS_ZOOM_FOV();
}

void LoopFunc()
{
	//GetServerTime();

	Welcome_Message();
	GetPosition();
	GetPing();
	GetChunks();
	GetResolution();
	GetInfosLastPlayer();
	get_temp();
	TitleMenu();
	DEBUG_FUNCTIONS_MESSAGES();
	//VersionText();
	InventoryCreativeTumble();

	ChangeValueLoop();
	ModuleLoop();

	SlideOpenMenuLoop();
	SlideCloseMenuLoop();
	DrawTextC("     ", 0, 0, color(255, 255, 255));//dont move
	MaxOption = 0;
	RGB1();
	RGB2();
	Custom_Crosshair(crosshair_value);
	GetNotify();
	logs::draw_logs();

	DRAW_HEAD_PIXEL_LOGO();

	if (DebugText)
		DrawTextC(initialDebugTxt, DebugTextX, DebugTextY, color(UI::Color::WHITE));

	if (DebugHud)
		DrawRectangle(DebugHudX, DebugHudY, DebugHudW, DebugHudH, UI::Color::BLACK);

	if (DebugHudAlpha)
	{
		Color BLACK_OPACITY{ 15, 15, 15, 200 };
		DrawRectangleAlpha(DebugHudAlphaX, DebugHudAlphaY, DebugHudAlphaW, DebugHudAlphaH, BLACK_OPACITY);
	}

	if (DebugDrawLine)
		drawLine(DebugDrawLineX, DebugDrawLineY, GetThemeColor());
}