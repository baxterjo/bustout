//GameWorld.h
//Jordan Baxter

#pragma once
#include "ofMain.h"


class Brick;
class Ball;
class Paddle;

enum Game_State {
	PLAY,
	WIN,
	LOSE
};


class GameWorld {
public:
	GameWorld();
	void fetchLevelLayout(string file1, string file2, string file3);
	void nextLevel();
	void changeState(enum Game_State gs);
	void draw();
	void resize();
	void loseLife();
	enum Game_State getState();
	bool noBricks();
	bool noLives();
	//Brick* generateBricks();
	//Ball* generateBalls();

private:


	char levelLayout1[4][12];
	char levelLayout2[4][12];
	char levelLayout3[4][12];
	enum Game_State gameState;
	int level;
	int lives;

	
};