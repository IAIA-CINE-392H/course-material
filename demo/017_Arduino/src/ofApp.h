#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		ofArduino arduino;
		bool bSetupArduino;
        void setupArduino();

		bool bLight;
		int potValue;

		ofSoundPlayer sound;
		ofVideoPlayer video;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void dragEvent(ofDragInfo dragInfo);
		
};
