#pragma once
#include "sfwdraw.h"
#include "Draw.h"
#include "paddle.h"
#include "ball.h"



struct GameState
{
	Player p1, p2;
	int score;
	Ball b1;
	unsigned f, d, r, u;
	unsigned font;



};

GameState CreateGameState()
{
	GameState gs;

	gs.p1 = createPaddle(10, 'W', 'S', WHITE, 100, 8);
	gs.p2 = createPaddle(790, 'I', 'K', RED, 100, 8);
	gs.b1 = createBall(300, 300, 1, 1, 15, WHITE);

	gs.f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	gs.d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	gs.r = sfw::loadTextureMap("./res/background.jpg");
	gs.u = sfw::loadTextureMap("./res/crosshair.png");
	return gs;
}

void updateGameState(GameState &gs)
{
	updatePaddle(gs.p1);
	updatePaddle(gs.p2);
	updateball(gs.b1, gs.p1, gs.p2);
	Collision(gs.b1, gs.p1, gs.p2);

}

void drawGameState(const GameState &gs)
{
	bool GameOver = false;

	//if (!GameOver)


		drawScore(gs.font, gs.p1.score, gs.p2.score);

	if (gs.p1.score >= 10)
	{
		GameOver = true;
		drawWin(gs.font);
	}

	if (gs.p2.score >= 10)
	{
		GameOver = true;
		drawWin2(gs.font);

	}

	drawPaddle(gs.p1);
	drawPaddle(gs.p2);
	drawball(gs.b1);
}
