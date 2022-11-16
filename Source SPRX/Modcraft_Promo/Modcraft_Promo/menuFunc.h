void gameRender_Stub(uint32_t r3, uint32_t r4) {
	__nop(); __nop(); __nop(); __nop(); __nop();
}

int toggleFunc(int value)
{
	if (value == 0)
	{
		return 1;
	}
	else if (value == 1)
	{
		return 0;
	}
	else
		return 0;
}

int toggleFunc(int value, int max)
{
	if (max - 1 <= value)
		value = -1;

	return ++value;
}

namespace mcBtnOfs
{
	enum MCbuttonsOffsets
	{
		_L2 = 0xF0,
		_R2 = 0xF1,
		R1 = 0xB3,
		R2 = 0xB1,
		R3 = 0xB2,
		L1 = 0xB3,
		L2 = 0xB1,
		L3 = 0xB2,
		DpadUp = 0xB2,
		DpadDown = 0xB2,
		DpadLeft = 0xB2,
		DpadRight = 0xB2,
		Cross = 0xB3,
		Square = 0xB3,
		Circle = 0xB3,
		Triangle = 0xB3,
		Select = 0xB3,
		Start = 0xB3
	};
}
namespace mcBtnBytes
{
	enum MCbuttonsBytes
	{
		_R2 = 0,
		_L2 = 0,
		R2L2 = 0xC0,
		R1 = 0x40,
		R2 = 0x40,
		R3 = 0x01,
		L1 = 0x80,
		L2 = 0x80,
		L3 = 0x02,
		DpadUp = 0x04,
		DpadDown = 0x08,
		DpadLeft = 0x10,
		DpadRight = 0x20,
		Cross = 0x01,
		Square = 0x04,
		Circle = 0x02,
		Triangle = 0x08,
		Select = 0x20,
		Start = 0x10
	};
}

 bool buttonPressed(int ofs, int button)
{
	if (*(char*)(btnMonOfs + (mcBtnOfs::MCbuttonsOffsets(ofs))) == mcBtnBytes::MCbuttonsBytes(button))
		return true;
	else
		return false;
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
	 if (_scroll == max )
		 return 0;
	 else if (_scroll == -1)
		 return max - 1;
	 else
		 return _scroll;
 }

 void open()
 {
	 isOpen = true;
 }

 void close()
 {
	 isOpen = false;
 }

 int saveFuncIndex = 0;
 void menuMon()
 {
	 if (isOpen)
	 {
		 int wI = 0;
		 keyPressed[wI] = false;
		 if (buttonPressed(mcBtnOfs::DpadUp, mcBtnBytes::DpadUp))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
				 scroll = doScroll(scroll--, subMax);
		 }
		 if (buttonPressed(mcBtnOfs::DpadDown, mcBtnBytes::DpadDown))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
				 scroll = doScroll(scroll++, subMax);
		 }
		 if (buttonPressed(mcBtnOfs::Cross, mcBtnBytes::Cross))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
				 select();
		 }
		 if (buttonPressed(mcBtnOfs::R3, mcBtnBytes::R3))
		 {
			 if (scrollWait(firstWaitTime, waitTime, wI))
				 close();
		 }
		 if (!keyPressed[wI])
		 {
			 lockFirst[wI] = false;
			 freeFirst[wI] = true;
			 resetWait[wI] = true;
			 resetWait2[wI] = true;
		 }
	 }
	 else
	 {
		 if (buttonPressed(mcBtnOfs::DpadUp, mcBtnBytes::DpadUp))
		 {
			 open();
		 }
	 }
 }

 void select()
 {
	 if (scroll == 0)
	 {

	 }
 }

 void menu()
 {
	 drawText("     ", 0, 0, color(255, 255, 255));//dont move

	 if (isOpen)
	 {
		 *(int*)0x0155847C = 0x01000000;
		 subMax = 10;
		 char* menuTxt[10] = { " DownCraft SPRX V4", "", "Host Options", "Non Host Options", "Visual Options", "Mics Options", "Teleport Options", "Game Options", "Settings", "Credits" };

		 int txtX = 30;
		 int txtY = 30;
		 int txtI = 12;

		 int bgX = txtX - 5;
		 int bgY = txtY - 5;
		 int bgW = 100;
		 int bgH = txtI * subMax + 5;

		 int bgColor[3] = { 15, 15, 15 };
		 int scrollColor[3] = { 255, 151, 187 };
		 drawRect(bgX, bgY, bgW, bgH, bgColor);
		 drawRect(bgX, bgX + (scroll * txtI) + 2, bgW, txtI, scrollColor);

		 for (int i = 0; i < subMax; i++)
			 drawText(menuTxt[i], txtX, txtY + (txtI * i), color(255, 255, 255));
	 }
	 else
	 {
		 *(int*)0x0155847C = 0x00000000;
	 }
 }

 void GetInfos()
 {
	 int txtI = 8;
 }