#pragma once

struct Ball;

struct Player
{
	float Y = 10, X;
	float size = 50;
	unsigned int color;
	float speed;
	char up, down;
	int score = 0;
};

Player createPaddle(float X, char up, char down, unsigned int color, int size, float speed);

void drawPaddle(const Player &p);

void updatePaddle(Player &p);

void Collision(Ball &b, Player &p1, Player &p2);


