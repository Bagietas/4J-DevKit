#pragma once

void RenderSubMenu()
{
	if (Opened)
	{
		switch (CurrentMenu)
		{
		case(MainMenu):
			MaxSubOptions = 4;
			Menu->AddHuds(MaxSubOptions);
			Menu->AddTitle(titleSPRX);
			Menu->Description(L"Main Menu");
			Menu->AddSubOption(L"Host Options");
			Menu->AddSubOption(L"Non Host Options");
			Menu->AddSubOption(L"Players Options");
			Menu->AddSubOption(L"Weather Options");
			Menu->AddSubOption(L"okkkkkkk");
			switch (getOption()) {
			case(0): openSubmenu(HostMenu1); break;
			}
			break;

		case(HostMenu1):
			MaxSubOptions = 23;
			Menu->AddHuds(MaxSubOptions);
			Menu->AddTitle(titleSPRX);
			Menu->Description(L"Host Menu");
			Menu->AddBoolOption(L"God Mode", GodMode);
			Menu->AddBoolOption(L"Demi God Mode", DemiGodMode);
			Menu->AddIntOption(L"Instant Damage", 2, -500, 500, InstantDamage);
			Menu->AddBoolOption(L"Critical Hit", CriticalHit);
			Menu->AddBoolOption(L"Kill In Creative", KillInCreative);
			Menu->AddBoolOption(L"No Damage Hit", NoDamageHit);
			Menu->AddBoolOption(L"Knockback", Knockback);
			Menu->AddBoolOption(L"Anti Knockback", AntiKnockback);
			Menu->AddBoolOption(L"Reverse KB", ReverseKB);
			Menu->AddBoolOption(L"Drop Far Items", DropFarItems);
			Menu->AddBoolOption(L"Max XP Level", MaxXPLevel);
			Menu->AddBoolOption(L"Water Jump", WaterJump);
			Menu->AddBoolOption(L"Drift Boat", DriftBoat);
			Menu->AddBoolOption(L"Stop Arrows", StopArrows);
			Menu->AddBoolOption(L"Remove Arrows", RemoveArrows);
			Menu->AddBoolOption(L"Potion Flying", PotionsFlying);
			Menu->AddBoolOption(L"Potion Go Down", PotionsNoGravity);
			Menu->AddBoolOption(L"Inf Pickup Items", InfinitePickupItems);
			Menu->AddBoolOption(L"Max Pickup Items", MaxPickupItems);
			Menu->AddBoolOption(L"Infinite Blocks", InfiniteBlocks);
			Menu->AddBoolOption(L"Burn In Water", BurnInWater);
			Menu->AddBoolOption(L"Remove Fire", RemoveFire);
			Menu->AddSubOption(L"Next Page");
			switch (getOption()) {
			case(0): GodMode =! GodMode; Offsets->GOD_MODE(GodMode); break;
			case(1): DemiGodMode =! DemiGodMode; Offsets->DEMI_GOD_MODE(DemiGodMode); break;
			case(2): Offsets->INSTANT_DAMAGE(InstantDamage); break;
			case(3): CriticalHit =! CriticalHit; Offsets->CRITICAL_HIT(CriticalHit); break;
			case(4): KillInCreative =! KillInCreative; Offsets->KILL_IN_CREATIVE(KillInCreative); break;
			case(5): NoDamageHit =! NoDamageHit; Offsets->NO_DAMAGE_HIT(NoDamageHit); break;
			case(6): Knockback =! Knockback; Offsets->KNOCKBACK(Knockback); break;
			case(7): AntiKnockback =! AntiKnockback; Offsets->ANTI_KNOCKBACK(AntiKnockback); break;
			case(8): ReverseKB =! ReverseKB; Offsets->REVERSE_KNOCKBACK(ReverseKB); break;
			case(9): DropFarItems =! DropFarItems; Offsets->DROP_ITEMS_FAR(DropFarItems); break;
			case(10): MaxXPLevel =! MaxXPLevel; Offsets->MAX_LEVEL_XP(MaxXPLevel); break;
			case(11): WaterJump =! WaterJump; Offsets->WATER_JUMP(WaterJump); break;
			case(12): DriftBoat =! DriftBoat; Offsets->DRIFT_BOAT(DriftBoat); break;
			case(13): StopArrows =! StopArrows; Offsets->STOP_ARROWS(StopArrows); break;
			case(14): RemoveArrows =! RemoveArrows; Offsets->REMOVE_ARROWS(RemoveArrows); break;
			case(15): PotionsFlying =! PotionsFlying; Offsets->POTIONS_FLYING(PotionsFlying); break;
			case(16): PotionsNoGravity =! PotionsNoGravity; Offsets->POTIONS_NO_GRAVITY(PotionsNoGravity); break;
			case(17): InfinitePickupItems =! InfinitePickupItems; Offsets->INFINITE_PICKUP_ITEMS(InfinitePickupItems); break;
			case(18): MaxPickupItems =! MaxPickupItems; Offsets->MAX_PICKUP_ITEMS(MaxPickupItems); break;
			case(19): InfiniteBlocks =! InfiniteBlocks; Offsets->INFINITE_BLOCKS(InfiniteBlocks); break;
			case(20): BurnInWater =! BurnInWater; Offsets->BURN_IN_WATER(BurnInWater); break;
			case(21): RemoveFire =! RemoveFire; Offsets->REMOVE_FIRE(RemoveFire); break;
			case(22): openSubmenu(HostMenu2); break;
			}
			break;

		case(HostMenu2):
			MaxSubOptions = 4;
			Menu->AddHuds(MaxSubOptions);
			Menu->AddTitle(titleSPRX);
			Menu->Description(L"Main Menu");
			Menu->AddBoolOption(L"Creative Slot", CreativeSlot);
			Menu->AddBoolOption(L"Survival Slot", SurvivalSlot);
			Menu->AddBoolOption(L"Survival Slot", SurvivalSlot);
			switch (getOption()) {
			case(0): CreativeSlot =! CreativeSlot; Offsets->CREATIVE_SLOT(CreativeSlot); break;
			case(1): SurvivalSlot =! SurvivalSlot; Offsets->SURVIVAL_SLOT(SurvivalSlot); break;
			}
			break;
		}
	}
}