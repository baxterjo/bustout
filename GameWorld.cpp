//GameWorld.cpp
//Jordan Baxter

#include <iostream>
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
	cout << "Fetching level layouts. \n";
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
	cout << "Done. \n";
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
void GameWorld::resize(Brick* brick, Paddle* paddle, Ball* ball) {
	//brick->resize();
	//ball->resize();
	//paddle->resize();
}
void GameWorld::loseLife() {
	this->lives -= 1;
}
enum Game_State GameWorld::getState() {
	return this->gameState;
}

char GameWorld::getLayout(int i, int j) {
	if (this->level == 1) {
		return this->levelLayout1[i][j];
	}
	else if (this->level == 2) {
		return this->levelLayout2[i][j];
	}
	else if (this->level == 3) {
		return this->levelLayout3[i][j];
	}
}

bool GameWorld::noBricks() {
	//TODO
	return true;
}
bool GameWorld::noLives() {
	return this->lives = 0;
}
void GameWorld::generateBricks(vector<Brick*> bricks) {
	cout << "Generating Bricks."<<"\n";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 12; ++j) {
			bricks.push_back(new Brick(ofGetHeight() * ((i + 3) / 25), ofGetHeight() *(j / 12), this->getLayout(i,j)));

		}
	}
	cout << "Done." << "\n";
}

/*Ball* GameWorld::generateBalls() {
	//TODO
}*/