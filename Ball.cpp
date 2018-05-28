//Ball.cpp
//Jordan Baxter

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

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
	//TODO
}

void Ball::bouncePaddle(Paddle* paddle) {
	this->velocity.y *= -1;
	this->velocity.x += ofMap(this->position.x, paddle->getX(), (paddle->getX() + paddle->getW()), -2, 2);
}

void Ball::damageBrick() {

}

bool Ball::hitPaddle(Paddle* paddle) {
	
	return (this->position.x > paddle->getX() && this->position.x < paddle->getX() + paddle->getW() && this->position.y > paddle->getY());
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
		if ((this->position.x > bricks[i]->getX()) && (this->position.x < bricks[i]->getX() + bricks[i]->getW()) && (this->position.y + this->r > bricks[i]->getY() || this->position.y - this->r < bricks[i]->getY() + bricks[i]->getW())) {
			return true;
		}
	}
	
}