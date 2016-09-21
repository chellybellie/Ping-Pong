#include "sfwdraw.h"
#include <random>
#include <time.h>
#include "paddle.h"
#include "ball.h"
#include "Draw.h"
#include "gamestate.h"
#include "main.h"
#include "Splash.h"
#include "menustate.h"
#include "Depart.h"
#include "Option.h"
#include "Controls.h"



void main()
{
	sfw::initContext(800, 600, "Snake Maze");
	sfw::setBackgroundColor(0x9932CCFF);
	
	int d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned snake = sfw::loadTextureMap("./res/snake.png");

	GameState gs;
	splash splash;
	depart depart;
	option option;
	control control;

	control.init(d);
	splash.init(d);
	depart.init(d);
	option.init(d);

	menueState state = Enter_Splash;

	gs.CreateGameState(d, snake);

	while (sfw::stepContext())
	{
		switch (state)
		{
		case Enter_Option:
			option.play();
		case Option:
			option.step();
			option.draw();
			state = option.next();
			break;

		case Enter_Controls:
			control.play();
		case Controls:
			control.step();
			control.draw();
			state = control.next();
			break;

		case Enter_Splash:
			splash.play();
		case Splash:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

		case Enter_Depart:
			depart.play(gs.getwinner());
		case Depart:
			depart.step();
			depart.draw();
			state = depart.next();
			break;
		

		case Enter_Game:
			
			gs.CreateGameState(d, snake);
		case Game:
			gs.updateGameState();
			gs.drawGameState();
			state = gs.nextAppState();
		}

	}
		
	sfw::termContext();

}