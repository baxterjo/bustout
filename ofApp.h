#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "GameWorld.h"
#include "Ball.h"
#include "Brick.h"

class ofApp : public ofBaseApp{

	public:
		GameWorld* gameWorld;
		Paddle* paddle;
		vector<Brick*> bricks;
		Ball* ball;
		ofSoundPlayer brickDamage;
		ofSoundPlayer brickDestroy;
		ofSoundPlayer hitWall;
		ofSoundPlayer loseLife;
		ofSoundPlayer hitPaddle;



		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
