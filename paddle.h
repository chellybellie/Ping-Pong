#pragma once

class Ball;

class Player
{
private:

	unsigned int color;
	float speed;
	char up, down;
	float Y = 10, X;
	float size = 50;
	int score = 0;
public:



	float getTop() { return Y + size; }
	float getBot() { return Y; }
	float getX()   { return X; }

	void createPaddle(float X, char up, char down, unsigned int color, int size, float speed);

	void drawPaddle();

	void updatePaddle();

	int getScore() { return score; }

	void doScore() { score++; }
};

