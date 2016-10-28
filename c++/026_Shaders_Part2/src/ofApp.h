#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofVideoGrabber video;
		ofImage image;

		ofSpherePrimitive sphere;
		ofTexture texture;
		ofShader shader;
		ofEasyCam camera;

		// frame buffer objects
		ofFbo fbo1;
		ofFbo fbo2;

		void setup();
		void update();
		void draw();
};
