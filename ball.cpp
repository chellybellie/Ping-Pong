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

void Ball::drawball()
{
	sfw::drawCircle(x, y, Radius, 12, color);

}

void Ball::createBall(float a_x, float a_y, float a_Radius, unsigned int a_color)
{
	x = a_x;
	y = a_y;
	VelX = randRange(15, 25);
	VelY = randRange(15, 25);
	Radius = a_Radius;
	color = a_color;
}




void Ball::updateball(Player &p1, Player &p2)  
{

	x += VelX;
	y += VelY;

	if (y > 600 - Radius)
	{
		y = 600 - Radius;


		VelY *= -1;
	}
	if (y < 0)
	{
		y = 0;
		VelY *= -1;
	}
	if (x < 0)
	{

		p1.doScore();
		printf("%d to %d \n", p1.getScore(), p2.getScore());

		x = 300;
		y = 400;
	}

	if (x > 800)
	{
		p2.doScore();
		printf("%d to %d \n", p1.getScore(), p2.getScore());
		x = 300;
		y = 400;
	}


	if (x - Radius < p1.getX() && y > p1.getBot() && y < p1.getTop())
	{
		VelX *= -1;
		x = p1.getX() + Radius;
	}
	if (x + Radius > p2.getX() && y > p2.getBot() && y < p2.getTop())
	{
		VelX *= -1;
		x = p2.getX() - Radius;
	}
}
