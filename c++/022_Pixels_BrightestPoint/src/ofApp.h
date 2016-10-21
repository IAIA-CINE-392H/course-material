#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofVideoGrabber camera;
		ofPixels pixels;
		ofPoint brightestPoint;

		void setup();
		void update();
		void draw();
};
