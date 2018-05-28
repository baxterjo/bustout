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
	void spawn();
	void move();
	void draw();
	void bounceWall();
	void bounceCeiling();
	void bounceBrick();
	void bouncePaddle(Paddle* paddle);
	void damageBrick();
	bool hitPaddle(Paddle* paddle);
	bool hitWall();
	bool hitCeiling();
	bool hitFloor();
	bool hitBrick(vector<Brick*> bricks);


private:
	ofVec2f position;
	ofVec2f velocity;
	float r;
	float s;
	ofColor color;
	bool superBall;

};