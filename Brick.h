//Brick.h
//Jordan Baxter

#pragma once
#include "ofMain.h"

class GameWorld;
class Ball;
class Paddle;

class Brick {
public:
	Brick(float y, float x, char c);
	void generateBricks(vector<Brick*> bricks, GameWorld* gameWorld);
	void damage();
	void draw();
	ofColor setColor(char c);
	int setStrength(char c);
	bool getExists();
private:
	float x;
	float y;
	float w;
	float h;
	ofColor color;
	int strength;
	bool powerup;
	bool exists;
};