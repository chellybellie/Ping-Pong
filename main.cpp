
#include "sfwdraw.h"
#include <random>

struct Ball
{
	float x = 0;
	float y = 0;
	float VelX;
	float VelY;
	float Radius;
	unsigned int color;

};


Ball createBall(float x, float y, float VelX, float VelY, float Radius, unsigned int color)
{
	Ball retval;
	retval.x      = x;
	retval.y      = y;
	retval.VelX   = rand() % 10;
	retval.VelY   = rand() % 10;
	retval.Radius = Radius;
	retval.color = color;
	return retval;
}

struct Player
{
	float Y = 10, X;
	float size = 50;
	unsigned int color;
	float speed;
	char up, down;
	int score = 0;
};


Player createPaddle(float X, char up, char down, unsigned int color, int size, float speed)
{
	Player retval;
	retval.up    = up;
	retval.down  = down;
	retval.X     = X;
	retval.color = color;
	retval.size  = size;
	retval.speed = speed;

	return retval;
}


void updateball(Ball &b)
{

	b.x += b.VelX;
	b.y += b.VelY;

	if (b.y > 600 - b.Radius)
	{
		b.y = 600 - b.Radius;
		b.VelY *= -1;
	}
	if (b.y < 0)
	{
		b.y = 0;
		b.VelY *= -1;
	}
	if (b.x < 0 || b.x > 800)
	{
		b.x = 400;
	}
}


void updatePaddle(Player &p)
{
	// also make sure that if Y < 0, that Y stops at 0
	if (sfw::getKey(p.up))
	{
		p.Y += p.speed;
	}
	if (sfw::getKey(p.down))
	{
		p.Y -= p.speed;
	}

	if (p.Y > 600 - p.size) p.Y = 600 - p.size;
	if(p.Y  <   0) p.Y = 0;
}


void Collision(Ball &b, Player &p1,  Player &p2)
{
	if (b.x - b.Radius < p1.X && b.y > p1.Y && b.y < ( p1.Y + p1.size))
	{
		b.VelX *= -1;
		b.x = p1.X + b.Radius;
	}
	if (b.x + b.Radius > p2.X && b.y > p2.Y && b.y < (p2.Y + p2.size))
	{
		b.VelX *= -1;
		b.x = p2.X - b.Radius;
	}
	if (b.x < 0)
	{
		p1.score++;
		
		printf("%d to %d \n", p1.score, p2.score);
		b.x = 30;
		b.y = 300;
		b.VelX *= -1;
	}
	if (b.x > 800)
	{
		p2.score++;

		printf("%d to %d \n", p1.score, p2.score);
		b.x = 770;
		b.y = 300;
		b.VelX *= -1;

	}
}


void drawball(const Ball &b)
{
	sfw::drawCircle(b.x, b.y, b.Radius, 12, b.color);


}



void drawPaddle(const Player &p)
{
	sfw::drawLine(p.X, p.size + p.Y, p.X, p.Y, p.color);
}


void drawScore(unsigned font, int p1score, int p2score)
{
	char buffer[64] = { 0 };
	sprintf_s(buffer, "%d", p1score);
	sfw::drawString(font, buffer, 650, 600, 40, 40);

	sprintf_s(buffer, "%d", p2score);
	sfw::drawString(font, buffer, 100, 600, 40, 40);
}

void drawWin(unsigned font)
{
	sfw::drawString(font, "Game Over PLayer 1 Wins!", 160, 600, 20, 20);
}

void drawWin2(unsigned font)
{
	sfw::drawString(font, "Game Over Player 2 Wins!", 160, 600, 20, 20);
}
void main()
{
	sfw::initContext(800, 600, "Ping Pong");
	sfw::setBackgroundColor(0x9932CCFF);

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	Player p1 = createPaddle(10,'W','S', WHITE, 100, 8);
	Player p2 = createPaddle(790,'I','K', RED, 100, 8);
	Ball b1 = createBall(300, 300, 1, 1, 15, WHITE);


	bool GameOver = false;
	while (sfw::stepContext())
	{
		if (!GameOver)
		{
			updatePaddle(p1);
			updatePaddle(p2);
			updateball(b1);
			Collision(b1, p1, p2);
		}

		drawScore(d, p1.score, p2.score);

		if (p1.score >= 10)
		{
			GameOver = true;
			drawWin(d);
		}

		if (p2.score >= 10)
		{
			GameOver = true;
			drawWin2(d);

		}
		drawPaddle(p1);
		drawPaddle(p2);
		drawball(b1);
	}
	sfw::termContext();

}
