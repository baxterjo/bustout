#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gameWorld = new GameWorld();
	paddle = new Paddle();
	gameWorld->fetchLevelLayout();
	gameWorld->generateBlocks(Block* []);
	gameWorld->generateBalls();
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameWorld->getState == PLAY) {
		ball->move();
		if (ball->hitwall()) {
			ball->bounceWall();
		}
		else if (ball->hitCeiling()) {
			ball->bounceCeiling();
		}
		else if (ball->hitPaddle()) {
			ball->bouncePaddle();
		}
		else if (ball->hitFloor()) {
			ball->loseLife();
		}
		else if (ball->hitBrick()) {
			ball->bounceBrick();
			brick->damage();
		}
		else if (brick->noneLeft()) {
			gameWorld->nextLevel();
		}
		else if (ball->noneLeft()) {
			gameWorld->loser();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gameWorld->draw();
	brick->draw();
	paddle->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
