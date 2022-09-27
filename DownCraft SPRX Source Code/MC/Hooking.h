#pragma once

#include "Minecraft/entity/Entity.h"
#include "Minecraft/entity/player/ServerPlayer.h"
#include "Minecraft/world/entity/DamageSource.h"

#pragma region "ASM"

void gameRender_Stub(uint32_t r3, uint32_t r4)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}

int asm_SetPresenceDetails_Hook(SceNpBasicPresenceDetails2* pres, uint32_t options)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}
int sceNpBasicSetPresenceDetails_Hook(SceNpBasicPresenceDetails2* pres, uint32_t options)
{
	strncpy(pres->status, "Using \uF477 DownCraft SPRX V4 \uF477", 30);

	return asm_SetPresenceDetails_Hook(pres, options);
}

int asm_destroyBlockHook(MultiPlayerGameMode* gamemode, BlockPos* blockPos) // ou (...) si tu veux opti apres  sa depend des fois sa marche des fois non!
{
    __nop(); __nop(); __nop(); __nop(); __nop();
	//__asm("li %r3, 0x332;");
}

void asm_LivingEntity_HurtHook(Entity* entity, EntityDamageSource* entityDamageSource, float damage)
{
    __nop(); __nop(); __nop(); __nop(); __nop();
    //__asm("li %r3, 0x332;");
}

void asm_Player_HurtHook(ServerPlayer* player, DamageSource* damageSource, float damage)
{
    __nop(); __nop(); __nop(); __nop(); __nop();
}

uint32_t asm_LivingEntity_onChangedBlockHook(Entity* entity, BlockPos* pos)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}

uint32_t asm_MultiPlayerGameMode_initPlayerHook(MultiPlayerGameMode* gamemode, ServerPlayer* player)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}

#pragma endregion

int MultiPlayerGameMode_destroyBlockHook(MultiPlayerGameMode* gamemode, BlockPos* blockPos)
{
	if (Nuker)
	{
		if (sizeNuker > 0)
		{
			for (int x = -sizeNuker; x < sizeNuker; x++)
			{
				for (int y = -sizeNuker; y < sizeNuker; y++)
				{
					for (int z = -sizeNuker; z < sizeNuker; z++)
					{
						blockPos->x = (int)mc->theMinecraft->cMultiplayerLocalPlayer->posX + x;
						blockPos->y = (int)mc->theMinecraft->cMultiplayerLocalPlayer->posY + y;
						blockPos->z = (int)mc->theMinecraft->cMultiplayerLocalPlayer->posZ + z;

						asm_destroyBlockHook(gamemode, blockPos);
					}
				}
			}
		}
	}
}

#include <string>
#include <vector>
#include "Minecraft/util/AABB.h"
#include "Minecraft/util/Vec2.h"
#include "Minecraft/util/Vec3.h"
void LivingEntity_HurtHook(Entity* entity, EntityDamageSource* entityDamageSource, float damage)
{
	debug_entity_id = entity->entityId;

	if (entity->isAlive())
		debug_entity_alive = true;
	else
		debug_entity_alive = false;

	double posX = entity->posX;
	double posY = entity->posY;
	double posZ = entity->posZ;

	double ViewAngleX = entity->m_viewAnglesX;
	double ViewAngleY = entity->m_viewAnglesY;

	FUNCTIONS::__printf("EntityID: %i \n", entity->entityId);
	FUNCTIONS::__printf("Entity Pos: %f, %f, %f \n", posX, posY, posZ);
	FUNCTIONS::__printf("View Angles: %f, %f \n", ViewAngleX, ViewAngleY);

	//AIMBOT TEST
	//mc->theMinecraft->cMultiplayerLocalPlayer->setLocationAndAngles(ViewAngleX, ViewAngleY)

	mc->theMinecraft->cMultiplayerLocalPlayer->SetPosition(posX + 0.5, posY + 1 + 0.5, posZ + 0.5);

    damage = 1.f;
    asm_LivingEntity_HurtHook(entity, entityDamageSource, damage);
}

