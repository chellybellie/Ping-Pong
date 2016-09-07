#pragma once
#include "paddle.h"
#include "ball.h"

struct GameState
{
	Player p1, p2;
	int score;

};

GameState(createGameState)
{
	Player p1 = createPaddle(10, 'W', 'S', WHITE, 100, 8);
	Player p2 = createPaddle(790, 'I', 'K', RED, 100, 8);
	Ball b1 = createBall(300, 300, 1, 1, 15, WHITE);

}

void updateGameState(GameState &gs)
{
	updatePaddle(p1);
	updatePaddle(p2);
	updateball(b1, p1, p2);
	Collision(b1, p1, p2);

}

void drawGameState(const GameState & gs)
{

}
