#pragma once
#include "sfwdraw.h"
#include "Draw.h"
#include "paddle.h"
#include "ball.h"

#include "menustate.h"

class GameState
{
private:
	Player p1, p2;
	int score;
	Ball b1;
	unsigned font;
	bool GameOver;

public:
	void GameState::CreateGameState(int font);
	void GameState::updateGameState();
	void GameState::drawGameState();

	menueState GameState::nextAppState();

	bool isGameOver() { return GameOver; }
};

