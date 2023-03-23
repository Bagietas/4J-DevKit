#pragma once

namespace FUNCTIONS
{
	CallFunction(0xA7E2E8, void, DrawText, (uint32_t font, uint32_t r4, uint32_t x, uint32_t y, uint32_t color, uint32_t r8, uint32_t r9));
	CallFunction(0xBDCA84, uint32_t, Tesselator_GetInstance, ());
	CallFunction(0xBDCA9C, uint32_t, ReadTesselatorInstance, (uint32_t r3));
	CallFunction(0x9C1928, void, Tesselator_Begin, (uint32_t pTesselator));
	CallFunction(0x9C1A3C, void, Tesselator_Color, (uint32_t pTesselator, int r, int g, int b, double a));
	CallFunction(0x9C170C, void, Tesselator_End, (uint32_t pTesselator));
	CallFunction(0x9C2388, void, BufferBuilder_endVertex, (uint32_t pTesselator, float f1, float f2, float f3, float f4, float f5))

	void Tesselator_EndVertex(uint32_t pTesselator, float X, float Y, float Z, int* Color) { Tesselator_Color(pTesselator, Color[0], Color[1], Color[2], 255); BufferBuilder_endVertex(pTesselator, X, Y, Z, 0, 0); }
};

void DrawText(const wchar_t* text, float x, float y, uint32_t color) {
	FUNCTIONS::DrawText(mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color, 0, 1);
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
