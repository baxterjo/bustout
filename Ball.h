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
	ofVec2f position;
	ofVec2f velocity;
	float r;
	float s;
	ofColor color;
	

};