
#include "Splash.h"
#include "Option.h"
#include "sfwdraw.h"
#include <iostream>
void option::init(int a_font)
{
	d = a_font;
}

void option::play() { select = 0; timer = 3.f; }

void option::draw()
{

	sfw::drawString(d, " Press 'P' to Start New Game", 100, 100, 20, 20, 0, 0, select == 1 ? BLACK : GREEN);

	sfw::drawString(d, " Press 'O' To Go To Options ", 100, 300, 20, 20, 0, 0, select == 0 ? BLACK : GREEN);
}

void option::step()
{
	timer -= sfw::getDeltaTime();
	if (timer < 0)
	{
		timer = 1.f;
		select = 1 - select;
	}
}

menueState option::next()
{
	if (sfw::getKey('O'))
	{
		return Enter_Controls;
	}
	if (sfw::getKey('P'))
	{
		return Enter_Game;
	}
	if (sfw::getKey(KEY_ENTER))
	{
		if (select == 0)
			return Enter_Depart;
		if (select == 1)
			return Enter_Game;
	}

	return Option;
}