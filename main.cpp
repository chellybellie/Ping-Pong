#include "sfwdraw.h"
#include <random>
#include <time.h>
#include "paddle.h"
#include "ball.h"
#include "Draw.h"
#include "gamestate.h"





void main()
{
	sfw::initContext(800, 600, "Ping Pong");
	sfw::setBackgroundColor(0x9932CCFF);
	
	GameState gs = CreateGameState();


	while (sfw::stepContext())
	{
		updateGameState(gs);

		drawGameState(gs);
	}
	sfw::termContext();

}
