#include "sfwdraw.h"
#include <random>
#include <time.h>
#include "paddle.h"
#include "ball.h"
#include "Draw.h"




void main()
{
	sfw::initContext(800, 600, "Ping Pong");
	sfw::setBackgroundColor(0x9932CCFF);

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	Player p1 = createPaddle(10,'W','S', WHITE, 100, 8);
	Player p2 = createPaddle(790,'I','K', RED, 100, 8);
	Ball b1 = createBall(300, 300, 1, 1, 15, WHITE);


	bool GameOver = false;
	while (sfw::stepContext())
	{
		if (!GameOver)
		{
			updatePaddle(p1);
			updatePaddle(p2);
			updateball(b1, p1, p2);
			Collision(b1, p1, p2);
		}

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
