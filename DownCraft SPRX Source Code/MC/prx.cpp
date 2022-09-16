
#include "Includes.h"

SYS_MODULE_INFO( DownCraftSPRX, 0, 1, 1);
SYS_MODULE_START( _DownCraftSPRX_prx_entry );
SYS_MODULE_STOP(_DownCraftSPRX_prx_stop);

void gameRender_Hook(uint32_t r3, uint32_t r4) 
{
	INITIALIZE_START();
	//WHITELIST(); //PSN WHITELIST
	gameRender_Stub(r3, r4);
	mc = (TheMinecraft*)(mcOfs);

	if (WhitelistCheck)
	{
		Inject();
	}
	else
	{
		UnInject("Oops look like your not whitelisted :(");
	}
}

extern "C" int _DownCraftSPRX_prx_entry(void)
{	
	const char* message;
	if (devmenu)
		message = "DownCraft SPRX Developer Version :)\nOpen menu press  + \nMenu made by Misakiii !";
	else
		message = "DownCraft SPRX Public Version\nOpen menu press  + \nMenu made by Misakiii !";

	Dialog::msgdialog_mode = Dialog::MODE_RUNNING;
	Dialog::ProgressBar(message, "Loading...", 20);
	Dialog::End();

	HookFunctionStart(gameRenderHook, *(uint32_t*)(gameRender_Hook), *(uint32_t*)(gameRender_Stub));
	HookFunctionStart(0x01084270, *(uint32_t*)(sceNpBasicSetPresenceDetails_Hook), *(uint32_t*)(asm_SetPresenceDetails_Hook));
	INITIALIZE_SPRX = true;
	return SYS_PRX_RESIDENT;
}
extern "C" int _DownCraftSPRX_prx_stop(void)
{
	*(uint32_t*)(0x0140A3B8) = (uint32_t)(0x014A1C10);

	UnHookFunctionStart(gameRenderHook, *(uint32_t*)(gameRender_Stub));
	UnHookFunctionStart(0x01084270, *(uint32_t*)(asm_SetPresenceDetails_Hook));
	return SYS_PRX_RESIDENT;
}