#pragma once
#include "sfwdraw.h"
#include "paddle.h"
#include <iostream>


void Player::createPaddle(float a_X, float a_Y, float a_X2, float a_Y2,
								unsigned int a_color, int a_size, float a_speed)
{
	
	X = a_X;
	Y = a_Y;
	X2 = a_X2;
	Y2 = a_Y2;
	color = a_color;
	size = a_size;
	speed = a_speed;

	score = 0;
}
void Player::drawPaddle()
{
	sfw::drawLine(X,Y, X2, Y2, color);
}


void Player::updatePaddle()
{

	if (sfw::getKey(up))
	{
		Y += speed;
	}
	if (sfw::getKey(down))
	{
		Y -= speed;
	}

	if (Y > 600 - size) Y = 600 - size;
	if (Y  <   0) Y = 0;
}


//
//void VertWall::draw()
//{
//	sfw::drawLine(x, y, x, y+size);
//}
//
//void HorzWall::draw()
//{
//	sfw::drawLine(x, y, x+size, y);
//}
