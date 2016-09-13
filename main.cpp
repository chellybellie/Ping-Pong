#include "sfwdraw.h"
#include <random>
#include <time.h>
#include "paddle.h"
#include "ball.h"
#include "Draw.h"
#include "gamestate.h"
#include "main.h"



void main()
{
	sfw::initContext(800, 600, "Ping Pong");
	sfw::setBackgroundColor(0x9932CCFF);
	
	int d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	GameState gs;
	//MenuState ms;

	gs.CreateGameState(d);

	while (sfw::stepContext())
	{
		//switch (CURRENT)
		//{
		//case 0: 
		//	ms.update();
		//	ms.draw();
		//	break;
		//case 1:
		//	gs.updateGameState();
		//	gs.drawGameState();
		//}

		if (gs.isGameOver() == false)
		{
			gs.updateGameState();

			gs.drawGameState();
		}
		else sfw::drawString(d, "Try Again! \n", 310, 300, 20, 20, 0, 0, YELLOW);
	}
		
	sfw::termContext();

}