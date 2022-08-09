#include <raylib.h>
#include <array>
#include <vector>
#include "square.h"

namespace GFX
{
	static const unsigned w = 800, h = 800;
	std::vector<std::array<int, 2>> tiles;
	void Init()
	{
		InitWindow(w, h, "Arkanoid");
		SetTargetFPS(60);
		
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 5; i++)
				tiles.push_back(std::array<int, 2> { i * 150 + 40, j * 150 + 40 });
	}
	void Update()
	{
		
	}
	void Draw()
	{
		ClearBackground({ 128, 128, 128, 255 });
		DrawCircle(w / 2, h - 100, 20, GREEN);
		for (std::array<int, 2> i : tiles)
			DrawRectangle(i[0], i[1], 80, 80, RED);
	}
	bool Open()
	{
		return !WindowShouldClose();
	}
	void Close()
	{
		CloseWindow();
	}
}

int main(int argc, char** argv)
{
	GFX::Init();
	while (GFX::Open())
	{
		GFX::Update();
		BeginDrawing();
		GFX::Draw();
		EndDrawing();
	}
	GFX::Close();
	return 0;
}
