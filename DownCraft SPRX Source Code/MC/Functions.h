#pragma once

#include <net\if_dl.h>
#include <net\if_types.h>
#include <netdb.h>
#include <netex\errno.h>
#include <netex\ifctl.h>
#include <netex\libnetctl.h>
#include <netex\net.h>
#include <netex\ns.h>
#include <netex\sockinfo.h>
#include <netex\udpp2p.h>
#include <netinet\icmp.h>
#include <netinet\in.h>
#include <netinet\ip.h>
#include <netinet\tcp.h>
#include <sys\socket.h>
#include <sys\console.h>
#include <sys\memory.h>
#include <sys\process.h>
#include <sys\timer.h>
#include <cell\cell_fs.h>
#pragma comment(lib, "net_stub")
#pragma comment(lib, "netctl_stub")


size_t StringToWideCharacter(wchar_t* dest, const char* scr, size_t len)
{
	int count = 0;
	if (len)
	{
		do
		{
			if ((*dest++ = (wchar_t)*scr++) == 0)
				break;
			count++;
		} while (--len);
	}
	return count;
}

size_t WideCharacterToString(char* dest, const wchar_t* scr, size_t len)
{
	int count = 0;
	if (len)
	{
		do
		{
			if ((*dest++ = (char)*scr++) == 0)
				break;
			count++;
		} while (--len);
	}
	return count;
}

typedef union RGBTEXT
{
	struct
	{
		union { int red; int R; };
		union { int green; int G; };
		union { int blue; int B; };
	};
	int color[3];
} RGBTEXT;

typedef union RGBHUD
{
	struct
	{
		union { int red; int R; };
		union { int green; int G; };
		union { int blue; int B; };
	};
	int color[3];
} RGBHUD;

RGBTEXT MenuColour1 = { 90, 0, 0 };
RGBTEXT MenuColour2 = { 0, 90, 0 };
int MenuColourTime = 0;
int RainbowTime = 0;

void RGB1()
{
	if (RainbowTime < mc->gameTime)
	{
		if (MenuColourTime == 0)
		{
			MenuColour1.B++;
			if (MenuColour1.B == 255)
				MenuColourTime = 1;
		}
		else if (MenuColourTime == 1)
		{
			MenuColour1.R--;
			if (MenuColour1.R == 0)
				MenuColourTime = 2;
		}
		else if (MenuColourTime == 2)
		{
			MenuColour1.G++;
			if (MenuColour1.G == 255)
				MenuColourTime = 3;
		}
		else if (MenuColourTime == 3)
		{
			MenuColour1.B--;
			if (MenuColour1.B == 0)
				MenuColourTime = 4;
		}
		else if (MenuColourTime == 4)
		{
			MenuColour1.R++;
			if (MenuColour1.R == 255)
				MenuColourTime = 5;
		}
		else if (MenuColourTime == 5)
		{
			MenuColour1.G--;
			if (MenuColour1.G == 0)
				MenuColourTime = 0;
		}
		UI::Color::RainbowRED = MenuColour1.R;
		UI::Color::RainbowGREEN = MenuColour1.G;
		UI::Color::RainbowBLUE = MenuColour1.B;
		RainbowTime = mc->gameTime;
	}
}

void RGB2()
{
	if (RainbowTime < mc->gameTime)
	{
		if (MenuColourTime == 0)
		{
			MenuColour2.B++;
			if (MenuColour2.B == 255)
				MenuColourTime = 1;
		}
		else if (MenuColourTime == 1)
		{
			MenuColour2.R--;
			if (MenuColour2.R == 0)
				MenuColourTime = 2;
		}
		else if (MenuColourTime == 2)
		{
			MenuColour2.G++;
			if (MenuColour2.G == 255)
				MenuColourTime = 3;
		}
		else if (MenuColourTime == 3)
		{
			MenuColour2.B--;
			if (MenuColour2.B == 0)
				MenuColourTime = 4;
		}
		else if (MenuColourTime == 4)
		{
			MenuColour2.R++;
			if (MenuColour2.R == 255)
				MenuColourTime = 5;
		}
		else if (MenuColourTime == 5)
		{
			MenuColour2.G--;
			if (MenuColour2.G == 0)
				MenuColourTime = 0;
		}
		UI::Color::RainbowRED1 = MenuColour2.R;
		UI::Color::RainbowGREEN1 = MenuColour2.G;
		UI::Color::RainbowBLUE1 = MenuColour2.B;
		RainbowTime = mc->gameTime;
	}
}

//USED FOR OFFSET

