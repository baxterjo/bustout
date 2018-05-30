//Paddle.cpp
//Jordan Baxter

#include "Paddle.h"
#include "ofMain.h"

Paddle::Paddle() {
	this->box = ofRectangle(0, ofGetHeight() - ofGetHeight() * 3 / 25, ofGetWidth() / 12, ofGetHeight() / 25);
	this->big = false;
	this->sticky = false;
	this->laser = false;

};
void Paddle::draw() {
	ofSetColor(255);
	ofDrawRectangle(this->box);
}

void Paddle::move(int x) {
	this->x = x - (this->w/2);
}

ofRectangle Paddle::getStructure() {
	return this->box;
}

float Paddle::getX() {
	return this->x;
}

float Paddle::getY() {
	return this->y;
}

float Paddle::getW() {
	return this->w;
}