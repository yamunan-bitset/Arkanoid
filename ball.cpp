#include "ball.h"

Ball::Ball()
{
	move_dir = new int[2]{ 0, 0 };
}

#include <iostream>
void Ball::AddForce(int x, int y)
{
	move_dir[0] = x;
	move_dir[1] = y;
	std::cout << x << ", " << y << std::endl;
}

int* Ball::GetForce()
{ // TODO
	return move_dir;
}

bool Ball::Collision()
{
	return false;
}

void Ball::Draw(int w, int h)
{
	x += move_dir[0];
	y += move_dir[1];
	DrawCircle(w / 2 - x, h - 100 - y, 20, GREEN);
}