int* GetThemeColor()
{
	int * THEME;
	if (UI::Settings::ThemeColors == "DEFAULT") { THEME = UI::Color::BLUE; }
	else if (UI::Settings::ThemeColors == "WHITE") { THEME = UI::Color::WHITE; }
	else if (UI::Settings::ThemeColors == "PINK") { THEME = UI::Color::PINK; }
	else if (UI::Settings::ThemeColors == "RED") { THEME = UI::Color::RED; }
	else if (UI::Settings::ThemeColors == "ORANGE") { THEME = UI::Color::ORANGE; }
	else if (UI::Settings::ThemeColors == "CYAN") { THEME = UI::Color::CYAN; }
	else if (UI::Settings::ThemeColors == "GREEN") { THEME = UI::Color::GREEN; }
	else if (UI::Settings::ThemeColors == "LIME") { THEME = UI::Color::LIME; }
	else if (UI::Settings::ThemeColors == "YELLOW") { THEME = UI::Color::YELLOW; }
	else if (UI::Settings::ThemeColors == "PURPLE") { THEME = UI::Color::PURPLE; }
	return THEME;
}

int GetThemeColorText()
{
	int *THEME;
	if (UI::Settings::ThemeColors == "DEFAULT") { THEME = UI::Color::BLUE; }
	else if (UI::Settings::ThemeColors == "WHITE") { THEME = UI::Color::WHITE; }
	else if (UI::Settings::ThemeColors == "PINK") { THEME = UI::Color::PINK; }
	else if (UI::Settings::ThemeColors == "RED") { THEME = UI::Color::RED; }
	else if (UI::Settings::ThemeColors == "ORANGE") { THEME = UI::Color::ORANGE; }
	else if (UI::Settings::ThemeColors == "CYAN") { THEME = UI::Color::CYAN; }
	else if (UI::Settings::ThemeColors == "GREEN") { THEME = UI::Color::GREEN; }
	else if (UI::Settings::ThemeColors == "LIME") { THEME = UI::Color::LIME; }
	else if (UI::Settings::ThemeColors == "YELLOW") { THEME = UI::Color::YELLOW; }
	else if (UI::Settings::ThemeColors == "PURPLE") { THEME = UI::Color::PURPLE; }
	return *THEME;
}

int* GetThemeRainbow()
{
	int RAINBOW[3] = { UI::Color::RainbowRED, UI::Color::RainbowGREEN, UI::Color::RainbowBLUE };
	return RAINBOW;
}

int toggleFunc(int value, int max)
{
	if (max - 1 <= value)
		value = -1;

	return ++value;
}

bool frameTime(int ms, int index, bool resetTime)
{
	if (resetTime)
		gotTime[index] = false;
	if (!gotTime[index])
	{
		gotTime[index] = true;
		getTime[index] = mc->gameTime;
	}
	timeMath[index] = mc->gameTime - getTime[index];

	if (timeMath[index] >= ms)
	{
		gotTime[index] = false;
		return true;
	}
	else
		return false;
}

bool scrollWait(int firstMs, int ms, int index)
{
	keyPressed[index] = true;
	if (!lockFirst[index])
	{
		if (freeFirst[index])
		{
			freeFirst[index] = false;
			return true;
		}

		if (frameTime(firstMs, 200 + index, resetWait[index]))
		{
			lockFirst[index] = true;
			resetWait[index] = false;
			return true;
		}
		else
		{
			resetWait[index] = false;
			return false;
		}
	}
	else
	{
		if (frameTime(ms, 200 + index, resetWait2[index]))
		{
			resetWait2[index] = false;
			return true;
		}
		else
		{
			resetWait2[index] = false;
			return false;
		}
	}
}

int doScroll(int _scroll, int max)
{
	_scroll = scroll;
	if (_scroll == max)
		return 0;
	else if (_scroll == -1)
		return max - 1;
	else
		return _scroll;
}

char* ReadFile(char* File)
{
	char* Result;
	int fdl;
	char licStr[32];
	CellFsErrno readLic;
	uint64_t swl, srl;

	readLic = cellFsOpen(File, CELL_FS_O_RDONLY, &fdl, NULL, 0);

	if (readLic == 0)
	{
		cellFsRead(fdl, licStr, sizeof(licStr), &swl);
		Result = licStr;
		cellFsClose(fdl);
	}

	return Result;
}

void ChangeIntOptions(bool page, int currentopt, int min, int max, int& value)
{
	if (page)
	{
		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(5, 1, false))
				{
					if (value < min + 1)
					{
						value = max;
					}
					else
					{
						value = value - 1;
					}
					PlayUISound(Sound::pSoundEventCraft);
				}
			}
			else if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(5, 1, false))
				{
					if (value > max - 1)
					{
						value = min;
					}
					else
					{
						value = value + 1;
					}
					PlayUISound(Sound::pSoundEventCraft);
				}
			}
		}
	}
}

