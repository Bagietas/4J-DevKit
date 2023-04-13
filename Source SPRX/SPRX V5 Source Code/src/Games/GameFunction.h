#pragma once

namespace FUNCTIONS
{
	CallFunction(0xA7E5DC, void, DrawTextShadow, (void* guiComponent, uint32_t font, uint32_t text, uint32_t x, uint32_t y, uint32_t color));
	CallFunction(0xA7E2E8, void, DrawText, (uint32_t font, uint32_t r4, uint32_t x, uint32_t y, uint32_t color, uint32_t r8, uint32_t r9));
	CallFunction(0xA7CE80, void, DrawRectangleAlpha, (void* guiComponent, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t color));

	CallFunction(0xBDCA84, uint32_t, Tesselator_GetInstance, ());
	CallFunction(0xBDCA9C, uint32_t, ReadTesselatorInstance, (uint32_t r3));
	CallFunction(0x9C1928, void, Tesselator_Begin, (uint32_t pTesselator));
	CallFunction(0x9C1A3C, void, Tesselator_Color, (uint32_t pTesselator, int r, int g, int b, int a));
	CallFunction(0x9C170C, void, Tesselator_End, (uint32_t pTesselator));
	CallFunction(0x9C2388, void, BufferBuilder_endVertex, (uint32_t pTesselator, float f1, float f2, float f3, float f4, float f5))
	
	void Tesselator_EndVertex(uint32_t pTesselator, float X, float Y, float Z, int* Color) { Tesselator_Color(pTesselator, Color[0], Color[1], Color[2], Color[3]); BufferBuilder_endVertex(pTesselator, X, Y, Z, 0, 0); }
};

void DrawTextShadow(const wchar_t* text, uint32_t x, uint32_t y, uint32_t color) {
	FUNCTIONS::DrawTextShadow(g_GuiComponent, mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color);
}

void DrawText(const wchar_t* text, float x, float y, uint32_t color) {
	FUNCTIONS::DrawText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color, 0, 1);
}

void DrawTextC(char* text, float x, float y, uint32_t color) {
	FUNCTIONS::DrawText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(c2wc(text)), x, y, color, 0, 1);
}

void DrawRectangle(float x, float y, float w, float h, int* color)
{
	uint32_t pTesselator = FUNCTIONS::ReadTesselatorInstance(FUNCTIONS::Tesselator_GetInstance());
	FUNCTIONS::Tesselator_End(pTesselator);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, h + y, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, h + y, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, w + x, y, 0, color);
	FUNCTIONS::Tesselator_EndVertex(pTesselator, x, y, 0, color);
	FUNCTIONS::Tesselator_End(pTesselator);
}

void DrawRectangleBorder(float x, float y, float w, float h, int* Color1, int* Color2, int borderSize)
{
	DrawRectangle(x - borderSize, y - borderSize, w + borderSize * 2, h + borderSize * 2, Color2);
	DrawRectangle(x, y, w, h, Color1);
}

void DrawRectangleAlpha(float x, float y, float width, float height, Color color) {
	FUNCTIONS::DrawRectangleAlpha(g_GuiComponent, x, y, width + 80, height + 80, color.ToHex());
}