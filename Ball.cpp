//Ball.cpp
//Jordan Baxter

#include "Ball.h"

Ball::Ball() {
	this->r = ofGetWidth() / 100;
	this->s = 0;
	this->position = ofVec2f(this->r *-1);
}

void Ball::spawn() {
	this->position = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	this->velocity = ofVec2f(ofRandom(-5, 5), -5);
}

void Ball::move() {
	this->position += this->velocity;
}

void Ball::draw() {
	ofSetColor(this->color);
	ofDrawCircle(this->position, this->r);
}

void Ball::bounceWall() {
	
}

void Ball::bounceCeiling() {
	//TODO
}

void Ball::bounceBrick() {
	//TODO
}

void Ball::bouncePaddle() {
	//TODO
}

void Ball::damageBrick() {

}

bool Ball::hitPaddle() {
	//TODO
	return true;
}

bool Ball::hitWall() {
	return (this->position.x - this->r < 0 || this->position.x + this->r > ofGetWidth());
}

bool Ball::hitCeiling() {
	return this->position.y - this->r < 0;
}

bool Ball::hitFloor() {
	return this->position.y + this->r > ofGetHeight();
}

bool Ball::hitBrick(vector<Brick*> bricks) {
	for (int i = 0; i < bricks.size(); ++i) {
		//if (this->position.x>)
	}
	return true;
}