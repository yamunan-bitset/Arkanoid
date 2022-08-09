#include <raylib.h>
#include <array>
#include <vector>

namespace GFX
{
	static const unsigned w = 800, h = 800;
	std::vector<std::array<int, 2>> tiles;
	int xpos = w / 2 - 50;
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
		if (IsKeyPressed(KEY_SPACE))
		{
			// TODO: ball.move = true;
		}
		if (IsKeyDown(KEY_LEFT))
			xpos -= 5;
		if (IsKeyDown(KEY_RIGHT))
			xpos += 5;
		if (xpos < 0) xpos = 0;
		if (xpos + 30 > h) xpos = h - 100;
	}
	void Draw()
	{
		ClearBackground({ 128, 128, 128, 255 });
		DrawCircle(w / 2, h - 100, 20, GREEN);
		for (std::array<int, 2> i : tiles)
			DrawRectangle(i[0], i[1], 80, 80, RED);
		DrawRectangle(xpos, h - 60 - 15, 100, 30, BLUE);
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
