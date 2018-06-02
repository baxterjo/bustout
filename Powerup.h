//Powerup.h
//Jordan Baxter

#pragma once
#include "ofMain.h"
class GameWorld;
class Paddle;
class Brick;
class Ball;
enum Type {
DOUBLE_POINTS,
SUPER_BALL,
LONG_PADDLE
};


class Powerup {
public:
	Powerup();
	void draw();
	void spawn(ofVec2f position);
	void move();
	void miss();
	bool hitPaddle(Paddle* paddle);
	void doIt(Paddle* &paddle, GameWorld* &gameWorld, Ball* &ball);

private:
	ofVec2f position;
	ofVec2f velocity;
	ofRectangle box;
	ofColor color;
	enum Type type;
};