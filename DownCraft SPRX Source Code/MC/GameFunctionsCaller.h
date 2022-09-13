
#pragma region "Funcs"

struct Color
{
	Color(std::uint8_t r = 255, std::uint8_t g = 255, std::uint8_t b = 255, std::uint8_t a = 255)
		: r(r), g(g), b(b), a(a)
	{

	}

	Color(std::uint32_t hexValue)
	{
		a = (hexValue & 0xFF000000) >> 24;
		r = (hexValue & 0xFF0000) >> 16;
		g = (hexValue & 0xFF00) >> 8;
		b = hexValue & 0xFF;
	}

	std::uint32_t ToHex()
	{
		return (a << 24) | (r << 16) | (g << 8) | b;
	}


	std::uint8_t a;
	std::uint8_t r;
	std::uint8_t g;
	std::uint8_t b;
};


wchar_t* c2wc(char* txt)
{
	if (checkTxt != txt)
	{
		int len = strlen(txt);
		for (int i = 0; i < len; i++)
		{
			charA2wcharA_[i] = txt[i];
		}
		charA2wcharA_[len] = '\0';
		checkTxt = txt;

	}
	return charA2wcharA_;
}

font_t getString(const wchar_t* str)
{
	font_t font;
	font.text = str;
	font.dataType = 7;
	font.wcstrlen = wcslen(str);
	font.wcstrlen1 = wcslen(str) + 3;
	font.unknown1 = 2.0625f;
	font.unknown1 = 1.0f;
	font.unknown1 = 1.0078125f;
	return font;
}

#pragma endregion

void DrawText(const wchar_t* text, float x, float y, uint32_t color) {
	FUNCTIONS::DrawText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color, 0, 1);
}

void DrawTextC(char* text, float x, float y, uint32_t color) {
	FUNCTIONS::DrawText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(c2wc(text)), x, y, color, 0, 1);
}

void DrawTextWithShadow(const wchar_t* text, uint32_t x, uint32_t y, uint32_t color) {
	FUNCTIONS::DrawTextWithShadow(g_GuiComponent, mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color);
}

void DrawRectangle(float x, float y, float w, float h, int* Color) {
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_Begin(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, Color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, Color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, Color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, Color);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void DrawRectangleAlpha(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color) {
	FUNCTIONS::DrawRectangleAlpha(g_GuiComponent, x, y, width, height, color.ToHex());
}

void PlayUISound(uintptr_t* SoundEvent) {
	FUNCTIONS::ConsoleUIController_PlayUISFX(ConsoleUIController, *SoundEvent);
}

void PlayerUpwardsJumpMotion(float jumpHeight) {
	FUNCTIONS::PlayerUpwardsJumpMotion(jumpHeight);
}