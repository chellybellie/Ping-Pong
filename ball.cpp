#pragma once
#include "sfwdraw.h"
#include "ball.h"
#include <random>
#include <time.h>
#include "paddle.h"

float randRange(int start, int end)
{
	srand(time(0));
	return rand() % (end - start + 1) - start;

}

void drawball(const Ball &b)
{
	sfw::drawCircle(b.x, b.y, b.Radius, 12, b.color);

}

Ball createBall(float x, float y, float VelX, float VelY, float Radius, unsigned int color)
{
	Ball retval;
	retval.x = x;
	retval.y = y;
	retval.VelX = randRange(15, 25);
	retval.VelY = randRange(15, 25);
	retval.Radius = Radius;
	retval.color = color;
	return retval;
}




void updateball(Ball &b, Player &p1, Player &p2)
{

	b.x += b.VelX;
	b.y += b.VelY;

	if (b.y > 600 - b.Radius)
	{
		b.y = 600 - b.Radius;


		b.VelY *= -1;
	}
	if (b.y < 0)
	{
		b.y = 0;
		b.VelY *= -1;
	}
	if (b.x < 0)
	{

		p1.score++;
		printf("%d to %d \n", p1.score, p2.score);

		b.x = 300;
		b.y = 400;
	}

	if (b.x > 800)
	{
		p2.score++;
		printf("%d to %d \n", p1.score, p2.score);
		b.x = 300;
		b.y = 400;
	}
}
