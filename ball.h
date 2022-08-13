#pragma once
#include <raylib.h>
class Ball
{
	int x, y;
	int* move_dir;
public:
	Ball();
	int* GetForce();
	void AddForce(int, int);
	bool Collision();
	void Draw(int, int);
};

