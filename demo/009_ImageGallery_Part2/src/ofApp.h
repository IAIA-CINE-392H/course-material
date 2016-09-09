#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		// image variables
		ofImage image;
		string imageFiles[3];

		// title 
		ofTrueTypeFont font;
		string titles[3];

		// arrows
		ofImage rightArrow;
		ofImage leftArrow;

		// current list index
		int i;


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
