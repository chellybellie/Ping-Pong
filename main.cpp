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



void main()
{
	sfw::initContext(800, 600, "Ping Pong");
	sfw::setBackgroundColor(0x9932CCFF);
	
	int d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	GameState gs;
	splash splash;
	depart depart;
	option option;

	splash.init(d);
	depart.init(d);
	option.init(d);

	menueState state = Enter_Splash;

	gs.CreateGameState(d);

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

		case Enter_Splash:
			splash.play();
		case Splash:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

		case Enter_Depart:
			depart.play();
		case Depart:
			depart.step();
			depart.draw();
			state = depart.next();
			break;
		

		case Enter_Game:
			//gs.isGameOver();
			gs.CreateGameState(d);
		case Game:
			gs.updateGameState();
			gs.drawGameState();
			state = gs.nextAppState();
		}

	}
		
	sfw::termContext();

}