#pragma once

namespace Options
{
	void GOD_MODE() { if (GodMode) *(int*)0x4B2020 = 0xFC80F890; else *(int*)0x4B2020 = 0xFC20F890; }
	void SUPER_SPEED() { if (SuperSpeed) *(int*)0x003ABD49 = 0x99999940; else *(int*)0x003ABD49 = 0x26AD8940; }

	char* getName()
	{
		if (*(int*)0x3000ABE4 == 0x00000000)
			return (char*) NyTekCFW::ReadString(0x3000ABA4);
		else
			return (char*)NyTekCFW::ReadString(0x3000AD34);
	}

	void setName(char* name)
	{
		NyTekCFW::WriteString(0x3000ABE4, name);
		NyTekCFW::WriteString(0x3000ABA4, name);
	}
}