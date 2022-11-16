void drawShadowText(uint32_t font, uint32_t r4, uint32_t x, uint32_t y, uint32_t color, uint32_t r8, uint32_t r9) {
	Call<void>(shaderOfs, font, r4, x, y, color, r8, r9);
}

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

int wcslen(const wchar_t * wchar) {
	return Call<int>(wcLenOfs, wchar);
}

font_t getString(const wchar_t * str) {
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

void drawText(char* text, float x, float y, uint32_t Color)
{
	drawShadowText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(c2wc(text)), x, y, Color, 0, 1);
}

uint32_t Tesselator_GetInstance() {
	return Call<uint32_t>(addr1);
}

uint32_t ReadTesselatorInstance(uint32_t r3) {
	return Call<uint32_t>(addr2, r3);
}
void Tesselator_Begin(uint32_t pTesselator) {
	Call<void>(addr3, pTesselator);
}
void Tesselator_Color(uint32_t pTesselator, int r, int g, int b, float a) {
	Call<void>(addr4, pTesselator, r, g, b, a);
}
void Tesselator_End(uint32_t pTesselator) {
	Call<void>(addr5, pTesselator);
}

void BufferBuilder_endVertex(uint32_t pTesselator, float f1, float f2, float f3, float f4, float f5) {
	Call<void>(addr6, pTesselator, f1, f2, f3, f4, f5);
}
void Tesselator_EndVertex(uint32_t pTesselator, float X, float Y, float Z, int* Color) {
	Tesselator_Color(pTesselator, Color[0], Color[1], Color[2], 255);
	BufferBuilder_endVertex(pTesselator, X, Y, Z, 0, 0);
}
void drawRect(float x, float y, float w, float h, int* Color) {
	uint32_t pTesselator = ReadTesselatorInstance(Tesselator_GetInstance());
	Tesselator_Begin(pTesselator);
	Tesselator_EndVertex(pTesselator, x, h + y, 0, Color);
	Tesselator_EndVertex(pTesselator, w + x, h + y, 0, Color);
	Tesselator_EndVertex(pTesselator, w + x, y, 0, Color);
	Tesselator_EndVertex(pTesselator, x, y, 0, Color);
	Tesselator_End(pTesselator);
}
void drawRectBorder(float x, float y, float w, float h, int* Color, int* Color2) {
	drawRect(x - 1, y - 1, w + 2, h + 2, Color2);
	drawRect(x, y, w, h, Color);
}