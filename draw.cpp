#pragma once
#include "sfwdraw.h"
#include "Draw.h"
#include <iostream>

void drawScore(unsigned font, int p1score, int p2score)
{
	char buffer[64] = { 0 };
	sprintf_s(buffer, "%d", p1score);
	sfw::drawString(font, buffer, 650, 600, 40, 40);

	sprintf_s(buffer, "%d", p2score);
	sfw::drawString(font, buffer, 100, 600, 40, 40);
}

void drawWin(unsigned font)
{
	sfw::drawString(font, "Game Over PLayer 1 Wins!", 160, 600, 20, 20);
	getchar();
}

void drawWin2(unsigned font)
{
	sfw::drawString(font, "Game Over Player 2 Wins!", 160, 600, 20, 20);
	
}