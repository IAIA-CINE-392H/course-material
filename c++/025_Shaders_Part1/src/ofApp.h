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

		void setup();
		void update();
		void draw();
};
