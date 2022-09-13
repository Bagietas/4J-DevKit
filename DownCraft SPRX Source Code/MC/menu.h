
//X = < >
//Y = /\ \/

#pragma region "Back Sub Menu"

 void BackSubMenu()
 {
	 if (MainMenu)
	 {
		 Opened = false;
		 Closed = true;
	 }

	 if (HostPage)
	 {
		 HostPage = false;
		 MainMenu = true;
	 }

	 if (HostPage1)
	 {
		 HostPage1 = false;
		 HostPage = true;
	 }

	 if (HostPage2)
	 {
		 HostPage2 = false;
		 HostPage1 = true;
	 }

	 if (HostPage3)
	 {
		 HostPage3 = false;
		 HostPage2 = true;
	 }

	 if (NonHostPage)
	 {
		 NonHostPage = false;
		 MainMenu = true;
	 }

	 if (NonHostPage1)
	 {
		 NonHostPage1 = false;
		 NonHostPage = true;
	 }

	 if (NonHostPage2)
	 {
		 NonHostPage2 = false;
		 NonHostPage1 = true;
	 }

	 if (NonHostPage3)
	 {
		 NonHostPage3 = false;
		 NonHostPage2 = true;
	 }

	 if (NonHostPage4)
	 {
		 NonHostPage4 = false;
		 NonHostPage3 = true;
	 }

	 if (NonHostPage5)
	 {
		 NonHostPage5 = false;
		 NonHostPage4 = true;
	 }

	 if (PlayersOptions)
	 {
		 PlayersOptions = false;
		 MainMenu = true;
	 }

	 if (WeathesMenu)
	 {
		 WeathesMenu = false;
		 MainMenu = true;
	 }

	 if (VisionMenu)
	 {
		 VisionMenu = false;
		 MainMenu = true;
	 }

	 if (VisionMenu1)
	 {
		 VisionMenu1 = false;
		 VisionMenu = true;
	 }

	 if (VisionMenu2)
	 {
		 VisionMenu2 = false;
		 VisionMenu1 = true;
	 }

	 if (VisionMenu3)
	 {
		 VisionMenu3 = false;
		 VisionMenu2 = true;
	 }

	 if (VisionMenu4)
	 {
		 VisionMenu4 = false;
		 VisionMenu3 = true;
	 }

	 if (VisionMenu5)
	 {
		 VisionMenu5 = false;
		 VisionMenu4 = true;
	 }

	 if (VisionMenu6)
	 {
		 VisionMenu6 = false;
		 VisionMenu5 = true;
	 }

	 if (NameChanger)
	 {
		 NameChanger = false;
		 MainMenu = true;
	 }

	 if (GameEditorMenu)
	 {
		 GameEditorMenu = false;
		 MainMenu = true;
	 }

	 if (EggChangerMenu)
	 {
		 EggChangerMenu = false;
		 GameEditorMenu = true;
	 }

	 if (BlockChangerMenu)
	 {
		 BlockChangerMenu = false;
		 GameEditorMenu = true;
	 }

	 if (BlockChangerMenu1)
	 {
		 BlockChangerMenu1 = false;
		 BlockChangerMenu = true;
	 }

	 if (BlockChangerMenu2)
	 {
		 BlockChangerMenu2 = false;
		 BlockChangerMenu1 = true;
	 }

	 if (MiniGamePage)
	 {
		 MiniGamePage = false;
		 MainMenu = true;
	 }

	 if (TPMiniGame)
	 {
		 TPMiniGame = false;
		 MiniGamePage = true;
	 }

	 if (TeleportMenu)
	 {
		 TeleportMenu = false;
		 MainMenu = true;
	 }

	 if (SettingsMenu)
	 {
		 SettingsMenu = false;
		 MainMenu = true;
	 }

	 if (EditMenu)
	 {
		 EditMenu = false;
		 SettingsMenu = true;
	 }

	 if (ThemeColors)
	 {
		 ThemeColors = false;
		 SettingsMenu = true;
	 }

	 if (DebugMenu)
	 {
		 DebugMenu = false;
		 SettingsMenu = true;
	 }

	 if (CustomImageMenu)
	 {
		 CustomImageMenu = false;
		 SettingsMenu = true;
	 }

	 if (MicsSettings)
	 {
		 MicsSettings = false;
		 SettingsMenu = true;
	 }

	 if (MicsSettings2)
	 {
		 MicsSettings2 = false;
		 MicsSettings = true;
	 }

	 if (CrosshairMenu)
	 {
		 CrosshairMenu = false;
		 SettingsMenu = true;
	 }

	 if (CreditsMenu)
	 {
		 CreditsMenu = false;
		 MainMenu = true;
	 }

	 if (DeveloperMenu)
	 {
		 DeveloperMenu = false;
		 MainMenu = true;
	 }
 }

#pragma endregion

