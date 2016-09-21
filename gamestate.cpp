#include <iostream>
#include "gamestate.h"
#include "ball.h"
#include "paddle.h"



void GameState:: CreateGameState(int a_font, unsigned a_snake)
{
	vwalls[0][0] = { 10, 10, 100 , BLACK, NORMAL, 0 }; 
	vwalls[0][1] = { 370,10,250  , BLACK, NORMAL, 0 };
	vwalls[0][2] = { 270,110,250 , BLACK, NORMAL, 0 };
	vwalls[0][3] = { 770,260,300 , BLACK, NORMAL, 0 };
	vwalls[0][4] = { 670,360,200 , BLACK, NORMAL, 0 };
	vwalls[0][5] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][6] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][7] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][8] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][9] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][10] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][11] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][12] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][13] = { 800,800,800 , BLACK, NORMAL, 0 };
	vwalls[0][41] = { 800,800,800 , BLACK, NORMAL, 0 };

	hwalls[0][0] = { 10,10,360   , BLACK, NORMAL, 0 };
	hwalls[0][1] = { 10,110,260  , BLACK, NORMAL, 0 };
	hwalls[0][2] = { 270,360,400 , BLACK, NORMAL, 0 };
	hwalls[0][3] = { 370,260,400 , BLACK, NORMAL, 0 };
	hwalls[0][4] = { 670,560,100 , BLACK, VICTORY, 0};
	hwalls[0][5] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][6] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][7] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][8] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][9] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][10] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][11] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][12] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][13] = { 800,800,800 , BLACK, NORMAL, 0 };
	hwalls[0][14] = { 800,800,800 , BLACK, NORMAL, 0 };// hits this line causes it to go to "lvl 2"


	vwalls[1][0] = { 10, 10, 100 , BLACK, NORMAL, 0 }; // start
	vwalls[1][1] = { 260,10, 200 , BLACK, NORMAL, 0 };
	vwalls[1][2] = { 160,110,100 , BLACK, NORMAL, 0 };
	vwalls[1][3] = { 360,210,50 ,  BLACK, NORMAL, 0 };
	vwalls[1][4] = { 360,260,100 , BLACK,BREAKABLE,0}; // FAKE WALL?
	vwalls[1][5] = { 60,210,200 ,  BLACK, NORMAL, 0 };
	vwalls[1][6] = { 360,360,50 ,  BLACK, NORMAL, 0 };
	vwalls[1][7] = { 860,860,800 , GREEN, NORMAL, 0 };// DID NOT USE
	vwalls[1][8] = { 860,860,800 , BLUE,  NORMAL, 0 };// DID NOT USE
	vwalls[1][9] = { 460,360,100 , BLACK, NORMAL, 0 };
	vwalls[1][10] = { 160,410,100 ,BLACK, NORMAL, 0 };
	vwalls[1][11] = { 260,410,100 ,BLACK, NORMAL, 0 };
	vwalls[1][12] = { 260,260,100 ,BLACK, NORMAL, 0 };// WALL IN MIDDLE OF BOX
	vwalls[1][13] = { 560,260,200 ,BLACK, NORMAL, 0 };
	vwalls[1][14] = { 210,110,100 ,BLACK , NORMAL, 0};

	hwalls[1][0] = { 10,10,  250  ,BLACK, NORMAL, 0 };
	hwalls[1][1] = { 10,110, 150 , BLACK, NORMAL, 0 };
	hwalls[1][2] = { 260,210,100 , BLACK, NORMAL, 0 };
	hwalls[1][3] = { 60,210,100 ,  BLACK, NORMAL, 0 };
	hwalls[1][4] = { 60,410,100 ,  BLACK, NORMAL, 0 }; // top of box
	hwalls[1][5] = {160,410,100 ,  BLACK, FAKE,   0 };
	hwalls[1][6] = { 260,410,100 , BLACK, NORMAL, 0 };
	hwalls[1][7] = { 360,260,200 , BLACK, NORMAL, 0 }; 
	hwalls[1][8] = { 360,360,100 , BLACK, NORMAL, 0 };
	hwalls[1][9] = { 460,460,100 , BLACK, VICTORY,0 };
	hwalls[1][10] = { 160,410,100, BLACK, FAKE,   0 };
	hwalls[1][11] = { 160,310,100, BLACK, NORMAL, 0 }; // WALL IN MIDDLE OF BOX
	hwalls[1][12] = { 160,510,100, BLACK, NORMAL, 0 };
	hwalls[1][13] = { 660,860,100, BLACK ,NORMAL, 0 };
	hwalls[1][14] = { 800,800,800, BLACK ,NORMAL, 0 };


	p1.createPaddle(0,  10 , 600, 10,  WHITE, 600, 8);
	p2.createPaddle(0,  790, 600, 790, BLACK, 600, 8);
	p3.createPaddle(40, 0  , 40 , 790, RED,   600, 8);

	b1.createBall(40, 40, 'W', 'S', 'A', 'D', 15, WHITE, 100, a_font, a_snake, 10.f);

	font = a_font;
	snake = a_snake;
	GameOver = false;
	
	

}

void GameState::updateGameState()
{
	

	//p1.updatePaddle();
	//p2.updatePaddle();
	//p3.updatePaddle();
	//b1.updateball(p1, p2, p3);
	b1.levelTimer();
	b1.updateWalls(hwalls[b1.getLevel()], 15, vwalls[b1.getLevel()], 15);
	
	if (b1.gethealth() <= 0 || b1.LevelTimer <=0)
	{	
		winner = 0;
		GameOver = true;
	
	
	} 
	if (b1.getLevel() >=2)
	{
		winner = 1;
		GameOver = true;
		
	}

}

void GameState::drawGameState()
{
	
	
	b1.drawHealth();
	b1.drawball();

	for (int i = 0; i < 15; ++i)
		hwalls[b1.getLevel()][i].draw();

	for (int i = 0; i < 15; ++i)
		vwalls[b1.getLevel()][i].draw();
}

menueState GameState::nextAppState()
{
	if (GameOver)
		return Enter_Depart;
	else return Game;
}
