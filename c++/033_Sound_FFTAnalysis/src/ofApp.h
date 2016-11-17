#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofSoundPlayer sound; 

		// fft (fast fourier transform) data
		float * fftSmoothed; // pointer to an array of floats
		const int nBands = 2048; // how much to split up the FFT 

		// 3D mesh to distort
		ofPlanePrimitive plane;

		// 3D camera
		ofEasyCam camera;
    
		// video camera
        ofVideoGrabber video;

		void setup();
		void update();
		void draw();
		void dragEvent(ofDragInfo dragInfo);
};