double TargetposX;
double TargetposY;
double TargetposZ;
void Player_actuallyHurtHook(ServerPlayer* player, DamageSource* damageSource, float damage)
{
	debug_entity_id = player->entityId;
	//char PSN = player->playerName;

	if (player->isAlive())
		debug_entity_alive = true;
	else
		debug_entity_alive = false;

	//TP AURA BETA
	if (TPAura)
	{
		TargetposX = player->posX;
		TargetposY = player->posY;
		TargetposZ = player->posZ;

		if (frameTime(1, 1, false))
		{
			mc->theMinecraft->cMultiplayerLocalPlayer->SetPosition(TargetposX, TargetposY, TargetposZ); //TARGET POS
			*(int*)0x00AEBED4 = 0xBE800000; //UNFAIR ATTACk
			*(int*)0x00233290 = 0xFF000000; //KILL AURA
			*(int*)0x00AEC34C = 0x40820024; //AUTO HIT
			sleep(250);
			*(int*)0x00AEBED4 = 0x3E800000;
			*(int*)0x00233290 = 0x00000000;
			*(int*)0x00AEC34C = 0x41820024;
		}
	}

	//FUNCTIONS::__printf("PSN: %d \n", PSN);

    damage = 1.f;
    asm_Player_HurtHook(player, damageSource, damage);
}

uint32_t LivingEntity_onChangedBlockHook(Entity* entity, BlockPos* pos)
{
	FUNCTIONS::FrostWalkerEnchantment_onEntityMoved(&entity->m_this, entity->m_multiPlayerLevel2, pos, 255);
	return asm_LivingEntity_onChangedBlockHook(entity, pos);
}

uint32_t MultiPlayerGameMode_initPlayerHook(MultiPlayerGameMode* gamemode, ServerPlayer* player)
{
	debug_entity_id = player->entityId;
	return asm_MultiPlayerGameMode_initPlayerHook(gamemode, player);
}


void InstallHooks()
{
	HookFunctionStart(0x01084270, *(uint32_t*)(sceNpBasicSetPresenceDetails_Hook), *(uint32_t*)(asm_SetPresenceDetails_Hook));
	HookFunctionStart(0x3A7F48, *(uint32_t*)(LivingEntity_HurtHook), *(uint32_t*)(asm_LivingEntity_HurtHook));
	HookFunctionStart(0x4A94B8, *(uint32_t*)(Player_actuallyHurtHook), *(uint32_t*)(asm_Player_HurtHook));
	HookFunctionStart(0xB34A6C, *(uint32_t*)(MultiPlayerGameMode_destroyBlockHook), *(uint32_t*)(asm_destroyBlockHook));
	//HookFunctionStart(0xAE1A04, *(uint32_t*)(LivingEntity_onChangedBlockHook), *(uint32_t*)(asm_LivingEntity_onChangedBlockHook));
	HookFunctionStart(0xAE1A04, *(uint32_t*)(MultiPlayerGameMode_initPlayerHook), *(uint32_t*)(asm_MultiPlayerGameMode_initPlayerHook));
}

void UninstallHooks()
{
	UnHookFunctionStart(gameRenderHook, *(uint32_t*)(gameRender_Stub));
	UnHookFunctionStart(0x01084270, *(uint32_t*)(sceNpBasicSetPresenceDetails_Hook));
	UnHookFunctionStart(0x3A7F48, *(uint32_t*)(LivingEntity_HurtHook));
	UnHookFunctionStart(0x4A94B8, *(uint32_t*)(Player_actuallyHurtHook));
	UnHookFunctionStart(0xB34A6C, *(uint32_t*)(MultiPlayerGameMode_destroyBlockHook));
	//UnHookFunctionStart(0xAE1A04, *(uint32_t*)(LivingEntity_onChangedBlockHook));
	UnHookFunctionStart(0xAE1A04, *(uint32_t*)(MultiPlayerGameMode_initPlayerHook));
}