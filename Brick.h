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
	void damage();
	void draw();
	void godHand();
	ofColor setColor(char c);
	int setStrength(char c);
	bool getExists();
	ofRectangle getStructure();
	float getX();
	float getY();
	float getW();
	float getH();
	void reset();

private:
	ofRectangle box;
	ofColor color;
	ofColor startColor;
	int strength;
	int startStrength;
	bool powerup;
	bool exists;
};