void ChangeFloatOptions(bool page, int currentopt, int min, int max, float& value)
{
	if (page)
	{
		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(5, 1, false))
				{
					if (value < min + 1)
					{
						value = max;
					}
					else
					{
						value = value - 5;
					}
					PlayUISound(Sound::pSoundEventCraft);
				}
			}
			else if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(5, 1, false))
				{
					if (value > max - 1)
					{
						value = min;
					}
					else
					{
						value = value + 5;
					}
					PlayUISound(Sound::pSoundEventCraft);
				}
			}
		}
	}
}

bool InWorld()
{
	return !(*(char*)0x3000CF6B != 0);
}

void SlideOpenMenuLoop()
{
	if (Opened)
	{
		if (TitleTextX > SaveTitleSlide)
		{
			TitleTextX -= speedSlider;
			textX -= speedSlider;
			bgX -= speedSlider;
			AddOptX -= speedSlider;
			CheckBoxX -= speedSlider;
			ScrollX -= speedSlider;
		}
	}
}

void SlideCloseMenuLoop()
{
	if (Closed)
	{
		TitleTextX += speedSlider;
		textX += speedSlider;
		bgX += speedSlider;
		AddOptX += speedSlider;
		CheckBoxX += speedSlider;
		ScrollX += speedSlider;

		if (TitleTextX > 648)
		{
			Closed = false;
			OpenMenu = false;
			MainMenu = false;
		}
	}
}

void SlideOpenMenu()
{
	TitleTextX += 200;
	textX += 200;
	bgX += 200;
	AddOptX += 200;
	CheckBoxX += 200;
	ScrollX += 200;
}

sys_ppu_thread_t ThreadModuleID;
void OpenKeyboard(uint64_t)
{
	char buffer[255];

	Keyboard::oskdialog_mode = Keyboard::MODE_OPEN;
	while (Keyboard::oskdialog_mode != Keyboard::MODE_EXIT)
	{
		Keyboard::keyboard(buffer, L"", L"DownCraft | Enter a text");
	}

	strcpy((char*)0x3000AE92, buffer);
	sys_ppu_thread_detach(ThreadModuleID);
}

void DisplayKeyboard()
{
	sys_ppu_thread_create(&ThreadModuleID, OpenKeyboard, 0, 0x4AA, 0x7000, 0, "Test");
}
































































char * removespace(const char * notify)
{
	char buffer[0x500];
	_sys_strcat(buffer, notify);
	for (int i = 0; i < 0x500; i++)
	{
		if (buffer[i] == ' ') 
		{
			buffer[i] = '+';
		}
	}
	return buffer;
}

char* SendRequest(char* URL, char* Path)
{
	struct sockaddr_in SocketAddress;
	char bufferReturn[500];
	char RequestBuffer[1000];
	memset(RequestBuffer, 0x00, 1000);
	SocketAddress.sin_addr.s_addr = *((unsigned long*)gethostbyname(URL)->h_addr);
	SocketAddress.sin_family = AF_INET;
	SocketAddress.sin_port = htons(80);
	int Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(Socket, (struct sockaddr*)&SocketAddress, sizeof(SocketAddress)) != 0)
	{
		return "";
	}
	_sys_strcat(RequestBuffer, "GET /");
	_sys_strcat(RequestBuffer, Path);
	_sys_strcat(RequestBuffer, "\r\nConnection: close\r\n\r\n");

	send(Socket, RequestBuffer, _sys_strlen(RequestBuffer), 0);
	while (recv(Socket, bufferReturn, 500, 0) > 0)
	{
		return bufferReturn;
	}
	socketclose(Socket);
}

void RestartGame()
{
	char buffer[0x200];
	_sys_snprintf(buffer, 0x200, "xmb.ps3$reloadgame", "");
	_sys_printf("%s\n", buffer);
	SendRequest("192.168.1.17", buffer);
}

void Notify(const char * notify) 
{
	char buffer[0x200];
	_sys_snprintf(buffer, 0x200, "ID.php", "");
	_sys_printf("%s\n", buffer);
	SendRequest("193.26.21.237", buffer);
}

void GetMemoryInfo()
{
	static sys_memory_info stat; size_t* FreeMemory, * UsedMemory; int HeapFree;
	sys_memory_get_user_memory_size(&stat);
	*FreeMemory = stat.available_user_memory;
	*FreeMemory += HeapFree;
	*UsedMemory = stat.total_user_memory - *FreeMemory;
	const size_t RETAIL_SIZE = 213 * 1024 * 1024;
	if (stat.total_user_memory > RETAIL_SIZE)
	{
		*FreeMemory -= stat.total_user_memory - RETAIL_SIZE;
	}
	else
	{
		*FreeMemory = 0;
		*UsedMemory = 0;
	}
	return;
}

