#pragma once
#include "sfwdraw.h"
#include "paddle.h"
#include <iostream>


void Player::createPaddle(float a_X, char a_up, char a_down,
								unsigned int a_color, int a_size, float a_speed)
{
	up = a_up;
	down = a_down;
	X= a_X;
	color = a_color;
	size = a_size;
	speed = a_speed;
}
void Player::drawPaddle()
{
	sfw::drawLine(X, size + Y, X, Y, color);
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
