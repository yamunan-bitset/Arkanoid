#include <raylib.h>
#include <vector>
#include "square.h"

namespace GFX
{
	static const unsigned w = 800, h = 800;
	std::vector<Vector2[4]> tiles;
	void Init()
	{
		InitWindow(w, h, "Arkanoid");
		SetTargetFPS(60);
		
		Rectangle tmp;
		for (unsigned j = 0; j < 3; j++)
			for (unsigned i = 0; i < 4; i++)
			{
				/*
				Vector2 vertices[] =
				{
					Vector2 { float(i) * 150 + 25, float(j) * 150 + 25 },
					Vector2 { vertices[0] + 150, 100},
					Vector2 { 100, 100 },
					Vector2 { 100, 100 },
				};*/
				Vector2 vertices[4];
				float x = float(i) * 150 + 25;
				float y = float(j) * 150 + 25;
				vertices[0] = { x, y };
				vertices[1] = { x + 150, y };
				vertices[2] = { x, y + 150 };
				vertices[3] = { x + 150, y };
				tiles.push_back(vertices);
			}
	}
	void Update()
	{
		
	}
	void Draw()
	{
		ClearBackground({ 128, 128, 128, 255 });
		DrawCircle(w / 2, h - 100, 20, GREEN);
		for (Vector2* i : tiles)
		{
			//DrawPolyLinesEx(i, );
			// TODO: Find ways to draw vertices into polygons (in Raylib v2.0, DrawPolyEx)
		}
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
