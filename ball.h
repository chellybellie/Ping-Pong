#pragma once

class Player;

class Ball
{
private:
	float x = 0;
	float y = 0;
	float VelX;
	float VelY;
	float Radius;
	unsigned int color;

public:
	void createBall(float x, float y, float Radius, unsigned int color);

	void updateball(Player &p1, Player &p2);

	void drawball();
};