#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gameWorld = new GameWorld();
	paddle = new Paddle();
	gameWorld->fetchLevelLayout();
	gameWorld->generateBricks(Brick* []);
	gameWorld->generateBalls();
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameWorld->getState == PLAY) {
		ball->move();
		if (ball->hitwall()) {
			ball->bounceWall();
		}
		if (ball->hitCeiling()) {
			ball->bounceCeiling();
		}
		if (ball->hitPaddle()) {
			ball->bouncePaddle();
		}
		if (ball->hitFloor()) {
			ball->loseLife();
		}
		if (ball->hitBrick()) {
			ball->bounceBrick();
			brick->damage();
		}
		if (brick->noneLeft()) {
			gameWorld->nextLevel();
		}
		if (ball->noneLeft()) {
			gameWorld->changeState(LOSE);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gameWorld->draw();
	if (gameWorld->getState() == PLAY) {
		brick->draw();
		paddle->draw();
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
	paddle->move();
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
	gameWorld->resize();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
