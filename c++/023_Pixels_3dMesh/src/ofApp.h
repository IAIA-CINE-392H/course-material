#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofVideoGrabber video;
		ofPixels pixels;

		ofEasyCam camera;
		ofPlanePrimitive plane;

		float extrude; 	// 3d mesh extrusion

		void setup();
		void update();
		void draw();
};
