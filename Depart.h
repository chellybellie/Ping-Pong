#pragma once
#include "menustate.h"

class depart
{
private:
	int d;
	float timer;
	int w;
public:
	void init(int a_font);
	void play(int w);
	void draw();
	void step();

	menueState next();
};