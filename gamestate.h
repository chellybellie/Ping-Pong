#pragma once
#include "sfwdraw.h"
#include "Draw.h"
#include "paddle.h"
#include "ball.h"

#include "menustate.h"

class GameState
{
private:
	Player p1, p2, p3;
	Ball b1;
	unsigned font;
	bool GameOver;

	HorzWall hwalls[2][5];
	VertWall vwalls[2][5];


public:
	void GameState::CreateGameState(int font);
	void GameState::updateGameState();
	void GameState::drawGameState();

	menueState GameState::nextAppState();

	bool isGameOver() { return GameOver; }
};

