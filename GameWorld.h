//GameWorld.h
//Jordan Baxter

#pragma once
#include "ofApp.h"

class Brick;
class Ball;
class Paddle;


class GameWorld {
public:
	GameWorld();
	void fetchLevelLayout(string file1, string file2, string file3);
	Brick* generateBricks();
	Ball* generateBalls();
	void nextLevel();
	void changeState(const int state);
	void draw();
	void getState();
	void resize();

private:


	char levelLayout1[4][12];
	char levelLayout2[4][12];
	char levelLayout3[4][12];
	enum Game_State gameState;
	int level;

};