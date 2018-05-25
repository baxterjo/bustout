//GameWorld.cpp
//Jordan Baxter

#include "GameWorld.h"
#include "Ball.h"
#include "Brick.h"
#include "ofMain.h"

GameWorld::GameWorld() {
	this->gameState = PLAY;
	this->level = 1;
	this->score = 0;
}

void GameWorld::fetchLevelLayout(string file1, string file2, string file3) {
	
	ofBuffer level = ofBufferFromFile(file1);
	vector<string> lines;
	for (auto line: level.getLines()) {
		lines.push_back(line);
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 12; ++j) {
			this->levelLayout1[i][j] = lines.at(i).at(j);
			cout << levelLayout1[i][j];
		}
		cout << "\n";
	}

	lines.clear();
	level = ofBufferFromFile(file2);

	for (auto line : level.getLines()) {
		lines.push_back(line);
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 12; ++j) {
			this->levelLayout2[i][j] = lines.at(i).at(j);
			cout << levelLayout2[i][j];
		}
		cout << "\n";
	}

	lines.clear();
	level = ofBufferFromFile(file3);

	for (auto line : level.getLines()) {
		lines.push_back(line);
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 12; ++j) {
			this->levelLayout3[i][j] = lines.at(i).at(j);
			cout << levelLayout3[i][j];
		}
		cout << "\n";
	}
}

void GameWorld::nextLevel() {
	this->level += 1;
}
void GameWorld::changeState(enum Game_State gs) {
	this->gameState = gs;
}
void GameWorld::draw() {
	//TODO
}
void GameWorld::resize() {
	//TODO
}
void GameWorld::loseLife() {
	this->lives -= 1;
}
enum Game_State GameWorld::getState() {
	return this->gameState;
}
bool GameWorld::noBricks() {
	//TODO
	return true;
}
bool GameWorld::noLives() {
	return this->lives = 0;
}
/*Brick* GameWorld::generateBricks(Brick** bricks) {
	if (this->level == 1) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 12; ++j) {
				bricks[i][j] = new Brick(ofGetWidth() *(j / 12), (i + 4) / 20, levelLayout1[i][j]);
			}
		}
	}
	
}
/*Ball* GameWorld::generateBalls() {
	//TODO
}*/