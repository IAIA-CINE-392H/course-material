#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofImage image;

		ofPlanePrimitive plane;
		ofTexture texture;
		ofShader shader;
		ofEasyCam camera;

		void setup();
		void update();
		void draw();
};
