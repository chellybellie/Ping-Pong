#include <iostream>
#include "gamestate.h"
#include "ball.h"
#include "paddle.h"


void GameState:: CreateGameState(int a_font)
{
	

	p1.createPaddle(10, 'W', 'S', WHITE, 100, 8);
	p2.createPaddle(790, 'I', 'K', RED, 100, 8);

	b1.createBall(300, 300, 15, WHITE);

	font = a_font;
	GameOver = false;

}

void GameState::updateGameState()
{
	

	p1.updatePaddle();
	p2.updatePaddle();
	b1.updateball(p1, p2);
	
	if (p1.getScore() >= 10)
	{
		GameOver = true;
	
	}

	if (p2.getScore() >= 10)
	{
		GameOver = true;
		

	}

}

void GameState::drawGameState()
{
	drawScore(font, p1.getScore(), p2.getScore());

	if (p1.getScore() >= 10)
	{
		
		drawWin(font);
	}

	if (p2.getScore() >= 10)
	{
		
		drawWin2(font);

	}

	p1.drawPaddle();
	p2.drawPaddle();
	b1.drawball();
}

menueState GameState::nextAppState()
{
	if (GameOver)
		return Enter_Depart;
	else return Game;
}
