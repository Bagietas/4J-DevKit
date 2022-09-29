#pragma once

//INCLUDES PS3
#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <sys/timer.h>
#include <cell/pad.h>

//INCLUDES MINECRAFT
#include "Minecraft/gamemode/GameMode.h"
#include "Minecraft/client/Minecraft.h"
#include "Minecraft/entity/player/ServerPlayer.h"
#include "Minecraft/world/entity/DamageSource.h"
#include "Minecraft/util/Direction.h"
#include "Minecraft/world/level/block/BlockPos.h"
#include "Minecraft/client/gui/GuiComponent.h"

//INCLUDES MEMORY / UTIL
#include "Util/NewDeleteOverride.hpp"
#include "Util/TimeHelpers.hpp"
#include "Util/SystemCalls.hpp"
#include "Memory/Detour.hpp"


MultiPlayerLevel* g_Level;
MultiplayerLocalPlayer* g_Localplayer;
Minecraft* g_Minecraft;
MultiPlayerGameMode* g_Gamemode;
GuiComponent* g_GuiComponent;

//INCLUDES SOURCE
#include "Buttons.h"
#include "Variables.h"
#include "PS3.h"
#include "Struct.h"
TheMinecraft* mc;
#include "GamesFunctions.h"
#include "Functions.h"
#include "Menu.h"
#include "Hooking.h"

