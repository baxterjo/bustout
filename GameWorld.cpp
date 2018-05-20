//GameWorld.cpp
//Jordan Baxter

#include "GameWorld.h"
#include "Ball.h"
#include "Brick.h"
#include "ofApp.h"

GameWorld::GameWorld() {
	this->gameState = PLAY;
	this->level = 1;
}

void GameWorld::fetchLevelLayout(string file1, string file2, string file3) {
	fstream level1;
	fstream level2;
	fstream level3;

	level1.open(file1);
	level2.open(file2);
	level3.open(file3);

	for (int i = 0; i < 4; ++i) {
		//TODO
	}
}

Brick* GameWorld::generateBricks() {

}