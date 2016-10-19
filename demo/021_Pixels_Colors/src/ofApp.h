#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofImage image;
		ofPixels pixels;
		ofTexture texture;

		void setup();
		void update();
		void draw();

		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		
};
