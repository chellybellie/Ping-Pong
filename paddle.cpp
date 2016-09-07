#pragma once
#include "paddle.h"
#include <iostream>
#include "sfwdraw.h"
#include "ball.h"


Player createPaddle(float X, char up, char down, unsigned int color, int size, float speed)
{
	Player retval;
	retval.up = up;
	retval.down = down;
	retval.X = X;
	retval.color = color;
	retval.size = size;
	retval.speed = speed;

	return retval;
}
void drawPaddle(const Player &p)
{
	sfw::drawLine(p.X, p.size + p.Y, p.X, p.Y, p.color);
}


void updatePaddle(Player &p)
{
	// also make sure that if Y < 0, that Y stops at 0
	if (sfw::getKey(p.up))
	{
		p.Y += p.speed;
	}
	if (sfw::getKey(p.down))
	{
		p.Y -= p.speed;
	}

	if (p.Y > 600 - p.size) p.Y = 600 - p.size;
	if (p.Y  <   0) p.Y = 0;
}
void Collision(Ball &b, Player &p1, Player &p2)
{
	if (b.x - b.Radius < p1.X && b.y > p1.Y && b.y < (p1.Y + p1.size))
	{
		b.VelX *= -1;
		b.x = p1.X + b.Radius;
	}
	if (b.x + b.Radius > p2.X && b.y > p2.Y && b.y < (p2.Y + p2.size))
	{
		b.VelX *= -1;
		b.x = p2.X - b.Radius;
	}
}
