
#include "Includes.h"

SYS_MODULE_INFO( DownCraftSPRX, 0, 1, 1);
SYS_MODULE_START( _DownCraftSPRX_prx_entry );
SYS_MODULE_STOP(_DownCraftSPRX_prx_stop);

void gameRender_Hook(uint32_t r3, uint32_t r4) 
{
	INITIALIZE_START();
	misakiii();
	gameRender_Stub(r3, r4);
	mc = (TheMinecraft*)(mcOfs);

	if (xKzLAOD015Ax11)
	{
		Inject();
	}
}

void callThreadFromEBOOT(uint64_t) 
{
	__asm("lis 3, 0x14C;");//oris r2, r2, 0x14C
	__asm("lwz 3, 0(3);");
	__asm("cmpwi 3, 0x3618;");//ori r2, r2, 0x361B
	__asm("beq end;");
	__asm("end:;");
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

	//HookFunctionStart(0xB34A6C, *(uint32_t*)(MultiPlayerGameMode_destroyBlockHook), *(uint32_t*)(asm_destroyBlockHook));
	//sys_ppu_thread_t ThreadModuleID;
	//sys_ppu_thread_create(&ThreadModuleID, callThreadFromEBOOT, 0, 0x4AA, 0x7000, 0, "Test");

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