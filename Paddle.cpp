//Paddle.cpp
//Jordan Baxter

#include "Paddle.h"
#include "ofMain.h"

Paddle::Paddle() {
	this->w = ofGetWidth() / 12;
	this->h = ofGetHeight() / 20;
	this->x = 0;
	this->y = ofGetHeight() - (this->h * 3);
	this->big = false;
	this->sticky = false;
	this->laser = false;

}
void Paddle::draw() {
	ofSetColor(255);
	ofDrawRectangle(this->x, this->y, this->w, this->h);
}

void Paddle::move(int x) {
	this->x = x;
}