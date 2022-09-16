#pragma once

#pragma region "Loading bar SPRX"

int loadtimer = 0;
int load = 0;
void LoadSPRX()
{
	int colorbg[3] = { 56, 56, 56 };

	DrawRectangle(388, 134, 193, 42, colorbg);
	DrawRectangle(388, 148, 193, 13, UI::Color::WHITE);
	DrawRectangle(388, 148, load, 13, UI::Color::BLUE);
	DrawTextC("DownCraft SPRX", 391, 137, color(UI::Color::WHITE));
	DrawTextC("Loading SPRX", 518, 165, color(UI::Color::WHITE));
	snprintf("%i       ", load, 563, 137);

	loadtimer += 1;

	if (loadtimer > 5)
	{
		loadtimer = 0;
		load += 1;
	}

	if (load > 194)
	{
		InitializeSPRX = false;
		UsableMenu = true;
		*(int*)0x0155847C = 0x01000000; //Usable HUD
		logs::SendMessageDebug(L"Welcome to DownCraft SPRX", UI::MCTextColors::Red);
		logs::SendMessageDebug(L"Version V4.2", UI::MCTextColors::Aqua);
		logs::SendMessageDebug(L"Press L1 + DPAD UP for open the menu", UI::MCTextColors::LightPurple);
	}
}

#pragma endregion

void Inject()
{
	if (FirstInfoMessage)
	{
		if (InWorld())
		{
			if (InitializeSPRX)
			{
				*(int*)0x30927421 = 0x00000000; //TEXT INVENTORY
				*(int*)0x3092CD81 = 0x00000000; //TEXT CREATIVE
				*(int*)0x0155847C = 0x00000000; //Unusable HUD
				LoadSPRX();
			}
		}
	}

	if (noclipvars)
	{
		LoopFunc();
		RenderMenu();
		Scroll();
	}
}

void UnInject(char* message)
{
	Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
	Dialog::Show(message);
	UnHookFunctionStart(gameRenderHook, *(uint32_t*)(gameRender_Stub));
	UnHookFunctionStart(0x01084270, *(uint32_t*)(asm_SetPresenceDetails_Hook));

	/*
	//FREEZE GAME KICK TO XMB
	*(int*)0x00785DBC = 0x40800028;
	*(int*)0x00AD8320 = 0x408000CC;
	*(int*)0x014CE214 = 0x01000001;
	*/
}

void INITIALIZE_START()
{
	if (INITIALIZE_SPRX)
	{
		PSN_NAME = PS3Lib::ReadString(0x3000ACC4);
		REGION = PS3Lib::ReadString(0x3000AD48);

		char HEX[] = { 0x42, 0x4C, 0x45, 0x53, 0x30, 0x31, 0x39, 0x37, 0x36 }; //detected if the custom EBOOT is used
		char* ADDRESS = (char*)0x01437D24; //address for | /dev_hdd0/game/BLES01976/USRDIR/MC.sprx

		for (int i = 0; i < 9; ++i)
		{
			if (ADDRESS[i] == HEX[i])
			{
	
			}
			else
			{
				UnInject("Oops look like your not using the right EBOOT.BIN :(");
			}
		}

		*(int*)0x31E7782C = 0x49600000; //pos images
		*(int*)0x31E77830 = 0xC98D0000; //pos images

		SaveTitleSlide = TitleTextX;
		SaveTextSlide = textX;
		SavebgSlide = bgX;
		SaveAddOptSlide = AddOptX;
		SaveCheckBoxSlide = CheckBoxX;
		SaveScrollSlide = ScrollX;

		//SAVE BLOCKS
		SAVE_BLOCK_AIR = Blocks::AIR;
		INITIALIZE_SPRX = false;
	}
}

void WHITELIST()
{
	char hex[] = { 0x53, 0x61, 0x69, 0x6B, 0x6F, 0x4D, 0x69, 0x73, 0x61, 0x6B, 0x69 };

	char* addr = (char*)0x3000ACC4;
	WhitelistCheck = true;
	for (int i = 0; i < 11; ++i)
	{
		if (addr[i] != hex[i])
		{
			WhitelistCheck = false;
		}
	}
}

void WHITELISTV2()
{
	if (!strcmp(0x00000, "Name")) {
		WhitelistCheck = true;
	}
}