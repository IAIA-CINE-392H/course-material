#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	
	public:
		void setup();
		void update();
		void draw();
		   
		// access to microphone sound buffer
        void audioIn(ofSoundBuffer &inBuffer);

		vector <float> volHistory;
		ofSoundStream soundStream;
		mutex audioMutex;
};
