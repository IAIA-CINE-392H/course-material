#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		// 3d scene
		ofLight light;

		// variable to rotate box 
		float ry = 0;

		// openFrameworks template
		void setup();
		void update();
		void draw();		
};
