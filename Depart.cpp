#include "Depart.h"
#include "menustate.h"
#include "sfwdraw.h"
#include <iostream>


void depart::init(int a_font)
{
	d = a_font;
}

void depart::play(int a_getwinner)
{
	timer = 5.f;
	w = a_getwinner;
}

void depart::draw()
{
	char buffer[64];
	
	
	if (w == 0)

	{
		sprintf_s(buffer, "You lose!");
		sfw::drawString(d, buffer, 100, 400, 60, 60);
		sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
		if (timer <= 3)
		{
			sfw::drawString(d, "GIT GUD", 300, 300, 20, 20);
			sfw::drawString(d, "returning to screen", 220, 250, 20, 20);
		}
	}
	else
	{
		sprintf_s(buffer, "You a winner!");
		sfw::drawString(d, buffer, 80, 400, 60, 60);
		sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
		if (timer <= 3)
		{
			sfw::drawString(d, "Great Job!!", 300, 300, 20, 20);
			sfw::drawString(d, "returning to screen", 200, 250, 20, 20);
		}
	}
}

void depart::step()
{
	timer -= sfw::getDeltaTime();
}

menueState depart::next()
{
	if (timer < 0)
		return Enter_Option;

	return Depart;
}
