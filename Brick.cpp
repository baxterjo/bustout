//Brick.cpp
//Jordan Baxter

#include "Brick.h"

Brick::Brick(float x, float y, char c) {
	int chance = ofRandom(100);
	this->x = x;
	this->y = y;
	this->w = ofGetWidth() / 12;
	this->h = ofGetHeight() / 20;
	this->strength = this->setStrength(c);
	this->color = this->setColor(c);
	if (c == ' ') {
		this->exists = false;
	}
	else {
		this->exists = true;
	}
	
	if (chance > 90) {
		this->powerup = true;
	}
	else {
		this->powerup = false;
	}
	
}

void Brick::damage() {
	this->strength -= 1;
	if (this->strength == 3) {
		this->color = setColor('o');
	}
	else if (this->strength == 2) {
		this->color = setColor('y');
	}
	else if (this->strength == 1) {
		this->color = setColor('g');
	}
	else if (this->strength == 0) {
		this->exists == false;
		if (this->powerup == true) {
			//dropPowerup(); TODO
		}
	}
}

void Brick::draw() {
	if (this->exists == true) {
		ofSetColor(this->color);
		ofDrawRectangle(this->x, this->y, this->w, this->h);
	}
}

ofColor Brick::setColor(char c) {
	if (c == 'r') {
		return ofColor(234, 41, 0);
	}
	else if (c == 'o') {
		return ofColor(234, 96, 0);
	}
	else if (c == 'y') {
		return ofColor(234, 210, 0);
	}
	else if (c == 'g') {
		return ofColor(44, 222, 0);
	}
}

int Brick::setStrength(char c) {
	if (c == 'r') {
		return 4;
	}
	else if (c == 'o') {
		return 3;
	}
	else if (c == 'y') {
		return 2;
	}
	else if (c == 'g') {
		return 1;
	}
}

bool Brick::getExists() {
	return this->exists;
}