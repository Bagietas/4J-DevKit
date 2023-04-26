#pragma once

enum eMenus
{
	MainMenu,
	HostMenu, HostMenu2, HostMenu3,
	NonHostMenu, NonHostMenu2, NonHostMenu3, NonHostMenu4, NonHostMenu5,
	PlayerMenu,
	WeatherMenu,
	VisionsMenu, VisionsMenu2, VisionsMenu3, VisionsMenu4,
	ModulesMenu,
};

//Initial vars
const wchar_t* titleSPRX = L"DownCraft SPRX";
int MenuX = -51, MenuY = 6, menuLenght = 0,
MenuR = 250, MenuG = 61, MenuB = 61;

//Rainbow color
int MenuColourTime = 0, RainbowTime = 0, RainbowRED1, RainbowGREEN1, RainbowBLUE1, RainbowRED2, RainbowGREEN2, RainbowBLUE2, RainbowColor[3];
int Rainbow[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };

//Scroller
bool gotTime[1000], keyPressed[100], freeFirst[100], resetWait[100], resetWait2[100], lockFirst[100];
int getTime[1000], firstWaitTime = 15, waitTime = 5, scrollTick = 0, timeMath[1000], scroll = 0;

//Menu settings
int CurrentMenu, CurrentOpt, MaxOption, MaxSubOptions, optionPress, returnPress, SpaceBetweenText = 11;
bool UsableMenu = true, Opened, Closed, FirstOpen;
char* ThemeColors = "RGB";

#pragma region "vars options"

//Host Page
int InstantDamage;
bool GodMode, DemiGodMode, CriticalHit, KillInCreative, NoDamageHit, Knockback, AntiKnockback, ReverseKB, DropFarItems, MaxXPLevel, WaterJump, DriftBoat, StopArrows, RemoveArrows, PotionsFlying, PotionsNoGravity, InfinitePickupItems, MaxPickupItems, InfiniteBlocks, BurnInWater, RemoveFire;

//Host Page 2
bool CreativeSlot, SurvivalSlot, KillSpawnEntity, StopBlockGravity, NoHitDelay, BypassMaxItems, InfiniteFood, MobIgnoreMe, DisablePortals, KillOnRespawn, FreezeAllEntity, StopEndermanTP, IgnoringPressure, AllEnchant, ItemsOnHead, StopBoat, NoWeb, EntityGodMode, RegenerateHealth, LockGameMode, LockWeather;

//Host Page 3
bool FastBow, DirectionArrows, TotemGiveHealth, TntNuclear, TntBigParticles, TntFlying, TntInstantExplode, DisableSpawnMobs, TntGoInGround, TntSoundOff, BigCreeper, CreeperNuclear, CreeperFire, DisableTotem, GlitchDeadEntity, PlayersInfos;


//Non-Host Page
int SuperSpeed, SuperJump;
bool BunnyHop, PhaseMode, BlockStaticCrack, InfiniteJump, JumpForBuild, JumpInSky, JumpForward, RemoveJump, JumpSpeed, FlyModeX, SwimFly, MovementSwim, SwimGlitch, NoColission, ItemsIds, AntiKick, InBlock, PositionView, FunnySound, FloatUp, ESPChests;

//Non-Host page 2
bool CameraDown, InstantMine, InfiniteCraft, HudMiniGame, AntiTeleport, UFOMode, AntiAFK, SensibilityFast, SensibilityExtrem, WalkAlone, NameOverHead, NameOverHeadV2, StaticMovement, WalkInSky, GravityMoon, Lookforback, CameraDownR3, BetterTime, SeeOutMap, Scaffold, DayAndNight, ESPPlayers;

//Non-host page 3
bool CanFly, NoColissionEntity, AlwaysOnCrouch, GetPlayersID, PlayersOnElytra, WaterSlowDown, JumpInLava, CrouchMovement, PosPlaceBlock, DestroyGame, Levitation, ReturnInXMB, ReturnInXMBV2, AddFakeClone, InvisiblePlayer, AutoLadder, AirToWater, MultiJumpV2, SuicideMode, GameSpeedStatic, Get64Items, AutoJump;

//Non-host page 4
bool AutoChangeView, AutoCrouch, AutoMine, AutoHit, AutoBuild, ESPWaypoint, BatEggsCrash, BatEggsFreeze, GetSpecialItems, ReachAttack, AutoSprint, AutoSprintV2, InstantHit, KillAura, FastBuild, CriticalMode, CriticalModeV2, NoSlowDown, NoHurtCam, PressXForHit, ShowArmor, UnfairAttack;

//Non-host page 5
bool HitBoxBETA, BigVelocity, NoVelocity, AntiVoidtoggle, ESPEntity, ESPTracer, ESPCOD;


//Player menu
bool AllPlayersFastMine, AllPlayersCantMine, AllPlayersCantRun, AllPlayersSpeed, AllPlayersSuperRun, AllPlayersZoomFOV, PlayersCantJoin, AllChangeHand, AllPlayersSuffocate, AllPlayersInFire;


//Weather menu
bool DarkStorm, RainbowStorm, RainToSnow, RainbowWithSnow, FlashSky, LightningBoldV1, LightningBoldV2;


//Visions Menu
bool XrayVision, NightVision, Apocalipse, FunnySound, HorrorView, AnimationRun, SkyRainbow, WTFView, SizeHUD, BrokenTexture, ShockWave, WallHack, WallHackV2, WallhackV3, PlasticTexture, GhostPlastic, BlueFog, BestSky, ShakeCamera, MoreLight, FlatItems, VibrateWalk, HUDInvDown, SmallGraphic, ParticlesFly, PaperModel, CameraLeft, CameraRight, BigParticles, HudLoading, StarsInSky, FootStepFast, FootStepSlow, SkinsDebug, ShadowSkins, SkinsPlayersRed, ParticlesFly1, LineBlockMove, DisablePlayers, SmallText, PosHudText, ArmsBroken, BlackFog, SkyNether, SmokeLobby, LookUnderWorld, FreeCam, RemoveHand, TornadoParticles, HitDamageRed, DisableFog, FovWithoutHand, ZoomWithoutHand, IronHelmet, EntityBaby, NoDetailedSkins, AimOn3thPerson, RenderEntity, RotationCam, TextureToBlack, GammaToMax, NameShadowBlack, AnimationCharacter, BigAnimCharacter, RotationBody, EntityBodyLight, NetherVision, ParticlesHitSpam, RobloxAnimation, Elytra, MoveHeadNoBody, StopAnimation, GiantGameplay, WorldLightWhite, WorldRainbowLight, ShadowSkins, DoubleName, OptimizeChunks, StopChunksLoad, RealJumpAnim, RainbowSky;
int ValueFOV, BigModel;


//Modules Menu
bool Zoom, TPAura, Nuker, AutoTossItems, AntiVoidtoggle, keystrokes;
int sizeNuker;
#pragma endregion