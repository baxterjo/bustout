//Ball.cpp
//Jordan Baxter

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

Ball::Ball() {
	this->r = ofGetWidth() / 100;
	this->position = ofVec2f(this->r *= -1);
	this->box = ofRectangle(this-> position, this->r * 2, this->r * 2);
	this->s = 0;
}

void Ball::spawn() {
	this->position = ofVec2f(ofGetWidth() / 1.5, ofGetHeight() / 2);
	this->velocity = ofVec2f(ofRandom(-5, 5), 5);
}

void Ball::move() {
	this->position += this->velocity;
	this->box.x = this->position.x;
	this->box.y = this->position.y;
}

void Ball::draw() {
	ofSetColor(this->color);
	ofDrawCircle(this->box.x + r, this->box.y + r, this->r);
}

void Ball::bounceWall() {
	this->velocity.x *= -1;
	this->velocity.y += this->s;
	if (this->velocity.y < 0 && this->position.x + this->r > ofGetWidth()) {
		this->s += .5;
	}
	else if (this->velocity.y > 0 && this->position.x + this->r > ofGetWidth()) {
		this->s += -.5;
	}
	else  if (this->velocity.y < 0 && this->position.x - this->r < 0) {
		this->s += -.5;
	}
	else if (this->velocity.y > 0 && this->position.x - this->r < 0) {
		this->s += .5;
	}
}

void Ball::bounceCeiling() {
	this->velocity.y *= -1;
	this->velocity.x += this->s;
	if (this->velocity.x < 0) {
		this->s += .5;
	}
	else if (this->velocity.x > 0) {
		this->s += -.5;
	}
}

void Ball::bounceBrick() {
	this->velocity.y *= -1;
}

void Ball::bouncePaddle(Paddle* paddle) {
	this->velocity.y *= -1;
	this->velocity.x += ofMap(this->position.x +r , paddle->getX(), (paddle->getX() + paddle->getW()), -4, 4);
}

void Ball::damageBrick(Brick* brick) {
	brick->damage();
}

bool Ball::hitPaddle(Paddle* &paddle) {
	ofRectangle paddleBox = paddle->getStructure();
	return this->box.intersects(paddleBox);
}

bool Ball::hitWall() {
	return (this->box.getMinX() < 0 || this->box.getMaxX() > ofGetWidth());
}

bool Ball::hitCeiling() {
	return this->position.y < 0;
}

bool Ball::hitFloor() {
	return this->position.y + this->r > ofGetHeight();
}

bool Ball::hitBrick(Brick* brick) {
	if (brick->getExists()) {
		ofRectangle brickBox = brick->getStructure();
		return this->box.intersects(brickBox);
	}
	
}