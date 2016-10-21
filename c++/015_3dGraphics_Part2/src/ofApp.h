#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		// 3d scene
		ofSpherePrimitive sphere;
		ofEasyCam camera;
		ofLight light;

		// openFrameworks template
		void setup();
		void update();
		void draw();		
};
