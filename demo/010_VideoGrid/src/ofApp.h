#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		// const = variable's value won't change
		// static = once the variable has been initialized, it remains in memory until the end of the program
		
		// grid layout
		const static int ROWS = 4;
		const static int COLUMNS = 3;
		const static int NUMBER_OF_VIDEOS = ROWS * COLUMNS;
		
		const float VIDEO_SCALE = 0.75f;

		// video player array
		ofVideoPlayer video[NUMBER_OF_VIDEOS];

		// video player hit test array
		ofRectangle rectangle[NUMBER_OF_VIDEOS];

		// set video pause state, overrides mouse behaivor
		bool pause = false;

		// openFrameworks template
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
