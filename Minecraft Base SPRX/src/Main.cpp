#include "Includes.h"

SYS_MODULE_INFO(Minecraft, 0, 1, 1);
SYS_MODULE_START(Minecraft_Main);
SYS_MODULE_STOP(Minecraft_Stop);

extern "C" int Minecraft_Main(void)
{
	InstallHooks();
	return SYS_PRX_RESIDENT;
}
extern "C" int Minecraft_Stop(void)
{
	UninstallHooks();
	return SYS_PRX_RESIDENT;
}