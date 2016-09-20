#pragma once
#include "sfwdraw.h"
#include "ball.h"
#include <random>
#include <time.h>
#include "paddle.h"
#include <iostream>

float randRange(int start, int end)
{
	srand(time(0));
	return rand() % (end - start + 1) - start;

}

void Ball::drawball()
{
	sfw::drawCircle(x, y, Radius, 12, color);

}


void Ball::createBall(float a_x, float a_y, char a_up, char a_down, char a_left, char a_right, float a_Radius, unsigned int a_color, float a_health,int d)
{
	x = a_x;
	y = a_y;
	up = a_up;
	down = a_down;
	left = a_left;
	right = a_right;
	VelX = 0;
	VelY = 0;
	Radius = a_Radius;
	color = a_color;
	health = a_health;
	font = d;
	level = 0;
}
void Ball::drawHealth()
{
	char buffer[64] = { 0 };
	sprintf_s(buffer, "%d", health);
	sfw::drawString(font, buffer, 650, 600, 40, 40);
}




void Ball::updateball(Player &p1, Player &p2, Player &p3)
{
	if (y > 600 - Radius)
	{
		y = 600 - Radius;
		VelY *= -1;
	}
	if (y < 0)
	{	y = 0;
		VelY *= -1;
	}

	if (x < 0)
	{	x = 300;
		y = 400;
	}

	if (x > 800)
	{	x = 300;
		y = 400;
	}

}



bool Ball::HwallCollide( HorzWall & wall)
{
		return ((x > wall.x) && (x < wall.x + wall.size)) &&
		(((y < wall.y) && (y - VelY > wall.y)) || ((y > wall.y) && (y - VelY < wall.y)));
}

bool Ball::VwallCollide( VertWall & wall)
{
	return
		(y > wall.y && y < wall.y + wall.size) &&
		((x < wall.x && x - VelX > wall.x) || (x > wall.x && x - VelX < wall.x));
}



// pass in two arrays- one for vertical and one for horizontal.
void Ball::updateWalls( HorzWall wallH[], int hCount,  VertWall wallV[], int vCount)
{
	accX = 0;
	accY = 0;

	if (sfw::getKey(up))  accY = .3;
	if (sfw::getKey(down)) accY = -.3;
	if (sfw::getKey(left)) accX = -.3;
	if (sfw::getKey(right)) accX = .3; 

	if (VelX > 3) VelX = 3;
	if (VelX < -3) VelX = -3;
	if (VelY > 3) VelY = 3;
	if (VelY < -3) VelY = -3;

	VelX += accX;
	VelY += accY;
	x += VelX;
	y += VelY;

	for (int i = 0; i < hCount; ++i)
		if (HwallCollide(wallH[i]))
		{
			if (wallH[i].color == GREEN)
			{
				level++;
				x = 40;
				y = 40;
			}
			else
			{
				health -= 10;
				VelY *= -1;
				y = wallH[i].y + VelY - accY;
				wallH[i].timer = 0.4f;
			}
		}
	
	for (int i = 0; i < vCount; ++i)
		if (VwallCollide(wallV[i]))
		{
			if (wallV[i].color == GREEN)
			{
				level++;
				x = 40;
				y = 40;
			}
			else
			{
				health -= 10;
				VelX *= -1;
				x = wallV[i].x + VelX - accX;
				wallV[i].timer = 0.4f;
			}
		}
}

void VertWall::draw()
{
	timer -= sfw::getDeltaTime();
	//if (timer < 0)
	//	color = BLACK;
	//else color = RED;

	sfw::drawLine(x, y, x, y + size, timer < 0 ? color : RED);
}


void HorzWall::draw()
{
	timer -= sfw::getDeltaTime();
	//if (timer < 0)
	//	color = BLACK;
	//else color = RED;

	sfw::drawLine(x, y, x + size, y, timer < 0 ? color : RED);
}