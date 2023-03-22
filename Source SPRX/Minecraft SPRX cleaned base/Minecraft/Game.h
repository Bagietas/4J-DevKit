#pragma once

//Call Methods

uint32_t Tesselator_GetInstance() {
	return Call<uint32_t>(0x00BDCA84);
}

uint32_t ReadTesselatorInstance(uint32_t r3) {
	return Call<uint32_t>(0x00BDCA9C, r3);
}

void Tesselator_Begin(uint32_t pTesselator, int iVertex) {
	Call<void>(0x009C18F0, pTesselator, iVertex);
}

void Tesselator_Begin(uint32_t pTesselator) {
	Call<void>(0x009C1928, pTesselator);
}

void Tesselator_Color(uint32_t pTesselator, uint32_t iColor) {
	Call<void>(0x009C241C, pTesselator, iColor);
}

void Tesselator_Color(uint32_t pTesselator, int r, int g, int b, int a) {
	Call<void>(0x009C1A3C, pTesselator, r, g, b, a);
}
void Tesselator_Vertex(uint32_t pTesselator, float v1, float v2, float v3) {
	Call<void>(0x009C22E4, pTesselator, v1, v2, v3);
}

void Tesselator_End(uint32_t pTesselator) {
	Call<void>(0x009C170C, pTesselator);
}

void Tesselator_End1(uint32_t pTesselator) {
	Call<void>(0x00BDD300, pTesselator);
}

void Tesselator_glNormal3f(uint32_t pTesselator, float v1, float v2, float v3) {
	Call<void>(0x009C24B8, pTesselator, v1, v2, v3);
}

void BufferBuilder_endVertex(uint32_t pTesselator, float f1, float f2, float f3, float f4, float f5) {
	Call<void>(0x009C2388, pTesselator, f1, f2, f3, f4, f5);
}

void Tesselator_EndVertex(uint32_t pTesselator, float X, float Y, float Z, int* Color) { Tesselator_Color(pTesselator, Color[0], Color[1], Color[2], 255); BufferBuilder_endVertex(pTesselator, X, Y, Z, 0, 0); }

void drawText(const wchar_t* text, float x, float y, uint32_t color)
{
	Call<void>(0x00A7E2E8, mc->theMinecraft->fontRenderer, (uint32_t)&getString(text), x, y, color, 0, 1);
}

void drawRectangle(float x, float y, float w, float h, int* color)
{
	uint32_t pTesselator = ReadTesselatorInstance(Tesselator_GetInstance());
	Tesselator_End(pTesselator);
	Tesselator_EndVertex(pTesselator, x, h + y, 0, color);
	Tesselator_EndVertex(pTesselator, w + x, h + y, 0, color);
	Tesselator_EndVertex(pTesselator, w + x, y, 0, color);
	Tesselator_EndVertex(pTesselator, x, y, 0, color);
	Tesselator_End(pTesselator);
}

