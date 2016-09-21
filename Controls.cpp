#include "Controls.h"
#include "menustate.h"
#include "sfwdraw.h"
#include <iostream>


void control::init(int a_font)
{
	d = a_font;
}

void control::play()
{
	
}

void control::draw()
{
	char buffer[64];

		sprintf_s(buffer, "To control your Snake!");
			sfw::drawString(d, buffer,100, 400, 30, 30);
		sprintf_s(buffer, "'W' To go Up ");
			sfw::drawString(d, buffer, 205, 300, 30, 20);
		sprintf_s(buffer, "'S' To go Down ");
			sfw::drawString(d, buffer, 205, 250, 30, 20);
		sprintf_s(buffer, "'A' To go Left ");
			sfw::drawString(d, buffer, 205, 200, 30, 20);
		sprintf_s(buffer, "'D' To go Right ");
			sfw::drawString(d, buffer, 205, 150, 30, 20);
			sprintf_s(buffer, "Press SPACE to Exit");
			sfw::drawString(d, buffer, 145, 50, 30, 30);
}

void control::step()
{
	
}

menueState control::next()
{
	if (sfw::getKey(' '))
	{
		 return Enter_Option;
	}
	

	return Controls;
}