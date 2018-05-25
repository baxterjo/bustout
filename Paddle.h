//Paddle.h
//Jordan Baxter

#pragma once

class GameWorld;
class Brick;
class Ball;

class Paddle {
public:
	Paddle();
	void draw();
	void move(int x);


private:
	float w;
	float h;
	float x;
	float y;
	bool big;
	bool laser;
	bool sticky;
};