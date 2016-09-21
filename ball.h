#pragma once

// forward declaration
class Player;

enum WALL_FLAG { BROKEN, NORMAL, BREAKABLE, FAKE, VICTORY };

struct HorzWall
{
	float x, y;
	float size;
	unsigned int color;
	WALL_FLAG flag;
	float timer;
	void draw();
};

struct VertWall
{
	float x, y;
	float size;
	unsigned int color;
	WALL_FLAG flag; // 0 broken wall, 1 normal wall, 2 means breakable wall, 3 means fake wall, 4 for victory wall
	float timer;
	void draw();

	// How do we make some walls have specialized logic?

};



class Ball
{
private:
	float x;
	float y;
	float VelX;
	float VelY;
	float accX;
	float accY;
	float Radius;
	float speed;
	int font;
	int health = 100;
	unsigned int color;
	unsigned snake;
	char up, down, left, right;
	int level;
	

public:
	int getsnake() { return snake; }
	int getLevel() { return level; }
	int gethealth() { return health; }
	void createBall(float x, float y, char up, char down, char left, char right, float Radius, unsigned int color, float health, int font, unsigned snake, float LevelTimer);
	float LevelTimer;
	void updateball(Player &p1, Player &p2, Player &p3);
	void levelTimer();
	void drawball();

	void updateWalls( HorzWall wallH[], int hCount,  VertWall wallV[], int vCount);
	bool HwallCollide(HorzWall &wall);
	bool VwallCollide( VertWall &wall);
	void drawHealth();
};