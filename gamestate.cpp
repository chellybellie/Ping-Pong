#include <iostream>
#include "gamestate.h"
#include "ball.h"
#include "paddle.h"


void GameState:: CreateGameState(int a_font)
{
	vwalls[0][0] = { 10, 10, 100 , BLACK };
	vwalls[0][1] = { 370,10,250  , BLACK };
	vwalls[0][2] = { 270,110,250 , BLACK };
	vwalls[0][3] = { 770,260,300 , BLACK };
	vwalls[0][4] = { 670,360,200 , BLACK };

	hwalls[0][0] = { 10,10,360   , BLACK };
	hwalls[0][1] = { 10,110,260  , BLACK };
	hwalls[0][2] = { 270,360,400 , BLACK };
	hwalls[0][3] = { 370,260,400 , BLACK };
	hwalls[0][4] = { 670,560,100 , GREEN }; // hits this line causes it to go to "lvl 2"


	vwalls[1][0] = { 10, 10, 100 , BLACK };
	vwalls[1][1] = { 370,10, 250 , GREEN };
	vwalls[1][2] = { 270,110,250 , BLACK };
	vwalls[1][3] = { 770,260,300 , BLACK };
	vwalls[1][4] = { 670,360,200 , BLACK };

	hwalls[1][0] = { 10,10,360   , BLACK };
	hwalls[1][1] = { 10,110,260  , BLACK };
	hwalls[1][2] = { 270,360,400 , BLACK };
	hwalls[1][3] = { 370,260,400 , BLACK };
	hwalls[1][4] = { 670,560,100 , BLACK }; // hits this line causes it to go to "lvl 2"

	p1.createPaddle(0,  10 , 600, 10,  WHITE, 600, 8);
	p2.createPaddle(0,  790, 600, 790, BLACK, 600, 8);
	p3.createPaddle(40, 0  , 40 , 790, RED,   600, 8);

	b1.createBall(40, 40, 'W', 'S', 'A', 'D', 15, WHITE, 100, a_font);

	font = a_font;
	GameOver = false;

	

}

void GameState::updateGameState()
{
	

	//p1.updatePaddle();
	//p2.updatePaddle();
	//p3.updatePaddle();
	//b1.updateball(p1, p2, p3);
	
	b1.updateWalls(hwalls[b1.getLevel()], 5, vwalls[b1.getLevel()], 5);

	if (b1.gethealth() <= 0)
	{
		GameOver = true;
	
	}

	//if (p2.getScore() >= 10)
	//{
	//	GameOver = true;
	//	

	//}

}

void GameState::drawGameState()
{
	b1.drawHealth();
	
	b1.drawball();

	for (int i = 0; i < 5; ++i)
		hwalls[b1.getLevel()][i].draw();

	for (int i = 0; i < 5; ++i)
		vwalls[b1.getLevel()][i].draw();
}

menueState GameState::nextAppState()
{
	if (GameOver)
		return Enter_Depart;
	else return Game;
}
