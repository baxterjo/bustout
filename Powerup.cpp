//Powerup.cpp
//Jordan Baxter

#include"ofMain.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "GameWorld.h"
#include "Powerup.h"

Powerup::Powerup() {
	int chance = ofRandom(99);
	if (chance < 33) {
		this->type = DOUBLE_POINTS;
		this->color = ofColor(166, 0, 255);
	}
	else if (chance > 66) {
		this->type = SUPER_BALL;
		this->color = ofColor(0, 251, 255);
	}
	else {
		this->type = LONG_PADDLE;
		this->color = ofColor(0, 8, 255);
	}
	this->box = ofRectangle(this->position, ofGetWidth() / 100, ofGetWidth() / 100);
	this->position = ofVec2f(this->box.width * -1, this->box.height * -1);

	
}

void Powerup::draw() {
	ofSetColor(this->color);
	ofDrawCircle(this->position - this->box.height / 2, this->box.height);
}

void Powerup::spawn(ofVec2f position) {
	this->position = position;
	this->velocity.y += 5;
}

void Powerup::move() {
	this->position += this->velocity;
	this->box.x = this->position.x;
	this->box.y = this->position.y;
}

void Powerup::miss() {
	if (this->box.getMaxY() == ofGetWidth()) {
		this->velocity.y = 0;
		this->position.x = this->box.width * -1;
		this->position.y = this->box.height * -1;
	}
}

bool Powerup::hitPaddle(Paddle* paddle) {
	ofRectangle paddlebox = paddle->getStructure();
	return this->box.intersects(paddlebox);
}

/*void Powerup::doIt(Paddle* &paddle, GameWorld* &gameWorld, Ball* &ball) {
	if (this->type == DOUBLE_POINTS) {
		gameWorld->doublePoionts();
	}
	else if (this->type == SUPER_BALL) {
		ball->superBall();
	}
	else if (this->type == LONG_PADDLE) {
		paddle->longPaddle();
	}
}*/