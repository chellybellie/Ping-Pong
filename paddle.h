#pragma once

class Ball;

class Player
{
private:

	unsigned int color;
	float speed;
	char up, down;
	float X, Y, X2, Y2;
	float size = 50;
	int score = 0;
public:



	float getTop() { return Y + size; }
	float getBot() { return Y; }
	float getX()   { return X; }

	void createPaddle(float X, float Y, float X2, float Y2, unsigned int color, int size, float speed);

	void drawPaddle();

	void updatePaddle();

	int getScore() { return score; }

	void doScore() { score++; }
};



