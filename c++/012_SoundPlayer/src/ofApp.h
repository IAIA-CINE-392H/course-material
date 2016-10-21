#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		// sound player objects
		ofSoundPlayer sound;
		ofSoundPlayer s1085;
		ofSoundPlayer beat;
		ofSoundPlayer synth;
		ofSoundPlayer violet;
		ofSoundPlayer mohawk;

		// openFrameworks template
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
		void dragEvent(ofDragInfo dragInfo);

};
