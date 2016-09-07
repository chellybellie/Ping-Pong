#pragma once

struct Player;

struct Ball
{
	float x = 0;
	float y = 0;
	float VelX;
	float VelY;
	float Radius;
	unsigned int color;

};
Ball createBall(float x, float y, float VelX, float VelY, float Radius, unsigned int color);

void updateball(Ball &b, Player &p1, Player &p2);

void drawball(const Ball &b);
