#include "Depart.h"
#include "menustate.h"
#include "sfwdraw.h"
#include <iostream>

void depart::init(int a_font)
{
	d = a_font;
}

void depart::play()
{
	timer = 5.f;
}

void depart::draw()
{
	char buffer[64];
	sprintf_s(buffer, "You Win!");
	sfw::drawString(d, buffer, 100, 100, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 5.f), 80);
	if (timer <= 4)
		sfw::drawString(d, "CONGRATZ", 300, 300, 20, 20);
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
