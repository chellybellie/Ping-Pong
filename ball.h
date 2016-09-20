#pragma once

// forward declaration
class Player;

struct HorzWall
{
	float x, y;
	float size;
	unsigned int color;
	float timer;
	void draw();
};

struct VertWall
{
	float x, y;
	float size;
	unsigned int color;
	float timer;
	void draw();
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
	char up, down, left, right;
	int level;

public:
	int getLevel() { return level; }
	int gethealth() { return health; }
	void createBall(float x, float y,char up, char down, char left, char right, float Radius, unsigned int color, float health, int font);

	void updateball(Player &p1, Player &p2, Player &p3);

	void drawball();

	void updateWalls( HorzWall wallH[], int hCount,  VertWall wallV[], int vCount);
	bool HwallCollide(HorzWall &wall);
	bool VwallCollide( VertWall &wall);
	void drawHealth();
};