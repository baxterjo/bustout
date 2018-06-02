//GameWorld.cpp
//Jordan Baxter

#include <iostream>
#include "GameWorld.h"
#include "Ball.h"
#include "Brick.h"
#include "ofMain.h"

GameWorld::GameWorld() {
	this->gamefont.load("Paradox.ttf", ofGetWidth() / 40, true, true);
	this->gameState = PLAY;
	this->lives = 3;
	this->level = 1;
	this->score = 0;
}

void GameWorld::fetchLevelLayout(string file1, string file2, string file3) {
	cout << "Fetching level layouts. \n";
	ofBuffer level = ofBufferFromFile(file1);
	cout << level.getText();
	vector<string> lines;
	for (auto line: level.getLines()) {
		lines.push_back(line);
		cout << line << "\n";
	}

	for (int i = 0; i < lines.size(); ++i) {
		for (int j = 0; j < lines.at(i).size(); ++j) {
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

	for (int i = 0; i < lines.size(); ++i) {
		for (int j = 0; j < lines.at(i).size(); ++j) {
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

	for (int i = 0; i < lines.size(); ++i) {
		for (int j = 0; j < lines.at(i).size(); ++j) {
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
	gamefont.drawString("LEVEL: " + ofToString(this->level), ofGetWidth() * 1 / 10, ofGetHeight() / 20);
	gamefont.drawString("LIVES: " + ofToString(this->lives), ofGetWidth() * 3 / 10, ofGetHeight() / 20);
	gamefont.drawString("SCORE: " + ofToString(this->score), ofGetWidth() * 5 / 10, ofGetHeight() / 20);
	
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
	else {
		return ' ';
	}
}

bool GameWorld::noBricks(vector<Brick*> &bricks) {
	bool noBricks = true;
	for (int i = 0; i < bricks.size(); ++i) {
		if (bricks[i]->getExists()) {
			noBricks = false;
			break;
		}
			
	}
	return noBricks;
}
bool GameWorld::noLives() {
	return this->lives == 0;
}
void GameWorld::generateBricks(vector<Brick*> &bricks) {
	bricks.erase(bricks.begin(), bricks.end());
	cout << "Generating Bricks...";

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 12; ++j) {
			bricks.push_back(new Brick(ofGetHeight() * ((i + 3) / 25.0), ofGetWidth() * (j / 12.0), this->getLayout(i,j)));
		}
	}
	cout << "Done." << "\n";
}

void GameWorld::generateBalls(vector<Ball*> &balls) {
	cout << "Generating balls...";
	for (int i = 0; i < 5; ++i) {
		balls.push_back(new Ball());
	}
	cout << "Done \n";
}

void GameWorld::scoreUp(int x) {
	this->score += x;
}