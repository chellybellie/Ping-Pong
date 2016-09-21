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
	int winner = -1;
	unsigned snake;
	HorzWall hwalls[2][15];
	VertWall vwalls[2][15];



public:
	int getwinner() { return winner; }
	void GameState::CreateGameState(int font, unsigned snake);
	void GameState::updateGameState();
	void GameState::drawGameState();

	menueState GameState::nextAppState();

	bool isGameOver() { return GameOver; }
};

