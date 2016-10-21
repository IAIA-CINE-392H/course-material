#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		// video camera
		ofVideoGrabber camera;

		// frame buffer
		ofImage image[100];

		// frame buffer index
		int index = -1;

		// how many frames to display at once (count)
		// can't be more than frame buffer size
		int cnt = 50; 

		// the alpha of each frame
		int alpha = 10;

		// openframeworks template
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
