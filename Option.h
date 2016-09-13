#pragma once
#include "menustate.h"

class option
{
private:
	int d;
	float timer;
	int select;
public:
	void init(int a_font);
	void play();
	void draw();
	void step();

	menueState next();
};