#pragma region "Scroll"

 void Scroll()
 {
	 int wI = 0;
	 keyPressed[wI] = false;

	 if (Buttons::IsMCButtonPressed(Buttons::L1) && Buttons::IsMCButtonPressed(Buttons::R3))
	 {
		 if (scrollWait(firstWaitTime, waitTime, wI))
		 {
			 if (UsableMenu)
			 {
				 if (OpenMenu)
				 {
					 OpenMenu = false;
				 }
				 else
				 {
					 OpenMenu = true;
				 }
				 return;
			 }
		 }
	 }

	 if (!OpenMenu)
	 {
		 if (Buttons::IsMCButtonPressed(Buttons::L1) && Buttons::IsMCButtonPressed(Buttons::UP))
		 {
			 if (UsableMenu)
			 {
				 Opened = true;
				 OpenMenu = true;
				 MainMenu = true;
				 SlideOpenMenu();
			 }
		 }
	 }

	 if (OpenMenu)
	 {
		 if (Buttons::IsMCButtonPressed(Buttons::UP))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
			 {
				 CurrentOpt = CurrentOpt - 1;
				 PlayUISound(Sound::pSoundEventScroll);
				 return;
			 }
		 }

		 if (Buttons::IsMCButtonPressed(Buttons::DOWN))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
			 {
				 CurrentOpt = CurrentOpt + 1;
				 PlayUISound(Sound::pSoundEventScroll);
				 return;
			 }
		 }

		 int fix = MaxOption;
		 fix -= 1;

		 if (CurrentOpt > fix)
		 {
			 CurrentOpt = 0;
		 }

		 if (CurrentOpt < 0)
		 {
			 CurrentOpt = fix;
		 }

		 if (Buttons::IsMCButtonPressed(Buttons::X))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
			 {
				 Options();
				 PlayUISound(Sound::pSoundEventPress);
				 return;
			 }
		 }

		 if (Buttons::IsMCButtonPressed(Buttons::O))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
			 {
				 BackSubMenu();
				 CurrentOpt = 0;
				 CurrentIndex = 0;
				 PlayUISound(Sound::pSoundEventBack);
				 return;
			 }
		 }

		 if (!keyPressed[wI])
		 {
			 lockFirst[wI] = false;
			 freeFirst[wI] = true;
			 resetWait[wI] = true;
			 resetWait2[wI] = true;
		 }
	 }
 }

