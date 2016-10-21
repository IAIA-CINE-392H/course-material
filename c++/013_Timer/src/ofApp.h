#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		float timer;				// current time in milliseconds
		float startTime;			// store when we start time timer
		float endTime;				// when do want to stop the timer
		bool bTimerReached;			// used as a trigger when we hit the timer
		bool bPause;				// keeps track if the timer is paused
		float pauseTimeOffset;		// offset time when paused
		
		int mediaIndex;				// keeps track of which media to display

		// openFrameworks template
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void gotMessage(ofMessage msg);		
};
