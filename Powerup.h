//Powerup.h
//Jordan Baxter

#pragma once
class GameWorld;
class Paddle;
class Brick;
class Ball;

class Powerup {
public:
	Powerup();
	void draw();
	void spawn();
	void move();
	void despawn();
private:
	float x;
	float y;
	float r;
	float vy;
	bool longPaddle;
	bool superBall;
};