#pragma endregion

 //MultiplayerLocalPlayer = 0x3373F5D0 / pWorld = 0x337389F0 / GetEntityWorld = 0x337389F0

 void LoopFunc()
 {
	 Welcome_Message();
	 GetPosition();
	 GetPing();
	 GetChunks();
	 GetResolution();
	 GetInfosLastPlayer();
	 get_temp();
	 TitleMenu();
	 DEBUG_FUNCTIONS_MESSAGES();
	 VersionText();
	 InventoryCreativeTumble();

	 Offsets::BIG_MODEL(BigModel);
	 Offsets::CHANGE_FOV(ValueFOV);

	 SlideOpenMenuLoop();
	 SlideCloseMenuLoop();
	 DrawTextC("     ", 0, 0, color(255, 255, 255));//dont move
	 MaxOption = 0;
	 RGB1();
	 RGB2();
	 Modules::AntiVoid();
	 Modules::BunnyJump();
	 Modules::SkyboxRGB();
	 Modules::Scaffold();
	 Modules::NoFall();
	 Offsets::ADD_CUSTOM_BANNER();
	 Offsets::ANIMATED_BANNER_GIF();
	 Offsets::ALL_PLAYERS_ZOOM_FOV();
	 Custom_Crosshair(crosshair_value);
	 GetNotify();
	 logs::draw_logs();
	 PlayerUpwardsJumpMotion(80);
 }

 void RenderMenu()
 {
	 if (!OpenMenu)
	 {
		 *(int*)0x0155847C = 0x00000000;
	 }
	 else
	 {
		 AddInstruction();
		 *(int*)0x0155847C = 0x01000000;

		 if (MainMenu)
		 {
			 SubMenu::MainMenu();
		 }

		 if (HostPage)
		 {
			 SubMenu::HostMenu();
		 }

		 if (HostPage1)
		 {
			 SubMenu::HostMenu1();
		 }

		 if (HostPage2)
		 {
			 SubMenu::HostMenu2();
		 }

		 if (HostPage3)
		 {
			 SubMenu::HostMenu3();
		 }

		 if (NonHostPage)
		 {
			 SubMenu::NonHostMenu();
		 }

		 if (NonHostPage1)
		 {
			 SubMenu::NonHostMenu1();
		 }

		 if (NonHostPage2)
		 {
			 SubMenu::NonHostMenu2();
		 }

		 if (NonHostPage3)
		 {
			 SubMenu::NonHostMenu3();
		 }

		 if (NonHostPage4)
		 {
			 SubMenu::NonHostMenu4();
		 }

		 if (NonHostPage5)
		 {
			 SubMenu::NonHostMenu5();
		 }

		 if (PlayersOptions)
		 {
			 SubMenu::PlayerOptionsMenu();
		 }

		 if (WeathesMenu)
		 {
			 SubMenu::WeatherOptionsMenu();
		 }

		 if (VisionMenu)
		 {
			 SubMenu::VisionsOptionsMenu();
		 }

		 if (VisionMenu1)
		 {
			 SubMenu::VisionsOptionsMenu1();
		 }

		 if (VisionMenu2)
		 {
			 SubMenu::VisionsOptionsMenu2();
			 //ChangeIntOptions(VisionMenu2, 0, 0, 255, BigModel);
		 }

		 if (VisionMenu3)
		 {
			 SubMenu::VisionsOptionsMenu3();
		 }

		 if (VisionMenu4)
		 {
			 SubMenu::VisionsOptionsMenu4();
		 }

		 if (VisionMenu5)
		 {
			 SubMenu::VisionsOptionsMenu5();
		 }

		 if (VisionMenu6)
		 {
			 SubMenu::VisionsOptionsMenu6();
			 ChangeIntOptions(VisionMenu6, 3, 0, 255, ValueFOV);
		 }

		 if (NameChanger)
		 {
			 SubMenu::NameChangerOptionsMenu();
		 }

		 if (GameEditorMenu)
		 {
			 SubMenu::GameEditorOptionsMenu();
		 }

		 if (EggChangerMenu)
		 {
			 SubMenu::EggChangerMenu();
		 }

		 if (BlockChangerMenu)
		 {
			 SubMenu::BlockChangerMenu();
		 }

		 if (BlockChangerMenu1)
		 {
			 SubMenu::BlockChangerMenu1();
		 }

		 if (BlockChangerMenu2)
		 {
			 SubMenu::BlockChangerMenu2();
		 }

		 if (MiniGamePage)
		 {
			 SubMenu::MiniGameOptionsMenu();
		 }

		 if (TPMiniGame)
		 {
			 SubMenu::TPMiniGameOptionsMenu();
		 }

		 if (TeleportMenu)
		 {
			 DrawRectangle(128, 53, 51, 30, UI::Color::BLACK);
			 GetTeleportXYZ();
			 SubMenu::TeleportOptionsMenu();
		 }

		 if (SettingsMenu)
		 {
			 SubMenu::SettingsMenu();
		 }

		 if (EditMenu)
		 {
			 SubMenu::EditMenu();
		 }

		 if (ThemeColors)
		 {
			 SubMenu::ThemeMenu();
		 }

		 if (DebugMenu)
		 {
			 Color BLACK_OPACITY{ 15, 15, 15, 200 };
			 SubMenu::DebugMenu();
			 DrawRectangle(DebugHudX, DebugHudY, DebugHudW, DebugHudH, UI::Color::BLACK);
			 DrawTextC("Debug Text", DebugTextX, DebugTextY, color(UI::Color::WHITE));
			 drawLine(Vector2(DebugLineStartX, DebugLineStartY), Vector2(DebugLineEndX, DebugLineEndY), GetThemeColor());
			 DrawRectangleAlpha(DebugHudX, DebugHudY, DebugHudW, DebugHudH, BLACK_OPACITY);
			 GetDebugXY();
		 }

		 if (CustomImageMenu)
		 {
			 DrawRectangle(127, 108, 218, 32, UI::Color::BLACK);
			 DrawTextC("Before using this read this!", 129, 110, color(UI::Color::WHITE));
			 DrawTextC("You need add a custom image in the MediaPS3.arc", 129, 120, color(UI::Color::WHITE));
			 DrawTextC("Set your PS3 language to English (United State)", 129, 130, color(UI::Color::WHITE));
			 SubMenu::CustomImageMenu();
		 }

		 if (MicsSettings)
		 {
			 SubMenu::MicsMenu();
			 ChangeIntOptions(MicsSettings, 11, -5, 255, menulenght);
			 ChangeIntOptions(MicsSettings, 12, 0, 255, shadowBG);
		 }

		 if (MicsSettings2)
		 {
			 SubMenu::MicsMenu2();
			 ChangeIntOptions(MicsSettings2, 4, 0, 500, RainbowSkyRGBSpeed);
		 }

		 if (CrosshairMenu)
		 {
			 SubMenu::CrosshairMenu();
			 ChangeIntOptions(CrosshairMenu, 1, 0, 5, crosshair_value);
		 }

		 if (CreditsMenu)
		 {
			 SubMenu::CreditsMenu();
		 }

		 if (DeveloperMenu)
		 {
			 if (devmenu)
			 {
				 SubMenu::DeveloperMenu();
			 }
		 }
	 }
 }