//ofApp.cpp
//Jordan Baxter

#include "ofApp.h"
#include "Paddle.h"
#include "GameWorld.h"
#include "Ball.h"
#include "Brick.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofHideCursor();
	ofSetBackgroundColor(0);
	brickDamage.load("brickDamage.WAV", false);
	brickDestroy.load("brickDestroy.WAV", false);
	hitWall.load("hitWall.WAV", false);
	loseLife.load("loseLife.WAV", false);
	hitPaddle.load("hitPaddle.WAV", false);
	gameWorld = new GameWorld();
	paddle = new Paddle();
	gameWorld->fetchLevelLayout("01.txt", "02.txt", "03.txt");
	gameWorld->generateBricks(bricks);
	ball = new Ball();
	ball->spawn();
	for (int i = 0; i < 10; ++i) {
		powerups.push_back(new Powerup());
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameWorld->getState() == PLAY) {
		ball->move();
			if (ball->hitWall()) {
				ball->bounceWall();
				hitWall.play();
			}
			if (ball->hitCeiling()) {
				ball->bounceCeiling();
				hitWall.play();
			}
			if (ball->hitPaddle(paddle)) {
				ball->bouncePaddle(paddle);
				hitPaddle.play();
			}
			if (ball->hitFloor()) {
				gameWorld->loseLife();
				ball->spawn();
				loseLife.play();
			}
			for (int i = 0; i < bricks.size(); ++i){
				if (ball->hitBrick(bricks[i])) {
					ball->bounceBrick();
					ball->damageBrick(bricks[i]);
					gameWorld->scoreUp(10);
					if (bricks[i]->getExists()) {
						brickDamage.play();
					}
					else {
						brickDestroy.play();
					}
				}
			}
			
		}

		if (gameWorld->noLives()) {
			gameWorld->changeState(LOSE);
		}
		else if (gameWorld->noBricks(bricks) && gameWorld->getLevel() > 3) {
			gameWorld->changeState(WIN);
		}
		else if (gameWorld->noBricks(bricks)) {
			gameWorld->nextLevel();
			gameWorld->generateBricks(bricks);
		}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gameWorld->draw();
	if (gameWorld->getState() == PLAY) {
		for (int i = 0; i < bricks.size(); ++i) {
			bricks[i]->draw();
		}
		paddle->draw();
		ball->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'k') {
		for (int i = 0; i < bricks.size(); ++i) {
			bricks[i]->godHand();
		}
	}
	if (key == OF_KEY_RETURN && gameWorld->getState() == LOSE) {
		gameWorld->changeState(PLAY);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	paddle->move(x);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (gameWorld->getState() != PLAY && button == 0) {
		gameWorld->reset(bricks, ball);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	//gameWorld->resize();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
