#include "Splash.h"
#include "menustate.h"
#include "sfwdraw.h"
#include <iostream>


void splash::init(int a_font)
{
	d = a_font;
}

void splash::play() { timer = 3.f; }

void splash::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Loading..");
	sfw::drawString(d, buffer, 100, 100, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.f), 80);
	if (timer <= 1)
		sfw::drawString(d, "Almost Done.", 300, 300, 20, 20);
}

void splash::step()
{
	timer -= sfw::getDeltaTime();
}

menueState splash::next()
{
	if (timer < 0)
		return Enter_Option;
	return Splash;
}

