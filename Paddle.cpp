//Paddle.cpp
//Jordan Baxter

#include "Paddle.h"
#include "ofMain.h"

Paddle::Paddle() {
	this->box = ofRectangle(0, ofGetHeight() - ofGetHeight() * 3 / 25, ofGetWidth() / 12, ofGetHeight() / 25);
	this->big = false;
	this->sticky = false;
	this->laser = false;

}

void Paddle::draw() {
	ofSetColor(255);
	ofDrawRectangle(this->box);
}

void Paddle::move(int x) {
	this->box.x = x - (this->box.width/2);
}

ofRectangle Paddle::getStructure() {
	return this->box;
}

float Paddle::getX() {
	return this->box.x;
}

float Paddle::getY() {
	return this->box.y;
}

float Paddle::getW() {
	return this->box.width;
}