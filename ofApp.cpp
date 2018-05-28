//ofApp.cpp
//Jordan Baxter

#include "ofApp.h"
#include "Paddle.h"
#include "GameWorld.h"
#include "Ball.h"
#include "Brick.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofHideCursor();
	gameWorld = new GameWorld();
	paddle = new Paddle();
	gameWorld->fetchLevelLayout("01.txt", "02.txt", "03.txt");
	gameWorld->generateBricks(bricks);
	gameWorld->generateBalls(balls);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameWorld->getState() == PLAY) {
		for (int i = 0; i < balls.size(); ++i) {
			balls[i]->move();
			if (balls[i]->hitWall()) {
				balls[i]->bounceWall();
			}
			if (balls[i]->hitCeiling()) {
				balls[i]->bounceCeiling();
			}
			if (balls[i]->hitPaddle(paddle)) {
				balls[i]->bouncePaddle(paddle);
			}
			if (balls[i]->hitFloor()) {
				gameWorld->loseLife();
			}
			if (balls[i]->hitBrick(bricks)) {
				balls[i]->bounceBrick();
				balls[i]->damageBrick();
			}
		}

		if (gameWorld->noLives()) {
			gameWorld->changeState(LOSE);
		}
		if (gameWorld->noBricks()) {
			gameWorld->nextLevel();
		}
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
		for (int i = 0; i < balls.size(); ++i) {
			balls[i]->draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
