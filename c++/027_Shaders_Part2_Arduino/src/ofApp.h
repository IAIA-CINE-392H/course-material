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

		float mixAmount; // texture mix (0.0-1.0)

		// arduino template
		const string ARDUINO_PORT = "COM5"; // update the COM port if needed
		ofArduino arduino;
		bool bSetupArduino;
		void connectArduino();
		void setupArduino();
		void updateArduino();
};
