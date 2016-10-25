#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		const string ARDUINO_PORT = "COM3";
		ofArduino arduino;
		bool bSetupArduino;
		void connectArduino();
		void setupArduino();
		void updateArduino();

		void setup();
		void update();
		void draw();

};