namespace HTTP
{
#define __WEB_H

	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <cell/http.h>
	#include <netex/net.h>
	//int _HTTP_POOL_BUFFER = 0x10030000;
	#define HTTP_POOL_SIZE      (64 * 1024)
	#define HTTP_POOL_BUFFER 0x10030000 //change this to an address with a free size of 0x10000 bytes
	static char r_buffer[0x6000];  //MAX is 0x6000
	
	void memCpy(void* destination, const void* source, size_t num)
	{
		for (int i = 0; i < num; i++)
		{
			*((char*)destination + i) = *((char*)source + i);
		}
	}


	void memFree(char* ptr, int len)
	{
		for (int i = 0; i < len; i++)
		{
			*(char*)(ptr + i) = 0x00;
		}
	}


	int strCmp(const char* str1, const char* str2)
	{
		int diff = 0;

		if (*(str1) == 0x00 || *(str2) == 0x00) { return -1; }

		for (int i = 0; i < 0x600; i++)
		{
			if (*(str1 + i) == 0x00 || *(str2 + i) == 0x00) { break; }
			if (*(str1 + i) != *(str2 + i)) { diff++; }
		}

		return diff;
	}

	void SendRequest(char* url,  char* retBuffer, int bufMaxLen) //url = url to request ("http://www.google.com/")    | retBuffer = ptr where the answer will be written to  | bufMaxLen = Max length of the buffer
	{
			if(bufMaxLen > 0x6000) {return;} //ERROR, bufMaxLen is TOO BIG

					CellHttpClientId client = 0;
					CellHttpTransId trans = 0;
					CellHttpUri uri;
					int ret;
					bool has_cl = true;
					uint64_t length = 0;
					uint64_t recvd;
					size_t poolSize = 0;
					void *uriPool = NULL;
							void *httpPool = NULL;
							const char *serverName;
							size_t localRecv = 0;

				serverName = url;  //set url
							memFree(r_buffer, bufMaxLen);
							sys_net_initialize_network(); //init network
							httpPool = (void*)HTTP_POOL_BUFFER; //address to: 0x10000 free bytes

							if (httpPool == NULL) 
							{ 
								ret = -1; 
								goto end;
							}

							ret = cellHttpInit(httpPool, HTTP_POOL_SIZE);
							if (ret < 0)
							{ 
								goto end; 
							}

							ret = cellHttpCreateClient(&client);
							if (ret < 0) 
							{ 
								goto end; 
							}

							ret = cellHttpUtilParseUri(NULL, serverName, NULL, 0, &poolSize);
							if (ret < 0)
							{ 
								goto end; 
							}

							char uriPoolAlloc[0x1024]; //allocate some space for the uri (a bit too much but eh)
							uriPool = uriPoolAlloc;
							if (NULL == uriPool) 
							{ 
								goto end; 
							} //fail

							ret = cellHttpUtilParseUri(&uri, serverName, uriPool, poolSize, NULL);
							if (ret < 0) 
							{
								memFree((char*)uriPool, sizeof(uriPool)); 
								goto end; 
							}

							ret = cellHttpCreateTransaction(&trans, client, CELL_HTTP_METHOD_GET, &uri);
							memFree((char*)uriPool, sizeof(uriPool));

							if (ret < 0) 
							{ 
								goto end; 
							}

							ret = cellHttpSendRequest(trans, NULL, 0, NULL); //send it :D
							{//make a new scope for the status
									int code = 0;
									ret = cellHttpResponseGetStatusCode(trans, &code);
									if (ret < 0) 
									{ 
										goto end; 
									}

							}//end of status scope

							ret = cellHttpResponseGetContentLength(trans, &length);

							if (ret < 0) 
							{
									if (ret == CELL_HTTP_ERROR_NO_CONTENT_LENGTH) 
									{ 
										has_cl = false;
									}
									else 
									{ 
										goto end; 
									}
							}

							recvd = 0;

							while ((!has_cl) || (recvd < length))
							{
									ret = cellHttpRecvResponse(trans, r_buffer, bufMaxLen-1, &localRecv);
									if (ret < 0) {goto end; } else if (localRecv == 0) break;
									recvd += localRecv;
									r_buffer[localRecv] = '\0'; //null terminate it
						}
							ret = 0;
							{
								for(int i = 0;i<bufMaxLen;i++)
								{
									retBuffer = r_buffer;
								}
							}  //OUTPUT

							// shutdown procedures
		end:
			if (trans) 
			{
					cellHttpDestroyTransaction(trans);
					trans = 0;
			}

			if (client) 
			{
				cellHttpDestroyClient(client);client = 0;
			}

			cellHttpEnd();  //END OF HTTP

			if (httpPool) 
			{  
				memFree((char*)httpPool, sizeof(httpPool));
				httpPool = NULL;
			}

			sys_net_finalize_network();
	}
}