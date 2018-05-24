//Ball.h
//Jordan Baxter

#pragma once
#include "ofMain.h"

class GameWorld;
class Paddle;
class Brick;

class Ball {
public:
	Ball();
	void move();
	void draw();
	void bounceWall();
	void bounceCeiling();
	void bounceBrick();
	void bouncePaddle();
	bool hitPaddle();
	bool hitWall();
	bool hitCeiling();
	bool hitFloor();
	bool hitBrick();

private:
	float x;
	float y;
	float r;
	float v;
	float s;
	ofColor color;
	

};