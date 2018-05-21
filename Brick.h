//Brick.h
//Jordan Baxter

#pragma once

class GameWorld;
class Ball;
class Paddle;

class Brick {
public:
	Brick();
	void damage();
	void draw();
private:
	int strength;
	bool powerup;
};