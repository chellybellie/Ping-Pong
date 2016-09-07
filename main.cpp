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

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	GameSate gs = createGameState();

	


	bool GameOver = false;
	while (sfw::stepContext())
	{
		if (!GameOver)
		

		drawScore(d, p1.score, p2.score);

		if (p1.score >= 10)
		{
			GameOver = true;
			drawWin(d);
		}

		if (p2.score >= 10)
		{
			GameOver = true;
			drawWin2(d);

		}
		drawPaddle(p1);
		drawPaddle(p2);
		drawball(b1);
	}
	sfw::termContext();

}
