#pragma once
#include "sfwdraw.h"
#include "Draw.h"
#include "ball.h"
#include <iostream>

void drawScore(unsigned font, float health)
{
	char buffer[64] = { 0 };
	sprintf_s(buffer,  "%d",health);
	sfw::drawString(font, buffer, 650, 600, 40, 40);
}

