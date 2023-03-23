
/*
___  ____                            __ _     ___________________   __
|  \/  (_)                          / _| |   /  ___| ___ \ ___ \ \ / /
| .  . |_ _ __   ___  ___ _ __ __ _| |_| |_  \ `--.| |_/ / |_/ /\ V /
| |\/| | | '_ \ / _ \/ __| '__/ _` |  _| __|  `--. \  __/|    / /   \
| |  | | | | | |  __/ (__| | | (_| | | | |_  /\__/ / |   | |\ \/ /^\ \
\_|  |_/_|_| |_|\___|\___|_|  \__,_|_|  \__| \____/\_|   \_| \_\/   \/

                          Made by Misaki
*/

#include "Includes.h"

SYS_MODULE_INFO( Minecraft, 0, 1, 1);
SYS_MODULE_START(Minecraft_Main);
SYS_MODULE_STOP(Minecraft_Stop);

void Loop()
{
	RenderSubMenu();
	Controller();
}

void RenderScreen_Stub(uint32_t r3, uint32_t r4)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}

void RenderScreen_Hook(uint32_t r3, uint32_t r4)
{
	RenderScreen_Stub(r3, r4);
	mc = (TheMinecraft*)(0x014CF2E4);
	DrawText(L"Working", -80, -80, color(MC_Color::White));
	MaxOption = 0;

	Loop();
}

extern "C" int Minecraft_Main(void)
{
	Dialog::msgdialog_mode = Dialog::MODE_RUNNING;
	Dialog::ProgressBar("DownCraft SPRX loaded !", "Loading...", 20);
	Dialog::End();

	HookFunctionStart(0xA89068, *(uint32_t*)(RenderScreen_Hook), *(uint32_t*)(RenderScreen_Stub));
	return SYS_PRX_RESIDENT;
}
extern "C" int Minecraft_Stop(void)
{
	UnHookFunctionStart(0xAA3360, *(uint32_t*)(RenderScreen_Hook));
	return SYS_PRX_RESIDENT;
}